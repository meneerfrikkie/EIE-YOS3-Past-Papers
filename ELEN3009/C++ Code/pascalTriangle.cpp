#include <iostream>

using namespace std;

int fact(int n) {
    return n > 1 ? fact(n - 1) * n : 1;
}

void userInput(int &max_rows){
    cout << "Enter the number of rows of Pascal’s Triangle\n";
    cin >> max_rows;
}

void printLeadingSpaces(int &row,int &max_row){
    for (auto i = row; i <= max_row; i++) {
        cout << " ";
    }
}

void printCoefficient(int &row){
    auto value = 0;
    for (auto i = 0; i <= row; i++) {
        value = fact(row) / (fact(i) * fact(row - i));
        cout << " " << value;
    } 
}

int main() {
    auto max_row = 0;
    userInput(max_row);
    
    for (auto row = 0; row < max_row; row++) {
        // Print leading spaces
        printLeadingSpaces(row,max_row);
        printCoefficient(row);
        cout << endl;
    }
    
    return 0;
}
