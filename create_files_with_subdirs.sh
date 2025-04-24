#!/bin/bash

# Get current date and time in the format YYYYMMDD_HHMMSS
main_dir=$(date +"%Y%m%d_%H%M%S")

# Create the main directory
mkdir "$main_dir"

# Array of 10 programming languages
languages=("Python" "Java" "C" "C++" "JavaScript" "Ruby" "Go" "Rust" "Swift" "Kotlin")

# Loop to create subdirectories and text files
for i in {1..10}
do
  sub_dir="$main_dir/file10$i"
  mkdir "$sub_dir"

  file_name="$sub_dir/tuser50$i.txt"
  echo "${languages[$((i-1))]}" > "$file_name"
done

echo "Directories and files created successfully in $main_dir."
