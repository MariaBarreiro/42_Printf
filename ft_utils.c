/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:06:40 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/14 19:54:42 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
static char			*ft_char(char *str, unsigned int nb, long int len);
static unsigned int	ft_countdigits(int n);

char	*ft_itoa(int n)
{
	long			nb;
	long int		len;
	char			*str;

	nb = n;
	len = ft_countdigits(n);
	if (nb == 0)
		return (ft_strdup("0"));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (nb < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	str = ft_char(str, nb, (len - 1));
	str[len] = '\0';
	return (str);
}

static unsigned int	ft_countdigits(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_char(char *str, unsigned int nb, long int len)
{
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	n;
	char	*dup;

	n = 0;
	i = ft_strlen(s);
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (n < i)
	{
		dup[n] = s[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

