/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:22:09 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/08 12:22:26 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_operation(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(operation, "rra", 3))
		return (r_rotate(stack_a, stack_b));
	if (!ft_strncmp(operation, "rrb", 3))
		return (r_rotate(stack_b, stack_a));
	if (!ft_strncmp(operation, "rrr", 3))
		return (r_rotate(stack_a, stack_b) && r_rotate(stack_b, stack_a));
	if (!ft_strncmp(operation, "pa", 2))
		return (push(stack_a, stack_b));
	if (!ft_strncmp(operation, "pb", 2))
		return (push(stack_b, stack_a));
	if (!ft_strncmp(operation, "sa", 2))
		return (swap(stack_a, stack_b));
	if (!ft_strncmp(operation, "sb", 2))
		return (swap(stack_b, stack_a));
	if (!ft_strncmp(operation, "ra", 2))
		return (rotate(stack_a, stack_b));
	if (!ft_strncmp(operation, "rb", 2))
		return (rotate(stack_b, stack_a));
	if (!ft_strncmp(operation, "rr", 2))
		return (rotate(stack_a, stack_b) && rotate(stack_b, stack_a));
	return (-1);
}
