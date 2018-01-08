#include<stdio.h>
#include<conio.h>
void main()
{
 int len=0, front, end, index, count;
 char str[]="this is the question number 6";
 clrscr();
 printf("Replace space with %20");
 printf("\n",str);

		if(!str)
			return 0;

		len = sizeof(str);
		front = len - 1;
		end = front;

		while(str[front] ==' ')          // find the index of the end of the actual string(get rid of tailing spaces)
			front--;

		index = front;
		count = 0;
		while(index >= 0)
			if(str[index--] == ' ')
				count++;                      // count spaces to be converted;

		end = front + count * 2;          // the len(result string) = len(former string) + #spaces * 2
		str[end + 1] = '\0';              // tailor the result string

		while(front >= 0 && end >= 0)     // trace backwards
		{
			if(str[front] == ' ')
			{
				str[end--] = '0';
				str[end--] = '2';
				str[end--] = '%';
			}                               // convert spaces
			else
				str[end--] = str[front];
							      // move non-space characters
	    front--;
		}
printf("\n%s",str);
getch();
}

