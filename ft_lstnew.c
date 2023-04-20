/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:17:31 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 13:20:04 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Nombre de función     : ft_lstnew
// Prototipo             : t_list *ft_lstnew(void *content);
// Parámetros            : content: el contenido con el que crear el nodo.
// Valor devuelto        : El nuevo nodo
// Funciones autorizadas : malloc
// Descripción           : Crea un nuevo nodo utilizando malloc(3). La
//                         variable miembro ’content’ se inicializa con el
//                         contenido del parámetro ’content’. La variable
//                         ’next’, con NULL.

t_list  *ft_lstnew(void *content)
{
        t_list  *node;

        node = (t_list *)malloc(sizeof(t_list));
        if (!node)
                return (NULL);
        node->content = content;
        node->next = NULL;
        return (node);
}
