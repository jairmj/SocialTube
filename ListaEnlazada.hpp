#pragma once
#include <iostream>
#include "usuario.hpp"
#include "tweet.hpp"
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
    void InsertarNodoFin(T* no){//no apunta al nuevo tweet
        if(head == nullptr){
            Nodo<T>* nuevoNodo = new Nodo<T>(no);//Le paso la direccion de memoria del nuevo tweet
            head = nuevoNodo;
            last = nuevoNodo;
            cantidad++;
        }
        else{
            Nodo<T>* nuevoNodo = new Nodo<T>(no);
            last->next = nuevoNodo;
            last = nuevoNodo;
            cantidad++;
        }
    }

    T* getValue(int position) {
        if (position == 0) { return head->data; }
        else if (position >= cantidad || position < 0) { std::cerr << "Error: Index out of range"; }
        else {
            int index = 0;
            Nodo<T>* iterator = new Nodo<T>();
            iterator = head;//Apunta al dato que esté en la posición 1
            while(iterator != nullptr){
                if (position == index) {
                    return iterator->data;
                }
                iterator = iterator->next; index++;
            }
        }   
    }
};
