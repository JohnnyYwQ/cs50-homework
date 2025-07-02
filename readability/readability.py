text = input("Text: ")

def num_word(text):
    return len(text.split())

def num_sen(text):
    num_sen = 0
    for char in text:
        if char in {".", "!", "?"}:
            num_sen += 1
    return num_sen

def num_let(text):
    num_let = 0
    for char in text:
        if char.isalpha():
            num_let += 1
    return num_let
    

def read_grade(num_word, num_sen, num_let):
    L = float(num_let / num_word) * 100
    S = float(num_sen / num_word) * 100
    level = 0.0588 * L - 0.296 * S - 15.8
    if level < 1:
        print("Before Grade 1")
    elif 1 <= level <= 16:
         print(f"Grade {round(level)}") 
    else:
        print("Grade 16+")


def main():
    read_grade(num_word(text), num_sen(text), num_let(text))

if __name__ == "__main__":
    main()

