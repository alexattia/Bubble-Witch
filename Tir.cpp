#include "Tir.h"
#include "Balle.h"
#include "Vector.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool Bordhaut ( Balle B)
{
    if (B.position.y < Bordy + 2*B.r)
    {
        return true;
    }
    else
    {
        return false;
    }
}



bool Coll2(Balle B, Balle G)
{   if (G.c !=0)
    {
    double n = norme2(B.position-G.position);
    return (n<=(B.r+G.r));
    }
    if (G.c ==0)
    {
        return false;
    }
} // renvoie true s'il y a contact entre B et G

bool Voisin(Balle B, Balle G)
{   if (G.c == 0)
{
    double n = norme2(B.position-G.position);
    return (n<=(B.r+G.r));
}
    if (G.c !=0)
    {
        return false;
    }
}

void boum(int u, int v)
{
    drawString(u , v+10, "BOUM ! ", BLACK, 10);
    milliSleep(700);
    fillRect(u, v, 45, 45 , WHITE);
    
}

bool borddroit(Grille G, Balle B)
{
    double xx= B.position.x+ B.r;
    if (xx > Bordx1+20)
    {return true;}
    else
    {return false;}
}



bool bordgauche(Grille G, Balle B)
{
    double xx= B.position.x+ B.r-35;
    if (xx < Bordx)
    {return true;}
    else
    {return false;}
    return(B.position.x==Bordx);
}

void rebond(Grille G, Balle& B, int& dt)
{
    bool bd=borddroit(G, B);
    bool bg=bordgauche(G, B);
    
    if (bd || bg)
    {
        dt=-dt;
    }
}

void Choc(double x,  double y,  double &vx,  double &vy,  double m,
          double x2, double y2, double &vx2, double &vy2, double m2)
{
    double vvx = (m * vx + m2 * vx2)/(m + m2);
    double vvy = (m * vy + m2 * vy2)/(m + m2);
    double deltax = x2 - x;
    double deltay = y2 - y;
    double norme = deltax * deltax + deltay * deltay;
    double scal = -2. * ((vx-vvx)*deltax + (vy-vvy)*deltay)/norme;
    vx += scal * deltax;
    vy += scal * deltay;
    scal = -2. * ((vx2-vvx)*deltax + (vy2-vvy)*deltay)/norme;
    vx2 += scal * deltax;
    vy2 += scal * deltay;
}

void ChocSimple(double x,  double y,  double &vx, double &vy, double m,
                double x2, double y2, double vx2, double vy2)
{
    Choc(x,y,vx,vy,m,x2,y2,vx2,vy2,1000*m);
}

