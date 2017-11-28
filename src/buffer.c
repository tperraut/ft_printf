/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:22:30 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/28 16:42:30 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

static size_t	buf_flush(t_buffer *b)
{
	size_t	len;

	len = MIN(b->size, BUF_SIZE);
	write(1, b->data, len);
	b->size = 0;
	b->len += len;
	return (b->len);
}

static void		buf_add(char c, t_buffer *b)
{
	if (!(b->size < BUF_SIZE))
		b->flush(b);
	b->data[b->size] = c;
	b->size++;
}

static void		buf_addstr(char *str, t_buffer *b)
{
	if (!str)
		return ;
	while (*str)
	{
		b->add(*str, b);
		str++;
	}
}

void			buf_init(t_buffer *b)
{
	if (!b)
		return ;
	b->size = 0;
	b->len = 0;
	b->flush = buf_flush;
	b->add = buf_add;
	b->addstr = buf_addstr;
}
