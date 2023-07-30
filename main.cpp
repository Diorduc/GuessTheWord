#include <iostream>
#include <cstdlib>

using namespace std;

// Define the Player class to manage player lives
class Player
{
public:
    int lives;
    int score;
    Player()
    {
        lives = 3;
        score = 0;
    }
};

int main()
{

    Player player;

    cout << "Hello my dear guesser! I do not remember you. What is your name?" << '\n';
    string playerName;
    cin >> playerName;
    cout << "Welcome to my humble game, " << playerName << "!" << '\n';

    char choice;

    do
    {
        cout << playerName << ", do you want to enter the game? (y for yes / n for no) ";
        cin >> choice;

        if (choice != 'y' && choice != 'n')
        {
            cout << "Invalid input! Please enter 'y' or 'n'." << endl;
        }
    } while (choice != 'y' && choice != 'n');

    while (choice == 'y')
    {

        cout << "Oh, my dear " << playerName << ", your initial number of lives is: " << player.lives << "!" << endl;

        cout << "Now the guessing game starts. I have a list of 10 words, and from that list I will generate a random word.\n";
        cout << "If you guess the word, the list will delete that item, and we will continue with the others.\n";
        cout << "If not, I will take one of your lives.\n";

        string wordList[10] = {"humans", "animals", "plants", "stars", "sun", "fishes", "clouds", "rivers", "oceans", "earth"};

        int size = sizeof(wordList) / sizeof(wordList[0]);

        string wordToGuess;

        while (player.lives != 0 && size != 0)
        {
            cout << "You're current score is: " << player.score << endl;
            // Display the list of available words for guessing
            cout << "List: ";
            for (string words : wordList)
            {
                cout << words << ' ';
            }
            cout << endl;

            // Generate a random index to choose a word from the list
            int randomIndex = rand() % size;
            wordToGuess = wordList[randomIndex];

            cout << "You want to say the word: ";

            string wordGuessed;
            cin >> wordGuessed;

            if (wordGuessed == wordToGuess)
            {
                cout << "You are right!";

                player.score++;

                wordList[randomIndex] = wordList[size - 1];
                size--;
            }
            else
            {
                cout << "You are wrong!" << '\n';

                player.lives = player.lives - 1;
                cout << "You have " << player.lives << " lives left!" << '\n';
                cout << "Please be careful next time! Do not rush.. it is not timed (yet -> I still have to learn how to do that!)" << endl;
            }
        }

        if (player.lives == 0)
        {
            cout << "Oh you didn't guess. Here was the word: " << wordToGuess << endl;
            cout << "You're total score was: " << player.score << endl;
        }

        player.lives = 3;
        player.score = 0;
        size = sizeof(wordList) / sizeof(wordList[0]);

        cout << "Do you want to play again? (y for yes / n for no) ";
        cin >> choice;

        if (choice != 'y' && choice != 'n')
        {
            cout << "Invalid input! Please enter 'y' or 'n'." << endl;
        }
    }

    cout << "See you next time, " << playerName << "!" << endl;

    return 0;
}
