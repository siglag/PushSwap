/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:11:17 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/28 17:11:01 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_parsed	*parser(int argc, char **argv)
{
	t_parsed	*parsed;

	parsed = malloc(sizeof(t_parsed));
	parsed->is_bench = true;
	parsed->strategy = argc;
	parsed->sequence_size = argv[0][0];
	return (parsed);
}
