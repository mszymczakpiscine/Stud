/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:57:57 by codespace         #+#    #+#             */
/*   Updated: 2025/04/28 19:35:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

// Couleurs
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

// Compteurs globaux
int total_tests = 0;
int passed_tests = 0;
int fast_mode = 0; // 0 = mode normal, 1 = résumé rapide

// Fonction pour dessiner la barre de progression
void print_progress_bar(float percentage)
{
    int bar_width = 20;
    int filled_length = (int)(percentage / 100.0f * bar_width);
    
    printf("[");
    for (int i = 0; i < bar_width; i++)
    {
        if (i < filled_length)
            printf("█"); // rempli
        else
            printf("-"); // vide
    }
    printf("] %.2f%%\n", percentage);
}

// --- Fonctions pour tests de base ---
void run_basic_tests(void)
{
    printf(YELLOW "\n========= TESTS FT_PRINTF (BASE) =========\n\n" RESET);
    int a = 42;

    #define TEST(desc, format, ...) \
        do { \
            int ret_ft = ft_printf(format, ##__VA_ARGS__); \
            int ret_printf = printf(format, ##__VA_ARGS__); \
            if (!fast_mode) \
            { \
                printf(YELLOW desc RESET " "); \
            } \
            total_tests++; \
            if (ret_ft == ret_printf) { \
                if (!fast_mode) printf(GREEN "[OK]\n" RESET); \
                passed_tests++; \
            } else { \
                if (!fast_mode) printf(RED "[FAIL] ft_printf=%d printf=%d\n" RESET, ret_ft, ret_printf); \
            } \
            if (!fast_mode) printf("\n"); \
        } while (0)

    TEST("Simple string", "Hello, World!\n");
    TEST("Character", "Char: %c\n", 'A');
    TEST("String", "String: %s\n", "Test string");
    TEST("Empty string", "Empty String: %s\n", "");
    TEST("NULL string", "NULL String: %s\n", (char *)NULL);
    TEST("Decimal", "Decimal: %d\n", 42);
    TEST("Negative integer", "Negative: %i\n", -42);
    TEST("Zero", "Zero: %d\n", 0);
    TEST("INT_MAX", "INT_MAX: %d\n", 2147483647);
    TEST("INT_MIN", "INT_MIN: %d\n", -2147483648);
    TEST("Unsigned int", "Unsigned: %u\n", 3000000000U);
    TEST("Hex lower", "Hex lower: %x\n", 255);
    TEST("Hex upper", "Hex upper: %X\n", 255);
    TEST("Pointer", "Pointer: %p\n", &a);
    TEST("NULL Pointer", "NULL Pointer: %p\n", NULL);
    TEST("Percent sign", "Percent: %%\n");
    TEST("Width 10", "Width 10: %10d!\n", 123);
    TEST("Left align Width -10", "Width -10: %-10d!\n", 123);
    TEST("Precision .5", "Precision .5: %.5d!\n", 123);
    TEST("Width 10 Precision .5", "Width 10 Precision .5: %10.5d!\n", 123);
    TEST("Combined formats", "Multiple: %d %s %x %c\n", 42, "string", 255, 'Z');
    TEST("Counting chars", "Counting chars: %d %s %c\n", 100, "chars", '!');
    TEST("Unknown specifier", "Unknown: %q\n");

    #undef TEST
}

void summary_basic_tests(int total, int passed)
{
    int failed = total - passed;
    float success_rate = (total > 0) ? (passed * 100.0f / total) : 0.0f;

    printf(YELLOW "\n========= Résultat TESTS BASE =========\n" RESET);
    printf("Total tests: %d\n", total);
    printf(GREEN "Réussis: %d\n" RESET, passed);
    printf(RED "Échoués: %d\n" RESET, failed);
    printf("Taux de réussite: %.2f%%\n", success_rate);
    print_progress_bar(success_rate);

    if (failed == 0)
        printf(GREEN "🎉 Tous les tests BASE sont passés avec succès ! 🎉\n" RESET);
    else
        printf(RED "❌ Il reste des erreurs de base à corriger ! ❌\n" RESET);
}

// --- Fonctions pour tests BONUS ---
void run_bonus_tests(void)
{
    printf(YELLOW "\n========= TESTS FT_PRINTF (BONUS) =========\n\n" RESET);
    int a = 42;
    int b = -42;
    unsigned int u = 255;

    #define TEST(desc, format, ...) \
        do { \
            int ret_ft = ft_printf(format, ##__VA_ARGS__); \
            int ret_printf = printf(format, ##__VA_ARGS__); \
            if (!fast_mode) \
            { \
                printf(YELLOW desc RESET " "); \
            } \
            total_tests++; \
            if (ret_ft == ret_printf) { \
                if (!fast_mode) printf(GREEN "[OK]\n" RESET); \
                passed_tests++; \
            } else { \
                if (!fast_mode) printf(RED "[FAIL] ft_printf=%d printf=%d\n" RESET, ret_ft, ret_printf); \
            } \
            if (!fast_mode) printf("\n"); \
        } while (0)

    // Tests FLAG #
    TEST("Flag #: Hexadecimal lower", "%#x\n", u);
    TEST("Flag #: Hexadecimal upper", "%#X\n", u);
    TEST("Flag #: Octal", "%#o\n", u);

    // Tests FLAG 0
    TEST("Flag 0: Zero padded decimal", "%010d\n", a);
    TEST("Flag 0: Zero padded negative", "%010d\n", b);

    // Tests FLAG +
    TEST("Flag +: Positive decimal", "%+d\n", a);
    TEST("Flag +: Negative decimal", "%+d\n", b);

    // Tests FLAG espace
    TEST("Flag espace: Positive", "% d\n", a);
    TEST("Flag espace: Negative", "% d\n", b);

    // Tests FLAG -
    TEST("Flag -: Left align decimal", "%-10d!\n", a);

    // Combinaisons
    TEST("Flags +0: Plus + Zero", "%+010d\n", a);
    TEST("Flags -0: Left align + Zero", "%-010d!\n", a);
    TEST("Flags #0: Alternate + Zero padding hex", "%#010x\n", u);

    // Spéciaux
    TEST("Flag #: Hex 0 value", "%#x\n", 0);
    TEST("Flag #: Octal 0 value", "%#o\n", 0);

    #undef TEST
}

void summary_bonus_tests(int total_start, int passed_start)
{
    int bonus_total = total_tests - total_start;
    int bonus_passed = passed_tests - passed_start;
    int bonus_failed = bonus_total - bonus_passed;
    float success_rate = (bonus_total > 0) ? (bonus_passed * 100.0f / bonus_total) : 0.0f;

    printf(YELLOW "\n========= Résultat TESTS BONUS =========\n" RESET);
    printf("Total tests bonus: %d\n", bonus_total);
    printf(GREEN "Réussis: %d\n" RESET, bonus_passed);
    printf(RED "Échoués: %d\n" RESET, bonus_failed);
    printf("Taux de réussite: %.2f%%\n", success_rate);
    print_progress_bar(success_rate);

    if (bonus_failed == 0)
        printf(GREEN "🎉 Tous les tests BONUS sont passés avec succès ! 🎉\n" RESET);
    else
        printf(RED "❌ Il reste des erreurs BONUS à corriger ! ❌\n" RESET);
}

// --- MAIN ---
int main(void)
{
    char choice;
    printf(YELLOW "Mode Résumé rapide ? (y/n): " RESET);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
        fast_mode = 1;

    int start_total = total_tests;
    int start_passed = passed_tests;

    run_basic_tests();
    summary_basic_tests(total_tests, passed_tests);

    int middle_total = total_tests;
    int middle_passed = passed_tests;

    run_bonus_tests();
    summary_bonus_tests(middle_total, middle_passed);

    return 0;
}
