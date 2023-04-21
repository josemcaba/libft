/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:20:52 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/21 19:31:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Nombre de función		:	ft_lstlast
// Prototipo				:	t_list *ft_lstlast(t_list *lst);
// Parámetros				:	lst: el principio de la lista.
// Valor devuelto			:	El último nodo de la lista
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Devuelve el último nodo de la lista.

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (lst == NULL)
		return (0);
	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}
