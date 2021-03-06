/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 04:11:29 by moska             #+#    #+#             */
/*   Updated: 2017/03/12 23:20:48 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_node(t_tkn *head)
{
	printf("%*s\n", (int)(6 + (ft_strlen(head->data) / 2)), head->data);
	printf("%5s %s\n", "/", "\\");
	printf("%5s %-5s\n\n", (head->left) ? head->left->data : \
	"null", (head->right) ? head->right->data : "null");
}

t_tkn	*highest_priority_node(t_tkn *tree)
{
	t_tkn	*tmp;
	t_tkn	*top;

	tmp = tree;
	top = tmp;
	while (tmp)
	{
		if (tmp->type > top->type)
			top = tmp;
		tmp = tmp->right;
	}
	return (top);
}

t_tkn	*get_left_branch(t_tkn *tree, t_tkn *head)
{
	t_tkn	*tmp;

	if (!tree)
		return (NULL);
	tmp = tree;
	while (!(tmp == head || tmp->right == head))
		tmp = tmp->right;
	if (tmp == head)
		return (NULL);
	tmp->right = NULL;
	return (tree);
}

t_tkn	*build_tree(t_tkn *tree)
{
	t_tkn	*head;
	t_tkn	*left;
	t_tkn	*right;
	t_tkn	*tmp;

	tmp = tree;
	if (!tree)
		return (NULL);
	head = highest_priority_node(tree);
	right = head->right;
	left = get_left_branch(tree, head);
	head->left = build_tree(left);
	head->right = build_tree(right);
	return (head);
}
