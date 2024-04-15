/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:46:46 by pokpalae          #+#    #+#             */
/*   Updated: 2024/04/15 14:54:08 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

int	return_if_error(char *str)
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
