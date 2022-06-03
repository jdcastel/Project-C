//==============================================
// Name:           Juan David Rodriguez Castelblanco
// Student Number: 147891204
// Email:          jdrodriguez-castelbl@myseneca.ca
// Section:        NFF
// Date:           18/07/2021
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	
		int val,ret;
		char ch;

		do
		{
			scanf("%d%c", &val, &ch);
			if (ch != '\n')
			{
				clearKeyboard();
				printf("*** INVALID INTEGER *** <Please enter an integer>: ");

			}
			else
			{
				ret = val;
			}

		} while (ch != '\n');
		return ret;
	
	
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int valid = 0,ret,value;
	do
	{
		
		value = getInt();
		if (!(value >= min && value <= max))
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);

		}

		else
		{

			valid = 1;
			ret = value;
		}


	} while (valid == 0);
	return ret;
}


// yes function definition goes here:
int yes(void)
{
	int valid = 0, ret;
	char ch ,value;

	do
	{
		scanf("%c%c", &value, &ch);
		if (ch != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			continue;

		}
		else
		{
			if (value == 'Y' || value == 'y' || value == 'N' || value == 'n')
			{
				if (value == 'Y' || value == 'y')
				{
					ret = 1;
				}
				else
				{
					ret = 0;
				}
				valid = 1;
			}
			if (!(value == 'Y' || value == 'y' || value == 'N' || value == 'n'))
			{
				clearKeyboard();
				printf("***INVALID ENTRY * **<Only(Y)es or (N)o are acceptable>: ");
				continue;
			}


		}

	} while (ch != '\n' && valid == 0);
	return ret;
}

// menu function definition goes here:
int menu(void)
{
	int selection;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	selection = getIntInRange(0, 6);

	return selection;

}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int valid = 0;
	int selection;
	do
	{

		selection = menu();
		if (selection == 1)
		{
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
		}
		if (selection == 2)
		{
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
		}
		if (selection == 3)
		{
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
		}
		if (selection == 4)
		{
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
		}
		if (selection == 5)
		{
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
		}
		if (selection == 6)
		{
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
		}
		if (selection == 0)
		{
			printf("\nExit the program? (Y)es/(N)o: ");

			if (yes() == 1)
			{
				printf("\nContact Management System: terminated\n");

				valid = 1;
			}
			else
			{
				printf("\n");
				valid = 0;
			}

		}
	} while (valid == 0);
}