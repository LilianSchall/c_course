#include "helper.h"

/**
 * Bienvenue sur ce cours recapitulatif de tout ce qu'il faut savoir en C.
 * Ce cours a pour objectif d'expliquer de A a Z tous les concepts techniques
 * du langage C. La liste des concepts abordes est la suivante :
 * - Les types de donnees
 * - Les fonctions et les mots clefs
 * - L'espace memoire et les pointeurs
 * - Les structures
 * - Les tableaux
 * - Les chaines de caracteres
 * - l'affichage et la saisie
 * - La recursivite
 * - La structure de la memoire et l'allocation dynamique
 *
 *
 * Afin d'expliquer au mieux tous ces concepts, une serie d'exercices a ete mis
 * en place. Pour chaque exercice, un couple de balise "BEGIN FIXME" et 
 * "END FIXME" est present. Il s'agit de la zone de code a completer pour
 * resoudre l'exercice. Pour chaque exercice, un ou plusieurs tests unitaires 
 * sont presents dans le fichier. Les tests sont effectuees de maniere
 * sequentielles et automatiques. Vous ne pouvez passer au test suivant que si
 * le test precedent est valide.
 *
 * Pret ? C'est parti !
 */


/**
 * Les octets, les bits et les formats de representation de donnees:
 * En informatique, les donnees sont stockees sous forme de bits. Un bit est
 * l'unite de base de l'information en informatique. Un bit peut prendre deux
 * valeurs: 0 ou 1 - c'est la base 2. Un octet est un groupe de 8 bits. 
 * Un octet peut donc prendre 2^8 = 256 valeurs differentes.
 *
 * Avec une serie de bits, on peut representer des nombres entiers, 
 * des nombres reels, des caracteres, etc.
 * Pour les nombres entiers, on peut soit les representer signes ou non signes,
 * dans ce cas le bit de poids fort (le bit le plus a gauche) est utilise pour
 * le signe. Ainsi, une meme serie de bits peut representer deux nombres selon
 * le format de representation choisi.
 * Example: 
 * 1010 = 10 car 1*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 10
 * Mais 1010 = -6 car 15 - 1*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = -6
 *
 * Generalement, quand on souhaite representer de maniere plus compacte les
 * series de bits, on choisit le format hexadecimale (base 16, de 0 a F).
 * Ainsi, 1010 en binaire = A en hexadecimal, 10 en decimal non signee
 * et -6 en decimal signee.
 *
 * Les types de donnees:
 *
 * En C, il existe plusieurs types de donnees: les types primitifs et les types
 * composes. Les types primitifs sont les types de donnees de base du langage C.
 * Les types composes sont des types de donnees qui sont construits a partir de
 * types primitifs. Les types primitifs sont les suivants:
 * - char: un octet signe
 * - short: un entier signe court (2 octets)
 * - int: un entier signe (4 octets)
 * - long: un entier signe long (8 octets)
 * - float: un nombre reel simple precision (4 octets)
 * - double: un nombre reel double precision (8 octets)
 * 
 * Il y a aussi le type void, qui est un type speciale: il represente le vide,
 * l'absence de valeur. Il est utilise pour definir des fonctions qui ne
 * retournent pas de valeur, ou qui ne prennent pas de parametre.
 *
 * En clair, le format de representation determine donc la **maniere**
 * dont on souhaite **interpreter la donnee**, ainsi: on pourrait tres bien
 * interpreter 0x61756465 comme "aude" si on lisait une lettre par octet,
 * ou "1635083365" si on lisait un entier signe sur 4 octets...
 */

/*
 * Les fonctions et les mots clefs:
 * En C, une fonction est un bloc de code qui effectue une tache specifique.
 * Une fonction est composee de:
 * - un type de retour: le type de donnee que la fonction retourne (void si
 *   pas de retour)
 * - un nom: le nom de la fonction
 * - des parametres: les valeurs que la fonction prend en entree (peut etre
 *   vide)
 * Voici un premier exemple de fonction: Elle renvoie un entier (int) et ne
 * prend pas de parametre. On peut aussi mettre void a la place de rien.
 */
