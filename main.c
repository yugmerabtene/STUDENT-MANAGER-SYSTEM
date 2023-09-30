#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un étudiant
typedef struct {
    char nom[50];
    char prenom[50];
    char dateNaissance[12]; // Format : JJ/MM/AAAA
    int promotion;
    char formation[50];
} Etudiant;

// Fonction pour ajouter un étudiant à la liste
void ajouterEtudiant(Etudiant *liste, int *taille, Etudiant etudiant) {
    if (*taille < 20) {
        liste[*taille] = etudiant;
        (*taille)++;
        printf("Étudiant ajouté avec succès.\n");
    } else {
        printf("La liste est pleine. Impossible d'ajouter un nouvel étudiant.\n");
    }
}

// Fonction pour afficher la liste des étudiants sous forme de tableau
void afficherEtudiants(Etudiant *liste, int taille) {
    if (taille == 0) {
        printf("La liste des étudiants est vide.\n");
    } else {
        printf("%-15s %-15s %-15s %-10s %-20s\n", "Nom", "Prénom", "Date de naissance", "Promotion", "Formation");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < taille; i++) {
            printf("%-15s %-15s %-15s %-10d %-20s\n",
                   liste[i].nom,
                   liste[i].prenom,
                   liste[i].dateNaissance,
                   liste[i].promotion,
                   liste[i].formation);
        }
    }
}

int main() {
    Etudiant listeEtudiants[20];
    int tailleListe = 0;
    int choix;

    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Afficher la liste des étudiants\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                Etudiant etudiant;
                printf("Nom : ");
                scanf("%s", etudiant.nom);
                printf("Prénom : ");
                scanf("%s", etudiant.prenom);
                printf("Date de naissance (JJ/MM/AAAA) : ");
                scanf("%s", etudiant.dateNaissance);
                printf("Promotion : ");
                scanf("%d", &etudiant.promotion);
                while (etudiant.promotion < 0 || etudiant.promotion > 3000) {
                    printf("Promotion invalide. Veuillez réessayer : ");
                    scanf("%d", &etudiant.promotion);
                }
                printf("Formation : ");
                scanf("%s", etudiant.formation);

                ajouterEtudiant(listeEtudiants, &tailleListe, etudiant);
                break;
            }
            case 2:
                afficherEtudiants(listeEtudiants, tailleListe);
                break;
            case 3:
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }

    return 0;
}
