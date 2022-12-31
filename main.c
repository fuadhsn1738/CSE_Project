#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "splashscreen.h"
#include "login.h"
#include "menu.h"
#define EXIT 4

void menu(void);
void welcome_screen(void);

int main(void)
{
    char login_name[256], pass[50];
    int login_func, prompt;
    char amogus;  // to cancel out \n

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
        scanf("%c", &amogus);

        if(prompt == 1)
        {
            printf("OPTION SELECTED: 1\n\n");
            new_file();
            system("cls");
            menu();
            printf("> ");
            scanf("%d", &prompt);
            scanf("%c", &amogus);
        }
        if(prompt == 2)
        {
            search_file();
            menu();
            printf("> ");
            scanf("%d", &prompt);
            scanf("%c", &amogus);
        }
    }

    return 0;
}

/*function for the menu*/
void menu(void)
{
    printf("\n\n1. Create new patient file\n");
    printf("2. Search a patient file\n");
    printf("3. Discharge a patient\n");
    printf("4. Exit\n");
    printf("================================\n");
}

/*function for the welcome screen*/
void welcome_screen(void)
{
    printf("\n                          =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n                          =                                         WELCOME!!                              =");
    printf("\n                          =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}