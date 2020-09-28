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

    int seleccion;
while(1){
    cout<<"Bienvenido a SocialTube!!"<<endl;
    cout<<"======================"<<endl;
    cout<<"[0] Ingresar"<<endl;
    cout<<"[1] Registrarse"<<endl;
    cout<<"[2] Salir"<<endl;
    cout<<"Tu selecci"<<(char)162<<"n: ";
    cin>>seleccion;

    switch (seleccion)
    {
    case 0:
        socialTube.ingresar();
        break;
    case 1:
        socialTube.registro();
        break;
    case 2:
        return 0;
    default:
        break;
    }
}


    return 0;
}