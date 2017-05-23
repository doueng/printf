/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:27:54 by douglas           #+#    #+#             */
/*   Updated: 2017/05/23 15:47:24 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<unistd.h>
// #include	<wchar.h>
// #include	<stddef.h>
#include 	<locale.h>
#include	<stdlib.h>
#include	"./libft/libft.h"
#include	<limits.h>
#define		MAX_INT 2147483647
int		ft_printf(const char* format, ...);

int		main(void)
{

	ft_printf("%b", 1);

// 	ft_printf("{%05.s}\n", 0);
// 	printf("{%05.s}", 0);

// 	ft_printf("%010d hell0\n", 42);
// 	printf("%+++000    00+d\n", 42);
// 	printf("%R hello");
// 	ft_printf("%+o\n", 0);
// 	printf("%+o\n\n", 0);
// 	ft_printf("%+o\n", 42);
// 	printf("%+o", 42);

// 	ft_printf("%.0%\n");
// 	printf("%.3%");

//   ft_printf("%#-8x\n", 42);
//   printf("%#-8x\n", 42);

	//   ft_printf("%-5%\n");
	//   printf("%-5%");


	// ft_printf("%.2s is a string\n", "this");
	// printf("%.2s is a string", "this");
	
	// printf("%d %", 42);

	ft_printf("%#08d\n", 42);
	// printf("%#08x\n", 42);

//   ft_printf("%#8x\n", 42);
//   printf("%#8x", 42);

// 	setlocale(LC_ALL, "");
// 	ft_printf("%0111S\n", L"의의의의의의");
// 	ft_printf("%C\n", L'의');
// 	printf("%0111S\n", L"의의의의의의");
// 	printf("%hhC, %hhC", 0, L'Á±≥');

// 	ft_printf("%+10.5d", 55);
// 	ft_printf("%p", 0);

// 	ft_printf("%4.s", "h");
// 	printf("%S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 	ft_printf("%hhC, %hhC", 0, L'Á±≥');

// 	printf("d%d\n", printf("%10c", 0));

// 	ft_printf("ld %ld", (long)MAX_INT + 1);
// 	ft_printf("\n");
// 	printf("ldp %ld",(long) MAX_INT + 1);
// 	ft_printf("%d\n", -42);
// 	ft_printf("\n");
// 	ft_printf("%u", (long)-1);



	// ft_printf("%c%c", 'h', 'e');
	// int a = 12;
	// printf("%p hello", &a);
	// ft_printf("hello world\n");
	// ft_printf("%x", 15);
	// ft_printf("%X", 15);
	// ft_printf("%o", 15);
	// ft_printf("%O", 15);
	// ft_printf("%d hello %X\n", 15, 13);
	// int i = ft_printf("%c", L'★');
	// ft_printf("\n%d\n", i);
	// int ii = printf("%S", L"Á±≥");
	// printf("%ls", L"★");
    // wprintf(L"%ls", L"ο Δικαιοπολις εν αγρω εστιν");
	// printf("\n%d\n", ii);
	// printf("%-14d %10d\n", 14, 10);
	


	return (0);
}




// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   convert.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2017/05/05 22:27:01 by douglas           #+#    #+#             */
// /*   Updated: 2017/05/14 11:51 by douglas          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_printf.h"

// char	*padding(char *str, t_id *id, size_t sign_len)
// {
// 	size_t	width;
// 	size_t	str_len;
// 	void	*result;

// 	str_len = ft_strlen(str) + sign_len;
// 	if (id->specifier == 's' && id->has_precision)
// 		str_len = (id->precision < str_len) ? id->precision : str_len;
// 	width = (id->width > str_len) ? id->width : str_len;
// 	result = ft_strnew(width);
// 	ft_memset(result, id->f_zero, width);
// 	if (!id->f_minus)
// 		ft_memmove(result + width - str_len, str, str_len);
// 	else
// 		ft_memmove(result, str, str_len);
// 	return (result);
// }

// static	char	*precision(char *nbr, t_id *id)
// {
// 	size_t	p_len;
// 	size_t	nbr_len;
// 	char	*result;

