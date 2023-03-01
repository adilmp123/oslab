#include <stdio.h>
#include <string.h>
#include <dirent.h>
void main(int argc,char *args[])
{
    char temp[200];
    FILE * fp;
    fp = fopen(args[2],"r");
    while(!feof(fp))
    {
        fgets(temp,sizeof(fp),fp);
        if(strstr(temp,args[1]))
        {
            printf("%s",temp);
        }
    }
    printf("\n");
    fclose(fp);

}
