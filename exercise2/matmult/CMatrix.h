// file...: CMatrix.h
// desc...: minimalistic helper class to hold matrix information 
// oct-2010 | a.knirsch@fbi.h-da.de

#ifndef CMATRIX_H_
#define CMATRIX_H_

#include <assert.h>

// some helper
void printError(const char* progname, const char* error = NULL);


class CMatrix {
public:
	
	// create matrix from given file
	CMatrix(const char* filename);
	
	// create empty matrix with given size
	CMatrix(unsigned int w, unsigned int h);
	
	// destructor
	~CMatrix();
	
	// size of matrix (amount of values)
	unsigned int size();
	
	// print matrix to stdout
	void print();
	
	// row selector -
	// with this, you can use matrix[row][col] 
	double * operator[]( unsigned int rowNumber );
	
	// public for smplification
	unsigned int height;
	unsigned int width;
	double* container;
};


#endif // CMATRIX_H_

