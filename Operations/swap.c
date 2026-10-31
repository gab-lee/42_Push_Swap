/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:12:40 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/31 11:12:41 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack_a, t_stack **stack_b)
{
	(void) stack_b;
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a; 
	*stack_a = temp;
	return (0);
}