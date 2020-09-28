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

        for(int i = 0; i < listaUsuarios.cantidad; i++){
            if(usuarioTemporal == listaUsuarios.getValue(i).apodo && contrasenaTemporal == listaUsuarios.getValue(i).contrasena){
                usuarioActual = listaUsuarios.getValue(i);
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
        cout<<"Social Tube"<<endl;
        cout<<"==========="<<endl;
        cout<<"[0] Ver perfil de contactos"<<endl;
        cout<<"[1] Ver publicaciones"<<endl;
        cout<<"[2] Ver tu perfil"<<endl;
        cout<<"[3] Salir"<<endl;
        cout<<"Seleccion: ";
    }
};