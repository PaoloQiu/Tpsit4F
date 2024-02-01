#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define DIM 5//Definisco un variabile di dimensione 5 così dopo nella creazione delll'array posso infilare
//direttamento questo valore

int main(int argc, char *argv[])
{
    int p;
    int n,number;
    int status;
    int fd[2];
    int array[DIM];
    p=fork();
    if (pipe(fd) == -1)
    {
        printf("Errore nella creazione del pipe\n");
        exit(-1);
    }
    if (p < 0)
    {
        printf("Errore nella generazione figlio\n");
    }
    if (p > 0) 
    {
        printf("\nSono il Dad: il mio PID è %d, mio son ha PID %d\n\n", getpid(), p);
        wait(&status);

        close(fd[1]); //Se fd è di argomento 1 chiudo la scrittura
        n = read(fd[0], array, DIM * sizeof(int));
        if (n == -1)
        {
            printf("Errore nella lettura del pipe\n");
            close(fd[0]);
            exit(-1);
        }
        printf("Inserisci un numero\n");
        scanf("%d", &number);
        for (int i = 0; i < DIM; i++)
        {
            array[i] = array[i] * number;
            printf("\n%d\n", array[i]);
        }
        close(fd[0]); //Argomento di fd è 0 esco di letteru e chiudo il pipe
    }
    else
    {
        printf("Sono il son: il mio PID  è %d, mio dad ha PID %d\n\n", getpid(), getppid());
        for (int i = 0; i < DIM; i++)
        {
            printf("Inserisci il numero %d\n", i + 1);
            scanf("%d", &array[i]);
        }
        if (write(fd[1], array, DIM * sizeof(int)) == -1) 
        {
            printf("Errore di scrittura nella pipe\n");
            close(fd[1]);
            exit(-1);
        }

        close(fd[1]);
    }
    return 0;
}
