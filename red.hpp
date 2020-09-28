 #pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "usuario.hpp"
#include "tweet.hpp"
#include "ListaEnlazada.hpp"
#include <conio.h>
using std::string;
using std::vector;
using std::endl;
using std::cout;


class red{
    public:
    usuario usuarioActual;
    ListaEnlazada<usuario> listaUsuarios;
    red(){}
    void anadirUsuario(usuario* nuevoUsuario){//nuevoUsuario apunta al usuario que quiero guardar
        listaUsuarios.InsertarNodoFin(nuevoUsuario);//el valor de nuevoUsuario es la direccion de memoria del usuario
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
            if(usuarioTemporal == listaUsuarios.getValue(i)->apodo && contrasenaTemporal == listaUsuarios.getValue(i)->contrasena){
                usuarioActual = *listaUsuarios.getValue(i);
            }
        }
        if(usuarioActual.apodo == "null"){
            cout<<endl<<"Usuario o contrasena inocorrecto"<<endl;
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
            case 0:
                hacerPublicacion();
                break;
            case 1:
                verPerfilContacto();
                break;
            case 3:
                verMisPublicaciones();
                break;
            case 4:
                statusOn = false;
                break;
            default:
                break;
            }
        }
    }

    void hacerPublicacion(){
        string textoPublicacion;
        system("cls");
        int seleccion;
        cout<<"Social Tube - Crear Publicacion"<<endl;
        cout<<"==============================="<<endl;
        cout<<endl<<(char)168<<"En qu"<<(char)130<<" est"<<(char)160<<"s pensando? ";
        cin>>textoPublicacion;
        tweet*  nuevaPublicacion;
        nuevaPublicacion = new tweet(textoPublicacion);
        usuarioActual.publicaciones.InsertarNodoFin(nuevaPublicacion);
        cout<<endl<<"Publicaci"<<(char)162<<"n realizada!";
        cout<<endl<<endl<<"Pulse cualquier tecla para regresar";
        getch();
    }

    void verPerfilContacto(){
        system("cls");
        int seleccion;
        cout<<"Contactos Social Tube"<<endl;
        cout<<"====================="<<endl;
        for(int i = 0; i < listaUsuarios.cantidad; i++)
            cout<<"["<<i<<"] "<<listaUsuarios.getValue(i)->apodo<<endl;
        cout<<"Seleccion: ";
        cin>>seleccion;
        //usuario* usuarioTarget = &listaUsuarios.getValue(seleccion);
        //verPublicaciones(usuarioTarget);
    }
    void verMisPublicaciones(){
        int selection;
        system("cls");
        cout<<"Publicacion de: "<<usuarioActual.apodo<<endl;
        cout<<"========================="<<endl;
        int cantidadTweets = usuarioActual.publicaciones.cantidad;
        if(cantidadTweets != 0){
            for(int i = 0; i < cantidadTweets; i++){
                cout<<"["<<i<<"] "<<usuarioActual.publicaciones.getValue(i)->contenido<<endl;
            }
            cout<<endl<<endl<<"["<<usuarioActual.publicaciones.cantidad<<"] Salir"<<endl;
            cout<<"Seleccion: ";
            cin>>selection;
            int op;
            system("cls");
            cout<<"Publicacion de: "<<usuarioActual.apodo<<endl;
            cout<<"================="<<endl<<(char)219<<usuarioActual.publicaciones.getValue(selection)->contenido;
            cout<<endl<<endl<<"Likes: "<<usuarioActual.publicaciones.getValue(selection)->likes;
            cout<<" | RTs: "<<usuarioActual.publicaciones.getValue(selection)->RTs<<endl<<endl;
            cout<<"[0] Dar like"<<endl;
            cout<<"[1] Dar RT"<<endl;
            cout<<"[2] Salir"<<endl;
            cout<<"Seleccion: ";cin>>op;
            switch (op)
            {
            case 0:
                usuarioActual.publicaciones.getValue(selection)->agregarLike();
                break;
            case 1:
                usuarioActual.publicaciones.getValue(selection)->agregarRT();
                break;
            default:
                break;
            }
            
        }   
    }
    /* void verPublicaciones(int a){
        int selection;
        system("cls");
        cout<<"Publicaciones de "<<us->apodo<<endl;
        cout<<"========================="<<endl;
        int cantidadTweets = us->publicaciones->cantidad;
        if(cantidadTweets != 0){
            for(int i = 0; i < cantidadTweets; i++)
                cout<<"["<<i<<"] "<< us->publicaciones->getValue(i)->contenido <<endl<<endl;
            cout<<endl<<endl<<"["<<us->publicaciones->cantidad<<"] Salir"<<endl;
            cout<<"Seleccion: ";
            cin>>selection;
            if(selection < cantidadTweets && selection >= 0){
                int op;
                system("cls");
                cout<<"Publicacion de: "<<us->apodo<<endl;
                cout<<"================="<<endl<<(char)219<<us->publicaciones->getValue(selection)->contenido;
                cout<<endl<<endl<<"Likes: "<<us->publicaciones->getValue(selection)->likes;
                cout<<" | RTs: "<<us->publicaciones->getValue(selection)->RTs<<endl;
                cout<<"[0] Dar like"<<endl;
                cout<<"[1] Dar RT"<<endl;
                cout<<"[2] Salir"<<endl;
                cout<<"Seleccion: ";cin>>op;
                switch (op)
                {
                case 0:
                    us->publicaciones->getValue(selection)->agregarLike();

                    break;
                case 1:
                    us->publicaciones->getValue(selection)->agregarRT();
                    break;
                case 2:
                    break;
                default:
                    break;
                }
            }
        }else{
            cout<<"Este usuario no cuenta con publicaciones:("<<endl;
            cout<<endl<<"Pulse cualquier boton para regresar"<<endl;
            getch();
        }

    } */

    void registro(){
        string user, contra, correo, rcontra;
        ofstream archivo("cuentas.txt", std::ios_base::app);

        system("cls");
            cout << "Registrarse" << endl;
            cout << "===========" << endl;
            cout << "Usuario: ";
            cin >> user;
            cout << "Correo: ";
            cin >> correo;
            cout << "Contraseña: ";
            cin >> contra;
            cout << "Repetir Contraseña: ";
            cin >> rcontra;

            if (contra == rcontra) {
                usuario* un = new usuario(user, contra, correo); //crea objeto usuario con los datos escritos

                listaUsuarios.InsertarNodoFin(un); //inserta el objeto usuario en la lista de cuentas
                archivo << "\n" << user << "," << correo << ";" << contra;
                cout<<endl<<"Cuenta registrado correctamente, bienvenido a SocialTube"<<usuarioActual.apodo;
                archivo.close();
                usuarioActual = *un;
                sesionPrincipal();
            }
            else{
                cout<<endl<<"Fallo al registrar cuenta, las contrase"<<(char)164<<"as no coinciden";
            }
        
    }
};