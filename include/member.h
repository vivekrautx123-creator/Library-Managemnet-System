#ifndef MEMBER_H
#define MEMBER_H

#define MAX_MEMBERS 50

typedef struct {
    int id;
    char name[100];
    char email[100];
    int issued_book_id; // -1 if none
} Member;

extern Member members[MAX_MEMBERS];
extern int member_count;

void add_member();
void remove_member();
void display_members();
int find_member_by_id(int id);

#endif
