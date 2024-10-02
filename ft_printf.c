/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:56:46 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/30 20:36:55 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	format_checker(const char format, va_list ap)
{
	char	*str;
	int		count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (format == 's')
	{
		str = va_arg(ap, char *);
		if (str)
			count += ft_printstr(str);
		else
			count += ft_printstr("(null)");
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

/* #include <limits.h>
#include <stdint.h>
#include <stdio.h>

 int	main(void)
{
	ft_printf("Testing with NULL:\n");
	ft_printf("My:%d\n", ft_printf(NULL));
	printf("Org:%d\n", printf(NULL));
	//      X and x
	ft_printf("Testing format x and X\n");
	ft_printf("My: Max hex: %x\n", 4294967295U);  
	printf("Org: Max hex: %x\n", 4294967295U); 
	ft_printf("My:%d\n", ft_printf("Hex zero: %x\n", 0));
	printf("Org:%d\n", printf("Hex zero: %x\n", 0));
	ft_printf("My:%d\n", ft_printf("Hex number: %x\n", 255)); 
	printf("Org:%d\n", printf("Hex number: %x\n", 255)); 
	//      %p
	ft_printf("Testing format p:\n");
	ft_printf("My:\n");
	
	ft_printf("%d\n", ft_printf("Test 1: %p\n", (void *)LONG_MIN));
	ft_printf("%d\n",ft_printf("Test 2: %p\n", (void *)LONG_MAX));
	ft_printf("%d\n",ft_printf("Test 3: %p\n", (void *)(uintptr_t)ULONG_MAX));
	ft_printf("%d\n",ft_printf("Test 4: %p\n", (void *)0));

	ft_printf("Org:\n");
		
	ft_printf("%d\n", ft_printf("Test 1: %p\n", (void *)LONG_MIN));
	ft_printf("%d\n",ft_printf("Test 2: %p\n", (void *)LONG_MAX));
	ft_printf("%d\n",ft_printf("Test 3: %p\n", (void *)(uintptr_t)ULONG_MAX));
	ft_printf("%d\n",ft_printf("Test 4: %p\n", (void *)0));
	//         %%
	ft_printf("Testing percent sign:\n");
	ft_printf("My:%d\n", ft_printf("%% this is %% sign test\n"));
	printf("Org:%d\n", printf("%% this is %% sign test\n"));
	//          %d , %i
	ft_printf("Testing d and i formats:\n");
	ft_printf("My d, int_max:%d\n", ft_printf("%d\n", INT_MAX));
	printf("Org: %d\n", printf("%d\n", INT_MAX));
	ft_printf("My d, int_min:%d\n", ft_printf("%d\n", INT_MIN));
	printf("Org: %d\n", printf("%d\n", INT_MIN));
	// 			i
	ft_printf("My i, int_max:%d\n", ft_printf("%i\n", INT_MAX));
	printf("Org: %d\n", printf("%i\n", INT_MAX));
	ft_printf("My i, int_min:%d\n", ft_printf("%i\n", INT_MIN));
	printf("Org: %d\n", printf("%i\n", INT_MIN));
	//          %s 
	ft_printf("Testing s format:\n");
	ft_printf("My:%d\n", ft_printf("%s\n", "Hello World!"));
	printf("Org:%d\n", printf("%s\n", "Hello World!"));
	
	ft_printf("Empty string test:\n");
	ft_printf("My:%d\n", ft_printf(""));
	printf("Org:%d\n", printf(""));
	
	ft_printf("Testing char:\n");
	ft_printf("My:%d\n", ft_printf("%c\n", 's'));
	printf("Org:%d\n", printf("%c\n", 's'));
	//          %u
	ft_printf("Testing unsigned int:\n");
	ft_printf("My: %d\n", ft_printf("Unsigned zero: %u\n", 0));
	printf("Org: %d\n", printf("Unsigned zero: %u\n", 0));
	ft_printf("My:%d\n", ft_printf("Max unsigned int: %u\n", 4294967295U));
	printf("Org:%d\n", printf("Max unsigned int: %u\n", 4294967295U));
	//          mixed
	ft_printf("Mixed formats:\n");
	ft_printf("My: %d\n", ft_printf("Hello, %s! This is a test from %d school.\
	Char: %c\n", "User", 42, 'F'));  
	printf("Org: %d\n", printf("Hello, %s! This is a test from %d school.\
	 Char: %c\n", "User", 42, 'F')); 
	ft_printf("My:%d\n", ft_printf("Name: %s, Age: %u,\
	 Hex: %x\n", "Jack", 42, 255)); 
	printf("Org:%d\n", printf("Name: %s, Age: %u, Hex:\
	 %x\n", "Jack", 42, 255));  
	int var = 42;
	ft_printf("My: %d\n", ft_printf("Pointer: %p, Hex:\
	 %x, Int: %d\n", &var, 255, var)); 
	printf("My: %d\n", printf("Pointer: %p, Hex:\
	 %x, Int: %d\n", &var, 255, var)); 
}  */
