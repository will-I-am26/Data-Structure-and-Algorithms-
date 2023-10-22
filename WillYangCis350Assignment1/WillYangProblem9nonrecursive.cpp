/*
Write a short non-recursive method that takes a character string and outputs its reverse. For example, the reverse of 'potspans' would be 'snapstop
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace chrono;

void printCharStringReverse(char str[],int n)
{
	// just a for loop that starts at the end of the character string
	// and prints it backward toward the start of the character string
	for (int i = n-1; i >= 0; i--)
	{
		cout << str[i];
	}
}

int main()
{
	// needed variables for random character string generator and character string
	srand(time(NULL));
	const int n = 10000;
	char str[n];
	char letter;
	int numberToPickLetter;
	char randomLetterpicker[] = { 'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o', 'p', 'q','r','s','t','u','v',
	'w','x','y','z' };
	
	// populate the character string with random characters
	for (int i = 0; i < n; i++)
	{
		numberToPickLetter = rand() % 26;
		str[i] = randomLetterpicker[numberToPickLetter];
	}

	// prints out the random generated character string
	cout << "The random generated character string is: ";
	for (int i = 0; i < n; i++)
	{
		cout << str[i];
	}
	cout << endl;

	// calls and print the reverse chracter string
	cout << "The reverse character string is: ";

	auto start1 = steady_clock::now();
	printCharStringReverse(str, n);
	
	auto dur = steady_clock::now() - start1;

	// prints out the microseconds
	cout << endl;
	cout << "The runtime in microseconds is: ";
	cout << duration_cast<microseconds>(dur).count() << endl;
	
	// exit the main function
	system("pause");
	return 0;
}