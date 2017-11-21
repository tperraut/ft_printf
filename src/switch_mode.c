
#include "libftprintf.h"
#include <stdio.h> //DEBUG

static void	switch_print(t_buffer *b, t_specs *specs, va_list ap)
{
	if (GET(specs->mod, M_L) || GET(specs->type, T_UD))
		print_long(va_arg(ap, long), specs, b);
	else if (GET(specs->mod, M_LL))
		print_llong(va_arg(ap, long long), specs, b);
	else if (GET(specs->mod, M_H))
		print_short((short)va_arg(ap, int), specs, b);
	else if (GET(specs->mod, M_HH))
		print_char((char)va_arg(ap, int), specs, b);
	else if (GET(specs->mod, (M_J | M_Z)))
		print_intmax_t(va_arg(ap, intmax_t), specs, b);
	else if (GET(specs->type, (T_D | T_I)))
		print_int(va_arg(ap, int), specs, b);
}

static void	switch_uprint(t_buffer *b, t_specs *specs, va_list ap)
{
	IF(GET(specs->type, T_P), print_p((size_t)va_arg(ap, int *), specs, b))
	ELIF(IS_SIGN(specs->type), switch_print(b, specs, ap))
	ELIF((GET(specs->mod, M_L) && GET(specs->type, T_C))
		|| GET(specs->type, T_UC), print_wc(va_arg(ap, wint_t), specs, b))
	ELIF((GET(specs->mod, M_L) && GET(specs->type, T_S))
		|| GET(specs->type, T_US), print_ws(va_arg(ap, wchar_t *), specs, b))
	ELIF(GET(specs->mod, M_L) || GET(specs->type, (T_UU | T_UO)),
		print_ulong(va_arg(ap, unsigned long), specs, b))
	ELIF(GET(specs->mod, M_LL), print_ullong(va_arg(ap, unsigned long), specs, b))
	ELIF(GET(specs->mod, M_H),
		print_ushort((unsigned short)va_arg(ap, int), specs, b))
	ELIF(GET(specs->mod, M_HH),
		print_uchar((unsigned char)va_arg(ap, int), specs, b))
	ELIF(GET(specs->mod, M_J), print_uintmax_t(va_arg(ap, uintmax_t), specs, b))
	ELIF(GET(specs->mod, M_Z), print_size_t(va_arg(ap, size_t), specs, b))
	ELIF(GET(specs->type, (T_O | T_U | T_X | T_UX | T_B)),
		print_uint(va_arg(ap, unsigned int), specs, b))
	ELIF(GET(specs->type, T_C), print_c((char)va_arg(ap, int), specs, b))
	ELIF(GET(specs->type, T_S), print_s(va_arg(ap, char *), specs, b))
}

void	switch_mode(char **format, t_buffer *b, va_list ap)
{
	t_specs	specs;

	init_specs(&specs);
	if (!format || !*format || !**format || !b || !ap)
		return;
	(*format)++;
	if (**format == '%')
	{
		b->add('%', b);
		(*format)++;
		return;
	}
	add_flags(format, &specs);
	add_width(format, &specs);
	add_preci(format, &specs);
	add_mod(format, &specs);
	add_type(format, &specs);
	if (specs.type)
		switch_uprint(b, &specs, ap);
}
