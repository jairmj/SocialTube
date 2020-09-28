#include <iostream>
#include "nodo.hpp"
using namespace std;
template<class T>
class ListaEnlazada
{
public:

    Nodo<T>* head;
    Nodo<T>* last;
    int cantidad;

    ListaEnlazada(){
        head = nullptr;
        last = nullptr;
        cantidad = 0;
    }
    void InsertarNodoFin(T* no){
        if(head == nullptr){
            Nodo<T>* nuevoNodo = new Nodo<T>(*no);
            head = nuevoNodo;
            last = nuevoNodo;
            cantidad++;
        }
        else{
            Nodo<T>* nuevoNodo = new Nodo<T>(*no);
            last->next = nuevoNodo;
            last = nuevoNodo;
            cantidad++;
        }
    }

    T getValue(int position) {
        if (position == 0) { return head->data; }
        else if (position >= cantidad || position < 0) { std::cerr << "Error: Index out of range"; }
        else {
            int index = 0;
            Nodo* iterator = new Nodo();
            iterator = head;//Apunta al dato que esté en la posición 1
            while(iterator != nullptr){
            if (position == index && operation == 4) {
                return iterator->valor;
            }
            iterator = iterator->s; index++;
        }
    }

};
