#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(char* word)
{
    int n=strlen(word);

    int i=0,j=n-1;

    while(i<j)
    {
        swap(&word[i],&word[j]);
        i++;
        j--;
    }
    
}

char* reverseEachWord(char* str)
{
    char* nstr=(char *)malloc(sizeof(char)*1000);
    
    char* token=strtok(str," ");

    int flag=0;

    while(token!=NULL)
    {
        reverse(token);
        if(flag==0)
        {
            strcpy(nstr,token);
            flag=1;
        }
        else
        {
            strcat(nstr," ");
            strcat(nstr,token);
        }

        token=strtok(NULL," ");
    }
    // printf("NSTR : %s\n",nstr);
    return nstr;
}

int main()
{
    char str[1000];
    gets(str);
    char* nstr=reverseEachWord(str);
    printf("%s ",nstr);
}