
int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);



int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}


int HW01_TestFunction() {

	int c;
	string add= "D:\\test\\";
	string add2;
	vector<Mat> va;
	Mat img;
	for (c = 1; c <= 10; c++) {
		stringstream ss;
		ss << c;
		string t = ss.str();	
		add2 = add + t +".jpg";
		cout << add2;
		img = imread(add2);
		va.push_back(img);
		
		namedWindow("Display window", WINDOW_AUTOSIZE);
		imshow("Display window", img);
		
		waitKey(0);
	}

	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	int c;
	string add = "D:\\test\\";
	string add2;
	vector<Mat> va;
	vector<Mat> vg;
	vector<Mat> vb;

	Mat img;
	for (c = 1; c <= 10; c++) {
		stringstream ss;
		ss << c;
		string t = ss.str();
		add2 = add + t + ".jpg";
		cout << add2;
		img = imread(add2);
		va.push_back(img);

		Mat Gray;
		cvtColor(img, Gray, CV_BGR2GRAY);
		vg.push_back(Gray);
		
		Mat Binary;
		threshold(Gray, Binary, 128.0, 255.0, THRESH_BINARY);
		vb.push_back(Binary);
		
		namedWindow("Display window", WINDOW_AUTOSIZE);
		imshow("Display window", img);
		namedWindow("Display GrayImage", WINDOW_AUTOSIZE);
		imshow("Display GrayImage", Gray); 
		namedWindow("Display BinaryImage", WINDOW_AUTOSIZE);
		imshow("Display BinaryImage", Binary);

		waitKey(0);
	}

	return 0;
}
