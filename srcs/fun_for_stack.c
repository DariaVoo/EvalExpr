/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_for_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:33:52 by snorcros          #+#    #+#             */
/*   Updated: 2019/08/18 22:03:25 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack_numb	*ft_create_stnumb(int data)
{
	t_stack_numb	*node;

	node = NULL;
	node = (t_stack_numb*)malloc(sizeof(t_stack_numb));
	if (node == NULL)
		return (node);
	node->number = data;
	node->previous = NULL;
	return (node);
}

t_stack_op		*ft_create_stop(t_operation data)
{
	t_stack_op	*node;

	node = NULL;
	node = (t_stack_op*)malloc(sizeof(t_stack_op));
	if (node == NULL)
		return (node);
	node->oper = data;
	node->previous = NULL;
	return (node);
}

void			ft_push_numb(t_stack_numb **begin_list, int data)
{
	t_stack_numb	*buff;

	buff = ft_create_stnumb(data);
	if (*begin_list != 0)
		buff->previous = *begin_list;
	*begin_list = buff;
}

void			ft_push_op(t_stack_op **begin_list, t_operation data)
{
	t_stack_op	*buff;

	buff = ft_create_stop(data);
	if (*begin_list != 0)
		buff->previous = *begin_list;
	*begin_list = buff;
}
