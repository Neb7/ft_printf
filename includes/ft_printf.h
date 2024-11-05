/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:55:19 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/04 11:04:37 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

# define PTRNULL "(nil)"

typedef struct s_flags
{
	bool	dieze;
	bool	space;
	bool	plus;
	bool	moins;
	bool	zero;
	bool	negatif;
	ssize_t	min;
	ssize_t	max;
	char	s[2];
}	t_flags;

/*ft_printf*/

int		ft_printf(const char *str, ...);

/*ft_printf_utils.c*/

int		ft_len_a(unsigned long int a, int len, unsigned int len_base);
int		ft_printf_strlen(char *str);
int		ft_strchar(char *str, int c);
ssize_t	ft_printf_atoi(char *str, int *i);
void	ft_verif_flags(t_flags *flags);

/*ft_printf_put.c*/

int		ft_printf_putchar(int c, t_flags *flags);
int		ft_printf_putstr(char *str, t_flags *flags);
int		ft_printf_putptr(void *ptr, t_flags *flags);
int		ft_putnbr_base(long int n, char *base);

/*ft_itoa_base*/

char	*ft_itoa_base(long int n, char *base, t_flags *flags);

/*ft_putnbrstr.c*/

int		ft_putnbrstr(char *str, t_flags *flags);

/*ft_printf_calloc.c*/

void	*ft_printf_calloc(size_t nmemb, size_t size);

int		ft_putnbr_hex(char *str, t_flags *flags);

#endif
