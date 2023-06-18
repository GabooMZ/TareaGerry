#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    fstream archivo("videos.txt");
    string linea;
    cout<<"hola"<<endl;
    while(getline(archivo, linea)){
        cout<<"linea:"<< linea<<endl;
        cout<<"hola2"<<endl;

    }
    archivo.close();
}