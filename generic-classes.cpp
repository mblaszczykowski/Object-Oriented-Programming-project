#include <iostream>

using namespace std;

template<typename T1>

class Max {
	T1 liczba1;
	T1 liczba2;
public:
	Max(T1 liczba1, T1 liczba2) {
		this->liczba1 = liczba1;
		this->liczba2 = liczba2;
	}

	T1 printMax() {
		if (liczba1>liczba2) {
			return liczba1;
		}
		else return liczba2;
	}
};

template<typename T2>
class Min {
	T2 liczba1;
	T2 liczba2;
public:
	Min(T2 liczba1, T2 liczba2) {
		this->liczba1 = liczba1;
		this->liczba2 = liczba2;
	}

	T2 printMin() {
		if (liczba1<liczba2) {
			return liczba1;
		}
		else return liczba2;
	}
};

template<typename T3>
class Multiplication {
	T3 liczba1;
	T3 liczba2;
public:
	Multiplication(T3 liczba1, T3 liczba2) {
		this->liczba1 = liczba1;
		this->liczba2 = liczba2;
	}

	T3 printAnswer() {
		return liczba1*liczba2;
	}
};

template<typename T4>
class Division {
	T4 liczba1;
	T4 liczba2;
public:
	Division(T4 liczba1, T4 liczba2) {
		this->liczba1 = liczba1;
		this->liczba2 = liczba2;
	}

	T4 printAnswer() {
		return liczba1/liczba2;
	}
};

template<typename T5>
class Square {
	T5 liczba1;
	T5 liczba2;
public:
	Square(T5 liczba1, T5 liczba2) {
		this->liczba1 = liczba1;
		this->liczba2 = liczba2;
	}

	T5 printAnswer() {
		for (int i = 1; i<liczba2-1; i++) {
			liczba1 *= liczba1;
		}
		return liczba1;
	}
};


int main() {
	cout << "Ilustracja pierwszej klasy generycznej Max" << endl;

	Max<int> *intMax = new Max<int>(10,15);
	cout << intMax->printMax() << endl;
	Max<float> *floatMax = new Max<float>(3.1,1.4);
	cout << floatMax->printMax() << endl << endl;


	cout << "Ilustracja drugiej klasy generycznej Min" << endl;

	Min<int> *intMin = new Min<int>(10,15);
	cout << intMin->printMin() << endl;
	Min<float> *floatMin = new Min<float>(3.1,1.4);
	cout << floatMin->printMin() << endl << endl;


	cout << "Ilustracja trzeciej klasy generycznej Multiplication" << endl;

	Multiplication<int> *intMultiplication = new Multiplication<int>(10,15);
	cout << intMultiplication->printAnswer() << endl;
	Multiplication<float> *floatMultiplication = new Multiplication<float>(3.1,1.4);
	cout << floatMultiplication->printAnswer() << endl << endl;


	cout << "Ilustracja czwartej klasy generycznej Division" << endl;

	Division<int> *intDivision = new Division<int>(30,15);
	cout << intDivision->printAnswer() << endl;
	Division<float> *floatDivision = new Division<float>(3.1,1.4);
	cout << floatDivision->printAnswer() << endl << endl;


	cout << "Ilustracja piatej klasy generycznej Square" << endl;

	Square<int> *intSquare = new Square<int>(2,4);
	cout << intSquare->printAnswer() << endl;
	Square<float> *floatSquare = new Square<float>(2.5,3);
	cout << floatSquare->printAnswer() << endl << endl;

	return 0;
}