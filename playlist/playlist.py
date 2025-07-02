import cs50
import csv

def main():
    min_tempo = cs50.get_int("Minimum Tempo: ")
    max_tempo = cs50.get_int("Maximum Tempo: ")

    playlist = []
    filename = "2018_top100.csv"
    with open(filename) as file:
        file_reader = csv.DictReader(file)


main()
