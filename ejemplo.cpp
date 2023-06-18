#include <iostream>
#include <fstream> //para la lectura del archivo
#include <sstream> //para particionar un string
#include <vector>
using namespace std;


void leeArchivoCSV(string nombre){
    ifstream archivo;
    archivo.open(nombre);
    if (archivo.is_open()){
        //declaro un string para guardar un renglón del archivo conforme las vamos leyendo
        string linea; 
        //leo una linea del archivo mientras haya lineas que leer repito el proceso,
        //el getline obtiene la linea del archivo y se guarda en el string linea
        while(getline(archivo,linea)){ 
            //Con la linea que leo, construyo un objeto stringstream para particionar la linea
            stringstream sstr(linea);
            //Declaro un string dato para ir guardando temporalmente una parte de la linea
            string dato;
            //DEclaro un vector para ir guardando cada parte obtenida de la linea
            //Es un vector de strings porque estoy obteniendo strings (partes del string linea)
            vector<string> datos;
            //obtengo una parte de la linea hasta donde encuentre "," y lo hago mientras haya partes
            while (getline(sstr, dato,',')) {
                //Coloco cada parte en el vector
                datos.push_back(dato);
            }
            //Una vez que tengo los datos en el vector los manipulo como requiera
            //Aquí sólo voy a imprimirlos a pantalla con un formato
            cout << "Nombre del profesor: " << datos[0] << endl;
            cout << "Nomina: " << datos[2] << endl;
            cout << "Pertenece a la escuela: " << datos[3]<< endl;
            cout << "Edad: " << datos[1] << endl;
            cout << "Edad dentro de un lustro: " << stoi(datos[1])+ 5 << endl;
            cout << "---------------------------------------------" << endl;
        }
    }
    else{
        cout << "Error de lectura del archivo" << endl;
    }


}
int main(){
    //mando a llamar a la función de lectura del archivo
    leeArchivoCSV("datos.csv");
    return 0;
}
