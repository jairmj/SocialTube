#include "red.hpp"

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