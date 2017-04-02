/*
** my_math.h for mylib in /home/nathan/PSU_2016_minishell1/mylib/include
**
** Made by nathan
** Login   <nathan.schwarz@epitech.eu@epitech.net>
**
** Started on  Sun Jan 22 04:38:40 2017 nathan
** Last update Tue Feb 14 15:57:39 2017 nathan
*/

#ifndef _MYMATH_
 #define _MYMATH_

typedef struct	s_my_eq2f
{
  int		solutions;
  float		a;
  float		b;
}		t_my_eq2f;

typedef struct	s_my_vector3f
{
  float		x;
  float		y;
  float		z;
}		t_my_vector3f;

t_my_eq2f	resolve_eq2(t_my_vector3f);
int		my_pow(int, int);
float		my_sqrt(float, int);
int		binary_base(unsigned int);
int		my_fabs(int);

#endif
