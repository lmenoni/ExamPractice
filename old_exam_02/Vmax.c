/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:35 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 11:20:42 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int r = 0;
    while (tab && len > 0)
    {
        if (r < tab[len - 1])
            r = tab[len - 1];
        len--;
    }
    return (r);
}

int main()
{
    int tab[20] = {0,1,2,3,3,444,7,8,90,100,11,111};
    int r = max(tab, 12);
    printf ("%d\n", r);
    return 0;
}