#include "CImg/CImg.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace cimg_library;

class ImageHandler
{
private:
    // config
    static const int DEFAULT_WIDTH = 800;
    static const int DEFAULT_HEIGHT = 600;
    static const int DEFAULT_CHANNELS = 3; // RGB
    static const int DEFAULT_DEPTH = 1;    // 8-bit per channel
    const int MIN_WIDTH = 32;
    const int MIN_HEIGHT = 32;
    const int MAX_WIDTH = 4096;
    const int MAX_HEIGHT = 4096;

    CImg<unsigned char> currentImage;
    CImgDisplay *currentDisplay;
    bool isFileExists(const std::string &path)
    {
        std::ifstream file(path);
        return file.good();
    }
    void initializeEmptyImage()
    {
        this->currentImage = CImg<unsigned char>(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_DEPTH, DEFAULT_CHANNELS, 255);
    }

    void normalizeImageSize()
    {
        int width = this->currentImage.width();
        int height = this->currentImage.height();
        bool needResize = false;

        if (width < MIN_WIDTH || height < MIN_HEIGHT)
        {
            width = std::max(width, MIN_WIDTH);
            height = std::max(height, MIN_HEIGHT);
            needResize = true;
        }

        if (width > MAX_WIDTH || height > MAX_HEIGHT)
        {
            float ratio = std::min((float)MAX_WIDTH / width, (float)MAX_HEIGHT / height);
            width = std::max(1, static_cast<int>(width * ratio));
            height = std::max(1, static_cast<int>(height * ratio));
            needResize = true;
        }

        if (needResize)
        {
            this->currentImage.resize(width, height, currentImage.depth(), currentImage.spectrum(), 3);
        }
    }

    void showImage(std::string path, bool blocking = true)
    {
        try
        {
            if (currentImage.is_empty())
            {
                initializeEmptyImage();
            }

            normalizeImageSize();

            // Tính toán kích thước cửa sổ hiển thị phù hợp
            int displayWidth = currentImage.width();
            int displayHeight = currentImage.height();

            // Điều chỉnh kích thước hiển thị nếu ảnh quá lớn
            if (displayWidth > DEFAULT_WIDTH || displayHeight > DEFAULT_HEIGHT)
            {
                float ratio = std::min((float)DEFAULT_WIDTH / displayWidth,
                                       (float)DEFAULT_HEIGHT / displayHeight);
                displayWidth *= ratio;
                displayHeight *= ratio;
            }

            if (currentDisplay != nullptr)
            {
                delete currentDisplay;
            }

            // Tạo cửa sổ hiển thị với kích thước đã tính
            currentDisplay = new CImgDisplay(currentImage, path.c_str());
            currentDisplay->resize(displayWidth, displayHeight);
            currentDisplay->set_title(path.c_str());
            currentDisplay->set_normalization(true);

            if (blocking)
            {
                while (!currentDisplay->is_closed() &&
                       !currentDisplay->is_keyQ() &&
                       !currentDisplay->is_keyESC())
                {
                    currentDisplay->wait(50); // 50ms timeout

                    if (currentDisplay->is_keyS())
                    {
                        saveImage(path + "_snapshot.jpg");
                    }
                    if (currentDisplay->is_keyR())
                    {
                        currentImage.rotate(90);
                        currentDisplay->display(currentImage);
                    }
                    // Thêm phím F để toggle fullscreen
                    if (currentDisplay->is_keyF())
                    {
                        currentDisplay->toggle_fullscreen();
                    }
                }
            }
        }
        catch (const CImgException &e)
        {
            std::cerr << "Error displaying image: " << e.what() << std::endl;
            if (currentDisplay != nullptr)
            {
                delete currentDisplay;
                currentDisplay = nullptr;
            }
        }
    }

public:
    ImageHandler() : currentDisplay(nullptr) {}
    ~ImageHandler()
    {
        if (this->currentDisplay != nullptr)
        {
            delete this->currentDisplay;
        }
    }
    bool readImage(const std::string &path)
    {
        try
        {
            if (!isFileExists(path))
            {
                std::cerr << "File does not exist: " << path << std::endl;
                return false;
            }
            // this->currentImage.assign(54,54,1,3);
            initializeEmptyImage();
            this->currentImage.load_bmp(path.c_str());
            normalizeImageSize();
            showImage(path.c_str());
            return true;
        }
        catch (const CImgException &e)
        {
            std::cerr << "Path: " << path << std::endl;
            std::cerr << "Error loading image: " << e.what() << std::endl;
            return false;
        }
    }
    bool saveImage(const std::string &path)
    {
        try
        {
            currentImage.save(path.c_str());
            std::cout << "Image saved successfully to: " << path << std::endl;
            return true;
        }
        catch (const CImgException &e)
        {
            std::cerr << "Error saving image: " << e.what() << std::endl;
            return false;
        }
    }
    void applyGrayscale()
    {
        if (!this->currentImage.is_empty())
        {
            this->currentImage = this->currentImage.get_RGBtoYCbCr().get_channel(0);
            showImage("Grayscale image");
        }
    }
    void resize(int newWidth, int newHeight, int interpolation = 3)
    {
        if (!currentImage.is_empty())
        {
            newWidth = std::max(MIN_WIDTH, std::min(newWidth, MAX_WIDTH));
            newHeight = std::max(MIN_HEIGHT, std::min(newHeight, MAX_HEIGHT));
            currentImage.resize(newWidth, newHeight, -100, -100, interpolation);

            if (currentDisplay != nullptr)
            {
                currentDisplay->display(currentImage);
            }
        }
    }
};

int main()
{
    ImageHandler test;
    test.readImage("Images\\av.bmp");
}