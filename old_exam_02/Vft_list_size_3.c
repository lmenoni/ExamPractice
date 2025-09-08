/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:11:24 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 12:11:32 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:*/
#include <stdio.h>
#include <stdlib.h>
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}

int main()
{
    t_list *list;
    t_list *new;
    t_list *neew;
    int i = 42;
    list = malloc(sizeof(t_list));
    new = malloc(sizeof(t_list));
    neew = malloc(sizeof(t_list));
    list->data = &i;
    list->next = NULL;
    new->data = &i;
    new->next = NULL;
    neew->data = &i;
    neew->next = NULL;
    new->next = neew;
    list->next = new;
    printf("%d\n", ft_list_size(list));
    return (0);
}
