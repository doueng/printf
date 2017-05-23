/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:45:13 by dengstra          #+#    #+#             */
/*   Updated: 2017/05/10 14:16:24 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		ft_get_num_len(int n)
// {
// 	int len;

// 	len = 0;
// 	while (n)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// void		print_padding(int n, char c)
// {
// 	if (n <= 0)
// 		return ;
// 	while (n--)
// 		ft_putchar(c);
// }

// int		ft_padding(size_t n_len, t_id *id)
// {
// 	int		len;
// 	char	*nbr;

// 	len = id->width - n_len;
// 	len = (len < 0) ? id->width : n_len;
// 	nbr = ft_strnew(len + 1);
// 	if (id->zero)
// 		ft_memset(nbr, '0', len);
// 	else
// 		ft_memset(nbr, ' ', len);
// 	if (id->f_plus)
// 	{
// 		nbr[0] = "+";
// 		nbr = ft_strjoin(++nbr, )
// 	}
// 	return (len);
// }