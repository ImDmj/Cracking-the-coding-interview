
#include<stdio.h>
#include<conio.h>

int main()
{
int mata[3][3],i,j,row[3],col[3],k=0;
for(i=0;i<3;i++)
   for(j=0;j<3;j++)
       scanf("%d",&mata[i][j]);

for(i=0;i<3;i++)
   for(j=0;j<3;j++)
    { 
    if(mata[i][j]==0)
      {  
        row[k]=i;
        col[k]=j;
        k++;
      }
   }   

for(int z=0;z<k;z++)
   {
   for(i=0;i<3;i++)
      {
        mata[row[z]][i]=0;
      }
   for(i=0;i<3;i++) 
      {  
        mata[i][col[z]]=0;
      }
     for(i=0;i<3;i++) 
      {  
        mata[(row[z]-1)][(col[z]-1)]=0;
        mata[(row[z]+1)][(col[z]+1)]=0;
        mata[(row[z]-1)][(col[z]+1)]=0;
        mata[(row[z]+1)][(col[z]-1)]=0;
      }
      
   }

for(i=0;i<3;i++)
   for(j=0;j<3;j++)

printf("%d",mata[i][j]);
getch();
return 0;
}
