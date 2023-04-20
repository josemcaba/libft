/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:22:57 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/18 14:15:12 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_bzero() function writes n zeroed bytes to the string s. If n is zero, 
// ft_bzero() does nothing.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i++;
	}
}
