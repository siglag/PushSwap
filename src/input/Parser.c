/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:11:17 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/28 02:09:47 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_parsed	*parser(int argc, char **argv)
{
	t_parsed	*parsed;

	parsed = (t_parsed *)malloc(sizeof(t_parsed));
	if (!parsed)
		return (NULL);
	if (!parse_flags(parsed, argc, argv))
	{
		free_parsed(parsed);
		return (NULL);
	}
	return (parsed);
}
