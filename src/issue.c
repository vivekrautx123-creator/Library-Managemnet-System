#include <stdio.h>
#include "issue.h"
#include "book.h"
#include "member.h"

void issue_book() {
    int mid, bid;
    printf("  Enter Member ID : "); scanf("%d", &mid);
    int mi = find_member_by_id(mid);
    if (mi == -1) { printf("  [!] Member not found.\n"); return; }
    if (members[mi].issued_book_id != -1) {
        printf("  [!] Member already has Book #%d issued. Return it first.\n", members[mi].issued_book_id);
        return;
    }

    printf("  Enter Book ID   : "); scanf("%d", &bid);
    int bi = find_book_by_id(bid);
    if (bi == -1) { printf("  [!] Book not found.\n"); return; }
    if (!books[bi].available) { printf("  [!] Book is not available.\n"); return; }

    books[bi].available = 0;
    members[mi].issued_book_id = bid;
    printf("  [✓] \"%s\" issued to %s.\n", books[bi].title, members[mi].name);
}

void return_book() {
    int mid;
    printf("  Enter Member ID : "); scanf("%d", &mid);
    int mi = find_member_by_id(mid);
    if (mi == -1) { printf("  [!] Member not found.\n"); return; }
    if (members[mi].issued_book_id == -1) {
        printf("  [!] This member has no issued book.\n");
        return;
    }

    int bid = members[mi].issued_book_id;
    int bi = find_book_by_id(bid);
    if (bi != -1) books[bi].available = 1;

    members[mi].issued_book_id = -1;
    printf("  [✓] Book #%d returned successfully.\n", bid);
}

void display_issued() {
    int found = 0;
    printf("\n  %-20s  ->  %s\n", "Member", "Book");
    printf("  %-20s  ->  %s\n", "-------------------", "-----------------------------");
    for (int i = 0; i < member_count; i++) {
        if (members[i].issued_book_id != -1) {
            int bi = find_book_by_id(members[i].issued_book_id);
            char *title = (bi != -1) ? books[bi].title : "Unknown";
            printf("  %-20s  ->  %s\n", members[i].name, title);
            found++;
        }
    }
    if (!found) printf("  [!] No books currently issued.\n");
}
