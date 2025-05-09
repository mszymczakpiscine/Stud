#!/bin/bash

export LC_NUMERIC=C
# =========================================
# Configuration
# =========================================
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
PURPLE='\033[1;35m'
CYAN='\033[1;36m'
NC='\033[0m'

TEST_DIR=".tester"

# Auto-generated test files for missing cases
create_test_file "test_putchar.c" "$(cat <<EOF
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar_fd(char c, int fd);

int main(void) {
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return 1;
    ft_putchar_fd('A', fd);
    close(fd);
    return 0;
}
EOF
)"
create_test_file "test_putendl.c" "$(cat <<EOF
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putendl_fd(char *s, int fd);

int main(void) {
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return 1;

    ft_putendl_fd("test", fd);
    close(fd);

    fd = open("test_output.txt", O_RDONLY);
    if (fd < 0) return 1;
    char buffer[10] = {0};
    read(fd, buffer, 9);
    close(fd);

    if (strcmp(buffer, "test\n") != 0) return 1;
    return 0;
}
EOF
)"
mkdir -p $TEST_DIR
LOG_FILE="test_results.log"
VALGRIND_LEAKS="--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose"
BUFFER_SIZES="1 32 1024 9999"

# =========================================
# Fonctions utilitaires
# =========================================

create_test_file() {
    local filename="$TEST_DIR/$1"
    local content="$2"
    
    # Création du dossier si inexistant
    mkdir -p "$TEST_DIR"
    
    # Création du fichier avec le contenu
    echo "$content" > "$filename" 2>/dev/null
    
    # Vérification robuste
    if [ ! -f "$filename" ]; then
        echo -e "${RED}Error: Failed to create test file $filename${NC}"
        echo "Debug: Current directory: $(pwd)" >&2
        echo "Debug: Attempting to create: $filename" >&2
        return 1
    fi
    
    return 0
}

print_header() {
    echo -e "${PURPLE}\n[=== $1 ===]${NC}"
    echo -e "\n[=== $1 ===]" >> $LOG_FILE
}

print_test() {
    printf "%-60s" "$1"
    printf "%-60s" "$1" >> $LOG_FILE
}

print_result() {
    if [ "$1" -eq 0 ]; then
        echo -e "${GREEN}✓ PASS${NC}"
        echo "✓ PASS" >> "$LOG_FILE"
    else
        echo -e "${RED}✗ FAIL${NC}"
        echo "✗ FAIL" >> "$LOG_FILE"
        [ -n "$2" ] && echo -e "${YELLOW}$2${NC}" && echo "$2" >> "$LOG_FILE"
    fi
}

print_ok() {
    echo -e "${GREEN}✓ OK${NC}"
    echo "✓ OK" >> $LOG_FILE
}

print_fail() {
    echo -e "${RED}✗ FAIL${NC}"
    echo "✗ FAIL" >> $LOG_FILE
    [ -n "$2" ] && echo -e "${YELLOW}Expected:\n$2${NC}" && echo "Expected:" >> $LOG_FILE && echo "$2" >> $LOG_FILE
    [ -n "$3" ] && echo -e "${YELLOW}Got:\n$3${NC}" && echo "Got:" >> $LOG_FILE && echo "$3" >> $LOG_FILE
}

find_header() {
    # Cherche le header dans les emplacements standards
    [ -f "./includes/ft_printf.h" ] && echo "-I./includes"
    [ -f "./ft_printf.h" ] && echo "-I."
    [ -f "../includes/ft_printf.h" ] && echo "-I../includes"
}

compile_test() {
    local include_flags=$(find_header)
    if [ -z "$include_flags" ]; then
        echo "Could not find ft_printf.h in any standard location" > "$TEST_DIR/compile_error.txt"
        return 1
    fi
    
    gcc $include_flags -o "$TEST_DIR/$1" "$TEST_DIR/$2" $3 2>"$TEST_DIR/compile_error.txt"
    return $?
}

run_test() {
    "$TEST_DIR/$1" > "$TEST_DIR/test_output.txt" 2>"$TEST_DIR/test_error.txt"
    return $?
}

run_valgrind() {
    valgrind $VALGRIND_LEAKS "$TEST_DIR/$1" > "$TEST_DIR/valgrind_out.txt" 2>&1
    grep -q "ERROR SUMMARY: 0 errors" "$TEST_DIR/valgrind_out.txt"
    return $?
}

cleanup() {
    rm -rf "$TEST_DIR"
}

# =========================================
# Fonctions de compilation et exécution
# =========================================
compile_test() {
    local test_name="$1"
    local test_file="$TEST_DIR/$2"
    local libs="$3"
    
    if [ ! -f "$test_file" ]; then
        echo "Test file $test_file not found" > "$TEST_DIR/compile_error.txt"
        return 1
    fi
    
    gcc -I. -Iincludes -o "$TEST_DIR/$test_name" "$test_file" $libs 2>"$TEST_DIR/compile_error.txt"
    return $?
}

run_test() {
    local test_name="$1"
    local timeout=2  # seconds
    
    timeout $timeout "$TEST_DIR/$test_name" > "$TEST_DIR/test_output.txt" 2>"$TEST_DIR/test_error.txt"
    return $?
}

