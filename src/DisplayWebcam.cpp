#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	VideoCapture cap(0); 	// open the default camera
	if( !cap.isOpened() )	// check if we succeeded
		return -1;
	
	Mat edges;
	namedWindow( "edges", WINDOW_AUTOSIZE );
	for(;;){
		Mat frame;
		cap >> frame;		// get a new frame from camera
		//cvtColor(frame, edges, COLOR_BGR2GRAY);
		imshow( "Webcam", frame );
		if( waitKey(30) >= 0 ) break;
	}
	// the camera is deinitialized automatically in VideoCapture destructor
	return 0;
}