// 	nbr = (*nbr == '0') ? ft_strnew(0) : nbr; 
// 	p_len = id->precision;
// 	nbr_len = ft_strlen(nbr);
// 	if (p_len > nbr_len)
// 	{
// 		result = ft_strnew(p_len);
// 		ft_memset(result, '0', p_len);
// 		ft_memmove(result + p_len - nbr_len, nbr, nbr_len);
// 	}
// 	else
// 		result = ft_strdup(nbr);
// 	// free(nbr);
// 	return (result);
// }

// static char	*get_sign(int minus, char specifier)
// {
// 	if (specifier == 'x' || specifier == 'p')
// 		return ("0x");
// 	else if (specifier == 'X')
// 		return ("0X");
// 	else if (specifier == 'o' || specifier == 'O')
// 		return ("0");
// 	else if (minus)
// 		return ("-");
// 	else
// 		return ("+");
// }

// int		ft_print_nbr(char *nbr, t_id *id)
// {
// 	size_t		len;
// 	int			minus;
// 	char		spec;

// 	spec = id->specifier;
// 	minus = (*nbr == '-') ? 1 : 0;
// 	if (minus)
// 		nbr++;
// 	nbr = (id->has_precision) ? precision(nbr, id) : nbr;
// 	(id->has_precision) ? id->f_zero = ' ' : 0;
// 	len = 0;
// 	if (id->f_space && ft_strchr("di", spec) && !minus && !id->f_plus)
// 		len = ft_putstr(" ");
// 	if ((*nbr != '0' || id->f_plus || spec == 'p' || minus) && 
// 		(!ft_strchr("oO", spec) || id->f_hash))
// 	{
// 		if ((id->f_plus || id->f_hash || minus) && id->f_zero == '0')
// 			len = ft_putstr(get_sign(minus, spec));
// 		else if ((id->f_plus || id->f_hash || minus) && (id->f_minus || id->f_zero == ' '))
// 			nbr = ft_strjoin(get_sign(minus, spec), nbr);
// 	}
// 	len += ft_putstr(padding(nbr, id, len));
// 	return (len);
// }

// int		ft_printstr(char *str, t_id *id)
// {
// 	if (!str)
// 		return (ft_putstr("(null)"));
// 	if (id->specifier == '%')
// 		id->has_precision = 0;
// 	return ft_putstr(
// 		padding(
// 		ft_strndup(str, 
// 		(id->has_precision) ? id->precision : ft_strlen(str))
// 		, id, 0));
// }

// int		ft_base(size_t n, char c, t_id *id)
// {
// 	char	*base;

// 	if (c == 'x' || c == 'p')
// 		base = BASE_16;
// 	else if (c == 'X')
// 		base = BASE_16_U;
// 	else
// 		base = BASE_8;
// 	return (ft_print_nbr(ft_itoa_base(n, base), id));
// }

// size_t		length_converter(va_list ap, int len)
// {
// 	if (len == h)
// 		return (short)(va_arg(ap, int));
// 	if (len == hh)
// 		return (char)(va_arg(ap, int));
// 	if (len == l)
// 		return (va_arg(ap, long));
// 	if (len == ll)
// 		return (va_arg(ap, long long));
// 	if (len == j)
// 		return (va_arg(ap, uintmax_t));
// 	if (len == z)
// 		return (va_arg(ap, size_t));
// 	return (va_arg(ap, int));
// }

// size_t		ulength_converter(va_list ap, int len)
// {
// 	if (len == h)
// 		return (unsigned short)(va_arg(ap, unsigned int));
// 	if (len == hh)
// 		return (unsigned char)(va_arg(ap, unsigned int));
// 	if (len == l)
// 		return (va_arg(ap, unsigned long));
// 	if (len == ll)
// 		return (va_arg(ap, unsigned long long));
// 	if (len == j)
// 		return (va_arg(ap, uintmax_t));
// 	if (len == z)
// 		return (va_arg(ap, size_t));
// 	return (va_arg(ap, unsigned int));
// }