#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "member.h"
#include "issue.h"

void print_menu() {
    printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
    printf("  BOOKS\n");
    printf("   1. Add Book\n");
    printf("   2. Remove Book\n");
    printf("   3. Search Book\n");
    printf("   4. Display All Books\n");
    printf("--------------------------------------\n");
    printf("  MEMBERS\n");
    printf("   5. Add Member\n");
    printf("   6. Remove Member\n");
    printf("   7. Display All Members\n");
    printf("--------------------------------------\n");
    printf("  ISSUE / RETURN\n");
    printf("   8. Issue Book\n");
    printf("   9. Return Book\n");
    printf("  10. View Issued Books\n");
    printf("--------------------------------------\n");
    printf("   0. Exit\n");
    printf("======================================\n");
    printf("  Choice: ");
}

int main() {
    int choice;
    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) { scanf("%*s"); continue; }

        printf("\n");
        switch (choice) {
            case 1:  add_book();        break;
            case 2:  remove_book();     break;
            case 3:  search_book();     break;
            case 4:  display_books();   break;
            case 5:  add_member();      break;
            case 6:  remove_member();   break;
            case 7:  display_members(); break;
            case 8:  issue_book();      break;
            case 9:  return_book();     break;
            case 10: display_issued();  break;
            case 0:
                printf("  Goodbye!\n");
                exit(0);
            default:
                printf("  [!] Invalid choice. Try again.\n");
        }
    }
    return 0;
}
