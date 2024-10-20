#include <iostream>
#include <cstdlib>

const int MAX_LETTERS = 32;
const bool LOGGING = false;

void log_custom(std::string msg)
{
    if (LOGGING)
    {
        std::cout << "[LOG]: " << msg;
    }
}

bool is_input_valid(std::string word)
{
    if (word.length() < 3)
    {
        std::cout << "Invalid input: word must be at least 3 letters long\n";
        return false;
    }
    if (word.length() > MAX_LETTERS)
    {
        std::cout << "Invalid input: word is too long\n";
        return false;
    }
    for (size_t i = 0; i < word.length(); i++)
    {
        char c = std::tolower(word.at(i));
        if (c < 'a' || c > 'z')
        {
            std::cout << "Invalid input. Only use letters between A and Z!\n";
            return false;
        }
    }
    return true;
}

int main()
{
    // Introduction
    system("clear");
    std::cout << "Welcome to the Hangman game!\n"
              << MAX_LETTERS << " is the maximum number of letters in a word.\n";
    std::cout << "Please enter the word you want to make guess!\n\n";

    // Choose the word
    std::string word = "";
    bool word_valid = false;
    while (!word_valid)
    {
        std::getline(std::cin, word);
        log_custom(word + std::string(" is the chosen word.\n"));
        word_valid = is_input_valid(word);
    }

    // Start the game
    if (!LOGGING)
    {
        system("clear");
    }

    std::cout << "Program finished succesfully.\n";
    return 0;
}