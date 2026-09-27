#include<stdio.h>

typedef struct{
    int id;
    char name[50];
    float marks;
} Student;

void inputStudents(Student students[], int n){
    for(int i=0;i<n;i++){
        printf("\nEnter details of Student %d\n",i+1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s",students[i].name);

        printf("Marks: ");
        scanf("%f",&students[i].marks);
    }
}

void writeToTextFile(Student students[], int n, const char *filename){
    FILE *fp = fopen(filename,"w");

    if(fp == NULL){
        printf("Error opening file for writing.\n");
        return;
    }

    for(int i=0;i<n;i++){
        fprintf(fp,"%d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].marks);
    }

    fclose(fp);
    printf("\nData written to file successfully.\n");
}

int readFromTextFile(Student students[], const char *filename){
    FILE *fp = fopen(filename,"r");

    if(fp == NULL){
        printf("Error opening file for reading.\n");
        return 0;
    }

    int i = 0;

    while(fscanf(fp,"%d %s %f",
                 &students[i].id,
                 students[i].name,
                 &students[i].marks) == 3){
        i++;
    }

    fclose(fp);
    return i;
}

void printStudents(Student students[], int n){
    printf("\nID\tName\tMarks\n");

    for(int i=0;i<n;i++){
        printf("%d\t%s\t%.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks);
    }
}

int main(){
    int n, count;

    printf("Enter number of students: ");
    scanf("%d",&n);

    Student students[n], studentsFromFile[n];

    inputStudents(students,n);

    writeToTextFile(students,n,"students.txt");

    count = readFromTextFile(studentsFromFile,"students.txt");

    printf("\nData read from file:\n");
    printStudents(studentsFromFile, count);

    return 0;
}