/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:19:43 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/28 14:58:25 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_ws(wchar_t *s, t_specs *specs, t_buffer *b)
{
	if (!s)
	{
		b->addstr("(null)", b);
		return ;
	}
	while (*s != L'\0')
	{
		print_wc((wint_t)(*s), specs, b);
		s++;
	}
}
