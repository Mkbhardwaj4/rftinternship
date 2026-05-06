#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
protected:
    int id;
    string title;
    bool isIssued;
    static int totalAvailableItems; 

public:
    Item(int id, string title) : id(id), title(title), isIssued(false) {
        totalAvailableItems++;
    }

    virtual void displayDetails() {
        cout << "ID: " << id << " | Title: " << title 
             << " | Status: " << (isIssued ? "Issued" : "Available") << endl;
    }

    void issueItem() {
        if (!isIssued) {
            isIssued = true;
            totalAvailableItems--;
            cout << "Item '" << title << "' has been issued successfully." << endl;
        } else {
            cout << "Item is already issued." << endl;
        }
    }

    void returnItem(int daysLate = 0) {
        if (isIssued) {
            isIssued = false;
            totalAvailableItems++;
            cout << "Item '" << title << "' returned.";
            
           
            if (daysLate > 0) {
                cout << " Fine incurred: $" << (daysLate * 2);
            }
            cout << endl;
        } else {
            cout << "Item was not issued." << endl;
        }
    }

    static int getTotalCount() {
        return totalAvailableItems;
    }
};

int Item::totalAvailableItems = 0;


class Book : public Item {
private:
    string author;

public:
    Book(int id, string title, string author) : Item(id, title), author(author) {}

    void displayDetails() override {
        cout << "[BOOK] ";
        Item::displayDetails();
        cout << "       Author: " << author << endl;
    }
};


class Magazine : public Item {
private:
    int issueNumber;

public:
    Magazine(int id, string title, int issueNum) : Item(id, title), issueNumber(issueNum) {}

    void displayDetails() override {
        cout << "[MAGAZINE] ";
        Item::displayDetails();
        cout << "           Issue No: " << issueNumber << endl;
    }
};


int main() {
    cout << "--- Library Management System ---\n" << endl;


    Book b1(101, "The Great Gatsby", "F. Scott Fitzgerald");
    Magazine m1(501, "National Geographic", 202);


    cout << "Initial available items: " << Item::getTotalCount() << endl;
    cout << "-----------------------------------" << endl;

    
    b1.displayDetails();
    m1.displayDetails();
    cout << endl;


    b1.issueItem();
    cout << "Available items now: " << Item::getTotalCount() << "\n" << endl;


    b1.returnItem(5);
    cout << "Available items now: " << Item::getTotalCount() << endl;

    return 0;
}