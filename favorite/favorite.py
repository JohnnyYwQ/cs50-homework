import csv

with open("large.csv") as file:
    reader_dict = csv.DictReader(file)
    reader = csv.reader(file)
    people = list(reader)

    count_list = []

    for i in range(1, len(people)):
        person = people[i][0]
        num = 0
        for j in range(1, len(people[0])):
            num += int(people[i][j])
        count_list.append([person, num])

    print(count_list)
    sort_list = sorted(count_list, key=lambda x:x[1])
    print(sort_list)
        
    # for person in sorted(count, key=count.get):
    #         print(f"{person}: {count[person]}")
            
            





        
            





        