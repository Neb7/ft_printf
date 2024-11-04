/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:52:35 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/04 11:13:51 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnull(char *str, t_flags *flags, int len);

int	ft_printf_putchar(int c, t_flags *flags)
{
	int	i;

	i = 0;
	if (!flags->moins)
		while (++i < flags->min)
			write(1, " ", 1);
	write(1, &c, 1);
	if (flags->moins)
		while (++i < flags->min)
			write(1, " ", 1);
	return (i);
}

int	ft_printf_putstr(char *str, t_flags *flags)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	if (!str)
		return (ft_putnull("(null)", flags, 6));
	i = ft_printf_strlen(str);
	if (flags->max != -1 && flags->max < i)
		i = flags->max;
	if (flags->moins)
		write(1, str, i);
	if (flags->min != -1 && flags->min > i)
	{
		j = i - 1;
		while (++j < flags->min)
			ret = ret + write(1, flags->s, 1);
	}
	if (!flags->moins)
		write(1, str, i);
	ret = ret + i;
	return (ret);
}

int	ft_printf_putptr(void *ptr, t_flags *flags)
{
	unsigned long int	a;
	char				buf[20];
	int					len;

	if (!ptr)
		return (ft_putnull(PTRNULL, flags, ft_printf_strlen(PTRNULL)));
	a = (unsigned long int)ptr;
	len = ft_len_a(a, 0, 16) + 2;
	buf[0] = '0';
	buf[1] = 'x';
	buf[len] = 0;
	while (a > 0)
	{
		buf[len - 1] = "0123456789abcdef"[a % 16];
		a = a / 16;
		len--;
	}
	if (flags->zero)
		flags->s[0] = '0';
	return (ft_printf_putstr(buf, flags));
}

static int	ft_putnull(char *str, t_flags *flags, int len)
{
	int	j;
	int	ret;

	j = -1;
	ret = len;
	if (flags->moins)
		write(1, str, len);
	if (flags->max != -1 && flags->max > len)
		while (++j < flags->max - len)
			ret = ret + write(1, flags->s, 1);
	if (!flags->moins)
		write(1, str, len);
	return (ret);
}

/*
int	ft_putnbr_base(long int n, char *base)
{
	long unsigned int	nb;
	long unsigned int	len;
	unsigned int		signe;
	int					len_buf;
	
	signe  = 0;
	len = (long unsigned int)ft_printf_strlen(base);
	if (n < 0)
	{
		ft_printf_putchar('-');
		nb = -n;
		signe++;
	}
	else
		nb = n;
	len_buf = ft_len_a(nb, 0, len) + signe;
	if (nb > len - 1)
	{
		ft_putnbr_base((long int)(nb / len), base);
		nb = nb % len;
	}
	ft_printf_putchar(base[nb]);
	return (len_buf);
}*/
