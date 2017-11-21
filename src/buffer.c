#include <unistd.h>
#include "libftprintf.h"

static void	buf_flush(t_buffer *b)
{
	write(1, b->data, MIN(b->size, BUF_SIZE));
	b->size = 0;
}

static void	buf_add(char c, t_buffer *b)
{
	if (!(b->size < BUF_SIZE))
		b->flush(b);
	b->data[b->size] = c;
	b->size++;
}

static void	buf_addstr(char *str, t_buffer *b)
{
	if (!str)
		return;
	while (*str)
	{
		b->add(*str, b);
		str++;
	}
}

void		buf_init(t_buffer *b)
{
	if (!b)
		return;
	b->size = 0;
	b->flush = buf_flush;
	b->add = buf_add;
	b->addstr = buf_addstr;
}
