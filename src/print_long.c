/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 18:07:29 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_long(long n, t_specs *specs, t_buffer *b)
{
	if (n < 0)
		SET(specs->info, SIGN);
	print_ulong((unsigned long) ABS(n), specs, b);
}

void	print_ulong(unsigned long n, t_specs *specs, t_buffer *b)
{
	char			*alpha_16;
	size_t			len;
	unsigned long	div;
	unsigned long	base;
	unsigned long	i;

	base = (unsigned long) get_base(specs);
	alpha_16 = (GET(specs->type, T_X)) ? ALPHA_16 : UALPHA_16;
	len = 1;
	i = n;
	div = 1;
	IF(n == 0, SET(specs->info, IS_0))
	while (i >= base)
	{
		div *= base;
		i /= base;
		len++;
	}
	len = check_flags_start(len, specs, b);
	while (div)
	{
		b->add(alpha_16[(n / div) % base], b);
		div /= base;
	}
	check_flags_end(len, specs, b);
}
