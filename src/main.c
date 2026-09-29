/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/29 11:42:49 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_parsed	*parsed;

	parsed = parser(argc, argv);
	if (!parsed)
	{
		fprintf(stderr, "Error: Failed to parse input\n");
		return (1);
	}
	printf("Parsing successful: %s\n", parsed ? "true" : "false");
	printf("Parsed sequence size: %zu\n", parsed->sequence_size);
	printf("Parsed strategy: %d\n", parsed->strategy);
	printf("Parsed is_bench: %d\n", parsed->is_bench);
	printf("Parsed sequence: %zu\n", parsed->sequence_size);
	free_parsed(parsed);
	return (0);
}
