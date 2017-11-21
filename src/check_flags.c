
#include <libftprintf.h>
#include <stdio.h> //DEBUG


static void	add_nopt(size_t *len, char c, size_t size, t_buffer *b)
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

static size_t	init_check_flags(size_t len, t_specs *specs)
{
	if (GET(specs->info, PRECI))
	{
		specs->preci = ((specs->preci > len) ? specs->preci - len : 0);
		len += specs->preci;
	}
	if (GET(specs->flags, (F_P | F_SP)) && IS_SIGN(specs->type))
		len++;
	if (GET(specs->flags, F_S) && !GET(specs->info, IS_0))
	{
		IF(GET(specs->type, (T_X | T_UX)), len += 2)
		ELIF(GET(specs->type, (T_O | T_UO)), len++)
	}
	return (len);
}

static size_t	right_check_flags(size_t len, t_specs *specs, t_buffer *b)
{
	add_nopt(&len, ' ', (len < specs->width) ? specs->width - len : 0, b);
	if (IS_SIGN(specs->type))
	{
		if (!GET(specs->info, SIGN))
		{
			if (GET(specs->flags, F_P))
				b->add('+', b);
			else if (GET(specs->flags, F_SP))
				b->add(' ', b);
		}
		else
			b->add('-', b);
	}
	if (GET(specs->flags, F_S) && !GET(specs->info, IS_0))
	{
		IF(GET(specs->type, T_X), b->addstr("0x", b))
		ELIF(GET(specs->type, T_UX), b->addstr("0X", b))
		ELIF(GET(specs->type, (T_O | T_UO)) && !specs->preci, b->add('0', b))
	}
	if (GET(specs->flags, F_Z) && !GET(specs->flags, F_M))
		add_nopt(&len, '0', (len < specs->width) ? specs->width - len : 0, b);
	return (len);
}

size_t		check_flags_start(size_t len, t_specs *specs, t_buffer *b)
{
	len = init_check_flags(len, specs);
	if (GET(specs->flags, (F_M | F_Z)) || len >= specs->width)
	{
		if (IS_SIGN(specs->type))
		{
			if (!GET(specs->info, SIGN))
			{
				if (GET(specs->flags, F_P))
					b->add('+', b);
				else if (GET(specs->flags, F_SP))
					b->add(' ', b);
			}
			else
				b->add('-', b);
		}
		if (GET(specs->flags, F_S) && !GET(specs->info, IS_0))
		{
			IF(GET(specs->type, T_X), b->addstr("0x", b))
			ELIF(GET(specs->type, T_UX), b->addstr("0X", b))
			ELIF(GET(specs->type, (T_O | T_UO)) && !specs->preci, b->add('0', b))
		}
		if (GET(specs->flags, F_Z) && !GET(specs->flags, F_M))
			add_nopt(&len, '0', (len < specs->width) ? specs->width - len : 0, b);
	}
	else
		len = right_check_flags(len, specs, b);
	add_nopt(NULL, '0', specs->preci, b);
	return (len);
}

void		check_flags_end(size_t len, t_specs *specs, t_buffer *b)
{
	add_nopt(&len, ' ', (len < specs->width) ? specs->width - len : 0, b);
}
