//Esercizio svolto in classe;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 4
int main(){
    char buffer[SIZE];

    FILE *origin,*dest;
    origin=fopen("miofile.txt","r");
    if(origin==NULL)
    {
        printf("Errore nell'apertura del file di origine");
        exit(-1);
    }
    dest=fopen("tuofile.txt","w+t");
    if(dest==NULL)
    {
        printf("Errore nell'apertura del file di destinazione");
        exit(-1);
    }
    int n;
    int i=0;
    while(n=fread(buffer,1,SIZE,origin)>0)
    {
        fwrite(buffer,1,SIZE,dest);
        i++;

    }
    /*int n=fread(buffer,1,SIZE,origin);
    fwrite(buffer,1,SIZE,dest);*/
    fclose(origin);
    fclose(dest);
    printf("%d\n",i);
    return 0;

}
