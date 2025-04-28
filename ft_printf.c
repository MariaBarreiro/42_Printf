
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:54:31 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/21 18:54:56 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case(va_list args, const char format);
int	ft_print_nbr(int content);
int	ft_print_char(int content);

int	ft_printf(const char *format, ...)
{
	size_t		i;
	va_list		args;
	int			len;

	i = 0;
	va_start(args, format);
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_case(args, format[i + 1]);///verificar formato e printar conforme isso
			i++; ///ignorar %
		}
		else
			ft_putchar_fd(format[i], 1);	///printar o que estiver entre aspas
		i++; ///avanca formato (o que estiver a seguir a %) OU 1 caracter (o que
		///			estiver a seguir as aspas (else case));
	}
	va_end(args);///terminar os args
	return (len);///retornar o length do que printei;
}

///criar if tree para checkar formatos
///return da if tree: len a adicionar ao len original!
///estou a mandar um const char porque apenas quero saber o que esta a seguir
///		a percentagem!! o char, nao o que esta dentro do endereco do pointer;

int	ft_case(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len = ft_print_char('%');
	else if (format == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (format == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len = ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), format);
	return (len);
}
///printnbr PARA INTS

int	ft_print_nbr(int content)
{
	char	*converted;
	int		len;

	converted = ft_itoa(content);
	len = ft_print_str(converted);
	free(converted);
	return (len);
}

///printchar PARA CHAR

int	ft_print_char(int content)
{
	write (1, &content, 1);
	return (1);
}
