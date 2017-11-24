/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:41:55 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:11:39 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_size_t(size_t n, t_specs *sp, t_buffer *b)
{
	char	*alpha_16;
	size_t	len;
	size_t	div;
	size_t	base;
	size_t	i;

	base = get_base(sp);
	alpha_16 = (GET(sp->type, T_X)) ? ALPHA_16 : UALPHA_16;
	len = 1;
	i = n;
	div = 1;
	if (n == 0)
		SET(sp->info, IS_0);
	while (i >= base && len++)
	{
		div *= base;
		i /= base;
	}
	len = check_flags_start(len, sp, b);
	while (div)
	{
		b->add(alpha_16[(n / div) % base], b);
		div /= base;
	}
	check_flags_end(len, sp, b);
}
