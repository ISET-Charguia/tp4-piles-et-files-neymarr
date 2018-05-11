#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Pile decouper (Pile p , int n);

void empilerdeuxpiles(Pile p1, Pile p2) ;
int expr ( char *ch  );

int main()
{
   char ch[100];
    
    puts("saisir chaine");
    scanf("%s",ch);
    if(!expr(ch)){
		
		puts("incorrect");
	}
	
    /*for(i=0;i<p1;i++){
    puts("saisir une entier");
    scanf("%d",&n);
    empiler(&mapile,n);
		}
	/*puts("Remplissage de 2 eme Pile");
    for(i=0;i<p2;i++){
    puts("saisir une entier");
    scanf("%d",&n);
    empiler(&mapile,n);
}*/
/*if(egalite(mapile,mapile2)){
puts("les deux pile sont identiques");	
}else{
puts("les deux piles ne sont pas identiques");
}
puts("saisir pos case");
scanf("%d",&n);
afficher(decouper(mapile,n));

puts("Affichage de deux piles");
empilerdeuxpiles(mapile,mapile2);*/
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
        printf("La pile est dÃ©jÃ  vide!\n");
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
return res;
}



Pile decouper (Pile p , int n)
{ 
Pile p1;
Pile p2;
   p1 = creerPile();

	
   p2 = creerPile();

	 
    while(!estVide(p))
	{
		empiler(&p1,sommet(p));
		depiler(&p);
	 }
	while(!estVide(p1)  && n!=0)
	{	
		empiler(&p2,sommet(p1));
		empiler(&p,sommet(p1));
		depiler(&p1);
		n=n-1;
  }
while(!estVide(p1))
	{
		empiler(&p,sommet(p1));
		depiler(&p1);
	 }
	return p2;
}


void empilerdeuxpiles(Pile p1, Pile p2)
{
	
Pile p3=creerPile();

while(!estVide(p2)){
empiler(&p3,sommet(p2));
depiler(&p2);	
}

while(!estVide(p3)){
empiler(&p1,sommet(p3));
depiler(&p3);	
}

afficher(p1);
	
	
}



int expr ( char *ch  )
{
	int i=0;
	Pile p=creerPile();
	Pile p1=creerPile();
	Pile p2=creerPile();
	Pile p3=creerPile();
	
	
	for(i=0;i<strlen(ch);i++){
	switch(ch[i]){
		case '(': empiler(&p,ch[i]);empiler(&p1,i);break;
		case ')': if(estVide(p))return 0;
			depiler(&p);empiler(&p3,sommet(p1));empiler(&p2,i);depiler(&p1);	
		}
	}
	
		if(!estVide(p)){
			return 0;
		}
		
		
		while(!estVide(p3)){
		printf("\n(%d,%d)",sommet(p3),sommet(p2));
		depiler(&p3);
		depiler(&p2);	
		
		}
		return 1 ;
}
