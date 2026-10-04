/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/04 14:04:32 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_parsed	*parsed;

	parsed = parser(argc, argv);
	if (!parsed)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (!calculate_disorder(parsed) || !strategies_router(parsed))
	{
		ft_printf("Error\n");
		free_parsed(parsed);
		exit(1);
	}
	bench(parsed);
	free_parsed(parsed);
	return (0);
}
