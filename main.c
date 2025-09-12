#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void AddPlane();
void DisplayAirPort();
void ModifyPlane();
void DeletePlane();
void SortPlanes();
void Statistics();
void Search();

typedef struct 
{
    int ID;
    char Model [20];
    int Capacity;
    char Status[15];
    
} plane;

typedef struct 
{
    char name [20];
    int planesNumber;
    plane planes [200];

} airport ;

airport Master;
plane Plane;
int identification = 73;


int main(){
    int choice;
    Master.planesNumber = 0;

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
            system("cls");
            printf("vous avez choisi l'affichage\n");
            DisplayAirPort();
        }break;
     case 2:
        {
            system("cls");
            printf("vous avez choisi l'ajout\n");
            AddPlane();

        }break;
    case 3:
        {
            printf("vous avez choisi la modification\n");
            ModifyPlane();
        }break;
     case 4:
        {
            printf("vous avez choisi la supprition\n");
            DeletePlane();
        }break;
     case 5:
        {
            printf("vous avez choisi la recherche\n");
            Search();
        }break;
     case 6:
        {
            printf("vous avez choisi le tri\n");
            SortPlanes();
        }break;
     case 7:
        {
            printf("vous avez choisi l'affichage des statistiques\n");
            Statistics();
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
    
    
    Master.planes[Master.planesNumber].ID = identification ++;
    printf("l'ID de cette avion est: %d\n", Master.planes[Master.planesNumber].ID);

    printf("entrer le model d'avion: ");
    scanf(" %[^\n]%*c", Master.planes[Master.planesNumber].Model);

    printf("entrer la capacite d'avion: ");
    scanf("%d",&Master.planes[Master.planesNumber].Capacity);

    printf("choisir le statut d'avion\n");
    printf("1.Disponible\n2.En maintenance\n3.En vol\n");
    scanf("%d", &choice);
    do
    {
        switch (choice)
    {
    case 1:
        printf("vous avez choisi 'disponible'\n");
        strcpy(Master.planes[Master.planesNumber].Status, "Disponible");
        break;
    case 2:{
        printf("vous avez choisi 'En maintenance'\n");
        strcpy(Master.planes[Master.planesNumber].Status, "En maintenance");
    }break;   
    case 3:{
        printf("vous avez choisi 'En vol'\n");
        strcpy(Master.planes[Master.planesNumber].Status, "En vol");
    }break;   
    
    default:
        printf("le choix indisponible. Ressayer.\n");
        break;
    }
        
    } while (choice < 1 || choice > 3);

    Master.planesNumber++;
    return ;
}

void DisplayAirPort(){
    system("cls");
    if (Master.planesNumber == 0)
    {
        printf("il n y a aucun avion enregister\n");
    } else
    {
       printf("| nom d'aeroport | nombre d'avion | ID d'avion | model d'avion | capacite d'avion | statut d'avion |\n");

    for (int i = 0; i < Master.planesNumber; i++)
    {
        printf("\t%s\t|\t%d\t|\t%d\t|\t%s\t|\t%d\t|\t%s\t|\n",Master.name , Master.planesNumber, Master.planes[i].ID, Master.planes[i].Model, Master.planes[i].Capacity, Master.planes[i].Status);
    }
    }
    return;
}

void ModifyPlane(){
    
    int id, enumeration = 1, choice;
    
    for (int i = 0; i < Master.planesNumber; i++)
    {
        printf("ID d'avion %d est: %d\n", enumeration, Master.planes[i].ID);
        enumeration++;
    }

    printf("entrer l'ID de l'avion a modifier: ");
    scanf("%d", &id);
    for (int i = 0; i < Master.planesNumber; i++)
    {
        if (Master.planes[i].ID == id)
        {
            printf("choisir le nouveau statut d'avion\n");
    printf("1.Disponible\n2.En maintenance\n3.En vol\n");
    scanf("%d", &choice);
    do
    {
        switch (choice)
    {
    case 1:
        printf("vous avez choisi 'disponible'\n");
        strcpy(Master.planes[i].Status, "Disponible");
        break;
    case 2:{
        printf("vous avez choisi 'En maintenance'\n");
        strcpy(Master.planes[i].Status, "En maintenance");
    }break;
    case 3:{
        printf("vous avez choisi 'En vol'\n");
        strcpy(Master.planes[i].Status, "En vol");
    }break;

    default:
        printf("le choix indisponible. Ressayer.\n");
        break;
    }
        
    } while (choice < 1 || choice > 3);

        printf("entrez le nouveau modele de votre avion: ");
        scanf(" %[^\n]%*c", Master.planes[i].Model);

        printf("entrez la nouvelle capacite de votre avion: ");
        scanf("%d",&Master.planes[i].Capacity);
        
    } else
    {
        printf("Aucun avion avec l'ID %d n'a ete trouve.\n", id);
    } 
    
    }
    return;
}

