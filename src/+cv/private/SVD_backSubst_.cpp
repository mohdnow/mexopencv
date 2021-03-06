/**
 * @file SVD_backSubst_.cpp
 * @brief mex interface for SVD_backSubst_
 * @author Kota Yamaguchi
 * @date 2012
 */
#include "mexopencv.hpp"
using namespace std;
using namespace cv;

/**
 * Main entry called from Matlab
 * @param nlhs number of left-hand-side arguments
 * @param plhs pointers to mxArrays in the left-hand-side
 * @param nrhs number of right-hand-side arguments
 * @param prhs pointers to mxArrays in the right-hand-side
 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
	// Check the number of arguments
	if (nrhs!=4 || nlhs>1)
        mexErrMsgIdAndTxt("mexopencv:error","Wrong number of arguments");
    
	// Argument vector
	vector<MxArray> rhs(prhs,prhs+nrhs);
	SVD svd;
	svd.w = rhs[0].toMat();
	svd.u = rhs[1].toMat();
	svd.vt = rhs[2].toMat();
	Mat	src(rhs[3].toMat()), dst;
	svd.backSubst(src, dst);
	plhs[0] = MxArray(dst);
}
