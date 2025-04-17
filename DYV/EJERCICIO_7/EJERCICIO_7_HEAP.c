#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Nodo{
    struct nodo *izq;
    struct nodo *der;
}Nodo;


bool es_heap(Nodo *nodo) {
    if(nodo==NULL) {
        return true;
    }

    while(nodo->izq!=NULL && nodo->der!=NULL) {
        if(es_heap(nodo->izq)) {

}




int main() {

}
