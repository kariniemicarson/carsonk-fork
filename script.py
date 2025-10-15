# input_file = "us_postal_codes.csv"
# output_file = "us_postal_codes_length_indicated_header_record.txt"

input_file = "us_postal_codes_ROWS_RANDOMIZED.csv"
output_file = "us_postal_codes_ROWS_RANDOMIZED_length_indicated_header_record.txt"

with open(input_file, "r", encoding="utf-8") as infile, open(output_file, "w", encoding="utf-8") as outfile:
    for line in infile:
        line = line.rstrip("\n")
        length = len(line)
        outfile.write(f"{length}{line}\n")
