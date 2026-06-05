#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int available; // 1 = available, 0 = issued
} Book;

extern Book books[MAX_BOOKS];
extern int book_count;

void add_book();
void remove_book();
void search_book();
void display_books();
int find_book_by_id(int id);

#endif
