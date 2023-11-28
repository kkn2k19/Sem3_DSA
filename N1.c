/*1. Suppose you have to store the 100 frequently used words list. Write a menu-driven program in C to store those words through Hashing mechanism so that searching for those words can be fast. You can use the following function

MyHash(string:: key)
{
    k= length of String key
    initialize u=0,n=0;
    for each character, key[i], do:
           n = ASCII (key[i])
           u+=i*n%31;
   next character
   return u%139;
}

A few examples of frequently used words are given below: EOD, FAQ, AKA, ASAP, DIY, LMGTFY, NP, N/A, 000, TIA

EOD: End of day
FAQ: Frequently asked question
AKA: Also known as
ASAP: As soon as possible
DIY: Do it yourself
LMGTFY: Let me Google that for you
NP: No problem
N/A: Not applicable or not available
000: Out of office
TIA: Thanks in advance
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 139

typedef struct Node {
    char word[20];
    struct Node* next;
} Node;

unsigned int myHash(char* key) {
    int k = strlen(key);
    unsigned int u = 0, n = 0;
    for (int i = 0; i < k; ++i) {
        n = key[i];
        u += i * n % 31;
    }
    return u % TABLE_SIZE;
}

void insertWord(Node* hashTable[], char* word) {
    unsigned int index = myHash(word);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void searchWord(Node* hashTable[], char* word) {
    unsigned int index = myHash(word);
    Node* current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            printf("%s found at index %u.\n", word, index);
            return;
        }
        current = current->next;
    }

    printf("%s not found.\n", word);
}

void displayTable(Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf("%d: ", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("%s -> ", current->word);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* hashTable[TABLE_SIZE] = { NULL };

    char* words[] = {
        "EOD", "FAQ", "AKA", "ASAP", "DIY", "LMGTFY", "NP", "N/A", "000", "TIA"
    };

    for (int i = 0; i < 10; ++i) {
        insertWord(hashTable, words[i]);
    }

    int choice;
    char searchWordInput[20];

    do {
        printf("\nMenu:\n");
        printf("1. Search for a word\n");
        printf("2. Display hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the word to search: ");
                scanf("%s", searchWordInput);
                searchWord(hashTable, searchWordInput);
                break;
            case 2:
                displayTable(hashTable);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
