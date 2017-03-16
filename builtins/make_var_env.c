/*
** make_var_env.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 16 14:04:36 2017 
** Last update Thu Mar 16 14:07:23 2017 
*/

#include	<stdlib.h>
#include	"my.h"

char		*make_var_env(char *name, char *value)
{
  char		*str;

  if ((str = malloc(sizeof(char) * (my_strlen(name) +
				    my_strlen(value) + 3))) == NULL)
    return (NULL);
  my_strcpy(str, name);
  my_strcat(str, "=");
  if (value != NULL)
    my_strcat(str, value);
  return (str);
}
      
