#ifndef Complex
#define Complex

#include <iostream>
#include <cmath>
#include <fstream>

class ComplexClass {

	double re;
	double im;

public:
	ComplexClass() {
		re = 0;
		im = 0;
	}

	double sgetterRe() { return re; }
	void sgetterRe(double re) { this->re = re; }

	double sgetterIm() { return re; }
	void sgetterIm(double im) { this->im = im; }

	double moduleCompl() {
		return sqrt(pow(re, 2) + pow(im, 2));
	}

};


void sumOfCompl(ComplexClass fNum, ComplexClass sNum);
void multiplyOfCompl(ComplexClass fNum, ComplexClass sNum);
void divOfCompl(ComplexClass fNum, ComplexClass sNum);


#endif Complex
