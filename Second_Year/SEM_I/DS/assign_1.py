"""

Program Name: Assignment No. 1
Author: Omkar Sonawane
Description: This program is implementation of Assignment No. 1.

"""

# Initialize empty lists for each sport
cricket = []
badminton = []
football = []

a = int(input("Enter the number of students who play cricket: "))
for i in range(a):
    name = input("Enter the name: ")
    cricket.append(name)

print("Cricket players:", cricket, "\n")

b = int(input("Enter the number of students who play badminton: "))
for j in range(b):
    name = input("Enter the name: ")
    badminton.append(name)

print("Badminton players:", badminton, "\n")

c = int(input("Enter the number of students who play football: "))
for k in range(c):
    name = input("Enter the name: ")
    football.append(name)

print("Football players:", football, "\n")

# players who play both cricket and badminton
def cri_bad(cricket_list, badminton_list):
    new_list = []
    
    for player in cricket_list:
        if player in badminton_list:
            new_list.append(player)

    print("\n1) Players who play both cricket and badminton:", new_list)

cri_bad(cricket, badminton)

# players who play only one of cricket or badminton
def second(cricket_list, badminton_list):
    new_list = []

    for player in cricket_list:
        if player not in badminton_list:
            new_list.append(player)

    for player in badminton_list:
        if player not in cricket_list:
            new_list.append(player)
    
    print("\n2) Players who play only cricket or only badminton:", new_list)

second(cricket, badminton)

# players who play neither cricket nor badminton
def third(cricket_list, badminton_list, football_list):
    new_list = []

    for player in football_list:
        if player not in cricket_list and player not in badminton_list:
            new_list.append(player)

    print("\n3) Students who play neither cricket nor badminton:", new_list)

third(cricket, badminton, football)

# players who play only cricket and football but not badminton
def fourth(cricket_list, badminton_list, football_list):
    new_list = []

    for player in cricket_list:
        if player in football_list and player not in badminton_list:
            new_list.append(player)

    print("\n4) Students who play only cricket and football but not badminton:", new_list)

fourth(cricket, badminton, football)
