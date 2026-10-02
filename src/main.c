/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/02 15:24:40 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_parsed(t_parsed *parsed)
{
	size_t	index;

	printf("  strategy:      %d\n", parsed->strategy);
	printf("  is_bench:      %d\n", parsed->is_bench);
	printf("  sequence_size: %zu\n", parsed->sequence_size);
	printf("  sequence:      ");
	index = 0;
	while (index < parsed->sequence_size)
	{
		printf("%d", parsed->sequence[index]);
		if (index + 1 < parsed->sequence_size)
			printf(", ");
		index++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_parsed	*parsed;

	printf("=== push_swap parser test ===\n");
	printf("argc: %d\n", argc);
	parsed = parser(argc, argv);
	if (!parsed)
	{
		printf("RESULT: REJECTED\n");
		return (1);
	}
	if (!disorder(parsed) || !strategies_router(parsed))
	{
		printf("RESULT: REJECTED\n");
		free_parsed(parsed);
		return (1);
	}
	printf("RESULT: ACCEPTED\n");
	print_parsed(parsed);
	free_parsed(parsed);
	return (0);
}
