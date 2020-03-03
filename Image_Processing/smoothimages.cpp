// Code for smoothing images using OpenCV function

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    Mat image = imread("C:/MS/Research/USL/Code/Smooth/Image1.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image. Exiting the program. Hit any key to exit." << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    // Use the OpenCV function to blur/smoothen images using Gaussian blur
    Mat smoothenedImage;
    GaussianBlur(image, smoothenedImage, Size(5, 5), 0);

    // Name of the windows
    String orginalImageWindow = "Original Image";
    String smoothenedImageWindow = "Smoothened_Image";

    // Windows to display the images
    namedWindow(orginalImageWindow);
    namedWindow(smoothenedImageWindow);

    // Display the two images
    imshow(orginalImageWindow, image);
    imshow(smoothenedImageWindow, smoothenedImage);

    // Wait for a key input and then destroy all the open windows
    waitKey(0);
    destroyAllWindows();

    return 0;
}
