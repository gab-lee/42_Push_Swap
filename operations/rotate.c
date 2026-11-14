/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiechang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:23:23 by jiechang          #+#    #+#             */
/*   Updated: 2026/11/14 09:48:52 by jiechang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	
	(void)stack_b;
	if (!*stack_a || !(*stack_a)->next)
		return (0);
	temp = (*stack_a)->next;
	ft_lstlast(*stack_a)->next = *stack_a;
	(*stack_a)->next = NULL;
	*stack_a = temp;
	return (0);
}

