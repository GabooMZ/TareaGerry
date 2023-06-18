#include <iostream>
#include <vector>
#include "video.h"

int main() {
    std::vector<Video> catalogo;
    
    Video video1("formato1", "Nombre Video 1", "Género 1");
    Video video2("formato2", "Nombre Video 2", "Género 2");
    
    catalogo.push_back(video1);
    catalogo.push_back(video2);
    
    // Set califications
    video1.setCalificacion(4.2);
    video2.setCalificacion(3.8);
    
    // Print catalog
    for (const auto& video : catalogo) {
        std::cout << video << std::endl;
    }
    
    // Search videos with a minimum rating
    float minRating = 4.0;
    std::cout << "\nVideos with a minimum rating of " << minRating << ":\n";
    for (const auto& video : catalogo) {
        if (video.getCalificacion() >= minRating) {
            std::cout << video << std::endl;
        }
    }
    
    // Search videos of a specific genre
    std::string targetGenre = "Género 2";
    std::cout << "\nVideos of genre '" << targetGenre << "':\n";
    for (const auto& video : catalogo) {
        if (video.getGenero() == targetGenre) {
            std::cout << video << std::endl;
        }
    }
    
    return 0;
}
