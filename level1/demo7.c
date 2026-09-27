#include<stdio.h>

void inputstrings(char str1[],char str2[])
{
    printf("Enter string1:");
    scanf("%s",str1);

    printf("Enter string 2:");
    scanf("%s",str2);
}

int comparestrings(char str1[],char str2[])
{
    int i=0;

    while(str1[i]!='\0' && str2[i]!='\0')
{
    if(str1[i]>str2[i])
    return 1;
    else if(str1[i]<str2[i])
    return -1;
    i++; 
}
    if(str1[i]=='\0' && str2[i]=='\0')
      return 0;
    else if(str1[i]=='\0')
      return -1;
    else
      return 1;

}
 
void output(int result)
{
  if(result==0)
    printf("Strings are equal\n");
  else if(result==1)
    printf("String 1 is greater\n");
  else
    printf("String 2 is greater\n");
}
int main()
{
  char str1[100],str2[100];
  int result;

    inputstrings(str1,str2);
    result=comparestrings(str1,str2);
    output(result);
   return 0;
}