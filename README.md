_This activity has been created as part of the 42 curriculum by mohmmah, sbanimou_

# Push_swap

## Description

**push_swap** sorts a stack of integers using a limited set of operations and prints the operation sequence that does it. Two stacks are involved: `a` (holds the input) and `b` (auxiliary). A strategy is picked from the input's disorder, or forced with a flag.

## Project flow

```
argv
  |
  v
parser
  |-- Validator       validate flags and argument order
  |-- Parser_utils   parse integers, reject duplicates
  |
  v
calculate_disorder
  |                     inversion ratio of the input
  v
strategies_router
  |
  |-- init_stack       initialize stack A, stack B
  |
  |-- choose_strategy
  |     ADAPTIVE:
  |       disorder < 0.20        → SIMPLE
  |       0.20 ≤ disorder < 0.50 → MEDIUM
  |       disorder ≥ 0.50        → COMPLEX
  |
  |-- dispatch
  |     SIMPLE   → Selection Sort
  |     MEDIUM   → Chunk Sort
  |     COMPLEX  → LSD Radix Sort
  |
  |-- operations      execute and count Push_swap operations
  |
  |-- free_stack
  |
  v
bench
  |
  |-- only with --bench
  |-- print disorder, strategy, complexity and operation counts
  |
  v
free_parsed
```

## Modules

- **`src/main.c`** — wires the pipeline: parse, measure disorder, route, bench, free. Single place for lifecycle and `Error\n` handling on failure.

- **`src/input/`** — `Parser`, `Validator`, `Parser_utils`. Turns argv into a validated `t_parsed` (sequence, strategy, bench flag). Validates flag placement and names, parses numbers, rejects duplicates. Why: keeps edge cases out of the sorting code.

- **`src/strategies/`** — `Router` + one file per algorithm. Router builds the stack, resolves the strategy (including adaptive thresholds on disorder), runs it, frees the stack. `Selection_sort` handles tiny inputs, `Chunk_sort` pushes indexed chunks to `b` then returns them in order, `Redix_sort` sorts by indexed bits. Why: different sizes suit different algorithms; the router isolates that choice.

- **`src/operations/`** — `swap`, `push`, `rotate`, `reverse_rotate`: the 11 allowed ops (`sa/sb/ss`, `pa/pb`, `ra/rb/rr`, `rra/rrb/rrr`). Each mutates the stacks, optionally prints its name, and counts itself when bench is on. Why: the only vocabulary sorters may use, centralized so printing and counting stay consistent.

- **`src/utils/`** — shared helpers: `init_stack`/`free_stack`, `index_stack` (rank compression so chunk/radix work on dense indexes), `is_sorted`, `Disorder` (inversion ratio), `Bench` (stats dump), plus string utilities (`String`, `Split`, `Itoa`, `Double_toa`). Why: infrastructure used by parser, router and strategies.

- **`src/printf/`** — minimal `ft_printf`. Why: 42 constraint; used for errors and bench output.

## Algorithm Selection

### Simple — Selection Sort

Selection sort is used for inputs with low disorder and small stacks.

The algorithm repeatedly finds the smallest element in stack `a`, moves it to the top using the shortest rotation direction, and pushes it to stack `b`. After the remaining elements are sorted, the elements are pushed back to `a`.

This approach is simple and predictable for small inputs.

```text
find minimum → rotate A → pb
repeat until A is small
sort remaining elements
pa everything back to A
```

**Complexity:** O(n²)

---

### Medium — Chunk Sort

The Medium strategy divides the normalized input into smaller ranges called chunks.

Elements belonging to the current chunk are pushed from `a` to `b`. Rotations are used to organize the elements in `b`. Once all elements are in `b`, the largest elements are pushed back to `a` in descending order so that `a` becomes sorted.

Chunk sorting reduces the amount of searching compared with treating every element independently.

```text
A → divide into chunks → push chunks to B
                         ↓
                    organize B
                         ↓
                    push back to A
```

**Current complexity:** O(n√n)

---

### Complex — LSD Radix Sort

The Complex strategy uses LSD (Least Significant Digit) Radix Sort on normalized indexes.

The elements are processed bit by bit. For each bit, elements with a `0` bit are pushed to `b`, while elements with a `1` bit are rotated in `a`. The elements in `b` are then pushed back to `a`.

The process continues from the least significant bit to the most significant bit.

```text
process bit 0
    ↓
process bit 1
    ↓
process bit 2
    ↓
...
```

Radix sort
**Complexity:** O(nlogn)

## Adaptive Strategy

The strategy is selected according to the input disorder:

```text
< 0.20        → Simple
0.20 – < 0.50 → Medium
≥ 0.50        → Complex
```

- **Simple:** Selection sort, O(n²)
- **Medium:** Chunk sort, currently O(n²)
- **Complex:** LSD Radix sort, O(n log n)

All strategies use O(n) stack space. The thresholds are used to match the sorting method to the input's level of disorder.

## Usage

```bash
make
./push_swap 4 67 3 87 23
./push_swap --bench --medium 4 67 3 87 23
```

Flags: `--simple`, `--medium`, `--complex`, `--adaptive` (default), `--bench` (print stats instead of the operation sequence). Flags come before the numbers; numbers may be space-separated in a single argument.

## Instructions

## Build

```bash
make          # build
make clean    # remove objects
make fclean   # remove objects + binary
make re       # rebuild
```

## Testing

The program was tested with:

- Small inputs
- Random inputs
- Already sorted inputs
- Reverse sorted inputs
- Duplicate values
- Invalid arguments
- Different strategy flags
- Benchmark mode

## Resources

1. 42 Push_swap subject.
2. C documentation.
3. Algorithm and data structure references.

## AI Usage

AI tools were used as a supporting resource during the project for research, troubleshooting, and documentation.

## Authors

- `mohmmah`
- `sbanimou`
