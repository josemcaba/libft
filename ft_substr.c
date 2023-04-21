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
	size_t	s_len;
	char	*ptr;
	size_t	i;

	s_len = ft_strlen(s);
	if (start > s_len)
		s_len = 0;
	else
		s_len = s_len - start;
	if (len < s_len)
		s_len = len;
	ptr = (char *)malloc(s_len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while ((i < s_len) && *(s + start + i))
	{
		*(ptr + i) = *(s + start + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
