#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putnbr(int n)
{
        unsigned int nb;
        if (n < 0)
        {
                ft_putchar('-');
                nb = -n;
        }
        else
                nb = n;
        if (nb >= 10)
                ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
}


int     is_prime(int nbr)
{
        if (nbr < 2)
                return 0;
        int i = 2;
        while (i <= nbr / 2)
        {
                if (nbr % i == 0)
                        return 0;
                i++;
        }
        return 1;
}

int     ft_atoi(char *str)
{
        int i = 0;
        int result = 0;
        int sign = 1;
        while (str[i] == ' ')
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        sign = -1;
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9' && str[i])
        {
                result = result * 10 + (str[i] - 48);
                i++;
        }
        return (sign * result);
}

int     main(int argc, char **argv)
{
        if (argc != 2 || ft_atoi(argv[1]) <= 0)
        {
                write(1, "0\n", 2);
                return 0;
        }
        int n = ft_atoi(argv[1]);
        int sum = 0;
        while (n > 1)
        {
                if (is_prime(n))
                        sum += n;
                n--;
        }
        ft_putnbr(sum);
        ft_putchar('\n');
}
