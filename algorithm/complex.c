/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:36:21 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/08 19:08:29 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	solve_complex(t_stack **stack_a, t_lst_op **lst_op, int stack_len);

int	complex(t_stack **stack_a, t_lst_op **lst_op)
{
	int	i;
	int stack_len;

	i = -1;
	stack_len = ft_lstsize(*stack_a);
	while (++i, i < len(bitwise(max)))
		solve_complex(stack_a, lst_op, stack_len);
	return (0);
}

static int	solve_complex(t_stack **stack_a, t_lst_op **lst_op, int stack_len)
{
	int		i;
	t_stack	*stack_b;

	i = -1;
	stack_b = NULL;
	while (++i, i < stack_len)
	{
		if (stack_a == 0)
			call_op("ra", stack_a, &stack_b);
		else
			call_op("pb", stack_a, &stack_b);
	}
	stack_len = ft_lstsize(stack_b);
	i = -1;
	while (++i, i < stack_len)
	{
		
	}
}