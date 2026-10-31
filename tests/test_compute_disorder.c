#include <stdio.h>
#include <stdint.h>
#include "../push_swap.h"

double	compute_disorder(t_stack **stack_a);

static t_stack	*build_stack(const int *values, int n)
{
	t_stack	*head;
	t_stack	*node;
	int		i;

	head = NULL;
	i = n;
	while (i-- > 0)
	{
		node = malloc(sizeof(t_stack));
		node->content = (void *)(intptr_t)values[i];
		node->next = head;
		head = node;
	}
	return (head);
}

static void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

static int	run_test(const char *name, const int *values, int n, double expected)
{
	t_stack	*stack;
	double	result;
	double	diff;

	stack = build_stack(values, n);
	result = compute_disorder(&stack);
	free_stack(stack);
	diff = result - expected;
	if (diff < 0)
		diff = -diff;
	if (diff < 0.0001)
		printf("PASS  %-26s -> %.2f\n", name, result);
	else
		printf("FAIL  %-26s -> got %.2f, expected %.2f\n",
			name, result, expected);
	return (diff >= 0.0001);
}

int	main(void)
{
	int	sorted[] = {1, 2, 3, 4, 5};
	int	reversed[] = {5, 4, 3, 2, 1};
	int	mixed[] = {3, 1, 2, 5, 4};
	int	negatives[] = {-3, -1, -2};
	int	two_sorted[] = {1, 2};
	int	two_reversed[] = {2, 1};
	int	single[] = {7};
	int	failures;

	failures = 0;
	failures += run_test("sorted", sorted, 5, 0.0);
	failures += run_test("reversed", reversed, 5, 1.0);
	failures += run_test("mixed (3/10)", mixed, 5, 0.3);
	failures += run_test("negatives (1/3)", negatives, 3, 1.0 / 3.0);
	failures += run_test("two sorted", two_sorted, 2, 0.0);
	failures += run_test("two reversed (1/1)", two_reversed, 2, 1.0);
	failures += run_test("single element", single, 1, 0.0);
	printf("\n%d failure(s)\n", failures);
	return (failures != 0);
}
