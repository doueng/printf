/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:30:04 by dengstra          #+#    #+#             */
/*   Updated: 2017/05/23 13:30:18 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		input_checker(t_id *id)
{
	while (id)
	{
		if (id->specifier == 'u' && id->f_plus)
			id->f_plus = '\0';
		id = id->next;
	}
	return (1);
}
