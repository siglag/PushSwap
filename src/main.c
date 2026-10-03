/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 12:10:53 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_parsed	*parsed;

	parsed = parser(argc, argv);
	if (!parsed)
	{
		printf("RESULT: REJECTED\n");
		return (1);
	}
	if (!calculate_disorder(parsed) || !strategies_router(parsed))
	{
		printf("RESULT: REJECTED\n");
		free_parsed(parsed);
		return (1);
	}
	bench(parsed);
	free_parsed(parsed);
	return (0);
}
