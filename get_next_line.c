/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:28:54 by malema            #+#    #+#             */
/*   Updated: 2023/02/17 21:15:43 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_beforenl(char *temp)
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
	while (temp[i] != '\n')
		i++;
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

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*readchars;
	int			count;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	readchars = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	count = 1;
	if (temp)
	{
		line = ft_strjoin(line, temp);
		free(temp);
	}
	while (count != 0)
	{
		if (line && ft_strchr(line, '\n'))
		{
			temp = ft_afternl(line);
			line = ft_beforenl(line);
			break ;
		}
		count = read(fd, readchars, BUFFER_SIZE);
		if (count == 0)
		{
			if (line)
				return (line);
			return(NULL);
		}
		if (count == -1)
		{	
			free(readchars);
			return (NULL);
		}
		readchars[count] = '\0';
		line = ft_strjoin(line, readchars);
	}
	free(readchars);
	return (line);
}
