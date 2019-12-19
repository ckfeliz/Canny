#include <iostream>
#include <hls_opencv.h>
#include "main.h"
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("Lenna.jpg",IMREAD_COLOR);
	Mat output;
	Canny(image,output,image.cols,image.rows);
	hls::stream imageStream, outputStream;
	cvMat2AXIvideo(image,imageStream);
	outputStream = edgeDetection(imageStream);
	return 0;
}
