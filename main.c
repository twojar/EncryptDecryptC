#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 4096


int main(int argc, char* argv[]) {
    int KEY_NUM = 7711;
    char buffer[BUFF_SIZE];

    int selected;
    printf("Press 1 to Encrypt\nPress 2 to Decrypt\n");
    scanf("%d", &selected);
    if (selected == 1) {
        FILE *pFin = fopen("../Input.txt", "r");
        FILE *pFout = fopen("../Encrypted.txt", "w");
        if (!pFin || !pFout) {
            perror("Failed to open file(s)");
            exit(1);
        }

        printf("Encrypting File to Encrypted.txt...");
        while (fgets(buffer,sizeof(buffer), pFin) != 0) {
            int n = strlen(buffer);
            for (int i = 0; i < n; i++) {
                buffer[i] = buffer[i] - 45;
            }
            fputs(buffer,pFout);
        }
        fclose(pFin);
        fclose(pFout);
        printf("File Encrypted Successfully\n");
    }
    if (selected == 2) {
        int userKeyInput;
        printf("Enter Password:\n");
        scanf("%d", &userKeyInput);
        if (userKeyInput != KEY_NUM) {
            printf("PASSWORD INCORRECT\nTERMINATING PROGRAM");
            exit(1);
        }
        if (userKeyInput == KEY_NUM) {
            FILE *pFin = fopen("../Decrypted.txt", "w");
            FILE *pFout = fopen("../Encrypted.txt", "r");
            if (!pFin || !pFout) {
                perror("Failed to open file(s)");
                exit(1);
            }
            printf("KEY ACCEPTED\n");
            printf("Decrypting File...\n");
            fopen("../Encrypted.txt", "r");
            while (fgets(buffer,sizeof(buffer), pFout) != 0) {
                int n = strlen(buffer);
                for (int i = 0; i < n; i++) {
                    buffer[i] = buffer[i] + 45;
                }
                fputs(buffer,pFin);
            }
            fclose(pFout);
            fclose(pFin);
            printf("File Decrypted Successfully\n");
        }
    }
    return 0;
}