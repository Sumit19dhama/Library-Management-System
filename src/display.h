#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void namaste();
void displayMenu();
void displayMenuUser();
// initial display
void namaste() {

    printf("\n\n");
    printf("\t\t\t     *****************************************\n");
    printf("\t\t\t     * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t     *                                       *\n");
    printf("\t\t\t     *     ----------------------------      *\n");
    printf("\t\t\t     *     |WELCOME TO STUDENT LIBRARY|      *\n");
    printf("\t\t\t     *     ----------------------------      *\n");
    printf("\t\t\t     *                                       *\n");
    printf("\t\t\t     * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t     *****************************************\n");
    printf("\n\n");
    printf("\t\t\t     *****************************************\n");
    printf("\t\t\t     *                                       *\n");
    printf("\t\t\t     *       ------------------------        *\n");
    printf("\t\t\t     *          |STUDENT LIBRARY|            *\n");
    printf("\t\t\t     *       ------------------------        *\n");
    printf("\t\t\t     *                                       *\n");
    printf("\t\t\t     *                                       *\n");
    printf("\t\t\t     *    Ghaziabad,Uttar pradesh,India      *\n");
    printf("\t\t\t     *     Email: studentlib@gmail.com       *\n");
    printf("\t\t\t     *     Contact:+91-xxxxxxxxxx            *\n");
    printf("\t\t\t     *                                       *\n");
    printf("\t\t\t     *****************************************\n");
    printf("\n\n\t\t\t             Press any key to continue: \n\n");
}

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add a Book\n");
    printf("2. Display Books\n");
    printf("3. Search for a Book\n");
    printf("4. Delete a Book\n");
    printf("5. Issue a Book\n");
    printf("6. return a Book\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void displayMenuUser() {
    printf("\nLibrary Management System\n");
    printf("1. Display Books\n");
    printf("2. Search for a Book\n");
    printf("3. Issue a Book\n");
    printf("4. return a Book\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}