#ifndef GROUP_HPP
#define GROUP_HPP
#include "highgui.h"

struct struct_sun 
{
	coordinate center;
	int radius;
};

struct group_sunspot {
	int id_group;
	std::vector<unsigned int>  blobids;
};

typedef std::vector<group_sunspot> group_sunspot_vector;

IplImage *circle_sunspots(IplImage *img, blob_collection &blobs);

struct_sun center_sun(IplImage *img, int debug);

group_sunspot_vector count_groups(const struct_sun &sun, blob_collection &blobs, IplImage *img);

void put_group (group_sunspot_vector &groups, unsigned int blobida, unsigned int blobidb);


#endif // UTILS_HPP
