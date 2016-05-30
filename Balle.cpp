#include "Balle.h"
#include "Tir.h"
#include "Vector.h"
#include <Imagine/Graphics.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Imagine/Images.h>
using namespace Imagine;


//int w=10;
//int h=10;

//byte *ra;
//byte *ga;
//byte *ba;

//int im1=loadColorImage(srcPath("red.png"),ra,ga,ba, w,h);
const char* red = srcPath("red.jpg");

void Tracercadre(int largeur, int hauteur)
{
drawLine(Bordx, Bordy, Bordx, Bordy1, BLACK,3);
drawLine(Bordx, Bordy, Bordx1+20, Bordy, BLACK,3);
drawLine(Bordx1+20, Bordy, Bordx1+20, Bordy1, BLACK,3);
}

Grille CreationGrille (int l,int L, int r)
{
    Grille G;
    G.longueur = fin;
    G.largeur = fin;
    G.r = r;
    G.l = floor(G.longueur/(2*r));
    G.L = floor(G.largeur/(2*r));
    //G.K = new Balle [G.l*G.L];
    G.restant=(G.L-5)*G.l;
    
    return G;
}






Balle CreationBalle(int r, int c, int i, int j)
{
    Balle B;
    Image<Color> R;
    B.r = r;
    B.c = c;
    if (c==0) {
        B.col = Color(180,180,180);
        //B.coll =srcPath("Color(180,180,180).jpg");
    }
    if (c==1) {
        B.col = RED;
//        B.coll = srcPath("red.jpg");
//        load(R,B.coll);
        //B.Image = R;
        //putColorImage(B.position.x,B.position.y,ra,ga,ba,w,h);
        
    }
    if (c==2) {
        B.col = BLUE;
//        B.coll = srcPath("blue.jpg");
//        load(R,B.coll);
        //putColorImage(B.position.x,B.position.y,ra,ga,ba,w,h);
        //B.Image = B;
    }
    if (c==3) {
        B.col = GREEN;
//        B.coll = srcPath("green.jpg");
//        load(R,B.coll);
        //B.Image = R;
    }
    if (c==4)
    {
        B.col = YELLOW;
//        B.coll = srcPath("yellow.jpg");
//        load(R,B.coll);
        
    }
    
    if (c==5)
    {
        B.col = CYAN;
        //        B.coll = srcPath("yellow.jpg");
        //        load(R,B.coll);
        
    }
    if (c==6)
    {
        B.col = Color(130, 130, 200);
    }
    if (c==7)
    {
        B.col = Color(180,180,180);
    }


    
            
    //R = enlarge(R, 2*B.r, 2*B.r);
    //B.Image = R;
    B.position.x = Bordx + 2*(i+1)* B.r;
    B.position.y = Bordy + 2*(j+1)*B.r;
    
    return B;
}

Balle CreationBalleV(int r, int c, Vector postion, Vector vitesse)
{
    
        Balle B;
    Image<Color> R;
        B.r = r;
        B.c = c;
    if (c==0) {
        B.col = Color(180,180,180);
        //B.coll =srcPath("Color(180,180,180).jpg");
    }
    if (c==1) {
        B.col = RED;
//        B.coll = srcPath("red.jpg");
//        load(R,B.coll);
        //B.Image = R;
        //putColorImage(B.position.x,B.position.y,ra,ga,ba,w,h);
        
    }
    if (c==2) {
        B.col = BLUE;
//        B.coll = srcPath("blue.jpg");
//        load(R,B.coll);
        //putColorImage(B.position.x,B.position.y,ra,ga,ba,w,h);
        //B.Image = B;
    }
    if (c==3) {
        B.col = GREEN;
//        B.coll = srcPath("green.jpg");
//        load(R,B.coll);
        //B.Image = R;
    }
    if (c==4) {
        B.col = YELLOW;
//        B.coll = srcPath("yellow.jpg");
//        load(R,B.coll);

    }
    if (c==5)
    {
        B.col = CYAN;
        //        B.coll = srcPath("yellow.jpg");
        //        load(R,B.coll);
        
    }
    if (c==6)
    {
        B.col = Color(130, 130, 200);
    }
    //B.Image = R;
    //R = enlarge(R, 19/10*B.r, 19/10*B.r);
    B.position=postion;
    B.vitesse=vitesse;
        
        return B;
    
}


void SetBalle(Grille& G, int c, int i, int j)
{
    Balle B = CreationBalle( G.r, c, i, j);
    G.K[i + G.L *j] = B;
   if (j%2 == 0) {
    G.K[i + G.L *j].position.x = G.K[i + G.L *j].position.x+ G.K[i + G.L *j].r;
    }

    
}

