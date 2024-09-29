/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:12:30 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/29 17:54:30 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (count += ft_printstr("0x0"));
	else
	{
		count += ft_printstr("0x");
		count += ft_puthex(ptr, 'x');
	}
	return (count);
}
