#include "push_swap.h"

char	*bench_strategy(t_parsed *parsed)
{
	if (parsed->strategy == SIMPLE)
		return ("O(n2)");
	else if (parsed->strategy == MEDIUM)
		return ("O(n√n)");
	else if (parsed->strategy == COMPLEX)
		return ("O(n log n)");
	else
		return ("NULL");
}

int count_operations(t_parsed *parsed)
{
	parsed->operations.total += parsed->operations.pa;
	parsed->operations.total += parsed->operations.pb;
	parsed->operations.total += parsed->operations.ra;
	parsed->operations.total += parsed->operations.rb;
	parsed->operations.total += parsed->operations.rr;
	parsed->operations.total += parsed->operations.rra;
	parsed->operations.total += parsed->operations.rrb;
	parsed->operations.total += parsed->operations.rrr;
	parsed->operations.total += parsed->operations.sa;
	parsed->operations.total += parsed->operations.sb;
	parsed->operations.total += parsed->operations.ss;
	return (parsed->operations.total);
}

char *strategy_name(t_parsed *parsed)
{
	if (parsed->adaptive == true)
		return ("ADAPTIVE");
	else if (parsed->strategy == SIMPLE)
		return ("SIMPLE");
	else if (parsed->strategy == MEDIUM)
		return ("MEDIUM");
	else if (parsed->strategy == COMPLEX)
		return ("COMPLEX");
	else
		return ("UNKNOWN");
}

int	bench(t_parsed *parsed)
{
	if (!parsed->is_bench)
		return (0);
	printf("[bench] disorder: %.2f%%\n", parsed->disorder * 100);
	return (1);
}
