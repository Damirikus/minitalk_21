#include "minitalk.h"


int main(int argc, char **argv)
{
	int pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 1)
    		ft_dist(argv[2], pid);
		else
			ft_putstr_fd("server not found\n", 2);
	}
	else
		printf("./client [PID] [messege]\n");
	return (0);
}

//PID > 1	Сигнал посылается процессу с соответствующим PID.
//PID == 0	Сигнал посылается всем процессам из той же группы что и процесс-источник.
//PID < 0	Сигнал посылается всем процессам, чей идентификатор группы равен абсолютному значению PID.
//PID == 1	Сигнал посылается всем процессам системы.

void ft_dist(char *str, int pid)
{
    int i;
    i = 0;
	while (str[i])
	{
		ft_binary(pid, str[i]);
		i++;
	}
	ft_binary(pid, '\n');

}



int ft_binary(int pid, char c)
{
	int t;
	t = 128;

	while (t >= 1)
	{
		if (c & t)  //сравнивает двоичный код числа t и двоичный код символа
		{
            G_SIGNAL = SIGUSR1;
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error", 2);
				exit(1);
			}
          
		}
		else
		{
            G_SIGNAL = SIGUSR2;
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error", 2);
				exit(1);
			}
		}
        signal(SIGUSR1, ft_cheker);
        signal(SIGUSR2, ft_cheker);
        usleep(2);
        if(G_SIGNAL)
            t /= 2;
        else
        {
            if (kill(pid, 0) == -1)
            {
				ft_putstr_fd("Error", 2);
				exit(1);
			}
            ft_putstr_fd("Error", 2);
				// exit(1);
            // printf("lomaetsya");
        }
		usleep(20);
	}
	return 0;
}


void ft_cheker(int sig)
{
    if (sig == G_SIGNAL)
       G_SIGNAL = 1;
    else
        G_SIGNAL = 0;

}