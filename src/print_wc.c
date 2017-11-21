
#include "libftprintf.h"
#include <unistd.h>

void	print_wc(wint_t c, t_specs *specs, t_buffer *b)
{
	if (!specs)
		return;
	if (c < 0x80)
		b->add(c, b);
	else if (c < 0x800)
	{
		b->add((((c & 0x07C0) >> 6) + 0xC0), b);
		b->add(((c & 0x003F) + 0x80), b);
	}
	else if (c < 0x10000)
	{
		b->add((((c & 0xF000) >> 12) + 0xE0), b);
		b->add((((c & 0x0Fc0) >> 6) + 0x80), b);
		b->add(((c & 0x003F) + 0x80), b);
	}
	else if (c < 0x11FFFF)
	{
		b->add((((c & 0x1c0000) >> 18) + 0xF0), b);
		b->add((((c & 0x03F000) >> 12) + 0x80), b);
		b->add((((c & 0x0Fc0) >> 6) + 0x80), b);
		b->add(((c & 0x003F) + 0x80), b);
	}
}
