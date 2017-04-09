/*
** update_pwd.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:47:18 2017 Martin Januario
** Last update Sun Apr  9 02:47:20 2017 Martin Januario
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
