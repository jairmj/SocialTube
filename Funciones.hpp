#pragma once
#include "red.hpp"
#include "tweet.hpp"
#include "ListaEnlazada.hpp"
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::ifstream;


void cargarDatos(red* redSocial){

    int seleccion;
    string user, correo, pass;
    user = correo = pass = "";
    int posComa, posPuntoComa;
    string linea;
    vector<string> text;
    ifstream archivo;
    archivo.open("cuentas.txt");
    while(!archivo.eof()){
        getline(archivo, linea);
        text.push_back(linea);
    }
    archivo.close();
    
    int j = 0;
    for(int i = 0; i < text.size(); i++){
        for(auto x: text[i]){
            int posComa = text[i].find(',');
            int posPuntoComa = text[i].find(';');
            if(j < posComa)
                user = user + x;
            if(j > posComa && j < posPuntoComa)
                correo = correo + x;
            if(j > posPuntoComa)
                pass = pass + x;
            j++;
        }
        j = 0;
        usuario* usuarioTemporal;
        usuarioTemporal = new usuario(user, pass, correo);
        redSocial->anadirUsuario(usuarioTemporal);
        user = correo = pass = "";
    } 
}

void imprimirDatos(red socialTube){
    for(int i = 0; i < socialTube.listaUsuarios.cantidad; i++){
        cout<<"Usuario: "<<socialTube.listaUsuarios.getValue(i)->apodo;
        cout<<" Email: "<<socialTube.listaUsuarios.getValue(i)->correo;
        cout<<" Pass: "<<socialTube.listaUsuarios.getValue(i)->contrasena<<endl;
    }
}

void cargarPublicaciones(ListaEnlazada<usuario>* listaUsuarios){
    listaUsuarios->getValue(0)->publicaciones.InsertarNodoFin(new tweet("Me encanta esta red social"));
    listaUsuarios->getValue(1)->publicaciones.InsertarNodoFin(new tweet("Ayer comi mi plato favorito"));
    listaUsuarios->getValue(2)->publicaciones.InsertarNodoFin(new tweet("Voy a mudarme dentro de poco"));
    listaUsuarios->getValue(3)->publicaciones.InsertarNodoFin(new tweet("Estoy muy triste"));
    listaUsuarios->getValue(4)->publicaciones.InsertarNodoFin(new tweet("Me van a subir el sueldo"));
    listaUsuarios->getValue(5)->publicaciones.InsertarNodoFin(new tweet("necesito ir de compras"));
}