 #pragma once
#include <string>
#include <iostream>
#include <vector>
#include "usuario.hpp"
using std::string;

class tweet{
    public:
    string contenido;
    int RTs, likes;
    tweet(string contenido){
        this->contenido = contenido;
        RTs = 0;
        likes = 0;
    }
    tweet(){
        contenido = "";
        RTs = 0;
        likes = 0;
    }
    void agregarRT(){
        RTs++;
    }
    void agregarLike(){
        this->likes = this->likes + 1;
    }

};