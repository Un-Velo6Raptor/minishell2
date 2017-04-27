/*
** get_next_line.h for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/include
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:04:30 2017 Martin Januario
** Last update Wed Apr 26 21:41:33 2017 Martin Januario
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define	READ_SIZE (1)

typedef struct	s_buffer
{
  char		buffer[READ_SIZE + 1];
  int		idx;
  int		size;
}		t_buffer;

#endif /* !GET_NEXT_LINE_H_ */
