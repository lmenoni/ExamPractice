/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:10:14 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 11:10:23 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/

#include <stdio.h>

int cerca_char(char c, const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (c == s[i])
            return (1);
        i++;
    }
    return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j = 0;
    while (!cerca_char(s[i], reject))
    {
        j++;
        i++;
    }
    return (j);
}

int main()
{
    char *s = "ciaohujahhdqh";
    char *reject = "hiubvg";
    printf("%zu\n", ft_strcspn(s, reject));
    return 0;
}