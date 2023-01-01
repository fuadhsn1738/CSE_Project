#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#endif

/*function for creating a new patient file*/
void new_file(void)
{
    char new_file[128];
    char directory[] = "D://Courses//CSE115+L//CSE_Project//Patient_files//";

    char name[256], ID[10], blood_group[5], disease[256], gender[155], total_amount[256], admission_date[25];
    char address[256], phone_number[20], father_name[256], mother_name[256];

    printf("Enter file name: ");
    gets(new_file);

    strcat(new_file, ".txt"); // concatonates the custom file name with .txt
    strcat(directory, new_file);  // concatonates the directory with custom file

    FILE *file;
    file = fopen(directory, "a");

    /*from line 23-66, the user is prompted to write their info and is read in using the gets() function and printed onto the custom file*/
    printf("Enter patient's name: ");
    gets(name);
    fprintf(file, "Patient's name: %s\n", name);

    printf("Enter patient's ID: ");
    gets(ID);
    fprintf(file, "Patient's ID: %s\n", ID);

    printf("Enter patient's gender: ");
    gets(gender);
    fprintf(file, "Gender: %s\n", gender);

    printf("Blood group: ");
    gets(blood_group);
    fprintf(file, "Blood group: %s\n", blood_group);

    printf("Enter patient's father's name: ");
    gets(father_name);
    fprintf(file, "Father's name: %s\n", father_name);

    printf("Enter patient's mother's name: ");
    gets(mother_name);
    fprintf(file, "Mother's name: %s\n", mother_name);

    printf("Enter disease: ");
    gets(disease);
    fprintf(file, "Disease: %s\n", disease);

    printf("Total hospital bill: ");
    gets(total_amount);
    fprintf(file, "Total charge: TK.%s\n", total_amount);

    printf("Enter patient's number: ");
    gets(phone_number);
    fprintf(file, "Phone number: %s\n", phone_number);

    printf("Enter patient's address: ");
    gets(address);
    fprintf(file, "Address: %s\n", address);

    printf("Enter date of admission(dd/mm/yyyy): ");
    gets(admission_date);
    fprintf(file, "Admission date: %s\n", admission_date);

    fclose(file);
    printf("File created successfully!");
}

/*function for searchin a patient file*/
void search_file(void)
{
    char file_search[128];
    char directory[] = "D://Courses//CSE115+L//CSE_Project//Patient_files//";
    char buffer[255];

    printf("Enter file name: ");
    gets(file_search);
    printf("\n\n%s's record\n======================\n", file_search);

    strcat(file_search, ".txt"); // concatenates the custom file name with .txt
    strcat(directory, file_search);  // concatenates the custom file with directory

    FILE *read_file;
    read_file = fopen(directory, "r");

    /*the WHILE loop prints each line into the buffer variable and puts() it onto the display till the end of file is reached*/
    while(!feof(read_file))
    {
        fgets(buffer, 255, read_file);
        puts(buffer);
    }

    fclose(read_file);

}

/*function to discharge a patient*/
void discharge_patient(void)
{
    char discharge[128];
    char directory[] = "D://Courses//CSE115+L//CSE_Project//Patient_files//";
    char temp[255];

    printf("Enter file name: ");
    gets(discharge);

    strcat(discharge, ".txt"); 
    strcat(directory, discharge);

    FILE *discharge_confirm;
    discharge_confirm = fopen(directory, "a+");

    while(!feof(discharge_confirm))
    {
        fgets(temp, 255, discharge_confirm);
    }

    strcpy(temp, "DISCHARGED");
    fprintf(discharge_confirm, "\nSTATUS: %s\n", temp);

    fclose(discharge_confirm);
}