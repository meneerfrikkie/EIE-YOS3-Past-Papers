/* M Dadabhay - 2023 */
#include <iostream>
#include <string>

using namespace std;

string removeSpaces(string input){
    auto start = input.find_first_not_of(" ");
    input.erase(0,start);
    auto end = input.find_last_not_of(" ");
    input.erase(end+1,input.length());
    return input;
}

int main()
{
    auto input = "  hello  "s;
    auto output = removeSpaces(input);

    cout << "Input: \'" << input << "\' versus Output: \'" << output << "\'" << endl;
    return 0;
}