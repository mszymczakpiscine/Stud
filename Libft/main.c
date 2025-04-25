/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:06:50 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/25 12:33:51 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    add_one(unsigned int i, char c)
{
    (void)i;
    return (c + 1);
}

int    main(void)
{
    char    *str;
    char    **split;
    int        i;
    char    dest1[20] = "Hello";
    char    dest2[20] = "Ha";
    char    dest3[20] = "Oh";
    char    *s;

    printf("==== Partie 1 ====\n");
    printf("ft_isalpha('A') : %d\n", ft_isalpha('A'));
    printf("ft_isdigit('4') : %d\n", ft_isdigit('4'));
    printf("ft_isalnum('3') : %d\n", ft_isalnum('3'));
    printf("ft_isascii(127) : %d\n", ft_isascii(127));
    printf("ft_isprint(' ') : %d\n", ft_isprint(' '));
    printf("ft_strlen(\"42\") : %zu\n", ft_strlen("42"));
    printf("ft_memcpy : %s\n", (char *)ft_memcpy(dest1, " World!", 7));
    printf("ft_strlcpy : %zu\n", ft_strlcpy(dest2, "Salut", 20));
    printf("ft_strlcat : %zu\n", ft_strlcat(dest3, " Bro", 20));
    printf("ft_toupper('a') : %d\n", ft_toupper('a'));
    printf("ft_tolower('Z') : %d\n", ft_tolower('Z'));
    printf("ft_strchr(\"Hello\", 'l') : %s\n", ft_strchr("Hello", 'l'));
    printf("ft_strrchr(\"Hello\", 'l') : %s\n", ft_strrchr("Hello", 'l'));
    printf("ft_strncmp(\"abc\", \"abd\", 2) : %d\n", ft_strncmp("abc", "abd", 2));
    printf("ft_memchr(\"bonjour\", 'j', 7) : %s\n", (char *)ft_memchr("bonjour", 'j', 7));
    printf("ft_memcmp(\"abc\", \"abd\", 2) : %d\n", ft_memcmp("abc", "abd", 2));
    s = ft_strdup("test");
    printf("ft_strdup : %s\n", s);
    free(s);
    printf("\n==== Partie 2 ====\n");
    printf("ft_atoi(\"42\") : %d\n", ft_atoi("42"));
    str = ft_substr("Hello World", 6, 5);
    printf("ft_substr : %s\n", str);
    free(str);
    str = ft_strjoin("Hello", "42");
    printf("ft_strjoin : %s\n", str);
    free(str);
    str = ft_strtrim("  42  ", " ");
    printf("ft_strtrim : %s\n", str);
    free(str);
    split = ft_split("Hello World From 42", ' ');
    i = 0;
    while (split && split[i])
    {
        printf("ft_split[%d] : %s\n", i, split[i]);
        free(split[i]);
        i++;
    }
    free(split);
    str = ft_itoa(12345);
    printf("ft_itoa : %s\n", str);
    free(str);
    str = ft_strmapi("abc", &add_one);
    printf("ft_strmapi : %s\n", str);
    free(str);

    printf("\n==== Partie 3 ====\n");
    ft_putstr_fd("ft_putstr_fd: Hello 42\n", 1);
    ft_putchar_fd('\n', 1);
    ft_putendl_fd("ft_putendl_fd: End line", 1);
    ft_putnbr_fd(4242, 1);
    ft_putchar_fd('\n', 1);

    printf("\n==== Partie BONUS ====\n");

    t_list    *head;
    t_list    *second;
    t_list    *third;
    //t_list    *map_result;
    t_list    *tmp;

    head = ft_lstnew("Hello");
    second = ft_lstnew("World");
    third = ft_lstnew("42");
    head->next = second;
    second->next = third;

    printf("ft_lstsize : %d\n", ft_lstsize(head));
    printf("ft_lstlast : %s\n", (char *)ft_lstlast(head)->content);

    ft_lstadd_front(&head, ft_lstnew("Start"));
    printf("After ft_lstadd_front : %s\n", (char *)head->content);

    ft_lstadd_back(&head, ft_lstnew("End"));
    printf("After ft_lstadd_back (last) : %s\n", (char *)ft_lstlast(head)->content);

    printf("Use ft_lstiter to print list:\n");
    tmp = head;
    while (tmp)
    {
        printf("- %s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
}
