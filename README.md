[![Build Status](https://travis-ci.org/yoon-gu/SuperLU.svg?branch=master)](https://travis-ci.org/yoon-gu/SuperLU)

SuperLU (Version 5.2.x)
=======================

SuperLU contains a set of subroutines to solve a sparse linear system 
A*X=B. It uses Gaussian elimination with partial pivoting (GEPP). 
The columns of A may be preordered before factorization; the 
preordering for sparsity is completely separate from the factorization.

SuperLU is implemented in ANSI C, and must be compiled with standard 
ANSI C compilers. It provides functionality for both real and complex
matrices, in both single and double precision. The file names for the 
single-precision real version start with letter "s" (such as sgstrf.c);
the file names for the double-precision real version start with letter "d"
(such as dgstrf.c); the file names for the single-precision complex
version start with letter "c" (such as cgstrf.c); the file names
for the double-precision complex version start with letter "z" 
(such as zgstrf.c).


SuperLU contains the following directory structure:

    SuperLU/README    instructions on installation
    SuperLU/CBLAS/    needed BLAS routines in C, not necessarily fast
    SuperLU/DOC/      Users' Guide and documentation of source code
    SuperLU/EXAMPLE/  example programs
    SuperLU/FORTRAN/  Fortran interface
    SuperLU/INSTALL/  test machine dependent parameters; the Users' Guide.
    SuperLU/MAKE_INC/ sample machine-specific make.inc files
    SuperLU/MATLAB/   Matlab mex-file interface
    SuperLU/SRC/      C source code, to be compiled into the superlu.a library
    SuperLU/TESTING/  driver routines to test correctness
    SuperLU/Makefile  top level Makefile that does installation and testing
    SuperLU/make.inc  compiler, compile flags, library definitions and C
                      preprocessor definitions, included in all Makefiles.
                      (You may need to edit it to be suitable for your system
                       before compiling the whole package.)

There are two ways to install the package. One uses CMake build system,
the other requires users to edit makefile manually.  The procedures
are described below.

1. Manual installation with makefile.      
   Before installing the package, please examine the three things dependent 
   on your system setup:

   1.1 Edit the make.inc include file.
       This make include file is referenced inside each of the Makefiles
       in the various subdirectories. As a result, there is no need to 
       edit the Makefiles in the subdirectories. All information that is
       machine specific has been defined in this include file. 

       Example machine-specific make.inc include files are provided 
       in the MAKE_INC/ directory for several systems, such as Linux,
       MacX, Cray, IBM, SunOS 5.x (Solaris), and HP-PA. 
       When you have selected the machine to which you wish 
       to install SuperLU, copy the appropriate sample include file (if one 
       is present) into make.inc. For example, if you wish to run 
       SuperLU on an linux, you can do

       	       cp MAKE_INC/make.linux make.inc
   
	For the systems other than listed above, slight modifications to the 
   	make.inc file will need to be made.
   
   1.2. The BLAS library.
       	If there is BLAS library available on your machine, you may define
       	the following in the file SuperLU/make.inc:
            BLASDEF = -DUSE_VENDOR_BLAS
            BLASLIB = <BLAS library you wish to link with>

   	The CBLAS/ subdirectory contains the part of the C BLAS needed by 
   	SuperLU package. However, these codes are intended for use only if 
	there is no faster implementation of the BLAS already available 
	on your machine. In this case, you should do the following:

    	1) In SuperLU/make.inc, undefine (comment out) BLASDEF, and define:
              BLASLIB = ../lib/blas$(PLAT).a

    	2) Go to the SuperLU/ directory, type:
              make blaslib
       	   to make the BLAS library from the routines in the	
	   CBLAS/ subdirectory.

   1.3. C preprocessor definition CDEFS.
   	In the header file SRC/slu_Cnames.h, we use macros to determine how
   	C routines should be named so that they are callable by Fortran.
   	(Some vendor-supplied BLAS libraries do not have C interface. So the 
    	re-naming is needed in order for the SuperLU BLAS calls (in C) to 
    	interface with the Fortran-style BLAS.)
   	The possible options for CDEFS are:

       	o -DAdd_: Fortran expects a C routine to have an underscore
		 postfixed to the name;
        o -DNoChange: Fortran expects a C routine name to be identical to
		     that compiled by C;
        o -DUpCase: Fortran expects a C routine name to be all uppercase.
   
   1.4. The Matlab MEX-file interface.
   	The MATLAB/ subdirectory includes Matlab C MEX-files, so that 
   	our factor and solve routines can be called as alternatives to those
    	built into Matlab. In the file SuperLU/make.inc, define MATLAB to be
	the directory in which Matlab is installed on your system, for example:

       	MATLAB = /usr/local/matlab

   	At the SuperLU/ directory, type "make matlabmex" to build the MEX-file
   	interface. After you have built the interface, you may go to the
	MATLAB/ directory to test the correctness by typing (in Matlab):
       		trysuperlu
       		trylusolve

   A Makefile is provided in each subdirectory. The installation can be done
   completely automatically by simply typing "make" at the top level.
   The test results are in the files below:
       INSTALL/install.out
       TESTING/stest.out   # single precision, real   
       TESTING/dtest.out   # double precision, real   
       TESTING/ctest.out   # single precision, complex
       TESTING/ztest.out   # double precision, complex


2. Using CMake build system. 
   You will need to create a build tree from which to invoke CMake.

   From the top level directory, do:
     	mkdir build ; cd build
   	cmake ..

     or with more options, e.g.,
        cmake .. \
	      -DCMAKE_INSTALL_INCLUDEDIR=/my/custom/path 	 

   To actually build, type:
   	make

   To run the installation test, type:
   	make test (or: ctest)

   	The test results are in the files below:
       	    build/TESTING/s_test.out   # single precision, real
       	    build/TESTING/d_test.out   # double precision, real
       	    build/TESTING/c_test.out   # single precision, complex
       	    build/TESTING/z_test.out   # double precision, complex

   To install the library, type:
        make install


--------------------
| RELEASE VERSIONS |
--------------------
    February 4,  1997  Version 1.0
    November 15, 1997  Version 1.1
    September 1, 1999  Version 2.0
    October 15,  2003  Version 3.0
    August 1,    2008  Version 3.1
    June 30,     2009  Version 4.0
    November 23, 2010  Version 4.1
    August 25,   2011  Version 4.2
    October 27,  2011  Version 4.3
    July 26,     2015  Version 5.0
    December 3,  2015  Version 5.1
    April 8,     2016  Version 5.2.0
