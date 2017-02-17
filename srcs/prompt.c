/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:33:26 by moska             #+#    #+#             */
/*   Updated: 2017/02/17 11:06:03 by moska            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_prompt(int terminated)
{
  // Todo: show working directory on the left
  if (terminated)
    write (1, "\n> ", 3);
  else
    write (1, "moska prompt $> ", 16);
}

void  command_not_found(t_shell **shell)
{
  ft_putstr_fd((*shell)->cmd[0], 2);
  ft_putstr_fd(": command not found\n", 2);
}