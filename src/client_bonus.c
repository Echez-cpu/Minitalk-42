/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:53:49 by pokpalae          #+#    #+#             */
/*   Updated: 2024/04/22 17:39:36 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static void	signl_confirm(int signl)
{
	if (signl == SIGUSR1)
		ft_printf("Message received\n");
	else
		ft_printf("signal received from pat (server_bonus)\n");
}

void	publish_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

static int	return_if_error(char *str)
{
	pid_t	n;

	n = ft_atoi(str);
	if ((n <= 0))
	{
		ft_printf("Error: Invalid PID\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (0);
	}
	else
	{
		return (n);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc == 3)
	{
		pid = return_if_error(argv[1]);
		if (pid <= 0)
			return (1);
		message = argv[2];
		while (*message != '\0')
		{
			signal(SIGUSR1, signl_confirm);
			signal(SIGUSR2, signl_confirm);
			publish_bits(pid, *message);
			message++;
		}
		publish_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
