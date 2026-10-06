/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:08:23 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/07 02:53:54 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_parsed	*parsed;

	if (argc < 2)
		exit(0);
	parsed = parser(argc, argv);
	if (!parsed)
	{
		ft_printf(2, "Error\n");
		exit(1);
	}
	if (!calculate_disorder(parsed) || !strategies_router(parsed))
	{
		ft_printf(2, "Error\n");
		free_parsed(parsed);
		exit(1);
	}
	bench(parsed);
	free_parsed(parsed);
	exit(0);
}
