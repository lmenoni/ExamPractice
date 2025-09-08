/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:39:25 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 13:39:32 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : fprime
// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------

// Write a program that takes a positive int and displays its prime factors on the
// standard output, followed by a newline.

// Factors must be displayed in ascending order and separated by '*', so that
// the expression in the output gives the right result.

// If the number of parameters is not 1, simply display a newline.

// The input, when there is one, will be valid.

// Examples:

// $> ./fprime 225225 | cat -e
// 3*3*5*5*7*11*13$
// $> ./fprime 8333325 | cat -e
// 3*3*5*5*7*11*13*37$
// $> ./fprime 9539 | cat -e
// 9539$
// $> ./fprime 804577 | cat -e
// 804577$
// $> ./fprime 42 | cat -e
// 2*3*7$
// $> ./fprime 1 | cat -e
// 1$
// $> ./fprime | cat -e
// $
// $> ./fprime 42 21 | cat -e
// $

#include <stdio.h>

int is_prime(int n)
{
    int i;

    i = 2;
    while (i <= n / 2)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void    prime_factors(int n)
{
    int i;

    if (n == 1)
    {
        printf("1\n");
        return ;
    }
    i = 2;
    while (n > 1)
    {
        if (is_prime(i) == 1)
        {
            while (n % i == 0)
            {
                printf("%d", i);
                n /= i;
                if (n > 1)
                    printf("*");
            }
        }
        i++;
    }
    printf("\n");
}

int main()
{
    prime_factors(225225);
    prime_factors(8333325);
    prime_factors(9539);
    prime_factors(804577);
    prime_factors(42);
    prime_factors(1);
}