/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:55:16 by pokpalae          #+#    #+#             */
/*   Updated: 2024/04/17 16:01:01 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signl_handler(int signl)
{
	static int	bit;
	static int	i;

	if (signl == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server\n");
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("waiting for a message....\n");
	while (argc == 1)
	{
		signal(SIGUSR1, signl_handler);
		signal(SIGUSR2, signl_handler);
		pause();
	}
	return (0);
}
