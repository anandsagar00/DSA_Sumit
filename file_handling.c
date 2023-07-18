#include<stdio.h>
#include<stdlib.h>


int main()
{
    FILE *fp=fopen("TODO.txt","r");
    FILE *fp1=fopen("NEW_TODO.txt","w");

    while(!feof(fp))
    {
        char str[1000];
        fgets(str,sizeof(str),fp);
        // printf("%s \n\n",str);
        fprintf(fp1,"%s",str);
    }
    fclose(fp1);
    fclose(fp);
}
