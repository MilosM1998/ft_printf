/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:07 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/26 23:25:26 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);   
}

static int format_checker(const char *format, va_list ap)
{
    int count;

    count = 0;
    while (*format)
    {
        if (*format == 'd')
        {   
            ft_itoa(va_arg(ap, int));
            count = 
        }
    }
    return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int printed;
    int i;

	va_start(ap, format);
	printed = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            printed += format_checker(&format[i + 1], ap);
            i++;
        }
        else
        {
            printed += ft_putchar(format[i]);
            i++;
        }
    }
    va_end(ap);
    return (printed);
}
int main()
{
    ft_printf("Testing");
}