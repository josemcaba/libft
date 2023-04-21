/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:19:15 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/21 17:32:20 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Nombre de función		:	ft_lstadd_front

// Prototipo				:	void ft_lstadd_front(t_list **lst, t_list *new);

// Parámetros				:	lst: la dirección de un puntero al primer nodo
//  							de una lista.
// 								new: un puntero al nodo que añadir al principio
// 								de la lista.

// Valor devuelto			:	Nada

// Funciones autorizadas	:	Ninguna

// Descripción 				:	Añade el nodo ’new’ al principio de la lista 
// 								’lst’.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
}
