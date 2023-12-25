#include <stdio.h>
#include <stdlib.h>
enum state{main_menu,login_system};
enum state currentwindow=main_menu;
typedef struct {
    int mois;
    int annee;
    int jour;
} date;

typedef struct {
    int id;
    int capacite;
    char matricule[50];
} bus;

typedef struct {
    int cin;
    int num_tel;
    char nom[50];
    char region[50];
} voyageur;

typedef struct {
    int num_reser;
    int nbr_voy;
    bus b;
    char pt_depart[50];
    char pt_arrive[50];
    date d_reser;
} reservation;

int ajouter_voyageur(char *filename, voyageur v);
int ajouter_reservation(char *filename, reservation r);
int ajouter_bus(char *filename, bus b);
voyageur chercher_voyageur(char *filename, int cin);
reservation chercher_reservation(char *filename, int num_reser);
bus chercher_bus(char *filename, int Id);
int modifier_reservation( char * filename, int num_reser, reservation r1 );
int modifier_voyageur (char * filename, int cin, voyageur v1);
int supprimer_reservation(char * filename, int num_reser);

int ajouter_voyageur(char *filename, voyageur v) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d %d %s %s\n", v.cin, v.num_tel, v.nom, v.region);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}

int ajouter_reservation(char *filename, reservation r) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d %d %s %s %d %d %s %d %d %d\n", r.num_reser, r.nbr_voy, r.pt_depart, r.pt_arrive, r.b.id, r.b.capacite, r.b.matricule, r.d_reser.mois, r.d_reser.annee, r.d_reser.jour);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}


