/*
Write a short non-recursive method that takes a character string and outputs its reverse. For example, the reverse of 'potspans' would be 'snapstop
*/

#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;

void printCharStringReverse(char str[], int n)
{
	// a termination case where the element of the 
	// character string is 0
	if (n == 0)
	{
		return;
	}
	else if (n < 10)
	{
		for (int i = n; i > 0; i--)
		{
			cout << str[i - 1];
		}
	}
	else
	{
		// just print out the character at the element
		for (int i = n; i > (n - 10); i--)
		{
			cout << str[i - 1];
		}
		// calls on the print function again
		return printCharStringReverse(str, n - 10);
	}
}

int main()
{
	// needed variables to create the random character string generator 
	srand(time(NULL));
	const int n = 10000;
	char str[n];
	char letter;
	int numberToPickLetter;
	char randomLetterpicker[] = { 'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o', 'p', 'q','r','s','t','u','v',
	'w','x','y','z' };
	
	// populate the character string with random character
	for (int i = 0; i < n; i++)
	{
		numberToPickLetter = rand() % 26;
		str[i] = randomLetterpicker[numberToPickLetter];
	}

	// print out the generated charcater string
	cout << "The random generated character string is: ";
	for (int i = 0; i < n; i++)
	{
		cout << str[i];
	}
	cout << endl;

	//prints out the character string in reverse
	cout << "The reverse character string is: ";

	auto start1 = steady_clock::now();
	printCharStringReverse(str, n);
	auto dur = steady_clock::now() - start1;
	cout << endl;

	// display the runtime in microseconds
	cout << "The runtime in microseconds is: ";
	cout << duration_cast<microseconds>(dur).count() << endl;

	//exit the main function
	system("pause");
	return 0;
}