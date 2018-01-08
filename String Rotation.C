#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

int areRotations(char *str1, char *str2)
{
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *temp;
  void *ptr;

  if (len1 != len2)
     return 0;

  temp   = (char *)malloc(sizeof(char)*(len1*2 + 1));
  temp[0] = '\0';
  strcat(temp, str1);
  strcat(temp, str1);

 ptr = strstr(temp, str2);

  free(temp);

  if (ptr != NULL)
    return 1;
  else
    return 0;
}

int main()
{
    char *str1 = "waterbottle";
    char *str2 = "erbottlewat";
    if (areRotations(str1, str2))
       printf("Strings are rotations of each other");
    else
       printf("Strings are not rotations of each other");

    return 0;
}
