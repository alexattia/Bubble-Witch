#include "Balle.h"
#include "Tir.h"
#include "Vector.h"
#include <Imagine/Graphics.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace Imagine;
#include <stdio.h>
#include <sstream>

void afficheScore(int s);
void effaceScore();
void cadre();
void afficheCoups(int s);
void effaceCoups();
void effacePourcents();
void AffichePourcents(int s);
void Finpartie (Grille& G, int x,int y);

void effacepage(int largeur, int hauteur);
void SuivanteB(Balle Ds, Vector Next);

bool Danscadre (int u, int v, int x1, int x2, int y1, int y2);

void RecommencerWindow (int largeur, int hauteur );

void Niveausuivant (Grille& G, int x,int y);
void GamePage (int largeur, int hauteur );
void Background (int largeur, int hauteur);
void homepage(int largeur, int hauteur);
void Choixniveau(int largeur, int hauteur);

void afficheNiveau(int n);
void Regle(int largeur, int hauteur );