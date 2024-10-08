/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:28:54 by malema            #+#    #+#             */
/*   Updated: 2023/02/28 20:08:19 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_beforenl(char *temp)
{
	int		i;
	char	*str;

	i = 0;
	while (temp[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	free(temp);
	return (str);
}

char	*ft_afternl(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		return (ft_strdup(""));
	i++;
	str = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	while (temp[i] != '\0')
	{
		str[j] = temp[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*read_chars(char *line, int fd)
{
	char		*readchars;
	int			count;

	readchars = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	count = 1;
	while (count != 0)
	{
		if (line && ft_strchr(line, '\n'))
			break ;
		count = read(fd, readchars, BUFFER_SIZE);
		if (count == 0 || count == -1)
		{
			free(readchars);
			if (!line || line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		readchars[count] = '\0';
		line = ft_strjoin(line, readchars);
	}
	free (readchars);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (temp[fd])
	{
		line = ft_strjoin(line, temp[fd]);
		free(temp[fd]);
		temp[fd] = NULL;
	}
	line = read_chars(line, fd);
	if (line && ft_strchr(line, '\n'))
	{
		temp[fd] = ft_afternl(line);
		line = ft_beforenl(line);
	}
	return (line);
}
