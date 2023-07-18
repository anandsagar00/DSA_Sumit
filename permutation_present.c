//Write a C prog to find if permutation of one string is present in another or not

#include<stdio.h>
#include<string.h>

//this function will return the count of permutation of one string into another
int countPermutation(char *str1,char *str2)
{
    int n1=strlen(str1);
    int n2=strlen(str2);

    int hash1[27];
    int hash2[27];

    for(int i=0;i<=26;i++)
    {
        hash1[i]=0;
        hash2[i]=0;
    }

    //in Hash2 I will store frequency of smaller string

    for(int i=0;i<n2;i++)
    hash2[str2[i]-'a']++;

    int count=0;

    for(int i=0;i<n1;i++)
    {
        if(i<n2-1)
        {
            hash1[str1[i]-'a']++;
        }
        else
        {
            hash1[str1[i]-'a']++;
            int flag=0;
            for(int j=0;j<=26;j++)
            {
                if(hash1[j]!=hash2[j])
                {
                    flag=1;
                    // break;
                }
            }
            if(!flag)
            count++;
            hash1[str1[i-n2+1]-'a']--;
        }
    }
    return count;

}

int main()
{
    char str1[100];
    char str2[100];

    scanf("%s",str1);
    scanf("%s",str2);

    printf("Count of permutations of \"%s\" in \"%s\" is : %d\n",str2,str1,countPermutation(str1,str2));

}