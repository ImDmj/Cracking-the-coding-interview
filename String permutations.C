#include<stdio.h>
#include<conio.h>

# define No_Of_Chars 256

int ispermutation(char *str1, char *str2);

int main()
{
 char str1[20]= "baby";
 char str2[20]="cab";
  
 if(ispermutation(str1, str2))
    printf("The two strings are permutations of each other");
 else
    printf("The two strings are not permutations of each other");

 return 0;
}

int ispermutation(char *str1, char *str2)
{
  int count[No_Of_Chars]={ 0 };
  int i=0;

  for(i=0; str1[i] && str2[i]; i++)
     {
       count[str1[i]]++;
       count[str2[i]]--;
     }

  if(  str1[i] || str2[i] )
     return 0;

   for(i=0; i<No_Of_Chars; i++)
      if ( count[i])
	 return 0;
      return 1;
}
