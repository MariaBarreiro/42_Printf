/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:45:12 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/23 12:46:40 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_format_percent();

int main() {
	ft_format_percent();
}

void ft_format_percent() {
	printf("%%\n", 1);
	ft_printf("%%\n", 1);
	
}
