#include <stdio.h>
#include <stdio.h>
#include <string.h>

// funcion para leer el texto y escribirlo en un nuevo archivo
void leer(char Archivo[], char OtroArchivo[])
{
    char caracter;
    FILE *archivo;
    FILE *archivoOtro;
    archivo = fopen(Archivo, "r");
    archivoOtro = fopen(OtroArchivo, "r+");

    if (archivo == NULL || archivoOtro == NULL)
    {

        printf("El archivo no se pudo abrir correctamente\n");
    }
    else
    {
        while (!feof(archivo))
        {
            caracter = fgetc(archivo);

            if (caracter == '\n')
            {
                printf("\n");
                fprintf(archivoOtro, "\n");
            }
            else
            {

                putchar(caracter);
                fprintf(archivoOtro, "%c", caracter);
            }
        }
        fclose(archivo);
        fclose(archivoOtro);
    }
}

// funcion para encontrar los errores
long encontrar(char nombreArchivo[])
{
    long posicion;
    int num;
    char caracter[10], palabra[10] = "ecuador";
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {

        printf("El archivo no se pudo abrir correctamente\n");
    }
    else
    {
        while (!feof(archivo))
        {
            posicion = ftell(archivo);
            fscanf(archivo, "%s", caracter);
            if (strcmp(palabra, caracter) == 0)
            {
                num = num + 1;
            }
        }
        printf("Se encontraron %d errores\n", num);
    }
    fclose(archivo);
    return posicion;
}


int errores(char nombreArchivo[])
{
    long posicion;
    int num;
    char caracter[10], palabra[10] = "ecuador";
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {

        printf("El archivo no se pudo abrir correctamente\n");
    }
    else
    {
        while (!feof(archivo))
        {
            posicion = ftell(archivo);
            fscanf(archivo, "%s", caracter);
            if (strcmp(palabra, caracter) == 0)
            {
                num = num + 1;
            }
        }
    }
    fclose(archivo);
    return num;
}

//funcion para reemplazar 
void reemplazar(char Archivo[], long posicion)
{
    char caracter[20], nuevo[20]="Ecuador" ;
    FILE *archivo;
    archivo = fopen(Archivo, "r");
    if (archivo == NULL)
    {

        printf("El archivo no se pudo abrir correctamente\n");
    }
    else
    {
        fseek(archivo, posicion, 0);
        fscanf(archivo, " %s ", &caracter);
        fseek(archivo, posicion, 0);
        fprintf(archivo, " %s ", nuevo);

    }
     fclose(archivo);
}

// funcion general
int main()
{
    int num;
    FILE *archivo;
    long posicion;
    char ArchivoNuevo[20] = "tricolor2.txt";
    char ArchivoViejo[20] = "tricolor.txt";
    archivo = fopen(ArchivoNuevo, "a+");
    fclose(archivo);
    leer(ArchivoViejo, ArchivoNuevo);
    posicion = encontrar(ArchivoNuevo);

    reemplazar(ArchivoNuevo, posicion);
    num=errores(ArchivoNuevo);
    printf("Hay %d errores", num);
    return 0;
}