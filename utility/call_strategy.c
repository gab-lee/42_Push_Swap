/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:09:27 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/08 12:14:42 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	call_strategy(char *strategy, t_stack **stack_a, t_lst_op **lst_operations)
{
	int	len;

	len = ft_strlen(strategy);
	if (ft_strncmp(strategy, "simple", len) == 0)
		return (simple(stack_a, lst_operations));
	if (ft_strncmp(strategy, "medium", len) == 0)
		return (medium(stack_a, lst_operations));
	if (ft_strncmp(strategy, "complex", len) == 0)
		return (complex(stack_a, lst_operations));
	else
		return (-1);
}