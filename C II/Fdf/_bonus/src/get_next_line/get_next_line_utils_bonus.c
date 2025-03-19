/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:46 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/12 00:28:07 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	tmp;

	if (!s)
		return (NULL);
	tmp = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == tmp)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == tmp)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*new;

	if (!src)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, s1_len);
	ft_memcpy(&new[s1_len], s2, s2_len);
	new[s1_len + s2_len] = '\0';
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	if (src == NULL && dest == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
