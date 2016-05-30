
#include "Vector.h"
#include "Balle.h"
#include <Imagine/Graphics.h>


bool Bordhaut ( Balle B);

bool Collision(double x1, double y1, double vx1, double vy1,
               double x2, double y2, double vx2, double vy2, int r);
void Tir(Vector& milieu, Vector& positionTir, int x, int y,Grille& G, int& u, int& v, Balle& D,int& p);

void reconaissance(Grille&G, int u, int v, int& s);

void boum(int u, int v);

bool procheD(int i, int j, int val, Grille& G);

void cascade(int i, int j, int val,int& compteur, int& s, Grille& G);

bool bordgauche(Grille G, Balle B, int largeur);

bool borddroit(Grille G, Balle B, int largeur);

void rebond(Grille G, Balle& B, int largeur1, int largeur2, int dt);

bool Rienup (Grille G, int i, int j);

void Chute (Grille& G);

void cascade2(int i, int j, int val,int& compteur, Grille& G, int temp[13][13]  );
void CASCADE(int i, int j, int val,int& compteur, int& s, Grille& G,int temp[13][13]  );
void TableauB(Grille&G, int temp[13][13]  );

bool NonBlanc(Grille& G, int i, int j);
void Accroche(Grille& G, int largeur, int hauteur);
void fload(Grille& G, int G1[13][13], int temp [13][13], int i, int j, int& compteur);

bool Voisin(Balle B, Balle G);
void Move(Balle& D, Grille& G, int largeur, int hauteur);
void Accroche3(Grille& G);

void PlacerBalle(Grille& G, Balle D, int u, int v, int& h, int& q);