#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define INITIAL_EXPENSES_CAPACITY 10

typedef struct { // structure des personnes
    char name[MAX_NAME_LENGTH];
    int *depeses; 
    int num_depeses; 
    int total_depeses; 
} Person;

void init_person(Person *p, const char *name) { // création de personnage
    strncpy(p->name, name, MAX_NAME_LENGTH);
    p->depeses = malloc(INITIAL_EXPENSES_CAPACITY * sizeof(int)); // assigne une allocation pour les depenses
    p->num_depeses = 0;
    p->total_depeses = 0;
}

void add_depense(Person *p, int amount) {
    if (p->num_depeses % INITIAL_EXPENSES_CAPACITY == 0) {
        p->depeses = realloc(p->depeses, (p->num_depeses + INITIAL_EXPENSES_CAPACITY) * sizeof(int));
    }
    p->depeses[p->num_depeses++] = amount; 
    p->total_depeses += amount; 
}

void free_person(Person *p) {
    free(p->depeses);
}

void calculate_balances(Person *people, int num_people) {// calcul
    int total_spent = 0;

    for (int i = 0; i < num_people; i++) {
        total_spent += people[i].total_depeses;
    }

    double average = (double)total_spent / num_people; // calcule la moyenne depense/nombre de personne

    printf("Moyenne : %.6f\n", average);
    
    for (int i = 0; i < num_people; i++) {// boucle qui affiche les depenses par personne
        double balance = people[i].total_depeses - average;
        printf("Nom : %s, Depenses : ", people[i].name);
        
        for (int j = 0; j < people[i].num_depeses; j++) {
            printf("%d ", people[i].depeses[j]);
        }
        
        printf(", Total Depenses : %d, %s : %.6f\n", people[i].total_depeses,
            balance < 0 ? "doit" : "recoit", balance < 0 ? -balance : balance); 
    }
}

int main() { // toute les personnes enregistrer -- possibilité de rajouter des personnes
    const int num_people = 3; // ne pas oublier de changer le num +1 si on ajoute une personne
    Person people[num_people];

    init_person(&people[0], "Paul");
    add_depense(&people[0], 100);
    add_depense(&people[0], 450);

    init_person(&people[1], "Elsa");
    add_depense(&people[1], 200);
    add_depense(&people[1], 100);
    add_depense(&people[1], 300);
    add_depense(&people[1], 400);

    init_person(&people[2], "Marc");
    add_depense(&people[2], 300);


    calculate_balances(people, num_people); // recupere le num de people pour caculer leur balance

    for (int i = 0; i < num_people; i++) {
        free_person(&people[i]);// libere la memoire
    }

    return 0;
}
