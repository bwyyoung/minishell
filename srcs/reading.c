/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 21:29:48 by moska             #+#    #+#             */
/*   Updated: 2017/02/08 21:55:44 by moska            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void put_together(char **overlay, char **buff)
{
  char *tmp;

  tmp = *buff;
  *buff = ft_strjoin(*overlay, *buff);
  free(tmp);
  ft_strdel(overlay);
}

static void  move_to_overlay(char **overlay, char **buff)
{
  char *tmp;

  tmp = *overlay;
  *overlay = ft_strdup(*buff);
  free(tmp);
  ft_bzero(*buff, ft_strlen(*buff));
}

static int line_finished(char *buff)
{
  size_t len;
  size_t i;

  i = 0;
  if ((len = ft_strlen(buff)))
  {
    while (buff[i] && buff[i] != '\n')
      i++;
    if (i == len - 1 && (buff[0] != '\n'))
      return (1);
  }
  return (0);
}

void read_line(t_shell **shell)
{
  char  *buff;
  char  *overlay;
  int   ret;

  buff = ft_strnew(BUFF_SIZE);
  overlay = NULL;
  while ((ret = read(0, buff, BUFF_SIZE)))
  {
    buff[ret] = '\0';
    if (overlay && buff[0])
      put_together(&overlay, &buff);
    if (line_finished(buff))
    {
      (*shell)->buff = buff;
      return ;
    }
    else if ((ft_strlen(buff) == 1) && buff[0] == '\n')
    {
      print_prompt(0);
      ft_bzero(buff, ft_strlen(buff));
    }
    else
      move_to_overlay(&overlay, &buff);
  }
  if (overlay)
    free(overlay);
  free(buff);
  (*shell)->exit = 1;
}