# =========================================#
# Fonctions de test avancées			   #
# =========================================#

run_single_test() {
    local test_name=$1
    local test_file=$2
    local libs=$3
    local check_mem=${4:-false}
    
    print_test "$test_name"
    if ! compile_test "test" "$test_file" "$libs"; then
        print_fail "Compilation failed" "$(cat $TEST_DIR/compile_error.txt)"
        return
    fi

    if ! run_test "test"; then
        print_fail "Runtime error" "$(cat $TEST_DIR/test_error.txt)"
        return
    fi

    if $check_mem; then
        if ! run_valgrind "test"; then
            local leaks=$(grep -A 10 -e "LEAK SUMMARY" -e "ERROR SUMMARY" "$TEST_DIR/valgrind_out.txt")
            print_fail "Memory issues detected" "$leaks"
            return
        fi
    fi

    print_ok
}

run_memory_test() {
    run_single_test "$1 (memory)" "$2" "$3" true
}

run_perf_test() {
    local test_name=$1
    local test_file=$2
    local libs=$3
    local iterations=${4:-1000}

    print_test "$test_name ($iterations iterations)"
    if ! compile_test "perf_test" "$test_file" "$libs"; then
        print_fail "Compilation failed" "$(cat $TEST_DIR/compile_error.txt)"
        return
    fi

    local start=$(date +%s.%N)
    for ((i=0; i<iterations; i++)); do
        "$TEST_DIR/perf_test" >/dev/null 2>&1
    done
    local end=$(date +%s.%N)
    local elapsed=$(printf "%.3f" $(echo "$end - $start" | bc))

    echo -e "${CYAN}⏱ ${elapsed}s${NC}"
    echo "⏱ ${elapsed}s" >> $LOG_FILE
}

run_fuzz_test() {
    local test_name=$1
    local test_file=$2
    local libs=$3
    local iterations=${4:-100}

    print_test "$test_name (fuzzing $iterations iterations)"
    if ! compile_test "fuzz_test" "$test_file" "$libs"; then
        print_fail "Compilation failed"
        return
    fi

    local fails=0
    for ((i=0; i<iterations; i++)); do
        local input=$(head /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 20 | head -n 1)
        echo "$input" > "$TEST_DIR/fuzz_input.txt"
        
        "$TEST_DIR/fuzz_test" "$TEST_DIR/fuzz_input.txt" >/dev/null 2>&1
        [ $? -ne 0 ] && fails=$((fails+1))
    done

    [ $fails -eq 0 ] && print_ok || print_fail "0 failures" "$fails failures detected"
}

