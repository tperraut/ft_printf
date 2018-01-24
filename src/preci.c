/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:22:59 by tperraut          #+#    #+#             */
/*   Updated: 2018/01/24 15:41:34 by tperraut         ###   ########.fr       */
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
