/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:42:06 by moska             #+#    #+#             */
/*   Updated: 2017/03/09 03:41:57 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	construct_command(t_shell **shell)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit((*shell)->buff, ';');
	while (tmp[i])
	{
		ft_lstadd_back(&(*shell)->commands, ft_lstnew(tmp[i],\
			ft_strlen(tmp[i]) + 1));
		i++;
	}
	ft_str2del(&tmp);
}
