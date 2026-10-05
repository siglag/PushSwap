/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 23:36:39 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 23:56:51 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversion(int fd, char conversion, va_list args)
{
	if (conversion == 'c')
		return (ft_print_char(fd, va_arg(args, int)));
	if (conversion == 's')
		return (ft_print_string(fd, va_arg(args, char *)));
	if (conversion == 'd' || conversion == 'i')
		return (ft_print_number(fd, va_arg(args, int)));
	if (conversion == '%')
		return (write(fd, "%", 1));
	return (0);
}
