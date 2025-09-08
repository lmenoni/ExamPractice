/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:12:58 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 11:13:04 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/
#include <stdio.h>

char    *ft_strrev(char *str)
{
    int i = 0;
    int j = 0;
    char t = 0;

    while (str[j] != '\0')
        j++;
    j--;
    while (i < j)
    {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
    return (str);
}

int main()
{
    char s[] = "ciao0!!";
    printf("%s\n", ft_strrev(s));
    return 0;
}