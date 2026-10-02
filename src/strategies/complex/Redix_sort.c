#include "push_swap.h"

int	complex_strategy(t_stack *stack)
{
	printf("Using complex strategy\n");
	return (stack->size_a + stack->size_b + 1);
}
