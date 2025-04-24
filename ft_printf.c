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

#include "ft_printf.h"
#include <stdio.h>

int		ft_case(va_list args, const char format);
int		ft_hex_len(unsigned int content);
char	*ft_unsigned_itoa(unsigned int content);
int		ft_unsigned_len(unsigned int content);
int		ft_print_unsigned(unsigned int content);
int		ft_print_nbr(int content);
int		ft_print_char(int content);
int		ft_put_str(char *content);
int		ft_print_str(char *content);
void	ft_hex_itoa(unsigned int content, const char format);
int		ft_hex_len(unsigned int content);
int		ft_print_hex(unsigned int content, const char format);

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

///ft_ptr_itoa



///ft_ptr_len

int	ft_ptr_len(unsigned long long content)
{

}

///ft_print_ptr

int	ft_print_ptr(unsigned long long content)
{
	unsigned int	len;

	len = ft_ptr_len(content);
	return (len)
}

///ft_hex_itoa 

void	ft_hex_itoa(unsigned int content, const char format)
{
	if (content >= 16)
	{
		ft_hex_itoa(content / 16, format);
		ft_hex_itoa(content % 16, format);
	}
	else
	{
		if (content <= 9)
		{
			ft_putchar_fd((content + '0'), 1);
		}
		if (content > 9 && content <= 16)
		{
			if (format == 'x')
				ft_putchar_fd(((content - 10) + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd(((content - 10) + 'A'), 1);
		}
	}
}

///ft_hex_len PARA CONTAR A LEN DO HEX A RETORNAR

int	ft_hex_len(unsigned int content)
{
	unsigned int	length;

	length = 0;
	while (content != 0)
	{
		content /= 16;
		length++;
	}
	return (length);
}

///ft_print_hex PARA PRINTAR HEXADECIMAIS

int	ft_print_hex(unsigned int content, const char format)
{
	unsigned int	len;

	ft_hex_itoa(content, format);
	len = ft_hex_len(content);
	return (len);
}

///Unsigneditoa PARA PRINT UNSIGNED

char	*ft_unsigned_itoa(unsigned int content)
{
	unsigned int	len;
	char			*str_converted;

	len = ft_unsigned_len(content);
	if (content == 0)
		return (ft_strdup("0"));
	str_converted = (char *)malloc((len + 1) * sizeof(char));
	if (!str_converted)
		return (0);
	while (content > 0)
	{
		str_converted[len--] = (content % 10) + '0';
		content /= 10;
	}
	return (str_converted);
}

///ft_unsigned_len PARA CONTAR DIGITOS DO UNSIGNED ITOA

int	ft_unsigned_len(unsigned int content)
{
	unsigned int	length;

	length = 0;
	if (content <= 0)
		length = 1;
	while (content)
	{
		content /= 10;
		length++;
	}
	return (length);
}

///printunsigned PARA UNSIGNED INT

int	ft_print_unsigned(unsigned int content)
{
	char			*str_converted;
	unsigned int	len;

	str_converted = ft_unsigned_itoa(content);
	len = ft_print_str(str_converted);
	free(str_converted);
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
