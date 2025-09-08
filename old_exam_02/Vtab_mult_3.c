/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:29:13 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/19 16:29:16 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>
#include <unistd.h>
void putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    char c = (n % 10) + '0';
    write (1, &c, 1);
    return ;
}
int ft_atoi(char *s)
{
    int r = 0;
    while (*s)
    {
        r = (r * 10) + (*s - '0');
        s++;
    }
    return (r);
}
int main(int ac, char *av[])
{
    if (ac == 2)
    {
        int i = 1;
        int n = ft_atoi(av[1]);
        while (i < 10)
        {
            putnbr(i);
            write(1, " x ", 3);
            putnbr(n);
            write(1, " = ", 3);
            putnbr((i * n));
            write(1, "\n", 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}