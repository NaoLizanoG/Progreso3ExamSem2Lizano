#include <stdio.h>
#include <stdio.h>
#include <string.h>

//funcion para leer el texto y escribirlo en un nuevo archivo
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

//funcion para encontrar los errores
int encontrar(char nombreArchivo[])
{
    int num = 0;
    long posicion;
    char caracter[10], palabra[] = "ecuador";
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
    return num;
}


//funcion general
int main()
{
    FILE *archivo;
    int num;
    char ArchivoNuevo[20] = "tricolor2.txt";
    char ArchivoViejo[20] = "tricolor.txt";
    archivo = fopen(ArchivoNuevo, "a+");
    fclose(archivo);
    leer(ArchivoViejo, ArchivoNuevo);
    num=encontrar(ArchivoNuevo);
    printf("Se encontraron %d errores\n",num );

    return 0;
}