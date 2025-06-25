#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

struct node {
    int bookId;
    char title[50];
    char author[50];
    int available;
    struct node* next;
    
};


typedef struct node node;
typedef struct User user;

// Function declarations

//Book* addBook(Book* library);
void displayBooks(const node* book);
node* addBookSorted(node* book, int bookId, const char* title, const char* author,int available) ;
void searchBook(node* book);
node* deleteBook(node* book, int bookId);
void issueBook(node* book, User* user);
void returnBook(node* book, User* user);



//function to add a book

node* addBookSorted(node* book, int bookId, const char* title, const char* author, int available) {
    node* newBook = (node*)malloc(sizeof(node));

    if (newBook == NULL) {
        printf("Memory allocation failed.\n");
        return book;
    }
    newBook->bookId = bookId;

    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    strncpy(newBook->author, author, sizeof(newBook->author) - 1);
    
    newBook->available = available;
    newBook->next = NULL;
    if (book == NULL || bookId < book->bookId) {
        // Insert at the beginning
        newBook->next = book;
        book = newBook;
    } else {
        // Insert in sorted order
        node* current = book;
        node* prev = NULL;

        while (current != NULL && bookId >= current->bookId) {
            prev = current;
            current = current->next;
        }

        if (prev != NULL) {
            prev->next = newBook;
        }
        newBook->next = current;
    }
    printf("Book added successfully.\n");
    return book;
}



// Function to display the linked list of books
void displayBooks(const node* book) {
    const node* current = book;

    printf("\nBook List\n");
    printf("-----------------------------------------------------------------\n");
    printf("Book ID\t\tTitle\t\tAuthor\t\tAvailable Copies\n");
    printf("-----------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%d\t\t%s\t\t%s\t\t%d\n", current->bookId, current->title, current->author, current->available);
        current = current->next;
    }
}




//function to search any book
void searchBook(node* book) {
    int bookId;
    printf("Enter the Book ID to search: ");
    scanf("%d", &bookId);

    while (book != NULL) {
        if (book->bookId == bookId) {
            printf("Book found!\n");
            printf("Book ID: %d\nTitle: %s\nAuthor: %s\n", book->bookId, book->title, book->author);
            return;
        }
        book = book->next;
    }
    printf("Book not found.\n");
}




//function to delete any book

node* deleteBook(node* book, int bookId) {
    node* current = book;
    node* prev = NULL;

    while (current != NULL) {
        if (current->bookId == bookId) {
            if (prev == NULL) {
                // Deleting the first node
                book = current->next;
            } else {
                //Deleting other node
                prev->next = current->next;
            }
            free(current);
            printf("Book deleted successfully.\n");
            return book;
        }
        prev = current;
        current = current->next;
    }
    printf("Book not found.\n");
    return book;
}




//function to issued  book
void issueBook(node* book, User* user) {
    int bookId;

    // Display the available books
    displayBooks(book);

    printf("Enter the Book ID to issue: ");
    scanf("%d", &bookId);

    node* current = book;
    while (current != NULL) {
        if (current->bookId == bookId && current->available > 0) {
            current->available--;
            user->booksIssued++;
            printf("Book issued successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Book not available or invalid Book ID.\n");
}




//function to return books
void returnBook(node* book, User* user) {
    int bookId;
    printf("Enter the Book ID to return: ");
    scanf("%d", &bookId);

    node* current = book;
    while (current != NULL) {
        if (current->bookId == bookId && user->booksIssued > 0) {
            current->available++;
            user->booksIssued--;
            printf("Book returned successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Book not issued to the student or invalid Book ID.\n");
}
