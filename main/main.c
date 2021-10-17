/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:28 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/10/17 19:54:49 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"

int	main_open_file(char *c)
{
	int	fd;

	fd = open(c, O_RDONLY);
	return (fd);
}

int	main(void)
{
	int		i;
	int		nboftimes;
	int		fd;
	char	*lol;

	i = 0;
	nboftimes = 10;
	fd = main_open_file("/Users/kamilbiczyk/Desktop/get_next_line-42/v4/gnlTester/files/big_line_with_nl");
	while (i != nboftimes)
	{
		printf("\n===== Appel n°: %d ==========\n", i + 1);
		lol = get_next_line(fd);
		printf("%s", lol);
		i++;
	}
	free(lol);
	system("leaks a.out");
	close(fd);
}
