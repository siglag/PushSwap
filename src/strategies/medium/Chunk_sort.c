#include "push_swap.h"

int	medium_strategy(t_stack *stack)
{
	printf("Using medium strategy\n");
	return (stack->size_a + stack->size_b + 1);
}
