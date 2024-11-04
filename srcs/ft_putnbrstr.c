/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:52:18 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/04 11:09:48 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_str(char *str, int len_str, t_flags *flags);

int	ft_putnbrstr(char *str, t_flags *flags)
{
	int	len_str;
	int	j;
	int	ret;

	ret = 0;
	if (flags->zero)
		flags->s[0] = '0';
	len_str = ft_printf_strlen(str);
	if (flags->negatif && flags->zero)
		write(1, str, 1);
	if (flags->moins)
		ret = ret + ft_write_str(str, len_str, flags);
	if (flags->min != -1 && (flags->min > len_str || flags->min > flags->max))
	{
		if (flags->max > len_str)
			j = flags->max - 1;
		else
			j = len_str - 1;
		while (++j < flags->min)
			ret = ret + write(1, flags->s, 1);
	}
	if (!flags->moins)
		ret = ret + ft_write_str(str, len_str, flags);
	free(str);
	return (ret);
}

static int	ft_write_str(char *str, int len_str, t_flags *flags)
{
	int	j;
	int	ret;

	if (flags->negatif && !flags->zero)
		write(1, str, 1);
	ret = 0;
	j = -1;
	if (flags->max != -1 && flags->max > len_str - flags->negatif)
		while (++j < flags->max + flags->negatif - len_str)
			ret = ret + write(1, "0", 1);
	write(1, &str[flags->negatif], len_str - flags->negatif);
	ret = ret + len_str;
	return (ret);
}
/*
static int	ft_write_zero(char *str, int len_str, t_flags *flags)
{
	int	j;
	int	ret;
	int	have_zero;

	have_zero = 0;
	if (!flags->zero && flags->negatif)
		have_zero = 1;
	ret = 0;
	j = -1;
	if (flags->max != -1 && flags->max > len_str - flags->negatif)
		while (++j < flags->max + flags->negatif - len_str)
			ret = ret + write(1, flags->s, 1);
	write(1, &str[flags->negatif - have_zero], len_str - \
	(flags->negatif - have_zero));
	ret = ret + len_str;
	return (ret);
}

static int	ft_write_space(char *str, int len_str, t_flags *flags)
{
	int	j;
	int	ret;

	ret = 0;
	j = -1;
	if (flags->max != -1 && flags->max > len_str - flags->negatif)
		while (++j < flags->max + flags->negatif - len_str)
			ret = ret + write(1, "0", 1);
	write(1, &str[flags->negatif], len_str - flags->negatif);
	ret = ret + len_str;
	return (ret);
}
*/