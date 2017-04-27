/*
** save_pipe.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr 26 22:45:06 2017 Martin Januario
** Last update Wed Apr 26 22:48:28 2017 Martin Januario
*/

#include	<unistd.h>
#include	"my.h"

void		save_pipe(int opt)
{
  static int	fd0 = -1;
  static int	fd1 = -1;

  if (opt == 0)
    {
      fd0 = dup(0);
      fd1 = dup(1);
    }
  else
    {
      dup2(fd1, 1);
      dup2(fd0, 0);
      close(fd0);
      close(fd1);
    }
}
