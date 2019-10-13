/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:31:47 by snorcros          #+#    #+#             */
/*   Updated: 2019/08/18 22:05:29 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_atoi(char *str)
{
	int ans;
	int sign;

	ans = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == ' ' || *str == '\v')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		ans = 10 * ans + (*str - '0');
		str++;
	}
	return (ans * sign);
}

void	remove_numb(t_stack_numb **numb)
{
	t_stack_numb *tmp;

	tmp = *numb;
	*numb = (*numb)->previous;
	free(tmp);
}

void	remove_op(t_stack_op **op)
{
	t_stack_op *tmp;

	tmp = *op;
	*op = (*op)->previous;
	free(tmp);
}
