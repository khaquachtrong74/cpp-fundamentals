// purpose: make something
// #define cimg_use_png
#include <iostream>
#include "CImg/CImg.h"
#include <vector>
#include<string>
using namespace cimg_library;
void program()
{
    std::cout << "Hello Detbeed!\n";
}
// show image;
void showImage(CImgDisplay& display){
    while(!display.is_closed()){
        display.wait();
        if(display.is_keyESC())
            break;
    }
}

// read image with path ()
void readImage(std::string path){
    try
    {
        // it's only read default (bmp).
        CImg<unsigned char> image("D:\\ProgramingCPP\\Function\\Images\\Struct.bmp"); // read image |
        showImage(new CImgDisplay(image, "Read Image"));
    }
    catch (const CImgException &e)
    {
        std::cerr << "Error loading image: " << e.what() << std::endl;
        return;
    }
}
// create image with matrix and use RGB to make it beauty
void createImageWithRGB(){
    try{
        // create bmp with matrix
        const int M = 500;
        const int N = 500;
        // width = N, height = M, depth= 1, channels=3 (RGB), init=0
        CImg<unsigned char> image(N, M, 1, 3, 0);
        // draw color on image
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                // channel RED
                image(j,i,0,0) = (i*255)/M; //Gradient red with columns directions
                // channel GREEN
                image(j,i,0,1) = (j*255)/N; // Gradient green with rows directions
                image(j,i,0,2) = 128; // blue static
            }
        }
        
        CImgDisplay display(image, "Color Image");
        image.save("Color_image.bmp");
        while(!display.is_closed()){
            display.wait();
        }
    }   
    catch(CImgException &e){
        std::cerr<<"Failed to create Image: "<<e.what()<<std::endl;
    }
}

void createChart(){
    const int width=800;
    const int height=600;
    const int margin=50;

    // create blank image
    CImg<unsigned char> img(width, height, 1, 3, 255);
    
    // sample data
    const int numPoints = 10;
    float dataPoints[10] = {50,80,65,90,75,85,70,95,60,80};
    // find min/max
    float minVal = dataPoints[0];
    float maxVal = dataPoints[0];
    for(int i = 1; i < numPoints; i++){
        if(dataPoints[i] < minVal) minVal = dataPoints[i];
        if(dataPoints[i] > maxVal) maxVal = dataPoints[i];
    }

    // draw
    unsigned char black[] ={0,0,0};
    // truc x
    img.draw_line(margin, height-margin, width-margin, height-margin, black);
    // truc y
    img.draw_line(margin,margin, margin, height-margin, black);

    // draw chart
    const float xStep = (width-2*margin) / (float)(numPoints-1);
    const float yScale = (height-2*margin)/ (maxVal-minVal);

    unsigned char blue[] = {0,0,255};
    unsigned char red[] = {255,0,0};

    for(int i = 0; i < numPoints-1;i++){
        float x1 = margin+i*xStep;
        float x2 = margin +(i+1)*xStep;
        float y1 = height-margin- (dataPoints[i]-minVal)*yScale;
        float y2 = height-margin- (dataPoints[i+1]-minVal)*yScale;

        // draw line
        img.draw_line(x1,y1,x2,y2,blue);
        img.draw_circle(x1,y1,3,red);
    }
    // draw last point
    img.draw_circle(margin + (numPoints-1)*xStep,
        height - margin - (dataPoints[numPoints-1] - minVal)*yScale,
        3, red
    );
    CImgDisplay display(img, "Line chart");
    while(!display.is_closed()){
        display.wait();
    }
}

int main()
{
    // read image
    // createImageWithRGB();
    createChart();
    program();
}