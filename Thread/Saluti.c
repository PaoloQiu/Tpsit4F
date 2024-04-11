//In qeusto caso per compilare si fa gcc Saluti.c -o Saluti -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//Thread POSIX
void *stampaNome(void *paramentro)//Funzione
{
     printf("Sono Qiu Xiaqiang\n");//Primo thread thread che creo 
}
void *stampaEntita(void *paramentro)//Funzione
{
     printf("I'm chinese and my english level is very high\n");//Secondo thread che creo 

}
void *stampaPatrimonio(void *paramentro)//Funzione
{
     printf("Ho tante montagne\n");//Terzo thread che creo 

}

int main(int argc , char * argv[])
{
    pthread_t threadNome,threadEntita,threadPatrimonio;
    printf("Hello world\n");
    pthread_create(&threadNome,NULL,&stampaNome,NULL);
    pthread_create(&threadEntita,NULL,&stampaEntita,NULL);
    pthread_create(&threadPatrimonio,NULL,&stampaPatrimonio,NULL);
    pthread_join(threadNome,NULL);//Join è la funzione wait del thread
    pthread_join(threadEntita,NULL);
    pthread_join(threadPatrimonio,NULL);
    //Con il thread voglio che tutto fraccia in parallelo come fosse che 4 computer ognuno stampa una stringa
    //printf("Sono Qiu Xiaqiang\n");
    //printf("I'm chinese and my english level is very high\n");
    //printf("Ho tante montagne\n");
    return 0;
}