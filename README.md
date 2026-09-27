_This activity has been created as part of the 42 curriculum by mohmmah, sbanimou_

# Push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.

The goal is to sort a stack of integers using a limited set of operations while producing the smallest possible sequence of instructions.

The project consists of two stacks:

- `a` — the main stack containing the input numbers.
- `b` — an auxiliary stack used during sorting.

The program receives a list of integers as arguments and outputs the operations required to sort them.

## Operations

The available operations are:

- `sa` / `sb` / `ss` — swap
- `pa` / `pb` — push
- `ra` / `rb` / `rr` — rotate
- `rra` / `rrb` / `rrr` — reverse rotate

## Usage

```bash
make

./push_swap 4 67 3 87 23
```

The program outputs a sequence of valid operations that sorts the numbers.

## Build

```bash
make
```

Clean build files:

```bash
make clean
```

Full cleanup:

```bash
make fclean
```

Rebuild:

```bash
make re
```

## Authors

- `mohmmah`
- `sbanimou`
