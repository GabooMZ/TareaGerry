// Gabriel Eduardo Melendez Zavala A01638293
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

using namespace std;

class Video { // se crea la clase base de video
    protected: // se declaran los atributos
        string name, genre, id;
        int duration,num_calificaciones, suma_calificaciones;
        double total_Calificacion;



public: // se declaran todos los metodos  
    Video();
    Video(string, string, int,string);
    ~Video();

    string getId();
    double getCalificacion();
    string getGenero();

    void calcular_calificacion();
    void Calificar(int);
    virtual string imprimir()=0;
    string imprimir_Calificacion();
    string imprimir_Genero();
    string SC();

    friend ostream& operator<<(ostream& os,  Video& video){
    os<<video.imprimir();
    return os;
    }
};

#endif // VIDEO_H