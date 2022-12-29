#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define EXIT 4

void logo(void);
char login(char username[256], char password[50]);
void menu(void);
void welcome_screen(void);

int main(void)
{
    char login_name[256], pass[50];
    int login_func, prompt;

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
    }

    return 0;
}

void logo (void)
{
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
   printf("#########################################################################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
                             printf("                        ######################\n");
    printf("PLEASE WAIT. LOADING.........");
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