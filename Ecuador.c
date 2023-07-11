#include <stdio.h>
#include <stdio.h>
#include <string.h>

void leer (char Archivo[]){
    char caracter;
FILE*archivo;
archivo=fopen(Archivo, "r");

if(archivo==NULL){

    printf("El archivo no se pudo abrir correctamente\n");
}
else{
while (!feof(archivo))
    {
        caracter = fgetc(archivo);

        if (caracter=='\n')
        {
            printf("\n");
        }
        else{
        
        putchar(caracter);
        }

    }
    fclose(archivo);
}
}


int main(){
FILE *archivo;
char ArchivoNuevo[20]="tricolor2.txt";
char ArchivoViejo[20]="tricolor.txt";
leer(ArchivoViejo);

    return 0;
}