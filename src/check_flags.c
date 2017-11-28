/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:20:46 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 14:07:54 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void	add_nopt(size_t *len, char c, size_t size, t_buffer *b)
{
	if (len)
		while (size > 0)
		{
			b->add(c, b);
			(*len)++;
			size--;
		}
	else
		while (size > 0)
		{
			b->add(c, b);
			size--;
		}
}

static size_t	init_check_flags(size_t len, t_specs *sp)
{
	if (GET(sp->info, PRECI))
	{
		if (is_empty(sp))
			len = 0;
		else
		{
			sp->preci = ((sp->preci > len) ? sp->preci - len : 0);
			len += sp->preci;
		}
	}
	if ((GET(sp->flags, F_P | F_SP) || NEG(sp->info)) && IS_SIGN(sp->type))
		len++;
	if (GET(sp->flags, F_S) && !GET(sp->info, IS_0))
	{
		if (GET(sp->type, T_X | T_UX))
			len += 2;
		else if (GET(sp->type, T_O | T_UO))
			len++;
	}
	return (len);
}

static size_t	right_check_flags(size_t len, t_specs *sp, t_buffer *b)
{
	add_nopt(&len, ' ', (len < sp->width) ? sp->width - len : 0, b);
	if (IS_SIGN(sp->type))
	{
		if (!NEG(sp->info))
		{
			if (GET(sp->flags, F_P))
				b->add('+', b);
			else if (GET(sp->flags, F_SP))
				b->add(' ', b);
		}
		else
			b->add('-', b);
	}
	if (GET(sp->flags, F_S)
		&& (!GET(sp->info, IS_0) || GET(sp->type, T_P)))
	{
		if (GET(sp->type, T_X))
			b->addstr("0x", b);
		else if (GET(sp->type, T_UX))
			b->addstr("0X", b);
		else if (GET(sp->type, T_O | T_UO) && !sp->preci)
			b->add('0', b);
	}
	if (GET(sp->flags, F_Z) && !GET(sp->flags, F_M)
			&& !GET(sp->info, PRECI))
		add_nopt(&len, '0', (len < sp->width) ? sp->width - len : 0, b);
	return (len);
}

size_t		check_flags_start(size_t len, t_specs *sp, t_buffer *b)
{
	len = init_check_flags(len, sp);
	if (GET(sp->flags, F_M)
		|| (GET(sp->flags, F_Z) && !GET(sp->info, PRECI)))
	{
		if (IS_SIGN(sp->type))
		{
			if (!NEG(sp->info))
			{
				if (GET(sp->flags, F_P))
					b->add('+', b);
				else if (GET(sp->flags, F_SP))
					b->add(' ', b);
			}
			else
				b->add('-', b);
		}
		if (GET(sp->flags, F_S)
				&& (!GET(sp->info, IS_0) || GET(sp->type, T_P)))
		{
			if (GET(sp->type, T_X))
				b->addstr("0x", b);
			else if (GET(sp->type, T_UX))
				b->addstr("0X", b);
			else if (GET(sp->type, T_O | T_UO) && !sp->preci)
				b->add('0', b);
		}
		if (GET(sp->flags, F_Z) && !GET(sp->flags, F_M))
			add_nopt(&len, '0', (len < sp->width) ? sp->width - len : 0, b);
	}
	else
		len = right_check_flags(len, sp, b);
	add_nopt(NULL, '0', sp->preci, b);
	return (len);
}

void		check_flags_end(size_t len, t_specs *sp, t_buffer *b)
{
	add_nopt(&len, ' ', (len < sp->width) ? sp->width - len : 0, b);
}
