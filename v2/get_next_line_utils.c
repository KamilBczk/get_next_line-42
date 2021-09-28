/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:37:35 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/09/27 22:02:40 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*pa;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	pa = malloc(sizeof(char) * i + 1);
	if (pa == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		pa[i] = s1[i];
		i++;
	}
	pa[i] = '\0';
	return (pa);
}