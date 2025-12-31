//Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
#include<stdio.h>
void my_strcat(char *s,char *t);
int main()
{
  char s[100];
  char t[100];
  printf("enter the string s : ");
  fgets(s,sizeof(s),stdin);
  printf("enter the string t : ");
  fgets(t,sizeof(t),stdin);
  char *p;
  p=s;
  while(*p != '\0')
  {
    if(*p == '\n')
    {
      *p='\0';
      break;
    }
    p++;
  }
  p=t;
  while(*p != '\0')
  {
    if(*p == '\n')
    {
      *p='\0';
      break;
    }
    p++;
  }
  my_strcat(s,t);
  printf("after concatenation : %s\n",s);
  return 0;
}
void my_strcat(char *s,char *t)
{
  while(*s!='\0')
  {
    s++;
  }
  while((*s = *t)!='\0')
  {
    s++;
    t++;
  }
}
