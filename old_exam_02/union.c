/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:28:44 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 11:28:52 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>

int main(int ac, char **av)
{
    int arr[128];
    int i = 0;
    char *s1 = av[1];
    char *s2 = av[2];

    if (ac == 3)
    {
        while (i <= 128)
        {
            arr[i] = 1;
            i++;
        }
        i = 0;
        while (s1[i] != '\0')
        {
            if (arr[(int)s1[i]] == 1)
            {
                write(1, &s1[i], 1);
                arr[(int)s1[i]] = 0;
            }
            i++;
        }
        i = 0;
        while (s2[i] != '\0')
        {
            if (arr[(int)s2[i]] == 1)
            {
                write(1, &s2[i], 1);
                arr[(int)s2[i]] = 0;
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}