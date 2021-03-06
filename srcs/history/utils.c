/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <tmoska@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:09:26 by tmoska            #+#    #+#             */
/*   Updated: 2017/03/26 09:54:25 by moska            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				print_history(t_shell **shell)
{
	t_h_lst	*lst;

	lst = (*shell)->history->list;
	while (lst->next)
		lst = lst->next;
	while (lst)
	{
		ft_putnbr(lst->index);
		ft_putstr("  ");
		ft_putendl(lst->cmd);
		lst = lst->prev;
	}
	return (0);
}

t_h_lst			*hist_at_index(t_shell **shell, int index)
{
	t_h_lst *lst;

	lst = (*shell)->history->list;
	while (lst && lst->index != index)
		lst = lst->next;
	return (lst);
}

static t_h_lst	*hist_new_node(char *cmd)
{
	t_h_lst	*lst;

	if (!(lst = (t_h_lst *)ft_memalloc(sizeof(*lst))) || !cmd)
		return (NULL);
	lst->cmd = ft_strdup(cmd);
	lst->next = NULL;
	return (lst);
}

void			hist_add(t_shell **shell)
{
	t_h_lst	*new;

	new = hist_new_node((*shell)->buff);
	new->next = (*shell)->history->list;
	if ((*shell)->history->list)
		(*shell)->history->list->prev = new;
	(*shell)->history->list = new;
	new->index = (*shell)->history->size;
	(*shell)->history->size++;
}
