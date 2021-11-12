#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthofstring(char *s)
{
    int i;
    for(i = 0; s[i] != '\0'; i++) {};
    printf("lenght of string is %d ", i);
    return 0;
}
int casechange(char *s)
{
    int i;
    for(i=0; s[i] !='\0' ;i++)
    {
        s[i] -= 32;
    }
    printf("the changed string is %s  ",s);
    return 0;
}
void toggling(char *s )
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i]>=65 && s[i] <= 90)
        {
            s[i] += 32;//changing to lower case
        }
        else if(s[i]>= 97 && s[i]<=122)
        {
            s[i] -= 32;//changing to uppercase
        }
        i++;
    }
    printf("the toggled string is %s ",s);
}
int checkvow(char *s)
{   
    int i, count = 0,counttwo= 0;
    for(i=0; s[i] != '\0';i++)
    {
        if(s[i] == 'a'|| s[i] =='e'|| s[i]=='i' || s[i]=='o' || s[i] =='u')
        {
            count++;
        }
        else if((s[i] >= 65 && s[i]<= 90) || (s[i] >= 97 && s[i]<= 122) )
        {
            counttwo++;
        }
    }
     printf("vowels are %d and consonents are %d ", count,counttwo);
     return 0;
}

int noofwords(char *s)
{   int i, spaces=0; //reasoning is that two words will have 3 spaces and n words will have n+1 spaces.
    for(i=0;s[i]!='\0';i++)
    {
        if( (s[i]==' ') && (s[i-1] != ' '))
        {
            spaces++;
        }
    }
    printf("no of words is %d",spaces++);
    return 0;
}
int reverse(char *s)//inthis method we used two character arrays
{
    int i,j;
    char B[j];
    for(i=0;s[i] != '\0';i++){};
      i -= 1;
    for(j=0; i >= 0  ;i--,j++)
    {
        B[j] = s[i];
    } 

    B[j] = '\0';

    printf("%s",B);
    return 0;
    
}
int reverse2ndmethod(char *s)//inthis method i am not using second array to store the reversed string
{
    int i,j;   // i am just incrementing and decrementing the two positions i and j
    char t;
    for(i=0;i!='\0';i++){};
        j -= 1;
    for(i=0;i<j;i++,j--)
    {
        t= s[i];
        s[i] = s[j]; ///    its like swapping (s[i],s[n-i-1]) for every iteration we could had done that also.
        s[j] = t;
    }
    printf("%s",s);
    return 0;
}
int comparestring(char *s)
int main()
{   
    char s[] = "zenith";
    //lengthofstring(s);
   // casechange(s);
   // toggling(s);
    //checkvow(s) ;
   // noofwords(s);
    reverse(s) ;
    //reverse2ndmethod(s);

}