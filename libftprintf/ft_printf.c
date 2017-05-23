/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:27:35 by douglas           #+#    #+#             */
/*   Updated: 2017/05/20 12:29:21 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char* format, ...)
{
	int		chars_printed;
	va_list	ap;
	t_id	*id;

	id = NULL;
	id = ft_get_flags((char*)format);
	if (!input_checker(id))
		return (0);
	va_start(ap, (char*)format);
	chars_printed = ft_printer((char*)format, id, ap);
	va_end(ap);
	return (chars_printed);
}