#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>


int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	// int		fd4;
	char	*line;
	char	*line2;
	char	*line3;
	// char	*line4;


	fd1 = open("aalice.txt", O_RDONLY);
	// fd2 = open("aalice.txt", O_RDONLY);
	// fd3 = open("aalice.txt", O_RDONLY);
	// line = get_next_line(fd1);
	// printf("%s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("%s", line);
	// free(line);

	// line = get_next_line(fd1);
	// printf("%s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("%s", line);
	// free(line);

	// fd2 = open("balice.txt", O_RDONLY);
	// fd3 = open("calice.txt", O_RDONLY);
	// fd4 = open("dalice.txt", O_RDONLY);

	// while (1)
	// {
		line = get_next_line(fd1);
		// line2 = get_next_line(fd2);
		// line3 = get_next_line(fd3);
		// line4 = get_next_line(fd4);
		// if (!line)
		// 	break ;
		printf("fd1: %s", line);
		// printf("fd2: %s", line2);
		// printf("fd3: %s", line3);
		// printf("%s", line4);
		free(line);
		// free(line2);
		// free(line3);
		// free(line4);
	// }

	return (0);
}


