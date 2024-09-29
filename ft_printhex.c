/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:25:37 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/29 17:59:49 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
		return (ft_putchar('0'));
	return (ft_puthex(n, format));
}
