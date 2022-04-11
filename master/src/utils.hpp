#ifndef UTILS_HPP
#define UTILS_HPP

#include "highgui.h"
#include <cassert>

#define WND_WIDTH 600
#define WND_HEIGHT 600

inline void create_window(const char *name)
{
    cvNamedWindow(name, 0);
    cvResizeWindow(name, WND_WIDTH, WND_HEIGHT);
}

template<typename T>
int count_pixels(IplImage *img, T val)
{
    int total = 0;

    assert(img->depth == IPL_DEPTH_8U);

    for (int i = 0; i < img->height; ++i) {
        const T *ptr = reinterpret_cast<T*> (img->imageData + i * img->widthStep);

        for (int j = 0; j < img->width; ++j)
            if (static_cast<T> (ptr[j]) == val)
                ++total;
    }

    return total;
}

template<typename T>
void cut(IplImage *img, T threshold, T val = static_cast<T> (255))
{
    int total = 0;

    assert(img->depth == IPL_DEPTH_8U);

    for (int i = 0; i < img->height; ++i) {
        T *ptr = reinterpret_cast<T*> (img->imageData + i * img->widthStep);

        for (int j = 0; j < img->width; ++j)
            if (static_cast<T> (ptr[j]) >= threshold)
                ptr[j] = val;
    }
}

#endif // UTILS_HPP
