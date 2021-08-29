import sys
import csv


# checking for correct command line input
if not len(sys.argv) == 3:
    sys.exit("Usage: python dna.py <databases/*.csv> <sequences/*.txt>")

# load database
with open(sys.argv[1]) as inputfile:
    reader = csv.DictReader(inputfile)
    person = []
    for line in reader:
        person.append(line)

# load STR patterns
with open(sys.argv[1]) as inputfile:
    reader = csv.reader(inputfile)
    patterns = []
    for line in reader:
        for i in range(1, len(line)):
            tempdict = {}
            tempdict["name"] = line[i]
            tempdict["repeats"] = 0
            patterns.append(tempdict)
        break

# load sequence
with open(sys.argv[2]) as inputfile:
    sequence = inputfile.read()

# iterating through each possible STR pattern type
for i in range(len(patterns)):
    a = 0
    b = len(patterns[i]["name"])
    combo = 0
    longest = 0
    # scanning through characaters of sequence, keeping count of longest consecutive repeats and updating them into patterns[].
    while a < len(sequence) - b:
        # if match:
        if sequence[a:a + b] == patterns[i]["name"]:
            combo += 1
            a += b
        else:
            if combo > 0:
                if combo > longest:
                    longest = combo
                combo = 0
            elif combo == 0:
                a += 1
    patterns[i]["repeats"] = longest

# check if any individual in the database have DNA that matches the sample
for i in range(len(person)):
    matches = 0
    for j in range(len(patterns)):
        if person[i][patterns[j]["name"]] == str(patterns[j]["repeats"]):
            matches += 1
        else:
            break
    if matches == len(patterns):
        print(person[i]["name"])
        sys.exit()
print("No match")