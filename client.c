/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:15:10 by qxia              #+#    #+#             */
/*   Updated: 2022/02/10 16:50:40 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Décimal en binaire
static char	*ft_bina(char c)
{
	char	*bina;
	int		i;

	i = 7;
	bina = malloc(sizeof(char) * 9);
	if (!bina)
		return (NULL);
	while (i >= 0 && c >= 0)
	{
		if (c % 2 == 0)
			bina[i] = '0';
		else if (c % 2 == 1)
			bina[i] = '1';
		c = c / 2;
		i--;
	}
	bina[8] = '\0';
	return (bina);
}

//define SIGUSR1 SIGUSR2
static void	sig_bina(char c, int pid)
{
	int		i;
	char	*s;

	i = 7;
	s = ft_bina(c);
	while (i >= 0)
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else if (s[i] == '0')
			kill(pid, SIGUSR2);
		i--;
		usleep (5000);
	}
	free (s);
}

//send signal
static void	send_sig(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		sig_bina(s[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	if (pid <= 0)
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	send_sig(argv[2], pid);
	return (0);
}
