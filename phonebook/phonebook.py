import csv

name = input("name: ")
number = input("number: ")

with open("phonebook.csv", "a") as file:

    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerows({"name": name, "number": number})
    