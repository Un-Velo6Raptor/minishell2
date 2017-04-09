/*
** match.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:23:19 2017 Martin Januario
** Last update Sun Apr  9 02:23:20 2017 Martin Januario
*/

int		match(char *s1, char *s2)
{
  if (*s1 == '\0' && (*s2 == '\0' || *s2 == '*'))
    return (1);
  if (*s1 == '\0' || *s2 == '\0')
    return (0);
  if (*s1 != *s2 && *s2 != '*')
    return (0);
  if (*s2 == '*' && *(s2 + 1) == '*')
    return (match(s1, s2 + 1));
  if (*s2 == '*' && *s1 != *(s2 + 1))
    return (match(s1 + 1, s2));
  else if (*s2 == '*' && *s1 == *(s2 + 1))
    return (match(s1 + 1, s2 + 2));
  return (match(s1 + 1, s2 + 1));
}
