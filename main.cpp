// Gabriel Eduardo Melendez Zavala A01638293
#include "Video.h"
#include "Peliculas.h"
#include "Capitulos.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

// void mostrarCatalogo(vector<Video*> videos){};
// void calificarVideo();

int main(){
    // Se crea un vecotr para almacenar los punteros
    vector<Video*> videos;
    ifstream archivo("videos.txt");

    if (archivo.is_open()) {
    string linea;
        while (getline(archivo, linea)) {   
            stringstream ss(linea);
            string t;
            getline(ss, t, ',');


            //me ayudo pablo a armar los punteros para cada serie y pelicula
            if (t == "c") {
                string id, title, str_dur, genre, serie;
                string num_episodio_str;
                int duration, num_episodio;

                getline(ss, id, ',');
                getline(ss, title, ',');
                getline(ss, str_dur, ',');
                getline(ss, genre, ',');
                getline(ss, serie, ',');
                getline(ss, num_episodio_str);

                duration = stoi(str_dur);
                num_episodio = stoi(num_episodio_str);

                videos.push_back(new Capitulos(id, title, duration, genre, serie, num_episodio));
            }
            else if (t == "p") {
                    string id, title, str_dur, genre;

                    int duration;
                    getline(ss, id, ',');
                    getline(ss, title, ',');
                    getline(ss, str_dur, ',');
                    getline(ss, genre);
                    duration = stoi(str_dur);

                    videos.push_back(new Peliculas(id, title, duration, genre));
            }   
            archivo.close();
        }
    }
    else {
    cout << "No se pudo abrir el archivo." << endl;
    }

    int opcion;
    while (true) {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Mostrar todo el catalogo con calificaciones" << endl;
        cout << "2. Calificar un video" << endl;
        cout << "3. Mostrar peliculas o capitulos con una calificacion minima determinada" << endl;
        cout << "4. Mostrar peliculas o capitulos de un cierto genre" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
            cout << "Id, Nombre, Duracion, Genero, (Serie, Episodio), Calificacion"<<endl;
            for(Video* video : videos){
                cout<< *video << endl;
                //cout << video->imprimir() << endl;
                }
                // mostrarCatalogo(videos);
            break;
            case 2:
                {
                string vid_ID = "";
                bool found_vid = false;
                cout << "ID del video a calificar: ";
                cin >> vid_ID;

                for(Video* video : videos) {
                    if (video->getId() == vid_ID) {
                        found_vid = true;

                        int score;
                        cout << "Ingrese la calificación que le quieres asignar a este id: ";
                        cin >> score;

                        // Validar la calificación ingresada
                        while (!score || score < 1 || score > 5) {
                            cout << "Ingrese un valor entre 1 y 5: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> score;
                        }
                        // Establecer la calificación del video
                        video->Calificar(score);

                        cout << "Calificación agregada. Gracias por su opinion" << endl;
                        break;
                    }
                }
                
                if (!found_vid) {
                        cout << "No se encontró un video con el ID ingresado." << endl;
                    }
                break;
                }
            case 3:
                // mostrarVideosPorCalificacion();
                break;
            case 4:
                // mostrarVideosPorGenero();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }

}
    

// void mostrarCatalogo(videos) {
//     // Mostrar todo el catálogo con calificaciones
//     cout << "Id, Nombre, Duracion, Genero, (Serie, Episodio), Calificacion"<<endl;
//     for(Video* video : videos){
//         cout<< *video << endl;
//         //cout << video->imprimir() << endl;
//     }
// }

// void calificarVideo() {
//     string nombre;
//     float calificacion;
//     cout << "Introduzca el nombre del video que desea calificar: ";
//     cin.ignore();
//     getline(cin, nombre);
    
//     bool encontrado = false;
//     for (auto& video : catalogo) {
//         if (video.nombre == nombre) {
//             cout << "Introduzca la calificacion del video (0-10): ";
//             cin >> calificacion;
//             video.calificacion = calificacion;
//             encontrado = true;
//             break;
//         }
//     }
    
//     if (encontrado) {
//         cout << "El video ha sido calificado exitosamente." << endl;
//     } else {
//         cout << "No se encontro ningun video con ese nombre." << endl;
//     }
// }

// void mostrarVideosPorCalificacion() {
//     float calificacionMinima;
//     cout << "Introduzca la calificacion minima: ";
//     cin >> calificacionMinima;
    
//     cout << "Videos con una calificacion minima de " << calificacionMinima << ":" << endl;
//     for (const auto& video : catalogo) {
//         if (video.calificacion >= calificacionMinima) {
//             cout << "Nombre: " << video.nombre << ", Calificacion: " << fixed << setprecision(1) << video.calificacion << endl;
//         }
//     }
// }

// void mostrarVideosPorGenero() {
//     string genre;
//     cout << "Introduzca el genre: ";
//     cin.ignore();
//     getline(cin, genre);
    
//     cout << "Videos del genre \"" << genre << "\":" << endl;
//     for (const auto& video : catalogo) {
//         if (video.genre == genre) {
//             cout << "Nombre: " << video.nombre << ", Calificacion: " << fixed << setprecision(1) << video.calificacion << endl;
//         }
//     }
// }