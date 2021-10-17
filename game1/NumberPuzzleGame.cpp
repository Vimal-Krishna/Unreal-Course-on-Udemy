#include <iostream>
#include <ctime>

using namespace std;

void PrintIntro(int levelOfDifficulty) {
    cout << "You are a secret agent breaking into a level " << levelOfDifficulty << " secure server room..." << endl;
    cout << "Enter the correct code to continue..." << endl;
}

bool PlayGame(int levelOfDifficulty) {

    // Print welcome messages to the terminal
    PrintIntro(levelOfDifficulty);

    const int CodeA = rand() % levelOfDifficulty + levelOfDifficulty;
    const int CodeB = rand() % levelOfDifficulty + levelOfDifficulty;
    const int CodeC = rand() % levelOfDifficulty + levelOfDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "There are three numbers in the code" << endl;
    cout << "The codes add up to: " << CodeSum << endl;
    cout << "The codes multiply to give: " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cin >> GuessA;
    cin >> GuessB;
    cin >> GuessC;
    cout << "You entered: " << GuessA << GuessB << GuessC << endl;
    int PlayerGuess;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum and GuessProduct == CodeProduct) {
        cout << "*** Great guess! You have extracted the file. ***\n" << endl;
        return true;
    } else {
        cout << "*** Bad guess! Try again ***\n" << endl;
        return false;
    }
}

int main() {
    int levelOfDifficulty {1};
    const int MaxLevels {5};
    srand(time(nullptr));
    while (true) {
        bool isLevelComplete = PlayGame(levelOfDifficulty);
        cin.clear(); // clears errors
        cin.ignore(); // clears buffer

        if (isLevelComplete) {
            levelOfDifficulty++;
        } 

        if (levelOfDifficulty > MaxLevels) {
            cout << "*** You have extracted all the files! Now you must escape to safety! ***" << endl;
            break;
        }
    }    
    return 0;
}