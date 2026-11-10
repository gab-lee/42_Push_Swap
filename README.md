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
├── push_swap.h                  # types, prototypes
├── push_swap.c                  # main: argument parsing, strategy selection
├── algorithm/
│   ├── simple.c                 # O(n²) strategy
│   ├── medium.c                 # O(n√n) strategy
│   ├── complex.c                # O(n log n) strategy
│   ├── adaptive.c               # picks a strategy from the disorder
│   └── disorder_metric.c        # disorder computation
├── Ops/
│   ├── call_op.c         # dispatches an operation by name
│   ├── push.c                   # pa, pb
│   ├── swap.c                   # sa, sb, ss
│   ├── rotate.c                 # ra, rb, rr
│   └── r_rotate.c               # rra, rrb, rrr
├── utility/
│   ├── check_valid_lst.c        # input validation
│   ├── check_valid_strategy.c   # strategy flag validation
│   ├── create_stack.c           # builds stack a from validated input
│   ├── clear_stack.c            # frees a stack
│   ├── clear_lst_op.c           # frees the operation list
│   └── handle_error.c           # prints the error message
└── libft/
    └── ft_lst*.c                # linked-list helpers (t_list)
```

## Data structures

| Type         | Fields                                  | Purpose                                      |
|--------------|-----------------------------------------|----------------------------------------------|
| `t_stack`    | `void *content`, `t_stack *next`        | One node of stack `a` or `b`                 |
| `t_lst_op`   | `void *op`, `t_lst_op *next`            | One recorded operation (name, e.g. `"ra"`)   |

## Function reference

Return convention: `0` success, `-1` failure, unless stated otherwise.
Status: **done** = implemented, **stub** = file exists but is empty or
unfinished, **planned** = used by `push_swap.c` but not yet declared in the
header.

### `Ops/`

Each operation takes the stack it acts on first and the other stack second, so
the `b` variants and the double operations are just calls with the arguments
swapped.

| Function | File | Prototype | What it does | Operations | Status |
|----------|------|-----------|--------------|------------|--------|
| `swap` | `swap.c` | `int swap(t_stack **stack_a, t_stack **stack_b)` | Swaps the first two nodes of the first stack; does nothing with fewer than two | `sa`, `sb`, `ss` | done |
| `push` | `push.c` | `int push(t_stack **stack_a, t_stack **stack_b)` | Moves the top of one stack onto the other | `pa`, `pb` | stub |
| `rotate` | `rotate.c` | `int rotate(t_stack **stack_a, t_stack **stack_b)` | Moves the first node of the first stack to the bottom | `ra`, `rb`, `rr` | stub |
| `r_rotate` | `r_rotate.c` | `int r_rotate(t_stack **stack_a, t_stack **stack_b)` | Moves the last node of the first stack to the top | `rra`, `rrb`, `rrr` | done |
| `call_op` | `call_op.c` | `int call_op(char *operation, t_stack **stack_a, t_stack **stack_b)` | Dispatches an operation name (`"pa"`, `"sb"`, `"rrr"`, ...) to the matching function above | all eleven | stub (compares strings with `==`, takes `t_stack` by value, not in header) |

### `algorithm/`

All strategies share one signature. They sort `stack_a` and append every
operation they apply to `lst_op`.

| Function | File | Prototype | What it does | Complexity | Status |
|----------|------|-----------|--------------|------------|--------|
| `simple` | `simple.c` | `int simple(t_stack **stack_a, t_lst_op **lst_op)` | Simple strategy | O(n²) | stub |
| `medium` | `medium.c` | `int medium(t_stack **stack_a, t_lst_op **lst_op)` | Medium strategy | O(n√n) | stub |
| `complex` | `complex.c` | `int complex(t_stack **stack_a, t_lst_op **lst_op)` | Complex strategy | O(n log n) | stub |
| `adaptive` | `adaptive.c` | `int adaptive(t_stack **stack_a, t_lst_op **lst_op)` | Measures the disorder, then calls `simple`, `medium` or `complex` | depends on disorder | stub |
| `compute_disorder` | `disorder_metric.c` | `double compute_disorder(t_stack **stack_a)` | Fraction of out-of-order pairs, from 0.0 (sorted) to 1.0 (reversed) | O(n²) | stub (file empty; not in header) |

### `utility/`

| Function | File | Prototype | What it does | Status |
|----------|------|-----------|--------------|--------|
| `check_valid_lst` | `check_valid_lst.c` | `int check_valid_lst(int *stack_a)` | Validates the input list: only integers, within `int` range, no duplicates. `0` valid, `-1` invalid | stub |
| `el_compare` | `el_compare.c` | `int el_compare(t_stack *a, t_stack *b)` | Compares the content of two nodes; positive if `a` is greater | planned (file removed; declared in header) |
| `handle_error` | `handle_error.c` | `int handle_error(void)` | Writes the error message to stderr and returns `-1` | done |
| `create_stack` | `create_stack.c` | called from `push_swap.c` | Builds stack `a` from the validated input | planned |
| `clear_stack` | `clear_stack.c` | called from `push_swap.c` | Frees every node of a stack | planned |
| `clear_lst_op` | `clear_lst_op.c` | called from `push_swap.c` | Frees the operation list | planned |
| `call_strategy` | `check_valid_strategy.c` | called from `push_swap.c` | Runs the strategy chosen by the flag, or errors on an unknown flag | planned |

### Entry point

| Function | File | What it does |
|----------|------|--------------|
| `main` | `push_swap.c` | Validates the input, builds stack `a`, runs the chosen strategy (default `adaptive`), frees everything and prints the error message on failure |

### `libft/`

Linked-list helpers on `t_list`: `ft_lstnew`, `ft_lstadd_front`,
`ft_lstadd_back`, `ft_lstlast`, `ft_lstsize`, `ft_lstdelone`, `ft_lstclear`,
`ft_lstiter`, `ft_lstmap`.

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
| Input validation (`check_valid_lst`)   | Gab    |
| Simple and Medium algorithms           | JR     |
| Complex algorithm                      | Gab    |
| Operation list printing                | Gab    |

Both authors understand and can explain all parts of the code.

## Resources

- Big-O / algorithmic complexity: https://en.wikipedia.org/wiki/Big_O_notation
- Sorting algorithms (selection, insertion, radix, quick, merge): _add the references you used_
- 42 push_swap subject (v1.2)
- Radix Sort Algorithm: https://www.youtube.com/watch?v=XiuSW_mEn7g

**AI usage:** _TBD — state which tasks and which parts of the project AI was used for._
(So far: fixing includes/indentation in `libft/*.c` and `Ops/call_op.c`.)

---

## Working notes (original team notes)

1. Code operations
int op(stack a, stack b) 
- push - JR
- swap - Gab x
- rotate - Jr
- reverse - Gab x

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

1. algorithims
int algo (stack a, lst_op)
0 successful
-1 fail

- simple - Jr
- Medium - Jr
- Complex - Gab
