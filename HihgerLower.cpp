#include <iostream>
using namespace std;

bool checkWin;
vector<int> numList;

bool checkNum(char letter, int num) {
    int last;
    if (!numList.empty()) { last = numList.back(); }

    numList.push_back(num);
    if (numList.size() < 2) { return true; }

    if ( letter == 'h' && (num > last)) { 
        cout << "Nice! The next number is HIGHER. Great guess!\n";
        checkWin = true;
        return true; 
    }
    if ( letter == 'l' && (num < last)) { 
        cout << "Nice! The next number is LOWER. Great guess!\n";
        checkWin = true;
        return true; 
    }

    checkWin = false;
    return false;
}

void printNumList() {
    for (int e : numList) { cout << e << " ";  }
    cout << endl;
}

int main() {
    srand(time(nullptr));
    int num;
    char inp;
    
    cout << "=== Welcome to the Top or Bottom Guessing Game! ===\n";
    cout << "Here's how it works:\n";
    cout << "- You'll be shown a number between 1 and 100.\n";
    cout << "- Your task is to guess whether the next number will be HIGHER or LOWER.\n";
    cout << "- If you're right, the new number becomes the current number and the game continues.\n";
    cout << "- Guess correctly 4 times in a row to win!\n";
    cout << "Good luck!\n\n";

    while (true) {
        do {
            num = rand() % 100 + 1;
        } while (!numList.empty() && num == numList.back());
        
        cout << "The number is: " << num << endl;
        
        if (!checkNum(inp, num)) { break; }
        if (numList.size() == 5) { break; }

        printNumList();
        cout << "What is your guess? Higher or Lower ? (H/L)\n";
        cin >> inp;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (tolower(inp) != 'h' && tolower(inp) != 'l') {
            cout << "Invalid choice. Please pick either Higher or Lower for the next number.\n";
            cout << "What is your guess? Higher or Lower? (H/L)\n";
            cin >> inp;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } 

    printNumList();
    if (checkWin) {
    cout << "🎉 You won! You're a Top or Bottom master! 🏆\n";
    } else {
        cout << "😢 You lost! Your luck ran out this time. Try again!\n";
    }

    return 0;
}