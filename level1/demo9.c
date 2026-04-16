/*students record with file handling*/
#include<stdio.h>
typedef struct{
  char name[50];
  int r;
  float m;
}stud;

void inputStudents(stud s[],int n)
{
for(int i=0;i<n;i++){
printf("enter the name of the student:\n");
scanf("%s",s[i].name);
printf("enter the roll number of the student:\n");
scanf("%d",&s[i].r);
printf("enter the marks of the student:\n");
scanf("%f",&s[i].m);
}
}

void writeToTextFile(stud s[],int n, const char *filename)
{
 FILE *file =fopen(filename,"w");
 if(file==NULL)
 {
    printf("error opening file\n");
    return;
}   
 for(int i=0;i<n;i++)
 {
 fprintf(file,"%s %d %.2f\n",s[i].name,s[i].r,s[i].m);
}
 fclose(file);
}
 int readFromTextFile(stud s[],int n,const char *filename)
 {
 FILE *file =fopen(filename,"r");
 if(file==NULL)
 {
 printf("error opening file\n");
 return 0;
 }
 int count=0;
 while(count < n && fscanf(file,"%s %d %f",s[count].name,&s[count].r,&s[count].m) == 3)
 {
    count++;
 }
fclose(file);
return count;
}
void printStudents(stud s[],int n)
{
printf("name\troll number\tmarks\n");
for(int i=0;i<n;i++)
{
printf("%s\t%d\t%.2f\n",s[i].name,s[i].r,s[i].m);
}
}
int main()
{

int n;
printf("enter the number of students:\n");
scanf("%d",&n);
stud s[n];
inputStudents(s,n);
writeToTextFile(s,n,"students.txt");
stud s2[n];
int count=readFromTextFile(s2,n,"students.txt");
printf("students read from file:\n");
printStudents(s2,count);
return 0;
}