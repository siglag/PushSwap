_This activity has been created as part of the 42 curriculum by mohmmah, sbanimou_

# Push_swap
## Description
**push_swap** sorts a stack of integers using a limited set of operations and prints the operation sequence that does it. Two stacks are involved: `a` (holds the input) and `b` (auxiliary). A strategy is picked from the input's disorder, or forced with a flag.

## Project flow

```
argv
  |
  v
parser                     validate argv, extract sequence + flags
  |-- Validator            flags before numbers, known flags only
  |-- Parser_utils         parse ints, reject duplicates
  v
calculate_disorder         inversion ratio of the sequence
  |
  v
strategies_router
  |-- init_stack           copy sequence into stack a
  |-- choose_strategy      ADAPTIVE: disorder < 0.2 -> SIMPLE
  |                       disorder < 0.5 -> MEDIUM, else COMPLEX
  |-- dispatch
  |     SIMPLE   selection sort    small inputs (2-5)
  |     MEDIUM   chunk sort        medium inputs (6-100)
  |     COMPLEX  radix sort        large inputs
  |-- operations           every op mutates stacks, prints and/or counts
  |-- free_stack
  |
  v
bench                      only with --bench: print disorder, strategy, op counts
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
