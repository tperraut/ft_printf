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

static unsigned short	other_type(char c)
{
	if (c == 'D')
		return (T_UD);
	if (c == 'C')
		return (T_UC);
	if (c == 'S')
		return (T_US);
	if (c == 'O')
		return (T_UO);
	if (c == 'U')
		return (T_UU);
	return (ZERO);
}

static unsigned short	basic_type(char c)
{
	if (c == 'd')
		return (T_D);
	if (c == 'i')
		return (T_I);
	if (c == 'c')
		return (T_C);
	if (c == 's')
		return (T_S);
	if (c == 'p')
		return (T_P);
	if (c == 'o')
		return (T_O);
	if (c == 'u')
		return (T_U);
	if (c == 'x')
		return (T_X);
	if (c == 'X')
		return (T_UX);
	if (c == 'b')
		return (T_B);
	return (other_type(c));
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
