/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:45:38 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 12:45:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	if (s2_len > n)
		return (0);
	i = 0;
	while ((i <= (n - s2_len)) && s1[i])
	{
		j = 0;
		while ((s1[i + j] == s2[j]) && s2[j])
			j++;
		if (j == s2_len)
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
