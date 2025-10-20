#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_PEL 2
#define MAX_DIR 5
#define MAX_LEN 20

typedef struct
{
    char Name[MAX_LEN];
    char Film_genres[MAX_LEN];
    int year;
    int number_of_directors;
    char directors[MAX_DIR][MAX_LEN];
} Pelicula;

void pelicula_SetNombre(Pelicula* w, char* nombre)
{
    strncpy(w->Name, nombre, MAX_LEN-1);
    w->Name[MAX_LEN-1] = '\0';
}

void pelicula_SetGenero(Pelicula* w, char* genero)
{
    strncpy(w->Film_genres, genero, MAX_LEN-1);
    w->Film_genres[MAX_LEN-1] = '\0';
}

void pelicula_SetAnio(Pelicula* w, int anio)
{
    w->year = anio;
}

void pelicula_SetnumDirectores(Pelicula* w, int numDirectores)
{
    w->number_of_directors = numDirectores;
}

void PeliculaSetDirectores(Pelicula* w)
{
    for (int i = 0; i < w->number_of_directors && i < MAX_DIR; i++) {
        printf("Ingresa el nombre del director %d: ", i + 1);
        scanf("%19s", w->directors[i]);
        w->directors[i][MAX_LEN-1] = '\0';
    }
}

const char* PeliculaGetNombre(Pelicula* w)
{
    return w->Name;
}

const char* PeliculaGetGenero(Pelicula *w)
{
    return w->Film_genres;
}

int PeliculaGetAnio(Pelicula* w)
{
    return w->year;
}

int PeliculaGetNumDirectores(Pelicula* w)
{
    return w->number_of_directors;
}

void PeliculaPrintDirectores(Pelicula* w)
{
    for (int i = 0; i < w->number_of_directors; i++) {
        printf(" - %s\n", w->directors[i]);
    }
}

bool ValidarNumeroPeliculas(int n)
{
    if (n <= 0) {
        printf("Error: la videoteca debe tener al menos 1 pelicula.\n");
        return false;
    }
    return true;
}

bool ValidarNumeroDirectores(int num)
{
    if (num <= 0 || num > MAX_DIR) {
        printf("Error: el numero de directores debe ser entre 1 y %d.\n", MAX_DIR);
        return false;
    }
    return true;
}

int BuscarPorNombre(Pelicula videoteca[], int n, const char* nombre)
{
    for (int i = 0; i < n; i++) {
        if (strcmp(videoteca[i].Name, nombre) == 0)
            return i;
    }
    return -1;
}

void BuscarPorAnio(Pelicula videoteca[], int n, int anio)
{
    printf("Peliculas del año %d:\n", anio);
    for (int i = 0; i < n; i++) {
        if (videoteca[i].year == anio)
            printf(" - %s\n", videoteca[i].Name);
    }
}

void BuscarPorDirector(Pelicula videoteca[], int n, const char* director)
{
    printf("Peliculas dirigidas por %s:\n", director);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < videoteca[i].number_of_directors; j++) {
            if (strcmp(videoteca[i].directors[j], director) == 0) {
                printf(" - %s\n", videoteca[i].Name);
                break;
            }
        }
    }
}

int ContarPorGenero(Pelicula videoteca[], int n, const char* genero)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(videoteca[i].Film_genres, genero) == 0)
            count++;
    }
    return count;
}

int main()
{
    Pelicula videoteca[NUM_PEL];
    int NUM_PELID = NUM_PEL;

    printf("Ingresa los datos de las peliculas que desea agregar\n");

    for(int i = 0; i < NUM_PELID; i++)
    {
        char NOMBRE[MAX_LEN];
        char GENERO[MAX_LEN];
        int ANIO, NUM_DIREC;

        printf("\nPelicula %d\n", i+1);

        // NUEVOS DATOS DE EJEMPLO
        if (i == 0) {
            strcpy(NOMBRE, "Inception");
            strcpy(GENERO, "CienciaFiccion");
            ANIO = 2010;
            NUM_DIREC = 1;
            pelicula_SetNombre(&videoteca[i], NOMBRE);
            pelicula_SetGenero(&videoteca[i], GENERO);
            pelicula_SetAnio(&videoteca[i], ANIO);
            pelicula_SetnumDirectores(&videoteca[i], NUM_DIREC);
            strcpy(videoteca[i].directors[0], "Nolan");
        } else if (i == 1) {
            strcpy(NOMBRE, "Titanic");
            strcpy(GENERO, "Romance");
            ANIO = 1997;
            NUM_DIREC = 1;
            pelicula_SetNombre(&videoteca[i], NOMBRE);
            pelicula_SetGenero(&videoteca[i], GENERO);
            pelicula_SetAnio(&videoteca[i], ANIO);
            pelicula_SetnumDirectores(&videoteca[i], NUM_DIREC);
            strcpy(videoteca[i].directors[0], "Cameron");
        }
    }

    printf("\n=== Peliculas ingresadas (de la ultima a la primera) ===\n");
    for(int i = NUM_PELID - 1; i >= 0; i--)
    {
        printf("\nNombre: %s\n", PeliculaGetNombre(&videoteca[i]));
        printf("Genero: %s\n", PeliculaGetGenero(&videoteca[i]));
        printf("Anio: %d\n", PeliculaGetAnio(&videoteca[i]));
        printf("Numero de Directores: %d\n", PeliculaGetNumDirectores(&videoteca[i]));
        printf("Directores:\n");
        PeliculaPrintDirectores(&videoteca[i]);
    }

    // BUSQUEDAS CON NUEVOS DATOS
    char nombreBuscar[MAX_LEN] = "Inception";
    int pos = BuscarPorNombre(videoteca, NUM_PELID, nombreBuscar);
    if (pos != -1)
        printf("\nSe encontro la pelicula '%s' en la posicion %d\n", nombreBuscar, pos);
    else
        printf("\nNo se encontro la pelicula '%s'\n", nombreBuscar);

    BuscarPorAnio(videoteca, NUM_PELID, 1997);
    BuscarPorDirector(videoteca, NUM_PELID, "Nolan");

    char generoContar[MAX_LEN] = "Romance";
    int totalGenero = ContarPorGenero(videoteca, NUM_PELID, generoContar);
    printf("\nTotal de peliculas del genero '%s': %d\n", generoContar, totalGenero);

    return 0;
}
