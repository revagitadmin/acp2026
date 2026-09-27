#include<stdio.h>
#include<string.h>
 typedef struct{
    char destination[100];
    int flightnumber;
    int seats_available;
 }flight;
int main()
{
    flight f[4];

    for(int i=0;i<4;i++)
    {
        printf("Enter the flightnumber:");
        scanf("%d",&f[i].flightnumber);

        printf("Enter the flightdestination:");
        scanf("%s",f[i].destination);

        printf("Enter the seats available:");
        scanf("%d",&f[i].seats_available);
    }
      
    char search[100];
    printf("Enter the  destination to search:");
    scanf("%s",search);

    for(int i=0;i<4;i++)
    {
        if(strcmp(f[i].destination,search)==0)
        {
            printf("Flight found:%d\n",f[i].flightnumber);
        }
    }
    return 0;
}