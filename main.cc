#include <iostream>
#include <fstream>
#include <windows.h>
#include <pam.h>

using namespace std;

int main() {
	//Meu primeiro programa para gerar um mapa bitmap em formato PPM. Ele gera um lindo mapa arco-íris!
    // Image
    const int image_width = 256;
    const int image_height = 256;
    //Agora está renderizando! mas somente a primeira linha e a ultima coluna da imagem... (?)



    // Render
	
	//std::cout << "P3\n" << image_height << ' ' << image_width << "\n255\n";
	ofstream img ("image.ppm");
    img << "P3" << endl;
    img << image_width << ' ' << image_height << ' ' << "\n255\n" << endl;

    for (int j = image_height-1 ; j >= 0 ; --j) {
    	//um codigo de contador, que aqui é inutil, mas pode ser util em outra ocasião (ele deixa a compilação mais lenta).
    	//std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            int auto r = 255.999 * (double(i) / (image_width-1));
            int auto g = 255.999 * (double(j) / (image_height-1));
            int auto b = (255.999 * 0.25);
			
			//Não precisa desses códigos estras, eles são inuteis aqui, só servem para atrapalhar e eu só não deletei para eu sempre me lembrar que eles são inuteis, só isso mesmo...
            //int ir = static_cast<int>(255.999 * r);
            //int ig = static_cast<int>(255.999 * g);
            // Deu certo! Preciso então passar as variaveis r, g e b para o img, ao inves de ir, ig e ib.
            //int ib = static_cast<int>(255.999 * b);
            
            //Mais código inutil...
            //std::cout << ir << ' ' << ig << ' ' << ib << '\n';
			img << r << ' ' << g << ' ' << b << '\n' << endl;
        }
    }
    return 0;
    //Outra parte do código do contador. Igualmente sem valor aqui nesse programa.
    //std::cerr << "\nDone.\n";
}
