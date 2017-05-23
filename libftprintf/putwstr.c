/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:10:02 by douglas           #+#    #+#             */
/*   Updated: 2017/05/12 12:50:1 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*one_byte(int c)
{
	char *result;

	result = ft_strnew(1);
	if (!result)
		exit(-1);
	result[0] = c;
	return (result);
}

static char		*two_byte(int c)
{
	char *result;

	result = ft_strnew(2);
	if (!result)
		exit(-1);
	result[0] = (c >> 6 | 0b11000000) & 0b11011111;
	result[1] = (c | 0b10000000) & 0b10111111;
	return (result);
}

static char		*three_byte(int c)
{
	char	*result;

	result = ft_strnew(3);
	if (!result)
		exit(-1);
	result[0] = (c >> 12 | 0b11100000) & 0b11101111;
	result[1] = (c >> 6 | 0b10000000) &  0b10111111;
	result[2] = (c | 0b10000000) & 0b10111111;
	return (result);
}

static char		*four_byte(int c)
{
	char *result;

	result = ft_strnew(4);
	if (!result)
		exit(-1);
	result[0] = (c >> 18 | 0b11110000) & 0b11110111;
	result[1] = (c >> 12 | 0b10000000) & 0b10111111;
	result[2] = (c >> 6 | 0b10000000) & 0b10111111;
	result[3] = (c | 0b10000000) & 0b10111111;
	return (result);
}

char		*ft_putwchar(wchar_t c, t_id *id)
{
	char	*result;

	if (c <= 127 || (id->specifier == 'c' && id->length == none))
		result = one_byte(c);
	else if (c <= 2047)
		result = two_byte(c);
	else if (c <= 65535)
		result = three_byte(c);
	else
		result = four_byte(c);
	return (result);
}

size_t		ft_putwstr(wchar_t *str, t_id *id)
{
	size_t	len;
	char	*result;
	char	*tmp;

	len = 0;
	if (!str)
		return (ft_putwstr(L"(null)", id));
	while (str[len++])
		;
	result = ft_strnew(len * 4);
	if (!result)
		exit(-1);
	while (*str)
	{
		tmp = ft_putwchar(*str++, id);
		ft_strcat(result, tmp);
		free(tmp);
	}
	len = ft_printstr(result, id);
	free(result);
	return (len);
}

size_t		ft_putbinary(char c)
{
	return ft_printf("%c%c%c%c%c%c%c%c",
		(c & 0b10000000) ? '1' : '0',
		(c & 0b01000000) ? '1' : '0',
		(c & 0b00100000) ? '1' : '0',
		(c & 0b00010000) ? '1' : '0',
		(c & 0b00001000) ? '1' : '0',
		(c & 0b00000100) ? '1' : '0',
		(c & 0b00000010) ? '1' : '0',
		(c & 0b00000001) ? '1' : '0');
}

int		ft_putzerochar(t_id *id)
{
	size_t width;

	width = 0;
	if (id->width)
		width = id->width - 1;
	if (id->f_minus)
	{
		ft_putchar(0);
		while (width--)
			ft_putchar(id->f_zero);
	}
	else
	{
		while (width--)
			ft_putchar(id->f_zero);
		ft_putchar(0);
	}
	return ((id->width) ? id->width : 1);
}