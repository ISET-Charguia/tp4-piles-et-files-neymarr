#include <stdio.h>
#include <stdlib.h>
//Type Pile
typedef struct cellule
{
    int valeur;
    struct cellule *suivant;
} Cellule;
typedef Cellule * Pile;

Pile creerPile();
int estVide(Pile p);
void empiler(Pile *p, int x);
void depiler(Pile *p);
int sommet(Pile p);
void afficher(Pile p);
int egalite(Pile p1 , Pile p2);
Pile decouper(Pile p, int n);

int main()
{
    Pile maPile;
    Pile maPile2;
	Pile mapile3;
    int i;
    maPile2=creerPile();
    maPile=creerPile();
    
    for(i=0; i<20; i+=2)
        empiler(&maPile,i);
        
        for(i=1; i<20; i+=2)
        empiler(&maPile2,i);
     afficher(maPile);
     afficher(maPile2);   
        if (egalite(maPile,maPile2)){printf("les deux piles sont egaales\n");}
        else {printf("les deux piles sont differentes\n");}
	mapile3=decouper(maPile2,20);
	afficher(mapile3); 
	afficher(maPile2); 
    /*
    afficher(maPile);
    if(!estVide(maPile))
        printf("Le sommet de la pile est %d\n",sommet(maPile));
    depiler(&maPile);
    afficher(maPile);*/
    return 0;
}
Pile creerPile()
{
    return NULL;
}
int estVide(Pile p) {
    return p==NULL;
}
void empiler(Pile *p, int x) {
    Cellule *nouv;
    nouv = (Cellule *)malloc(sizeof(*nouv));
    nouv->valeur=x;
    nouv->suivant=*p;
    *p=nouv;
}
void depiler(Pile *p) {
    if(!estVide(*p)){
    Pile ancien;
    ancien = *p;
    *p = (*p)->suivant;
    free(ancien);
    }
    else
        printf("La piles est déjà vide!\n");
}
int sommet(Pile p) {
    return p->valeur;
}
void afficher(Pile p) {
    Pile tmp;
    tmp = creerPile();
    if(estVide(p)){
        printf("La pile est vide!\n");
    }
    else{
        while(!estVide(p)){
            printf("%d\n",sommet(p));
            empiler(&tmp,sommet(p));
            depiler(&p);
        }
        while(!estVide(tmp)){
            empiler(&p,sommet(tmp));
            depiler(&tmp);
        }
    }
}

int egalite(Pile p1 , Pile p2){
	Pile p11=creerPile(),p22=creerPile();
while(p1!=NULL && p2 !=NULL && (p1->valeur == p2->valeur)){


empiler(&p11,sommet(p1));
depiler(&p1);
empiler(&p22,sommet(p2));
depiler(&p2);


}
int res=estVide(p1) && estVide(p2);
while(!estVide(p11)){
            empiler(&p1,sommet(p11)); depiler(&p11);
        }
        while(!estVide(p22)){
            empiler(&p2,sommet(p22));
            depiler(&p22);
        }
return (res);
}


//decouper 
Pile decouper (Pile p , int n)
{ Pile tmp1;
	
   tmp1 = creerPile();
	 Pile tmp2;
	
   tmp2 = creerPile();
	
	 
    while(!estVide(p))
	{empiler(&tmp1,sommet(p));
		depiler(&p);
	 }
	while(!estVide(tmp1)  && n!=0)
	{empiler(&tmp2,sommet(tmp1));
		empiler(&p,sommet(tmp1));
		depiler(&tmp1);
		n=n-1;
  }
while(!estVide(tmp1))
	{empiler(&p,sommet(tmp1));
		depiler(&tmp1);
	 }
	return tmp2;
}
