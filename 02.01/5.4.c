//Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.

#include<stdio.h>

int strend(char *s,char *t);

int main()
{
  char s[100];
  char t[100];
  
  printf("enter the string s : ");
  fgets(s,sizeof(s),stdin);
  
  printf("enter the string t : ");
  fgets(t,sizeof(t),stdin);
  
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
  
  p=t;
  
  while(*p!='\0')
  {
    if(*p=='\n')
    {
      *p='\0';
      break;
    }
    p++;
  }
  
  if(strend(s,t))
  {
    printf("the string s has t at end\n");
  }
  else
  {
    printf("the string s does not have t at the end\n");
  }
  
  return 0;
}

int strend(char *s,char *t)
{
  char *send=s;
  char *tend=t;
  
  while(*send!='\0')
  { 
    send++;
  }
  while(*tend!='\0')
  {
    tend++;
  }
  
  while(tend>t)
  {
    send--;
    tend--;
    if(*send!=*tend)
    {
      return 0;
    }
  }
  return 1;
}