test_libft_memory() {
    print_header "LIBFT Memory Tests"
    
    # Test mémoire complet
    create_test_file "mem_libft.c" "
#include \"libft.h\"
int main() {
    char *s1 = ft_strdup(\"test\");
    char *s2 = ft_itoa(123);
    free(s1);
    free(s2);
    return 0;
}"
    run_memory_test "libft memory" "mem_libft.c" "libft.a"
}

test_libft_performance() {
    print_header "LIBFT Performance Tests"

    create_test_file "perf_strlen.c" "
#include \"libft.h\"
#define ITER 10000
int main() {
    for (int i = 0; i < ITER; i++)
        ft_strlen(\"performance test\");
    return 0;
}"
    run_perf_test "ft_strlen" "perf_strlen.c" "libft.a"
}

test_libft_fuzzing() {
    print_header "LIBFT Fuzzing Tests"

    create_test_file "fuzz_atoi.c" "
#include \"libft.h\"
int main(int argc, char **argv) {
    if (argc != 2) return 1;
    ft_atoi(argv[1]);
    return 0;
}"
    run_fuzz_test "ft_atoi" "fuzz_atoi.c" "libft.a"
}

check_required_files() {
    local project=$1
    shift
    local missing=0

    print_header "Checking $project required files"
    
    # Ne pas vérifier les fichiers .a initialement
    local files_to_check=()
    for file in "$@"; do
        [[ $file != *.a ]] && files_to_check+=("$file")
    done
    
    for file in "${files_to_check[@]}"; do
        print_test "Checking $file"
        if [ -f "$file" ]; then
            print_ok
        else
            print_fail
            missing=$((missing+1))
        fi
    done

    [ $missing -gt 0 ] && echo -e "${RED}$missing required files missing${NC}" && return 1
    
    # Compilation si tout ok
    print_test "Compiling project"
    make re >/dev/null 2>"$TEST_DIR/make_error.txt"
    if [ $? -eq 0 ]; then
        print_ok
        # Vérification des fichiers .a après compilation
        for file in "$@"; do
            if [[ $file == *.a ]]; then
                print_test "Checking $file"
                if [ -f "$file" ]; then
                    print_ok
                else
                    print_fail
                    missing=$((missing+1))
                fi
            fi
        done
    else
        print_fail "Compilation failed" "$(cat $TEST_DIR/make_error.txt)"
        return 1
    fi
    
    [ $missing -gt 0 ] && echo -e "${RED}$missing required files missing${NC}" && return 1
    return 0
}

# =========================================#
# Tests LIBFT							   #	
# =========================================#

test_libft() {
    print_header "TESTING LIBFT"
    
    # Vérification des fichiers et compilation
    if ! check_required_files "libft" "Makefile" "libft.h" "ft_isalpha.c"; then
        echo -e "${YELLOW}Attempting to compile anyway...${NC}"
        make re >/dev/null 2>&1
    fi

    # Vérifier explicitement la bibliothèque
    if [ ! -f "libft.a" ]; then
        echo -e "${YELLOW}libft.a not found, trying to compile...${NC}"
        make re >/dev/null 2>&1
        if [ ! -f "libft.a" ]; then
            echo -e "${RED}Error: libft.a not found after compilation${NC}"
            return 1
        fi
    fi

    # Tests standards
    test_libft_part1
    test_libft_part2
    test_libft_part3
    test_libft_extra
    test_libft_bonus

    # Tests avancés
    test_libft_memory
    test_libft_performance
    test_libft_fuzzing
}

test_libft_part1() {
    print_header "Testing Part 1 - ctype functions"

    # ft_isalpha
    create_test_file "test_isalpha.c" "
#include \"libft.h\"
int main() {
    if (!ft_isalpha('A') || !ft_isalpha('z') || ft_isalpha('0')) return 1;
    return 0;
}"
    run_single_test "ft_isalpha" "test_isalpha.c" "libft.a"

    # ft_isdigit
    create_test_file "test_isdigit.c" "
#include \"libft.h\"
int main() {
    if (!ft_isdigit('0') || !ft_isdigit('9') || ft_isdigit('a')) return 1;
    return 0;
}"
    run_single_test "ft_isdigit" "test_isdigit.c" "libft.a"

    # ft_isalnum
    create_test_file "test_isalnum.c" "
#include \"libft.h\"
int main() {
    if (!ft_isalnum('A') || !ft_isalnum('9') || ft_isalnum('!')) return 1;
    return 0;
}"
    run_single_test "ft_isalnum" "test_isalnum.c" "libft.a"

    # ft_isascii
    create_test_file "test_isascii.c" "
#include \"libft.h\"
int main() {
    if (!ft_isascii(0) || !ft_isascii(127) || ft_isascii(128)) return 1;
    return 0;
}"
    run_single_test "ft_isascii" "test_isascii.c" "libft.a"

    # ft_isprint
    create_test_file "test_isprint.c" "
#include \"libft.h\"
int main() {
    if (!ft_isprint(' ') || !ft_isprint('~') || ft_isprint(31)) return 1;
    return 0;
}"
    run_single_test "ft_isprint" "test_isprint.c" "libft.a"

    # ft_toupper
    create_test_file "test_toupper.c" "
#include \"libft.h\"
int main() {
    if (ft_toupper('a') != 'A' || ft_toupper('Z') != 'Z') return 1;
    return 0;
}"
    run_single_test "ft_toupper" "test_toupper.c" "libft.a"

    # ft_tolower
    create_test_file "test_tolower.c" "
#include \"libft.h\"
int main() {
    if (ft_tolower('A') != 'a' || ft_tolower('z') != 'z') return 1;
    return 0;
}"
    run_single_test "ft_tolower" "test_tolower.c" "libft.a"
}

test_libft_part2() {
    print_header "Testing Part 2 - string functions"

    # ft_strlen
    create_test_file "test_strlen.c" "
#include \"libft.h\"
int main() {
    if (ft_strlen(\"\") != 0 || ft_strlen(\"hello\") != 5) return 1;
    return 0;
}"
    run_single_test "ft_strlen" "test_strlen.c" "libft.a"

    # ft_strchr
    create_test_file "test_strchr.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = \"test\";
    if (ft_strchr(s, 'e') != strchr(s, 'e') || ft_strchr(s, 0) != s + 4) return 1;
    return 0;
}"
    run_single_test "ft_strchr" "test_strchr.c" "libft.a"

    # ft_strrchr
    create_test_file "test_strrchr.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = \"test\";
    if (ft_strrchr(s, 't') != s + 3 || ft_strrchr(s, 'x')) return 1;
    return 0;
}"
    run_single_test "ft_strrchr" "test_strrchr.c" "libft.a"

    # ft_strncmp
    create_test_file "test_strncmp.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    if (ft_strncmp(\"test\", \"test\", 4) != 0 || 
        ft_strncmp(\"a\", \"b\", 1) >= 0) return 1;
    return 0;
}"
    run_single_test "ft_strncmp" "test_strncmp.c" "libft.a"

    # ft_strlcpy
    create_test_file "test_strlcpy.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char dst[10];
    if (ft_strlcpy(dst, \"hello\", sizeof(dst)) != 5 || strcmp(dst, \"hello\")) return 1;
    return 0;
}"
    run_single_test "ft_strlcpy" "test_strlcpy.c" "libft.a"

    # ft_strlcat
    create_test_file "test_strlcat.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char dst[10] = \"a\";
    if (ft_strlcat(dst, \"b\", sizeof(dst)) != 2 || strcmp(dst, \"ab\")) return 1;
    return 0;
}"
    run_single_test "ft_strlcat" "test_strlcat.c" "libft.a"

    # ft_strnstr
    create_test_file "test_strnstr.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = \"hello world\";
    if (ft_strnstr(s, \"world\", 11) != s + 6 || ft_strnstr(s, \"x\", 11)) return 1;
    return 0;
}"
    run_single_test "ft_strnstr" "test_strnstr.c" "libft.a"

    # ft_atoi
    create_test_file "test_atoi.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    if (ft_atoi(\"123\") != 123 || ft_atoi(\"-456\") != -456) return 1;
    return 0;
}"
    run_single_test "ft_atoi" "test_atoi.c" "libft.a"

    # ft_strdup
    create_test_file "test_strdup.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = ft_strdup(\"test\");
    if (!s || strcmp(s, \"test\")) { free(s); return 1; }
    free(s);
    return 0;
}"
    run_memory_test "ft_strdup" "test_strdup.c" "libft.a"
}

test_libft_part3() {
    print_header "Testing Part 3 - memory functions"

    # ft_memset
    create_test_file "test_memset.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char str[10];
    ft_memset(str, 'A', 10);
    for (int i = 0; i < 10; i++)
        if (str[i] != 'A') return 1;
    return 0;
}"
    run_single_test "ft_memset" "test_memset.c" "libft.a"

    # ft_bzero
    create_test_file "test_bzero.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char str[10] = \"test\";
    ft_bzero(str, 2);
    if (str[0] != 0 || str[1] != 0 || str[2] != 's') return 1;
    return 0;
}"
    run_single_test "ft_bzero" "test_bzero.c" "libft.a"

    # ft_memcpy
    create_test_file "test_memcpy.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char src[10] = \"test\";
    char dst[10];
    ft_memcpy(dst, src, 5);
    if (strcmp(dst, src)) return 1;
    return 0;
}"
    run_single_test "ft_memcpy" "test_memcpy.c" "libft.a"

    # ft_memmove
    create_test_file "test_memmove.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char s[10] = \"hello\";
    ft_memmove(s + 1, s, 4);
    if (strcmp(s, \"hhell\")) return 1;
    return 0;
}"
    run_single_test "ft_memmove" "test_memmove.c" "libft.a"

    # ft_memchr
    create_test_file "test_memchr.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = \"test\";
    if (ft_memchr(s, 'e', 4) != s + 1 || ft_memchr(s, 'x', 4)) return 1;
    return 0;
}"
    run_single_test "ft_memchr" "test_memchr.c" "libft.a"

    # ft_memcmp
    create_test_file "test_memcmp.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    if (ft_memcmp(\"a\", \"b\", 1) >= 0 || ft_memcmp(\"a\", \"a\", 1) != 0) return 1;
    return 0;
}"
    run_single_test "ft_memcmp" "test_memcmp.c" "libft.a"

    # ft_calloc
    create_test_file "test_calloc.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = ft_calloc(10, 1);
    for (int i = 0; i < 10; i++)
        if (s[i] != 0) { free(s); return 1; }
    free(s);
    return 0;
}"
    run_memory_test "ft_calloc" "test_calloc.c" "libft.a"
}

