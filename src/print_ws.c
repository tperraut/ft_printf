/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:19:43 by tperraut          #+#    #+#             */
/*   Updated: 2017/12/11 16:58:02 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_wstrlen(wchar_t *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (*s != L'\0')
	{
		if (*s < 0x80)
			len++;
		else if (*s < 0x800)
			len += 2;
		else if (*s < 0x10000)
			len += 3;
		else if (*s < 0x11FFFF)
			len += 4;
		else
			break ;
		s++;
	}
	return (len);
}

static void		ft_print(wchar_t *s, t_specs *sp, t_buffer *b)
{
	if (!s)
		b->addstr("(null)", b);
	else
		while (*s != L'\0')
		{
			print_wc((wint_t)(*s), sp, b);
			s++;
		}
}

void			print_ws(wchar_t *s, t_specs *sp, t_buffer *b)
{
	size_t	len;
	char	opt;

	opt = (GET(sp->flags, F_Z)) ? '0' : ' ';
	len = (!s) ? 6 : ft_wstrlen(s);
	if (GET(sp->flags, F_M))
	{
		ft_print(s, sp, b);
		while (len++ < sp->width)
			b->add(' ', b);
		return ;
	}
	while (len++ < sp->width)
		b->add(opt, b);
	ft_print(s, sp, b);
}
