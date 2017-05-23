/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 15:31:38 by douglas           #+#    #+#             */
/*   Updated: 2017/05/23 13:30:26 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_is_specifier(char c)
{
	if (!c)
		return ('\0');
	return (ft_strchr("%sSpdiDuUoOxXcCb", c) != NULL);
}
