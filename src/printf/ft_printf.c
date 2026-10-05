/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:25:38 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/12 00:45:30 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(int fd, const char *input, ...)
{
	va_list	args;
	int		count;
	int		index;

	va_start(args, input);
	count = 0;
	index = 0;
	while (input[index])
	{
		if (input[index] == '%')
		{
			index++;
			count += ft_handle_conversion(fd, input[index], args);
		}
		else
			count += write(fd, &input[index], 1);
		index++;
	}
	va_end(args);
	return (count);
}
