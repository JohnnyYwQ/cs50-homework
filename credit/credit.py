# input number
def get_number():
    number = input("Number: ")
    if number.isdigit():
        return number
    else:
        return get_number()   

# check calculate number
def check_legal(number):
    digits_odd = number[-2::-2]
    count = 0
    for digit in digits_odd:
        if int(digit) * 2 > 9:
            count += int(digit) * 2 - 9
        else:
            count += int(digit) * 2
    digits_even = number[-1::-2]
    for digit in digits_even:
        count += int(digit)
    if count % 10 == 0:
        return True
    else:
        return False
    
def check_number(number):
    # check length of number
    if not check_legal(number):
        print("INVALID")
        return 
    
    lenth = len(number)
    if lenth == 15 and (number[:2] in {"34", "37"}):
        print("AMEX")
    elif lenth == 13 and number[0] == "4":
        print("VISA")
    elif lenth == 16:
        if 51 <= int(number[:2]) <= 55:
            print("MASTERCARD")
        elif number[0] == "4":
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

check_number(get_number())
