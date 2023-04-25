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
