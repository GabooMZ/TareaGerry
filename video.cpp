// Gabriel Eduardo Melendez Zavala A01638293
#include "video.h"
#include <string>
using namespace std;

Video::Video():Video("","",0,""){}

Video::Video(string id, string name, int duration, string genre){
    this->id = id;
    this->name = name;
    this->duration = duration;
    this->genre = genre;
    suma_calificaciones = 0;
    num_calificaciones = 0;
    total_Calificacion = 0;}

Video::~Video(){}
string Video::getId(){
    return this->id;}

double Video::getCalificacion(){
    return this->total_Calificacion;}

string Video::getGenero(){
    return this->genre;
    }
void Video::Calificar(int calificacion){
    this->suma_calificaciones += calificacion;
    this->num_calificaciones++; 
    this->calcular_calificacion();
     
    }

void Video::calcular_calificacion(){
    if (this->num_calificaciones !=0){
        this->total_Calificacion = (double)this->suma_calificaciones/this->num_calificaciones;
    }}
string Video::SC(){
    if (this->suma_calificaciones != 0){
        return to_string(this->total_Calificacion);
    }
    else{
        return "SC";
    }
}

string Video::imprimir_Genero(){
    return this->genre;}

string Video::imprimir_Calificacion(){
    return to_string(this->total_Calificacion);}