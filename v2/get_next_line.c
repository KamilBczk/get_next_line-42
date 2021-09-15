/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:48:28 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/09/15 23:42:42 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE 1

// int	get_next_index(int index, int fd)
// {
// 	printf("\n");
// 	int		c;
// 	int		i;
// 	int		return_index;
// 	char	buf[BUFF_SIZE + 1];

// 	c = 1;
// 	while (c != 0)
// 	{
// 		c = read(fd, buf, BUFF_SIZE);
// 		buf[c] = '\0';
// 		printf("%s", buf);
// 	}
// 	return(0);
// }

// char	*create_malloc(int index, int fd)
// {
// 	int	len;

// 	len = get_next_index(index, fd);
// 	printf("\n%d\t", len);
// 	return (0);
// }

int get_line_index(int line, int fd, char *buf)
{
	int			i;
	static int	index = 0;
	static int	current_line = 0;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			if (buf[i] == '\0' && current_line == line)
				return (-2);
			if (current_line == line)
				return (index);
			else
				index = 0;
			current_line++;
		}
		i++;
		index++;
	}
	return (-1);
}

void	get_bus(int line, int fd)
{
	int		c;
	int		line_index;
	char	*buf;
	
	c = 1;
	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (c != 0)
	{
		c = read(fd, buf, BUFF_SIZE);
		buf[c] = '\0';
		line_index = get_line_index(line, fd, buf);
		if ((line_index != -1) || (line_index != 0))
			{printf("%d", line_index);}
	}
	
}

char    *get_next_line(int fd)
{
	static int	lineToRead = 0;
	static int	lineIndex = 0;

	if (fd == -1)
		return (NULL);
	printf("\nAppel numéro : %d #####\n", lineToRead);
	get_bus(lineToRead, fd);
	printf("\n######### %d ##########\n\n", lineIndex);
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
	nbOfTimes = 5;
	while (i != nbOfTimes)
	{
		int	fd = main_open_file("testfile");
		get_next_line(fd);
		close(fd);
		i++;
	}
}