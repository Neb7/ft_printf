/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:31:06 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/11 13:36:32 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n);

void	*ft_printf_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (nmemb < 1 || size < 1)
	{
		r = (void *)malloc(0);
		if (!r)
			return (NULL);
		return (r);
	}
	if (size * nmemb / nmemb != size)
		return (NULL);
	r = (void *)malloc(size * nmemb);
	if (!r)
		return (NULL);
	ft_bzero(r, size * nmemb);
	return (r);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s != NULL)
	{
		while (i * 8 < n && n / 8)
		{
			((long *)s)[i] = 0;
			i++;
			j = j + 8;
		}
		while (j % 8 < n % 8)
		{
			((unsigned char *)s)[j] = 0;
			j++;
		}
	}
}

void	ft_put_flags_negatif(t_flags *flags)
{
	flags->negatif = true;
	flags->plus = false;
	flags->space = false;
}

int	ft_test_char(char *str, int *j)
{
	int	i;

	i = 0;
	while (ft_strchar("0 -+#", str[i]) != -1)
		i++;
	while (ft_strchar("0123456789.", str[i]) != -1)
		i++;
	if (ft_strchar("cspdiuxX%", str[i]) < 0)
	{
		*j = i + 1;
		return (-1);
	}
	return (0);
}
