/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:36:21 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/09 09:29:12 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_complex(t_stack **stack_a, t_lst_op **lst_op, int bit_index);
static int	mv_zero_atob(t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op, int bit_index);
static int	mv_zero_btoa(t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op);
static void	del(void *content);

int	complex(t_stack **stack_a, t_lst_op **lst_op)
{
	int	i;
	int	bit_len;

	i = -1;
	bit_len = get_bit_loop(stack_a);
	while (++i, i < bit_len)
		if (solve_complex(stack_a, lst_op, i) == -1)
			return (-1);		
	return (0);
}

static int	get_bit_loop(t_stack **stack_a)
{
	t_stack			*cur;
	int				bit_len;

	cur = *stack_a;
	bit_len = 0;
	while (cur)
	{
		if ((int)(cur->content) >> bit_len != 0)
		{
			bit_len++;
			continue ;
		}
		cur = cur->next;
	}
	return (bit_len);
}

static int	solve_complex(t_stack **stack_a, t_lst_op **lst_op, int bit_index)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (mv_zero_atob(stack_a, &stack_b, lst_op, bit_index) == -1)
	{
		ft_lstclear(&stack_b, del);
		return (-1);
	}
	if (mv_zero_btoa(stack_a, &stack_b, lst_op) == -1)
	{
		ft_lstclear(&stack_b, del);
		return (-1);
	}
	return (0);
}

static int	mv_zero_atob(t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op, int bit_index)
{
	int				i;
	unsigned int	stack_len;

	stack_len = ft_lstsize(*stack_a);
	i = -1;
	while (++i, i < stack_len)
	{
		if ((((int)(*stack_a)->content) >> bit_index & 1) == 1)
		{
			if (call_op("ra", stack_a, stack_b, lst_op) == -1)
				return (-1);
			continue ;
		}
		if (call_op("pb", stack_a, stack_b, lst_op) == -1)
			return (-1);
	}
	return (0);
}
static int mv_zero_btoa(t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op)
{
	int	i;
	int	stack_len;

	i = -1;
	stack_len = ft_lstsize(*stack_b);
	while (++i, i < stack_len)
	{
		if (call_op("pa", stack_a, stack_b, lst_op) == -1)
			return (-1);
	}
	return (0);
}

static void	del(void *content)
{
	(void)content;
}
