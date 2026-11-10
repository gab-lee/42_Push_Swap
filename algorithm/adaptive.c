/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:37:28 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/08 12:21:04 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	adaptive(t_stack **stack_a, t_lst_op **lst_op)
{
	double	disorder;

	disorder = 0.0; //to update once disorder metric created
	if (disorder < 0.2)
		return (call_strategy("simple", stack_a, lst_op));
	if (disorder >= 0.2 && disorder < 0.5)
		return (call_strategy("medium", stack_a, lst_op));
	if (disorder >= 0.5)
		return (call_strategy("complex", stack_a, lst_op));
	else
		return (-1);
}