
def main():
    card_number = input("Credit Card Number: ")
    if len(card_number) == 15:
        if card_number[0] == '3':
            if card_number[1] == '4' or card_number[1] == '7':
                if algorithm(card_number):
                    print("AMEX")
                else:
                    print("INVALID")

    elif len(card_number) == 13 or len(card_number) == 16:
        if card_number[0] == '4':
            if algorithm(card_number):
                print("VISA")
            else:
                print("INVALID")

        elif card_number[0] == '5':
            if card_number[1] == '1' or card_number[1] == '2' or card_number[1] == '3' or card_number[1] == '4' or card_number[1] == '5':
                if algorithm(card_number):
                    print("MASTERCARD")
                else:
                    print("INVALID")
    else:
        print("INVALID")


def algorithm(card_number):
    total = 0
    for i in range(len(card_number) - 2, -1, -2):
        if int(card_number[i]) * 2 < 10:
            total += int(card_number[i]) * 2
        else:
            digit1 = int(int(card_number[i]) * 2 / 10)
            digit2 = int(card_number[i]) * 2 % 10
            total += digit1 + digit2
    for j in range(len(card_number) - 1, -1, -2):
        total += int(card_number[j])
    if total % 10 == 0:
        return True
    return False


main()