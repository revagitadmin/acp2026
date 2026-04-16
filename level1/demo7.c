/*compare two strings
void inputstrings(char s1[], char s2[])
int comparestrings(char s1[], char s2[])
void output(int result)*/
#include<stdio.h>
#include<string.h>
void inputstrings(char s1[] ,char s2[])
{
    printf("string1:\n");
    scanf("%s",s1);
    printf("string2:\n");
    scanf("%s",s2);

}
int comparestrings(char s1[],char s2[])
{
    int result=strcmp(s1,s2);
    if(result==0)
    {
        return 0;
    }
    else if(result>0){
        return 1;
    }
    else{
        return -1;
    }

    }
    
void output(int result)
{
    if(result==0)
    {
        printf("the two strings are equal\n");


    }
    else if(result==1)
    {
        printf("string1 is greater than string2\n");
    }
    else{
        printf("string 2 is greater than string 1\n");
    }
    
}
int main()
{
    char s1[50],s2[50];
    inputstrings(s1,s2);
    int result=comparestrings(s1,s2);
    output(result);
    return 0;

    
}