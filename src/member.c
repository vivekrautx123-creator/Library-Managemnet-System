#include <stdio.h>
#include <string.h>
#include "member.h"

Member members[MAX_MEMBERS];
int member_count = 0;

int find_member_by_id(int id) {
    for (int i = 0; i < member_count; i++)
        if (members[i].id == id) return i;
    return -1;
}

void add_member() {
    if (member_count >= MAX_MEMBERS) {
        printf("  [!] Member limit reached!\n");
        return;
    }
    Member m;
    m.id = (member_count > 0) ? members[member_count - 1].id + 1 : 1;

    printf("  Name  : "); scanf(" %[^\n]", m.name);
    printf("  Email : "); scanf(" %[^\n]", m.email);
    m.issued_book_id = -1;

    members[member_count++] = m;
    printf("  [+] Member added! (ID: %d)\n", m.id);
}

void remove_member() {
    int id;
    printf("  Enter Member ID to remove: "); scanf("%d", &id);
    int i = find_member_by_id(id);
    if (i == -1) { printf("  [!] Member not found.\n"); return; }
    if (members[i].issued_book_id != -1) {
        printf("  [!] Cannot remove — member has an issued book. Ask them to return it first.\n");
        return;
    }
    members[i] = members[--member_count];
    printf("  [-] Member removed.\n");
}

void display_members() {
    if (member_count == 0) { printf("  [!] No members registered.\n"); return; }
    printf("\n  %-5s %-25s %-30s %s\n", "ID", "Name", "Email", "Issued Book");
    printf("  %-5s %-25s %-30s %s\n", "----", "------------------------", "-----------------------------", "-----------");
    for (int i = 0; i < member_count; i++) {
        char issued[20];
        if (members[i].issued_book_id == -1)
            snprintf(issued, sizeof(issued), "None");
        else
            snprintf(issued, sizeof(issued), "Book #%d", members[i].issued_book_id);
        printf("  %-5d %-25s %-30s %s\n",
            members[i].id, members[i].name, members[i].email, issued);
    }
}
