#pragma once
#include <iostream>

template<class T>
class Nodo
{
public:
    T* data;
    Nodo* next;
    Nodo(T* valor){//Valor apunta al usuario
        data = valor;//hago que data también apunte al usuario
        next = nullptr;
    }
    Nodo(){
        next = nullptr;
    }
    ~Nodo();
};
