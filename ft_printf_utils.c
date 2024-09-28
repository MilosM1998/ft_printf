/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:39:51 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/28 00:57:21 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_printstr(char *str)
{
    int len;
    
    len = 0;
    while(str[len])
    {
        write(1, &str[len], 1);
        len++;
    }
    return (len);
}

int ft_printnumber(int n)
{
    int len;
    char *str;
    
    len = 0;
    str = ft_itoa(n);
    len = ft_printstr(str);
    free(str);
    return (len);   
}
