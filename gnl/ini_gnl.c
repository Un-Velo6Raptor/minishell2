/*
** ini_gnl.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/gnl
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:05:18 2017 Martin Januario
** Last update Sun Apr  9 02:05:19 2017 Martin Januario
*/

#include	"get_next_line.h"
#include	"my.h"

void		ini_gnl(t_buffer *news)
{
  news->buffer[0] = '\0';
  news->idx = 0;
  news->size = 0;
}
