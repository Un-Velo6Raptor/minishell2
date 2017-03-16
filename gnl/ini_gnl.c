/*
** ini_gnl.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 12:54:02 2017 
** Last update Tue Mar 14 12:54:04 2017 
*/

#include	"get_next_line.h"
#include	"my.h"

void		ini_gnl(t_buffer *news)
{
  news->buffer[0] = '\0';
  news->idx = 0;
  news->size = 0;
}
