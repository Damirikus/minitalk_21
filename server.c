#include "minitalk.h"

void signal_handlers(int signal)    // делаем статические переменные, так как все в бесконечном цикле
{
	static int i = 0;
	static int count = 128;
	static wchar_t out_char = 0;   //символ, который будет собирать все числа из бинарных чисел

	if (signal == SIGUSR1)
	{
		out_char += count;
		count /= 2;
		i++;
	}
	if (signal == SIGUSR2)
	{
		count /= 2;
		i++;
	}
	if (i == 8) //если собирается байт, все обнуляется
	{
		write(1, &out_char, 1);
		i = 0;
		count = 128;
		out_char = 0;
	}
}


int main()
{
//	sigset_t newset;
//	sigemptyset(&newset);

	ft_putnbr_fd(getpid(), 1);       //Печатаем номер процесса
	write(1, "\n", 1);

	while (1) {    //Запускаем бесконечный цикл для сервера и делаем так, что он принимает только 2 сигнала

		signal(SIGUSR1, signal_handlers);
		signal(SIGUSR2, signal_handlers);
	}
}