void DeletePlane(){

    int  id;
    for (int i = 0; i < Master.planesNumber; i++)
    {
        printf("ID d'avion %d est: %d\n", i+1, Master.planes[i].ID);

    }

    printf("entrer l'ID de l'avion a supprimer: ");
    scanf("%d", &id);
    for (int i = 0; i < Master.planesNumber; i++)
    {   
        if (id == Master.planes[i].ID)
        {
            for (int j = i; j < Master.planesNumber-1; j++)
        {
            Master.planes[j] = Master.planes[j+1];
        }

        } else
        {
            printf("Aucun avion avec l'ID %d n'a ete trouve.\n", id);
        }
    }
    Master.planesNumber--;
    return;
}

void SortPlanes(){

    int choice;
    plane temp;
    printf("chosir de trier par:\n1.Par capacite.\n2.Par Model.\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("vous avez choisi par capacite.\n");
        for (int i = 0; i < Master.planesNumber; i++)
        {
            for (int j = i+1; j < Master.planesNumber; j++)
            {
                if (Master.planes[i].Capacity > Master.planes[j].Capacity)
                {
                    temp = Master.planes[i];
                    Master.planes[i] = Master.planes[j];
                    Master.planes[j] = temp;
                }
                
            }
            printf("L'ID d'avion %d est: %d de capacite %d.\n", i+1, Master.planes[i].ID, Master.planes[i].Capacity);
        }
        
        break;
    case 2:
    
        printf("vous avez choisi par model.\n");
        for (int i = 0; i < Master.planesNumber; i++)
        {
            for (int j = i+1; j < Master.planesNumber; j++)
            {
                if (stricmp(Master.planes[i].Model, Master.planes[j].Model) > 0)
                {
                    temp = Master.planes[i] ;
                    Master.planes[i] = Master.planes[j];
                    Master.planes[j] = temp;
                }
                
            }
            printf("L'ID d'avion %d est: %d de model %s.\n", i+1, Master.planes[i].ID, Master.planes[i].Model);
        }

        break;
    default:
        break;
    }
    return;
}

void Statistics(){

    int choice =0;
    int countDispo = 0, countMaintenance = 0, countVol = 0;

    for (int i = 0; i < Master.planesNumber; i++)
    {
        if (stricmp(Master.planes[i].Status, "disponible") == 0)
        {
            countDispo++;
        } else if (stricmp(Master.planes[i].Status, "en maintenance") == 0)
        {
            countMaintenance++;
        } else if (stricmp(Master.planes[i].Status, "en vol") == 0)
        {
            countVol++;
        }
    }

    printf("choisir entre: \n1.Affichage nombre d'avion par statut.\n2.Affichage de nombre d'avion dans le parc.\n3.Affichage de capaciter total de la flotte.\n4.Affichage d'avion par capacite (plus grande/plus petite)\n5.l'affichage de coefficient d'occupation du parc\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("le nombre total d'avion: \n1.diponible: %d.\n2.en maintenance: %d.\n3.En vol: %d\n", countDispo, countMaintenance, countVol);
        break;

    case 2:{
        int parkingPlanes=0;
        parkingPlanes = countDispo + countMaintenance;  
        printf("le nombre d'avion dans en parc: %d\n", parkingPlanes);
        break;
        }

    case 3:{
        int totalCapacity = 0;
        for (int i = 0; i < Master.planesNumber; i++)
        {
            totalCapacity += Master.planes[i].Capacity;
        }
        printf("Capacite totale de la flotte est: %d\n", totalCapacity);
        break;
        }   
        
    case 4:{
        int max = Master.planes[0].Capacity;
        int min = Master.planes[0].Capacity;
        for (int i = 1; i < Master.planesNumber; i++)
        {
            if (Master.planes[i].Capacity > max)
            {
                max = Master.planes[i].Capacity;
            }
            if (Master.planes[i].Capacity < min)
            {
                min = Master.planes[i].Capacity;
            }
        }
        printf("L'avion de la grande capacite est: %d\nL'avion de la petite capacite est: %d\n", max, min);
        break;}    

    case 5:{
        float coeff;
        coeff = ((float)countDispo / Master.planesNumber)*100;
        printf("le coefficient d'occupation du parc est: %.2f %%\n", coeff);
        break; }   

    default:
        printf("choix invalide.\n");
    }

    return ;
}

