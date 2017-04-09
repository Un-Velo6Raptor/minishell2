/*
** check_access.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/builtins
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:08:51 2017 Martin Januario
** Last update Sun Apr  9 02:44:20 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	"my.h"

int		check_access(char *path, char *path_display)
{
  struct stat	sb;

  if (access(path, 0) == -1)
    {
      my_puterror(path_display);
      my_puterror(": No such file or directory.\n");
      return (1);
    }
  if (access(path, R_OK) == -1)
    {
      my_puterror(path_display);
      my_puterror(": Permission denied.\n");
      return (1);
    }
  if (lstat(path, &sb) != -1 && S_ISDIR(sb.st_mode) == 0)
    {
      my_puterror(path_display);
      my_puterror(": Not a directory.\n");
      return (1);
    }
  return (0);
}
