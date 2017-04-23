/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:02:28 2017 Martin Januario
** Last update Sun Apr 23 14:55:31 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"my.h"

void		recup_sig(int signo)
{
  (void) signo;
}

int		loop_order(t_needs *news, int value_ret)
{
  t_buffer	buffer;
  t_my_order	*order;
  char		*tmp;

  ini_gnl(&buffer);
  isatty_disp(news);
  if (signal(SIGINT, recup_sig) == SIG_ERR)
    return (0);
  while ((tmp = get_next_line(0, &buffer)) != NULL)
    {
      if (signal(SIGINT, recup_sig) == SIG_ERR)
	return (0);
      if ((order = prepare_order(tmp)) != NULL)
	{
	  value_ret = exec_the_order(news, order);
	  free_list_order(order);
	}
      my_free(tmp);
      isatty_disp(news);
    }
  my_free(tmp);
  return (value_ret);
}

int		main(int argc, char **argv, char **env)
{
  t_needs	news;
  int		value_ret;

  value_ret = 0;
  (void) argc;
  (void) argv;
  if ((news.my_env = my_tabdup(env)) == NULL)
    return (MALLOC_FAILED);
  if (ini_needs(&news) == 84)
    return (84);
  if (news.pwd == NULL || news.oldpwd == NULL)
    return (84);
  value_ret = loop_order(&news, 0);
  free_tab(news.my_env);
  my_free(news.pwd);
  my_free(news.oldpwd);
  my_free(news.path);
  my_free(news.home);
  return (value_ret);
}
