/*************************************************************************
	> File Name: cv_util.h
	> Author: caowenlong
	> Mail: caowenlong92@gmail.com 
	> Created Time: 2019年07月31日 星期三 20时02分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
// struct_type = st
template <typename T>
typedef struct cfImage {
	T left;
	T top;
	T right;
	T bottom;
} cfImage;

using cf_image_i = cfImage<int>;
using cf_image_f = cfImage<float>;
