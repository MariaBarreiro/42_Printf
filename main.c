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
#include <unistd.h>

int main(){
	int i = 42;
	printf("%p\n", &i);
	ft_printf("%x\nSchizophrenia", 17);
	return (0);
}

