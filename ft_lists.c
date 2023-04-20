/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:53:09 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 13:03:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Nombre de función		:	ft_lstnew
// Prototipo				:	t_list *ft_lstnew(void *content);
// Parámetros				:	content: el contenido con el que crear el nodo.
// Valor devuelto			:	El nuevo nodo
// Funciones autorizadas	:	malloc
// Descripción				:	Crea un nuevo nodo utilizando malloc(3). La 
// 								variable miembro ’content’ se inicializa con el
// 								contenido del parámetro ’content’. La variable
// 								’next’, con NULL.

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

// Nombre de función		:	ft_lstsize
// Prototipo				:	int ft_lstsize(t_list *lst);
// Parámetros				:	lst: el principio de la lista.
// Valor devuelto			:	La longitud de la lista
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Cuenta el número de nodos de una lista.

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*node;

	len = 1;
	node = lst;
	while (node->next)
	{
		len++;
		node = node->next;
	}
	return (len);
}

// Nombre de función		:	ft_lstlast
// Prototipo				:	t_list *ft_lstlast(t_list *lst);
// Parámetros				:	lst: el principio de la lista.
// Valor devuelto			:	El último nodo de la lista
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Devuelve el último nodo de la lista.

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}

// Nombre de función		:	ft_lstadd_back
// Prototipo				:	void ft_lstadd_back(t_list **lst, t_list *new);
// Parámetros				:	lst: el puntero al primer nodo de una lista.
//								new: el puntero a un nodo que añadir a la lista.
// Valor devuelto			:	Nada
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Añade el nodo ’new’ al final de la lista ’lst’.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	node->next = new;
}

// Nombre de función		:	ft_lstdelone
// Prototipo				:	void ft_lstdelone(t_list *lst, 
// 												  void (*del)(void *));
// Parámetros				:	lst: el nodo a liberar.
//								del: un puntero a la función utilizada para 
//								liberar el contenido del nodo.
// Valor devuelto			:	Nada
// Funciones autorizadas	:	free
// Descripción 				:	Toma como parámetro un nodo ’lst’ y libera la
// 								memoria del contenido utilizando la función 
// 								’del’ dada como parámetro, además de liberar el 
// 								nodo. La memoria de ’next’ no debe liberarse.

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// Programa de pruebas

void	delete(void *content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node0 = ft_lstnew("42");
	node1 = ft_lstnew("Malaga");
	node2 = ft_lstnew("Hello, ");
	node3 = ft_lstnew(". Welcome!");
	ft_lstadd_front(&node1, node0);
	ft_lstadd_front(&node0, node2);
	printf("%s%s%s\n", (char *)node2->content, \
						(char *)node0->content, (char *)node1->content);
	printf("%d\n", ft_lstsize(node2));
	printf("%s\n", (char *)ft_lstlast(node2)->content);
	ft_lstadd_back(&node2, node3);
	printf("%d\n", ft_lstsize(node2));
	printf("%s\n", (char *)ft_lstlast(node2)->content);
	ft_lstdelone(node3, delete);
	free(node0);
	free(node1);
	free(node2);
	return (0);
}
