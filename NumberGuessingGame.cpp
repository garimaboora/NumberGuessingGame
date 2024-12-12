#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to display the header for the game
void displayHeader() {
    cout << "*******************************" << endl;
    cout << "   Welcome to the Number Guessing Game!" << endl;
    cout << "*******************************" << endl;
    cout << "Try to guess the number I'm thinking of!" << endl;
}

// Function to handle user input and ensure valid guesses
int getUserGuess(int lowerBound, int upperBound) {
    int guess;
    while (true) {
        cout << "Enter a number between " << lowerBound << " and " << upperBound << ": ";
        cin >> guess;

        // Check if the input is valid
        if (cin.fail() || guess < lowerBound || guess > upperBound) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "Invalid input! Please enter a number between " << lowerBound << " and " << upperBound << "." << endl;
        } else {
            return guess;
        }
    }
}

// Main function to run the game
int main() {
    srand(time(0));  // Seed the random number generator with current time

    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 100;
    int numberToGuess = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
    int userGuess = 0;
    int attempts = 0;

    displayHeader();

    // Game loop
    while (userGuess != numberToGuess) {
        userGuess = getUserGuess(LOWER_BOUND, UPPER_BOUND);
        attempts++;

        if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << numberToGuess << " in " << attempts << " attempts." << endl;
        }
    }

    return 0;
}
