
#include "libftprintf.h"

static void	switch_print(t_buffer *b, t_specs *sp, va_list ap)
{
	if (GET(sp->mod, M_L) || GET(sp->type, T_UD))
		print_long(va_arg(ap, long), sp, b);
	else if (GET(sp->mod, M_LL))
		print_llong(va_arg(ap, long long), sp, b);
	else if (GET(sp->mod, M_H))
		print_short((short)va_arg(ap, int), sp, b);
	else if (GET(sp->mod, M_HH))
		print_char((char)va_arg(ap, int), sp, b);
	else if (GET(sp->mod, M_J | M_Z))
		print_intmax_t(va_arg(ap, intmax_t), sp, b);
	else if (GET(sp->type, T_D | T_I))
		print_int(va_arg(ap, int), sp, b);
}

static void	classic_mode(t_buffer *b, t_specs *sp, va_list ap)
{
	if (GET(sp->type, T_O | T_U | T_X | T_UX | T_B))
		print_uint(va_arg(ap, unsigned int), sp, b);
	else if (GET(sp->type, T_C))
		print_c((char)va_arg(ap, int), sp, b);
	else if (GET(sp->type, T_S))
		print_s(va_arg(ap, char *), sp, b);
}

static void	switch_uprint(t_buffer *b, t_specs *sp, va_list ap)
{
	if (GET(sp->type, T_P))
		print_p((size_t)va_arg(ap, int *), sp, b);
	else if (IS_SIGN(sp->type))
		switch_print(b, sp, ap);
	else if ((GET(sp->mod, M_L) && GET(sp->type, T_C)) || GET(sp->type, T_UC))
		print_wc(va_arg(ap, wint_t), sp, b);
	else if ((GET(sp->mod, M_L) && GET(sp->type, T_S)) || GET(sp->type, T_US))
		print_ws(va_arg(ap, wchar_t *), sp, b);
	else if (GET(sp->mod, M_L) || GET(sp->type, T_UU | T_UO))
		print_ulong(va_arg(ap, unsigned long), sp, b);
	else if (GET(sp->mod, M_LL))
		print_ullong(va_arg(ap, unsigned long), sp, b);
	else if (GET(sp->mod, M_H))
		print_ushort((unsigned short)va_arg(ap, int), sp, b);
	else if (GET(sp->mod, M_HH))
		print_uchar((unsigned char)va_arg(ap, int), sp, b);
	else if (GET(sp->mod, M_J))
		print_uintmax_t(va_arg(ap, uintmax_t), sp, b);
	else if (GET(sp->mod, M_Z))
		print_size_t(va_arg(ap, size_t), sp, b);
	else
		classic_mode(b, sp, ap);
}

static void	percent_mode(char **fmt, t_buffer *b, t_specs *sp, size_t *len)
{
	*len = check_flags_start(1, sp, b);
	b->add('%', b);
	check_flags_end(*len, sp, b);
	(*fmt)++;
}

void		switch_mode(char **fmt, t_buffer *b, t_specs *sp, va_list ap)
{
	size_t	len;

	len = 0;
	init_specs(sp);
	(*fmt)++;
	add_flags(fmt, sp);
	add_width(fmt, sp);
	add_preci(fmt, sp);
	if (**fmt == '%')
	{
		percent_mode(fmt, b, sp, &len);
		return ;
	}
	add_mod(fmt, sp);
	add_type(fmt, sp);
	if (sp->type)
		switch_uprint(b, sp, ap);
	else
	{
		len = check_flags_start(1, sp, b);
		b->add(**fmt, b);
		check_flags_end(len, sp, b);
		(*fmt)++;
	}
}
