/*
** make_var_env.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/builtins
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:09:31 2017 Martin Januario
** Last update Sun Apr  9 02:09:32 2017 Martin Januario
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
