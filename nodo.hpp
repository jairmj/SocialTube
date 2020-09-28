#pragma once
#include <iostream>

template<class T>
class Nodo
{
public:
    T data;
    Nodo* next;
    Nodo(T valor){
        data = valor;
        next = nullptr;
    }
    Nodo(){
        next = nullptr;
    }
    ~Nodo();
};
