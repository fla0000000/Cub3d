/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:16:25 by fbiondo           #+#    #+#             */
/*   Updated: 2023/03/03 14:17:45 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *backup, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!backup)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	if (!backup || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (backup)
		while (backup[++i] != '\0')
			str[i] = backup[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(backup) + ft_strlen(buff)] = '\0';
	free(backup);
	return (str);
}
