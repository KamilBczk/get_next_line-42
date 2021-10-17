/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:51:27 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/10/16 19:27:41 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(char *buf, char *memory, char **finalstr)
{
	int	i;
	int	endlflag;
    char *temp;
    char test[2];

	i = 0;
	endlflag = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
        test[0] = buf[i];
        test[1] = '\0';
        temp = *finalstr;
		*finalstr = ft_strjoin(*finalstr, test);
        free(temp);
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

char	*freeall(char *buf, char *finalstr)
{
	free(buf);
	free(finalstr);
	return (NULL);
}


char	*get_next_line(int fd)
{
	int			c;
	char		*buff;
	static char	memory[BUFFER_SIZE] = {0};
    char        *finalstr;
	char		n[2];
	char 		*temp;
	
    finalstr = malloc(sizeof(char) * (1));
    finalstr[0] = '\0';
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	c = -1;
	if (fd < 0 || fd > FOPEN_MAX || (read(fd, NULL, 0) < 0) || BUFFER_SIZE < 1)
		return (freeall(buff, finalstr));
	while (c != 0)
	{
		if (memory[0] != '\0')
			if (new_line(memory, memory, &finalstr) == -1)
				break ;
		c = read(fd, buff, BUFFER_SIZE);
		buff[c] = '\0';
		if (new_line(buff, memory, &finalstr) == -1)
			break ;
	}
	n[0] = '\n';
	if (c == 0)
		n[0] = '\0';
	n[1] = '\0';
	temp = finalstr;
    finalstr = ft_strjoin(finalstr, n);
	free(temp);
	free(buff);
	if(finalstr[0] == '\0')
	{
		free(finalstr);
		return (NULL);
	}
	return finalstr;
}