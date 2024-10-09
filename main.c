#include <stdio.h>
#include <string.h>

struct User {
    char name[1000];
    char surname[1000];
    char email[1000];
};

void rewrite(struct User *users) {
    printf("Which use are you gonna rewrite? (Tell me the user number)\n");
    int rewrite;
    for (int i = 0; i < 30; ++i) {
        if (strcmp(users[i].name, "") != 0) {
            printf("%s%d%s%s\n", "User number ", i, ": ", users[i].name);
        }
    }
    scanf("%d", &rewrite);

    char name[1000];
    char surname[1000];
    char email[1000];
    printf("Enter name:");
    scanf("%s", name);
    printf("Enter surname:");
    scanf("%s", surname);
    printf("Enter email:");
    scanf("%s", email);
    strcpy(users[rewrite].name, name);
    strcpy(users[rewrite].surname, surname);
    strcpy(users[rewrite].email, email);
}

void deleteUser(struct User *users) {
    int delete;
    printf("What user do you want to delete?\n");
    for (int i = 0; i < 30; ++i) {
        if (strcmp(users[i].name, "") != 0) {
            printf("%s%d%s%s\n", "User number ", i, ": ", users[i].name);
        }
    }
    scanf("%d", &delete);
    strcpy(users[delete].name, "");
    strcpy(users[delete].surname, "");
    strcpy(users[delete].email, "");
}

void addUser(char *name, char *surname, char *email, struct User *users) {
    int added = 0;
    for (int i = 0; i < 30; ++i) {
        if (strcmp(users[i].name, "") == 0) {
            strcpy(users[i].name, name);
            strcpy(users[i].surname, surname);
            strcpy(users[i].email, email);
            printf("Uzivatel vytvoren\n");
            added = 1;
            break;
        }
    }
    if (!added) {
        printf("Ucty jsou plne, nemuzete pridat dalsiho uzivatele\n");
    }
}

int main(void) {
    struct User user[30];
    for (int i = 0; i < 30; ++i) {
        strcpy(user[i].name, "");
    }
    for (int i = 0; i < 10;) {
        char option;
        printf("\nVyber si jednu z moznosti\n1) Pridat ucet\n2) Odebrat ucet\n3) Prepsat\n4) Vypnout\n");
        scanf(" %c", &option);
        switch (option) {
            case '1':
                char name[1000];
                char surname[1000];
                char email[1000];
                printf("Enter name:");
                scanf("%s", name);
                printf("Enter surname:");
                scanf("%s", surname);
                printf("Enter email:");
                scanf("%s", email);
                addUser(name, surname, email, user);
                break;
            case '2':
                deleteUser(user);
                break;
            case '3':
                rewrite(user);
                break;
            case '4':
                for (int i = 0; i < 30; ++i) {
                    if (strcmp(user[i].name, "") != 0) {
                        printf("%s%d%s%s%s%s%s%s\n", "This is name number ", i, ": Name: ", user[i].name, ", Email: ",
                               user[i].email, ", surname: ", user[i].surname);
                    }
                }
                printf("%s", "Vypinam");

                return 1;
            default:
                printf("%s", "Napsal jsi neco spatne, zkus to znovu");
                break;
        }
    }
}
