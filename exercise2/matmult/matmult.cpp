// file...: matmult.cpp
// desc...: parallel matrix multiplication solution
// may 2012 | christoph@cdietzel.de

#include <iostream>
#include <assert.h>
#include <mpi.h>
#include "CMatrix.h"

using namespace std;

// +++ main starts here +++
int main(int argc, char** argv) {
	
	// process arguments
	/*if(argc != 3) {
		printError(argv[0], "wrong number of arguments.");
		return -1;
	}*/ //Arguments are hard coded for development
	
	MPI::Init();
	
	CMatrix m1("matA");					// read 1st matrix
	CMatrix m2("matB");					// read 2nd matrix
	
	assert(m1.width == m2.height);			// check compatibility
	assert(m2.width == m1.height);			// check compatibility
	
	CMatrix result(m1.height,m2.width);		// allocate memory
	
	
	// TODO multiply matrices
    cout << "someday i will multiply here; i'm rank " << MPI::COMM_WORLD.Get_rank() 
		<< " of " << MPI::COMM_WORLD.Get_size() << endl;
		
	MPI::Finalize();
	
	// print matrix
	result.print();
	
	return 0;
}

// EOF
