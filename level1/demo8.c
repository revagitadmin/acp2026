/*wacp to concatenate two strings using user-defined function
#include<stdio.h>
#include<string.h>
void input(char *str)
{
    printf("enter a string:");
    scanf("%s",str);

}
void concatenate_strings(char *str1,char *str2)
{
    
    // strcpy(str,str1);
    strcat(str1,str2);
    
}
void display(char *str)
{
    printf("concatenated string is %s",str);
}
int main()
{
    char str1[100],str2[100];
    input(str1);
    input(str2);
    concatenate_strings(str1,str2);
    display(str1);
    return 0;
}*/
#include<stdio.h>
void input(char *str){
    scanf("%s",str);
}
void concateneate_strings(char *str1,char *str2){
    int i=0;
    while(str1[i]!='\0'){
        i++;
    }
    int j = 0;
    while(str2[j]!='\0'){
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i]='\0';

} 
void display(char *str){
    printf("the concatenated string is %s",str);
}
int main(){
    char str1[100],str2[100];
    printf("enter the first string:\n");
    input(str1);
    printf("enter the second string:\n");
    input(str2);
   concateneate_strings(str1,str2);
    display(str1);
    return 0;
}