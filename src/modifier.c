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

static char	basic_mod(char mod)
{
	if (mod == 'l')
		return (M_L);
	if (mod == 'h')
		return (M_H);
	if (mod == 'j')
		return (M_J);
	if (mod == 'z')
		return (M_Z);
	return (ZERO);
}

static char	advanced_mod(char mod)
{
	if (mod == 'l')
		return (M_LL);
	if (mod == 'h')
		return (M_HH);
	return (ZERO);
}

void		add_mod(char **fmt, t_specs *sp)
{
	char	c;
	char	*mod;

	c = '\0';
	mod = MOD;
	if (is_contain(**fmt, MOD))
	{
		c = **fmt;
		(*fmt)++;
	}
	else
		return ;
	while (!sp->mod && *mod)
	{
		if (**fmt == *mod && *mod == c)
		{
			SET(sp->mod, advanced_mod(*mod));
			(*fmt)++;
		}
		mod++;
	}
	if (!sp->mod)
		SET(sp->mod, basic_mod(c));
}
