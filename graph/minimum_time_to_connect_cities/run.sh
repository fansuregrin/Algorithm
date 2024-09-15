#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

samples_in_file="samples.in.txt"
samples_out_file="samples.out.txt"
program="./a.out"
delim="---"

if [[ ! -e "${samples_in_file}" ]]; then
    echo -e ${RED}"${samples_in_file}" not exits!${NC}
fi
if [[ ! -e "${samples_out_file}" ]]; then
    echo -e ${RED}"${samples_out_file}" not exits!${NC}
fi

in_samples=()
sample=""
while IFS= read -r line; do
    if [[ "${line}" == "${delim}" ]]; then
        in_samples+=("${sample}")
        sample=""
    else
        sample+="${line}"$'\n'
    fi
done < "${samples_in_file}"
in_samples+=("${sample}")

out_samples=()
sample=""
while IFS= read -r line; do
    if [[ "${line}" == "${delim}" ]]; then
        out_samples+=("${sample}")
        sample=""
    else
        sample+="${line}"$'\n'
    fi
done < "${samples_out_file}"
out_samples+=("${sample}")

declare -i passed=0
declare -i len=${#in_samples[@]}
for ((i=0; i<${len}; i++)); do
    test_out=$(echo -n "${in_samples[${i}]}" | ${program})$'\n'
    if [[ "${test_out}" != "${out_samples[${i}]}" ]]; then
        echo -e "${RED}WRONG ANSWER${NC}"
        echo -en "sample: \n${in_samples[${i}]}"
        echo -en "${GREEN}answer: \n${out_samples[${i}]}${NC}"
        echo -en "${RED}yours: \n${test_out}${NC}"
    else
        passed+=1
    fi
done

declare -i failed=`expr ${len} - ${passed}`
rate=$(echo "scale=3; ${passed}/${len}*100" | bc)
echo -e "=========================="
echo -e "passed rate: ${rate}%"
echo -e "total samples: ${len}"
echo -e "${GREEN}passed: ${passed}${NC}"
echo -e "${RED}failed: ${failed}${NC}"
echo -e "=========================="