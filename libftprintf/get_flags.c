/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:27:28 by douglas           #+#    #+#             */
/*   Updated: 2017/05/21 12:21:47 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_length(char *format, t_id **id)
{
	if (*format == 'l' && *(format + 1) == 'l')
	{
		(*id)->length = ll;
		return (format + 2);
	}
	if (*format == 'h' && *(format + 1) == 'h')
	{
		(*id)->length = hh;
		return (format + 2);
	}
	(*format == 'l') ? (*id)->length = l : 0;
	(*format == 'h') ? (*id)->length = h : 0;
	(*format == 'j') ? (*id)->length = j : 0;
	(*format == 'z') ? (*id)->length = z : 0;
	if ((*id)->length)
		return (++format);
	return (format);
}

static char	*get_flags(t_id **id, char *format)
{
	while (ft_strchr("#0- +", *format))
	{
		if (*format == '#')
			(*id)->f_hash = *format;
		if (*format == '0' && !(*id)->f_minus)
			(*id)->f_zero = *format;
		if (*format == '-')
		{
			(*id)->f_minus = *format;
			(*id)->f_zero = ' ';
		}
		if (*format == '+')
			(*id)->f_plus = *format;
		if (*format == ' ')
			(*id)->f_space = ' ';
		format++;
	}
	return (format);
}

t_id	*ft_id(char *format)
{
	t_id	*id;
	
	id = (t_id*)ft_memalloc(sizeof(t_id));
	id->f_zero = ' ';
	id->specifier = '\0';
	format = get_flags(&id, format);
	if (*format >= '1' && *format <= '9')
	{
		id->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	if (*format == '.')
	{
		id->precision = ft_atoi(++format);
		id->has_precision = 1;
		while (ft_isdigit(*format))
			format++;
	}
	format = get_length(format, &id);
	id->specifier = *format;
	if (id->specifier == 'p')
		id->f_hash = '#';
	return (id);
}

void	add_to_lst(t_id **lst, t_id *id)
{
	t_id	*tmp;

	if (*lst == NULL)
	{
		*lst = id;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = id;
}

t_id	*ft_get_flags(char *format)
{
	t_id	*lst;

	lst = NULL;
	while (*format)
	{
		if (*format == '%')
			add_to_lst(&lst, ft_id(++format));
		format++;
	}
	return (lst);
}