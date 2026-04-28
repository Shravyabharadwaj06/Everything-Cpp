#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}

    virtual void display() = 0;  // pure virtual (abstraction)
};
class Student : public Person {
    int booksIssued;

public:
    Student(string n, int i) : Person(n, i), booksIssued(0) {}

    void display() override {
        cout << "Student: " << name << " | ID: " << id << endl;
    }

    int getBooksIssued() { return booksIssued; }
    void issueBook() { booksIssued++; }
    void returnBook() { booksIssued--; }
};

class Librarian : public Person {
public:
    Librarian(string n, int i) : Person(n, i) {}

    void display() override {
        cout << "Librarian: " << name << " | ID: " << id << endl;
    }
};
class Book {
protected:
    string title;
    string author;
    int bookID;
    bool available;

public:
    Book(string t, string a, int id)
        : title(t), author(a), bookID(id), available(true) {}

    virtual void display() {
        cout << title << " by " << author 
             << " | ID: " << bookID
             << " | " << (available ? "Available" : "Issued") << endl;
    }

    bool isAvailable() { return available; }
    void issue() { available = false; }
    void returnBook() { available = true; }

    int getID() { return bookID; }
};

class AcademicBook : public Book {
public:
    AcademicBook(string t, string a, int id) : Book(t, a, id) {}

    void display() override {
        cout << "[Academic] ";
        Book::display();
    }
};

class FictionBook : public Book {
public:
    FictionBook(string t, string a, int id) : Book(t, a, id) {}

    void display() override {
        cout << "[Fiction] ";
        Book::display();
    }
};
class Library {
    vector<Book*> books;

public:
    void addBook(Book* b) {
        books.push_back(b);
    }

    void showBooks() {
        for (auto b : books) {
            b->display();
        }
    }

    Book* findBook(int id) {
        for (auto b : books) {
            if (b->getID() == id)
                return b;
        }
        return nullptr;
    }

    void issueBook(int id) {
        Book* b = findBook(id);
        if (b && b->isAvailable()) {
            b->issue();
            cout << "Book issued successfully.\n";
        } else {
            cout << "Book not available.\n";
        }
    }

    void returnBook(int id) {
        Book* b = findBook(id);
        if (b) {
            b->returnBook();
            cout << "Book returned.\n";
        }
    }
};
void saveBooks(Library &lib) {
    ofstream file("books.txt");
    // Simple demo: not full serialization
    file << "Library data saved.\n";
    file.close();
}
int main() {
    Library lib;

    lib.addBook(new AcademicBook("Data Structures", "Mark Allen", 1));
    lib.addBook(new FictionBook("Harry Potter", "J.K. Rowling", 2));

    int choice, id;

    do {
        cout << "\n1. Show Books\n2. Issue Book\n3. Return Book\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.showBooks();
                break;

            case 2:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.issueBook(id);
                break;

            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.returnBook(id);
                break;
        }

    } while (choice != 4);

    saveBooks(lib);

    return 0;
}