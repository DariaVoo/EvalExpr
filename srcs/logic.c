/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:29:06 by snorcros          #+#    #+#             */
/*   Updated: 2019/08/18 22:22:06 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_oop.h"
#include <stdio.h>

void	calcul(t_stack_numb **nums, t_stack_op **ops)
{
	int ans;

	ans = 0;
	ans = (*ops)->oper.fun(((*nums)->previous)->number, (*nums)->number);
	remove_op(ops);
	remove_numb(nums);
	remove_numb(nums);
	ft_push_numb(nums, ans);
}

void	brace(t_stack_numb **nums, t_stack_op **ops)
{
	int ans;

	ans = 0;
	while ((*ops)->oper.name != '(')
	{
		ans = (*ops)->oper.fun(((*nums)->previous)->number, (*nums)->number);
		remove_op(ops);
		remove_numb(nums);
		remove_numb(nums);
		ft_push_numb(nums, ans);
	}
	remove_op(ops);
}

int		this_ans(t_stack_numb **nums, t_stack_op **ops)
{
	int ans;

	ans = 0;
	while (*ops != NULL && *nums != NULL)
	{
		ans = (*ops)->oper.fun(((*nums)->previous)->number, (*nums)->number);
		remove_op(ops);
		remove_numb(nums);
		remove_numb(nums);
		ft_push_numb(nums, ans);
	}
	return (ans);
}

void	read_sign(char *str, t_stack_numb **numbers, t_stack_op **ops)
{
	int		i;

	i = 0;
	while (i < 7 && *str != g_opp[i].name)
		i++;
	if (i >= 7)
		return ;
	if (g_opp[i].name == ')')
		brace(numbers, ops);
	else if (*ops && g_opp[i].priority <= (*ops)->oper.priority
			&& g_opp[i].priority > 0)
	{
		calcul(numbers, ops);
		ft_push_op(ops, g_opp[i]);
	}
	else
		ft_push_op(ops, g_opp[i]);
}

int		eval_expr(char *str)
{
	t_stack_numb	*numbers;
	t_stack_op		*ops;
	int				ans;

	ans = 0;
	ops = 0;
	numbers = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == ' ')
			str++;
		if (*str >= '0' && *str <= '9')
		{
			ft_push_numb(&numbers, ft_atoi(str));
			while (*str >= '0' && *str <= '9')
				str++;
		}
		else
		{
			read_sign(str, &numbers, &ops);
			str++;
		}
	}
	ans = this_ans(&numbers, &ops);
	return (ans);
}
