#include <stdio.h>
#include <stdlib.h>
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
    char x;  // to cancel out \n
    int y;

    logo();
    sleep(2);
    system("cls");

    printf("Enter username: ");
    gets(login_name);
    printf("Enter password: ");
    gets(pass);
    login_func = login(login_name, pass);

    while(login_func == 1) // loop that displays error after receiving 1 from void login function
    {
        printf("Wrong username and password. Try again!\n\n");
        printf("Enter username: ");
        gets(login_name);
        printf("Enter password: ");
        gets(pass);
        login_func = login(login_name, pass);
    }

    if (login_func == 0)  //if verify - 0 from void login
    {
        printf("Success!\nPLEASE WAIT. LOADING.........");
        sleep(1);
        system("cls");


        welcome_screen();
        menu();
        printf("> ");
        scanf("%d", &prompt);
        scanf("%c", &x);

        while(prompt != EXIT)
        {
            if(prompt == 1)
            {
                system("cls");
                printf("OPTION SELECTED: 1\n\n");
                new_file();
                sleep(1);
                system("cls");
            }

            if(prompt == 2)
            {
                system("cls");
                printf("OPTION SELECTED: 2\n\n");
                search_file();
                printf("\n\nPress 0 to continue: ");
                scanf("%d", &y);
                if(y == 0)
                {
                    system("cls");
                }
            }

            if(prompt == 3)
            {
                system("cls");
                printf("OPTION SELECTED: 3\n\n");
                discharge_patient();
                printf("\n\nPress 0 to continue: ");
                scanf("%d", &y);
                if(y == 0)
                {
                    system("cls");
                }
            }

            menu();
            printf("> ");
            scanf("%d", &prompt);
            scanf("%c", &x);
        }
        if(prompt == EXIT)
        {
            printf("\nProgram terminated\n");
            printf("Thank you!");
        }
    }

    return 0;
}

/*function for the menu*/
void menu(void)
{
    printf("\nSelect an option:\n1. Create new patient file\n");
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

