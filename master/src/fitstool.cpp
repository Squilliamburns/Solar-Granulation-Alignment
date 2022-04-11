#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cmath>
#include "fitstool.hpp"
#include <CCfits/CCfits>

using namespace CCfits;

void getDatefit(const char * sfitsfile, std::string &sdate)
{

    fitsfile *fptr;       /* pointer to the FITS file; defined in fitsio.h */
    int status, ii, jj;
    long  fpixel = 1, naxis = 2, nelements, exposure;
    long naxes[2] = { 512, 512 };   /* image is 300 pixels wide by 200 rows */
    short array[512][512];
	
    status = 0;         /* initialize status before calling fitsio routines */
    ffopen(&fptr, sfitsfile, 0, &status);   /* create new file */
	
	char date[20];
	
	char comm[255];
	
	
	ffgkey(fptr, "DATE", date, comm, &status);
	
	ffclos(fptr, &status);
	
	sdate = std::string(date);
}
