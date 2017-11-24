/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:22:54 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:08:04 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_flags(char **fmt, t_specs *sp)
{
	while (is_contain(**fmt, FLAGS))
	{
		if (!GET(sp->flags, F_S) && **fmt == '#')
			SET(sp->flags, F_S);
		else if (!GET(sp->flags, F_Z) && **fmt == '0')
			SET(sp->flags, F_Z);
		else if (!GET(sp->flags, F_P) && **fmt == '+')
			SET(sp->flags, F_P);
		else if (!GET(sp->flags, F_M) && **fmt == '-')
			SET(sp->flags, F_M);
		else if (!GET(sp->flags, F_SP) && **fmt == ' ')
			SET(sp->flags, F_SP);
		(*fmt)++;
	}
}
