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
