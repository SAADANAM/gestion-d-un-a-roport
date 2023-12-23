#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//1)creer les structure 
typedef struct{
	int j,a,m;
}date;
typedef struct avion {
	char mat[20];
	int nbrp;
	char type[20];
	date dt;
	int nbrv;
	struct avion *next ;
}avion;
// 2)saisie 
 
avion* creer_avion (){
	//allaocation
	avion *a=(avion*)malloc(sizeof(avion));
	//saisie 
	printf ("saisire les info suivant :\n");
	printf ("matrecule :");
	scanf("%s",a->mat);
	printf ("\nsaiisre le nbr de place dans cette avion: ");
	scanf("%d",&a->nbrp);
	do {
		printf ("\n saisire la sitiuation de l'avion (decoler,atterit ou maintenace ) :");
		scanf("%s",a->type);	
	}while (strcmp(a->type,"decoler")!=0 || strcmp(a->type,"atterit")!=0 || strcmp(a->type,"maintenace")!=0);
	printf ("\nla date :");
	scanf("%d%d%d",&a->dt.j,&a->dt.m,&a->dt.a);
	printf ("\nsasisre le nbr de vols :");
	scanf("%d",&a->nbrv);
	return a;
}
//3)d- trier par nombre de places dans un order decroissant
avion*trier(avion *liste){
	avion  *p=liste,*nv;
	int nbrpmax=p->nbrp,tour=0;
	nv=creer_avion ();
	//trouver le nombre max de places
	while (p->next!=NULL){
if(nbrpmax<p->nbrp){
    nbrpmax=p->nbrp
}
		p=p->next;

	}
	//remplace list par nv
	while (p->next!=NULL){
if(nbrpmax<=p->nbrp){
        if(tour==0){ajout_debut(nv);
            tour++;
        }else if(tour==1){ajout_pos(nv,2);
            tour++;
        }else ajout_fin(nv);
}
		p=p->next;
	}
	return nv ;
}
avion* ajout_pos(avion *liste ){
	int pos;
	avion *a,*p=liste,*m=p ;
	a=creer_avion();
	printf (" saisire la position :\n");
	scanf("%d",&pos);
	int n;
	while (p->next!=NULL){
		p=p->next;
		
		n++;
		if(n==pos){
			break;
		}
		m=m->next;	
	}
	
	a->next=p;
	m->next=a;
	return liste ;
}
avion*trier(avion *liste){
	avion *a=liste, *p=liste ,*p1=liste;
	while (p->next!=NULL){
	
		p=p->next;
		
	}
	while (p1->next != p->next ){
		p1=p1->next;
			 if (p->nbrp > a->nbrp){
				p=NULL;
			 }else a=p1->next;
	}
	return liste ;
}
void affichage (avion *liste){
	avion *p=liste;
	while (p->next!=NULL){
	
		p=p->next;
		printf ("%s\t%d\t%s\t%d/%d/%d\t%d->",p->mat,p->nbrp,p->type,p->dt.j,p->dt.m,p->dt.a,p->nbrv);
		
	}
}
//sup 
//  5 a suprime liste dbut
avion *suprdb(avion *liste){
	avion *t=liste;
	if(liste==NULL){return liste;}
	liste=liste->next;
	free(t);
	return liste ;
}



// 5 b suppresion fin
avion *supfn( avion*liste){
	avion *t1=liste;
	avion *t;
	while(t1->next->next!=NULL){
		t1=t1->next;	
	}
	t1->next=NULL;
	t=t1->next;
	free(t);
	
	return liste ; 
}
// 5 c suppresion en position 
avion *suppos( avion *liste, int pos){
	avion *t;
 	avion *c=liste;
 	int i=0 ;  
 	if(liste==NULL)return liste;
 	if(pos==1){ 
 	  return 	suprdb(liste) ; 
	 }else{
	while(c!=NULL){
	 		 i++;
	 		if(i==pos-1){
			 break;
			 }
 	        c=c->next;
			
            }
 if(c==NULL){
 	printf("indspoo");
 	return liste;
	 }

 	t=c->next;
 	c->next=t->next;
 	free(t);
 }
 	return liste ;	
 	
} 
// 6verification 
avion* verifie (avion *liste ){
	char s[9] ;
		avion*a=liste ;
	printf (" saisire le code de l avion a verifier :\n");
	gets(s);
	while (a->next!=NULL){
			
			if (strcmp(a->mat,s)==0){
				
				return *s;
			}
			else {
				return -1;
			}
			a=a->next;
}
}


