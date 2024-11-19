#!/bin/bash

PROGRAM_PATH="./cub3D"

MAPS_DIR="./maps/invalid"

GREEN='\033[1;32m'
RED='\033[1;31m'
NC='\033[0m' # No Color

passed_tests=0
total_tests=0
failed_maps=()

for map_file in "$MAPS_DIR"/*; do
    if [ -f "$map_file" ]; then
        total_tests=$((total_tests + 1))
        map_name=$(basename "$map_file")
        echo "Testing with map: $map_name"
        output=$("$PROGRAM_PATH" "$map_file" 2>&1) # Capture both stdout and stderr
        if echo "$output" | grep -q "Error"; then
            echo -e "$output"
            echo -e "${GREEN}[OK]${NC}"
            passed_tests=$((passed_tests + 1))
        else
            echo -e "${RED}Output:${NC}"
            echo "$output"
            echo -e "${RED}[This is not OK]${NC}"
            failed_maps+=("$map_name")
        fi
        echo "--------------------------------"
    else
        echo "No files found in $MAPS_DIR"
        exit 1
    fi
done

echo -e "${GREEN}${passed_tests}/${total_tests} tests passed.${NC}"

if [ ${#failed_maps[@]} -ne 0 ]; then
    echo -e "${RED}The following maps didn't pass:${NC}"
    for failed_map in "${failed_maps[@]}"; do
        echo -e "${RED}- $failed_map${NC}"
    done
else
    echo -e "${GREEN}All maps passed the test. Congrats!${NC}"
fi
