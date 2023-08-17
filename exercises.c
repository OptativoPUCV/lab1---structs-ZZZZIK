#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/

int findMax(int arr[], int size) { 
  int mayor=0;
  for (int i=0 ; i<size ; i++){
    if (i==0){
      mayor=arr[i];
    }
    else if(arr[i]>mayor){
      mayor=arr[i];
    }
  }
  return mayor; 
}
/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int j=0;
  int temp;
  for(int i=size-1 ; i>=(size/2) ;i--){
    temp=arr[j];
    arr[j]=arr[i];
    arr[i] =temp;
    j++;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) {
  
  int *pares = (int *)malloc(*newSize * sizeof(int));
  if(pares==NULL)return NULL; 
  int j = 0;
  for(int i=0; i<size; i++){
      if (arr[i]%2==0){
        pares[j]=arr[i];
        j++;
      }
  }
  *newSize = j;
  return pares; 
}




/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]) {
    int talla_f=(size1+size2),j=0;
  
    // Juntamos los 2 arreglos en result
    for (int i=0; i<talla_f;i++){
        if(i<size1) result[j]=arr1[i];
        else result[j]=arr2[i-size1];
        j++;
    }
    
    // Usamos el algoritmo burbuja para ordenar el vector result
    for(int i=0 ;i<talla_f ;i++){
        for(int j=0 ;j<talla_f-1 ;j++){
            if(result[j]>result[j+1]){
                int temp = result[j];
                result[j]=result[j+1];
                result[j+1]= temp;
            }
        }
    }
}  




  
  
/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden .
*/
int checkSorted(int arr[], int size) {
  int copia_ascendente[size];
  int copia_descendente[size];
  
  // Flags
  int ascen = 1;
  int decen = 1;
  // Hacemos 2 copias
  for (int i=0; i<size; i++){
    copia_ascendente[i]=arr[i];
    copia_descendente[i]=arr[i];
  }
  // Ordenamos la copia ascendente
  for(int i=0 ;i<size ;i++){
        for(int j=0 ;j<size-1 ;j++){
            if(copia_ascendente[j]>copia_ascendente[j+1]){
                int temp1 = copia_ascendente[j];
                copia_ascendente[j]=copia_ascendente[j+1];
                copia_ascendente[j+1]= temp1;
            }
            if(copia_descendente[j]<copia_descendente[j+1]){
                int temp2 = copia_descendente[j];
                copia_descendente[j]=copia_descendente[j+1];
                copia_descendente[j+1]= temp2;
            }
        }
  }

  // Comparamos para saber que es finalmente
  for (int i=0; i<size;i++){
    if (copia_ascendente[i]!=arr[i]) ascen = 0;
    else if (copia_descendente[i]!=arr[i]) decen = 0;
  }
  if ((ascen==0) && (decen==0)) return 0;
  if (ascen==1) return 1;
  if (decen==1) return -1;
}


/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion){
    strcpy(libro->titulo,titulo);
    strcpy(libro->autor.nombre,nombreAutor);
    libro->autor.anioNacimiento= anioNacimiento;
    libro->autor.anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { return NULL; }
