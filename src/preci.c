/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:22:59 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:08:29 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_preci(char **fmt, t_specs *sp)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		SET(sp->info, PRECI);
	}
	else
		return ;
	sp->preci = uatoi(fmt);
}
