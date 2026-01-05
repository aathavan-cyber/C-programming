//Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).

#include<stdio.h>
#define MAX 100

int my_getline(char *s,int max);

int main()
{
  char s[100];
  
  if(my_getline(s,MAX)>0)
  {
    printf("after getting input from my_getline function : %s\n",s);
  }
  else
  {
    printf("invalid");
  }
  
  return 0;
}

int my_getline(char *s,int max)
{
  char *start=s;
  int c;
  while(max>0 && (c=getchar())!=EOF && c!='\n')
  {
    *s=c;
    s++;
    max--;
  }
  if(c=='\n')
  {
    *s='\n';
    s++;
  }
  *s='\0';
  
  return s-start;
}
