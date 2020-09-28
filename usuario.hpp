 #pragma once
#include <string>
#include <iostream>
#include "tweet.hpp"
using std::string;
using std::vector;

class usuario{
    public:
    string apodo, contrasena, correo;
    vector<tweet> tweets;


    usuario(string apodo, string contrasena, string correo){
        this->apodo = apodo;
        this->contrasena = contrasena;
        this->correo = correo;
    }
    usuario(){
        apodo = "null";
    }
};