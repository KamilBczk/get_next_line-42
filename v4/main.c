/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:28 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/10/15 00:43:18 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 12

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	new_line(char *buf, char *memory)
{
	int	i;
	int	endlflag;

	i = 0;
	endlflag = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		printf("%c", buf[i]);
		i++;
	}
	if (buf[i] == '\n')
		endlflag = -1;
	if (buf[i] == '\n' && buf[i + 1] != '\0')
		ft_strcpy(memory, buf + i + 1);
	else
		memory[0] = '\0';
	return (endlflag);
}

char	*get_next_line(int fd)
{
	int			c;
	char		*buff;
	static char	memory[BUFFER_SIZE] = {0};

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	c = -1;
	if (fd == -1 || !buff)
		return (NULL);
	while (c != 0)
	{
		if (memory[0] != '\0')
			if (new_line(memory, memory) == -1)
				break ;
		c = read(fd, buff, BUFFER_SIZE);
		buff[c] = '\0';
		if (new_line(buff, memory) == -1)
			break ;
	}
	return (0);
}

int	main_open_file(char *c)
{
	int	fd;

	fd = open(c, O_RDONLY);
	return (fd);
}

int	main(void)
{
	int	i;
	int	nboftimes;
	int	fd;

	i = 0;
	nboftimes = 70;
	fd = main_open_file("testfile");
	while (i != nboftimes)
	{
		printf("\n===== Appel n°: %d ==========\n", i + 1);
		get_next_line(fd);
		i++;
	}
	close(fd);
}
