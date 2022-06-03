

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5



// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); 
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

	int value, ret;
	char ch;

	scanf(" %d%c", &value, &ch);

	do {
		if (ch != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf(" %d%c", &value, &ch);
		} 

		else if (ch == '\n')
			ret = 1; 

	} while (ret == 0);

	return value; 
}

int getIntInRange(int min, int max) { 

	int value, ret = 0, check;

	check = scanf("%d", &value);

	do {

		if (check != 1) {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			check = scanf(" %d", &value);

		}

		else if (value < min || value > max) { 
			clearKeyboard();
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
			check = scanf(" %d", &value);
		}

		else
			ret = 1; 

	} while (ret == 0);

	return value;
}


// yes function definition goes here:
int yes(void)
{
	int output = -1;
	char ans, NL;

	scanf(" %c%c", &ans, &NL);

	while (!(NL == '\n' && (ans == 'Y' || ans == 'y' || ans == 'N' || ans == 'n'))) 
	{ 
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &ans, &NL);

	}

	if (ans == 'N' || ans == 'n') 
		output = 0;
	else if (ans == 'Y' || ans == 'y') 
		output = 1;

	return output;
}

// menu function definition goes here:
int menu(void)
{

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

	return getIntInRange(0, 6); 

}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void) {
	int option, ans;

	struct Contact contacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
											   { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
											   { "4161112222", "4162223333", "4163334444" } },
											{
												{ "Maggie", "R.", "Greene" },
												{ 55, "Hightop House", 0, "A9A 3K3", "Bolton"},
												{ "9051112222", "9052223333", "9053334444" } },
											{
												{ "Morgan", "A.", "Jones" },
												{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
												{ "7051112222", "7052223333", "7053334444" } },
											{
												{ "Sasha", {'\0'}, "Williams" },
												{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												{ "9052223333", "9052223333", "9054445555" } },
	};

	do {
		option = menu();

		switch (option) 
		{ 

		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			ans = yes(); 

			if (ans == 1) {
				printf("\n");
				printf("Contact Management System: terminated\n");
				return;
			}
			else if (ans == 0) {
				printf("\n");
			}
			break;

		case 1:
			displayContacts(contacts, MAXCONTACTS);

			break;

		case 2:
			addContact(contacts, MAXCONTACTS);


			break;

		case 3:
			updateContact(contacts, MAXCONTACTS);

			break;

		case 4:
			deleteContact(contacts, MAXCONTACTS);

			break;

		case 5:
			searchContacts(contacts, MAXCONTACTS);

			break;

		case 6:
			sortContacts(contacts, MAXCONTACTS);

			break;

		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> \n");
			printf("\n");
			break;
		}
	} while (option >= 0 || option <= 6);

	return;
}


void getTenDigitPhone(char phoneNum[]) {
	int digits = 1;

	while (digits == 1) {
		scanf(" %10[0-9]", phoneNum);
		clearKeyboard();


		if (strlen(phoneNum) == 10)
			digits = 0;
		else
			printf("Enter a 10-digit phone number: ");

	}

}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
	int i;
	int find = 0;
	int index = -1;

	for (i = 0; i < size && find == 0; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			find = 1;
			index = i;
		}

	}

	return index;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);

}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact) {

	if (contact->name.middleInitial[0] == '\0')
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	else
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	if (contact->address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	else
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
	int i, count = 0;
	printf("\n");
	displayContactHeader();

	for (i = 0; i < size; i++) {
		if (contacts[i].numbers.cell[0] > 0) {
			displayContact(&contacts[i]);
			count++;
		}

	}

	displayContactFooter(count);
	pause();
	getchar();
	printf("\n");
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {
	char cellNum[11];
	int result;

	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	result = findContactIndex(contacts, size, cellNum);

	if (result < 0) {
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
		pause();
		printf("\n");

	}
	else if (result >= 0) {
		printf("\n");
		displayContact(&contacts[result]);
		printf("\n");
		pause();
		printf("\n");
	}
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
	int i, index = -1;

	printf("\n");

	for (i = 0; i < size; i++) {

		if (contacts[i].numbers.cell[0] == 0) {
			index = i;
		}
	}

	if (index < 0) {
		printf("*** ERROR: The contact list is full! ***\n");
		printf("\n");
		pause();
		getchar();
		printf("\n");
	}

	else if (index >= 0) {
		getContact(&contacts[index]);
		printf("--- New contact added! ---\n");
		printf("\n");
		pause();
		printf("\n");
	}

}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {
	char cellNum[11];
	int result, answ;
	struct Name noName = { {'\0'} };
	struct Address noAddress = { 0, {'\0'}, 0, {'\0'}, {'\0'} };
	struct Numbers noNumbers = { {'\0'} };

	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	result = findContactIndex(contacts, size, cellNum);

	if (result < 0) {
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
		pause();
		printf("\n");
	}

	else if (result >= 0) {
		printf("\n");
		printf("Contact found:\n");

		displayContact(&contacts[result]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		answ = yes();

		if (answ == 1) {
			contacts[result].name = noName;
			getName(&contacts[result].name);
		}

		printf("Do you want to update the address? (y or n): ");
		answ = yes();

		if (answ == 1) {
			contacts[result].address = noAddress;
			getAddress(&contacts[result].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		answ = yes();

		if (answ == 1) {
			contacts[result].numbers = noNumbers;
			getNumbers(&contacts[result].numbers);
		}

		printf("--- Contact Updated! ---\n");
		printf("\n");
		pause();
		printf("\n");
	}
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
	
	int result, response;
	char cellNum[11];
	struct Contact blank = { { {'\0'} }, {0, {'\0'}, 0, {'\0'}, {'\0'} }, { {'\0'} } };

	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	printf("\n");

	result = findContactIndex(contacts, size, cellNum);

	if (result < 0) {
		printf("*** Contact NOT FOUND ***\n\n");
		printf("\n");
		pause();
		printf("\n");
	}

	else if (result >= 0) {
		printf("Contact found:\n");

		displayContact(&contacts[result]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		response = yes();

		if (response == 1) {
			contacts[result] = blank;
			printf("--- Contact deleted! ---\n");
			printf("\n");
			pause();
			printf("\n");
		}

		else if (response == 0) {
			printf("\n");
			pause();
			printf("\n");
		}
	}
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size) {
	printf("\n<<< Feature to sort is unavailable >>>\n\n");
	pause();
	getchar();
	printf("\n");
}


