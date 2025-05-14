/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:13:58 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/28 22:29:41 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int output_OG;
	int output_FT;

	printf("------------%%u------------\n");
	unsigned nbr_u = 42;
	ft_printf("FT -> %u\n", nbr_u);
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	printf("ft: [%d]\n", ft_printf("ft {%u} ", 0));
	printf("Og: [%d]\n", printf("Og {%u} ", 0));
}
