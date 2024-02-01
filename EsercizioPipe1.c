//Realizzare un programma in C in modo tale che riesce a far comunicare padre e figlio
//tramite una pipe ovvero consiste che il padre scrive un messaggio nella pipe e il figlio lo legge dalla pipe.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_BIG 1024
int main (int argc, char *argv[])
{
    int fd[2];
    int p;
    char buffer[BUFFER_BIG];
    int n;
    if(pipe(fd)==-1)//Funzione che mi fa creare la pipe
    {
        printf("Errore nella creazione del pipe\n");
        exit(-1);
    }
    p=fork();
    if(p<0)
    {
        printf("\nErrore generazione figlio");
    }
    if(p>0)//P maggiore di 0 abbiamo il dad
    {
        printf("Sono il DAD: e il mio PID e'%d\n, il mio FIGLIO ha PID%d\n",getpid(),p);
        close(fd[0]);//Il padre scrive nella pipe quindi chiusura in modalità lettura (input output)
        const char *messaggio ="Good Luck";
        if(write(fd[1],messaggio,strlen(messaggio))==-1)//Funzione di scrittura 
        {
            printf("\nError write pipe");
            exit(-1);
        }
        close(fd[1]);
        wait();

    }
    else//Altrimenti genera un child
    {
        printf("Sono il figlio: e il mio PID e'%d\n, il mio figlio ha PID%d\n",getpid(),getppid());
        close(fd[1]);//Il figlio legge dalla pipe quindi chiusura in modalità scrittura (input output)
        n=read(fd[0],buffer,BUFFER_BIG);
        if(n==-1)
        {
            printf("\nErrore nella lettura dalla PIPE");
            exit(-1);
        }
        else
        {
            buffer[n]='0';
            printf("\n Message riceved: %s\n",buffer);
            close(fd[0]);

        }


    }
    return 0;

}