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

int	count_operations(t_parsed *parsed)
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

char	*strategy_name(t_parsed *parsed)
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
	printf("[bench] strategy: %s / %s\n", strategy_name(parsed), bench_strategy(parsed));
	printf("[bench] total_ops: %d\n", count_operations(parsed));
	printf("[bench] sa: %d  sb: %d  ss: %d  ", parsed->operations.sa, parsed->operations.sb, parsed->operations.ss);
	printf("pa: %d  pb: %d\n", parsed->operations.pa, parsed->operations.pb);
	printf("[bench] ra: %d  rb: %d  rr: %d  ", parsed->operations.ra, parsed->operations.rb, parsed->operations.rr);
	printf("rra: %d  rrb: %d  rrr: %d\n", parsed->operations.rra, parsed->operations.rrb, parsed->operations.rrr);
	return (1);
}
