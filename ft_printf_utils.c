/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:39:51 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/29 18:02:39 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}

int	ft_print_nbr(int n)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}

int	ft_puthex(unsigned int n, const char format)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, format);
		count += ft_puthex(n % 16, format);
	}
	else if (n <= 9)
		count += ft_putchar((n + '0'));
	else
	{
		if (format == 'x')
			count += ft_putchar((n - 10) + 'a');
		else if (format == 'X')
			count += ft_putchar((n - 10) + 'A');
	}
	return (count);
}
