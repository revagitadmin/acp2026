#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void inputEmployees(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter ID: ");
        scanf("%d", &emp[i].id);
        printf("Enter Name: ");
        scanf("%s", emp[i].name);
        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }
}

void writeEmployees(Employee emp[], int n, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fwrite(emp, sizeof(Employee), n, fp);
    fclose(fp);
}

void readEmployees(Employee emp[], int n, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    fread(emp, sizeof(Employee), n, fp);
    fclose(fp);
}

void printEmployees(Employee emp[], int n) {
    printf("\nEmployee Records:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee emp[n];
    inputEmployees(emp, n);
    writeEmployees(emp, n, "employees.bin");

    Employee readEmp[n];
    readEmployees(readEmp, n, "employees.bin");
    printEmployees(readEmp, n);

    return 0;
}