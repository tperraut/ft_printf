/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:42:57 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/28 17:40:25 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned short	basic_type(char c)
{
	if (c == 'd')
		return (T_D);
	else if (c == 'D')
		return (T_UD);
	else if (c == 'i')
		return (T_I);
	else if (c == 'c')
		return (T_C);
	else if (c == 'C')
		return (T_UC);
	else if (c == 's')
		return (T_S);
	else if (c == 'S')
		return (T_US);
	else if (c == 'p')
		return (T_P);
	else if (c == 'o')
		return (T_O);
	else if (c == 'O')
		return (T_UO);
	else if (c == 'u')
		return (T_U);
	else if (c == 'U')
		return (T_UU);
	else if (c == 'x')
		return (T_X);
	else if (c == 'X')
		return (T_UX);
	else if (c == 'b')
		return (T_B);
	return (ZERO);
}

void					add_type(char **fmt, t_specs *sp)
{
	char	*types;

	types = TYPE;
	while (!sp->type && *types)
	{
		if (**fmt == *types)
		{
			SET(sp->type, basic_type(*types));
			(*fmt)++;
		}
		types++;
	}
}
