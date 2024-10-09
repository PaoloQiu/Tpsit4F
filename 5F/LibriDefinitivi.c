#include <stdio.h>
#include <string.h>
//Definisco la struttura Libro che contiene i campi principali del libro
typedef struct {
    char titolo[100];    // Titolo del libro
    char autore[100];    // Autore del libro
    int anno;            // Anno di pubblicazione del libro
    float prezzo;        // Prezzo del libro
} Libro;
//Definisco un'altyra struttura Categoria per contenere le categorie degli libri 
typedef struct {
    char nome[50];       // Nome della categoria
    Libro libri[100];    // Lista di libri appartenenti alla categoria
    int conteggio_libri; // Numero di libri attualmente nella categoria
} Categoria;
// Funzione per aggiungere un nuovo libro alla lista di una categoria
void aggiungiLibro(Categoria *categoria, Libro libro) {
    // Controllo con un if  se c'è spazio per aggiungere un altro libro
    if (categoria->conteggio_libri < 100) {
        categoria->libri[categoria->conteggio_libri] = libro;
        categoria->conteggio_libri++; // Incremento il conteggio deglòi libri 
    } else {
        printf("Non è possibile aggiungere altri libri alla categoria %s. Limite raggiunto.\n", categoria->nome);
    }
}
// Funzione per stampare tutti i libri in una determinata categoria
void stampaLibriCategoria(Categoria categoria) {
    printf("Categoria: %s\n", categoria.nome);
    printf("Numero di libri: %d\n", categoria.conteggio_libri);
    for (int i = 0; i < categoria.conteggio_libri; i++) {
        Libro libro = categoria.libri[i]; // Seleziono il libro corrente dell'eventuale lista 
        printf("Libro %d:\n", i + 1);
        printf("  Titolo: %s\n", libro.titolo);
        printf("  Autore: %s\n", libro.autore);
        printf("  Anno di pubblicazione: %d\n", libro.anno);
        printf("  Prezzo: %.2f euro\n", libro.prezzo);
    }
    printf("\n");
}
//Creazione di una funzione che ordina i libriu in base al titolo usando la yecnica della cosidetta bubble sort 
void ordinaLibriPerTitolo(Categoria *categoria) {
    int n = categoria->conteggio_libri;
    //Ciclo for per scorrere intera lista degli libri per poi con un'altro for scorrendo di nuovo confrontando uno a uno
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //Confronta i titoli dei due libri
            if (strcmp(categoria->libri[j].titolo, categoria->libri[j + 1].titolo) > 0) {
                //Se il titolo del primo libro è maggiore del secondo scambio i due libri
                Libro temp = categoria->libri[j];
                categoria->libri[j] = categoria->libri[j + 1];
                categoria->libri[j + 1] = temp;
            }
        }
    }
}
//Stesso ragionamento qua per ordinamento in base all'annop di pubblicazione utilizzando sempre la tecnica del bubble sort 
void ordinaLibriPerAnno(Categoria *categoria) {
    int n = categoria->conteggio_libri;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //Confronto gli anni di pubblicazione dei due libri
            if (categoria->libri[j].anno > categoria->libri[j + 1].anno) {
                //Se l'anno del primo libro è maggiore del secondo, scambia i due libri
                Libro temp = categoria->libri[j];
                categoria->libri[j] = categoria->libri[j + 1];
                categoria->libri[j + 1] = temp;
            }
        }
    }
}
//Funzione per leggere i dati dei libri da un file CSV e popolare la categoria
void leggiLibriDaFile(const char *nomeFile, Categoria *categoria) {
    //Apre il file in modalità lettura
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        //Se il file non viene aperto correttamente, stampa un messaggio di errore
        printf("Errore: Impossibile aprire il file %s\n", nomeFile);
        return;
    }
    //Legge ogni riga del file CSV e la inserisce in un libro
    while (!feof(file)) {
        Libro libro;  //Creo un oggetto libro per ogni riga
        //Legge i campi di un libro dal file CSV
        fscanf(file, "%[^,],%[^,],%d,%f\n", libro.titolo, libro.autore, &libro.anno, &libro.prezzo);
        //Aggiungo tramite la funzipone fatta  il libro alla categoria
        aggiungiLibro(categoria, libro);
    }
    // Chiude il file una volta terminata la lettura
    fclose(file);
}
// Funzione per stampare un menu per l'utente e gestire le operazioni principali
void stampaMenu() {
    printf("----- GESTIONE LIBRERIA -----\n");
    printf("1. Leggi libri da file CSV\n");
    printf("2. Stampa tutti i libri\n");
    printf("3. Ordina libri per titolo\n");
    printf("4. Ordina libri per anno\n");
    printf("5. Esci\n");
    printf("Seleziona un'opzione: ");
}
//Main 
int main() {
    // Inizializzo una categoria generica per inserire i libri
    Categoria categoriaGenerale = {"Generale", {}, 0};
    int scelta;
    do {
        stampaMenu();  // Mostro il menu all'utente
        scanf("%d", &scelta);  // Legge la scelta dell'utente
        switch (scelta) {
            case 1: {
                // Leggi i libri dal file CSV
                char nomeFile[100];
                printf("Inserisci il nome del file CSV: ");
                scanf("%s", nomeFile);
                leggiLibriDaFile(nomeFile, &categoriaGenerale);
                printf("Libri caricati con successo congratulazioni!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
                break;
            }
            case 2:
                //Stampo i libri nella categoria con questa funzione 
                stampaLibriCategoria(categoriaGenerale);
                break;
            case 3:
                // Ordino i libri per titolo con la funzione fatta 
                ordinaLibriPerTitolo(&categoriaGenerale);
                printf("Libri ordinati per titolo.\n\n");
                break;
            case 4:
                //Ordino i libri per anno di pubblicazione sempre con la funzione fatta 
                ordinaLibriPerAnno(&categoriaGenerale);
                printf("Libri ordinati per anno.\n\n");
                break;
            case 5:
                //Esco dal programma
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida, what are you doing???????????????????????????????????????\n");
                break;
        }
    } while (scelta != 5);
    return 0;
}
