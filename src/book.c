#include <stdio.h>
#include <string.h>
#include "book.h"

Book books[MAX_BOOKS];
int book_count = 0;

int find_book_by_id(int id) {
    for (int i = 0; i < book_count; i++)
        if (books[i].id == id) return i;
    return -1;
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("  [!] Library is full!\n");
        return;
    }
    Book b;
    b.id = (book_count > 0) ? books[book_count - 1].id + 1 : 1;

    printf("  Title  : "); scanf(" %[^\n]", b.title);
    printf("  Author : "); scanf(" %[^\n]", b.author);
    b.available = 1;

    books[book_count++] = b;
    printf("  [+] Book added! (ID: %d)\n", b.id);
}

void remove_book() {
    int id;
    printf("  Enter Book ID to remove: "); scanf("%d", &id);
    int i = find_book_by_id(id);
    if (i == -1) { printf("  [!] Book not found.\n"); return; }
    if (!books[i].available) { printf("  [!] Cannot remove — book is currently issued.\n"); return; }

    books[i] = books[--book_count];
    printf("  [-] Book removed.\n");
}

void search_book() {
    char query[100];
    printf("  Search by title: "); scanf(" %[^\n]", query);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(books[i].title, query) || strstr(books[i].author, query)) {
            printf("  [%d] \"%s\" by %s — %s\n",
                books[i].id, books[i].title, books[i].author,
                books[i].available ? "Available" : "Issued");
            found++;
        }
    }
    if (!found) printf("  [!] No matching books found.\n");
}

void display_books() {
    if (book_count == 0) { printf("  [!] No books in library.\n"); return; }
    printf("\n  %-5s %-30s %-25s %s\n", "ID", "Title", "Author", "Status");
    printf("  %-5s %-30s %-25s %s\n", "----", "-----------------------------", "------------------------", "--------");
    for (int i = 0; i < book_count; i++) {
        printf("  %-5d %-30s %-25s %s\n",
            books[i].id, books[i].title, books[i].author,
            books[i].available ? "Available" : "Issued");
    }
}
