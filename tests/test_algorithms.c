#include "test_utils.h"

int	cal_operation(char *operation, t_stack **stack_a, t_stack **stack_b);

typedef int	(*t_algo)(t_stack **stack_a, t_lst_op **lst_operations);

/* Replays the recorded operations (op holds the operation name as a string)
** on a fresh copy of the input and checks that a ends up sorted, b empty. */
static int	replay_sorts(const int *values, int n, t_lst_op *ops)
{
	t_stack	*a;
	t_stack	*b;
	int		ok;

	a = build_stack(values, n);
	b = NULL;
	while (ops)
	{
		cal_operation((char *)ops->op, &a, &b);
		ops = ops->next;
	}
	ok = stack_is_sorted(a) && stack_size(a) == n && !b;
	free_stack(a);
	free_stack(b);
	return (ok);
}

static int	op_count(t_lst_op *ops)
{
	int	n;

	n = 0;
	while (ops)
	{
		n++;
		ops = ops->next;
	}
	return (n);
}

static int	run_case(const char *algo_name, t_algo algo, const char *case_name,
		const int *values, int n)
{
	t_stack		*a;
	t_lst_op	*ops;
	char		name[96];
	int			ok_sorted;
	int			ok_replay;

	a = build_stack(values, n);
	ops = NULL;
	algo(&a, &ops);
	ok_sorted = stack_is_sorted(a) && stack_size(a) == n;
	ok_replay = replay_sorts(values, n, ops);
	snprintf(name, sizeof(name), "%-8s %-14s (%d ops)", algo_name, case_name,
		op_count(ops));
	free_stack(a);
	return (report(name, ok_sorted && ok_replay));
}

static void	fill_pseudo_random(int *values, int n)
{
	unsigned int	seed;
	int				i;
	int				j;
	int				tmp;

	i = 0;
	while (i < n)
	{
		values[i] = i - n / 2;
		i++;
	}
	seed = 42;
	i = n - 1;
	while (i > 0)
	{
		seed = seed * 1103515245u + 12345u;
		j = (seed >> 8) % (i + 1);
		tmp = values[i];
		values[i] = values[j];
		values[j] = tmp;
		i--;
	}
}

int	main(void)
{
	const char	*names[] = {"simple", "medium", "complex", "adaptive"};
	t_algo		algos[] = {simple, medium, complex, adaptive};
	int			sorted[] = {1, 2, 3, 4, 5};
	int			reversed[] = {5, 4, 3, 2, 1};
	int			three[] = {2, 3, 1};
	int			five[] = {3, 1, 5, 2, 4};
	int			two[] = {2, 1};
	int			one[] = {7};
	int			big[100];
	int			f;
	int			i;

	fill_pseudo_random(big, 100);
	f = 0;
	i = 0;
	while (i < 4)
	{
		f += run_case(names[i], algos[i], "single", one, 1);
		f += run_case(names[i], algos[i], "two", two, 2);
		f += run_case(names[i], algos[i], "three", three, 3);
		f += run_case(names[i], algos[i], "already sorted", sorted, 5);
		f += run_case(names[i], algos[i], "reversed", reversed, 5);
		f += run_case(names[i], algos[i], "random 5", five, 5);
		f += run_case(names[i], algos[i], "random 100", big, 100);
		i++;
	}
	printf("\n%d failure(s)\n", f);
	return (f != 0);
}