test_libft_extra() {
    print_header "Testing Additional Functions"

    # ft_substr
    create_test_file "test_substr.c" "
#include \"libft.h\"
int main() {
    char *s = ft_substr(\"hello world\", 6, 5);
    if (!s || strcmp(s, \"world\")) { free(s); return 1; }
    free(s);
    return 0;
}"
    run_memory_test "ft_substr" "test_substr.c" "libft.a"

    # ft_strjoin
    create_test_file "test_strjoin.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = ft_strjoin(\"hello\", \" world\");
    if (!s || strcmp(s, \"hello world\")) { free(s); return 1; }
    free(s);
    return 0;
}"
    run_memory_test "ft_strjoin" "test_strjoin.c" "libft.a"

    # ft_strtrim
    create_test_file "test_strtrim.c" "
#include \"libft.h\"
int main() {
    char *s = ft_strtrim(\"  hello  \", \" \");
    if (!s || strcmp(s, \"hello\")) { free(s); return 1; }
    free(s);
    return 0;
}"
    run_memory_test "ft_strtrim" "test_strtrim.c" "libft.a"

    # ft_split
    create_test_file "test_split.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char **arr = ft_split(\"hello world\", ' ');
    if (!arr || !arr[0] || !arr[1] || arr[2] || 
        strcmp(arr[0], \"hello\") || strcmp(arr[1], \"world\")) {
        if (arr) {
            for (int i = 0; arr[i]; i++) free(arr[i]);
            free(arr);
        }
        return 1;
    }
    for (int i = 0; arr[i]; i++) free(arr[i]);
    free(arr);
    return 0;
}"
    run_memory_test "ft_split" "test_split.c" "libft.a"

    # ft_itoa
    create_test_file "test_itoa.c" "
#include \"libft.h\"
#include <string.h>
int main() {
    char *s = ft_itoa(-123);
    if (!s || strcmp(s, \"-123\")) { free(s); return 1; }
    free(s);
    return 0;
}"
    run_memory_test "ft_itoa" "test_itoa.c" "libft.a"

    # ft_strmapi
    create_test_file "test_strmapi.c" "
#include \"libft.h\"
char mapi(unsigned int i, char c) { return c + i; }
int main() {
    char *s = ft_strmapi(\"abc\", mapi);
    if (!s || strcmp(s, \"ace\")) { free(s); return 1; }
    free(s);
    return 0;
}"
    run_memory_test "ft_strmapi" "test_strmapi.c" "libft.a"

    # ft_striteri
    create_test_file "test_striteri.c" "
#include \"libft.h\"
#include <string.h>
void iter(unsigned int i, char *c) { *c += i; }
int main() {
    char s[4] = \"abc\";
    ft_striteri(s, iter);
    if (strcmp(s, \"ace\")) return 1;
    return 0;
}"
    run_single_test "ft_striteri" "test_striteri.c" "libft.a"

    # ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd - VERSION CORRIGÉE
test_libft_extra() {
    print_header "Testing Additional Functions"

    # ... (autres tests existants)
    create_test_file "test_putchar.c" '
#include "libft.h"
int main() {
    ft_putchar_fd('\''X'\'', 1);  // stdout
    return 0;
}'
    
    if [ -f "$TEST_DIR/test_putchar.c" ]; then
        echo "Fichier créé avec succès à: $TEST_DIR/test_putchar.c"
        run_single_test "ft_putchar_fd" "test_putchar.c" "libft.a"
    else
        echo -e "${RED}Échec critique: Impossible de créer le fichier de test${NC}"
        echo "Veuillez vérifier:"
        echo "1. Les permissions du dossier $(pwd)"
        echo "2. L'espace disque disponible"
        echo "3. La commande 'touch $TEST_DIR/test.tmp' fonctionne"
    fi
}

    # ft_putstr_fd
    create_test_file "test_putstr.c" '
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open(".tester/putstr_out", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1) return 1;
    
    ft_putstr_fd("Hello", fd);
    close(fd);
    
    fd = open(".tester/putstr_out", O_RDONLY);
    if (fd == -1) return 1;
    
    char buf[10] = {0};
    read(fd, buf, 5);
    close(fd);
    
    return strcmp(buf, "Hello");
}'
    run_single_test "ft_putstr_fd" "test_putstr.c" "libft.a"

    # ft_putendl_fd
    create_test_file "test_putendl.c" '
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open(".tester/putendl_out", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1) return 1;
    
    ft_putendl_fd("World", fd);
    close(fd);
    
    fd = open(".tester/putendl_out", O_RDONLY);
    if (fd == -1) return 1;
    
    char buf[10] = {0};
    read(fd, buf, 6);
    close(fd);
    
    return strcmp(buf, "World\n");
}'
    run_single_test "ft_putendl_fd" "test_putendl.c" "libft.a"

    # ft_putnbr_fd
    create_test_file "test_putnbr.c" '
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open(".tester/putnbr_out", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1) return 1;
    
    ft_putnbr_fd(12345, fd);
    ft_putnbr_fd(-678, fd);
    close(fd);
    
    fd = open(".tester/putnbr_out", O_RDONLY);
    if (fd == -1) return 1;
    
    char buf[20] = {0};
    read(fd, buf, 9);
    close(fd);
    
    return strcmp(buf, "12345-678");
}'
    run_single_test "ft_putnbr_fd" "test_putnbr.c" "libft.a"
}

# =========================================
# Ajout des fonctions bonus manquantes
# =========================================

test_libft_bonus() {
    print_header "Testing Bonus Functions"
    
    # Vérification des fichiers bonus
    local bonus_files=("ft_lstnew.c" "ft_lstadd_front.c" "ft_lstsize.c" 
                      "ft_lstlast.c" "ft_lstadd_back.c" "ft_lstdelone.c" 
                      "ft_lstclear.c" "ft_lstiter.c" "ft_lstmap.c")
    local missing=0
    
    for file in "${bonus_files[@]}"; do
        if [ ! -f "$file" ]; then
            missing=1
            break
        fi
    done
    
    if [ $missing -eq 1 ]; then
        echo -e "${YELLOW}Bonus files not found, skipping...${NC}"
        return
    fi

    # Recompilation avec les bonus
    make re bonus >/dev/null 2>"$TEST_DIR/make_bonus_error.txt"
    if [ $? -ne 0 ]; then
        echo -e "${RED}Bonus compilation failed${NC}"
        return 1
    fi
 
	 # ft_lstsize
    create_test_file "test_lstsize.c" '
#include "libft.h"
int main() {
    char *s1 = strdup("a");
    char *s2 = strdup("b");

    if (!s1 || !s2)
        return 1;

    t_list *lst = ft_lstnew(s1);
    if (!lst) {
        free(s1);
        free(s2);
        return 1;
    }

    t_list *node2 = ft_lstnew(s2);
    if (!node2) {
        free(s2);
        ft_lstclear(&lst, free);
        return 1;
    }

    ft_lstadd_front(&lst, node2);

    int size = ft_lstsize(lst);

    ft_lstclear(&lst, free);

    return (size == 2) ? 0 : 1;
}'

    run_memory_test "ft_lstsize" "test_lstsize.c" "libft.a"

    # ft_lstlast
    create_test_file "test_lstlast.c" '
#include "libft.h"
int main() {
    char *s1 = strdup("a");
    char *s2 = strdup("b");
    char *s3 = strdup("last");

    if (!s1 || !s2 || !s3)
        return 1;

    t_list *lst = ft_lstnew(s1);
    t_list *second = ft_lstnew(s2);
    t_list *last = ft_lstnew(s3);

    if (!lst || !second || !last) {
        free(s1);
        free(s2);
        free(s3);
        ft_lstclear(&lst, free);
        ft_lstclear(&second, free);
        ft_lstclear(&last, free);
        return 1;
    }

    ft_lstadd_front(&lst, second); // second devient la tête
    ft_lstadd_back(&lst, last);    // last devient la fin

    int result = (ft_lstlast(lst) == last) ? 0 : 1;

    ft_lstclear(&lst, free);
    return result;
}'
    run_memory_test "ft_lstlast" "test_lstlast.c" "libft.a"

    # ft_lstadd_back
    create_test_file "test_lstadd_back.c" '
#include "libft.h"
int main() {
    char *s1 = strdup("a");
    char *s2 = strdup("new");

    if (!s1 || !s2)
        return 1;

    t_list *lst = ft_lstnew(s1);
    t_list *new = ft_lstnew(s2);

    if (!lst || !new) {
        free(s1);
        free(s2);
        ft_lstclear(&lst, free);
        ft_lstclear(&new, free);
        return 1;
    }

    ft_lstadd_back(&lst, new);

    int result = (ft_lstlast(lst) == new) ? 0 : 1;

    ft_lstclear(&lst, free);
    return result;
}'
    run_memory_test "ft_lstadd_back" "test_lstadd_back.c" "libft.a"

    # ft_lstdelone
    create_test_file "test_lstdelone.c" '
#include "libft.h"
void del(void *content) { free(content); }
int main() {
    char *s = strdup("content");
    t_list *lst = ft_lstnew(s);
    ft_lstdelone(lst, del);
    return 0;
}'
    run_memory_test "ft_lstdelone" "test_lstdelone.c" "libft.a"

    # ft_lstdelone
    create_test_file "test_lstdelone.c" '
#include "libft.h"
void del(void *content) { free(content); }
int main() {
    char *s = strdup("content");
    t_list *lst = ft_lstnew(s);
    ft_lstdelone(lst, del);
    return 0;
}'
    run_memory_test "ft_lstdelone" "test_lstdelone.c" "libft.a"

    # ft_lstclear
    create_test_file "test_lstclear.c" '
#include "libft.h"
void del(void *content) { free(content); }
int main() {
    t_list *lst = ft_lstnew(strdup("a"));
    ft_lstadd_back(&lst, ft_lstnew(strdup("b")));
    ft_lstclear(&lst, del);
    if (lst) return 1;
    return 0;
}'
    run_memory_test "ft_lstclear" "test_lstclear.c" "libft.a"

    # ft_lstiter
    create_test_file "test_lstiter.c" '
#include "libft.h"
void iter(void *content) { ((char *)content)[0] = '\''X'\''; }
int main() {
    char *s1 = strdup("a");
    char *s2 = strdup("b");
    t_list *lst = ft_lstnew(s1);
    ft_lstadd_back(&lst, ft_lstnew(s2));
    ft_lstiter(lst, iter);
    if (strcmp(s1, "X") || strcmp(s2, "X")) {
        ft_lstclear(&lst, free);
        return 1;
    }
    ft_lstclear(&lst, free);
    return 0;
}'
    run_memory_test "ft_lstiter" "test_lstiter.c" "libft.a"

    # ft_lstmap
    create_test_file "test_lstmap.c" '
#include "libft.h"
void *map(void *content) { return strdup("mapped"); }
void del(void *content) { free(content); }
int main() {
    t_list *lst = ft_lstnew(strdup("a"));
    t_list *new = ft_lstmap(lst, map, del);
    if (!new || strcmp(new->content, "mapped")) {
        ft_lstclear(&lst, del);
        ft_lstclear(&new, del);
        return 1;
    }
    ft_lstclear(&lst, del);
    ft_lstclear(&new, del);
    return 0;
}'
    run_memory_test "ft_lstmap" "test_lstmap.c" "libft.a"
}

# =========================================#
# Tests FT_PRINTF						   #
# =========================================#

test_printf() {
    print_header "TESTING FT_PRINTF"
    
    # Vérification des fichiers sans forcer la lib .a
    if ! check_required_files "printf" "Makefile" "ft_printf.h" "ft_printf.c"; then
        echo -e "${YELLOW}Attempting to compile anyway...${NC}"
        make re >/dev/null 2>&1
    fi

    # Vérifier si la bibliothèque a été créée
    if [ ! -f "libftprintf.a" ]; then
        echo -e "${YELLOW}libftprintf.a not found, trying to compile...${NC}"
        make re >/dev/null 2>&1
        if [ ! -f "libftprintf.a" ]; then
            echo -e "${RED}Error: libftprintf.a not found after compilation${NC}"
            return 1
        fi
    fi

    # Tests standards
    test_printf_basic
    test_printf_format
    test_printf_edge
    
    # Tests avancés
    test_printf_memory
    test_printf_performance
}

test_printf_basic() {
    print_header "Testing Basic printf"

    create_test_file "test_printf_basic.c" '
#include "ft_printf.h"
int main() {
    int count = ft_printf("Hello %s!", "world");
    return (count != 12);
}'
    run_single_test "Basic string" "test_printf_basic.c" "-L. -lftprintf"
}

test_printf_format() {
    print_header "Testing Format Specifiers"

    create_test_file "test_printf_format.c" '
#include "ft_printf.h"
int main() {
    int c = ft_printf("Char: %c\\nString: %s\\nPointer: %p\\n", '\''A'\'', "test", (void *)0x1234);
    return (c <= 0);
}'
    run_single_test "Format specifiers" "test_printf_format.c" "-L. -lftprintf"
}

test_printf_edge() {
    print_header "Testing Edge Cases"

    create_test_file "test_printf_edge.c" '
#include "ft_printf.h"
int main() {
    ft_printf("%%");
    ft_printf("%s", "(null)");
    return 0;
}'
    run_single_test "Edge cases" "test_printf_edge.c" "-L. -lftprintf"
}

test_printf_memory() {
    print_header "Testing Memory Usage"

    create_test_file "test_printf_mem.c" '
#include "ft_printf.h"
int main() {
    char *s = "memory test";
    ft_printf("String: %s\\nCount: %d\\nHex: %x\\n", s, 42, 255);
    return 0;
}'
    run_single_test "Memory check" "test_printf_mem.c" "-L. -lftprintf" true
}

test_printf_performance() {
    print_header "Testing Performance"

    create_test_file "test_printf_perf.c" '
#include "ft_printf.h"
#include <time.h>
#define ITER 10000
int main() {
    clock_t start = clock();
    for (int i = 0; i < ITER; i++) {
        ft_printf("Iter %d: %s %x %p\\n", i, "test", i, (void *)(long)i);
    }
    clock_t end = clock();
    double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    ft_printf("Completed %d iterations in %.3f seconds\\n", ITER, elapsed);
    return 0;
}'
    run_single_test "Performance" "test_printf_perf.c" "-L. -lftprintf"
}

# =========================================
# Fonctions supplémentaires
# =========================================
check_required_files() {
    local project=$1
    shift
    local missing=0

    print_header "Checking $project required files"
    
    for file in "$@"; do
        print_test "Checking $file"
        if [ -f "$file" ] || [ -f "includes/$file" ]; then
            print_ok
        else
            print_fail
            missing=$((missing+1))
        fi
    done

    [ $missing -gt 0 ] && echo -e "${YELLOW}$missing files missing${NC}" >> $LOG_FILE
    return $missing
}

# =========================================
# Tests GNL
# =========================================
test_gnl() {
    print_header "TESTING GET_NEXT_LINE"
    
    check_required_files "gnl" "Makefile" "get_next_line.h" "get_next_line.c" "get_next_line_utils.c" || return

    # Tests avec différentes tailles de buffer
    for size in $BUFFER_SIZES; do
        print_test "Compiling with BUFFER_SIZE=$size"
        make re CFLAGS="-D BUFFER_SIZE=$size" >/dev/null 2>"$TEST_DIR/make_error.txt"
        [ $? -eq 0 ] && print_ok || print_fail "Compilation failed"

        test_gnl_basic $size
        test_gnl_advanced $size
        test_gnl_performance $size
    done

    # Tests avancés
    test_gnl_memory
    test_gnl_fuzzing
}

test_gnl_basic() {
    local size=$1
    print_header "Testing Basic Functionality (BUFFER_SIZE=$size)"

    echo -e "line1\nline2\nline3" > "$TEST_DIR/test_file.txt"

    create_test_file "test_gnl_basic.c" "
#include \"get_next_line.h\"
#include <fcntl.h>
int main() {
    int fd = open(\"$TEST_DIR/test_file.txt\", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    if (!line || strcmp(line, \"line1\n\") != 0) return 1;
    free(line);
    
    line = get_next_line(fd);
    if (!line || strcmp(line, \"line2\n\") != 0) return 2;
    free(line);
    
    close(fd);
    return 0;
}"
    run_single_test "GNL basic" "test_gnl_basic.c" "-L. -lgnl"
}

test_gnl_advanced() {
    local size=$1
    print_header "Testing Advanced Cases (BUFFER_SIZE=$size)"

    echo -n "no_newline" > "$TEST_DIR/test_file2.txt"

    create_test_file "test_gnl_adv.c" "
#include \"get_next_line.h\"
#include <fcntl.h>
int main() {
    int fd = open(\"$TEST_DIR/test_file2.txt\", O_RDONLY);
    char *line = get_next_line(fd);
    if (!line || strcmp(line, \"no_newline\") != 0) return 1;
    free(line);
    close(fd);
    return 0;
}"
    run_single_test "GNL no newline" "test_gnl_adv.c" "-L. -lgnl"
}

test_gnl_performance() {
    local size=$1
    print_header "Performance Testing (BUFFER_SIZE=$size)"

    # Créer un gros fichier de test
    dd if=/dev/urandom of="$TEST_DIR/bigfile.txt" bs=1K count=100 2>/dev/null

    create_test_file "perf_gnl.c" "
#include \"get_next_line.h\"
#include <fcntl.h>
int main() {
    int fd = open(\"$TEST_DIR/bigfile.txt\", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd))) free(line);
    close(fd);
    return 0;
}"
    run_perf_test "GNL performance" "perf_gnl.c" "-L. -lgnl" 10
}

test_gnl_memory() {
    print_header "GNL Memory Tests"

    echo -e "test\nmemory\nleak" > "$TEST_DIR/mem_test.txt"

    create_test_file "mem_gnl.c" "
#include \"get_next_line.h\"
#include <fcntl.h>
int main() {
    int fd = open(\"$TEST_DIR/mem_test.txt\", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd))) free(line);
    close(fd);
    return 0;
}"
    run_memory_test "GNL memory" "mem_gnl.c" "-L. -lgnl"
}

test_gnl_fuzzing() {
    print_header "GNL Fuzzing Tests"

    # Créer plusieurs fichiers de test aléatoires
    for i in {1..5}; do
        head -c 500 /dev/urandom | tr -dc 'a-zA-Z0-9\n' > "$TEST_DIR/fuzz_$i.txt"
    done

    create_test_file "fuzz_gnl.c" "
#include \"get_next_line.h\"
#include <fcntl.h>
int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int fd = open(argv[1], O_RDONLY);
    char *line;
    while ((line = get_next_line(fd))) free(line);
    close(fd);
    return 0;
}"
    
    print_test "GNL fuzzing (5 files)"
    local fails=0
    for i in {1..5}; do
        "$TEST_DIR/fuzz_gnl" "$TEST_DIR/fuzz_$i.txt" >/dev/null 2>&1
        [ $? -ne 0 ] && fails=$((fails+1))
    done
    
    [ $fails -eq 0 ] && print_ok || print_fail "0 failures" "$fails files failed"
}

# =========================================
# Fonctions du menu
# =========================================
check_project_structure() {
    echo -e "${CYAN}"
    echo "Select project to check:"
    echo "1. Libft"
    echo "2. ft_printf"
    echo "3. get_next_line"
    echo -e "${NC}"
    
    read -p "Your choice: " project_choice
    case $project_choice in
        1) check_required_files "libft" "Makefile" "libft.h" "ft_isalpha.c" "libft.a" ;;
        2) check_required_files "printf" "Makefile" "ft_printf.h" "ft_printf.c" "libftprintf.a" ;;
        3) check_required_files "gnl" "Makefile" "get_next_line.h" "get_next_line.c" "get_next_line_utils.c" ;;
        *) echo -e "${RED}Invalid choice${NC}" ;;
    esac
}

run_performance_tests() {
    print_header "RUNNING ALL PERFORMANCE TESTS"
    
    # Libft
    if check_required_files "libft" "Makefile" "libft.h"; then
        make re >/dev/null 2>&1
        test_libft_performance
    fi
    
    # ft_printf
    if check_required_files "printf" "Makefile" "ft_printf.h"; then
        make re >/dev/null 2>&1
        test_printf_perf
    fi
    
    # GNL
    if check_required_files "gnl" "Makefile" "get_next_line.h"; then
        for size in $BUFFER_SIZES; do
            make re CFLAGS="-D BUFFER_SIZE=$size" >/dev/null 2>&1
            test_gnl_performance $size
        done
    fi
}

# =========================================
# Menu principal
# =========================================
main_menu() {
    echo -n "" > $LOG_FILE  # Reset log file
    while true; do
        clear
        echo -e "${CYAN}"
        echo "========================================"
        echo "  42 PROJECT TESTER - COMPLETE VERSION  "
        echo "========================================"
        echo -e "${NC}"
        echo "1. Test Libft (complet)"
        echo "2. Test ft_printf (complet)"
        echo "3. Test get_next_line (complet)"
        echo "4. Run all tests with valgrind"
        echo "5. Run performance tests only"
        echo "6. Check project structure"
        echo "0. Exit"
        echo ""
        read -p "Select an option: " choice

        case $choice in
            1) test_libft ;;
            2) test_printf ;;
            3) test_gnl ;;
            4) VALGRIND_LEAKS="$VALGRIND_LEAKS --quiet" test_libft; test_printf; test_gnl ;;
            5) run_performance_tests ;;
            6) check_project_structure ;;
            0) exit 0 ;;
            *) echo -e "${RED}Invalid option${NC}" ;;
        esac

        read -p "Press enter to continue..."
    done
}

# =========================================
# Point d'entrée
# =========================================
trap cleanup EXIT
main_menu
