#include <iostream>
#include <ctime>

int trial = 3;// agent trial 
void Introduction(int Difficulty)
{
	std::cout << "\n\nYou are a secret agent breaking in level " << Difficulty << " server room...\n";
	std::cout << "Starting the game...\n";
}

bool PlayGame(int Difficulty)
{
	Introduction(Difficulty);

	// Game Starts 
	const int CodeA = rand() % Difficulty + Difficulty; // get random number , modulous by difficulty number 
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;


	std::cout << "+There are 3 number in the game.\n";
	std::cout << "+The code adds up to ::" << CodeSum << "\n";
	std::cout << "+The Code product is ::" << CodeProduct << "\n";

	// Input from Player
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;

	std::cout << "Your guess is :" << "\t" << GuessA << ",\t" << GuessB << ",\t" << GuessC << "\n";

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	std::cout << "Sum is :" << GuessSum << "\n" << "Product is :" << GuessProduct << "\n\n";


	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{

		std::cout << "Great job!!   Agent You extracted the files,Let's go the next level , you have " << ::trial << " trial";
		return true;
	}
	else
	{
		::trial--;

		std::cout << "You enter the wrong code agent ! Careful you have " << ::trial << " trail left. Try Again!";

		return false;
	}


}
int main()
{
	srand(time(NULL)); // create new random sequence based on time of day
	const int MaxDifficultylevel = 7;

	int LevelDifficulty = 1;

	while (LevelDifficulty <= MaxDifficultylevel)
	{
		bool Plevel = PlayGame(LevelDifficulty);

		std::cin.clear();// Clear aany errors 
		std::cin.ignore();//Discard the buffer 

		if (Plevel == true)
		{
			++LevelDifficulty; // Increment Difficulty 
		}
		if (::trial < 1)
		{
			if (Plevel == false)
			{
				::trial = 3;
				--LevelDifficulty;//decrement difficulty

			}
		}

	}
	std::cout << "Good Job agent you have extracted all the files , Now get out there quickly & get back to the headquarters ";

	return 0;

}