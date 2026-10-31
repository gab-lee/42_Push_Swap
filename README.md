*This project has been created as part of the 42 curriculum by <login1>, <login2>.*

# 42_Push_swap

## Description

push_swap sorts a stack of integers using two stacks (`a` and `b`) and a limited
set of operations (`sa sb ss pa pb ra rb rr rra rrb rrr`), printing the shortest
sequence of operations it can find, one per line on stdout.

The program embeds four strategies and picks one at runtime:

| Flag         | Strategy                      | Complexity (in operations) |
|--------------|-------------------------------|----------------------------|
| `--simple`   | Simple                        | O(n²)                      |
| `--medium`   | Medium                        | O(n√n)                     |
| `--complex`  | Complex                       | O(n log n)                 |
| `--adaptive` | Adaptive (default, see below) | depends on disorder        |

`--bench` additionally prints to stderr: the disorder (% with two decimals), the
strategy name and complexity class, the total operation count and the count of
each operation type.

## Instructions

```
make            # builds push_swap
make clean      # removes object files
make fclean     # removes objects and binary
make re         # fclean + all

./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
```

Examples:

```
./push_swap 2 1 3 6 5 8
./push_swap --complex 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
./push_swap --bench $(shuf -i 0-9999 -n 500) 2> bench.txt >/dev/null
```

No arguments prints nothing. Invalid input (non-integers, out of `int` range,
duplicates) prints `Error` followed by a newline on stderr.

Target benchmarks: 100 numbers < 700 ops (excellent), 500 numbers < 5500 ops (excellent).

## File structure

```
.
├── Makefile
├── README.md
├── push_swap.h              # types, prototypes
├── push_swap.c              # main: argument parsing, strategy selection
├── disorder_metric.c        # disorder computation
├── algorithm/
│   ├── simple.c             # O(n²) strategy
│   ├── medium.c             # O(n√n) strategy
│   ├── complex.c            # O(n log n) strategy
│   └── adaptive.c           # picks a strategy from the disorder
├── Operations/
│   ├── call_operation.c     # dispatches an operation by name
│   ├── push.c               # pa, pb
│   ├── swap.c               # sa, sb, ss
│   ├── rotate.c             # ra, rb, rr
│   └── reverse_rotate.c     # rra, rrb, rrr
├── utility/
│   └── check_valid_stack.c  # input validation
└── libft/
    └── ft_lst*.c            # linked-list helpers (t_list)
```

## Disorder metric

Computed once on the initial stack `a`, before any move: the number of pairs
`(i, j)` with `i < j` and `a[i] > a[j]`, divided by the total number of pairs.
0 means sorted, 1 means fully reversed. It is O(n²) to compute, which is
negligible next to the operation count.

## Algorithms

> TODO: fill in once implemented. The subject requires a detailed explanation
> and justification of each algorithm.

### Simple — O(n²)
- Technique: _TBD_
- Why chosen: _TBD_

### Medium — O(n√n)
- Technique: _TBD_
- Why chosen: _TBD_

### Complex — O(n log n)
- Technique: _TBD_
- Why chosen: _TBD_

### Adaptive
Selects a strategy from the measured disorder:

| Disorder        | Regime | Required complexity | Method |
|-----------------|--------|---------------------|--------|
| < 0.2           | Low    | O(n²)               | _TBD_  |
| 0.2 ≤ d < 0.5   | Medium | O(n√n)              | _TBD_  |
| ≥ 0.5           | High   | O(n log n)          | _TBD_  |

- Rationale for thresholds: _TBD_
- Time/space upper bounds (in Push_swap operations): _TBD_

## Contributions

| Part                                   | Author |
|----------------------------------------|--------|
| Operations: push, rotate               | JR     |
| Operations: swap, reverse rotate       | Gab    |
| Disorder metric                        | JR     |
| Input validation (`check_valid`)       | Gab    |
| Simple and Medium algorithms           | JR     |
| Complex algorithm                      | Gab    |
| Operation list printing                | Gab    |

Both authors understand and can explain all parts of the code.

## Resources

- Big-O / algorithmic complexity: https://en.wikipedia.org/wiki/Big_O_notation
- Sorting algorithms (selection, insertion, radix, quick, merge): _add the references you used_
- 42 push_swap subject (v1.2)

**AI usage:** _TBD — state which tasks and which parts of the project AI was used for._
(So far: fixing includes/indentation in `libft/*.c` and `Operations/call_operation.c`.)

---

## Working notes (original team notes)

1. Code operations
int op(stack a, stack b) 
- push - JR
- swap - Gab
- rotate - Jr
- reverse - Gab

1. disorder
int disorder(stack a) - Jr

1. check_valid  - Gab
int checker (stack a)
- check stack a is valid list of integers > 1
- if number 1 -> 0 (no sorting required)
- if invalid -> -1
not integers, integers outside the
valid range, or duplicate values.
0 successful
-1 fail

1. choose alogorithm (adaptive)
if (!algo)
	choose algo
algo

1. algorithims
int algo (stack a, lst_operations)
0 successful
-1 fail

- simple - Jr
- Medium - Jr
- Complex - Gab

1. print_lst_op - Gab

typedef struct *s_lst_op{

	char *lst_op->op 
	next

} t_lst_op
