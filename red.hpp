 #pragma once
#include <string>
#include <iostream>
#include <vector>
#include "usuario.hpp"
#include "ListaEnlazada.hpp"

using std::string;
using std::vector;
using std::endl;
using std::cout;


class red{
    public:
    ;
    usuario usuarioActual;
    ListaEnlazada<usuario> listaUsuarios;
    red(){}
    void anadirUsuario(usuario nuevoUsuario){
        listaUsuarios.InsertarNodoFin(&nuevoUsuario);
    }

    void ingresar(){
        string usuarioTemporal, contrasenaTemporal;
        system("cls");
        cout<<"Ingresa a SocialTube"<<endl;
        cout<<"================="<<endl;
        cout<<"Usuario: ";
        std::cin>>usuarioTemporal;
        cout<<endl<<"Contrase"<<(char)164<<"a: ";
        std::cin>>contrasenaTemporal;

        for(int i = 0; i < ; i++){
            if(usuarioTemporal == usuarios[i].apodo && contrasenaTemporal == usuarios[i].contrasena){
                usuarioActual = usuarios[i];
            }
        }
        if(usuarioActual.apodo == "null"){
            cout<<endl<<"Usuario o contrasena inocorrecto";
        }else{
            cout<<endl<<"Sesion iniciada, bienvenido "<<usuarioActual.apodo;
            sesionPrincipal();//El usuario entra a la red social
        }
    }

    void sesionPrincipal(){
        system("cls");

    }
};