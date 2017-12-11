/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:06:40 by tperraut          #+#    #+#             */
/*   Updated: 2017/12/11 11:06:56 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_short(short n, t_specs *sp, t_buffer *b)
{
	if (n < 0)
		SET(sp->info, SIGN);
	print_ushort((unsigned short)ABS(n), sp, b);
}

void	print_ushort(unsigned short n, t_specs *sp, t_buffer *b)
{
	char			*alpha_16;
	size_t			len;
	unsigned short	div;
	unsigned short	base;
	unsigned short	i;

	base = (unsigned short)get_base(sp);
	alpha_16 = (GET(sp->type, T_X)) ? ALPHA_16 : UALPHA_16;
	len = 1;
	i = n;
	div = 1;
	SET(sp->info, (n == 0) ? IS_0 : ZERO);
	while (i >= base && ++len)
	{
		div *= base;
		i /= base;
	}
	len = check_flags_start(len, sp, b);
	if (!is_empty(sp))
		while (div)
		{
			b->add(alpha_16[(n / div) % base], b);
			div /= base;
		}
	check_flags_end(len, sp, b);
}
