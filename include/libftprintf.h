/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:22:02 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 11:10:34 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# define BUF_SIZE	4096
# define TRUE	1
# define FALSE	0
# define ABS(X)	((X < 0) ? -X : X)
# define MIN(X, Y)	((X > Y) ? Y : X)
# define MAX(X, Y)	((X < Y) ? Y : X)
# define IF_RETURN(Bool, Value)	if (Bool) return (Value)
# define IF(Bool, Do)	if (Bool) {Do;}
# define ELIF(Bool, Do)	else if (Bool) {Do;}
# define ELSE(Do)	else {Do;}
# define INIT(Type, Var, Value)	Type Var = Value
# define UALPHA_16	"0123456789ABCDEF"
# define ALPHA_16	"0123456789abcdef"
# define ZERO	0x00
/* Flags */
# define FLAGS	"#0+- "
# define F_S	0x01
# define F_Z	0x02
# define F_P	0x04
# define F_M	0x08
# define F_SP	0x10
/* Modifiers */
# define MOD	"lhjz"
# define M_L	0x01
# define M_LL	0x02
# define M_H	0x04
# define M_HH	0x08
# define M_J	0x10
# define M_Z	0x20
/*INFO*/
# define PRECI	0x01
# define SIGN	0x02
# define IS_0	0x04
# define NEG(Num)	((Num & SIGN) ? TRUE : FALSE)
/* Types */
# define TYPE	"dsciuxopbCSDOUX"
# define T_D	0x0001
# define T_UD	0x0002
# define T_I	0x0004
# define T_O	0x0008
# define T_UO	0x0010
# define T_U	0x0020
# define T_UU	0x0040
# define T_X	0x0080
# define T_UX	0x0100
/* BONUS : Binary type */
# define T_B	0x0200
# define T_C	0x0400
# define T_UC	0x0800
# define T_S	0x1000
# define T_US	0x2000
# define T_P	0x4000
# define IS_SIGN(Num)	(Num > ZERO && Num < T_O)
# define SET(Num, Mask)	Num |= Mask
# define GET(Num, Mask)	((Num & Mask) ? TRUE : FALSE)

typedef struct	s_buffer
{
	char	data[BUF_SIZE];
	size_t	size;
	void	(*add)(char c, struct s_buffer *b);
	void	(*flush)(struct s_buffer *b);
	void	(*addstr)(char *str, struct s_buffer *b);
}				t_buffer;

/*
** preci : precision asked
** width : number length
** flags : 8b flags
** mod : 8b modifier
** type : 1b sign, 1b if precision to check, 14b type
*/

typedef struct	s_specs
{
	size_t			preci;
	size_t			width;
	unsigned char	flags;
	unsigned char	mod;
	unsigned char	info;
	unsigned short	type;
}				t_specs;

int		ft_printf(const char *format, ...);
void	buf_init(t_buffer *b);
void	switch_mode(char **format, t_buffer *b, va_list ap);
void	init_specs(t_specs *specs);
size_t	uatoi(char **fmt);
char	is_contain(char c, char *str);
char	get_base(t_specs *specs);
void	add_flags(char **fmt, t_specs *specs);
size_t	check_flags_start(size_t len, t_specs *specs, t_buffer *b);
void	check_flags_end(size_t len, t_specs *specs, t_buffer *b);
void	add_mod(char **fmt, t_specs *specs);
void	add_width(char **fmt, t_specs *specs);
void	add_preci(char **fmt, t_specs *specs);
void	add_type(char **fmt, t_specs *specs);
/**/
void	print_uchar(unsigned char n, t_specs *specs, t_buffer *b);
void	print_char(char n, t_specs *specs, t_buffer *b);
void	print_ushort(unsigned short n, t_specs *specs, t_buffer *b);
void	print_short(short n, t_specs *specs, t_buffer *b);
void	print_uint(unsigned int n, t_specs *specs, t_buffer *b);
void	print_int(int n, t_specs *specs, t_buffer *b);
void	print_ulong(unsigned long n, t_specs *specs, t_buffer *b);
void	print_long(long n, t_specs *specs, t_buffer *b);
void	print_ullong(unsigned long long n, t_specs *specs, t_buffer *b);
void	print_llong(long long n, t_specs *specs, t_buffer *b);
void	print_uintmax_t(uintmax_t n, t_specs *specs, t_buffer *b);
void	print_intmax_t(intmax_t n, t_specs *specs, t_buffer *b);
void	print_size_t(size_t n, t_specs *specs, t_buffer *b);
void	print_p(size_t n, t_specs *specs, t_buffer *b);
void	print_s(char *s, t_specs *specs, t_buffer *b);
void	print_ws(wchar_t *s, t_specs *specs, t_buffer *b);
void	print_c(char s, t_specs *specs, t_buffer *b);
void	print_wc(wint_t s, t_specs *specs, t_buffer *b);

#endif
