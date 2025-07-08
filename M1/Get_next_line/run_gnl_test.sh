# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_gnl_test.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 10:12:57 by mszymcza          #+#    #+#              #
#    Updated: 2025/04/29 10:13:48 by mszymcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Étape 1 : Créer les fichiers de test

# test1.txt : plusieurs lignes avec \n
echo -e "Ligne 1\nLigne 2\nLigne 3" > test1.txt

# test2.txt : une ligne sans \n
echo -n "Ligne unique sans saut de ligne" > test2.txt

# test3.txt : fichier vide
touch test3.txt

# test4.txt : très longue ligne
head -c 10000 /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 10000 | head -n 1 > test4.txt

# Étape 2 : Compilation
echo "Compilation..."
cc test_gnl.c get_next_line.c get_next_line_utils.c -o test_gnl
if [ $? -ne 0 ]; then
    echo "Erreur de compilation."
    exit 1
fi

# Étape 3 : Lancer les tests
echo -e "\n=== Lancement des tests ==="
./test_gnl test1.txt test2.txt test3.txt test4.txt