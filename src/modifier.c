/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:26:35 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:08:22 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_mod(char **fmt, t_specs *sp)
{
	char	c;

	c = '\0';
	if (is_contain(**fmt, MOD))
	{
		c = **fmt;
		(*fmt)++;
	}
	else
		return ;
	if (!GET(sp->mod, M_LL) && **fmt == 'l' && c == 'l')
		SET(sp->mod, M_LL);
	else if (!GET(sp->mod, M_L) && c == 'l')
		SET(sp->mod, M_L);
	else if (!GET(sp->mod, M_HH) && **fmt == 'h' && c == 'h')
		SET(sp->mod, M_HH);
	else if (!GET(sp->mod, M_H) && c == 'h')
		SET(sp->mod, M_H);
	else if (!GET(sp->mod, M_J) && c == 'j')
		SET(sp->mod, M_J);
	else if (!GET(sp->mod, M_Z) && c == 'z')
		SET(sp->mod, M_Z);
	if (is_contain(**fmt, MOD))
		(*fmt)++;
}
