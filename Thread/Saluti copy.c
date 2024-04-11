//In qeusto caso per compilare si fa gcc Saluti.c -o Saluti -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//Thread POSIX
void *stampaNome(void* paramentro)//Funzione
{
     printf("%s\n",(char*)paramentro);//Primo thread thread che creo 
     return (void*)0;
}
void *stampaEntita(void* paramentro)//Funzione
{
     pprintf("%s\n",(char*)paramentro);
     return (void*)0;//Secondo thread che creo 

}
void *stampaPatrimonio(void* paramentro)//Funzione
{
     printf("%s\n",(char*)paramentro);//Primo thread thread che creo 
     return (void*)0;//Terzo thread che creo 

}

int main(int argc , char * argv[])
{
    pthread_t threadNome,threadEntita,threadPatrimonio;
    char* stringa = "Sono Qiu Xiaqiang\n";
    char* stringa2 = "I'm chinese and my english level is very high\n";
    char* stringa3 = "Ho tante montagne\n";
    printf("Hello world\n");
    pthread_create(&threadNome,NULL,&stampaNome,stringa);
    pthread_create(&threadEntita,NULL,&stampaEntita,stringa2);
    pthread_create(&threadPatrimonio,NULL,&stampaPatrimonio,stringa3);
    pthread_join(threadNome,NULL);//Join è la funzione wait del thread
    pthread_join(threadEntita,NULL);
    pthread_join(threadPatrimonio,NULL);
    //Con il thread voglio che tutto fraccia in parallelo come fosse che 4 computer ognuno stampa una stringa
    //printf("Sono Qiu Xiaqiang\n");
    //printf("I'm chinese and my english level is very high\n");
    //printf("Ho tante montagne\n");
    return 0;
}