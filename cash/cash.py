def get_change():
    while True:
        try:
            change = float(input("change: "))
            if change > 0:
                return change * 100
        except ValueError:
            continue
    
def cash(cents):
    count = 0
    for coin in [25, 10, 5, 1]:
        count += cents // coin
        cents %= coin
    print(int(count))

cash(get_change())
        