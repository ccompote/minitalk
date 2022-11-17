/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:37:25 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/17 19:18:54 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "f.h"

void pc(int c)
{
	write(1, &c, 1);
}
void func(int var)
{
	static t_var *gl;
	
	if (!gl){
		gl = malloc(sizeof(t_var));
		gl->count = 0;
		gl->bits = 0;}
	
	gl->count += 1;
	gl->bits = gl->bits << 1;
	gl->bits |= var;
	
	if (gl->count == 8)
	{
		pc(gl->bits);
		gl->bits = 0;
		gl->count = 0;
	}
}
void func1(int process)
{
	// printf("func1\n");
	func(1);
}
void func2(int process)
{
	// printf("func2\n");
	func(0);
}
int main(void)
{
	int x;

	x = getpid();
	printf("%d\n", x);
	while(1)
	{
		signal(SIGUSR1, func1);
		signal(SIGUSR2, func2);
	}
	return(0);
}