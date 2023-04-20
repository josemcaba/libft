/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:50:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 12:51:14 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reserva (con malloc(3) y devuelve una nueva string,
// formada por la concatenación de 's1' y 's2'.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoined;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	strjoined = (char *)malloc(len * sizeof(char) + 1);
	if (!strjoined)
		return (NULL);
	ft_strlcpy(strjoined, s1, len);
	ft_strlcat(strjoined, s2, len);
	return (strjoined);
}
