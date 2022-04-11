#ifndef BLOB_HPP
#define BLOB_HPP

#include <map>
#include <list>
#include "highgui.h"

struct coordinate
{
    unsigned int x, y;
    void * data;
};

struct blob
{
    //unsigned int blobId;
    coordinate min, max;

    coordinate center;

    double lat;
    double lon;

    std::vector<coordinate> listPoints;
};

typedef std::map<unsigned int, blob> blob_collection;

blob_collection detectBlobs(IplImage* frame);

#endif // BLOB_HPP