int example1()
{
    /**
     * Nous voici dans le corps de la fonction. Ici, on peut ecrire du code
     * afin d'operer des actions sur les donnees.
     */

    /* Pour definir une variable, on utilise le type de donnee suivi du nom */
    int a;

    /* Pour affecter une valeur a une variable, on utilise le signe = */
    a = 1;

    /* On peut aussi definir et affecter une variable en meme temps */
    int b = 2;

    /**
     * Sur les types primitifs, on peut effectuer des operations en C,
     * comme l'addition (+), la soustraction (-), la multiplication (*), la
     * division (/), le modulo (%), l'incrementation (++) et la decrementation
     * (--).
     * On peut aussi effectuer des operations logiques, comme l'ET (&&), le OU
     * (||), le NON (!), la comparaison (==, !=, <, >, <=, >=). 
     */

    a = b + 1; /* a vaut 3 */
    a = b * b; /* a vaut 4 */
    a = a / a; /* a vaut 1 */
    a *= 4; /* a vaut 4 */
    a++; /* a vaut 5 */
    a--; /* a vaut 4 */
    ++a; /* a vaut 5 */
    --a; /* a vaut 4 */

    /**
     * On peut effectuer des operations de maniere conditionnels en C,
     * au travers des mots-clefs de conditions: if, else if, else.
     */
    if (a == 4)
    {
        /* Si a vaut 4, on execute ce bloc de code */
        b = 10;
    }
    else if (a == 5)
    {
        /* Sinon, si a vaut 5, on execute ce bloc de code */
        b = 20;
    }
    else
    {
        /* Sinon, on execute ce bloc de code */
        b = 30;
    }

    /**
     * On peut aussi effectuer des operations de maniere iterative en C,
     * au travers des mots-clefs de boucles: for, while, do while.
     */

    /** La boucle for est une boucle qui s'execute un nombre de fois selon une
     * condition. Elle est composee de trois parties: l'initialisation, 
     * la condition d'arret et l'incrementation.
     * for (initialisation; condition; incrementation)
     * Dans l'exemple suivant, on initialise la variable i a 0, on execute le
     * bloc de code tant que i est inferieur a 10, et on incremente i a chaque
     * iteration.
     * On pourrait tout a fait faire autre chose qu'incrementer, comme par
     * exemple multiplier i par 2 a chaque iteration.
     */
    for (int i = 0; i < 10; i++)
    {
        /* On execute ce bloc de code 10 fois */
        b += i;
    }
    /* b vaut 45 */

    /* La boucle while est une boucle qui s'execute tant qu'une condition est
     * vraie */
    while (b < 50)
    {
        /* On execute ce bloc de code tant que b est inferieur a 50 */
        b++;
    }
    /* On aura donc executer 5 fois l'operation b++.*/

    /* La boucle do while est une boucle qui s'execute au moins une fois, puis
     * tant qu'une condition est vraie */

    do
    {
        /* On execute ce bloc de code au moins une fois */
        b++;
    } while (b < 50);
    /* On aura donc b = 51 */

    /**
     * On peut aussi controler le flux d'execution du programme en C, au travers
     * des mots-clefs de controle de flux: break, continue, return.
     */

    b = 0;
    if (b != 0)
    {
        /* Si b est different de 0, on sort de la fonction */
        /**
         * Dans le cas d'une fonction de type void, on peut tout de meme appeler
         * le mot clef return, mais sans valeur.
         */
        return 0;
    }

    /* Le mot clef break permet de sortir d'une boucle */
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        b += i;
    }
    /**
     * b vaut 10, car on aura fait que 5 tours de boucle: 0 + 1 + 2 + 3 + 4 = 10
     */

    /**
     * Pour renvoyer une valeur, on utilise le mot clef return
     * Une fonction dont le type de retour n'est pas void doit 
     * obligatoirement renvoyer une valeur
     */
    return b;
}

/** 
 * Exercice 1: Ecrire une fonction qui assigne la valeur 5 a la variable a,
 * puis, qui retourne le reste de la division euclidienne de a par 2.
 */
int exo1(void)
{
    // BEGIN FIXME
    int a = 0;
    // END FIXME
    return a;
}

