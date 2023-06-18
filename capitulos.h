// Gabriel Eduardo Melendez Zavala A01638293

#ifndef CAPITULOS_H
#define CAPITULOS_H

#include "videos.h"
#include <string>

using namespace std;

class Capitulos:public Video{// incialisas la clase capitulo heredando de video
private:
int num_episodio;
string serie;

public: 
    Capitulos(); //constructores 
    Capitulos(string, string, int, string, string, int); //los capitulos tienen un formato extra para decir la serie/ temporada y el episodio
    ~Capitulos(); //destructor
    
    string imprimir();
};
#endif