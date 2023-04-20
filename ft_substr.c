/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:42:27 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 12:42:44 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reserva (con malloc(3)) y devuelve una substring de la string 's'.
// La substring empieza desde el indice 'start' y tiene una longitud
// máxima 'len'.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	max_len;

	max_len = ft_strlen(s) - start;
	if (len > max_len)
		len = max_len;
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while ((i < len) && *(s + start + i))
	{
		*(ptr + i) = *(s + start + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
