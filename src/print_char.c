/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:06:26 by tperraut          #+#    #+#             */
/*   Updated: 2017/12/11 11:06:56 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char(char n, t_specs *sp, t_buffer *b)
{
	if (n < 0)
		SET(sp->info, SIGN);
	print_uchar((unsigned char)ABS(n), sp, b);
}

void	print_uchar(unsigned char n, t_specs *sp, t_buffer *b)
{
	char			*alpha_16;
	size_t			len;
	unsigned char	div;
	unsigned char	base;
	unsigned char	i;

	base = (unsigned char)get_base(sp);
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
			b->add(alpha_16[(int)((n / div) % base)], b);
			div /= base;
		}
	check_flags_end(len, sp, b);
}
