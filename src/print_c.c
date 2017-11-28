/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:23:10 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:09:11 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_c(char c, t_specs *sp, t_buffer *b)
{
	if (GET(sp->flags, F_M))
	{
		b->add(c, b);
		sp->width = (sp->width) ? sp->width - 1 : 0;
		while (sp->width > 0)
		{
			b->add(' ', b);
			(sp->width)--;
		}
	}
	else
	{
		sp->width = (sp->width) ? sp->width - 1 : 0;
		while (sp->width > 0)
		{
			b->add(' ', b);
			(sp->width)--;
		}
		b->add(c, b);
	}
}
