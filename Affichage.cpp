#include <Imagine/Graphics.h>
using namespace Imagine;
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std;
#include <sstream>
#include "Vector.h"
#include "Tir.h"
#include "Balle.h"
#include "Affichage.h"
#include <Imagine/Images.h>


void cadre()
{
    drawString(5 , 20, "SCORE", BLACK, 20);
    
    Image<Color> L;
    load(L , srcPath("RetourMenu.png"));
    display(L,largeur/100, 500-20);
    
    Image<Color> K;
    load(K, srcPath("Recommencer.png"));
    display(K,largeur*69/100, 500 - 20);
    
    
    drawString(5 , 90, "COUPS RESTANTS", BLACK, 10);
    drawString(5 , 160, "ACCOMPLI", BLACK, 10);
    
    
    drawString(5 , 230, "NIVEAU", BLACK, 20);
    
    
}


void effaceScore(){
    fillRect(10, 30, 75, 30 , BLACK);
}
void effaceNiveau(){
    fillRect(10, 240, 75, 30 , BLACK);
}


void effacePourcents(){
    fillRect(10, 170, 75, 30 , BLACK);
}

void effaceCoups(){
    fillRect(10, 100, 75, 30 , BLACK);
}
void afficheScore(int s){ // affiche le score
    effaceScore();
    
    ostringstream oss;
    oss << s;
    string result = oss.str();
    
    drawString(15, 50, result, RED, 20);
}

void afficheCoups(int s){ // affiche les coups restants
    effaceCoups();
    
    ostringstream oss;
    oss << s;
    string coups = oss.str();
    
    drawString(15, 120, coups, RED, 20);
}

void AffichePourcents(int s){ // affiche le pourcentage accompli, trouver comment diminuer les % selon le nombre de balles restantes
    effacePourcents();
    
    ostringstream oss;
    oss << s<<" %";
    string coups = oss.str();
    
    drawString(15, 190, coups, RED, 20);
}
void afficheNiveau(int n)
{ // affiche le niveau
    effaceNiveau();
    
    ostringstream oss;
    oss << n;
    string result = oss.str();
    
    drawString(15, 260, result, RED, 20);
}

void Finpartie (Grille& G, int x,int y)
{
    for (int i=0; i<G.l; i++)
    {
        for (int j = 0; j<floor(G.L); j++)
        {
            milliSleep(20);
            EffaceGrille(G, j, i);
        }
    }
    milliSleep(50);
    drawString(x, y, "PERDU", BLACK, 50);
}





void Niveausuivant (Grille& G, int x,int y)
{

    drawString(x, y, "GAGNE", BLACK, 50);
    milliSleep(200);
    click();
}




void homepage(int largeur, int hauteur)
{
    Background(largeur, hauteur);
    Image<Color> L;
    load(L, srcPath("BubbleWitch.png"));
    display(L,largeur/2-90, hauteur*1/4);
    //drawString(largeur/2 - 90, hauteur*1/4, "Bubble Witch", BLACK, 30);
    Image<Color> K;
    load(K, srcPath("bub.jpg"));

    display(K,largeur/2-90, hauteur *1/2-20);
    drawString(largeur/2-90, hauteur *1/2, " Commencer Jeu ", WHITE, 20);
    
    display(K,largeur/2-90, hauteur *1/2+140);
    drawString(largeur/2-90, hauteur *1/2 +160, " Quitter  Jeu", WHITE, 20);
    
//    display(K,largeur/2-90, hauteur *1/2 +20);
//    drawString(largeur/2-90, hauteur *1/2 + 40, " Commencer Jeu  2", WHITE, 20);

    display(K,largeur/2-90, hauteur *1/2+60);
    drawString(largeur/2-90, hauteur *1/2+80, " Règles du Jeu ", WHITE, 20);

    drawString(largeur*7/10, hauteur *1/2+240, " An Attia & Hayat Game© ", BLUE, 10);

}

void effacepage(int largeur, int hauteur)
{
    fillRect(0, 0, largeur, hauteur , WHITE);
}

void SuivanteB(Balle Ds, Vector Next)
{
    AfficheBalle(Ds);
    drawRect(Next.x-Ds.r, Next.y-Ds.r, 2*Ds.r, 2*Ds.r, BLACK);
    drawLine(Next.x-Ds.r, Next.y-Ds.r, Next.x+Ds.r, Next.y+Ds.r, BLACK);
    drawLine(Next.x+Ds.r, Next.y-Ds.r, Next.x-Ds.r, Next.y+Ds.r, BLACK);
    drawString(Next.x-7*Ds.r,  Next.y+ Ds.r/2, "SUIVANTE", BLACK, Ds.r);
}

bool Danscadre (int u, int v, int x1, int x2, int y1, int y2 )
{
    if ( x1<u and u<x2 and y1<v and v<y2)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

void RecommencerWindow (int largeur, int hauteur )
{
    effacepage(largeur, hauteur);
    Background(largeur, hauteur);

    Image<Color> J;
    load(J, srcPath("Surrecommencer.png"));
    display(J,largeur*1/4-20, hauteur*1/2 -180);
    
    
    Image<Color> K;
    load(K, srcPath("Non.png"));
    display(K,largeur*5/8, hauteur *1/2);
    

    Image<Color> L;
    load(L, srcPath("Oui.png"));
    display(L,largeur*1/8, hauteur *1/2);
}

void Choixniveau (int largeur, int hauteur)
{
    effacepage(largeur, hauteur);
    Background(largeur, hauteur);
    Image<Color> K;
    load(K, srcPath("bub.jpg"));
    
    Image<Color> L;
    load(L, srcPath("Choixduniveau.png"));
    display(L,largeur/2-120, hauteur *1/2-70);

    
    display(K,largeur/2-90, hauteur *1/2-20);
    drawString(largeur/2-90, hauteur *1/2, "          Niveau 1 ", WHITE, 20);
    
    display(K,largeur/2-90, hauteur *1/2 +20);
    drawString(largeur/2-90, hauteur *1/2 + 40, "          Niveau  2", WHITE, 20);
    
    display(K,largeur/2-90, hauteur *1/2 +60);
    drawString(largeur/2-90, hauteur *1/2 + 80, "          Niveau  3", WHITE, 20);
    
    
}

void Background (int largeur, int hauteur)
{
    fillRect(0,0,largeur, hauteur, Color(180,180,180));
    int r = largeur/50;
    
    for (int i = 0; i < 50; i ++)
        for (int j= 0; j < 50; j ++)
        {
            fillCircle(r+3+i*(2*r), (r+3)+j*(2*r), r, Color(Random(0, 255),Random(0, 255) , Random(0, 255)));
        }
  
}

void GamePage (int largeur, int hauteur )
{
    effacepage(largeur, hauteur);
    fillRect(0,0,largeur, hauteur, Color(180,180,180));
    
}

void Regle(int largeur, int hauteur )
{
    effacepage(largeur, hauteur);
    Image<Color> L;
    load(L, srcPath("Regles.png"));
    display(L);
    click();
}

