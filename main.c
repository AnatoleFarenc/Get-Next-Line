/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:42:49 by anfarenc          #+#    #+#             */
/*   Updated: 2025/11/19 18:28:42 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;
	int i = 0;
	char *res;


	fd = open("tt.txt", O_RDONLY);

	// printf("fd : %d\n", fd);
	
	while ((res = get_next_line(fd)))
	{
		printf("call %d : %s",i, res);
		free(res);
		i++;
	}
	free(res);
	close(fd);
	return (0);
}
