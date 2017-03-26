/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:32:02 by moska             #+#    #+#             */
/*   Updated: 2017/03/26 07:41:52 by moska            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	command_is_good(char *cmd)
{
	return (!(!cmd || ft_strisblank(cmd)));
}

int			validate_and_prep_cmd(t_shell **shell)
{
	char *tmp;

	if (command_is_good((*shell)->buff))
	{
		tmp = (*shell)->buff;
		(*shell)->buff = ft_strtrim((*shell)->buff);
		replace_double_exclamation(shell, tmp);
		if (ft_strchr((*shell)->buff, '!'))
			replace_single_exclamation(shell, &(*shell)->buff);
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}
