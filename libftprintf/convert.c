/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:27:01 by douglas           #+#    #+#             */
/*   Updated: 2017/05/23 15:49:08 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*padding(char *str, t_id *id, size_t sign_len)
{
	size_t	width;
	size_t	str_len;
	void	*result;

	str_len = ft_strlen(str) + sign_len;
	if (id->specifier == 's' && id->has_precision)
		str_len = (id->precision < str_len) ? id->precision : str_len;
	width = (id->width > str_len) ? id->width : str_len;
	result = ft_strnew(width);
	ft_memset(result, id->f_zero, width);
	if (!id->f_minus)
		ft_memmove(result + width - str_len, str, ft_strlen(str) + 1);
	else
		ft_memmove(result, str, str_len);
	// if ((id->has_precision && id->specifier != 's') || ((id->f_plus || id->f_hash) && (id->f_minus || id->f_zero == ' ')))
		// free(str);
	return (result);
}

static	char	*precision(char *nbr, t_id *id)
{
	size_t	p_len;
	size_t	nbr_len;
	char	*result;

	if (!nbr)
		exit(-1);
	if (id->precision == 0 && *nbr == '0')
		return (ft_strnew(0));
	p_len = id->precision;
	nbr_len = ft_strlen(nbr);
	if (p_len > nbr_len)
	{
		result = ft_strnew(p_len);
		ft_memset(result, '0', p_len);
		ft_memmove(result + p_len - nbr_len, nbr, nbr_len);
	}
	else
		result = ft_strdup(nbr);
	return (result);
}

static char	*get_sign(int minus, t_id *id)
{
	char specifier;

	specifier = id->specifier;
	if (specifier == 'x' || specifier == 'p')
		return ("0x");
	else if (specifier == 'X')
		return ("0X");
	else if (specifier == 'o' || specifier == 'O')
		return ("0");
	else if (minus)
		return ("-");
	else if (id->f_plus == '+')
		return ("+");
	else
		return ("");
}

static	int		flag_space(t_id *id, int minus)
{
	int len;

	len = 0;
	if (id->f_space && ft_strchr("di", id->specifier) && !minus && !id->f_plus)
		len = write(1, " ", 1);
	return (len);
}

int		ft_print_nbr(char *nbr, t_id *id)
{
	size_t		len;
	int			minus;
	char		spec;
	char		*prec;

	if (!nbr)
		exit(-1);
	spec = id->specifier;
	minus = (*nbr == '-') ? 1 : 0;
	if (minus)
		nbr++;
	prec = NULL;
	nbr = (id->has_precision) ? (prec = precision(nbr, id)) : nbr;
	(id->has_precision) ? id->f_zero = ' ' : 0;
	len = flag_space(id, minus);
	if ((*nbr != '0' || id->f_plus || spec == 'p' || minus) &&
		(!ft_strchr("oOxX", spec) ||
		(id->f_hash && (*nbr || ft_strchr("oO", spec)))))
	{
		if ((id->f_plus || id->f_hash || minus) && id->f_zero == '0')
		{
			len += ft_putstr(get_sign(minus, id));
			len += ft_putstrfree(padding(nbr, id, len));
		}
		// else if ((id->f_plus || id->f_hash || minus) && (id->f_minus || id->f_zero == ' '))
		else
		{
			nbr = ft_strjoin(get_sign(minus, id), nbr);
			len += ft_putstrfree(padding(nbr, id, len));
			free(nbr);
		}
	}
	else
		len += ft_putstrfree(padding(nbr, id, len));
	if (prec)
		free(prec);
	return (len);
}

int		ft_printstr(char *str, t_id *id)
{
	char	*tmp;
	int		len;

	if (!str)
		return (ft_putstr("(null)"));
	if (id->specifier == '%')
		id->has_precision = 0;
	tmp = ft_strndup(str, (id->has_precision) ? id->precision : ft_strlen(str));
	len = ft_putstrfree(padding(tmp, id, 0));
	free(tmp);
	return (len);
}

int		ft_base(size_t n, char c, t_id *id)
{
	char	*base;
	char	*tmp;
	int		len;

	if (c == 'x' || c == 'p')
		base = BASE_16;
	else if (c == 'X')
		base = BASE_16_U;
	else
		base = BASE_8;
	len = ft_print_nbr((tmp = ft_itoa_base(n, base)), id);
	if (tmp)
		free(tmp);
	return (len);
}

size_t		length_converter(va_list ap, int len)
{
	if (len == h)
		return (short)(va_arg(ap, int));
	if (len == hh)
		return (char)(va_arg(ap, int));
	if (len == l)
		return (va_arg(ap, long));
	if (len == ll)
		return (va_arg(ap, long long));
	if (len == j)
		return (va_arg(ap, uintmax_t));
	if (len == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, int));
}

size_t		ulength_converter(va_list ap, int len)
{
	if (len == h)
		return (unsigned short)(va_arg(ap, unsigned int));
	if (len == hh)
		return (unsigned char)(va_arg(ap, unsigned int));
	if (len == l)
		return (va_arg(ap, unsigned long));
	if (len == ll)
		return (va_arg(ap, unsigned long long));
	if (len == j)
		return (va_arg(ap, uintmax_t));
	if (len == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}
