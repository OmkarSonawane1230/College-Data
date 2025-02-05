class HashEntry:
    def __init__(self):
        self.name = None
        self.num = -1

    def insert(self, name, num):
        self.name = name
        self.num = num

    def collision(self):
        return self.name is not None

def hashOne(size, val):
    return val % size

def hashTwo(size, val):
    prime = size - 1
    while prime > 1:
        for i in range(2, int(prime ** 0.5) + 1):
            if prime % i == 0:
                break
        else:
            break
        prime -= 1

    return prime - (val % prime)

def finalHash(val, size, i):
    return (hashOne(size, val) + i * hashTwo(size, val)) % size

def stringToInt(strn):
    sum = 0
    for i in strn:
        sum += ord(i)
    return sum

class LinearProbing:
    # Function to handle linear probing
    def __init__(self, size):
        self.size = size
        self.HashTable = []
        for _ in range(size):
            self.HashTable.append(HashEntry())

    def insert(self):
        inputStr = input("Enter telephone NUMBER and NAME of client (separated by space):\t")
        inputVal = inputStr.split()

        if len(inputVal) != 2:
            print("\nPlease enter both telephone number and name.\n")
            return

        num, name = inputVal
        name2 = stringToInt(name)
        pos = hashOne(self.size, name2)

        i = 1
        while self.HashTable[pos].collision():
            pos = (pos + i) % self.size
            i += 1
        self.HashTable[pos].insert(name, num)
        print("\nInserted\n")

    def search(self):
        name = input("Enter name of the client: ")
        name2 = stringToInt(name)
        pos = hashOne(self.size, name2)

        i = 1
        while self.HashTable[pos].name != name:
            pos = (pos + i) % self.size
            i += 1
            if i == self.size + 1:
                break
        else:
            print("\nTelephone number of the client", name, "is", self.HashTable[pos].num, "\n")
            return
        print("\nClient not found.\n")

    def display(self):
        j = 0
        print("\nPos".ljust(5, " "), "Name".ljust(9, " "), "Value".ljust(6, " "))
        print("".ljust(5, "-"), "".ljust(9, "-"), "".ljust(6, "-"))
        for i in self.HashTable:
            n = "-" if (i.name is None) else i.name
            print(str(j).ljust(5, " "), str(n).ljust(9, " "), str(i.num).ljust(6, " "))
            j += 1

class DoubleHashing:
# Function to handle double hashing
    def __init__(self, size):
        self.size = size
        self.HashTable = []
        for _ in range(size):
            self.HashTable.append(HashEntry())

    def insert(self):
        inputStr = input("Enter telephone NUMBER and NAME of client (separated by space): ")
        inputVal = inputStr.split()

        if len(inputVal) != 2:
            print("\nPlease enter both telephone number and name.\n")
            return

        num, name = inputVal
        name2 = stringToInt(name)

        i = 0
        while True:
            pos = finalHash(name2, self.size, i)
            if self.HashTable[pos].collision():
                i += 1
            else:
                break
        self.HashTable[pos].insert(name, num)
        print("\nInserted\n")

    def search(self):
        name = input("Enter name of the client: ")
        name2 = stringToInt(name)

        i = 0
        while True:
            pos = finalHash(name2, self.size, i)
            if self.HashTable[pos].name != name:
                i += 1
            else:
                break
            if i == self.size:
                break
        print("\nTelephone number of client", name, "is", self.HashTable[pos].num, "\n")

    def display(self):
        j = 0
        print("\nPos".ljust(5, " "), "Name".ljust(9, " "), "Value".ljust(6, " "))
        print("".ljust(5, "-"), "".ljust(9, "-"), "".ljust(6, "-"))
        for i in self.HashTable:
            n = "-" if (i.name is None) else i.name
            print(str(j).ljust(5, " "), str(n).ljust(9, " "), str(i.num).ljust(6, " "))
            j += 1

def main():
# Main function with options
    tableSize = int(input("Enter size of hash table: "))
    method = None

    while True:
        print(" MAIN MENU ")
        print("1. Linear Probing")
        print("2. Double Hashing")
        print("3. Exit")
        optn = int(input("Choose an option (1-3): "))
        if optn == 1:
            method = LinearProbing(tableSize)
        elif optn == 2:
            method = DoubleHashing(tableSize)
        elif optn == 3:
            print("\n\n## END OF CODE\n")
            exit(1)
        else:
            print("Please choose a valid option (1-3).")
            continue
    
        while True:
            print("\n CHOOSE OPERATION (HASH TABLE) ")
            print("1. Insert")
            print("2. Search")
            print("3. Display")
            print("4. Return to previous menu")
            optn = int(input("Choose an option (1-4): "))
            if optn == 1:
                method.insert()
            elif optn == 2:
                method.search()
            elif optn == 3:
                method.display()
            elif optn == 4:
                break
            else:
                print("Please choose a valid option (1-4).")
                continue

main()