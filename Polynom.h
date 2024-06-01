#pragma once
#include <iostream>
#include<math.h>
template<typename T>
class Polynom {
public:
	Polynom(int degree, float* coeff) : degree(degree), coeff(coeff) {}
	Polynom() : degree(0), coeff(0) {}
	friend std::ostream& operator<<(std::ostream& output, Polynom p) {
        int n = p.degree;
        while (p.degree) {
            if (p.degree != 1 && p.degree == n) {
                output << p.coeff[p.degree - 1] << "x^" << p.degree;
            }
            else {
                if (p.degree != 1 && p.degree != n) {
                    if (p.coeff[p.degree - 1] > 0) {
                        output << '+' << p.coeff[p.degree - 1] << "x^" << p.degree;
                    }
                    else {
                        if(p.coeff[p.degree - 1] < 0){
                            output << p.coeff[p.degree - 1] << "x^" << p.degree;
                        }
                    }

                }
            }
            if (p.degree == 1 && p.degree != n) {
                if (p.coeff[p.degree - 1] > 0) {
                    output << '+' << p.coeff[p.degree - 1] << "x";
                }
                else{
                    if (p.coeff[p.degree - 1] < 0) {
                        output << p.coeff[p.degree - 1] << "x";
                    }
                }
            }
            if (p.degree == 0 && p.degree != n) {
                if (p.coeff[p.degree - 1] > 0) {
                    output << '+' << p.coeff[p.degree - 1];
                }
                else {
                    if (p.coeff[p.degree - 1] < 0) {
                        output << p.coeff[p.degree - 1];
                    }
                }
            }
            p.degree--;
        }
        return output;
	}
	int getdegree() {
		return degree;
	}
	void setdegree() {
		std::cin >> degree;
	}
	float* getcoeff() {
		return coeff;
	}
	void setcoeff() {
		std::cin >> *coeff;
	}
	void sum(const Polynom<T> &p) {
		Polynom p1;
		if (degree < p.degree) {
			p1.degree = p.degree;
			p1.coeff = new T[p1.degree];
			for (int i = 0; i < degree; i++) {
				p1.coeff[i] =p.coeff[i] + coeff[i];
			}
			for (int i = degree; i < p.degree; i++) {
				p1.coeff[i] = p.coeff[i];
			}
		}
		else {
			p1.degree = degree;
			p1.coeff = new T[p1.degree];
			for (int i = 0; i < p.degree; i++) {
				p1.coeff[i] =coeff[i] + p.coeff[i];
			}
			for (int i = p.degree; i < degree; i++) {
				p1.coeff[i] = coeff[i];
			}
		}
		std::cout << p1 << '\n';
	}
	void dif(const Polynom<T> &p) {
		Polynom<T> p1;
		if (degree < p.degree) {
			p1.degree = p.degree;
			p1.coeff = new T[p1.degree];
			for (int i = 0; i < degree; i++) {
				p1.coeff[i] =p.coeff[i] - coeff[i];
			}
			for (int i = degree; i < p.degree; i++) {
				p1.coeff[i] = p.coeff[i];
			}
		}
		else {
			p1.degree = degree;
			p1.coeff = new T[p1.degree];
			for (int i = 0; i < p.degree; i++) {
				p1.coeff[i] =coeff[i] - p.coeff[i];
			}
			for (int i = p.degree; i < degree; i++) {
				p1.coeff[i] = coeff[i];
			}
		}
		std::cout << p1 << '\n';
	}
	void rez(float x) {
		float s = 0;
		for (int i = 0; i < degree; i++) {
			s += coeff[i] * pow(x, i + 1);
		}
		std::cout << s << '\n';
	}
	void prod(const Polynom<T> &p) {
		Polynom<T> p1;
		p1.degree = degree + p.degree;
		p1.coeff = new T[p1.degree]();
		for (int i = 0; i < degree; i++) {
			for (int j = 0; j < p.degree; j++) {
				p1.coeff[i + j+1] =p1.coeff[i+j+1] + coeff[i] * p.coeff[j];
			}
		}
		std::cout << p1<<'\n';
	}
private:
	int degree;
	T* coeff;
};