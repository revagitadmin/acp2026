/*student records with binary file handling
void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename );
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);
*/
#include<stdio.h>
typedef struct
{
    char n[50];
    int r;
    float m;
}Student;
void inputStudents(Student students[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("enter the name of the students:\n");
    scanf("%s",students[i].n);
    printf("enter the roll number:\n");
scanf("%d",&students[i].r);
printf("enter the marks:\n");
scanf("%f",&students[i].m);

    }

}
void writeToBinaryFile(Student students[], int n,const char *filename)
{
    FILE *file =fopen(filename,"wb");
    if(file==NULL)
    {
        printf("erro opening file\n");
        return;
    }
    fwrite(students,sizeof(Student),n,file);
    fclose(file);

}
int readFromBinaryFile(Student students[],const char *filename)
{
    FILE *file =fopen(filename,"rb");
    if(file==NULL){
        printf("error opening file\n");
        return 0;
    }
    int count =fread(students,sizeof(Student),100,file);
    fclose(file);
    return count;
}
void printStudents(Student students[],int n)
{
    printf("name\troll number\tmarks\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\t%.2f\n",students[i].n,students[i].r,students[i].m);

    }

}
int main()
{
    Student students[100];
    int n;
    printf("enter the number of students:\n");
    scanf("%d",&n);
    inputStudents(students,n);
    writeToBinaryFile(students,n,"students.dat");
    int count= readFromBinaryFile(students,"students.dat");
    printf("students read from binary file:\n");
    printStudents(students,count);
    return 0;
}