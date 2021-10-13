/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:28 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/10/13 21:59:32 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 3

int		new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		printf("%c", buf[i]);
		i++;
	}
	
	if (buf[i] == '\n' && buf[i + 1] != '\0')
		printf("%s", buf + i + 1);
	if (buf[i] == '\n')
		return (-1);
	return (0);
}

char    *get_next_line(int fd) {
	int         c;
	char		*buff;
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // buff
	c = -1; // to enter in the while
	if (fd == -1 || !buff) // if file doesn't exist or creation of malloc are false
		return (NULL);
	while (c != 0)
	{
		c = read(fd, buff, BUFFER_SIZE);
		buff[c] = '\0';
		if (new_line(buff) == -1)
			return NULL;
	}
	return (0);
}

























int main_open_file(char *c)
{
	int fd;

	fd = open(c, O_RDONLY);
	return (fd);
}

int main(void)
{
	int	i;
	int nbOfTimes;

	i = 0;
	nbOfTimes = 6;
	int	fd = main_open_file("testfile");
	while (i != nbOfTimes)
	{
		printf("\n===== Appel n°: %d ==========\n", i + 1);
		get_next_line(fd);
		i++;
	}
	close(fd);
}