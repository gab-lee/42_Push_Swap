/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiechang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:56:44 by jiechang          #+#    #+#             */
/*   Updated: 2026/11/15 00:33:04 by jiechang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cnt_smaller(t_stack *stack, t_stack *node)
{
	int	cnt;

	cnt = 0;
	while (stack)
	{
		if ((int)(long)stack->content < (int)(long)node->content)
			cnt++;
		stack = stack->next;
	}
	return (cnt);
}

static int	push_chunks(t_stack **stack_a, t_stack **stack_b,
		t_lst_op **ops, int width)
{
	int	pushed;
	int	rank;

	pushed = 0;
	while (*stack_a)
	{
		rank = cnt_smaller(*stack_a, *stack_a)
			+ cnt_smaller(*stack_b, *stack_a);
		if (rank > pushed + width)
		{
			if (call_op("ra", stack_a, stack_b, ops) == -1)
				return (-1);
			continue ;
		}
		if (call_op("pb", stack_a, stack_b, ops) == -1)
			return (-1);
		if (rank < pushed && call_op("rb", stack_a, stack_b, ops) == -1)
			return (-1);
		pushed++;
	}
	return (0);
}

static int	max_pos(t_stack *stack)
{
	t_stack	*node;
	int		size;
	int		pos;

	size = (int)ft_lstsize(stack);
	node = stack;
	pos = 0;
	while (cnt_smaller(stack, node) != size - 1)
	{
		node = node->next;
		pos++;
	}
	return (pos);
}

static int	push_back(t_stack **stack_a, t_stack **stack_b, t_lst_op **ops)
{
	int	size;
	int	pos;

	while (*stack_b)
	{
		size = (int)ft_lstsize(*stack_b);
		pos = max_pos(*stack_b);
		while (pos > 0 && pos <= size / 2)
		{
			if (call_op("rb", stack_a, stack_b, ops) == -1)
				return (-1);
			pos--;
		}
		while (pos < size && pos > size / 2)
		{
			if (call_op("rrb", stack_a, stack_b, ops) == -1)
				return (-1);
			pos++;
		}
		if (call_op("pa", stack_a, stack_b, ops) == -1)
			return (-1);
	}
	return (0);
}

int	medium(t_stack **stack_a, t_lst_op **ops)
{
	t_stack	*stack_b;
	int		width;
	int		size;
	int		result;

	if (!(*stack_a) || !(*stack_a)->next || compute_disorder(stack_a) == 0)
		return (0);
	width = 1;
	size = (int)ft_lstsize(*stack_a);
	while (width * width <= size)
		width++;
	width--;
	stack_b = NULL;
	result = push_chunks(stack_a, &stack_b, ops, width * 3 / 2);
	if (result == 0)
		result = push_back(stack_a, &stack_b, ops);
	ft_lstclear(&stack_b, del);
	return (result);
}
