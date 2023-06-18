// Gabriel Eduardo Melendez Zavala A01638293

#include "capitulos.h"
#include <string>


using namespace std;

Capitulos::Capitulos():Video(){ // constructor vacio 
    serie = "";
    num_episodio = 0;
    
}

// constructor de la serie con id, nombre, duracion, genero, la serie y el episodio
Capitulos::Capitulos(string id, string name, int duration, string genre, string serie, int num_episodio):Video(id, name, duration, genre){
    this->serie = serie;

    this->num_episodio = num_episodio;
    
}

Capitulos::~Capitulos(){}//destructor

string Capitulos::imprimir(){
    string output = this->id + ",";
    output +=  this->name + ",";
    output += to_string(duration) + ",";
    output += this->genre + ",";
    output += this->serie + ",";
    output += to_string(this->num_episodio) + ",";
    output +=  imprimir_Calificacion() + ",";
    return output;
    }