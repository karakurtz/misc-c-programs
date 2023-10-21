#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for representing book information
typedef struct Book {
    char title[100];
    float price;
    int pages;
    char language[20];
    float weight;
    int publicationYear;
    struct Book* next;
} Book;

// Function to create a new book
Book* createBook(const char title[], float price, int pages, const char language[], float weight, int publicationYear) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        return NULL;
    }

    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->publicationYear = publicationYear;
    newBook->next = NULL;

    return newBook;
}

// Function to add a book to the end of the linked list
void addBookToList(Book** head, Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
    } else {
        Book* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }
}

// Function to print information about all books in the linked list
void printBookList(const Book* head) {
    const Book* current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Price (USD): %.2f\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight (kg): %.2f\n", current->weight);
        printf("Publication year: %d\n", current->publicationYear);
        printf("\n");
        current = current->next;
    }
}

// Function to free all books in the linked list
void freeBookList(Book* head) {
    while (head != NULL) {
        Book* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Book* bookList = NULL;

    // Adding books to the linked list
    addBookToList(&bookList, createBook("Harry Potter and the Philosopher's Stone", 10.65, 223, "English", 0.24, 1997));
    addBookToList(&bookList, createBook("Harry Potter and the Chamber of Secrets", 17.83, 251, "English", 0.41, 1998));
    addBookToList(&bookList, createBook("Harry Potter and the Prisoner of Azkaban", 28.74, 317, "English", 0.48, 1999));
    addBookToList(&bookList, createBook("Harry Potter and the Goblet of Fire", 17.27, 636, "English", 0.51, 2000));
    addBookToList(&bookList, createBook("Harry Potter and the Order of the Phoenix", 18.07, 766, "English", 0.65, 2003));
    addBookToList(&bookList, createBook("Harry Potter and the Half-Blood Prince", 18.88, 607, "English", 0.45, 2005));
    addBookToList(&bookList, createBook("Harry Potter and the Deathly Hallows", 21.63, 607, "English", 0.51, 2007));

    // Printing information about all books in the linked list
    printBookList(bookList);

    // Freeing books and memory
    freeBookList(bookList);

    return 0;
}
