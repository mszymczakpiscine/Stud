int    ft_atoi_base(const char *str, int base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int digit;

    if (base < 2 || base > 16)
        return (0);

    // Gestion du signe uniquement s'il est en premier caractère
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            digit = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            digit = str[i] - 'A' + 10;
        else
            break; // caractère non valide, on arrête

        if (digit >= base)
            break; // chiffre hors base, on arrête

        result = result * base + digit;
        i++;
    }

    return (result * sign);
}

int	main(void)
{
	printf("Hex FF = %d\n", ft_atoi_base("FF", 16));         // 255
	printf("Bin 1010 = %d\n", ft_atoi_base("1010", 2));      // 10
	printf("Dec -42 = %d\n", ft_atoi_base("-42", 10));       // -42
	printf("Base 8 '77' = %d\n", ft_atoi_base("77", 8));     // 63
	printf("Invalid '1G' = %d\n", ft_atoi_base("1G", 16));   // 1
	return (0);
}
