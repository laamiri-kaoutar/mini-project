#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct Livre{
     char titre[80];
     char auteur[100];
     float prix;
     int quantite;
}Livre ;
void ajouter(Livre livres[], int *cmp){
       int n;
       printf("vous voulez ajouter : \n 1-un element \n 2-plusieurs elements\n");
       scanf("%d",&n);
       if(n==1){
        printf("entrer le titre de livre : ");
        scanf("%s",livres[*cmp].titre);
        printf("entrer l'auteur de livre :");
        scanf("%s",livres[*cmp].auteur);
        printf("entrer le prix de livre : ");
        scanf("%f",&livres[*cmp].prix);
        printf("entrer la quantite de livre : ");
        scanf("%d",&livres[*cmp].quantite);
        printf("\n");
          (*cmp)++;
       } else {
         int nmblivres;
        printf("combiet de livre vous voulez entrer :");
        scanf("%d",&nmblivres);
        for(int i=0; i< nmblivres ; i++){
         printf("entrer le titre de livre %d : ", i+1);
        scanf("%s",livres[*cmp].titre);
        printf("entrer l'auteur de livre %d : ", i+1);
        scanf("%s",livres[*cmp].auteur);
        printf("entrer le prix de livre %d : ", i+1);
        scanf("%f",&livres[*cmp].prix);
        printf("entrer la quantite de livre %d : ", i+1);
        scanf("%d",&livres[*cmp].quantite);
        printf("\n");
          (*cmp)++;
        }
        }

}
void afficher(Livre livres[] , int cmp){
    printf("\n%-20s | %-20s | %-20s | %-20s | ","Titre", "Auteur", "Prix", "Qauntite");
    for(int i=0 ; i<cmp ; i++){
        printf("\n%-20s | %-20s | %-20f | %-20d | ",livres[i].titre,livres[i].auteur,livres[i].prix,livres[i].quantite);

    }
}
void rechercher(Livre livres[], int cmp){
    char titre[50];
    int found=-1;
    printf("qu'il est le titre de livre que vous voulez chercher : ");
    scanf("%s",titre);
    for(int i=0 ; i< cmp ; i++){
        if(strcmp(livres[i].titre , titre) == 0){
        printf("\n%-20s | %-20s | %-20f | %-20d | ",livres[i].titre,livres[i].auteur,livres[i].prix,livres[i].quantite);
        found=i;
        break;
        }
    }
    if (found<0) printf("ce livre n'est existe pas :");
}
int index_rechercher(Livre livres[],char titre[], int cmp){
    int found=-1;
    for(int i=0 ; i< cmp ; i++){
        if(strcmp(livres[i].titre , titre) == 0){
        found=i;
        break;
        }
    }
   return found;
}
void suppremer(Livre livre[] , int *cmp){
    char titre[50];
    printf("qu'il est le titre de livre que vous voulez suppremer : ");
    scanf("%s",titre);
    int found = index_rechercher(livre , titre , *cmp);
    if(found>=0){
        for(int j=found ; j<(*cmp)-1 ; j++){
         strcpy(livre[j].titre, livre[j+1].titre);
         strcpy(livre[j].auteur, livre[j+1].auteur);
         livre[j].prix=livre[j+1].prix;
         livre[j].quantite=livre[j+1].quantite;
            }
            (*cmp)--;
    }else   printf("ce livre n'est existe pas :");
}

void modifier(Livre livre[], int cmp){
    char titre[50];
    printf("qu'il est le titre de livre que vous voulez modifier : ");
    scanf("%s",titre);
    int found = index_rechercher(livre , titre , cmp);
    if(found>=0){
            int new_qauntite;
            printf("entrer la nouvelle qauntite de ce livre : ");
            scanf("%d",&new_qauntite);
            livre[found].quantite= new_qauntite;
            printf("bla bal:");
    } else printf("ce livre n'est existe pas :");
    }

int main(){
Livre livres[150];
int cmp =0;
ajouter(livres,&cmp);
afficher(livres,cmp);
/**rechercher*/
rechercher(livres,cmp);
suppremer(livres ,&cmp);
afficher(livres,cmp);
modifier(livres,cmp);
afficher(livres,cmp);

}
