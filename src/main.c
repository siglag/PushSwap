/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/02 23:24:11 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// all of this shit is temp, will deal with it later when we're done with the strategies
static void	print_parsed(t_parsed *parsed)
{
	size_t	index;

	printf("\tstrategy:      %s / %s / %d \n", strategy_name(parsed), bench_strategy(parsed), parsed->strategy);
	printf("\tis_bench:      %d\n", parsed->is_bench);
	printf("\tdisorder: %f%%\n", parsed->disorder * 100);
	printf("\tsequence_size: %zu\n", parsed->sequence_size);
	printf("\tsequence:      ");
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
	if (!calculate_disorder(parsed))
	{
		printf("RESULT: REJECTED\n");
		free_parsed(parsed);
		return (1);
	}

	if (!strategies_router(parsed))
	{
		printf("RESULT: REJECTED\n");
		free_parsed(parsed);
		return (1);
	}
	bench(parsed);
	printf("RESULT: ACCEPTED\n");
	print_parsed(parsed);
	free_parsed(parsed);
	return (0);
}
