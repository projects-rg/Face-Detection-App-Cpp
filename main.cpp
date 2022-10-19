#include<opencv2/imgcodecs.hpp>
#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
using namespace cv;
using namespace std;

/*
	Reading in an image

void main() {

	//std::string 
	string path = "face.jpg";
	Mat image = imread(path);
	imshow("Frame", image);
	waitKey(0);
}*/


//reading in a video
void main() {
	Mat image;
	//VideoCapture video(""); if want to read in a video
	VideoCapture camera(0); 
	CascadeClassifier detectFace;
	detectFace.load("haarcascade_frontalface_default.xml"); //will decide which part is being detected
	//if the camera cannot be opened will show error message
	if (!camera.isOpened()) {
		cout << "cannot open camera";
	}
	//infinite loop
	while (true) {
		camera.read(image);
		vector<Rect> foundFace;
		detectFace.detectMultiScale(image, foundFace, 1.3, 5);	
		for (int i = 0; i < foundFace.size(); i++) {
			//scalar BGR
			rectangle(image, foundFace[i].tl(), foundFace[i].br(), Scalar(255, 0, 0), 3); //draws a rectangle around the face in red
			//will show how many faces are on screen at any given time
			putText(image,"front faces found: "+ to_string(foundFace.size()), Point(10, 60), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 1);
		}
		imshow("Frame", image);
		waitKey(25); //wait ms between frame
	}
}
