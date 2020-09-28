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
    usuario* usuarioActual;
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
                usuarioActual = listaUsuarios.getValue(i);
            }
        }
        if(usuarioActual->apodo == "null"){
            cout<<endl<<"Usuario o contrasena inocorrecto"<<endl;
        }else{
            cout<<endl<<"Sesion iniciada, bienvenido "<<usuarioActual->apodo;
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
            //cout<<"[2] Ver publicaciones"<<endl;
            cout<<"[2] Ver tu perfil"<<endl;
            cout<<"[3] Cerrar sesion"<<endl;
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
            case 2:
                verPublicaciones(posicion(usuarioActual->apodo));
                break;
            case 3:
                statusOn = false;
                break;
            default:
                break;
            }
        }
    }
    int posicion(string apodo){
        for(int i = 0; i < listaUsuarios.cantidad; i++){
            if(apodo == listaUsuarios.getValue(i)->apodo) return i;
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
        usuarioActual->publicaciones.InsertarNodoFin(nuevaPublicacion);
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
        verPublicaciones(seleccion);
    }


    void verPublicaciones(int a){
        usuario* usuariFunc = listaUsuarios.getValue(a); 
        int selection;
        system("cls");
        cout<<"Publicaciones de "<<listaUsuarios.getValue(a)->apodo<<endl;
        cout<<"========================="<<endl;
        int cantidadTweets = listaUsuarios.getValue(a)->publicaciones.cantidad;
        if(cantidadTweets != 0){
            for(int i = 0; i < cantidadTweets; i++)
                cout<<"["<<i<<"] "<< usuariFunc->publicaciones.getValue(i)->contenido <<endl<<endl;
            cout<<endl<<endl<<"["<< cantidadTweets <<"] Salir"<<endl;
            cout<<"Seleccion: ";
            cin>>selection;
            if(selection < cantidadTweets && selection >= 0){
                int op;
                system("cls");
                cout<<"Publicacion de: "<<usuariFunc->apodo<<endl;
                cout<<"================="<<endl<<(char)219<<usuariFunc->publicaciones.getValue(selection)->contenido;
                cout<<endl<<endl<<"Likes: "<<usuariFunc->publicaciones.getValue(selection)->likes;
                cout<<" | RTs: "<<usuariFunc->publicaciones.getValue(selection)->RTs<<endl;
                cout<<"[0] Dar like"<<endl;
                cout<<"[1] Dar RT"<<endl;
                cout<<"[2] Salir"<<endl;
                cout<<"Seleccion: ";cin>>op;
                switch (op)
                {
                case 0:
                    usuariFunc->publicaciones.getValue(selection)->agregarLike();

                    break;
                case 1:
                    usuariFunc->publicaciones.getValue(selection)->agregarRT();
                    usuarioActual->publicaciones.InsertarNodoFin(usuariFunc->publicaciones.getValue(selection));
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

    } 

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
            cout << "Contrase"<<(char)164<<"a: ";
            cin >> contra;
            cout << "Repetir Contrase"<<(char)164<<"a: ";
            cin >> rcontra;

            if (contra == rcontra) {
                usuario* un = new usuario(user, contra, correo); //crea objeto usuario con los datos escritos

                listaUsuarios.InsertarNodoFin(un); //inserta el objeto usuario en la lista de cuentas
                archivo << "\n" << user << "," << correo << ";" << contra;
                archivo.close();
                usuarioActual = un;
                cout<<endl<<"Cuenta registrada correctamente, bienvenido a SocialTube "<<usuarioActual->apodo;
                cout<<endl<<endl<<"Pulse cualquier tecla para acceder a su cuenta";
                getch();
                sesionPrincipal();
            }
            else{
                cout<<endl<<"Fallo al registrar cuenta, las contrase"<<(char)164<<"as no coinciden";
            }
        
    }
};