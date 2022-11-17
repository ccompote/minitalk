/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:36:56 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/17 19:18:12 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include<signal.h>
#include <stdio.h>
#include <unistd.h>
#include "f.h"
void pc(int c)
{
	write(1, &c, 1);
}
void send_signal(int pid, char *str)
{
	int c;
	int i;
	int	j;

	i = 0;
	while (str[i])
	{
		c = (int)str[i];
		j = 7;
		while (j >= 0)
		{
			if (c >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			j--;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("sasiruy\n");
		return(0);
	}
	int id = atoi(argv[1]);
	send_signal(id, argv[2]);
}