/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:19:21 by snorcros          #+#    #+#             */
/*   Updated: 2019/08/18 21:55:32 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sub(int a, int b)
{
	return (a - b);
}

int		ft_mul(int a, int b)
{
	return (a * b);
}

int		ft_mod(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a % b);
}

int		ft_div(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a / b);
}
