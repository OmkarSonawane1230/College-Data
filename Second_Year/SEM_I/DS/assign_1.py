# Initialize empty lists for each sport
cricket = []
badminton = []
football = []

# Input the number of students who play cricket and their names
a = int(input("Enter the number of students who play cricket: "))
for i in range(a):
    name = input("Enter the name: ")
    cricket.append(name)
print(cricket, "\n")

# Input the number of students who play badminton and their names
b = int(input("Enter the number of students who play badminton: "))
for j in range(b):
    name = input("Enter the name: ")
    badminton.append(name)
print(badminton, "\n")

# Input the number of students who play football and their names
c = int(input("Enter the number of students who play football: "))
for k in range(c):
    name = input("Enter the name: ")
    football.append(name)
print(football, "\n")

# Function to find players who play both cricket and badminton
def cri_bad(cricket, badminton):
    new_list = [player for player in cricket if player in badminton]
    print("\n1) Players who play both cricket and badminton:", new_list, "\n")

cri_bad(cricket, badminton)

# Function to find players who play only one of cricket or badminton
def second(cricket, badminton):
    new_list = []
    # Players who play only cricket
    only_cricket = [player for player in cricket if player not in badminton]
    # Players who play only badminton
    only_badminton = [player for player in badminton if player not in cricket]
    new_list.extend(only_cricket)
    new_list.extend(only_badminton)
    print("\n2) Players who play only cricket or badminton:", new_list)

second(cricket, badminton)

# Function to find players who play neither cricket nor badminton
def third(cricket, badminton, football):
    new_list = [player for player in football if player not in cricket and player not in badminton]
    print("\n3) Students who play neither cricket nor badminton:", new_list)

third(cricket, badminton, football)

# Function to find players who play only cricket and football but not badminton
def fourth(cricket, badminton, football):
    only_cricket_football = [player for player in cricket if player in football and player not in badminton]
    print("\n4) Students who play only cricket and football but not badminton:", only_cricket_football)

fourth(cricket, badminton, football)