/**
 * Exercice 2: Ecrire une fonction qui prend en parametre deux entiers a et b,
 * et qui renvoie la somme de ces deux entiers.
 */
int exo2(int a, int b)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * Exercice 3: Ecrire une fonction qui prend en parametre un entier a et qui
 * renvoie la n-ieme puissance de cet entier.
 * On part du principe que a != 0 et n >= 0 (c'est ce que veut dire unsigned
 * int). 
 * Exemple: exo3(2, 3) = 8
 * Exemple: exo3(2, 0) = 1
 */
int exo3(int a, unsigned int n)
{
    int result = 1;
    for (unsigned int i = 0; i < n; i++)
    {
        // BEGIN FIXME
        // END FIXME
    }
    return result;
}

/**
 * Exercice 4: La meme chose que l'exercice 3, mais avec while.
 */
int exo4(int a, unsigned int n)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * L'espace memoire et les pointeurs:
 * Dans un ordinateur, la memoire est un espace de stockage de donnees 2
 * dimensions. La dimensions x est l'adresse memoire, et la dimension y est la
 * taille de mot. Sur les ordinateurs moderne, la taille de mot est de 32 bits.
 * Maintenant, a chaque allocation de memoire que l'on fait, on reserve une
 * adresse memoire dans l'espace memoire. 
 * Cette adresse est represente par un pointeur en C: en effet, un pointeur est
 * une variable qui stocke l'adresse memoire d'une autre variable. Comme les
 * pointeurs sont des variables, ils ont aussi une adresse memoire, et donc on
 * peut faire des pointeurs de pointeurs.
 */
void example2(void)
{
    /* Prenons par exemple cet entier */
    int entier = 10;

    /* Si je souhaite obtenir l'adresse memoire de cette variable, j'utilise
     * l'operateur & */
    int *pointeur = &entier;

    /* Si je souhaite obtenir la valeur de la variable pointee par le pointeur,
     * j'utilise l'operateur * */
    int valeur = *pointeur;

    /* Ici, valeur = entier = 10 */
    /** 
     * Je peux aussi modifier la valeur de la variable pointee par le pointeur,
     * c'est a dire modifier la valeur de la variable "entier".
     */
    *pointeur = 20;
    /* Ici, entier = 20, mais valeur vaut encore 10 */
}

/**
 * Supposons que je veuille qu'une fonction modifie la valeur d'une variable
 * sans la retourner. Je vais alors donner l'adresse de la variable que je
 * souhaite modifier a la fonction.
 */
void elever_au_carre(int *a)
{
    *a = *a * *a;
}

void example3(void)
{
    int a = 5;
    elever_au_carre(&a);
    /* Ici, a = 25 */
}

/**
 * Exercice 5: Ecrire une fonction qui prend en parametre un entier a et un
 * pointeur sur un entier b, et qui affecte la valeur de a a la variable pointee
 * par b.
 */
void exo5(int a, int *b)
{
    // BEGIN FIXME
    // END FIXME
}

/**
 * Exercice 6: Ecrire une fonction qui echange les deux valeurs de deux entiers
 * a et b.
 * Exemple: a = 5, b = 10 -> a = 10, b = 5
 */
void exo6(long *a, long *b)
{
    // BEGIN FIXME
    // END FIXME
}

/**
 * Les structures:
 * En C, une structure est un type de donnee compose qui permet de regrouper
 * plusieurs variables de types differents sous un meme nom. Une structure est
 * definie par le mot clef struct suivi du nom de la structure, puis des
 * variables qui la compose.
 */
struct Rectangle
{
    int longueur;
    int largeur;
};

/* On peut aussi creer une structure dans une structure */
struct Point
{
    int x;
    int y;
};
struct Carre
{
    struct Point p;
    int cote;
};

/* Mais aussi une structure qui stocke un ou plusieurs pointeurs */
struct Liste
{
    struct Liste *suivant;
    int valeur;
};

/**
 * On peut aussi renommer un type que l'on a cree avec le mot clef typedef
 * Ici, il faut mettre le nom du type que l'on veut renommer, et le nom que l'on
 * veut lui donner a la toute fin.
 */
