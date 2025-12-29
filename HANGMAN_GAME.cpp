#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

// HANGMAN GAME ------------------------------------------------------------------------------------------------------------------------------------------------------------ 

int main() {

    srand(time(0));
    system("color 0A");

    char choice;
    cout << "Hey There , Wanna play a game ? -  (y/n) : ";
    cin >> choice;
    if (choice != 'y') {
        cout << "aw man :( " << "\n\n";
        system("pause");
        system("cls");
        return 0;
        
    }
start:

    cout << "\n" << R"( /$$   /$$  /$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$  /$$   /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$
| $$  | $$ /$$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$| $$$ | $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/
| $$  | $$| $$  \ $$| $$$$| $$| $$  \__/| $$$$  /$$$$| $$  \ $$| $$$$| $$      | $$  \__/| $$  \ $$| $$$$  /$$$$| $$      
| $$$$$$$$| $$$$$$$$| $$ $$ $$| $$ /$$$$| $$ $$/$$ $$| $$$$$$$$| $$ $$ $$      | $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   
| $$__  $$| $$__  $$| $$  $$$$| $$|_  $$| $$  $$$| $$| $$__  $$| $$  $$$$      | $$|_  $$| $$__  $$| $$  $$$| $$| $$__/   
| $$  | $$| $$  | $$| $$\  $$$| $$  \ $$| $$\  $ | $$| $$  | $$| $$\  $$$      | $$  \ $$| $$  | $$| $$\  $ | $$| $$      
| $$  | $$| $$  | $$| $$ \  $$|  $$$$$$/| $$ \/  | $$| $$  | $$| $$ \  $$      |  $$$$$$/| $$  | $$| $$ \/  | $$| $$$$$$$$
|__/  |__/|__/  |__/|__/  \__/ \______/ |__/     |__/|__/  |__/|__/  \__/       \______/ |__/  |__/|__/     |__/|________/
                                                                                                                          
                                                                                                                          
                                                                                                                          )" << "\n";
    string words[] = { "apple", "beach", "brain", "bread", "brush",
    "chair", "chest", "chord", "click", "clock",
    "cloud", "dance", "diary", "drink", "drive",
    "earth", "feast", "field", "fruit", "glass",
    "grape", "grass", "ghost", "guide", "heart",
    "horse", "house", "human", "image", "juice",
    "light", "lemon", "melon", "money", "music",
    "night", "ocean", "party", "phone", "photo",
    "piano", "pilot", "pizza", "place", "plane",
    "plant", "plate", "power", "radio", "range",
    "river", "robot", "round", "salad", "sauce",
    "scene", "scope", "shape", "share", "sheep",
    "sheet", "shell", "shirt", "shoes", "sight",
    "skate", "skill", "sleep", "smile", "smoke",
    "snake", "space", "spoon", "sport", "stage",
    "start", "steam", "steel", "stone", "store",
    "storm", "story", "sugar", "sweet", "table",
    "taste", "thing", "tiger", "toast", "touch",
    "tower", "track", "trade", "train", "truck",
    "uncle", "video", "voice", "watch", "water" };

    int totalwords = sizeof(words) / sizeof(words[0]);

    int wordindex, word, guess, lives = 5;
    char letter;
    wordindex = rand() % totalwords;

    string secretword = words[wordindex];
    string hiddenword = "_____";
    cout << "Now .. You gotta guess the word you've got , =====>  5 tries  <=====\n";
    cout << "or .. HE DIES";
    while (lives > 0 && secretword != hiddenword) {
        system("cls");


        cout << "\n" << R"( /$$   /$$  /$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$  /$$   /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$
| $$  | $$ /$$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$| $$$ | $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/
| $$  | $$| $$  \ $$| $$$$| $$| $$  \__/| $$$$  /$$$$| $$  \ $$| $$$$| $$      | $$  \__/| $$  \ $$| $$$$  /$$$$| $$      
| $$$$$$$$| $$$$$$$$| $$ $$ $$| $$ /$$$$| $$ $$/$$ $$| $$$$$$$$| $$ $$ $$      | $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   
| $$__  $$| $$__  $$| $$  $$$$| $$|_  $$| $$  $$$| $$| $$__  $$| $$  $$$$      | $$|_  $$| $$__  $$| $$  $$$| $$| $$__/   
| $$  | $$| $$  | $$| $$\  $$$| $$  \ $$| $$\  $ | $$| $$  | $$| $$\  $$$      | $$  \ $$| $$  | $$| $$\  $ | $$| $$      
| $$  | $$| $$  | $$| $$ \  $$|  $$$$$$/| $$ \/  | $$| $$  | $$| $$ \  $$      |  $$$$$$/| $$  | $$| $$ \/  | $$| $$$$$$$$
|__/  |__/|__/  |__/|__/  \__/ \______/ |__/     |__/|__/  |__/|__/  \__/       \______/ |__/  |__/|__/     |__/|________/
                                                                                                                          
                                                                                                                          
                                                                                                                          )" << "\n";

        cout << " Only 5 Chances !! \n Guess the Word , 5 letters \n OR .. HE DIES\n\n";

        if (lives == 5) {
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "=========\n";
        }
        else if (lives == 4) {
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "=========\n";
        }
        else if (lives == 3) {
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << "  |   |\n";
            cout << "      |\n";
            cout << "=========\n";
        }
        else if (lives == 2) {
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << " /|   |\n";
            cout << "      |\n";
            cout << "=========\n";
        }
        else if (lives == 1) {
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << " /|\\  |\n";
            cout << "      |\n";
            cout << "=========\n";
            cout << "LAST CHANCE! BE CAREFUL!\n";
        }
        cout << "\nCurrent word: " << hiddenword << "\n";
        cout << "\nGuess a letter =====> ";
        cin >> letter;
        bool found = false;

        for (int i = 0; i < secretword.length(); i++) {
            if (secretword[i] == letter) {
                hiddenword[i] = letter;
                found = true;

            }
        }

        if (found) {
            cout << "Nice! Found one.\n";
        }
        else {
            cout << "Nope!\n";
            lives--;
            cout << "Lives left: " << lives << endl;
            if (lives == 1) {
                cout << "Be Careful !!! ! live left " << "\n";
            }
        } 

    }
    system("cls");

    if (hiddenword == secretword) {
        cout << R"(
 /$$     /$$ /$$$$$$  /$$   /$$       /$$      /$$ /$$$$$$ /$$   /$$       /$$
|  $$   /$$//$$__  $$| $$  | $$      | $$  /$ | $$|_  $$_/| $$$ | $$      | $$
 \  $$ /$$/| $$  \ $$| $$  | $$      | $$ /$$$| $$  | $$  | $$$$| $$      | $$
  \  $$$$/ | $$  | $$| $$  | $$      | $$/$$ $$ $$  | $$  | $$ $$ $$      | $$
   \  $$/  | $$  | $$| $$  | $$      | $$$$_  $$$$  | $$  | $$  $$$$      |__/
    | $$   | $$  | $$| $$  | $$      | $$$/ \  $$$  | $$  | $$\  $$$          
    | $$   |  $$$$$$/|  $$$$$$/      | $$/   \  $$ /$$$$$$| $$ \  $$       /$$
    |__/    \______/  \______/       |__/     \__/|______/|__/  \__/      |__/
                                                                              
                                                                              
                                                                              

                                                                              
                                                                              )";
        cout << "\nYOU WIN! The word was: " << secretword << endl;
    }
    else {
        cout << R"( 
 /$$     /$$ /$$$$$$  /$$   /$$       /$$        /$$$$$$   /$$$$$$  /$$$$$$$$             /$$
|  $$   /$$//$$__  $$| $$  | $$      | $$       /$$__  $$ /$$__  $$|__  $$__/            | $$
 \  $$ /$$/| $$  \ $$| $$  | $$      | $$      | $$  \ $$| $$  \__/   | $$               | $$
  \  $$$$/ | $$  | $$| $$  | $$      | $$      | $$  | $$|  $$$$$$    | $$               | $$
   \  $$/  | $$  | $$| $$  | $$      | $$      | $$  | $$ \____  $$   | $$               |__/
    | $$   | $$  | $$| $$  | $$      | $$      | $$  | $$ /$$  \ $$   | $$                   
    | $$   |  $$$$$$/|  $$$$$$/      | $$$$$$$$|  $$$$$$/|  $$$$$$/   | $$                /$$
    |__/    \______/  \______/       |________/ \______/  \______/    |__/               |__/
                                                                                             
                                                                                             
                                                                                             


            )";

        cout << "\n\n  +---+\n";
        cout << "  |   |\n";
        cout << "  O   |\n";
        cout << " /|\\  |\n";
        cout << " / \\  |\n";
        cout << "=========\n";

        cout << "\n============================================\n";
        cout << "GAME OVER. The word was:  ====> " << secretword << endl;
    }
    char choice1;
    cout << "Wanna play again ? - (y/n)";
    cin >> choice1;
    if (choice1 == 'y') {
        system("cls");
        goto start;
        
    }
    system("pause");
    return 0;
}