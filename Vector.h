#pragma once

struct Vector { // Vecteur du plan
	double x;
	double y;
};

Vector operator+(Vector a,Vector b);      // Somme de deux vecteurs
Vector operator-(Vector a,Vector b);      // Difference de deux vecteurs
double norme2(Vector a);                  // Norme euclidienne d'un vecteur
Vector operator*(Vector a,double lambda); // Multiplication par un scalaire
Vector operator*(double lambda,Vector a); // Multiplication par un scalaire