void Search() {
    int searchID, choice, verification = 0;
    char searchModel[20];
    plane temp;

    printf("Choisir:\n1. Par ID.\n2. Par Model.\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
        int enumeration = 1;
        for (int i = 0; i < Master.planesNumber; i++) {
            for (int j = i+1; j < Master.planesNumber; j++) {
                if (Master.planes[i].ID > Master.planes[j].ID) {
                    plane tmp = Master.planes[i];
                    Master.planes[i] = Master.planes[j];
                    Master.planes[j] = tmp;
                }
            }
        }

        for (int i = 0; i < Master.planesNumber; i++) {
            printf("ID d'avion %d est: %d\n", enumeration, Master.planes[i].ID);
            enumeration++;
        }

        printf("Entrer l'ID de l'avion a rechercher: ");
        scanf("%d", &searchID);

        int left = 0, right = Master.planesNumber - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (searchID == Master.planes[middle].ID) {
                printf("L'id---->%d\nl'model---->%s\nl'capacite---->%d\nl'statut---->%s\n",Master.planes[middle].ID, Master.planes[middle].Model, Master.planes[middle].Capacity, Master.planes[middle].Status);
                verification = 1;
                break;
            } else if (searchID > Master.planes[middle].ID) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        if (!verification) {
            printf("Aucun avion a l'ID = %d\n", searchID);
        }
        break;
    }

    case 2: {
        int enumeration = 1;
        for (int i = 0; i < Master.planesNumber; i++) {
            for (int j = i+1; j < Master.planesNumber; j++) {
                if (stricmp(Master.planes[i].Model, Master.planes[j].Model) > 0) {
                    temp = Master.planes[i];
                    Master.planes[i] = Master.planes[j];
                    Master.planes[j] = temp;
                }
            }
        }

        for (int i = 0; i < Master.planesNumber; i++) {
            printf("Le model d'avion %d est: %s\n", enumeration, Master.planes[i].Model);
            enumeration++;
        }

        printf("Entrer le model de l'avion a rechercher: ");
        scanf(" %[^\n]%*c", searchModel);

        int left = 0, right = Master.planesNumber - 1, found = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = stricmp(Master.planes[mid].Model, searchModel);

            if (cmp == 0) {
                printf("Avions trouves avec le model %s:\n", searchModel);

                int i = mid;
                while (i >= 0 && stricmp(Master.planes[i].Model, searchModel) == 0) {
                    i--;
                }
                i++;

                while (i < Master.planesNumber && stricmp(Master.planes[i].Model, searchModel) == 0) {
                    printf("L'id---->%d\nl'model---->%s\nl'capacite---->%d\nl'statut---->%s\n",Master.planes[mid].ID, Master.planes[mid].Model, Master.planes[mid].Capacity, Master.planes[mid].Status);
                           
                    i++;
                }
                found = 1;
                break;
            } else if (cmp < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (!found) {
            printf("Aucun avion avec le model %s\n", searchModel);
        }
        break;
    }

    default:
        printf("Choix invalide.\n");
        return;
    }
}
