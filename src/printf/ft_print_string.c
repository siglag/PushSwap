/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 00:35:25 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/12 00:35:49 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *string)
{
	int	count;

	if (!string)
		string = "(null)";
	count = 0;
	while (string[count])
		count++;
	write(1, string, count);
	return (count);
}
