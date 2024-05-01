#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

void search();
void search_manga();
void search_author();
void listmanga();
void listauthor();
void write_account();
void display_menu();
void display();

class account {
public:
    char name[50];
    char rating[3];

    void create_account();
    void report(int);
};

void account::create_account() {
    system("cls");
    cout << "Review Survey:";
    cout << "\n\nName: ";
    cin.getline(name, 50);
    cout << "\nRating: ";
    cin.getline(rating, 3);
    cout << "\n\n\nResponse Recorded!!";
}

void account::report(int i) {
    cout << i << ")" << name << "     " << rating << endl;
}

void screen() {
    char ch;
    cout << "\t\t\t\t**MANGA CHRONICLE.io** ";
    cout << "\n\t\t\t   Welcome to the world of fantasies!!";
    cout << "\nHit Enter To Browse The Website.";
    ch = getch();
    system("cls"); // clear screen
}

void menu() {
    char ch;
    do {
        system("cls");
        cout << "MENU-\n";
        cout << "1.Search" << endl;
        cout << "2.Manga" << endl;
        cout << "3.Authors" << endl;
        cout << "4.Reviews" << endl;
        cout << "5.Exit" << endl;
        cout << "\n\n\tSelect Your Option (1-5): ";
        cin >> ch;
        system("cls");
        switch (ch) {
            case '1':
                search();
                break;
            case '2':
                listmanga();
                break;
            case '3':
                listauthor();
                break;
            case '4':
                display();
                break;
            case '5':
                break;
            default:
                cout << "Invalid Operation";
        }
    } while (ch != '5');
    cin.ignore();
    write_account();
    cout << "Thanks for using Manga Chronicles!!";
    cin.get();
}

void write_account() {
    account ac;
    ofstream outFile;
    outFile.open("datasets/account_manga.txt", ios::binary | ios::app);
    ac.create_account();
    outFile.write((char *)&ac, sizeof(account));
    outFile.close();
}

void display_menu() {
    cout << "Press any key to return to the menu...";
    getch();
}

void display() {
    account ac;
    ifstream inFile;
    char ch;
    int i = 1;
    inFile.open("datasets/account_manga.txt", ios::binary);
    if (inFile) {
        system("cls");
        cout << "\n\n\t\tVisitors List\n\n";
        cout << "====================================================\n";
        cout << "Sr UserName         Rating\n";
        cout << "====================================================\n";
        while (inFile.read((char *)&ac, sizeof(account))) {
            ac.report(i);
            i++;
        }
        inFile.close();
        display_menu(); // Prompt to return to menu
        menu(); // Display the menu
    } else {
        cout << "Error opening file." << endl;
    }
}

void search() {
    char ch;
    cout << "Search for...." << endl;
    cout << "1.Manga" << endl;
    cout << "2.Authors" << endl;
    cout << "3.Back" << endl;
    cin >> ch;
    switch (ch) {
        case '1':
            search_manga();
            break;
        case '2':
            search_author();
            break;
        case '3':
            menu();
            break;
        default:
            cout << "Error!";
            break;
    }
}

void search_manga() {
    system("cls");
    char ch;
    string search;
    int offset;
    string line;
    ifstream Myfile;
    Myfile.open("datasets/Manga_DB.txt");
    cout << "Enter the Manga to search: ";
    cin >> search;
    if (Myfile.is_open()) {
        while (!Myfile.eof()) {
            getline(Myfile, line);
            if ((offset = line.find(search, 0)) != string::npos) {
                cout << line << endl;
            }
        }
        Myfile.close();
        cout << "Press any key to continue...";
        getch();
    } else {
        cout << "File opening error" << endl;
    }
}

void search_author() {
    system("cls");
    char ch;
    string search;
    int offset;
    string line;
    ifstream Myfile2;
    Myfile2.open("datasets/Author_DB.txt");
    cout << "Enter the Author to search: ";
    cin >> search;
    if (Myfile2.is_open()) {
        while (!Myfile2.eof()) {
            getline(Myfile2, line);
            if ((offset = line.find(search, 0)) != string::npos) {
                cout << line << endl;
            }
        }
        Myfile2.close();
        cout << "Press any key to continue...";
        getch();
    } else {
        cout << "File opening error" << endl;
    }
}

void listmanga() {
    system("cls");
    char ch;
    string getcontent;
    ifstream openfile("datasets/Manga_DB.txt");
    if (openfile.is_open()) {
        while (!openfile.eof()) {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }
        openfile.close();
    } else {
        cout << "File opening error" << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

void listauthor() {
    system("cls");
    char ch;
    string getcontent;
    ifstream openfile("datasets/Author_DB.txt");
    if (openfile.is_open()) {
        while (!openfile.eof()) {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }
        openfile.close();
    } else {
        cout << "File opening error" << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

int main() {
    screen();
    menu();
    return 0;
}
