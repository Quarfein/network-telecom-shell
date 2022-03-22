/* Petite fonction qui affiche une signature de notre shell si la commande rtshell est tapée */
#include <stdio.h>
#define VERSION "0.2.1"
#define LOGO "______ _____   _          _ _\n| ___ \\_   _| | |        | | |\n| |_/ / | |___| |__   ___| | |\n|    /  | / __| '_ \\ / _ \\ | |\n| |\\ \\  | \\__ \\ | | |  __/ | |\n\\_| \\_| \\_/___/_| |_|\\___|_|_|" //C'est de l'ASCII art, faites moi confiance
#define DESCRIPTION "RTshell Copyright (C) 2022 Département Réseaux et Télécommunications, IUT Nice Côte D'Azur."
#define ETUDIANT "Étudiants ayant travaillé sur ce projet : ACHBAIRY Akim, BOUKADIDA Latifa, JUST Maxime, KOUIDRI Yanis, TRANVOUEZ Evan."
#define APROPOS "Shell résulant d'un projet scolaire étalé sur 3 semestres." 
#define GARANTIE "Il n'offre ABSOLUMENT AUCUNE GARANTIE."

void signature(){
    printf("%s   ",LOGO);
    printf("(v%s)\n\n", VERSION);
    printf("%s\n",DESCRIPTION);
    printf("%s\n",APROPOS);
    printf("%s\n",ETUDIANT);
    printf("%s\n\n",GARANTIE);
}
