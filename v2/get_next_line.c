/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:48:28 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/09/28 21:56:28 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 2000

int	get_line_index(char *buf, int fd, int line, int resetstatic)
{
	int	i;
	static int	current_line = 0;
	static int	index = 0;
	
	if (resetstatic == 1)
	{
		index = 0;
		current_line = 0;
		return (0);
	}
	i = 0;
	while (i < BUFF_SIZE)
	{
		if (buf[i] == '\0')
			return(-1);
		if (line == current_line)
			return (index);
		if (buf[i] == '\n')
			current_line++;
		index++;
		i++;
	}
	return (-1);
}

void	get_bus(int line, int fd)
{
	int		c;
	int		line_index;
	char	buf[BUFF_SIZE + 1];
	
	c = 1;
	get_line_index(NULL, 0, 0, 1);
	while (c != 0)
	{
		c = read(fd, buf, BUFF_SIZE);
		buf[c] = '\0';
		line_index = get_line_index(buf, fd, line, 0);
		if (line_index != -1)
		{
			printf("%d\n", line_index);
			return ;
		}
	}
}

char    *get_next_line(int fd)
{
	static int	lineToRead = 0;
	static int	lineIndex = 0;

	if (fd == -1)
		return (NULL);
	get_bus(lineToRead, fd);
	lineToRead++;
	return (0);
}

/**
 * 
 ** ##### MAIN #####
 *
 */

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
	nbOfTimes = 1000;
	while (i != nbOfTimes)
	{
		int	fd = main_open_file("testfile");
		get_next_line(fd);
		close(fd);
		i++;
	}
}