//7)supprimer les avions moins de 20ans et sont actuellement en maintenance technique
avion* ans20(avion *liste){
avion *a=liste;
//n est la position 
int n=0,age;
while(a->next!=NULL){
        n++;
        // age et test maintenance
        age=2023-(a->dt.a);
    if (age>=20&&strcmp(a->type,"maintenace")==0){
        liste=suppos(liste,n);
    }
      a=a->next;
}
return liste ;
}
//12)
void poucentage(avion *liste){
avion *a=liste;
int nm=0,nd=0,na=0,nbr;
nbr=nbrtotale(liste);

while(a->next!=NULL){

    if (strcmp(a->type,"maintenace")==0){
        nm++;
    }
     if (strcmp(a->type,"decoler")==0){
        nd++;
    }
     if (strcmp(a->type,"atterit")==0){
        na++;
    }
      a=a->next;
}
printf("\n le pourcentage des avions atterit est: %d \nle pourcentage des avions decoler est: %d \nle pourcentage des avions maintenace est: %d ",(na/nbr)*100,(nd/nbr)*100,(nm/nbr)*100);
}
//13
void maxvol(avion *liste){
avion *a=liste;
int age,maxvol,test=0;
//calcule max vols dune avion dage < 10
while(a->next!=NULL){
        age=2023-(a->dt.a);
    if (age<10){
            if(test==0){
                   maxvol=a->nbrv;
                test++;
            }
            if(maxvol<a->nbrv){
                maxvol=a->nbrv;
            }
    }
      a=a->next;
}
//affiche lavion qui a le maxvol
while(a->next!=NULL){
age=2023-(a->dt.a);
    if (maxvol&&age<10){
            printf ("%s\t%d\t%s\t%d/%d/%d\t%d->",a->mat,a->nbrp,a->type,a->dt.j,a->dt.m,a->dt.a,a->nbrv);

    }
      a=a->next;
}
}
//14
void minvol(avion *liste){
avion *a=liste;
int age,minvol,test=0;
//calcule min vols dune avion dage < 10
while(a->next!=NULL){
        age=2023-(a->dt.a);
    if (age<10){
            if(test==0){
                   minvol=a->nbrv;
                test++;
            }
            if(minvol>a->nbrv){
                minvol=a->nbrv;
            }
    }
      a=a->next;
}
//affiche lavion qui a le minvol
while(a->next!=NULL){
age=2023-(a->dt.a);
    if (minvol&&age<10){
            printf ("%s\t%d\t%s\t%d/%d/%d\t%d->",a->mat,a->nbrp,a->type,a->dt.j,a->dt.m,a->dt.a,a->nbrv);

    }
      a=a->next;
}
}
//9
int nbr_avion_atterirt(avion*liste){
	avion *p=liste ;
	
	int j,n;
	printf (" saaisire le jour :\n");
	scanf("%d",&j);
	while(p->next!=NULL){
		if (strcmp(p->type,"atterit")==0 &&  p->dt.j==j ){
			n++;
		}
		p=p->next;
}
		return n;
}10
int nbr_avion_decolle(avion*liste){
	avion *p=liste ;
	
	int j,n;
	printf (" saisire le jour :\n");
	scanf("%d",&j);
	while(p->next!=NULL){
		if (strcmp(p->type,"decolle")==0 &&  p->dt.j==j ){
			n++;
		}
		p=p->next;
		
}
return n;
}11
int nbr_avion_maintenance(avion*liste){
	avion *p=liste ;
	
	int j,n;
	printf (" saaisire le jour :\n");
	scanf("%d",&j);
	while(p->next!=NULL){
		if (strcmp(p->type,"maintenance")==0 &&  p->dt.j==j ){
			n++;
		}
		p=p->next;
		
}
return n;
}
int main() {
	
	getch();
}
