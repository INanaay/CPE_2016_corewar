/*
** my_strcmp.c for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Sat Jan 21 02:50:27 2017 flavian gontier
** Last update Fri Mar 17 18:14:35 2017 nathan
*/

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 != 0 && *s2 != 0)
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}