int ajouter_bus(char *filename, bus b) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d %d %s\n", b.id, b.capacite, b.matricule);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}
voyageur chercher_voyageur(char *filename, int cin) {
    voyageur v;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (tr == 0 && fscanf(f, "%d %d %s %s\n", &v.cin, &v.num_tel, v.nom, v.region) != EOF) {
            if (v.cin == cin) {
                tr = 1;
            }
        }
        fclose(f);
    }

    if (tr == 0) {
        v.cin = -1;
    }
    return v;
}
void exit_system()
{
    printf("\t\tSortir...\n\t\t aucun enregistement \n\n\t\tPress \"Entrer/Retourner\" Pour sortir");
    char exitprog;
    fflush(stdin);
    scanf("%c",&exitprog);
}
 bus chercher_bus(char *filename, int Id) {
    bus b;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (tr == 0 && fscanf(f, "%d %d %s\n", &b.id, &b.capacite, b.matricule) != EOF) {
            if (b.id == Id) {
                tr = 1;
            }
        }
        fclose(f);
    }

    if (tr == 0) {
        b.id = -1;
    }
    return b;
}
reservation chercher_reservation(char *filename, int num_reser) {
    reservation r;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (tr == 0 && fscanf(f,"%d %d %s %s %d %d %s %d %d %d\n", &r.num_reser, &r.nbr_voy, r.pt_depart, r.pt_arrive, &r.b.id, &r.b.capacite, r.b.matricule, &r.d_reser.mois, &r.d_reser.annee, &r.d_reser.jour ) != EOF) {
            if (r.num_reser == num_reser) {
                tr = 1;
            }
        }
        fclose(f);
    }

    if (tr == 0) {
         r.num_reser= -1;
    }
    return r;
}
    modifier_reservation( char * filename, int numreser, reservation r1 ){
    int tr=0;
    reservation r;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d %s %d %d %d\n", &r.num_reser, &r.nbr_voy, r.pt_depart, r.pt_arrive, &r.b.id, &r.b.capacite, r.b.matricule, &r.d_reser.mois, &r.d_reser.annee, &r.d_reser.jour)!=EOF)
        {
            if(r.num_reser==numreser )
            {
                fprintf(f2,"%d %d %s %s %d %d %s %d %d %d\n", &r1.num_reser, &r1.nbr_voy, r1.pt_depart, r1.pt_arrive, &r1.b.id, &r1.b.capacite, r1.b.matricule, &r1.d_reser.mois, &r1.d_reser.annee, &r1.d_reser.jour);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %s %s %d %d %s %d %d %d\n", &r.num_reser, &r.nbr_voy, r.pt_depart, r.pt_arrive, &r.b.id, &r.b.capacite, r.b.matricule, &r.d_reser.mois, &r.d_reser.annee, &r.d_reser.jour);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
modifier_voyageur (char * filename, int cin, voyageur v1){
    int tr=0;
    voyageur v;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s\n", &v.cin, &v.num_tel, v.nom, v.region)!=EOF)
        {
            if(v.cin==cin )
            {
                fprintf(f2,"%d %d %s %s\n", &v1.cin, &v1.num_tel, v1.nom, v1.region);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %s %s\n", &v.cin, &v.num_tel, v.nom, v.region);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
supprimer_reservation(char * filename, int num_reser){
     int tr=0;
    reservation r;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d %s %d %d %d\n", &r.num_reser, &r.nbr_voy, r.pt_depart, r.pt_arrive, &r.b.id, &r.b.capacite, r.b.matricule, &r.d_reser.mois, &r.d_reser.annee, &r.d_reser.jour)!=EOF)
        {
            if(r.num_reser== num_reser)
                tr=1;
            else
                fprintf(f2,"%d %d %s %s %d %d %s %d %d %d\n", &r.num_reser, &r.nbr_voy, r.pt_depart, r.pt_arrive, &r.b.id, &r.b.capacite, r.b.matricule, &r.d_reser.mois, &r.d_reser.annee, &r.d_reser.jour);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int main() {
   char filename1[] = "bus.txt";
    char filename2[] = "reservation.txt";
    char filename3[] = "voyageur.txt";
      while (1)
    {
    int choice;
   system("CLS");
        if(currentwindow==main_menu){
 printf("\n\t\t\t\t\tBienvenue dans E-Bus Travel \n\t\t\t\t\vous etes dans la bonne place merci pour votre confiance\n");

            currentwindow=login_system;
                   system("PAUSE");
                    system("CLS");
        }








           else if(currentwindow==login_system){


        printf("\n\t\t\t\t\tMenu:\n");
        printf("\n\t\t\t\t1. Ajouter un voyageur\n");
        printf("\n\t\t\t\t2. Ajouter une reservation\n");
        printf("\n\t\t\t\t3. Ajouter un bus\n");
        printf("\n\t\t\t\t4. Chercher un voyageur\n");
        printf("\n\t\t\t\t5. Chercher une reservation\n");
        printf("\n\t\t\t\t6. Chercher un bus\n");
        printf("\n\t\t\t\t7. Modifier une reservation\n");
        printf("\n\t\t\t\t8. Modifier un voyageur\n");
        printf("\n\t\t\t\t9. Supprimer une reservation\n");
        printf("\n\t\t\t\t10. Quitter\n");

        printf("\n\t\t\t\tChoix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                voyageur v;
                int k;
                printf("\n\t\t\t\tEntrez les détails du voyageur :\n");
                printf("\n\t\t\t\tEntrez le nom :\n ");
                scanf("\n\t\t\t\t%s",&v.nom);
                printf("\n\t\t\t\tEntrez la region :\n ");
                scanf("\n\t\t\t\t%s",&v.region);
                printf("\n\t\t\t\tEntrez le cin :\n ");
                scanf("\n\t\t\t\t%d",&v.cin);
                printf("\n\t\t\t\tEntrez le num_tel :\n ");
                scanf("\n\t\t\t\t%d",&v.num_tel);
                k=ajouter_voyageur(filename3, v);
                if (k==1){
                    printf("\n\t\t\t\tajout avec succes");
                }
                else {
                    printf("\n\t\t\t\techec");
                }
                  system("PAUSE");
                system("CLS");
                   break;
            }

            case 2: {
                reservation r;

                int a;
                printf("\n\t\t\t\tEntrez les détails de la réservation :\n");
                printf("\n\t\t\t\tentrez le num_reser:\n");
                scanf("\n\t\t\t\t%d",&r.num_reser);
                printf("\n\t\t\t\tentrez le nbr_voy:\n");
                scanf("\n\t\t\t\t%d",&r.nbr_voy);
                printf("\n\t\t\t\tentrez le pt_depart:\n");
                scanf("\n\t\t\t\t%s",&r.pt_depart);
                printf("\n\t\t\t\tentrez le pt_arrive:\n");
                scanf("\n\t\t\t\t%s",&r.pt_arrive);
                printf("\n\t\t\t\tentrez b.id:\n");
                scanf("\n\t\t\t\t%d",&r.b.id);
                printf("\n\t\t\t\tentrez b.capacite:\n");
                scanf("\n\t\t\t\t%d",&r.b.capacite);
                printf("\n\t\t\t\tentrez b.matricule:\n");
                scanf("\n\t\t\t\t%s",&r.b.matricule);
                printf("\n\t\t\t\tentrez d_reser.mois:\n");
                scanf("\n\t\t\t\t%d",&r.d_reser.mois);
                printf("\n\t\t\t\tentrez d_reser.annee:\n");
                scanf("\n\t\t\t\t%d",&r.d_reser.annee);
                printf("\n\t\t\t\tentrez d_reser.jour:\n");
                scanf("\n\t\t\t\t%d",&r.d_reser.jour);
                a=ajouter_reservation(filename2, r);
                if (a==1){
                    printf("\n\t\t\t\tsucces");
                }
                else{
                    printf("\n\t\t\t\techec");
                }
                 system("PAUSE");
                system("CLS");
                break;
            }
            case 3: {
                bus b;
                int s;
                printf("\n\t\t\t\tEntrez les détails du bus :\n");
                printf("\n\t\t\t\tentrez le id:\n");
                scanf("\n\t\t\t\t%d",&b.id);
                printf("\n\t\t\t\tentrez la capacite:\n");
                scanf("\n\t\t\t\t%d",&b.capacite);
                printf("\n\t\t\t\tentrez la matricule:\n");
                scanf("\n\t\t\t\t%s",&b.matricule);
                s=ajouter_bus(filename1, b);
                if (s==1){
                    printf("\n\t\t\t\tsucces");
                }
                else{
                    printf("\n\t\t\t\techec");

                } system("PAUSE");
                system("CLS");
                break;
            }
            case 4: {
                int cin;
                voyageur v;
                printf("\n\t\t\t\tEntrez le numéro de CIN du voyageur : ");
                scanf("\n\t\t\t\t%d", &cin);
                 v = chercher_voyageur(filename3,cin);

                    if(v.cin!=-1)
  {

                    printf("\n\t\t\le nom de voyageur dispo avec cette CIN : %s\n",v.nom);
                     printf("\n\t\t\la region de voyageur dispo avec cette CIN : %s\n",v.region);
                      printf("\n\t\t\le numero de voyageur dispo avec cette CIN : %d\n",v.num_tel);
  }
          else {
              printf("\n\t\t\voyageur non trouvable avec  cette CIN: %d\n",cin);
          }


                  system("PAUSE");
                system("CLS");
                break;
            }
            case 5: {
                int num_reser;
                printf("\n\t\t\t\tEntrez le numéro de réservation : ");
                scanf("\n\t\t\t\t%d", &num_reser);
                reservation r = chercher_reservation(filename2, num_reser);
      if(r.num_reser!=-1)  {

                    printf("\n\t\t\le nombre  de voyageurs pour cette reservation : %d\n",r.nbr_voy);
                    bus k=r.b;
                     printf("\n\t\t\le identifiant de bus pour cette reservation: %d\n",k.id);

  }
          else {
              printf("\n\t\t\reservation non trouvable avec  cette num_reser: %d\n",num_reser);
          }


                system("PAUSE");
                system("CLS");
                break;
            }
            case 6: {
                int id;
                printf("\n\t\t\t\tEntrez l'ID du bus : ");
                scanf("\n\t\t\t\t%d", &id);
                bus b = chercher_bus(filename1, id);
                      if(b.id!=-1)  {

                    printf("\n\t\t\la capacité de cette bus  %d\n",b.capacite);

                     printf("\n\t\t\ le matricule de cette bus: %s\n",b.matricule);

  }
          else {
              printf("\n\t\ bus non trouvable avec  cet id: %d\n",id);
          }
                  system("PAUSE");
                system("CLS");
                break;
            }
            case 7: {
                int num_reser;
                printf("Entrez le numéro de réservation à modifier : ");
                scanf("%d", &num_reser);
                reservation r = chercher_reservation(filename2, num_reser);
                printf("Entrez les nouvelles informations de la réservation :\n");
                modifier_reservation(filename2, num_reser, r);
                  system("PAUSE");
                system("CLS");
                break;
            }
            case 8: {
                int cin;
                printf("\n\t\t\t\tEntrez le numéro de CIN du voyageur à modifier : ");
                scanf("\n\t\t\t\t%d", &cin);
                voyageur v = chercher_voyageur(filename3, cin);
                printf("\n\t\t\t\tEntrez les nouvelles informations du voyageur :\n");
                modifier_voyageur(filename3, cin, v);
                  system("PAUSE");
                system("CLS");
                break;
            }
            case 9: {
                int num_reser;
                printf("\n\t\t\t\tEntrez le numéro de réservation à supprimer : ");
                scanf("\n\t\t\t\t%d", &num_reser);
                supprimer_reservation(filename2, num_reser);
                 system("PAUSE");
                system("CLS");
                break;
            }
            case 10:{
                    exit_system();
                    exit(0);
                    break;
            }
            default:
                printf("\n\t\t\t\tChoix invalide. Veuillez réessayer.\n");

                break;
                }}

    }

    return 0;
}