void AfficheBalle( Balle B)
{
    fillCircle(B.position.x, B.position.y, B.r, B.col);
    //load(B.,B.coll);
    //display(enlarge(B.Image, 2*B.r, 2*B.r), B.position.x-B.r,B.position.y-B.r, false);
}

void AfficheBalleGrille( Grille& G, int i, int j)
{
    AfficheBalle(G.K[i + G.L *j]);
}
void Efface(Balle B) {
    fillCircle(B.position.x, B.position.y, B.r, Color(180,180,180));

//    Image<Color> W;
//    load(W,srcPath("Color(180,180,180).jpg"));
//    B.Image = W;
//    display(enlarge(B.Image, 2*B.r, 2*B.r), B.position.x-B.r,B.position.y-B.r, false);
}

void EffaceGrille(Grille& G, int i, int j){
    Efface(G.K[i+ G.L*j]);
    SetBalle(G, 0, i, j);
    
}

void EvoluePositionX(Balle &B, int dt) {
    B.position.x=B.position.x+B.vitesse.x*dt;
}
void EvoluePositionY(Balle &B, int dt)
{
    B.position.y=B.position.y+B.vitesse.y*dt;
}
void Remplirligne(Grille& G, int i,int c)
{
    for (int j=0; j<G.l; j++)
    {
        SetBalle(G, c, i, j);
    }
}

void InitRandom() {
    srand((unsigned int)time(0));
}

double Random(double a, double b) {
    double x = double(rand())/RAND_MAX;
    return a + (b-a)*x;
}

void RemplirLigneRand( Grille&G, int j)
{
    for (int i=0; i<G.l; i++)
    {
        G.K[i + G.L *j].c = Random(1,5);
        SetBalle(G, G.K[i + G.L *j].c, i, j);
    }
}



void AfficheLigne ( Grille& G, int j)
{
    for (int i=0; i<G.l ; i++)
    {
        AfficheBalleGrille ( G, i, j);
    }
}

void RemplirGrille( Grille&G)
{
    for (int i = 0; i<floor(G.L-5); i++)
    {
        RemplirLigneRand( G,i);
        AfficheLigne ( G, i);
    }
    for (int i = 0; i< G.l; i++)
    {
        SetBalle(G, 0, i, floor(G.L-5));
    }
    
}




void RemplirGrilleN1( Grille&G)
{
    for (int i = 0; i<floor(G.L); i++)
    {
        AfficheLigne ( G, i);
    }

    
}



// Niveau 2
void RemplirLigneRand2( Grille&G, int j)
{
    for (int i=0; i<G.l; i++)
    {
        G.K[i + G.L *j].c = Random(1,7);
        SetBalle(G, G.K[i + G.L *j].c, i, j);
    }
    for (int i = 0; i< G.l; i++)
    {
        SetBalle(G, 0, i, floor(G.L-5));
    }
}

void RemplirGrille2( Grille&G)
{
    for (int i = 0; i<floor(G.L-5); i++)
    {
        RemplirLigneRand2( G,i);
        AfficheLigne ( G, i);
    }
    
}

// Niveau 3
void RemplirLigneRand3( Grille&G, int j)
{

    for (int i=0; i<G.l; i++)
    {
        if ((i == 5 && j == 2)|| (i == 5 && j == 3) || (i == 6 && j == 3))
        {
            G.K[i + G.L *j].c = 7;
            SetBalle(G, G.K[i + G.L *j].c, i, j);
        }
        else
        {
            G.K[i + G.L *j].c = Random(1,7);
            SetBalle(G, G.K[i + G.L *j].c, i, j);
        }
    }
    
    for (int i = 0; i< G.l; i++)
    {
        SetBalle(G, 0, i, floor(G.L-5));
    }
}

void RemplirGrille3( Grille&G)
{

    for (int i = 0; i<floor(G.L-5); i++)
    {

        RemplirLigneRand3( G,i);
        AfficheLigne ( G, i);
        
    }
    
    for (int i = 0; i< G.l; i++)
    {
        SetBalle(G, 0, i, floor(G.L-5));
    }
    Image<Color> LIB;
    load(LIB, srcPath("lib.png"));
    display(LIB, 260, 92);
    AfficheBalle(G.K[4+G.L*2]);
    AfficheBalle(G.K[6+G.L*2]);
}

bool JeuTombe (Grille& G)
{
    if (G.K[4 + G.L *2].c ==0 && G.K[5 + G.L *2].c==0 && G.K[6 + G.L *2].c==0 && G.K[5 + G.L *3].c==0 && G.K[6 + G.L *3].c == 0)
    {

        return true;
    }
        else
        {
            return false;
        }
       

}

