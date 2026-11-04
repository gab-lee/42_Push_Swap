#include "test_utils.h"

/* Operations are dispatched by name through call_operation.c.
** The tests expect the signature the operations themselves use (t_stack **). */
int	cal_operation(char *operation, t_stack **stack_a, t_stack **stack_b);

static int	check_op(const char *op, const int *a_in, int na, const int *b_in,
		int nb, const int *a_out, int na_out, const int *b_out, int nb_out)
{
	t_stack	*a;
	t_stack	*b;
	char	name[64];
	int		ok;

	a = build_stack(a_in, na);
	b = build_stack(b_in, nb);
	cal_operation((char *)op, &a, &b);
	ok = stack_equals(a, a_out, na_out) && stack_equals(b, b_out, nb_out);
	free_stack(a);
	free_stack(b);
	snprintf(name, sizeof(name), "%s (a:%d b:%d)", op, na, nb);
	return (report(name, ok));
}

int	main(void)
{
	int	f;
	int	a123[] = {1, 2, 3};
	int	a213[] = {2, 1, 3};
	int	a231[] = {2, 3, 1};
	int	a312[] = {3, 1, 2};
	int	b456[] = {4, 5, 6};
	int	b546[] = {5, 4, 6};
	int	b564[] = {5, 6, 4};
	int	b645[] = {6, 4, 5};
	int	a23[] = {2, 3};
	int	b1456[] = {1, 4, 5, 6};
	int	a1[] = {1};
	int	a12[] = {1, 2};
	int	a21[] = {2, 1};
	int	b45[] = {4, 5};
	int	a4123[] = {4, 1, 2, 3};
	int	b56[] = {5, 6};

	f = 0;
	f += check_op("sa", a123, 3, b456, 3, a213, 3, b456, 3);
	f += check_op("sb", a123, 3, b456, 3, a123, 3, b546, 3);
	f += check_op("pa", a123, 3, b456, 3, a4123, 4, b56, 2);
	f += check_op("pb", a123, 3, b456, 3, a23, 2, b1456, 4);
	f += check_op("ra", a123, 3, b456, 3, a231, 3, b456, 3);
	f += check_op("rb", a123, 3, b456, 3, a123, 3, b564, 3);
	f += check_op("rr", a123, 3, b456, 3, a231, 3, b564, 3);
	f += check_op("rra", a123, 3, b456, 3, a312, 3, b456, 3);
	f += check_op("rrb", a123, 3, b456, 3, a123, 3, b645, 3);
	f += check_op("rrr", a123, 3, b456, 3, a312, 3, b645, 3);
	/* edge cases: nothing to do, nothing should break */
	f += check_op("sa", a1, 1, b456, 3, a1, 1, b456, 3);
	f += check_op("ra", a1, 1, b456, 3, a1, 1, b456, 3);
	f += check_op("rra", a1, 1, b456, 3, a1, 1, b456, 3);
	f += check_op("sa", NULL, 0, b456, 3, NULL, 0, b456, 3);
	f += check_op("pa", a12, 2, NULL, 0, a12, 2, NULL, 0);
	f += check_op("pb", NULL, 0, b45, 2, NULL, 0, b45, 2);
	f += check_op("ra", a12, 2, b45, 2, a21, 2, b45, 2);
	printf("\n%d failure(s)\n", f);
	return (f != 0);
}
