//#include <opencv2/opencv.hpp>
//
//using namespace cv;
//
//int main(int argc, char *argv[]) {
//    Mat image, out;
//
//    image = imread("/home/kb1prb13/LOCAL/IG_1-14/2016-2017/Image/Intensity/lena.png", CV_LOAD_IMAGE_GRAYSCALE);
//
//    if(!image.data)return -1;
//
//    image.convertTo(out, CV_8U);
//
//    for (int y = 0; y < out.cols; y++)  for (int x = 0; x < out.rows; x++)  out.at<uchar>(y, x) /= 2;
//
//    //threshold(out, out, 128, 255, THRESH_TRUNC);
//    threshold (out,out,64,128,THRESH_BINARY);
//    //threshold(out, out, 32, 64, THRESH_TRUNC);
//    //threshold(out, out, 16, 255, THRESH_TRUNC);
//
//    namedWindow("Lena", CV_WINDOW_AUTOSIZE);
//    namedWindow("Out",  CV_WINDOW_AUTOSIZE);
//
//    imshow("Lena", image);
//    imshow("Out", out);
//
//    waitKey(0);
//    return 0;
//}

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
    Mat image = imread("/home/kb1prb13/LOCAL/IG_1-14/V/Image/Group/IntensityGroup/origin.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    if(!image.data)return 0;

    imshow("Original Image", image);
    int min = 150;
    int M = image.rows;
    int N = image.cols * image.channels();
    for(int i = 0; i < M; i++) {
        uchar *data = image.ptr<uchar>(i);
        for(int j = 0; j < N; j++) {
            if(data[j] > min)
                data[j] = 255;
            else data[j] = 0;
        }
    }
    imshow("Processed Image", image);

    waitKey(0);
}
