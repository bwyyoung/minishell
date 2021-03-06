/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:42:06 by moska             #+#    #+#             */
/*   Updated: 2017/03/30 05:16:56 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_tokens(t_tkn *tokens)
{
	t_tkn	*tkns;
	int		i;

	i = 0;
	tkns = tokens;
	printf("===== START print_tokens START =====\n");
	while (tkns)
	{
		printf("%i: %-10s type: %i\n", i + 1, tkns->data, tkns->type);
		tkns = tkns->right;
		i++;
	}
	printf("=====   END print_tokens END   =====\n");
}

int			tokenize(t_shell **shell)
{
	if (get_tokens(shell, 1) == 1)
		return (1);
	reorganize_tokens(shell);
	(*shell)->tree = build_tree((*shell)->tkns);
	(*shell)->tkns = NULL;
	return (0);
}
