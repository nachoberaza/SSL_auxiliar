#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#define WIDTH 7
#endif

#ifdef linux
#include <stdlib.h>
#endif

#include <stdio.h>
#include <string.h>

int clearScreen();
int writeFile(char fileName[]);
int readFile(char fileName[]);

int main(){
    clearScreen();
    writeFile("cacho.txt");
    


    return 0;
}


int clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 0;
}

int readFile(char fileName[]){
    
    FILE* ptr;
    char ch;
     
    ptr = fopen(fileName, "r"); // "r" defino "read mode"
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    // Muestro el contenido del archivo caracter por caracter
    while (ch != EOF){
        ch = fgetc(ptr);
        printf("%c", ch);
    };
 
    // Cierro el 
    fclose(ptr);

    return 0;
}

int writeFile(char fileName[]){

    int i=0;
    FILE * fptr;
    char fn[50];
    char str[] = "Escribo desde C";

    fptr = fopen(fileName, "w"); // "w" defino "writing mode"

    while (i < strlen(str)){
        fputc(str[i], fptr);
        i++;
    };

    fclose(fptr);

    return 0;
}