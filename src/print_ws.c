/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:19:43 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/24 11:20:31 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_ws(wchar_t *s, t_specs *specs, t_buffer *b)
{
	if (!s)
		return ;
	while (*s != L'\0')
	{
		print_wc((wint_t)(*s), specs, b);
		s++;
	}
}
