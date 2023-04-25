/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:22:24 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/25 09:22:24 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros     : lst : un puntero a un nodo.
//				    f   : la dirección de un puntero a una función usada en la
//                        iteración de cada elemento de la lista. 
//				    del : un puntero a función utilizado para eliminar el 
//					      contenido de un nodo, si es necesario.
// Valor devuelto : La nueva lista
//					NULL si falla la reserva de memoria.
// Func. autoriz. : malloc, free
// Descripción    : Itera la lista ’lst’ y aplica la función ’f’ al contenido
//                  de cada nodo. Crea una lista resultante de la aplicación
//                  correcta y sucesiva de la función ’f’ sobre cada nodo. La
//                  función ’del’ se utiliza para eliminar el contenido de un
//                  nodo, si hace falta.

#include "libft.h"

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	while ((*lst).next)
	{
		lst = (*lst).next;
		new_node = ft_lstnew((*f)(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (new_lst == NULL)
			new_lst = new_node;
		else
			ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}


#include "libft.h"
#include <stdio.h>

void *add_one(void *num)
{
    int *new_num = (int *)malloc(sizeof(int));
    *new_num = *((int *)num) * (-1);
    return (new_num);
}

void free_int(void *num)
{
    free(num);
}

int main(void)
{
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    t_list *lst;
    lst = ft_lstnew(&num1);
    ft_lstadd_back(&lst, ft_lstnew(&num2));
    ft_lstadd_back(&lst, ft_lstnew(&num3));

    t_list *new_lst = ft_lstmap(lst, add_one, free_int);

    // Imprimir los valores de la lista original
    printf("Valores de la lista original:\n");
    while (lst)
    {
        printf("%d\n", *((int *)lst->content));
        lst = lst->next;
    }

    // Imprimir los valores de la lista modificada
    printf("Valores de la lista modificada:\n");
    while (new_lst)
    {
        printf("%d\n", *((int *)new_lst->content));
        new_lst = new_lst->next;
    }

    // Liberar memoria
    ft_lstclear(&lst, free_int);
    ft_lstclear(&new_lst, free_int);

    return (0);
}

