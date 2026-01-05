//pointer version of reverse

#include<stdio.h>

void reverse(char *s);

int main()
{ 
  char s[100];
  printf("enter the string : ");
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
  
  reverse(s);
  
  printf("the string after reversed : %s\n",s);
  return 0;
}

void reverse(char *s)
{
  char *end=s;
  
  while(*end!='\0')
  {
    end++;
  }
  end--;
  
  while(s < end)
  {
    char temp=*s;
    *s=*end;
    *end=temp;
    
    s++;
    end--;
  }
}
