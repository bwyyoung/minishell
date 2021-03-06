/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 05:07:59 by adeletan          #+#    #+#             */
/*   Updated: 2017/03/29 02:52:27 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_linesize(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int			ft_currentline(t_shell **shell)
{
	char	**argv;
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	argv = ft_strsplit((*shell)->buff, '\n');
	while (argv[++i])
	{
		tmp = argv[i];
		argv[i] = ft_strjoin(argv[i], "\n");
		free(tmp);
	}
	len = (*shell)->term->tc_in;
	i = -1;
	ft_getpart(shell, &tmp);
	while (argv[++i] && ft_strncmp(argv[i], tmp, ft_strlen(tmp)) != 0)
	{
		ft_strdel(&tmp);
		ft_getpart(shell, &tmp);
		len -= ft_strlen(argv[i]);
	}
	ft_strdel(&tmp);
	ft_str2del(&argv);
	return (len);
}

int			ft_isfirstline(t_shell **shell)
{
	int i;
	int	i2;

	i2 = 0;
	i = (*shell)->term->tc_in;
	if (i < 0)
		i = 0;
	while (i > 0 && (*shell)->buff[i])
	{
		if ((*shell)->buff[i] == '\n' && i != (*shell)->term->tc_in)
			i2++;
		if (i2 == 1)
			return (0);
		--i;
	}
	return (1);
}

static char	**ft_appendreturn(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strjoin(str[i], "\n");
		free(tmp);
		++i;
	}
	return (str);
}

int			ft_getpart(t_shell **shell, char **str)
{
	int		i;
	char	**array;
	int		i2;
	int		i3;

	i = -1;
	i2 = -1;
	i3 = -1;
	array = ft_strsplit((*shell)->buff, '\n');
	array = ft_appendreturn(array);
	i2 = 0;
	while (++i < (*shell)->term->tc_in)
		if (!array || !array[i2])
			break ;
		else if (++i3 && !array[i2][i3])
		{
			i3 = 0;
			++i2;
		}
	i3 = ft_strlen(array[i2]);
	str ? *str = ft_strdup(array[i2]) : NULL;
	ft_str2del(&array);
	return (i3);
}
