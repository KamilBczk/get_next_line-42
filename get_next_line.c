/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:38:54 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/09/08 14:05:34 by kamilbiczyk      ###   ########.fr       */
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
char *get_next_line(int fd)
{
    char    c;
    char    *buf;

    buf = malloc(BUFF_SIZE + 1);
    if (!buf)
        return (NULL);
    c = read(fd, buf, BUFF_SIZE);
    printf("%d", c);
    return (0);
}

int main(void)
{
    int fd;
    
    fd = open("testfile", O_RDONLY);
    printf("%s", get_next_line(fd));
}