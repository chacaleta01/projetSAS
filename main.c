#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void AddPlane();

typedef struct 
{
    char ID [6];
    char Model [20];
    int Capacity;
    char Status[15];
    // if i want to add date (optional)
} plane;

typedef struct 
{
    char name [20];
    int planesNumber = 0;
    plane planes [200];

} airport ;

airport Master;
plane Plane;

int main(){
    int choice;

    printf("--------bienvenue--------\n");
    printf("Entrez le nom de votre aeroport: ");
    scanf(" %[^\n]%*c", Master.name);

    while (1)
    {
        printf("---------------MENU---------------\n");
    printf("\n1.Afficher les informatins de l'aeroport.\n2.Ajouter un avion.\n3.Modifier les informations d'une avion (statut, model, capacite).\n4.Supprimer un avion.\n5.Rechercher un avion.\n6.trier la list des avions.\n7.Afficher les statistiques.\n0.Quitter\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        {
            printf("vous avez choisi l'affichage");
        }break;
     case 2:
        {
            printf("vous avez choisi l'ajout");

        }break;
    case 3:
        {
            printf("vous avez choisi la modification");
        }break;
     case 4:
        {
            printf("vous avez choisi la supprition");
        }break;
     case 5:
        {
            printf("vous avez choisi la recherche");
        }break;
     case 6:
        {
            printf("vous avez choisi le tri");
        }break;
     case 7:
        {
            printf("vous avez choisi l'affichage des statistiques");
        }break;
     case 0:
        {
            printf("au revoir");
            return 0;
        }break;
    }
    }
}

void AddPlane(){
system("cls");
    int choice;
    
    // printf("entrer le CNE/ID d'etudient : ");
    // scanf("%s",classe[nombreEtudients].CNE);
    

    printf("entrer le model d'avion: ");
    scanf(" %[^\n]%*c", Master.planes.Capacity);

    printf("entrer la capacite d'avion: ");
    scanf("%[^\n]%*c",Master.planes.Capacity);

    printf("choisir le statut d'avion");
    scanf("%d", &choice);
    do
    {
        switch (choice)
    {
    case 1:{
        printf("vous avez choisi 'disponible'");
        strcpy(Master.planes[Master.planesNumber].Status, "Disponible");
    }break;
    case 2:{
        printf("vous avez choisi 'En maintenance'");
        strcpy(Master.planes[Master.planesNumber].Status, "En maintenance");
    }break;   
    case 3:{
        printf("vous avez choisi 'En vol'");
        strcpy(Master.planes[Master.planesNumber].Status, "En vol");
    }break;   
    
    default:
        printf("le choix indisponible. Ressayer.\n");
        break;
    }
        Master.planesNumber++;
    } while (choice == 1 || choice == 2 || choice == 3);
    
    

    return ;
}