/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:06:50 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/25 12:01:49 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    ft_atoi_test(const char *str)
{
    char *test_str1 = "   ---+--+1234ab567";
    char *test_str2 = "1234";
    char *test_str3 = "   -42";
    char *test_str4 = "0";
    char *test_str5 = "+2147483647";

    printf("Input: '%s' -> Output: %d\n", test_str1, ft_atoi(test_str1));
    printf("Input: '%s' -> Output: %d\n", test_str2, ft_atoi(test_str2));
    printf("Input: '%s' -> Output: %d\n", test_str3, ft_atoi(test_str3));
    printf("Input: '%s' -> Output: %d\n", test_str4, ft_atoi(test_str4));
    printf("Input: '%s' -> Output: %d\n", test_str5, ft_atoi(test_str5));
}
void ft_bzero_test(void)
{
    char buffer[20] = "Hello, World!";
    size_t n = 6;

    printf("before: '%s'\n", buffer);
    ft_bzero(buffer, n);
    printf("after: '", n);
    for (size_t i = 0; i < sizeof(buffer); i++)
    {
        if (buffer[i] == '\0')
            printf("\\0");
        else
            printf("%c", buffer[i]);
    }
    printf("'\n");
}

int main(void)
{
    ft_atoi_test();
    ft_bzero_test();
    
    return (0);
}
