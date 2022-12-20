#!/bin/bash

# Set the directory to search
search_dir="containers_test/logs"

# Initialize a counter for the number of files with "ft" in the name and containing "hello"
counter=0

# Go through all the files in the search directory
for file in "$search_dir"/*; do
  # Extract the file name from the file path
  filename=$(basename "$file")
  # Check if the file name contains "ft" and the file contents contain "hello"
  if [[ "$filename" =~ "ft" ]] && ! grep -q "All heap blocks were freed -- no leaks are possible" "$file"; then
    # If "ft" is found in the file name and "hello" is found in the file contents, increment the counter
    ((counter++))
  fi
done

# Echo the final count of files with "ft" in the name and containing "hello"
echo "Number of files with 'ft' in the name and containing 'hello': $counter"