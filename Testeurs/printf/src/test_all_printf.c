#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    ft_printf("===== Test ft_printf =====\n");

    // Test simple string
    ret1 = ft_printf("Hello, World!\n");
    ret2 = printf("Hello, World!\n");
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    // Test %d
    ret1 = ft_printf("Number: %d\n", 42);
    ret2 = printf("Number: %d\n", 42);
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    // Test %s
    ret1 = ft_printf("String: %s\n", "Test string");
    ret2 = printf("String: %s\n", "Test string");
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    // Test %c
    ret1 = ft_printf("Char: %c\n", 'A');
    ret2 = printf("Char: %c\n", 'A');
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    // Test %u
    ret1 = ft_printf("Unsigned: %u\n", 3000000000U);
    ret2 = printf("Unsigned: %u\n", 3000000000U);
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    // Test %x, %X
    ret1 = ft_printf("Hex lowercase: %x\n", 255);
    ret2 = printf("Hex lowercase: %x\n", 255);
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    ret1 = ft_printf("Hex uppercase: %X\n", 255);
    ret2 = printf("Hex uppercase: %X\n", 255);
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    // Test %p
    int a = 42;
    ret1 = ft_printf("Pointer: %p\n", &a);
    ret2 = printf("Pointer: %p\n", &a);
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    // Test %%
    ret1 = ft_printf("Percent: %%\n");
    ret2 = printf("Percent: %%\n");
    ft_printf("ft_printf returned: %d | printf returned: %d\n\n", ret1, ret2);

    return 0;
}

