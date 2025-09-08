/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:08:21 by lmenoni           #+#    #+#             */
/*   Updated: 2025/03/12 15:08:22 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int print_ex(unsigned int n)
{
    char *base = "0123456789abcdef";
    int count = 0;

    if (n > 15)
        count += print_ex(n / 16);
    write (1, &base[n % 16], 1);
    return (count + 1);
}

int print_nbr(int n)
{
    int count = 0;
    char c;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (n > 9)
        count += print_nbr(n / 10);
    c = (n % 10) + '0';
    write (1, &c, 1);
    return (count + 1);
}

int print_str(char *s)
{
    int count = 0;
    
    if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while (s[count] != '\0')
    {
        write(1, &s[count], 1);
        count++;
    }
    return (count);
}

int ft_printf(const char *s, ... )
{
    int i = 0;
    int count = 0;
    va_list args; 
    
    va_start(args, s);
    while (s[i] != '\0')
    {
        if (s[i] == '%')
        {
            i++;
            if (s[i] == 's')
                count += print_str(va_arg(args, char *));
            if (s[i] == 'd')
                count += print_nbr(va_arg(args, int));
            if (s[i] == 'x')
                count += print_ex(va_arg(args, unsigned int));
        }
        else
        {
            write(1, &s[i], 1);
            count++;
        }
        if (s[i] != '\0')
            i++;
    }
    va_end(args);
    return (count);
}

int main()
{
    ft_printf("%d characters were printed\n", ft_printf("s is %s\nd is %d\nx is %x\n", "ciao", "42", 42));
    printf ("%d characters were printed\n", printf("s is %s\nd is %d\nx is %x\n", "ciao", 42, 42));
    return (0);
}
