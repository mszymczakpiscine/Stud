/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:06:50 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/24 16:16:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_ft_isalnum(void)
{
    printf("Testing ft_isalnum:\n");
    char test_chars[] = {'A', 'z', '5', '!', ' ', '0', '9', 'a', 'Z', '@', 0};
    for (int i = 0; i < (int)(sizeof(test_chars) / sizeof(test_chars[0])); i++)
    {
        if (ft_isalnum(test_chars[i]))
            printf("'%c' is alphanumeric.\n", test_chars[i]);
        else
            printf("'%c' is NOT alphanumeric.\n", test_chars[i]);
    }
    printf("\n");
}

void test_ft_bzero(void)
{
    printf("Testing ft_bzero:\n");
    char str[10] = "abcdefghi";
    printf("Before ft_bzero: %s\n", str);
    ft_bzero(str, 5);
    printf("After ft_bzero: ");
    for (int i = 0; i < 10; i++)
    {
        if (str[i] == 0)
            printf("\\0");
        else
            printf("%c", str[i]);
    }
    printf("\n\n");
}

void test_ft_calloc(void)
{
    printf("Testing ft_calloc:\n");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Allocated memory (should be all zeros):\n");
    for (int i = 0; i < 5; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    free(arr);
    printf("\n");
}

void test_ft_strjoin(void)
{
    printf("Testing ft_strjoin:\n");
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("Result: %s\n", result);
        free(result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    printf("\n");
}

void test_ft_atoi(void)
{
    printf("Testing ft_atoi:\n");
    const char *test_cases[] = {"42", "   -42", "   +42", "   123abc", "   -123abc", "   +0", "   -0", "2147483647", "-2147483648", NULL};
    for (int i = 0; test_cases[i]; i++)
    {
        printf("Input: '%s' -> Output: %d\n", test_cases[i], ft_atoi(test_cases[i]));
    }
    printf("\n");
}

#include "libft.h"
#include <stdio.h>

void test_ft_isalpha(void)
{
    printf("Testing ft_isalpha:\n");
    char test_chars[] = {'A', 'z', '5', '!', ' ', '0', '9', 'a', 'Z', '@', 0};
    for (int i = 0; i < (int)(sizeof(test_chars) / sizeof(test_chars[0])); i++)
    {
        if (ft_isalpha(test_chars[i]))
            printf("'%c' is alphabetic.\n", test_chars[i]);
        else
            printf("'%c' is NOT alphabetic.\n", test_chars[i]);
    }
    printf("\n");
}

void test_ft_isdigit(void)
{
    printf("Testing ft_isdigit:\n");
    char test_chars[] = {'A', 'z', '5', '!', ' ', '0', '9', 'a', 'Z', '@', 0};
    for (int i = 0; i < (int)(sizeof(test_chars) / sizeof(test_chars[0])); i++)
    {
        if (ft_isdigit(test_chars[i]))
            printf("'%c' is a digit.\n", test_chars[i]);
        else
            printf("'%c' is NOT a digit.\n", test_chars[i]);
    }
    printf("\n");
}

void test_ft_isalnum(void)
{
    printf("Testing ft_isalnum:\n");
    char test_chars[] = {'A', 'z', '5', '!', ' ', '0', '9', 'a', 'Z', '@', 0};
    for (int i = 0; i < (int)(sizeof(test_chars) / sizeof(test_chars[0])); i++)
    {
        if (ft_isalnum(test_chars[i]))
            printf("'%c' is alphanumeric.\n", test_chars[i]);
        else
            printf("'%c' is NOT alphanumeric.\n", test_chars[i]);
    }
    printf("\n");
}

void test_ft_isascii(void)
{
    printf("Testing ft_isascii:\n");
    char test_chars[] = {'A', 'z', '5', '!', ' ', '0', '9', 'a', 'Z', '@', 0, -1, 128};
    for (int i = 0; i < (int)(sizeof(test_chars) / sizeof(test_chars[0])); i++)
    {
        if (ft_isascii(test_chars[i]))
            printf("'%c' (ASCII %d) is an ASCII character.\n", test_chars[i], test_chars[i]);
        else
            printf("'%c' (ASCII %d) is NOT an ASCII character.\n", test_chars[i], test_chars[i]);
    }
    printf("\n");
}

void test_ft_isprint(void)
{
    printf("Testing ft_isprint:\n");
    char test_chars[] = {'A', 'z', '5', '!', ' ', '0', '9', 'a', 'Z', '@', 0, 127};
    for (int i = 0; i < (int)(sizeof(test_chars) / sizeof(test_chars[0])); i++)
    {
        if (ft_isprint(test_chars[i]))
            printf("'%c' (ASCII %d) is printable.\n", test_chars[i], test_chars[i]);
        else
            printf("'%c' (ASCII %d) is NOT printable.\n", test_chars[i], test_chars[i]);
    }
    printf("\n");
}
void test_ft_lstnew(void)
{
    printf("Testing ft_lstnew:\n");
    t_list *node = ft_lstnew("Hello");
    if (node)
    {
        printf("Node content: %s\n", (char *)node->content);
        free(node);
    }
    else
    {
        printf("ft_lstnew failed.\n");
    }
    printf("\n");
}

void test_ft_lstadd_front(void)
{
    printf("Testing ft_lstadd_front:\n");
    t_list *head = ft_lstnew("World");
    t_list *new_node = ft_lstnew("Hello");
    ft_lstadd_front(&head, new_node);
    print_list(head);
    free(new_node);
    free(head);
    printf("\n");
}

void test_ft_lstadd_back(void)
{
    printf("Testing ft_lstadd_back:\n");
    t_list *head = ft_lstnew("Hello");
    t_list *new_node = ft_lstnew("World");
    ft_lstadd_back(&head, new_node);
    print_list(head);
    free(new_node);
    free(head);
    printf("\n");
}

void test_ft_lstsize(void)
{
    printf("Testing ft_lstsize:\n");
    t_list *head = ft_lstnew("Node 1");
    ft_lstadd_back(&head, ft_lstnew("Node 2"));
    ft_lstadd_back(&head, ft_lstnew("Node 3"));
    printf("List size: %d\n", ft_lstsize(head));
    // Free the list
    t_list *tmp;
    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    printf("\n");
}

void test_ft_lstdelone(void)
{
    printf("test ft_lstdelone:\n");
    t_list *node = ft_lstnew("To be deleted");
    printf("Node content before deletion: %s\n", (char *)node->content);
    ft_lstdelone(node, free);
    printf("Node deleted.\n\n");
}
int main(void)
{
    test_ft_isalnum();
    test_ft_bzero();
    test_ft_calloc();
    test_ft_strjoin();
    test_ft_atoi();
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isascii();
    test_ft_isprint();
	test_ft_lstnew();
    test_ft_lstadd_front();
    test_ft_lstadd_back();
    test_ft_lstsize();
    test_ft_lstdelone();
    return (0);
}
