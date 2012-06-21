################################################################
## SIMPLE MAKEFILE TO BUILD WITH MPICH2                       ##
################################################################
# may-2012 - christoph@cdietzel.de                             #
################################################################

CXX	= mpic++
CFLAGS	= -O1
PROGS	= matmult
OBJS	= matmult.o CMatrix.o

PLATFORM=$(shell uname)
ifeq ($(PLATFORM), Darwin)
CFLAGS	+= -I/opt/local/include/
LDFLAGS += -L/opt/local/lib/ 
else
LDFLAGS += 
endif

all: $(OBJS)
	
	$(CXX) $(LDFLAGS) matmult.o CMatrix.o -o matmult 
	
%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(PROGS) *~ *.o ._*
