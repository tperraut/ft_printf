/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:22:50 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/28 15:42:35 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	uatoi(char **fmt)
{
	size_t	n;

	if (!fmt || !*fmt)
		return (0);
	n = 0;
	if (!(**fmt < '0' || **fmt > '9'))
	{
		n = **fmt - '0';
		(*fmt)++;
	}
	while (!(**fmt < '0' || **fmt > '9'))
	{
		n *= 10;
		n += **fmt - '0';
		(*fmt)++;
	}
	return (n);
}

char	get_base(t_specs *sp)
{
	if (GET(sp->type, T_X | T_UX))
		return (16);
	if (GET(sp->type, T_O | T_UO))
		return (8);
	if (GET(sp->type, T_B))
		return (2);
	return (10);
}

char	is_contain(char c, char *str)
{
	if (!str)
		return (FALSE);
	while (*str)
	{
		if (c == *str)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

char	is_empty(t_specs *sp)
{
	if (GET(sp->info, IS_0) && GET(sp->info, PRECI) && !(sp->preci)
			&& (GET(sp->type, T_I | T_U | T_X | T_UX | T_D | T_UD)
				|| (GET(sp->type, T_O | T_UO) && !GET(sp->flags, F_S))))
		return (TRUE);
	return (FALSE);
}
