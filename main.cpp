#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void replace(string& str, char oldChar, char newChar) {
    for (char& ch : str) {
        if (ch == oldChar) {
            ch = newChar;
        }
    }
}

bool islower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

char toupper(char ch) {
    if (islower(ch)) {
        return ch - 'a' + 'A';
    }
    return ch;
}

int main() {
    ifstream inFile("f1.txt");
    ofstream outFile("f2.txt");

    if (!inFile || !outFile) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        replace(line, ',', ' ');
        replace(line, ';', ' ');

        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (islower(word[0])) {
                word[0] = toupper(word[0]);
            }
            outFile << word << ' ';
        }
        outFile << '\n';
    }

    inFile.close();
    outFile.close();

    return 0;
}