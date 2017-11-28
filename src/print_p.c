/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:23:06 by tperraut          #+#    #+#             */
/*   Updated: 2017/11/28 14:53:33 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_p(size_t n, t_specs *sp, t_buffer *b)
{
		SET(sp->flags, F_S);
		SET(sp->type, T_X);
		print_size_t(n, sp, b);
}
