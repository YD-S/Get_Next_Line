/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:03:17 by ysingh            #+#    #+#             */
/*   Updated: 2022/10/29 15:09:23 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_buffer(char *buff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	str = (char *)ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	free(buff);
	return (str);
}

static char	*ft_line(char *temp)
{
	int		j;
	char	*str;

	j = 0;
	if (!temp[j])
		return (NULL);
	while (temp[j] && temp[j] != '\n')
		j++;
	str = (char *)ft_calloc((j + 2), sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (temp[j] && temp[j] != '\n')
	{
		str[j] = temp[j];
		j++;
	}
	if (temp[j] == '\n')
	{
		str[j] = temp[j];
		j++;
	}
	return (str);
}

static char	*ft_read(int fd, char *buff)
{
	char	*temp;
	int		n;

	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (NULL);
	n = 1;
	while (!(ft_strchr(buff, '\n')) && n != 0)
	{
		n = read(fd, temp, BUFFER_SIZE);
		if (n == -1)
		{
			if (buff != NULL)
				free(buff);
			return (free(temp), NULL);
		}
		temp[n] = '\0';
		buff = ft_strjoin(buff, temp);
	}
	free(temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = ft_read(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_line(buff[fd]);
	buff[fd] = ft_buffer(buff[fd]);
	return (line);
}
