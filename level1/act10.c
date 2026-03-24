#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Input student details
void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }
}

// Write to binary file
void writeToBinaryFile(Student students[], int n, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(students, sizeof(Student), n, fp);
    fclose(fp);
}

// Read from binary file
int readFromBinaryFile(Student students[], const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    int count = 0;
    while (fread(&students[count], sizeof(Student), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}

// Display students
void printStudents(Student students[], int n) {
    printf("\nStudent Records (Binary File):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];
    inputStudents(students, n);

    writeToBinaryFile(students, n, "students.bin");

    Student readStudents[n];
    int count = readFromBinaryFile(readStudents, "students.bin");

    printStudents(readStudents, count);

    return 0;
}