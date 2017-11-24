/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:50:11 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 12:07:50 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	t_buffer	buf;
	va_list		ap;
	char		*tmp;

	buf_init(&buf);
	if (!format)
		return (-1);
	tmp = (char *)format;
	va_start(ap, format);
	while (*tmp)
	{
		if (*tmp == '%')
			switch_mode(&tmp, &buf, ap);
		else
		{
			buf.add(*tmp, &buf);
			tmp++;
		}
	}
	va_end(ap);
	return ((int) buf.flush(&buf));
}
