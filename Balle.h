#pragma once

#include "Vector.h"

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>

using namespace Imagine;
const int largeur = 512;
const int hauteur = 512;
const int l = 128;
const int fin = largeur- 128;
const int Bordx = 100;
const int Bordy = 10;
const int Bordx1 = fin + Bordx;
const int Bordy1 = fin + Bordy;
const int milieuTirx =(Bordx)+(Bordx1-Bordx+20)/2;


typedef struct Balle {
	Vector vitesse;             // A enlever et mettre vitesse constante
	double r;
	Color col;
    int c;
    Vector position;
//    char* coll;
//    Image<Color> Image;

}Balle;

struct Grille{
    int longueur;
    int largeur;
    int l;
    int L;
    int r;
    int restant;
    Balle K[13*13];
    
};


Grille CreationGrille (int l,int L, int r);

Balle CreationBalle(int r, int c, int i, int j);

Balle CreationBalleV(int r, int c, Vector postion, Vector vitesse);

void SetBalle(Grille& G, int c, int i, int j);
void AfficheBalle ( Balle B);
void AfficheBalleGrille ( Grille& G, int i, int j);
void Remplirligne(Grille& G, int i, int c);

void InitRandom();
void RemplirLigneRand( Grille&G, int i);
void AfficheLigne ( Grille& G, int i);
double Random(double a, double b);
void RemplirGrille( Grille&G);
void RemplirGrilleN1( Grille&G);

void EvoluePositionX(Balle &B, int dt);
void EvoluePositionY(Balle &B, int dt);

void Efface(Balle B);
void EffaceGrille(Grille& G, int i, int j);

void Tracercadre(int largeur, int hauteur);

void RemplirLigneRand2( Grille&G, int j);
void RemplirGrille2( Grille&G);

// Niveau 3
void RemplirLigneRand3( Grille&G, int j);
void RemplirGrille3( Grille&G);
bool JeuTombe (Grille& G);