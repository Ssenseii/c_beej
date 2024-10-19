#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    int age;
    float gpa;
} Student;

int main(void)
{
    Student record[1024];
    int count = 0;
    int found;

    int choice;

    Student temp;
    int searchterm;

    FILE *fp;

    printf("\n\n>========== Welcome To The Student Records ==========<\n");

    while (1)
    {

        printf("\n\nPick your choice\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search for Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student Student\n");
        printf("6. Save Records\n");
        printf("7. Load Records\n");
        printf("0. Exit Program\n");

        printf("Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            // Add Student
        case 1:
            printf("\n\n");
            printf("> Adding a Student... ");
            printf("\n");
            printf("> Enter Student Name: ");
            scanf("%s", &temp.name);
            printf("> Enter Student Age: ");
            scanf("%d", &temp.age);
            printf("> Enter Student GPA: ");
            scanf("%f", &temp.gpa);

            temp.id = rand() % 10000;

            printf("\nCreating Student...");
            printf("\nID: %d, Name: %s, Age: %d, GPA: %.2f", temp.id, temp.name, temp.age, temp.gpa);
            record[count] = temp;
            count++;
            printf("\nStudent Created Succesfully !!");
            printf("\nCurrent Student Count: %d", count);
            break;

        // print all student records
        case 2:
            printf("\nAll Students...");
            printf("\nCurrent Student Count: %d", count);
            for (int i = 0; i < count; i++)
            {
                printf("\nID: %d, Name: %s, Age: %d, GPA: %.2f", record[i].id, record[i].name, record[i].age, record[i].gpa);
            }
            break;

        // Search for a student using their IDs
        case 3:
            printf("\nSearching for a Student...");
            printf("\nEnter Student ID:");
            scanf("%d", &searchterm);
            found = 0;

            for (int i = 0; i < count; i++)
            {
                if (record[i].id == searchterm)
                {
                    found = 1;
                    printf("\nStudent Found.");
                    printf("\nID: %d, Name: %s, Age: %d, GPA: %.2f", record[i].id, record[i].name, record[i].age, record[i].gpa);
                    break;
                }
            }

            if (!found)
            {
                printf("Student Not Found.");
            }
            break;

        // updating a record
        case 4:
            printf("\nUpdating for a Student...");
            printf("\nEnter Student ID:");
            scanf("%d", &searchterm);
            found = 0;

            for (int i = 0; i < count; i++)
            {
                if (record[i].id == searchterm)
                {
                    found = 1;
                    printf("\nStudent Found.");
                    printf("\nID: %d, Name: %s, Age: %d, GPA: %.2f", record[i].id, record[i].name, record[i].age, record[i].gpa);
                    printf("\n> Enter New Student Name: ");
                    scanf("%s", &record[i].name);
                    printf("> Enter New Student Age: ");
                    scanf("%d", &record[i].age);
                    printf("> Enter New Student GPA: ");
                    scanf("%f", &record[i].gpa);
                    printf("\nStudent Updated.");
                    printf("\nID: %d, Name: %s, Age: %d, GPA: %.2f", record[i].id, record[i].name, record[i].age, record[i].gpa);
                    break;
                }
            }

            if (!found)
            {
                printf("Student Not Found.");
            }
            break;

        /// Deleting a record.
        case 5:
            printf("\nDeleting for a Student...");
            printf("\nEnter Student ID:");
            scanf("%d", &searchterm);
            found = 0;

            for (int i = 0; i < count; i++)
            {
                if (record[i].id == searchterm)
                {
                    found = 1;
                    printf("\nStudent Found.");
                    for (int j = i; j < count; j++)
                    {
                        record[j] = record[j + 1];
                    }
                    count--;
                    printf("\nStudent Removed.");
                    printf("\nCurrent Student Count: %d.", count);
                    break;
                }
            }

            if (!found)
            {
                printf("Student Not Found.");
            }
            break;

        /// Saving Records
        case 6:
            printf("\nSaving Records...");
            fp = fopen("records.txt", "w");

            fprintf(fp, "%d\n", count);

            for (int i = 0; i < count; i++)
            {
                fprintf(fp, "ID: %d, Name: %s, Age: %d, GPA: %.2f\n", record[i].id, record[i].name, record[i].age, record[i].gpa);
            }

            fclose(fp);
            break;

        /// Loading Records
        case 7:
            printf("\nLoading Records...");
            fp = fopen("records.txt", "r");

            /// Later When I'm More Free

            fclose(fp);
            break;

        case 0:
            printf("\n Closing Program...");
            return 0;

        default:
            printf("Wrong Input, Try Again...");
            break;
        }
    }
}