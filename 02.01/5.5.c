//Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.

#include<stdio.h>

void my_strncpy(char *s,char *t,int n);
void my_strncat(char *s,char *t,int n);
int my_strncmp(char *s,char *t,int n);

int main()
{
  char s[100];
  char t[100];
  char buf[100];
  int n;
  printf("string copy..\n");
  printf("enter the string t for strcopy :");
  fgets(t,sizeof(t),stdin);
  printf("enter the value of n : ");
  fgets(buf,sizeof(buf),stdin);
  sscanf(buf,"%d",&n);
  char *p=t;
  while(*p!='\0')
  {
    if(*p=='\n')
    {
      *p='\0';
      break;
    }
    p++;
  }
  my_strncpy(s,t,n);
  printf("the string s after string copy : %s\n",s);
  
  char str1[100];
  char str2[100];
  printf("string concatenation...\n");
  printf("enter the string str1 for concat : ");
  fgets(str1,sizeof(str1),stdin);
  printf("enter the string str2 for concat : ");
  fgets(str2,sizeof(str2),stdin);
  printf("enter the number n : ");
  fgets(buf,sizeof(buf),stdin);
  sscanf(buf,"%d",&n);
  
  p=str1;
  while(*p!='\0')
  {
    if(*p=='\n')
    {
      *p='\0';
      break;
    }
    p++;
  }
  
  p=str2;
  while(*p!='\0')
  {
    if(*p=='\n')
    {
      *p='\0';
      break;
    }
    p++;
  }
  my_strncat(str1,str2,n);
  printf("the string after concatenation with t : %s\n",str1);
  
  
  
  printf("string compare...\n");
  printf("enter the string s for compare : ");
  fgets(s,sizeof(s),stdin);
  printf("enter the string t for compare : ");
  fgets(t,sizeof(t),stdin);
  printf("enter the number n : ");
  fgets(buf,sizeof(buf),stdin);
  sscanf(buf,"%d",&n);
  
  p=s;
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
  int val=my_strncmp(s,t,n);
  if(val==0)
  {
    printf("both the string are equal\n");
  }
  else if(val<0)
  {
    printf("the string s is smaller\n");
  }
  else
  {
    printf("the string t is smaller \n");
  }
  
  return 0; 
}

void my_strncpy(char *s,char *t,int n)
{
  while(n>0 && *t!='\0')
  {
    *s=*t;
    s++;
    t++;
    n--;
  }
  *s='\0';
}

void my_strncat(char *s,char *t,int n)
{
  while(*s!='\0')
  {
    s++;
  }
  
  while(n>0 && *t!='\0')
  {
    *s=*t;
    s++;
    t++;
    n--;
  }
  *s='\0';
}

int my_strncmp(char *s,char *t,int n)
{
  while(n>0 && *s && *t && (*s==*t))
  {
    s++;
    t++;
    n--;
  }
  if(n==0)
  {
    return 0;
  }
  return *s - *t;
}