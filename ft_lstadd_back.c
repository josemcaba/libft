/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:21:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/22 22:21:30 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parámetros				:	lst: el puntero al primer nodo de una lista.
//								new: el puntero a un nodo que añadir a la lista.
// Valor devuelto			:	Nada
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Añade el nodo ’new’ al final de la lista ’lst’.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	if (node == NULL)
		*lst = new;
	else
		node->next = new;
}
