#include"Polynom.h"
int main()
{
	int d = 5;
	float* coef = new float[d];
	for (int i = 0; i < d; i++)
		coef[i] = i * 2;
	int d2 = 3;
	float* coef2 = new float[d2];
	for (int i = 0; i < d2; i++)
		coef2[i] = i + 2;
	Polynom<float> p1(d, coef);
	Polynom<float> p2(d2, coef2);
	Polynom<float> p3 = p2;
	std::cout << "1." << '\n';
	std::cout << p1 << '\n' << p2 << '\n' << p3 << '\n';
	p3 = p1;
	std::cout << '\n';
	std::cout << p1<< '\n' << p2 << '\n' << p3 << '\n';
	std::cout << "2." << '\n';
	p1.dif(p2);
	p1.sum(p2);
	std::cout << "3." << '\n';
	float x;
	std::cin >> x;
	p3.rez(x);
	std::cout << "4." << '\n';
	std::cout << p2 << '\n';
	p1.prod(p2);
	return 0;
}
