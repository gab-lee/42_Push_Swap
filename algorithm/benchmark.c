/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:24:38 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/09 10:47:15 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_bench(t_bench *bench, t_lst_op *lst_op);
static void	count_swap_push(char *op, t_bench *bench);
static void	count_rotate(char *op, t_bench *bench);

int	benchmark(t_bench *bench, t_lst_op *lst_op)
{
	fill_bench(bench, lst_op);
	ft_printf("disorder: %d\n", bench->disorder);
	ft_printf("strategy: %s\n", bench->strategy);
	ft_printf("total_ops: %d\n", bench->total_ops);
	ft_printf("sa: %d\tsb: %d\tss: %d\tpa: %d\tpb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("ra: %d\trb: %d\trr: %d\trra: %d\trrb: %d\trrr: %d\n",
		bench->ra, bench->rb, bench->rr,
		bench->rra, bench->rrb, bench->rrr);
	return (0);
}

static void	fill_bench(t_bench *bench, t_lst_op *lst_op)
{
	bench->total_ops = ft_lstsize(lst_op);
	while (lst_op)
	{
		count_swap_push((char *)lst_op->content, bench);
		count_rotate((char *)lst_op->content, bench);
		lst_op = lst_op->next;
	}
}

static void	count_swap_push(char *op, t_bench *bench)
{
	if (!ft_strncmp(op, "sa", 3))
		bench->sa++;
	else if (!ft_strncmp(op, "sb", 3))
		bench->sb++;
	else if (!ft_strncmp(op, "ss", 3))
		bench->ss++;
	else if (!ft_strncmp(op, "pa", 3))
		bench->pa++;
	else if (!ft_strncmp(op, "pb", 3))
		bench->pb++;
}

static void	count_rotate(char *op, t_bench *bench)
{
	if (!ft_strncmp(op, "ra", 3))
		bench->ra++;
	else if (!ft_strncmp(op, "rb", 3))
		bench->rb++;
	else if (!ft_strncmp(op, "rr", 3))
		bench->rr++;
	else if (!ft_strncmp(op, "rra", 4))
		bench->rra++;
	else if (!ft_strncmp(op, "rrb", 4))
		bench->rrb++;
	else if (!ft_strncmp(op, "rrr", 4))
		bench->rrr++;
}




