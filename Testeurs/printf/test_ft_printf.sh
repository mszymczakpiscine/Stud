# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_ft_printf.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 11:28:44 by mszymcza          #+#    #+#              #
#    Updated: 2025/04/29 11:36:26 by mszymcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

Vérifie si le fichier de test existe
if [ ! -f "ft_printf.c" ]; then
    echo "Le fichier ft_printf.c est manquant. Assurez-vous que le fichier est présent dans le dossier."
    exit 1
fi

if [ ! -d "utils" ]; then
    echo "Le dossier utils est manquant. assurez vous qu'il contient les fichiers"
    exit 1
fi

Étape 1 : Compilation
echo "Compilation de ft_printf..."
cc -Wall -Wextra -Werror ft_printf.c utils/*.c -I utils -o test_ft_printf
if [ $? -ne 0 ]; then
    echo "Erreur lors de la compilation."
    exit 1
fi

Étape 2 : Création de fichiers de test (cas variés)
echo "Création des fichiers de test..."

Fichier 1 : Test simple
echo "Test simple : printf et ft_printf avec des chaînes de caractères simples." > test1.txt
echo "Test simple : printf et ft_printf avec des chaînes de caractères simples." >> test1.txt

Fichier 2 : Test avec des entiers
echo "Test avec des entiers : 42 et -42." > test2.txt
echo "42 et -42." >> test2.txt

Fichier 3 : Test avec des flottants
echo "Test avec des flottants : 3.14 et -1.23." > test3.txt
echo "3.14 et -1.23." >> test3.txt

Fichier 4 : Test avec des pointeurs
echo "Test avec des pointeurs : (adresse)." > test4.txt
echo "(adresse)" >> test4.txt

Fichier 5 : Test avec des caractères
echo "Test avec des caractères : 'a' et 'z'." > test5.txt
echo "'a' et 'z'." >> test5.txt

Fichier 6 : Test avec des pourcentages
echo "Test avec des pourcentages : %%." > test6.txt
echo "%%." >> test6.txt

Fichier 7 : Test avec des chaînes vides
echo "Test avec des chaînes vides." > test7.txt
echo "" >> test7.txt

Fichier 8 : Test avec de très grands nombres
echo "Test avec un grand nombre : 123456789012345." > test8.txt
echo "123456789012345." >> test8.txt

Étape 3 : Test et comparaison des sorties
echo "Lancement des tests..."

for i in {1..8}
do
    echo -e "\n=== Test $i ==="

    # Exécuter ft_printf
    ./test_ft_printf < test${i}.txt > ft_printf_output.txt

    # Exécuter printf standard
    echo "Résultat avec printf :"
    cat test${i}.txt | xargs -I {} printf "{}" > printf_output.txt
    cat printf_output.txt

    echo -e "\nRésultat avec ft_printf :"
    cat ft_printf_output.txt

    # Comparer les deux sorties
    echo -e "\nComparaison des sorties :"
    diff printf_output.txt ft_printf_output.txt

    echo "=== Fin du test $i ===\n"
done

Nettoyage des fichiers temporaires
rm -f ft_printf_output.txt printf_output.txt

echo "Tous les tests sont terminés."
