// Gabriel Eduardo Melendez Zavala A01638293
#ifndef PELICULAS_H
#define PELICULAS_H


#include "videos.h"
#include <string>

using namespace std;

class Peliculas:public Video{ // se inicializa la clase pelicula con herencia de video
public:
    Peliculas();
    Peliculas(string, string, int, string);
    ~Peliculas();
    string imprimir();
};

#endif