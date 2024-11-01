/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:31:06 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/01 13:33:41 by benpicar         ###   ########.fr       */
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
