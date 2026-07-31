#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "header.h"
using namespace std;
int num;
string textfromfile;

int menu() {
    cout << "--------Movie List----------" << "\n" << "\n";
    cout << "1. current watchlist" << "\n";
    cout << "2. add film to watchlist" << "\n";
    cout << "3. mark film as watched" << "\n";
    cout << "4. view watched films" << "\n";
    cout << "5. exit""\n";
    cin >> num;
    return num;
}
void option1() {
    cout << "--------Movie List----------" << "\n" << "\n";
    cout << "1. current watchlist" << "\n";
    ifstream readfile("movies.txt");
    while (getline(readfile, textfromfile)) {
        if (textfromfile.back() != '1') {
            cout << textfromfile.substr(0, textfromfile.size() - 2) << "\n";
        }
    }
    readfile.close();
    cout << "\n";
}
void option2() {
    string moviename;
    cout << "--------Movie List----------" << "\n" << "\n";
    cout << "2. add film to watchlist" << "\n";
    cout << "movie name?";
    cin.ignore();
    getline(cin, moviename);
    ofstream fileout("movies.txt", ios::app);
    Movie movienew(moviename, false);
    fileout << "\n" << movienew.name << "." << movienew.seen;
    fileout.close();
    cout << "added!" << "\n";
}
void option3() {
    int pick = 0;
    int movienum;
    string temp;
    vector<string> filecontents;
    vector<string> filecontentsunseen;
    cout << "--------Movie List----------" << "\n" << "\n";
    cout << "pick film" << "\n";
    ifstream readfile("movies.txt");
    while (getline(readfile, textfromfile)) {
        filecontents.push_back(textfromfile);
        if (textfromfile.back() != '1') {
            filecontentsunseen.push_back(textfromfile);
            pick++;
            cout << pick << ": " << textfromfile.substr(0, textfromfile.size() - 2) << "\n";
        }
    }
    cin >> movienum;
    temp = filecontentsunseen.at(movienum - 1);
    for (int i = 0; i < filecontents.size(); i++) {
        if (filecontents[i] == temp) {
            temp.replace(temp.size() - 1, 1, "1");
            filecontents[i] = temp;
        }
    }
    ofstream fileout("movies.txt");
    for (int i = 0; i < filecontents.size(); i++) {
        fileout << filecontents.at(i) << "\n";
    }
    fileout.close();

    cout << "updated!" << "\n";
}
void option4() {
    cout << "--------Movie List----------" << "\n" << "\n";
    cout << "4. watched films" << "\n";
    ifstream readfile("movies.txt");
    while (getline(readfile, textfromfile)) {
        if (textfromfile.back() != '0') {
            cout << textfromfile.substr(0, textfromfile.size() - 2) << "\n";
        }
    }
    readfile.close();
    cout << "\n";
}


int main() {
    bool exit = false;
    while (!exit) {
        menu();
        if (num == 1) option1();
        if (num == 2) option2();
        if (num == 3) option3();
        if (num == 4) option4();
        if (num == 5) exit = true;
    }
 return 0;
};