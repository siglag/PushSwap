/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/29 17:39:43 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_parsed	*parsed;
	size_t		index;

	printf("[main]Main function called with %d arguments\n", argc);
	printf("[main]Testing count_numbers function: %d\n", count_numbers(argv[1]));
	parsed = parser(argc, argv);
	if (!parsed)
	{
		fprintf(stderr, "Error: Failed to parse input\n");
		return (1);
	}
	printf("[main]Parsing successful: %s\n", parsed ? "true" : "false");
	printf("[main]Parsed strategy: %d\n", parsed->strategy);
	printf("[main]Parsed is_bench: %d\n", parsed->is_bench);
	printf("[main]Parsed sequence size: %zu\n", parsed->sequence_size);
	index = 0;
	while (index < parsed->sequence_size)
	{
		printf("[main][%zu] Parsed sequence: %d\n", index, parsed->sequence[index]);
		index++;
	}
	free_parsed(parsed);
	return (0);
}
