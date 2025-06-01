#!/bin/bash

generate_unique_numbers() {
  local count=$1
  local min=-10000
  local max=10000

  seq "$min" "$max" | awk 'BEGIN {srand()} {print rand(), $0}' \
    | sort -n | cut -d' ' -f2 | head -n "$count"
}

run_single_test() {
  local values="$1"
  local arg=$(echo "$values" | tr '\n' ' ')
  local result
  local instruction_count

  result=$(./push_swap $arg | tee /tmp/push_swap_output.txt | ./checker_linux $arg)
  instruction_count=$(wc -l < /tmp/push_swap_output.txt)

  echo "$instruction_count;$result"
}

run_tests_for_size() {
  local COUNT=$1
  local TESTS=$2
  local total=0
  local max=0
  local min=999999
  local ok_count=0
  local ko_count=0

  echo -e "\n============================"
  echo -e "🔢 Taille : $COUNT éléments"
  echo -e "🧪 Tests : $TESTS"
  echo -e "============================"

  for i in $(seq 1 $TESTS); do
    values=$(generate_unique_numbers "$COUNT")
    output=$(run_single_test "$values")
    instr=$(echo "$output" | cut -d';' -f1)
    result=$(echo "$output" | cut -d';' -f2)

    if [[ "$result" == "OK" ]]; then
      ((ok_count++))
      color="\033[1;32m"
    else
      ((ko_count++))
      color="\033[1;31m"
    fi

    total=$((total + instr))
    (( instr > max )) && max=$instr
    (( instr < min )) && min=$instr

    echo -e "${color}Test $i : $result - $instr instructions\033[0m"
  done

  avg=$((total / TESTS))
  echo -e "\n📊 Résumé pour $COUNT éléments :"
  echo -e "✅ OK : $ok_count / ❌ KO : $ko_count"
  echo -e "📈 Min : $min | Max : $max | Moyenne : $avg"
}

# ------------------------
# CONFIGURATION
run_tests_for_size 3 5
run_tests_for_size 5 5
run_tests_for_size 100 5
run_tests_for_size 500 3
# ------------------------

