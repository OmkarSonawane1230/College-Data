// ======================================================================
// Name        : assign_6.cpp
// Author      : Omkar Sonawane
// Description : This program implements sorting and searching operations
//               using STL on Item records.
// ======================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class ItemRecord {
    static int code;

public:
    string itemCode;
    string itemName;
    int cost, quantity;
    string category;

    ItemRecord() : itemCode("ITEM" + to_string(code)) {
        code++;
    }

    friend istream& operator>>(istream& input, ItemRecord& item) {
        input >> item.itemName >> item.cost 
              >> item.quantity >> item.category;
        return input;
    }

    bool operator==(const ItemRecord& item) const {
        return itemCode == item.itemCode; // Compare based on itemCode number
    }

    bool operator<(const ItemRecord& item) const {
        return category < item.category; // Compare based on itemName
    }
};

int ItemRecord::code = 10;

vector<ItemRecord> Items;

void print(const ItemRecord &item);
void display();
void insert();
void search();
void dlt();

int main() {
    int ch;
    do {
        cout << "\n* * * * * Menu * * * * *";
        cout << "\n1. Insert Item Record";
        cout << "\n2. Display Item Records";
        cout << "\n3. Search Item Record";
        cout << "\n4. Sort Item Records";
        cout << "\n5. Delete Item Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: sort(Items.begin(), Items.end());
                    cout << "\nSorted on Name:\n"; display(); break;
            case 5: dlt(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }

    } while(ch != 6);
    return 0;
}

void insert() {
    ItemRecord item;
    cout << "\nEnter Details [ Name Cost Quantity Category ]: ";
    cin >> item;
    Items.push_back(item);
}

string formatWithPadding(const string& str, int width) {
    return str + string(width > str.length() ? width - str.length() : 0, ' ');
}

void display() {
    cout << "\nItem Code   Name                     Cost      Quantity  Item Category" << endl;
    cout << string(70, '-') << endl;

    for_each(Items.begin(), Items.end(), print);
}

void print(const ItemRecord &item) {
    cout << formatWithPadding(item.itemCode, 12)
         << formatWithPadding(item.itemName, 25)
         << formatWithPadding(to_string(item.cost), 10)
         << formatWithPadding(to_string(item.quantity), 10)
         << item.category << endl;
}

void search() {
    ItemRecord item;
    cout << "\nEnter Item Code to search: ";
    cin >> item.itemCode;
    
    vector<ItemRecord>::iterator p = find(Items.begin(), Items.end(), item);
    if(p == Items.end()) {
        cout << "\nNot found!!!\n";
    } else {
        cout << "\nFound!!!\n";
        print(*p); // Print found Item
    }
}

void dlt() {
    ItemRecord item;
    cout << "\nEnter Item Code to delete: ";
    cin >> item.itemCode;

    vector<ItemRecord>::iterator p = find(Items.begin(), Items.end(), item);

    if(p == Items.end()) {
        cout << "\nNot found!!!\n";
    } else {
        Items.erase(p);
        cout << "\nDeleted!!!\n";
    }
}



// Sample inputs

/*

SamsungGalaxyS21 79999 150 Electronics
SonyWH-1000XM4 29999 200 Electronics
DellXPS13 99999 75 Electronics
LGOLED55CXPUA 199999 50 Electronics
AppleAirPodsPro 24999 300 Electronics
NikeAirMax270 8999 120 Clothing
Levis501OriginalJeans 5999 200 Clothing
AdidasUltraboost 17999 150 Clothing
HMCasualShirt 2499 250 Clothing
TheNorthFaceJacket 8999 80 Clothing
PhilipsAirFryer 12999 100 HomeAppliances
DysonV11Vacuum 39999 60 HomeAppliances
LGRefrigerator 54999 40 HomeAppliances
SamsungWashingMachine 29999 70 HomeAppliances
InstantPotDuo 9999 150 HomeAppliances
WilsonTennisRacket 8999 200 SportsEquipment
AdidasSoccerBall 2499 300 SportsEquipment
FitbitCharge5 14999 120 SportsEquipment
CallawayGolfClubsSet 49999 30 SportsEquipment
NorthFaceHikingBackpack 7999 80 SportsEquipment
MACLipstick 2499 250 BeautyProducts
EsteeLauderFoundation 3999 150 BeautyProducts
OlayMoisturizer 1499 200 BeautyProducts
SephoraEyeshadowPalette 5999 100 BeautyProducts
L'OrealShampoo 999 500 BeautyProducts


*/