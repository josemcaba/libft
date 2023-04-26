/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:22:24 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/25 20:47:43 by jocaball         ###   ########.fr       */
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

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	while (*lst)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	if (node == NULL)
		*lst = new;
	else
		node->next = new;
}

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
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}



void *add_one(void *num)
{
    int *new_num = (int *)malloc(sizeof(int));
    *new_num = *((int *)num) + 'A' - 1;
    return (new_num);
}



void free_int(void *num)
{
    free(num);
}



void imprime(void *num)
{
    printf("%d\n", *(int *)num);
}

int main(void)
{
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    t_list *lst;
	t_list *new_lst;

    lst = ft_lstnew(&num1);
    ft_lstadd_back(&lst, ft_lstnew(&num2));
    ft_lstadd_back(&lst, ft_lstnew(&num3));

    new_lst = ft_lstmap(lst, add_one, free_int);

    // Imprimir los valores de la lista original
    printf("Valores de la lista original:\n");
    ft_lstiter(lst, imprime);

    // Imprimir los valores de la lista modificada
    printf("Valores de la lista modificada:\n");
    ft_lstiter(new_lst, imprime);

    // Liberar memoria
//    ft_lstclear(&lst, free_int);
    ft_lstclear(&new_lst, free_int);

    return (0);
}

