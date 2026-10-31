/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:13:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/31 16:29:48 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv)
{
	t_stack		*stack_a;
	t_lst_op	*lst_operations;
	int			*lst_a;
	int			res;

	if (check_valid_lst(lst_a) == -1)
		return (handle_error());
	stack_a = create_stack(lst_a);
	if (!stack_a)
		return (handle_error());
	if (STRATEGY)
		res = call_strategy(STRATEGY, &stack_a, &lst_operations);
	else
		res = adaptive(&stack_a, &lst_operations);
	clear_stack(stack_a);
	clear_lst_operations(lst_operations);
	if (res == -1)
		return (handle_error());
	return (0);
}
