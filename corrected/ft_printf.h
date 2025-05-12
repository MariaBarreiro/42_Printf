/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:36:42 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/26 13:32:34 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h> 
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_case(va_list args, const char format);
int		ft_unsigned_len(unsigned int content);
int		ft_print_unsigned(unsigned int content);
int		ft_print_nbr(int content);
int		ft_print_char(int content);
int		ft_put_str(char *content);
int		ft_hex_len(unsigned int content);
int		ft_print_hex(unsigned int content, const char format);
int		ft_print_str(char *content);
int		ft_ptr_len(uintptr_t content);
int		ft_print_ptr(unsigned long long content);
int		ft_hex_len(unsigned int content);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int content);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_ptr_itoa(uintptr_t content);
void	ft_hex_itoa(unsigned int content, const char format);
size_t	ft_strlen(const char *str);
// int	main();

#endif
