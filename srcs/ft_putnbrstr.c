/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:52:18 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/06 17:39:35 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_str(char *str, int len_str, t_flags *flags);

/*Affiche le nombre 'str' (qui est en base 10) placer en paramètre en fonction
des flags*/
int	ft_putnbrstr(char *str, t_flags *flags)
{
	int	len_str;
	int	j;
	int	ret;

	ret = 0;
	if (flags->zero)
		flags->s[0] = '0';
	len_str = ft_printf_strlen(str);
	if ((flags->negatif && flags->zero) || (flags->plus && flags->zero))
		write(1, str, 1);
	if (flags->moins)
		ret = ret + ft_write_str(str, len_str, flags);
	if (flags->min != -1 && (flags->min > len_str || flags->min > flags->max))
	{
		if (flags->max > len_str)
			j = flags->max + flags->plus + flags->negatif + flags->space - 1;
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

	if ((flags->negatif && !flags->zero) || (flags->plus) || (flags->space))
		write(1, str, 1);
	ret = 0;
	j = -1;
	if (flags->max != -1 && flags->max > len_str - flags->negatif - \
	flags->plus - flags->space)
		while (++j < flags->max + flags->negatif + flags->plus + \
		flags->space - len_str)
			ret = ret + write(1, "0", 1);
	write(1, &str[flags->negatif + flags->plus + flags->space], len_str - \
	(flags->negatif + flags->plus + flags->space));
	ret = ret + len_str;
	return (ret);
}
