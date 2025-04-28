/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:59:45 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/26 11:00:30 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *content);

///putstr PARA PRINTSTR

int	ft_put_str(char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		write (1, &content[i], 1);
		i++;
	}
	return (i);
}

///Printstr PARA CHAR *

int	ft_print_str(char *content)
{
	size_t	len;

	len = 0;
	if (content == NULL)
		len = ft_put_str("(null)");
	else
		len = ft_put_str(content);
	return (len);
}

