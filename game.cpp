#include <ctime>
#include <iostream>
#include <stdlib.h>

int sum(int CodeA, int CodeB, int CodeC)
{
    return CodeA + CodeB + CodeC;
}

int product(int CodeA, int CodeB, int CodeC)
{
    return CodeA * CodeB * CodeC;
}

void PrintIntroduction(int* LevelDifficulty)
{
    std::cout << "You are a secret agent breaking into a level " << *LevelDifficulty;
    std::cout << " secure server room... \nYou need to enter the correct codes to continue..." << std::endl;
}

bool PlayGame(int* LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);

    const int CodeA = (std::rand() % *LevelDifficulty) + *LevelDifficulty;
    const int CodeB = (std::rand() % *LevelDifficulty) + *LevelDifficulty;
    const int CodeC = (std::rand() % *LevelDifficulty) + *LevelDifficulty;

    const int CodeSum = sum(CodeA, CodeB, CodeC);
    const int CodeProduct = product(CodeA, CodeB, CodeC);

    std::cout << std::endl;
    std::cout << "* There are three numbers in the code" << std::endl;
    std::cout << "-> The numbers add-up to: " << CodeSum << std::endl;
    std::cout << "-> The numbers multiply to give: " << CodeProduct << std::endl;

    int PlayerGuessA, PlayerGuessB, PlayerGuessC;

    std::cout << std::endl;
    std::cout << "What's your guess? ";
    std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

    const int PlayerGuessSum = sum(PlayerGuessA, PlayerGuessB, PlayerGuessC);
    const int PlayerGuessProduct = product(PlayerGuessA, PlayerGuessB, PlayerGuessC);

    bool bSuccess = CodeSum == PlayerGuessSum && CodeProduct == PlayerGuessProduct;

    if (bSuccess) {
        std::cout << "You're in! Into the next level..." << std::endl;
    } else {
        std::cout << "No! Try again... But be careful!" << std::endl;
    }

    std::cout << std::endl;

    return bSuccess;
}

int main(int argc, char* argv[])
{
    srand(time(NULL)); // give rand function a different seed each time we play

    const int MaximumDifficulty = 5;
    int LevelDifficulty = 1;
    while (LevelDifficulty <= MaximumDifficulty)
    {
        bool bLevelComplete = PlayGame(&LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }

    std::cout << "There are no more levels! You made it! Congratulations, you're a super hacker!" << std::endl;

    return EXIT_SUCCESS;
}
