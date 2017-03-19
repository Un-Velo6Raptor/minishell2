/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 13:01:35 2017 
** Last update Sun Mar 19 21:29:07 2017 
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"my.h"

void            recup_sig(int signo)
{
  (void) signo;
}

int		loop_order(t_needs *news)
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
	  exec_the_order(news, order);
	  free_list_order(order);
	}
      my_free(tmp);
      isatty_disp(news);
    }
  free(tmp);
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_needs	news;

  (void) argc;
  (void) argv;
  if ((news.my_env = my_tabdup(env)) == NULL)
    return (MALLOC_FAILED);
  if (ini_needs(&news) == 84)
    return (84);
  if (news.pwd == NULL || news.oldpwd == NULL)
    return (84);
  loop_order(&news);
  free_tab(news.my_env);
  my_free(news.pwd);
  my_free(news.oldpwd);
  my_free(news.path);
  my_free(news.home);
  return (0);
}
