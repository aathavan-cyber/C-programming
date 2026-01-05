//pointer version of integer to string

#include<stdio.h>

void my_itoa(int n,char *s);
void reverse(char *s);

int main()
{
  int n;
  char s[100];
  printf("enter the number : ");
  scanf("%d",&n);
  
  my_itoa(n,s);
  reverse(s);
  printf("the number after converted to string : %s\n",s);
  
  return 0;
}

void my_itoa(int n,char *s)
{
  int sign=n;
  
  if(n<0)
  {
    n=-n;
  }
  
  do
  {
    *s=(n%10) + '0';
    s++;
    n=n/10;
  }while(n>0);
  
  if(sign<0)
  {
    *s='-';
  }
}

void reverse(char *s)
{
  char *end=s;
  
  while(*end!='\0')
  {
    end++;
  }
  end--;
  
  while(s<end)
  {
    char temp=*s;
    *s=*end;
    *end=temp;
    
    s++;
    end--;
  }
}