typedef struct Liste UnidirectionalList;

/**
 * On peut aussi renommer un type de base. On pourra alors utiliser le mot clef
 * "int" ou le nouveau type "Entier" pour representer le meme type.
 */
typedef int Entier;

void example4(void)
{
    /* Pour creer une variable de type structure, on utilise le nom de la
     * structure suivi du nom de la variable */
    struct Rectangle r;

    /* Pour acceder a une variable de la structure, on utilise l'operateur . */
    r.longueur = 10;
    r.largeur = 5;

    /* On peut aussi creer un pointeur sur une structure */
    struct Rectangle *p = &r;

    /**
     * Pour acceder a une variable de la structure pointee, on utilise l'operateur
     * -> 
     */
    p->longueur = 20;
    p->largeur = 10;

    struct Carre c;
    c.p.x = 10;
    c.p.y = 5;
    c.cote = 10;

    struct Liste l1;
    UnidirectionalList l2; /* struct Liste */

    l1.suivant = &l2;
    l1.valeur = 10;
    l2.suivant = NULL;
    l2.valeur = 20;
}

/**
 * Exercice 7: Definir une structure nommee Maison qui contient les champs:
 * - un entier pour le nombre de pieces
 * - un entier pour le nombre d'etages
 *   Puis, ecrire une fonction qui prend en parametre une maison et qui renvoie
 *   le nombre total de pieces de la maison.
 */
struct Maison
{
    // BEGIN FIXME
    FIX_ME_MAISON
    // END FIXME
};

int exo7(struct Maison m)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * Exercice 8: Cette fois-ci, la fonction prend en parametre un pointeur sur
 * une maison et modifier le nombre de pieces, pour qu'il y ait autant de
 * pieces, que la moitie du nombre d'etages.
 * Example: si la maison a 4 etages, elle doit avoir 2 pieces.
 */
void exo8(struct Maison *m)
{
    // BEGIN FIXME
    // END FIXME
}

/**
 * Les tableaux:
 * En C, un tableau est une plage memoire qui permet de stocker plusieurs
 * valeurs de meme type sous un meme nom. Un tableau est defini par le type de
 * donnee suivi du nom du tableau, puis de la taille du tableau entre crochets.
 */
void example5(void)
{
    int tab[10];
    int taille = 10;

    for (int i = 0; i < taille; i++)
    {
        tab[i] = i;
    }
    /* Le tableau tab contient desormais les valeurs de 0 a 9 */

    /* On peut aussi creer un tableau de pointeurs */
    struct Maison* quartier[2];

    struct Maison m1;
    m1.pieces = 5;
    m1.etages = 2;

    struct Maison m2;
    m2.pieces = 10;
    m2.etages = 3;

    quartier[0] = &m1;
    quartier[1] = &m2;

    /**
     * Si on souhaite acceder le nombre de pieces de la maison m1, on va alors
     * effectuer l'operation suivante:
     */
    int nb_pieces = quartier[0]->pieces;

    /**
     * On peut aussi creer un tableau de structures
     */
    struct Maison maisons[2];
    maisons[0].pieces = 5;
    maisons[0].etages = 2;
    maisons[1].pieces = 10;
    maisons[1].etages = 3;
    /**
     * Dans ce cas, chaque case du tableau contient une structure Maison, ce
     * qui est different d'avoir un tableau de pointeurs sur des structures.
     * La raison est que si on souhaite stocker une case du tableau dans une
     * variable, on va stocker une copie de la case, et non l'adresse de la
     * case. La case et la variable vont donc etre differentes, des lors que
     * l'une ou l'autre est modifiee.
     */
    struct Maison m = maisons[0];
    m.pieces = 10;
    /**
     * Ici m.pieces vaut 10, mais maisons[0].pieces vaut 5.
     */
}

/**
 * Exercice 9: Ecrire une fonction qui prend en parametre un tableau d'entiers
 * et sa taille, et qui renvoie la somme de tous les elements du tableau.
 */
int exo9(int *tab, unsigned int taille)
{
    int sum = 0;
    // BEGIN FIXME
    // END FIXME
    return sum;
}


int main(void)
{
    return 0;
}
