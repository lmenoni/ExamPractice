/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:10:34 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 12:10:50 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

#include <stdio.h>
int position(char c, int base)
{
    int i = 0;
    char *digit = "0123456789abcdef";
    char *DIGIT = "0123456789ABCDEF";
    while (i < base)
    {
        if (c == DIGIT[i] || c == digit[i])
            return (i);
        i++;
    }
    return (-1);
}

int	ft_atoi_base(const char *nbr, unsigned int base)
{
    int i = 0;
    int sign = 1;
    unsigned int r = 0;
    int pos = 0;
    if (nbr[i] == '-')
    {
        sign *= -1;
        i++;
    }
    while ((pos = position(nbr[i], base)) >= 0)
    {
        r = r * base + pos;
        i++;
    }
    if (nbr[i] == '-')
        return (0);
    if (sign < 0 && r == 2147483648)
        return (-2147483648);
    return ((int)r * sign);
}
int main()
{
    printf("%d\n", ft_atoi_base("-bd277696", 14));
	printf("%d\n", ft_atoi_base("B", 16));
	printf("%d\n", ft_atoi_base("C", 16));
	printf("%d\n", ft_atoi_base("D", 16));
	printf("%d\n", ft_atoi_base("e", 16));
	printf("%d\n", ft_atoi_base("E", 16));
	return (0);
}