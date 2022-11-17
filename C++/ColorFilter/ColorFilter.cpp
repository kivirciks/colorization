﻿#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <shlwapi.h>
#include <ctime>
#include <cstdio>

using namespace cv;
using namespace std;

int main()
{
    //кириллица в консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double start = clock();

    //загрузка изображения
    cout << "Введите полный путь фотографии: " << endl;
    //пример пути "C:\\Users\\username\\Desktop\\image.jpg"
    string path;
    cin >> path;


    Mat img = imread(path);
    //вывод оригинального фото
    namedWindow("original", WINDOW_AUTOSIZE);
    imshow("original", img);

    Mat img2 = imread(path);
    Mat bluemat;
    //преобразование в оттенки синего
    bluemat = img2;
    for (int i = 0; i < img2.rows; i++)
        for (int j = 0; j < img2.cols; j++)
        {
            //максимализация синего канала
            img2.at<Vec3b>(i, j)[0] = 255;
        }
    //вывод синего фото
    namedWindow("windwindow_blue", WINDOW_AUTOSIZE);
    imshow("windwindow_blue", bluemat);
    //сохранение на устройство (в папке проекта ColorFilter)
    imwrite("blueIMG.jpg", bluemat);
    waitKey(0);

    printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
