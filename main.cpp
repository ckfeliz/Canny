#include <iostream>
#include "main.h"
using namespace std;

void edgeDetection(hls::stream image){
	hls::Mat input,output;
	hls::Mat2AXIvideo(image,input);
	hls::GaussianBlur(input,output,input.rows,input.cols);
	hls::Sobel(output,input);

	hls::AXIvideo2Mat(output);

	input = output;

}
