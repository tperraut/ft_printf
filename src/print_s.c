
#include "libftprintf.h"

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

static void		add_nopt(size_t *len, char c, size_t size, t_buffer *b)
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

static	void	print_ss(size_t *len, char *s, t_buffer *b)
{
	while (*s)
	{
		b->add(*s, b);
		(*len)++;
		s++;
	}
}

void			print_s(char *s, t_specs *sp, t_buffer *b)
{
	size_t	len;

	len = 0;
	if (!s)
		b->addstr("(null)", b);
	else if (GET(sp->info, PRECI))
	{
		if (GET(sp->flags, F_M))
		{
			print_ns(&len, s, sp->preci, b);
			print_nopt(NULL, ' ', (sp->width > len) ? sp->width - len : 0, b);
		}
		else
		{
			len = MIN(ft_strlen(s), sp->preci);
			print_nopt(NULL, ' ', (sp->width > len) ? sp->width - len : 0, b);
			print_ns(NULL, s, len, b);
		}
	}
	else
	{
		if (GET(sp->flags, F_M))
		{
			print_ss(&len, s, b);
			print_nopt(NULL, ' ', (sp->width > len) ? sp->width - len : 0, b);
		}
		else
		{
			len = ft_strlen(s);
			print_nopt(NULL, ' ', (sp->width > len) ? sp->width - len : 0, b);
			print_ns(NULL, s, len, b);
		}
	}
}
