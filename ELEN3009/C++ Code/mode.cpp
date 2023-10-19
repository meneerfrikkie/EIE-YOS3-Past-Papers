/* M Dadabhay - 2023 */
#include <iostream>
#include <vector>

using namespace std;

void mode(vector<int>& input) {
    vector<int> store(input.size(), 0);

    for (auto i = 0; i < input.size(); i++) {
        auto current = 0;
        auto current_Index = input[i];
        
        for (auto j = 0; j < input.size(); j++) {
            if (current_Index == input[j]) {
                current++;
            }
        }

        store[i] = current;
    }

    int answer = 0;
    for (auto i = 1; i < store.size(); i++) {
        if (store[i] > store[answer]) {
            answer = i;
        }
    }

    cout << "Frequency of each element: ";
    for (auto i = 0; i < store.size(); i++) {
        cout << store[i] << " ";
    }
    cout << endl;

    cout << "Mode count: " << store[answer] << endl;
    cout << "Mode value: " << input[answer] << endl;
}

int main()
{
    vector<int> input = {6,3,6,1,7,6,7,6,17,12,12};
    mode(input);
    return 0;
}