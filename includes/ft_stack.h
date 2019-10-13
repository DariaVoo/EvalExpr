/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:28:50 by snorcros          #+#    #+#             */
/*   Updated: 2019/08/18 22:15:24 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include <unistd.h>
# include <stdlib.h>

typedef struct				s_operation
{
	char	name;
	int		priority;
	int		(*fun)(int, int);
}							t_operation;

typedef struct				s_stack_numb
{
	int						number;
	struct s_stack_numb		*previous;
}							t_stack_numb;

typedef struct				s_stack_op
{
	t_operation				oper;
	struct s_stack_op		*previous;
}							t_stack_op;

int							ft_add(int a, int b);
int							ft_sub(int a, int b);
int							ft_mul(int a, int b);
int							ft_mod(int a, int b);
int							ft_div(int a, int b);

t_stack_numb				*ft_create_stnumb(int data);
void						remove_numb(t_stack_numb **numb);
void						ft_push_numb(t_stack_numb **begin_list, int data);

t_stack_op					*ft_create_stop(t_operation data);
void						remove_op(t_stack_op **op);
void						ft_push_op(t_stack_op **begin_list,
		t_operation data);

int							ft_atoi(char *str);
int							ft_putchar(char c);
void						ft_putnbr(int nb);

void						calcul(t_stack_numb **nums, t_stack_op **ops);
int							eval_expr(char *str);

void						read_sign(char *str, t_stack_numb **numbers,
		t_stack_op **ops);

#endif
