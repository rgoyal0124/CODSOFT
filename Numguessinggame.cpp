#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // The random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int Number = rand() % 100 + 1;

    int guess;
    cout << "The Number Guessing Game" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == Number) {
            cout << "Congratulations! You guessed the correct number." << endl;
            break;
        } else if (guess < Number) {
            cout << "Try a higher number." << endl;
        } else {
            cout << "Try a lower number." << endl;
        }
    }

    cout << "The secret number was: " << Number << endl;
    return 0;
}
