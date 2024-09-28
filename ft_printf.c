/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:07 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/28 01:05:44 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

// formats: cspdiuxX%

int format_checker(const char format, va_list ap)
{
    int count;

    count = 0;
        if (format == 'd')
            count += ft_printnumber(va_arg(ap, int));
        if (format == 's')
            count += ft_printstr(va_arg(ap, char *));
        if (format == 'c')
            count += ft_putchar(va_arg(ap, int));
        if (format == 'x' || format == 'X')
            count += ft_printhex(va_arg(ap, unsigned long long), format);
    return (count);            
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int printed;

	va_start(ap, format);
	printed = 0;
    while (*format)
    {
        if (*format == '%' && (*++format))
            printed += format_checker(*format++, ap);
        else
            printed += ft_putchar(*format++);
    }
    va_end(ap);
    return (printed);
}
#include <stdio.h>
int main()
{
    unsigned int n = 24241241;
    int len2 = printf("Org:%x\n", n);
    int len = ft_printf("My:%x\n", n); 
    ft_printf("%d\n", len);
    printf("%d\n", len2);    
}