/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:35:30 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:55:47 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (*(s + i))
	{
		*(ptr + i) = *((char *)s + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

int	ftt_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (-1);
		s++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = (ft_strlen(s + start));
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[len] = '\0';
	return (s2);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	i;

	dest2 = (char *)dest;
	src2 = (char *)src;
	i = -1;
	if (!dest && !src)
		return (NULL);
	if (dest2 > src2)
		while ((int)(--n) >= 0)
			dest2[n] = src2[n];
	else
		while (++i < n)
			dest2[i] = src2[i];
	return (dest);
}
