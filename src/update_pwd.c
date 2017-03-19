/*
** update_pwd.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Mar 19 18:07:38 2017 
** Last update Sun Mar 19 20:24:08 2017 
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		update_pwd(t_needs *news)
{
  my_free(news->pwd);
  news->pwd = getcwd(NULL, 0);
  return (0);
}
