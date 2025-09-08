/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:49 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 11:31:56 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *s)
{
    int r = 0;
    int i = 0;
    int sign = 1;
    if (s[i] == '-')
    {
        sign *= -1;
        i++;
    }
    while(s[i])
    {
        r *= 10;
        r += s[i] - '0';
        i++;
    }
    return (r * sign);
}

int is_prime(int n)
{
    int i = 1;
    while (i <= (n / 2))
    {
        if (i != 1 && n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

void ft_putnbr(int n)
{
    char c;
    int dec = 1;
    while (n / dec > 9)
        dec *= 10;
    while (dec >= 1)
    {
        c = (n / dec) + '0';
        write (1, &c, 1);
        n %= dec;
        dec /= 10;
    }
    write (1, "\n", 1);
    return ;
}

int main(int ac, char **av)
{
    int i = 2;
    int r = 0;
    if (ac != 2)
    {
        write(1, "0\n", 2);
        return 0;
    }
    int n = ft_atoi(av[1]);
    if (n < 0)
    {
        write(1, "0\n", 2);
        return 0;
    }
    while (i <= n)
    {
        if (is_prime(i))
        {
            r += i;
        }
        i++;
    }
    ft_putnbr(r);
    return 0;
}
