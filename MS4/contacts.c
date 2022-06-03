//==============================================
// Name:           Juan David Rodriguez Castelblanco
// Student Number: 147891204
// Email:          jdrodriguez-castelbl@myseneca.ca
// Section:        NFF
// Date:           24/07/2021
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-----------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2     |
// |        function definitions below...                |
// |                                                     |
// | HINT:  Update the getNumbers function to use the    |
// |        new helper function "getTenDigitPhone"       |
// |        where applicable                             |
// +-----------------------------------------------------+

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name* name) {
   
    int option;

    printf("Please enter the contact's first name: ");
    scanf(" %31[^\n]", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    option = yes();

    if (option == 1) {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %6[^\n]", name->middleInitial);
    }

    else if (option == 0) {
        name->middleInitial[0] = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf(" %36[^\n]", name->lastName); 
    clearKeyboard();

    return;
}

// getAddress:
void getAddress(struct Address* address)
{
    int strN = 0, addr = 0, option;

    printf("Please enter the contact's street number: ");
    strN = getInt();

    while (strN < 0) {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        strN = getInt();
    }

    address->streetNumber = strN;

    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    option = yes();

    if (option == 1) {
        printf("Please enter the contact's apartment number: ");
        addr = getInt();
    }

    else if (option == 0) {
        address->apartmentNumber = ' ';
    }

    while (addr < 0) {
        printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
        addr = getInt();
    }

    address->apartmentNumber = addr;

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]", address->city);


    return; 
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char opt;

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    opt = yes();

    if (opt == 1) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }


    printf("Do you want to enter a business phone number? (y or n): ");
    opt = yes();

    if (opt == 1) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }

    return; 
}

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contacts) {

    getName(&contacts->name);
    getAddress(&contacts->address);
    getNumbers(&contacts->numbers);

}

