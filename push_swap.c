/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:13:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/09 10:38:50 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv)
{
	t_stack		*stack_a;
	t_lst_op	*lst_op;
	t_bench		*bench;
	int			*lst_a;
	int			res;

	if (argc == 0)
		return (handle_error());
	lst_a = argv[0];
	if (check_valid_lst(lst_a) == -1)
		return (handle_error());
	stack_a = create_stack(lst_a);
	if (!stack_a)
		return (handle_error());
	if (argc == 0)
		return (handle_error()); // If no parameters are specified, the program must not display anything and give the prompt back.
	else if (argc == 2)
		res = call_strategy(argv[1], &stack_a, &lst_op);
	else
		res = adaptive(&stack_a, &lst_op);
	ft_lstclear(stack_a, del);
	ft_lstclear(lst_op, del);
	if (res == -1)
		return (handle_error());
	return (0);
}
