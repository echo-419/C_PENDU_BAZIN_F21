#include <stdio.h>
#include <stdlib.h>

//prototype
int TestLettre (char mot[], char lettre, char *MotProposez[]);
int Affichage (char mot[], char MotProposez[],char lettre, int *essai);

int main()
{
    printf("Jeu Du Pendu!\n\n");

    char MotCacher[20];
    char MotProposez[20];
    char PropositionLettre=' ' ;
    int y=0;
    int essai=7;

    printf("Entrez un mot a trouver:\n");
    scanf("%s",MotCacher);
    while ((MotProposez[y++]!= MotCacher[y++])||(essai==0)){      //tant le mot rechercher et le mot afficher sont different ou qu'il reste des vie
        system("cls");
        Affichage(MotCacher,MotProposez,PropositionLettre, &essai);
        printf("\n Il vous reste %d essai(s)\n",essai);
        essai=essai--;
        printf("Entrez une lettre a trouver:\n");
        scanf("%c",&PropositionLettre);


    }
    if (essai!=0)
        printf("Vous avez Gagner !!!");
    else
        printf("Vous avez Perdu");
    return 0;
}

int Affichage (char mot[], char MotProposez[],char lettre,int *essai){
    int i=-1, test=1;
    while (mot[++i]) //tant que mot[i] existe dans tous le tableau
        if (TestLettre(mot,lettre,&MotProposez )==1)
            printf("%c ",mot[i]);   //si lettre touver affichage de la lettre
        else{
            printf("_ " );  //si lettre non trouver on laisse un _
            test=0;
            }
        if (test==0)
            essai=essai-1;             //on retitre un essai
return test;
}

int TestLettre (char mot[], char lettre, char *MotProposez[]){
    int i=0, test=0;
    while (mot[i])  //tant que mot[i] existe dans tous le tableau
    if (mot[i++] == lettre){    //si lettre touver
        test=1;
        *MotProposez[i]= lettre;    //on modifie le tableau du mot proposé
    }
    return test;}
