/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:11:17 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/29 11:48:44 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_parsed	*parser(int argc, char **argv)
{
	t_parsed	*parsed;
	int			flags;

	parsed = malloc(sizeof(t_parsed));
	parsed->strategy = 0;
	flags = extract_flags(parsed, argc, argv);
	if (flags <= 0 || flags > 2)
		return (free_parsed(parsed), NULL);
	return (parsed);
}
