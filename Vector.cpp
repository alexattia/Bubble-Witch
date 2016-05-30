#include "Vector.h"

#include <cmath>
using namespace std;

// Somme de deux vecteurs
Vector operator+(Vector a,Vector b) {
	Vector v={a.x+b.x,a.y+b.y};
	return v;
}

// Différence de deux vecteurs
Vector operator-(Vector a,Vector b) {
	Vector v={a.x-b.x,a.y-b.y};
	return v;
}

// Norme euclidienne d'un vecteur
double norme2(Vector a) {
	return sqrt(a.x*a.x+a.y*a.y);
}

// Multiplication d'un vecteur par un scalaire
Vector operator*(Vector a,double lambda) {
	Vector v={lambda*a.x,lambda*a.y};
	return v;
}

// Multiplication d'un vecteur par un scalaire
Vector operator*(double lambda,Vector a) {
	return a*lambda;
}
