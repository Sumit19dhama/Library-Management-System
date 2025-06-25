#include <stdio.h>
#include <stdlib.h> 
#include "admin.h"
#include "library.h"
#include "display.h"



//main function. All calls of function occur from main function. 
int main() {
        int n,choice;
        node* book = NULL;
        int bookId=0,available;
        node* current;
        char title[50], author[50];
        char username[100], password[100];
        User userInstance;
        
        namaste();
    do {
        printf("Login as a adminstrator (yes(1)) or (no(0))\n");
        scanf("%d", &n );
        
        if(n==1) {
            printf("username :\n");
            scanf("%s", username);
            printf("password :\n");
            scanf("%s", password);
            if(identification(username, password)) {
                    printf("Login Successfully\n");
        
                    do{
        
                        displayMenu();  
                        scanf("%d", &choice);

                        switch (choice) {
                        case 1:
                        // library = addBook(library);
                            printf("Enter Book ID: ");
                            scanf("%d", &bookId);
                            printf("Enter Title: ");
                            scanf("%s",title);
                            printf("Enter Author: ");
                            scanf("%s", author);
                            printf("Enter Available no.: ");
                            scanf("%d", &available);
                            book = addBookSorted(book, bookId, title, author,available);
                            break;
                        case 2:
                            displayBooks(book);
                            break;
                        case 3:
                            searchBook(book);
                            break;
                        case 4:
                            book = deleteBook(book, bookId);
                            break;   
                        case 5:
                            issueBook(book, &userInstance);
                            break;
                        case 6:
                            returnBook(book, &userInstance);
                            break;
                        case 7:
                            printf("Exiting the program.\n");
                            break;
                        default:
                            printf("\n\t\t\t\t      ...Invalid Option!...\n");
                            printf("\n\t\t\t\t      Press any key to try again: ");
                
        
                        } 
                    } while (choice != 7);
            } else {
	        printf("Invalid username or password. Please try again.\n");
            }
    
        } else if(n==0) {
            printf("username :\n");
            scanf("%s", username);
            printf("password :\n");
            scanf("%s", password);
            
            if(identificationuser(username, password)) {
                printf("Login Successfully\n");
                do {
        
                displayMenuUser();
                scanf("%d", &choice);

                switch (choice) {   
                    case 1:
                        displayBooks(book);
                        break;
                    case 2:
                        searchBook(book);
                        break;   
                    case 3:
                        issueBook(book, &userInstance);
                        break;
                    case 4:
                        returnBook(book, &userInstance);
                        break;
                    case 5:
                        printf("Exiting the program.\n");
                        break;
                    default:
                        printf("\n\t\t\t\t      ...Invalid Option!...\n");
                        printf("\n\t\t\t\t      Press any key to try again: ");
                
                    }
                } while (choice != 5);
            } else {
	                printf("Invalid username or password. Please try again.\n");
            }

        } else {
            printf("invalid\n");
            printf("try again\n");
        }
    } while(1);
    return 0;
    clrscr();
}



   