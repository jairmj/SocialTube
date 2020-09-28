#include "usuario.hpp"

#include <string>;
#include <vector>;
#include <fstream>;
using std::string;
using std::vector;
using std::ifstream;


void cargarDatos(){
    int seleccion;
    string user, correo, pass;
    user = correo = pass = "";
    int posComa, posPuntoComa;
    string linea;
    vector<string> text;
    vector<usuario> vectorUsuarios;
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
        usuario nuevoUsuario(user, correo, pass);
        vectorUsuarios.push_back(nuevoUsuario);
        user = correo = pass = "";
    }
}