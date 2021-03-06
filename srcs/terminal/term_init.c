/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <tmoska@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 12:03:00 by tmoska            #+#    #+#             */
/*   Updated: 2017/03/26 03:40:48 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		clean_terminal(void)
{
	ft_putstr(tgetstr("cl", NULL));
	return (0);
}

int		term_init(t_shell **shell)
{
	char	*term_name;

	term_name = ttyname(0);
	if (term_name == NULL)
		return (1);
	if (tcgetattr(STDIN_FILENO, &(*shell)->term->term) == -1 ||
		tgetent(NULL, get_env_val(shell, "TERM")) < 1)
		return (1);
	(*shell)->term->term.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &(*shell)->term->term) == -1)
		return (1);
	(*shell)->term->tc_ok = 1;
	return (0);
}

int		term_trigger(t_shell **shell, int off)
{
	if ((*shell)->term->tc_ok)
	{
		if (off)
			(*shell)->term->term.c_lflag |= (ICANON | ECHO);
		else
			(*shell)->term->term.c_lflag &= ~(ICANON | ECHO);
		if (tcsetattr(STDIN_FILENO, TCSADRAIN,
			&((*shell)->term->term)) == -1)
			return (1);
	}
	return (0);
}
