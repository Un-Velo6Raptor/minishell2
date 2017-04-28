/*
** redir_error.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Apr  7 18:34:03 2017 Martin Januario
** Last update Thu Apr 27 16:25:10 2017 Martin Januario
*/

#include	<sys/stat.h>
#include	<unistd.h>
#include	"my.h"

int		redir_error(char *str, int opt)
{
  struct stat	sb;

  if (lstat(str, &sb) == -1)
    {
      if (opt == 1)
	{
	  my_puterror(str);
	  return (my_puterror(": No such file or directory.\n"));
	}
      return (0);
    }
  if (S_ISDIR(sb.st_mode) != 0)
    {
      my_puterror(str);
      return (my_puterror(": Is a directory.\n"));
    }
  if (access(str, W_OK) == -1)
    {
      my_puterror(str);
      return (my_puterror(": Permission denied.\n"));
    }
  return (0);
}
