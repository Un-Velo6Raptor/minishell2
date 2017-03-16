/*
** get_next_line.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 12:53:43 2017 
** Last update Wed Mar 15 13:39:45 2017 
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"

static int	my_strlen_gnl(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}

static char	*my_free_gnl(char *result)
{
  if (result != NULL)
    free(result);
  return (NULL);
}

static char	*my_realloc_gnl(char *str, char *add_str, int *idx_res)
{
  char		*new_str;
  int		idx;
  int		idx2;

  idx = 0;
  idx2 = 0;
  if ((new_str = malloc(sizeof(char) * (my_strlen_gnl(str) +
					my_strlen_gnl(add_str) + 1))) == NULL)
    return (NULL);
  while (str != NULL && str[idx] != '\0')
    {
      new_str[idx] = str[idx];
      idx++;
    }
  while (add_str[idx2] != '\0' && add_str[idx2] != '\n')
    {
      new_str[idx + idx2] = add_str[idx2];
      idx2++;
    }
  new_str[idx + idx2] = '\0';
  free(str);
  *idx_res = idx2;
  return (new_str);
}

static char   	*put_excedent(char *buffer, int *idx_res)
{
  char		*str;
  int		idx;

  str = NULL;
  idx = 1;
  if ((str = malloc(sizeof(char) * (my_strlen_gnl(buffer) + 1))) == NULL)
    return (NULL);
  while (buffer[idx] != '\0' && buffer[idx] != '\n')
    {
      str[idx - 1] = buffer[idx];
      idx++;
    }
  str[idx - 1] = '\0';
  *idx_res += idx;
  return (str);
}

char		*get_next_line(int fd, t_buffer *news)
{
  char		*result;

  result = NULL;
  if (my_strlen_gnl(&news->buffer[news->idx]) != 0)
    {
      if ((result = put_excedent(&news->buffer[news->idx], &news->idx)) ==
	  NULL)
	return (NULL);
      if (news->buffer[news->idx] == '\n')
	return (result);
    }
  news->idx = 0;
  news->buffer[0] = '\0';
  while ((news->size = read(fd, news->buffer, READ_SIZE)) > 0)
    {
      news->buffer[news->size] = '\0';
      if ((result = my_realloc_gnl(result, news->buffer, &news->idx)) == NULL)
	return (NULL);
      if (news->idx != my_strlen_gnl(news->buffer))
	return (result);
    }
  return ((my_strlen_gnl(result) == 0) ? my_free_gnl(result) : result);
}
