/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:22:38 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:06:56 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_specs(t_specs *sp)
{
	if (!sp)
		return ;
	sp->preci = 0;
	sp->width = 1;
	sp->flags = ZERO;
	sp->mod = ZERO;
	sp->info = ZERO;
	sp->type = ZERO;
}
