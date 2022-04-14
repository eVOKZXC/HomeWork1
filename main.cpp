#include <iostream>
#include "Complex.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <Windows.h>

int Foo1() {

	ComplexClass fNum, sNum;

	std::cout << "Введите коэффиценты для первого числа через пробел: ";
	double tempReCof, tempImCof;
	std::cin >> tempReCof >> tempImCof;
	fNum.sgetterRe(tempReCof);
	fNum.sgetterIm(tempImCof);

	std::cout << "Введите коэффиценты для второго числа через пробел: ";
	std::cin >> tempReCof >> tempImCof;
	sNum.sgetterRe(tempReCof);
	sNum.sgetterIm(tempImCof);

	std::cout << "Модуль первого числа: " << fNum.moduleCompl() << std::endl;
	std::cout << "Модуль второго числа: " << sNum.moduleCompl() << std::endl;

	sumOfCompl(fNum, sNum);
	multiplyOfCompl(fNum, sNum);
	divOfCompl(fNum, sNum);
	return 0;
}

int Foo2() {
	std::ifstream fin("complexMas.txt");
	int n = 0;
	char lineBuf[1024];
	std::string lineStr;
	if (!fin.is_open()) return -1;
	while (!fin.eof()) {
		fin.getline(lineBuf, 1024, '\n');
		n++;
	}

	fin.close();
	std::ifstream fin2("complexMas.txt");
	if (!fin2.is_open()) return -1;

	ComplexClass* p = new ComplexClass[n];
	int counter = 0;
	while (getline(fin2, lineStr)) {
		std::string reBuf, imBuf;
		double reI, imI;
		bool checker = false;
		for (int i = 0; i < lineStr.size(); ++i) {
			if (lineStr[lineStr.size() - 1] != 105) {
				reBuf += lineStr[i];
				continue;
			}
			if (lineStr[i] == 32) continue;
			if (i != 0 and (lineStr[i] == 43 or lineStr[i] == 45)) checker = true;
			if (checker == false) {
				reBuf += lineStr[i];
			}
			else {
				if (lineStr[i] == 43) continue;
				if (lineStr[i] == 105) break;
				imBuf += lineStr[i];
			}
		}

		if (reBuf.empty()) reI = 0;
		else reI = stod(reBuf);

		if (imBuf.empty()) imI = 0;
		else imI = stod(imBuf);

		p[counter].sgetterRe(reI);
		p[counter].sgetterIm(imI);
		counter++;
	}


	double maxModule = 0;
	for (int i = 0; i < n; ++i) if (p[i].moduleCompl() > maxModule) maxModule = p[i].moduleCompl();

	std::cout << "Максимальный модуль числа из файла: " << maxModule << std::endl;
	return 0;

}



int main()
{
	setlocale(LC_ALL, "rus");
	int count = 0;
	std::cout << "Выберите подраздел задания (1 или 2): ";
	std::cin >> count;
	count == 1 ? Foo1() : Foo2();

	return 0;
}