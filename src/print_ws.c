
#include "libftprintf.h"

void	print_ws(wchar_t *s, t_specs *specs, t_buffer *b)
{
	if (!s)
		return;
	while (*s != L'\0')
	{
		print_wc((wint_t)*s, specs, b);
		s++;
	}

}
