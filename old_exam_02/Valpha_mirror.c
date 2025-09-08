/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:56:59 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 10:57:16 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>*/

#include <unistd.h>

int main (int ac, char **av)
{
    int i = 0;
    char c;
    if (ac == 2)
    {
        while (av[1][i] != '\0')
        {
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                c = 'z' - (av[1][i] - 'a');
                write (1, &c, 1);
            }
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                c = 'Z' - (av[1][i] - 'A');
                write (1, &c, 1);
            }
            else
                write (1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return 0;
}
