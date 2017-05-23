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