/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:56:46 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/29 17:56:52 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

// formats: cspdiuxX%

int	format_checker(const char format, va_list ap)
{
	int	count;
	char	*str;

	count = 0;
	str = va_arg(ap, char *);
	if (format == 'd' || format == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (format == 's')
	{
		if (str)
			count += ft_printstr(str);
		else
			count+= ft_printstr("(null)");
	}
	else if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 'p')
		count += ft_printp(va_arg(ap, unsigned long));
	else if (format == 'x' || format == 'X')
		count += ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == 'u')
		count += ft_print_uint(va_arg(ap, unsigned int));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				printed += format_checker(*format++, ap);
		}
		else
			printed += ft_putchar(*format++);
	}
	va_end(ap);
	return (printed);
}
/*
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
int main() {
    ft_printf("Test 1: %p\n", (void *)LONG_MIN);
    ft_printf("Test 2: %p\n", (void *)LONG_MAX);
    ft_printf("Test 3: %p\n", (void *)(uintptr_t)ULONG_MAX);
    ft_printf("Test 4: %p\n", (void *)0);
    
    return 0;
}
*/

/* #include <limits.h>
#include <stdio.h>

int	main(void)
{
	ft_printf("testing with NULL:\n");
	ft_printf("My:%d\n", ft_printf(NULL));
	printf("Org:%d\n", printf(NULL));

	 		ft_printf("Testing formats without arguments:\n");
		ft_printf("My:%d\n", ft_printf("%d\n"));
		printf("Org:%d\n", printf("%d\n"));
			
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
	ft_printf("Testing percent sign:\n");

	ft_printf("My:%d\n", ft_printf("%% this is %% sign test\n"));
	printf("Org:%d\n", printf("%% this is %% sign test\n"));
	//          %d , %i
	ft_printf("Testing d and i formats:\n");
	int n = INT_MAX;
	int d_len = ft_printf("%d\n", n);
	int d_len2 = printf("%d\n", n);
	int i_len = ft_printf("%i\n", n);
	int i_len2 = printf("%i\n", n);
	ft_printf("My:%d\n", d_len);
	printf("Org: %d\n", d_len2);
	ft_printf("My:%d\n", i_len);
	printf("Org: %d\n", i_len2);
	//          %s %c
	ft_printf("Testing s and c formats:\n");
	char *str = "world!";
	int s_len = ft_printf("%s\n", str);
	int s_len2 = printf("%s\n", str);
	ft_printf("My:%d\n", s_len);
	printf("Org:%d\n", s_len2);
	ft_printf("Empty string test:\n");
	ft_printf("My:%d\n", ft_printf(""));
	printf("Org:%d\n", printf(""));
	ft_printf("Testing char:\n");
	char c = 's';
	int char_len = ft_printf("%c\n", c);
	int char_len2 = printf("%c\n", c);
	ft_printf("My:%d\n", char_len);
	printf("Org:%d\n", char_len2);
	//          %u
	ft_printf("Testing unsigned int:\n");
	int un = INT_MIN;
	int u_len = ft_printf("%u\n", un);
	int u_len2 = printf("%u\n", un);
	ft_printf("My:%d\n", u_len);
	printf("Org:%d\n", u_len2);
	//          mixed
	int d = 42;
	ft_printf("Hello %s, this i%c a test, %d.\n", str, c, d);
} */ 
