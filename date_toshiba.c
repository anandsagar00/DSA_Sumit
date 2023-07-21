#include<stdio.h>
#include<string.h>

int countUniqueYear(char *str)
{
    int arr[10000]={0};

    char *token=strtok(str," ");

    while(token!=NULL)
    {
        char nstr[100];
        strcpy(nstr,token);

        int year;

        if(strlen(nstr)==10 && nstr[2]=='-' && nstr[5]=='-')
        {
            //dd-mm-yyyy
            year=((nstr[6]-'0')*1000)+((nstr[7]-'0')*100)+((nstr[8]-'0')*10)+((nstr[9]-'0'));
            // printf("YEAR : %d\n",year);
            arr[year]++;
        }
        token=strtok(NULL," ");
    }

    int count=0;
    for(int i=0;i<10000;i++)
    {
        if(arr[i])
        count++;
    }
    return count;
}

int main()
{
    char str[1000];
    gets(str);

    printf("%d",countUniqueYear(str));

}