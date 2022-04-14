#include "Complex.h"

char signFoo(double imCof, double reCof) {
	char sign;
	imCof < 0 ? sign = '-' : sign = '+';
	return sign;
}

void sumOfCompl(ComplexClass fNum, ComplexClass sNum) {
	double reCof = fNum.sgetterRe() + sNum.sgetterRe();
	double imCof = fNum.sgetterIm() + sNum.sgetterIm();

	if (imCof == 0) std::cout << "�����: " << reCof << std::endl;
	if (reCof == 0) std::cout << "�����: " << imCof << 'i' << std::endl;
	if (imCof != 0 and reCof != 0) std::cout << "�����: " << reCof << signFoo(imCof, reCof) << abs(imCof) << "i\n";
}

void multiplyOfCompl(ComplexClass fNum, ComplexClass sNum) {
	double reCof = fNum.sgetterRe() * sNum.sgetterRe() - fNum.sgetterIm() * sNum.sgetterIm();
	double imCof = fNum.sgetterRe() * sNum.sgetterIm() + sNum.sgetterRe() * fNum.sgetterIm();

	if (imCof == 0) std::cout << "������������: " << reCof << std::endl;
	if (reCof == 0) std::cout << "������������: " << imCof << 'i' << std::endl;
	if (imCof != 0 and reCof != 0) std::cout << "������������: " << reCof << signFoo(imCof, reCof) << abs(imCof) << "i\n";

}

void divOfCompl(ComplexClass fNum, ComplexClass sNum) {
	double reCof = (fNum.sgetterRe() * sNum.sgetterRe() + fNum.sgetterIm() * sNum.sgetterIm()) / (pow(sNum.sgetterRe(), 2) + pow(sNum.sgetterIm(), 2));
	double imCof = (sNum.sgetterRe() * fNum.sgetterIm() - fNum.sgetterRe() * sNum.sgetterIm()) / (pow(sNum.sgetterRe(), 2) + pow(sNum.sgetterIm(), 2));

	if (imCof == 0) std::cout << "�������: " << reCof << std::endl;
	if (reCof == 0) std::cout << "�������: " << imCof << 'i' << std::endl;
	if (imCof != 0 and reCof != 0) std::cout << "�������: " << reCof << signFoo(imCof, reCof) << abs(imCof) << "i\n";

}