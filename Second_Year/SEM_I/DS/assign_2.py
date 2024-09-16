"""

Program Name: Assignment No. 2
Author: Omkar Sonawane
Description: This program is implementation of Assignment No. 2.

"""

# declaration of marks variable
marks = []

def accept_num():
    n = int(input("Enter the total number of students: "))

    for i in range(n):
        x = input(f"Enter the marks scored in FDS for student {i+1}: ")
        
        try:
            x = -1 if x == "AB" else int(x)
        except ValueError:
            print("Invalid input. Please enter a number or 'AB'.")

        marks.append(x)
        print(marks)

    print("Marks accepted and stored successfully.")

def display_marks():
    print("\nMarks scored in FDS:")
    for i in range(len(marks)):
        val = "AB" if marks[i] == -1 else marks[i]
        print(f"\tStudent {i + 1}: {val}")
    print("\n")

def average_score_of_class():
    valid_marks = [mark for mark in marks if mark != -1]
    avg = sum(valid_marks) / len(valid_marks) if valid_marks else 0

    display_marks()
    print(f"\nAverage score of the class is {avg:.2f}\n")


def find_lowest_and_highest_class():
    max_score = -1
    min_score = 31
    max_ind = -1
    min_ind = -1

    for i in range(len(marks)):
        if marks[i] != -1:
            if marks[i] > max_score:
                max_score = marks[i]
                max_ind = i

            if marks[i] < min_score:
                min_score = marks[i]
                min_ind = i
                
    display_marks()
    print(f"Highest mark scored is {max_score} by student {max_ind+1}")
    print(f"Lowest mark scored is {min_score} by student {min_ind+1}")

def count_absent_students():
    count = marks.count(-1)
    display_marks()
    print(f"\tAbsent Student Count = {count}")

def display_marks_with_highest_frequency():
    frequency = {}
    
    # Count frequencies of valid marks
    for mark in marks:
        if mark != -1:
            frequency[mark] = frequency.get(mark, 0) + 1
    
    # Find the mark with the highest frequency
    max_mark, max_freq = max(frequency.items(), key=lambda item: item[1])
    
    display_marks()
    print(f"\nMarks with highest frequency: {max_mark} ({max_freq} times)")

def main():
    while True:
        print("1. Accept the marks")
        print("2. Average score of the class")
        print("3. Highest and Lowest score in the class")
        print("4. The count of the students who were absent")
        print("5. Marks with highest frequency")
        print("6. Exit")

        ch = int(input("Enter your choice: "))

        match (ch):
            case 1:
                accept_num()
                display_marks()
            case 2:
                average_score_of_class()
            case 3:
                find_lowest_and_highest_class()
            case 4:
                count_absent_students()
            case 5:
                display_marks_with_highest_frequency()
            case 6:
                print("End of Program")
                break
            case _:
                print("Wrong choice entered! Try again.")

# Calling Main Function
main()