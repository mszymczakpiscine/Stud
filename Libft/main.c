/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:37:22 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/24 15:48:18 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int	main()
{
	// is fonctions
	printf("ft_isalnum('6') = %d\n", ft_isalnum('6'));
	printf("ft_isalpha('B') = %d\n", ft_isalpha('B'));
	printf("ft_isascii('127') = %d\n", ft_isascii('127'));
	printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
	printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
	
	//strlen
	printf("ft_strlen(\"Hello\") = %zu\n", ft_strlen("Hello"));
	
	//memset
	charbuf1[10] = "abcdef"
}
