#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#endif


char login(char username[256], char password[50])
{
    int verify;
    FILE *inp = fopen("user info.txt", "r");
    char user_info[255];
    fgets(user_info, 255, inp);
    fclose(inp);

    if (strstr(user_info, username) != NULL && strstr(user_info, password) != NULL)
    {
        verify = 0;
    } else
    {
        verify = 1;
    }

    return verify;
}
