/*
** close_broken.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Apr 27 17:00:41 2017 Martin Januario
** Last update Thu Apr 27 22:37:57 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		close_broken(t_my_order *beg)
{
  if (beg->before != NULL && beg->before->pipe[0] != -1)
    close(beg->before->pipe[0]);
  else if (beg->pipe[0] != -1)
    close(beg->pipe[0]);
}
