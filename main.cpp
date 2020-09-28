#include <iostream>
#include "usuario.hpp"
#include "red.hpp"
#include "tweet.hpp"
#include "Funciones.hpp"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;


int main(){

/*     for(auto x: vectorUsuarios){
        cout<<"Usuario: "<<x.apodo<<" email: "<<x.correo<<" contra: "<<x.contrasena<<endl;
    } */
    red socialTube;
    cargarDatos(&socialTube);
    for(int i = 0; i < socialTube.listaUsuarios.cantidad; i++){
        cout<<"Usuario: "<<socialTube.listaUsuarios.getValue(i).apodo;
        cout<<" Email: "<<socialTube.listaUsuarios.getValue(i).correo;
        cout<<" Pass: "<<socialTube.listaUsuarios.getValue(i).contrasena<<endl;
    }
    int seleccion;
    /* while(1){
        cout<<"Bienvenido a SocialTube!!"<<endl;
        cout<<"======================"<<endl;
        cout<<"[0] Ingresar"<<endl;
        cout<<"[1] Registrarse"<<endl;
        cout<<"[2] Ver publicaciones"<<endl;
        cout<<"[3] Salir"<<endl;
        cout<<"Tu selecci"<<(char)162<<"n: ";
        cin>>seleccion;

        switch (seleccion)
        {
        case 0:
            socialTube.ingresar();
            break;
        case 2:
        default:
            break;
        }
    } */
    cin>>seleccion;

    return 0;
}