/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:43:09 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 13:41:18 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Elimina todos los caracteres de la string 'set' desde el principio y desde
// el final de 's1', hasta encontrar un caracter no perteneciente a 'set'. La
// string resultante se devuelve con una reserva de malloc(3).

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*strtrimmed;

	len = ft_strlen(s1);
	if (len > 0)
		end = len - 1;
	else
		end = 0;
	start = 0;
	while ((start < len) && ft_strchr(set, s1[start]))
		start++;
	while ((end > start) && ft_strchr(set, s1[end]))
		end--;
	strtrimmed = (char *)malloc((end - start + 2) * sizeof(char));
	if (!strtrimmed)
		return (NULL);
	ft_strlcpy(strtrimmed, s1 + start, end - start + 2);
	return (strtrimmed);
}
