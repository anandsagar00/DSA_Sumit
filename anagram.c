#include<stdio.h>
#include<string.h>

int anagram(char *str1,char *str2)
{
    int hash1[27]={0};
    int hash2[27]={0};

    int n1=strlen(str1);
    int n2=strlen(str2);

    if(n1!=n2)
    return 0;

    for(int i=0;i<n1;i++)
    {
        hash1[str1[i]-'a']++;
        hash2[str2[i]-'a']++;
    }
    for(int i=0;i<=26;i++)
    {
        if(hash1[i]!=hash2[i])
        return 0;
    }
    return 1;
}

int main()
{
    char str1[100];
    char str2[100];

    scanf("%s",str1);
    scanf("%s",str2);

    if(anagram(str1,str2))
    printf("YES\n");
    else
    printf("NO\n");
}