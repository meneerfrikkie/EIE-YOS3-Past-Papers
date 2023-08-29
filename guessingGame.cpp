/* M Dadabhay - 2023 */
#include <iostream>
#include <string>

using namespace std;

int generateRandomNumber(){
    srand(time(0));
    auto maxNumber = 100;
    auto minNumber = 1;
    return ((rand()%maxNumber)+minNumber);
}

int playTurn(const int randomNumber, int& userInput){
    auto choice = 0;
    if (randomNumber == userInput) {choice = 0;}
    else if (userInput < randomNumber) {choice = 1;}
    else if (userInput > randomNumber) {choice = 2;}
    return choice;
}

void outputHints(int resultant){
    switch (resultant)
    {
    case 0:
        cout << "You win!" << endl;
        break;
    case 1:
        cout << "Guess bigger..." << endl;
        break;
    case 2:
        cout << "Guess smaller..." << endl;
        break;
    default:
        break;
    }
}

void getUserInput(int &userInput){
    cout << "Guess a random number: ";
    cin >> userInput;
}

int main()
{
    auto randomNumber = generateRandomNumber();
    auto gameCounter = 0;
    // cout << randomNumber << endl;
    while (gameCounter < 5)
    {
        int userInput;
        getUserInput(userInput);
        auto roundResult = playTurn(randomNumber,userInput);
        outputHints(roundResult);

        if (roundResult == 0) {break;}
        
        gameCounter++;
        if (gameCounter == 5) { cout << "You lose. The correct number was " << randomNumber << endl;}
    }
    
    
    return 0;
}