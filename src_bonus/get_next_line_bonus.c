/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:35:13 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:55:21 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	the_line(char *str, char **line, int i)
{
	int	len;

	*line = ft_substr(str, 0, i);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

char	*ft_join_norm(char *s1, char *s2, char *join, int len1)
{
	int	i;

	i = -1;
	while (s1 [++i])
		join[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2 [++i])
		join[len1 + i] = s2[i];
	join[len1 + i] = '\0';
	return (join);
}

char	*ft_join(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*join;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (NULL);
	join = ft_join_norm(s1, s2, join, len1);
	return (join);
}

int	get_norm(int retour, char **str, char **line)
{
	if (str)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (retour);
	}
	return (retour);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*str;
	int			retour;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (str)
	{
		i = ftt_strchr(str, '\n');
		if (i != -1)
			return (the_line(str, line, i));
	}
	retour = 1;
	while (retour > 0)
	{
		retour = read(fd, buff, BUFFER_SIZE);
		buff[retour] = '\0';
		str = ft_join(str, buff);
		i = ftt_strchr(str, '\n');
		if (i != -1)
			return (the_line(str, line, i));
	}
	return (get_norm(retour, &str, line));
}
