/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:09:27 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/09 10:17:03 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	call_strategy(char *strategy, t_stack **stack_a, t_lst_op **lst_op)
{
	int	len;

	len = ft_strlen(strategy);
	if (ft_strncmp(strategy, "--simple", len) == 0)
		return (simple(stack_a, lst_op));
	if (ft_strncmp(strategy, "--medium", len) == 0)
		return (medium(stack_a, lst_op));
	if (ft_strncmp(strategy, "--complex", len) == 0)
		return (complex(stack_a, lst_op));
	if (ft_strncmp(strategy, "--adaptive", len) == 0)
		return (adaptive(stack_a, lst_op));
	else
		return (-1);
}