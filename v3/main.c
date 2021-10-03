/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:33:13 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/10/02 16:42:12 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 10

int	parse_buf(char *buf, int *c_line, int l_read)
{
	static int	nb;

	while (*buf)
	{
		if (*buf == '\n')
		{
			if (*c_line == l_read)
			{
				if (l_read == 0)
					printf("|%d|\n", nb + 1);
				else
					printf("|%d|\n", nb);
			}
			*c_line += 1;
			nb = 0;
		}
		nb++;
		buf++;
	}
}

int	read_line(int fd, int l_read)
{
	int	c;
	char buf[BUFF_SIZE + 1];
	int	c_line;

	c_line = 0;
	c = 1;
	while (c != 0)
	{
		c = read(fd, buf, BUFF_SIZE);
		buf[c] = '\0';
		parse_buf(buf, &c_line, l_read);
	}
	return (0);
}

char    *get_next_line(int fd)
{
	static int  l_read; // line to read

	if (fd == -1)
		return (0);
	printf("----\n");
	read_line(fd, l_read);
	printf("----");
	l_read++;
	printf("\n");
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
	while (i != nbOfTimes)
	{
		int	fd = main_open_file("testfile");
		get_next_line(fd);
		close(fd);
		i++;
	}
}