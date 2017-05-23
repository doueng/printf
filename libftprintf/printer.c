/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:27:44 by douglas           #+#    #+#             */
/*   Updated: 2017/05/22 11:31:21 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	function_caller(char c, size_t num, t_id *id, va_list ap)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = NULL;
	len += (ft_strchr("uU", c)) ? 
			ft_print_nbr((tmp = ft_itoa_base(num, BASE_10)), id) : 0;
	len += (ft_strchr("idD", c)) ? ft_print_nbr((tmp = ft_itoa(num)), id) : 0;
	len += (c == '%') ? ft_printstr("%", id) : 0;
	len += (num && ft_strchr("cC", c)) ? 
			ft_printstr((tmp = ft_putwchar(num, id)), id) : 0;
	len += (!num && ft_strchr("cC", c)) ? ft_putzerochar(id) : 0;
	len += (c == 's' && id->length != l) ? 
			ft_printstr(va_arg(ap, char*), id) : 0;
	len += (ft_strchr("xXoO", c)) ? ft_base(num, c, id) : 0;
	len += (c == 'p') ? ft_base((long)va_arg(ap, void*), c, id) : 0;
	len += (c == 'b') ? ft_putbinary(va_arg(ap, int)) : 0;
	len += (c == 'S' || (c == 's' && id->length == l))
			? ft_putwstr(va_arg(ap, wchar_t*), id) : 0;
	if (tmp)
		free(tmp);
	return (len);
}

static size_t	len_converter(char c, va_list ap, t_id *id)
{
	if (ft_strchr("cdDi", c))
		return (length_converter(ap, id->length));
	else if (ft_strchr("xXoOuUC", c))
		return (ulength_converter(ap, id->length));
	return (0);
}

int		ft_printer(char *format, t_id *id, va_list ap)
{
	char	c;
	int		len;
	t_id	*tmp;

	len = 0;
	if (!id)
		return (ft_putstr(format));
	while (*format)
	{
		if (*format != '%')
		{
			len += ft_putchar(*format++);
			continue;
		}
		c = id->specifier;
		if (!ft_is_specifier(c))
		{
			format++;
			continue;
		}
		if (ft_strchr("DOU", c))
			id->length = l;
		len += function_caller(c, len_converter(c, ap, id), id, ap);
		tmp = id;
		id = id->next;
		free(tmp);
		format++;
		while (!ft_is_specifier(*format++))
			;
	}
	free(id);
	return (len);
}