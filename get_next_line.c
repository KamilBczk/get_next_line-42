/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:38:54 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/09/14 23:49:56 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

/*
** This function appends a single line into our line variable. We do this by
** finding the length of the line. If at index len, the character is a newline,
** we save the string into line up to the length found. Then we readjust the
** stored data (**s) by creating a temporary string that stored the rest of data
** after the newline. We free the stored data to update it to the current
** address because we already append a line from it. This is done by freeing *s
** and setting it equal to the temporary string that stored the remaining data.
** At any point when we reach the end of the file, we free the memory used to
** track our location in *s because it is not needed anymore.
*/

/* Return the index of each "\n" in the coresponding line */
int	get_line_index(char *buf, int index, int line, int fd, int buffsize)
{
	int	c;
	int i;
	int	current_line;

	c = 1;
	current_line = 0;
	while (c != 0)
	{
		i = 0;
		c = read(fd, buf, buffsize);
		buf[c] = '\0';
		while (i < buffsize)
		{
			if (buf[i] == '\n' || buf[i] == '\0')
			{
				/* TODO : Si il y a des 2 lignes et on apelle la fonction 4 fois il y aura des erreurs. */
				if (buf[i] == '\0' && current_line != line)
					return (0);
				if (current_line == line)
					return (index);
				else
					index = 0;
				current_line++;
			}
			i++;
			index++;
		}
	}
	return (-1);
}

char    *get_next_line(int fd)
{
	static int  x = 0;
	static int	indexline = 0;
	char    *buf;

	if (fd == -1)
		return (0);
	/* On malloc le tableau avec le BUFF_SIZE +1 */
	buf = malloc(BUFF_SIZE + 1);
	if (!buf)
		return (NULL);
	indexline += get_line_index(buf, indexline, x, fd, BUFF_SIZE);
	printf("%d\n", indexline);
	x++;
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
	get_next_line(main_open_file("testfile"));
	get_next_line(main_open_file("testfile"));
	get_next_line(main_open_file("testfile"));
	get_next_line(main_open_file("testfile"));

}