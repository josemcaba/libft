/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:10:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 13:10:23 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strchr() function locates the first occurrence of c (converted to a
// char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is `\0', the func-
// tions locate the terminating `\0'.

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != c))
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}