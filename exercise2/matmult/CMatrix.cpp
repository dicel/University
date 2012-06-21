// file...: CMatrix.cpp
// desc...: matrix helper class implementation
// oct-2010 | a.knirsch@fbi.h-da.de

#include <iostream>
#include <fstream>
#include <assert.h>
#include "CMatrix.h"

using namespace std;

void printError(const char* progname, const char* error) {
	if(error != NULL) {
		cerr << "ERROR: " << error << endl;
	}
	cerr << "usage: " << progname << " <width> <heigth>" << endl
	<< "\t<width> and <heigth> are of type unsigned int" << endl;
}
	
// create matrix from given file
CMatrix::CMatrix(const char* filename) {
	width = 0;
	height = 0;		
	FILE* pFile = NULL;
	double value = 0.0;
	unsigned int i = 0;
	
	pFile = fopen (filename,"r");
	if (pFile == NULL) {
		perror ("Error opening file");
	} else {
		assert(1 == fscanf(pFile, "%u", &width));
		assert(1 == fscanf(pFile, "%u", &height));
		container = new double[size()];
		while(EOF != fscanf(pFile, "%lf", &value)) {
			container[i++] = value;
		}
		fclose(pFile);
		assert(size() == i);
	}
	
}

// create empty matrix with given size
CMatrix::CMatrix(unsigned int w, unsigned int h) {
	width = w;
	height = h;
	container = new double[size()];
	for(unsigned int i=0; i<size(); i++) {
		container[i] = 0.0;
	}
}

CMatrix::~CMatrix() { delete[] container; container = NULL; }

unsigned int CMatrix::size() { return height * width; }

double * CMatrix::operator[]( unsigned int rowNumber ) {
	assert( rowNumber < height );
	return container + (rowNumber * width );
}

void CMatrix::print() {
	cout << width << " " << height << endl;
	for(unsigned int i=0; i<size(); i++) {
		cout << container[i];
		if(((i+1)%width)==0) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
}
