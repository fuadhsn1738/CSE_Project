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
    fprintf(file, "Total charge: %s\n", total_amount);

    printf("Enter patient's number: ");
    gets(phone_number);
    fprintf(file, "Phone number: %s\n", phone_number);

    printf("Enter patient's address: ");
    gets(address);
    fprintf(file, "Address: %s\n", address);

    printf("Enter date of admission(dd/mm/yyyy): ");
    gets(admission_date);
    fprintf(file, "Admission date: %s\n", admission_date);

    fprintf(file, "STATUS: ADMITTED");

    fclose(file);
}

/*function for searchin a patient file*/
void search_file(void)
{
    system("cd Patient_files");
    system("dir /b");
}