void PlacerBalle(Grille& G, Balle D, int u, int v, int& h, int& q)
{
    if (u!=0 && u != G.l)
    {
        for (int i=u-1;i<u+2;i++)
        {
            if (v!=0 && v!= G.L)
            {
                
                for (int j=v-1;j<v+2;j++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
        }
    }
    if (u==0)
    {
        for (int i=u;i<u+2;i++)
        {
            if (v!=0 && v!= G.L)
            {
          
                for (int j=v-1;j<v+2;j++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            if (v ==0)
            {
                
                for (int j=v;j<v+2;j++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            
            if (v == G.L)
            {
                
                for (int j=v-1;j<v+1;j++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            

        }
    }
  
    
    if (u==G.L)
    {
        for (int i=u-1;i<u+1;i++)
        {
            if (v!=0 && v!= G.L)
            {
                
                for (int j=v-1;j<v+2;j++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            if (v ==0)
            {
                
                for (int j=v;j<v+2;j++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            
            if (v == G.L)
            {
                
                for (int j=v-1;j<v;j++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            
            
        }
    }

    
    if (v==0)
    {
        for (int j=v;j<v+2;j++)
        {
            if (u!=0 && u!= G.L)
            {
                
                for (int i=v-1;i<v+2;i++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2+ G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            if (u ==0)
            {
                
                for (int i=v;i<v+2;i++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            
            if (u == G.L)
            {
                
                for (int i=u-1;i<u+1;i++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            
            
        }
    }
    
    
    if (v==G.L)
    {
        for (int j=v-1;j<v+1;j++)
        {
            if (u!=0 && u!= G.L)
            {
                
                for (int i=u-1;i<u+2;i++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            if (u ==0)
            {
                
                for (int i=u;i<u+2;i++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            
            if (u == G.L)
            {
                
                for (int i=u-1;i<u+1;i++)
                {
                    bool voisin = Voisin( D, G.K[i- j%2 + G.L*j] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        h = i;
                        q = j;
                    }
                }
            }
            
            
        }
    }

    
    
}

void Tir(Vector& milieu, Vector& positionTir, int x, int y,Grille& G, int& u, int& v, Balle& D, int& p)
{
drawArrow(milieu.x,milieu.y,x,y,BLACK);
milliSleep(500);
drawArrow(milieu.x,milieu.y,x,y,Color(180,180,180));
    /****************** INITIALISATION *******************/
    int a = norme2(positionTir-milieu);
    Vector vitesse1={2*(positionTir.x-milieu.x)/a,2*(positionTir.y-milieu.y)/a};
    D.vitesse= vitesse1;
    //Balle D=CreationBalleV(G.r, Random(1,5), milieu, vitesse1);
    Balle OD=D;
    int dtX = 4;
    int dtY = 4;
    //****** Boucle principale ******
    bool avance= true;
    G.restant ++;
    bool bordhaut = Bordhaut(D);
    
    while (avance)
    {
        
        noRefreshBegin();
        Efface(OD);
        AfficheBalle(D);
        OD=D;
        noRefreshEnd();
        milliSleep(20);

        rebond(G, D, dtX);
        EvoluePositionX(D, dtX);
        EvoluePositionY(D, dtY);
        bordhaut = Bordhaut(D);
        
        Tracercadre(largeur, hauteur);
        //cout<<D.position.x<<endl;
        
        
        for (int i=0;i<G.L;i++)
        {
            for (int j=0;j<G.l;j++)
                {
                   
                    bool aiJeCollisé= Coll2( D, G.K[i + G.L*j] ); // true s'il y a collision
                    if(aiJeCollisé)
                    {
                        avance= false; // le while s'arrete vu qu'il y a collision
                        u=i;
                        v=j;
                    }
                   
                }
        }
        if (bordhaut == true)
        {
            avance = false;
        }
    }
    int h,q;
    if (bordhaut==true)
    {
        h= 0;
        for (int i=0;i<G.L;i++)
        {

                {
                    bool voisin = Voisin( D, G.K[i] ); // true s'il y a collision
                    if(voisin==true)
                    {
                        q = i;
                    }
                }
        }

        
    }

    if (bordhaut == false)
    {
    PlacerBalle(G, D, u, v, h, q);
    }
    
    cout << h <<" "<<q<<endl;
    int colorD=D.c;
    Efface(D);
    Efface(OD);
    p=p-1;

    SetBalle(G, colorD, h, q);
    if (bordhaut==true)
    {
        AfficheLigne(G, 0);
    }
    else
    {
    AfficheLigne(G, v);
    AfficheLigne(G, v+1);
    }
    u = h;
    v = q;
}

void reconaissance(Grille&G, int u, int v, int& s)
{
    if( G.K[u + G.L*(v+1)].c==G.K[u + G.L*v].c)
    {
        if( G.K[u + G.L*v].c==G.K[u + G.L*(v-1)].c)
        {
            EffaceGrille(G, u ,v);
            EffaceGrille(G, u ,v+1);
            EffaceGrille(G, u ,v-1);
            AfficheLigne(G, v);
            AfficheLigne(G, v-1);
            AfficheLigne(G, v+1);
            s=s+300;
            boum(milieuTirx-30,Bordy1+ 15);
        }
        
    }
    if(G.K[u + G.L*(v+1)].c==G.K[u-1 + G.L*v].c)
    {
        if( G.K[u-1 + G.L*v].c==G.K[u-1 + G.L*(v-1)].c)
        {
            EffaceGrille(G, u-1 ,v);
            EffaceGrille(G, u ,v+1);
            EffaceGrille(G, u-1 ,v-1);
            AfficheLigne(G, v);
            AfficheLigne(G, v-1);
            AfficheLigne(G, v+1);
            AfficheLigne(G, v);
            s=s+300;
            boum(milieuTirx-30,Bordy1+ 15);
        }
    }
}

//bool Rienup (Grille G, int i, int j)
//{
//    if (G.K[i + G.L*(j-1)].c==0 && G.K[i-1 + G.L*(j-1)].c==0 && G.K[i+1 + G.L*(j-1)].c==0 && G.K[i-1 + G.L*(j)].c==0 && G.K[i+1 + G.L*(j)].c==0)
//    {
//        return true;
//    }
//    else
//    {
//        return false ;
//    }
//        
//}
//
//void Chute (Grille& G)
//{
//    for (int i = 1; i<G.L-1; i++)
//    {
//        for(int j =1; j<G.l-1; j++)
//        {
//            bool OK = Rienup (G, i, j);
//            if( OK == true)
//            {
//                
//                G.K[i + G.L*j].c = 0;
//                EffaceGrille(G, i, j);
//            }
//        }
//    }
//}


bool procheD(int i, int j, int val, Grille& G)
{
    if( G.K[i + G.L*j].c == val)
    {
        return true;
    }
    if( G.K[i + G.L*j].c != val)
    {
        return false;
    }
}

void cascade(int i, int j, int val,int& compteur, int& s, Grille& G)
{
    bool col = procheD(i, j, val, G);

    if (col && i>-1 && j>-1 && i < G.L && j<G.l)
    {
        //temp[compteur] = i + G.L*j;
        compteur ++;
        s=s+4*compteur;

        EffaceGrille(G, i, j);

        

    }
    else
    {
    return;
    }
    int k = (i)%2;
    cout << k << endl;
    
    cascade(i-1, j, val, compteur,s, G);
    cascade(i+1, j, val, compteur,s, G);
    
    
    cascade(i- j%2, j-1, val, compteur,s, G);
    cascade(i + 1 - j%2, j-1, val, compteur,s, G);
    cascade(i- j%2, j+1, val, compteur,s, G);
    cascade(i + 1 - j%2, j+1, val, compteur,s, G);


}

void TableauB(Grille& G, int temp[13][13]  )
{
    for( int i=0; i< G.L; i++)
        for (int j= 0; j<G.l; j++)
        {
            temp[i][j] = 0;
        }
}

void cascade2(int i, int j, int val,int& compteur, Grille& G, int temp[13][13]  )
{
    bool col = procheD(i, j, val, G);
    if (col && i>-1 && j>-1 && i < G.L && j<G.l && temp[i][j] == 0 )
    {
        temp[i][j] = 1;
        compteur ++;
        cout << compteur << endl;

    }
    else
    {

                return;
    }
    
    cascade2(i-1, j, val, compteur, G, temp );
    cascade2(i+1, j, val, compteur, G, temp );

    
    cascade2(i- j%2, j-1, val, compteur, G, temp );
    cascade2(i + 1 - j%2, j-1, val, compteur, G, temp );
    cascade2(i- j%2, j+1, val, compteur, G, temp );
    cascade2(i + 1 - j%2, j+1, val, compteur, G, temp);
}

void CASCADE(int i, int j, int val,int& compteur, int& s, Grille& G,int temp[13][13]  )
{
    TableauB(G, temp  );
    cascade2(i, j, val, compteur, G, temp );
    if (compteur > 2)
    {
            cascade(i, j, val, compteur,s, G);
        
    }
    
    G.restant= G.restant-compteur;
    compteur = 0;
}

bool NonBlanc(Grille& G, int i, int j)
{
    
    if( G.K[i + G.L*j].c != 0)
    {
        return true;
    }
    if( G.K[i + G.L*j].c == 0l)
    {
        return false;
    }

}

void Accroche(Grille& G, int largeur, int hauteur)
{
    int temp[13][13];
    int G1[13][13];
    TableauB(G, temp );
    TableauB(G, G1);
    int compteur = 0;
    milliSleep(500);
    for (int i =0; i< G.L; i++)
    {
    bool NB = NonBlanc(G,i,0);
        if(NB == true)
        {
        fload(G, G1, temp, i, 0, compteur);
        }
    }
    for (int i =0; i< G.L; i++)
        for (int j =0; j< G.l; j++)
    {
        if(G1[i][j]==0 && not(G .K[i+G.L*j].c ==0))
        {
            //Balle D =G .K[i+G.L*j];
            EffaceGrille(G, i, j);
            //Move(D, G, largeur, hauteur);

        }
    }
    G.restant = compteur;

}
void Accroche3(Grille& G)
{
    int temp[13][13];
    int G1[13][13];
    TableauB(G, temp );
    TableauB(G, G1);
    int compteur = 0;
    milliSleep(500);
    for (int i =0; i< G.L; i++)
    {
        bool NB = NonBlanc(G,i,0);
        if(NB == true)
        {
            fload(G, G1, temp, i, 0, compteur);
        }
    }
    for (int i =0; i< G.L; i++)
        for (int j =0; j< G.l; j++)
        {
            if(G1[i][j]==0)
            {
                EffaceGrille(G, i, j);
            }
        }
    G.restant = compteur;
    
    RemplirGrilleN1(G);
    Image<Color> LIB;
    load(LIB, srcPath("lib.png"));
    display(LIB, 260, 92);
    AfficheBalle(G.K[4+G.L*2]);
    AfficheBalle(G.K[6+G.L*2]);
}

void fload(Grille& G, int G1[13][13], int temp [13][13], int i, int j, int& compteur)
{
    bool NB = NonBlanc(G,i,j);
    if (NB && i>-1 && j>-1 && i < G.L && j<G.l && temp[i][j] == 0 )
    {
        temp[i][j] = 1;
        G1[i][j]= G.K[i + G.L*j].c;
        compteur ++;
        //G.B[i + G.L*j] = 1;
        //s=s+4*compteur;
        //cout << temp[compteur]<< endl;
        //cout << i << " " << j << " "<<compteur <<  endl;
        //EffaceGrille(G, i, j);
        //G.restant --;
    }
    else
    {
        
        return;
    }

    fload(G, G1, temp,i-1, j, compteur);
    fload(G, G1, temp, i+1, j, compteur);
    fload(G, G1, temp,i + 1 - j%2, j+1, compteur);
    fload(G, G1, temp,i- j%2, j+1, compteur);

}

void Move(Balle& D, Grille& G, int largeur, int hauteur)
{
    //milliSleep(500);
    Balle OD;
    /****************** INITIALISATION *******************/
    
    Vector vitesse1={0,10};
    D.vitesse= vitesse1;
    //Balle D=CreationBalleV(G.r, Random(1,5), milieu, vitesse1);
    OD=D;
    int dtX = 1;
    int dtY = 1;
    //****** Boucle principale ******
    int avance = 5;

    while (avance>1)
    {
        
        noRefreshBegin();
        milliSleep(20);
        Efface(OD);
        AfficheBalle(D);
        OD=D;
        noRefreshEnd();

        
        rebond(G, D, dtX);
        EvoluePositionX(D, dtX);
        EvoluePositionY(D, dtY);
        
        Tracercadre(largeur, hauteur);
                Efface(D);
        //fillRect(103, 14, 512-128, 512-128, Color(180,180,180));

        RemplirGrilleN1(G);
        avance --;
        
    }
}
