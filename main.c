#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "splashscreen.h"
#define EXIT 4

char login(char username[256], char password[50]);
void menu(void);
void welcome_screen(void);
void new_file(void);

int main(void)
{
    char login_name[256], pass[50];
    int login_func, prompt;
    char amogus;

    logo();
    sleep(2);
    system("cls");

    printf("Enter username: ");
    gets(login_name);
    printf("Enter password: ");
    gets(pass);
    login_func = login(login_name, pass);

    while(login_func == 1)
    {
        printf("Wrong username and password. Try again!\n\n");
        printf("Enter username: ");
        gets(login_name);
        printf("Enter password: ");
        gets(pass);
        login_func = login(login_name, pass);
    }
    if (login_func == 0)
    {
        printf("Success!\nPLEASE WAIT. LOADING.........");
        sleep(1);
        system("cls");
        welcome_screen();
        menu();
        printf("> ");
        scanf("%d", &prompt);
        amogus = getchar();
        if(prompt == 1)
        {
            new_file();
            menu();
            printf("> ");
            scanf("%d", &prompt);
            amogus = getchar();
        }
    }

    return 0;
}

char login(char username[256], char password[50])
{
    char default_login[] = "hospital";
    char default_password[] = "hospital123";
    int verify;

    while((strcmp(default_login, username)) && (strcmp(default_password, password)))
    {
        verify = 1;
        return verify;  
    }
    while((strcmp(username, default_login)) && (strcmp(password, default_password)))
    {
        verify = 1;
        return verify;
    }
    if((!strcmp(default_login, username)) && (!strcmp(default_password, password)))
    {
        verify = 0;
    }

     return verify;
}

void menu(void)
{
    printf("\n\n1. Create new patient file\n");
    printf("2. Search a patient file\n");
    printf("3. Discharge a patient\n");
    printf("4. Exit\n");
    printf("================================\n");
}

void welcome_screen(void)
{
    printf("\n                          =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n                          =                                         WELCOME!!                              =");
    printf("\n                          =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}

void new_file(void)
{
    char new_file[128];
    char name[256], address[256], phone_number[20];

    printf("Enter file name: ");
    gets(new_file);
    strcat(new_file, ".txt");
    FILE *file;
    file = fopen(new_file, "a");

    printf("Enter patient's name: ");
    gets(name);
    fprintf(file, "Patient's name: %s\n", name);
    printf("Enter address: ");
    gets(address);
    fprintf(file, "Address: %s\n", address);

    printf("Enter phone number: ");
    gets(phone_number);
    fprintf(file, "Phone number: %s\n", phone_number);

    fclose(file);
}