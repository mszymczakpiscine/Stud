#!/bin/bash

# Couleurs pour l'affichage
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

# Compteur de tests
TOTAL_TESTS=0
PASSED_TESTS=0

# Fonction pour afficher les résultats
print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}[OK]${NC} $2"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        echo -e "${RED}[KO]${NC} $2"
    fi
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
}

# Fonction pour tester les erreurs
test_errors() {
    echo -e "\n${BLUE}=== Test de gestion des erreurs ===${NC}"
    
    # Test avec lettre
    ./push_swap "a" 2>&1 | grep -q "Error" && print_result 0 "Test avec lettre" || print_result 1 "Test avec lettre"
    
    # Test avec doublon
    ./push_swap "1 1" 2>&1 | grep -q "Error" && print_result 0 "Test avec doublon" || print_result 1 "Test avec doublon"
    
    # Test avec nombre trop grand
    ./push_swap "2147483648" 2>&1 | grep -q "Error" && print_result 0 "Test avec INT_MAX+1" || print_result 1 "Test avec INT_MAX+1"
    
    # Test avec nombre trop petit
    ./push_swap "-2147483649" 2>&1 | grep -q "Error" && print_result 0 "Test avec INT_MIN-1" || print_result 1 "Test avec INT_MIN-1"
}

# Fonction pour tester si une pile est triée
is_sorted() {
    local NUMS=($1)
    for ((i=0; i<${#NUMS[@]}-1; i++)); do
        if [ ${NUMS[$i]} -gt ${NUMS[$i+1]} ]; then
            return 1
        fi
    done
    return 0
}

# Fonction pour compter les instructions
count_instructions() {
    local NUMS="$1"
    local COUNT=$(./push_swap $NUMS | wc -l)
    echo $COUNT
}

# Fonction pour tester les petites piles
test_small_stacks() {
    echo -e "\n${BLUE}=== Test des petites piles ===${NC}"
    
    # Test avec 2 nombres
    local NUMS="2 1"
    local COUNT=$(count_instructions "$NUMS")
    local OUTPUT=$(./push_swap $NUMS | ./push_swap $NUMS | tr '\n' ' ')
    is_sorted "$NUMS" && [ $COUNT -le 1 ] && print_result 0 "2 nombres ($COUNT moves)" || print_result 1 "2 nombres ($COUNT moves)"
    
    # Test avec 3 nombres
    NUMS="3 1 2"
    COUNT=$(count_instructions "$NUMS")
    OUTPUT=$(./push_swap $NUMS | ./push_swap $NUMS | tr '\n' ' ')
    is_sorted "$NUMS" && [ $COUNT -le 3 ] && print_result 0 "3 nombres ($COUNT moves)" || print_result 1 "3 nombres ($COUNT moves)"
    
    # Test avec 5 nombres
    NUMS="5 2 3 1 4"
    COUNT=$(count_instructions "$NUMS")
    OUTPUT=$(./push_swap $NUMS | ./push_swap $NUMS | tr '\n' ' ')
    is_sorted "$NUMS" && [ $COUNT -le 12 ] && print_result 0 "5 nombres ($COUNT moves)" || print_result 1 "5 nombres ($COUNT moves)"
}

# Fonction pour générer une séquence aléatoire
generate_random_sequence() {
    local SIZE=$1
    seq 1 $SIZE | shuf | tr '\n' ' '
}

# Fonction pour tester les grandes piles
test_big_stacks() {
    echo -e "\n${BLUE}=== Test des grandes piles ===${NC}"
    
    # Test avec 100 nombres
    local NUMS=$(generate_random_sequence 100)
    local COUNT=$(count_instructions "$NUMS")
    local OUTPUT=$(./push_swap $NUMS | ./push_swap $NUMS | tr '\n' ' ')
    is_sorted "$NUMS" && [ $COUNT -le 700 ] && print_result 0 "100 nombres ($COUNT moves)" || print_result 1 "100 nombres ($COUNT moves)"
    
    # Test avec 500 nombres
    NUMS=$(generate_random_sequence 500)
    COUNT=$(count_instructions "$NUMS")
    OUTPUT=$(./push_swap $NUMS | ./push_swap $NUMS | tr '\n' ' ')
    is_sorted "$NUMS" && [ $COUNT -le 5500 ] && print_result 0 "500 nombres ($COUNT moves)" || print_result 1 "500 nombres ($COUNT moves)"
}

# Fonction pour tester les cas spéciaux
test_special_cases() {
    echo -e "\n${BLUE}=== Test des cas spéciaux ===${NC}"
    
    # Test avec pile déjà triée
    local NUMS="1 2 3 4 5"
    local COUNT=$(count_instructions "$NUMS")
    [ $COUNT -eq 0 ] && print_result 0 "Pile déjà triée" || print_result 1 "Pile déjà triée"
    
    # Test avec pile en ordre inverse
    NUMS="5 4 3 2 1"
    COUNT=$(count_instructions "$NUMS")
    local OUTPUT=$(./push_swap $NUMS | ./push_swap $NUMS | tr '\n' ' ')
    is_sorted "$NUMS" && print_result 0 "Pile en ordre inverse" || print_result 1 "Pile en ordre inverse"
}

# Exécution des tests
echo -e "${BLUE}=== Début des tests de Push_swap ===${NC}"
test_errors
test_small_stacks
test_big_stacks
test_special_cases

# Affichage du résultat final
echo -e "\n${BLUE}=== Résultats des tests ===${NC}"
echo -e "Tests réussis: ${GREEN}$PASSED_TESTS${NC}/$TOTAL_TESTS"
if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}Tous les tests ont réussi !${NC}"
else
    echo -e "${RED}Certains tests ont échoué.${NC}"
fi 