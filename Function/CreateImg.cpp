#include "CImg/CImg.h"
using namespace cimg_library;

int main() {
    int width = 256;
    int height = 256;
    CImg<unsigned char> image(width, height, 1, 3, 0);

    // Tạo gradient
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            // Red channel
            image(x,y,0,0) = x;
            // Green channel
            image(x,y,0,1) = y;
            // Blue channel
            image(x,y,0,2) = (x + y) / 2;
        }
    }

    // Hiển thị và lưu ảnh
    CImgDisplay display(image, "Gradient");
    image.save("gradient.bmp");
    
    while(!display.is_closed()) {
        display.wait();
    }

    return 0;
}