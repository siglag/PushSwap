#include "push_swap.h"

int	simple_strategy(t_stack *stack)
{
	printf("Using simple strategy\n");
	return (stack->size_a + stack->size_b + 1);
}
