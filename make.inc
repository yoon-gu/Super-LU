############################################################################
#
#  Program:         SuperLU
#
#  Module:          make.inc
#
#  Purpose:         Top-level Definitions
#
#  Creation date:   May 10, 2015
#
#  Modified:	    
#		    
#
############################################################################
#
# ToDo: Make this work for shared libraries and out-of-source builds.  Right
# now it only works for builds under /Users/j4c06/repos/SuperLU/
#
#  The name of the libraries to be created/linked to
#
SuperLUroot	= $(ROOT)
SUPERLULIB   	= $(SuperLUroot)/SRC/libsuperlu.a

TMGLIB       	= libtmglib.a

# BLASDEF 	= -DUSE_VENDOR_BLAS
BLASLIB		= $(SuperLUroot)/CBLAS/libblas.a
LIBS		= $(SUPERLULIB) $(SuperLUroot)/CBLAS/libblas.a

#
#  The archiver and the flag(s) to use when building archive (library)
#  If your system has no ranlib, set RANLIB = echo.
#
ARCH         = /usr/bin/ar
ARCHFLAGS    = cr
RANLIB       = /usr/bin/ranlib

CC           = /usr/bin/cc
CFLAGS 	     = -O3 -DNDEBUG -DPRNTlevel=0 -DAdd_  
NOOPTS       = -O0
FORTRAN	     = /usr/bin/gfortran

LOADER       = $(CC)
LOADOPTS     =

#
# The directory in which Matlab is installed
#
MATLAB	     = /Applications/MATLAB_R2015b.app
