#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <fstream> 
#include <string> 

using namespace std;

// Function to clear the console screen
void clearScreen() {
    #ifdef _WIN32 // If the operating system is Windows
        system("cls"); // Clear screen command for Windows
    #else
        system("clear"); // Clear screen command for Unix/Linux/MacOS
    #endif
}

// Function to get a valid integer input from the user
int getValidInt() {
    int num;
    while (!(cin >> num)) {
        cin.clear(); // Clear the error flag
        cin.sync();
        cout << "Please enter the number: ";
    }
    return num;
}

// Function to handle one level of the guessing game
int Lvl(int num, int score, int dif) {
    // Generate a random number between 1 and dif
    int randNum = (rand() % dif) + 1;
    do {
        cout << "GUESS!!!" << endl; // Prompt user to guess
        num = getValidInt(); // Read and validate user's guess
        if (num > randNum) { // If the guess is too high
            clearScreen(); // Clear the screen
            cout << "TOO MUCH" << endl; // Notify the user
            score = score - 50; // Deduct 50 points
        } else if (num < randNum) { // If the guess is too low
            clearScreen(); // Clear the screen
            cout << "TOO LESS" << endl; // Notify the user
            score = score - 50; // Deduct 50 points
        }
    } while (!(num == randNum)); // Repeat until the user guesses correctly
    return score; // Return the current score
}

// Function to get the current time as a string
string getCurrentTime() {
    time_t now = time(0); // Get the current time
    tm *ltm = localtime(&now); // Convert to local time structure
    char buffer[50];
    // Format the time as dd-mm-yyyy hh:mm:ss
    sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d",
            ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return string(buffer); // Return the formatted time as a string
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int score = 1000, num = 0, dif = 10; // Initialize score, number, and difficulty
    string nick;

    cout << "NAME:" << endl; // Prompt user for their name
    cin >> nick; // Read user's name
    cout << "\nSTART\n" << "YOU HAVE " << score << " POINTS" << endl; // Start message with initial score

    // Level I
    cout << "LEVEL I" << endl;
    score = Lvl(num, score, dif); // Play level I
    clearScreen(); // Clear the screen
    cout << "GJ " << nick << " !\n" << "YOUR SCORE " << score << endl; // Display score
    dif = dif * 10; // Increase difficulty

    // Level II
    cout << "LEVEL II" << endl;
    score = Lvl(num, score, dif); // Play level II
    clearScreen(); // Clear the screen
    cout << "GJ " << nick << " !\n" << "YOUR SCORE " << score << endl; // Display score
    dif = dif * 10; // Increase difficulty

    // Level III
    cout << "LEVEL III" << endl;
    score = Lvl(num, score, dif); // Play level III
    clearScreen(); // Clear the screen
    cout << "GJ " << nick << " !\n" << "YOUR SCORE " << score << endl; // Display score
    dif = dif * 10; // Increase difficulty

    // Level IV
    cout << "LEVEL IV" << endl;
    score = Lvl(num, score, dif); // Play level IV
    clearScreen(); // Clear the screen
    cout << "GJ " << nick << " !\n" << "YOUR SCORE " << score << endl; // Display score

    // Save the results to a file
    fstream PBLWyniki;
    PBLWyniki.open("PBLWyniki.txt", ios::in | ios::app); // Open the file in append mode
    if (PBLWyniki.is_open()) { // Check if the file is open
        // Write the user's name, score, and current time to the file
        PBLWyniki << nick << "\n" << score << " pts\n" << getCurrentTime() << "\n" << endl;
    }
    PBLWyniki.close(); // Close the file

    return 0; // End of the program
}
