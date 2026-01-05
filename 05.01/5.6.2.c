//pointer version of atoi

#include<stdio.h>

int my_atoi(char *s);

int main()
{
  char s[100];
  printf("enter the number(string) : ");
  fgets(s,sizeof(s),stdin);
  
  char *p=s;
  while(*p!='\0')
  {
    if(*p=='\n')
    {
      *p='\0';
      break;
    }
    p++;
  }
  
  int result = my_atoi(s);
  printf("after coverted to int : %d\n",result);
  return 0;
}

int my_atoi(char *s)
{ 
  while(*s==' ' || *s=='\t')
  {
    s++;
  }
  int sign;
  if(*s=='+' || *s=='-')
  {
    sign=(*s=='-') ? -1 : 1;
    s++;
  }
  int n=0;
  while(*s!='\0')
  {
    n=(n*10) + (*s - '0');
    s++;
  }
  return n * sign;
}

