/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/29 11:22:15 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_parsed *parsed;

	parsed = parser(argc, argv);
	printf("Parsed sequence size: %zu\n", parsed->sequence_size);
	printf("Parsed strategy: %d\n", parsed->strategy);
	printf("Parsed is_bench: %d\n", parsed->is_bench);
	printf("Parsed sequence: %zu\n", parsed->sequence_size);
	// printf("test result: %d\n", validate_format(argc, argv));
	free_parsed(parsed);
	return (0);
}
