/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:20:14 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/21 20:20:12 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parámetros				:	lst: el principio de la lista.
// Valor devuelto			:	La longitud de la lista
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Cuenta el número de nodos de una lista.

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*node;

	if (lst == NULL)
		return (0);
	len = 1;
	node = lst;
	while (node->next)
	{
		len++;
		node = node->next;
	}
	return (len);
}
