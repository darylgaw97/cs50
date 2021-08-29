import cs50

height = cs50.get_int("Height: ")
while height < 1 or height > 8:
    height = cs50.get_int("Height: ")
for i in range(height, 0, -1):
    print(" " * (i - 1), end="")
    print("#" * (height + 1 - i))