/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:43:08 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/12 13:43:14 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:
#include <stdio.h>
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;
    t_list *curr = *begin_list;
    t_list *prev = NULL;
    while (curr != NULL)
    {
        if(!cmp(curr->data, data_ref))
        {
            temp = curr->next;
            free(curr->data);
            free(curr);
            if (prev == NULL)
                *begin_list = temp;
            else
                prev->next = temp;
            curr = temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}