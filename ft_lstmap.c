/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:11:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/21 22:27:37 by jocaball         ###   ########.fr       */
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

static void	ft_lstappend(t_list **lst, t_list node)
{
	if (lst == NULL)
		
		
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = NULL;
	if (lst)
	{
		new_lst = ft_lstnew((*lst).content);
	}
	(void)lst;
	(void)f;
	(void)del;
	return (0);
}
