/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:24:04 by tperraut          #+#    #+#             */
/*   Updated: 2018/01/24 17:27:47 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s || s == 0)
		return (len);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

static void		print_nopt(size_t *len, char c, size_t size, t_buffer *b)
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

static void		print_ns(size_t *len, char *s, size_t size, t_buffer *b)
{
	size_t	i;

	i = 0;
	if (!s || s == 0)
		return ;
	if (len)
		while (i < size && s[i])
		{
			b->add(s[i], b);
			(*len)++;
			i++;
		}
	else
		while (i < size && s[i])
		{
			b->add(s[i], b);
			i++;
		}
}

static	void	print_s_nopreci(size_t len, char *s, t_buffer *b, t_specs *sp)
{
	char	opt;

	opt = (GET(sp->flags, F_Z)) ? '0' : ' ';
	if (GET(sp->flags, F_M))
	{
		if (!s || s == 0)
			return ;
		while (*s)
		{
			b->add(*s, b);
			len++;
			s++;
		}
		print_nopt(NULL, ' ', (sp->width > len) ? sp->width - len : 0, b);
	}
	else
	{
		len = ft_strlen(s);
		print_nopt(NULL, opt, (sp->width > len) ? sp->width - len : 0, b);
		print_ns(NULL, s, len, b);
	}
}

void			print_s(char *s, t_specs *sp, t_buffer *b)
{
	size_t	len;
	char	opt;

	opt = (GET(sp->flags, F_Z)) ? '0' : ' ';
	len = 0;
	if (!s || s == 0)
		s = "(null)";
	if (GET(sp->info, PRECI))
	{
		if (GET(sp->flags, F_M))
		{
			print_ns(&len, s, sp->preci, b);
			print_nopt(NULL, ' ', (sp->width > len) ? sp->width - len : 0, b);
		}
		else
		{
			len = MIN(ft_strlen(s), sp->preci);
			print_nopt(NULL, opt, (sp->width > len) ? sp->width - len : 0, b);
			print_ns(NULL, s, len, b);
		}
	}
	else
		print_s_nopreci(len, s, b, sp);
}
