#include <unistd.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return res;
}

void	ft_puthex(unsigned int n)
{
	char *hex = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16);
	write(1, &hex[n % 16], 1);
}

int	main(int argc, char **argv)
{
	unsigned int n;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}

	n = (unsigned int)ft_atoi(argv[1]);
	ft_puthex(n);
	write(1, "\n", 1);
	return 0;
}
