/*
** error_exec.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 23 00:11:52 2017 
** Last update Mon Mar 27 17:23:27 2017 Martin Januario
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<signal.h>
#include	"my.h"

void		error_exec(int status)
{
  WIFSIGNALED(status);
  if (status - 128 == SIGSEGV || status == SIGSEGV)
    my_puterror("Segmentation fault");
  if (status - 128 == SIGFPE || status == SIGFPE)
    my_puterror("Floating exception");
  if (status - 128 == SIGABRT || status == SIGABRT)
    my_puterror("Aborted");
  if (status - 128 == SIGILL || status == SIGILL)
    my_puterror("Illegal instruction");
  if (WCOREDUMP(status))
    my_puterror(" (core dumped)\n");
  else
    my_puterror("\n");
}
