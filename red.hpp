 #pragma once
#include <string>
#include <iostream>
#include <vector>
#include "usuario.hpp"
#include "ListaEnlazada.hpp"
#include <conio.h>
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
            if(usuarioTemporal == listaUsuarios.getValue(i).apodo && contrasenaTemporal == listaUsuarios.getValue(i).contrasena || true){
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
        bool statusOn = true;
        while(statusOn){
            system("cls");
            int seleccion;
            cout<<"Social Tube"<<endl;
            cout<<"==========="<<endl;
            cout<<"[0] Hacer una publicacion"<<endl;
            cout<<"[1] Ver perfil de contactos"<<endl;
            cout<<"[2] Ver publicaciones"<<endl;
            cout<<"[3] Ver tu perfil"<<endl;
            cout<<"[4] Salir"<<endl;
            cout<<"Seleccion: ";
            cin>>seleccion;
            switch (seleccion)
            {
            case 1:
                verPerfilContacto();
                break;
            
            default:
                break;
            }
        }
    }
    void verPerfilContacto(){
        system("cls");
        int seleccion;
        cout<<"Contactos Social Tube"<<endl;
        cout<<"====================="<<endl;
        for(int i = 0; i < listaUsuarios.cantidad; i++)
            cout<<"["<<i<<"] "<<listaUsuarios.getValue(i).apodo<<endl;
        cout<<"Seleccion: ";
        cin>>seleccion;
        verPublicaciones(listaUsuarios.getValue(seleccion));
    }

    void verPublicaciones(usuario us){
        int selection;
        system("cls");
        cout<<"Publicaciones de "<<us.apodo<<endl;
        cout<<"========================="<<endl;
        if(us.publicaciones.cantidad != 0){
            for(int i = 0; i < us.publicaciones.cantidad; i++)
                cout<<"["<<i<<"] "<<listaUsuarios.getValue(i).apodo<<endl<<endl;
        }else{
            cout<<"Este usuario no cuenta con publicaciones:("<<endl;
        }
        cout<<endl<<"Pulse cualquier boton para regresar"<<endl;
        getch();
    }
};