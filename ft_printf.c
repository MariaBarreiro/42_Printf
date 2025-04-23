/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:54:31 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/21 18:54:56 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	int			len;

	i = 0;
	va_start(args, format);
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			///verificar formato e printar conforme isso
			///ignorar %
		}
		else
			///printar o que estiver entre aspas
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
		len = ft_printchar('%');
	else if (format == 'c')
		len = ft_printchar(va_arg(args, char));
	else if (format == 's')
		len = ft_printstr(va_args(args, char *));
	else if (format == 'p')
		len = va_args(args, unsigned long long)
	else if (format == 'd' || format == 'i')
		len = ft_printnbr(va_args(args, int));
	else if (format == 'u')
		len = ft_printunsigned(va_args(args, unsigned int));
	else if (format == 'x')
		len = 
	else if (format == 'X')
		len = 
	return (len);
}

///Unsigneditoa PARA PRINT UNSIGNED

char *ft_unsigneditoa(unsigned int content)
{
	unsigned int		len;
	char			*str_converted;

	len = ft_unsignedlen(n);
	if (content == 0)
		return (ft_strdup("0"));
	str_converted = (char *)malloc((len + 1) * sizeof(char));
	if (!str_converted)
		return (0);
	if (content < 0)
	{
		content = -content;
		str_converted[0] = '-';
	}
	while (content > 0)
	{
		str_converted[len--] = (content % 10) + '0';
		content /= 10;
	}
	return (str_converted);
}

///ft_unsignedlen PARA CONTAR DIGITOS DO UNSIGNED ITOA

unsigned int ft_unsignedlen(unsigned int content)
{
	unsigned int	len;

	len = 0;
	if (content <= 0)
		len = 1;
	while (content)
	{
		content /= 10;
		len++;
	}
	return (len);
}

///printunsigned PARA UNSIGNED INT

int	ft_printunsigned(unsigned int content)
{
	char *str_converted;
	unsigned int	len;

	str_converted = ft_unsigneditoa(content);
	len = ft_printstr(str_converted);
	free(str_converted);
	return (len);
}

///printnbr PARA INTS

int	ft_printnbr(int	content)
{
	char *converted;
	int	len;

	converted = ft_itoa(content);
	len = ft_printstr(converted);
	free(converted);
	return (len);
}

///printchar PARA CHAR

int	ft_printchar(int content)
{
	write (1, &content, 1);
	return (1);
}

///putstr PARA PRINTSTR

int	ft_putstr(char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		write (1, &content[i], 1)
		i++;
	}
	return (i);
}

///Printstr PARA CHAR *

int	ft_printstr(char *content)
{
	size_t	len;

	len = 0;
	if (content == NULL)
		len = ft_putstr("(null)");
	else
		len = ft_putstr(content);
	return (len);
}
