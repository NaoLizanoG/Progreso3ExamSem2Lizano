#include <stdio.h>
#include <stdio.h>
#include <string.h>

void leer (char Archivo[], char OtroArchivo[]){
    char caracter;
FILE*archivo;
FILE *archivoOtro;
archivo=fopen(Archivo, "r");
archivoOtro=fopen(OtroArchivo, "r+");

if(archivo==NULL || archivoOtro==NULL){

    printf("El archivo no se pudo abrir correctamente\n");
}
else{
while (!feof(archivo))
    {
        caracter = fgetc(archivo);

        if (caracter=='\n')
        {
            printf("\n");
            fprintf(archivoOtro, "\n");
        }
        else{
        
        putchar(caracter);
        fprintf(archivoOtro, "%c", caracter);
        }

    }
    fclose(archivo);
    fclose(archivoOtro);
}
}




int main(){
FILE *archivo;
char ArchivoNuevo[20]="tricolor2.txt";
char ArchivoViejo[20]="tricolor.txt";
archivo=fopen(ArchivoNuevo, "a+");
fclose(archivo);
leer(ArchivoViejo, ArchivoNuevo);

    return 0;
}