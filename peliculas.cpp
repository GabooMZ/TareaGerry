// Gabriel Eduardo Melendez Zavala A01638293

#include <string>
#include "peliculas.h"


using namespace std;

Peliculas::Peliculas():Video(){}//constructor inicial
Peliculas::Peliculas(string id, string name, int duration, string genre):Video(id, name, duration, genre){}//cponsturctor con parametros

string Peliculas::imprimir(){ // imprimir con el formato standard del ejercicio
    string output = this->id + ",";
    output +=  name + ",";
    output += to_string(duration) + ",";
    output += genre + ",";
    output +=  imprimir_Calificacion() + ",";
    return output;
}
Peliculas::~Peliculas(){}// destructor