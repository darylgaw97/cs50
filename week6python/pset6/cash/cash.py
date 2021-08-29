import cs50

change = cs50.get_float("Change: ")
while change < 0:
    change = cs50.get_float("Change owed: ")
change = round(change * 100)

coins = 0
while change >= 25:
    change -= 25
    coins += 1
while change >= 10:
    change -= 10
    coins += 1
while change >= 5:
    change -= 5
    coins += 1
while change >= 1:
    change -= 1
    coins += 1
print(coins)