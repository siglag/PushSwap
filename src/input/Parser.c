/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:11:17 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/01 00:47:45 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_parsed(t_parsed *parsed)
{
	if (parsed->sequence)
		free(parsed->sequence);
	if (parsed)
		free(parsed);
	return (0);
}

t_parsed	*parser(int argc, char **argv)
{
	t_parsed	*parsed;
	int			flags;

	if (argc < 2 || !validate_format(argc, argv))
		return (NULL);
	parsed = malloc(sizeof(t_parsed));
	if (!parsed)
		return (NULL);
	parsed->sequence = NULL;
	parsed->sequence_size = 0;
	parsed->is_bench = false;
	parsed->strategy = ADAPTIVE;
	flags = extract_flags(parsed, argc, argv);
	if (flags < 0 || flags > 2)
		return (free_parsed(parsed), NULL);
	if (!extract_sequence(parsed, argc, argv))
		return (free_parsed(parsed), NULL);
	if (parsed->sequence_size == 0)
		return (free_parsed(parsed), NULL);
	return (parsed);
}
