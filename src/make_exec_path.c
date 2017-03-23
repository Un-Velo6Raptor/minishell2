/*
** make_exec_path.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 23 00:41:11 2017 
** Last update Thu Mar 23 04:20:00 2017 
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		size_path(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    {
      if (str[idx] == ':')
	return (idx);
      idx++;
    }
  return (idx);
}

int		found_good_path(char *path,
				t_my_order *my_order,
				char **exec)
{
  struct stat	sb;
  int		idx;
  int		size;

  idx = 0;
  size = 0;
  while (idx < my_strlen(path))
    {
      size = size_path(&path[idx]);
      if ((*exec = malloc(my_strlen(my_order->order[0]) + size + 3)) == NULL)
	return (MALLOC_FAILED);
      my_strncpy(*exec, &path[idx], size);
      if (path[size_path(&path[idx]) - 1 + idx] != '/' &&
	  my_order->order[0][0] != '/')	
	my_strcat(*exec, "/");
      my_strcat(*exec, my_order->order[0]);
      if (access(*exec, 0) != -1 && access(*exec, R_OK) != -1 &&
	  lstat(*exec, &sb) != -1 && S_ISDIR(sb.st_mode) == 0)
	return (0);
      my_free(*exec);
      idx += size + 1;
    }
  if ((*exec = my_strdup(my_order->order[0])) == NULL)
    return (MALLOC_FAILED);
  return (-1);
}

int		make_exec_path(t_needs *news,
			       t_my_order *my_order,
			       char **exec_path)
{
  int		nb;

  nb = 0;
  if (count_spe_char(my_order->order[0], '/') != 0)
    {
      if ((*exec_path = my_strdup(my_order->order[0])) == NULL)
	return (MALLOC_FAILED);
      return (0);
    }
  if (found_var(news->my_env, "PATH=*") == -1 &&
      news->path == NULL)
    return (my_puterror("No var PATH.\n"));
  if ((nb = found_var(news->my_env, "PATH=*")) != -1)
    return (found_good_path(&news->my_env[nb][5], my_order, exec_path));
  return (found_good_path(news->path, my_order, exec_path));
}
