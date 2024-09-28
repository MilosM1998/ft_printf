/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:07 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/28 15:19:37 by mmilicev         ###   ########.fr       */
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
            count += ft_print_int(va_arg(ap, int));
        if (format == 's')
            count += ft_printstr(va_arg(ap, char *));
        if (format == 'c')
            count += ft_putchar(va_arg(ap, int));
        if (format == 'p')
            count += ft_printp(va_arg(ap, unsigned long));
        if (format == 'x' || format == 'X')
            count += ft_printhex(va_arg(ap, unsigned int), format);
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
        if (*format == '%' && (*(format + 1) == '%'))
        {
            printed += ft_putchar('%');
            format += 2;
        }
        else if (*format == '%')
        {
            format++;
            printed += format_checker(*format++, ap);
        }
        else
            printed += ft_putchar(*format++);
    }
    va_end(ap);
    return (printed);
}
#include <stdio.h>
int main()
{
    //      X and x
    ft_printf("Testing format x and X\n");
    unsigned int n_x = 24241241;
    int x_len2 = printf("%x\n", n_x);
    int x_len = ft_printf("%x\n", n_x); 
    ft_printf("My:%x\n", x_len);
    printf("Org:%d\n", x_len2);
    
    //      %p
    ft_printf("Testing format p:\n");
    char *n_p;
    n_p = "Hello";
    int p_len2 = printf("%p\n", n_p);
    int p_len = ft_printf("%p\n", n_p); 
    ft_printf("My:%d\n", p_len);
    printf("Org:%d\n", p_len2);
    
    //         %%
    ft_printf("Testing for percent sign:\n");
    int sign_len = ft_printf("%%\n");
    int sign_len2 = printf("%%\n");   
    ft_printf("My:%d\n", sign_len);
    printf("Org: %d\n", sign_len2);
    
    
}