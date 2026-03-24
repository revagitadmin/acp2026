#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
    char grade;
} Student;

void inputStudents(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter ID: ");
        scanf("%d", &s[i].id);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);

        if (s[i].marks >= 85) s[i].grade = 'A';
        else if (s[i].marks >= 70) s[i].grade = 'B';
        else if (s[i].marks >= 50) s[i].grade = 'C';
        else s[i].grade = 'F';
    }
}

void printStudents(Student s[], int n) {
    printf("\nStudent Grades:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f, Grade: %c\n", s[i].id, s[i].name, s[i].marks, s[i].grade);
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student s[n];
    inputStudents(s, n);
    printStudents(s, n);

    return 0;
}