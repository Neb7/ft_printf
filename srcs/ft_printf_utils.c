/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:52:34 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/06 15:50:06 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Longueur necessaire pour mettre 'a' dans un 'char *'*/
int	ft_len_a(unsigned long int a, int len, unsigned int len_base)
{
	while (a > 0)
	{
		a = a / len_base;
		len++;
	}
	return (len);
}

int	ft_printf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*Cherche 'c' dans 'str' et renvoie le premier indice trouvé ou -1 sùil ne
trouve rien*/
int	ft_strchar(char *str, int c)
{
	int	i;

	if (! str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (-1);
}

/*Atoi simplifié*/
ssize_t	ft_printf_atoi(char *str, int *i)
{
	ssize_t	y;

	y = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		y = (y * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (y);
}

/*Met à jour flags par rapport aux flags qui l'emporte sur d'autres*/
void	ft_verif_flags(t_flags *flags)
{
	if (flags->plus)
		flags->space = false;
	if (flags->moins || flags->max != -1)
		flags->zero = false;
}
