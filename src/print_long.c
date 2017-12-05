/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:10:22 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_long(long n, t_specs *sp, t_buffer *b)
{
	if (n < 0)
		SET(sp->info, SIGN);
	print_ulong((unsigned long)ABS(n), sp, b);
}

void	print_ulong(unsigned long n, t_specs *sp, t_buffer *b)
{
	char			*alpha_16;
	size_t			len;
	unsigned long	div;
	unsigned long	base;
	unsigned long	i;

	base = (unsigned long)get_base(sp);
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
