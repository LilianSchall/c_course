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
    return a / 2;
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
    int hauteur;
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
    r.hauteur = 5;

    /* On peut aussi creer un pointeur sur une structure */
    struct Rectangle *p = &r;

    /**
     * Pour acceder a une variable de la structure pointee, on utilise l'operateur
     * -> 
     */
    p->longueur = 20;
    p->hauteur = 10;

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

/**
 * Exercice 10: Ecrire une fonction qui prend en parametre un tableau d'entiers
 * et sa taille, et qui renvoie le minimum, le maximum, la moyenne et la mediane
 * des elements du tableau, en mettant a jour les valeurs pointees par les
 * pointeurs min, max, mean et median.
 *
 */
void exo10(int *tab, unsigned int taille, int *min, int *max, int *mean, int *median)
{
    // BEGIN FIXME
    // END FIXME
}

/**
 * Les chaines de caracteres:
 * En C, une chaine de caracteres est un tableau de caracteres termine par un
 * caractere nul ('\0'). Un caractere est un entier representant un caractere
 * ASCII. Une chaine de caracteres est donc un tableau d'entiers de type char.
 */
void example6(void)
{
    char chaine[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char chaine2[] = "Hello";

    /**
     * On peut aussi creer un tableau de chaines de caracteres
     */
    char *tab[2] = {"Hello", "World"};

    /**
     * On peut aussi creer une chaine de caracteres a partir d'un pointeur
     * Ces chaines de caracteres sont stockees dans la memoire en lecture seule:
     * on ne peut pas les modifier.
     */
    char *chaine3 = "Hello";

    /**
     * Pour les parcourir, on utilise une boucle for, en s'arretant quand on
     * rencontre le caractere nul (donc soit 0, soit '\0', c'est la meme chose,
     * car '\0' vaut litteralement 0).
     */
    for (int i = 0; chaine[i] != '\0'; i++)
    {
        printf("%c", chaine[i]);
    }
}

/**
 * Exercice 11: Ecrire une fonction qui prend en parametre une chaine de
 * caracteres et qui renvoie la longueur de la chaine.
 */
unsigned int exo11(char *chaine)
{
    int size = 0;
    // BEGIN FIXME
    // END FIXME
    return size;
}

/**
 * Exercice 12: Ecrire une fonction qui prend en parametre une chaine de
 * caracteres et qui renvoie 1 si la chaine est un palindrome, 0 sinon.
 * Un palindrome est une chaine de caracteres qui se lit de la meme maniere
 * dans les deux sens.
 * Exemple: "kayak" est un palindrome, "hello" ne l'est pas.
 */
int exo12(char *chaine)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * Exercice 13: Ecrire une fonction qui prend en parametre une chaine de
 * caracteres et qui modifie cette chaine pour que tous les caracteres 
 * soient en majuscule.
 * Exemple: "hello" -> "HELLO"
 * Exemple: "HeLlO" -> "HELLO"
 * A noter: on peut effectuer des operations sur les caracteres en C, comme
 * l'addition, la soustraction, la comparaison, etc.
 * Ainsi, pour mettre en majuscule un caractere, on peut d'abord verifier si ce
 * caractere est entre 'a' et 'z', puis lui soustraire 'a' et lui ajouter 'A'.
 */
void exo13(char *chaine)
{
    // BEGIN FIXME
    // END FIXME
}

/**
 * L'affichage et la saisie:
 * En C, on peut afficher des donnees a l'ecran en utilisant la fonction printf.
 * Cette fonction prend en parametre une chaine de caracteres, suivie de valeurs
 * a afficher.
 */
void example7(void)
{
    int a = 10;
    printf("La valeur de a est %d\n", a);
    /**
     * %d est un format de conversion qui permet d'afficher un entier.
     * Il existe d'autres formats de conversion, comme %f pour afficher un
     * nombre reel, %c pour afficher un caractere, %s pour afficher une chaine
     * de caracteres, etc.
     */

    /**
     * On peut aussi lire des donnees a partir du clavier en utilisant la
     * fonctions scanf. Cette fonction prend en parametre une chaine de
     * caracteres, suivie de pointeurs sur des variables ou stocker les valeurs.
     */
    int b;
    scanf("%d", &b);
    /**
     * Ici, on va lire un entier a partir du clavier et le stocker dans la
     * variable b.
     */
}

/**
 * Exercice 14: Ecrire une fonction qui prend en parametre un entier a et qui
 * affiche la valeur de a a l'ecran.
 */
void exo14(int a)
{
    // BEGIN FIXME
    // END FIXME
}

/**
 * Exercice 15: Ecrire une fonction qui prend en parametre un entier a et qui
 * renvoie la valeur lue a partir du clavier.
 */
int exo15(void)
{
    int a;
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * La recursivite:
 * La recursivite est une technique de programmation qui consiste a resoudre un
 * probleme en le decoupant en sous-problemes plus petits, jusqu'a arriver a un
 * probleme simple a resoudre. On appelle cette technique "diviser pour
 * regner".
 * En C, on peut ecrire des fonctions recursives, c'est a dire des fonctions qui
 * s'appellent elles-memes.
 * Attention: une fonction recursive doit avoir une condition d'arret, sinon
 * elle va s'appeler indefiniment et ca va planter.
 * Exemple: la factorielle d'un entier n est n * (n-1) * (n-2) * ... * 1
 * Exemple: la somme des n premiers entiers est n + (n-1) + (n-2) + ... + 1
 */
int example8_somme(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + example8_somme(n - 1);
}

/**
 * Exercice 16: Ecrire une fonction recursive qui prend en parametre un entier
 * n et qui renvoie la factorielle de n.
 * Exemple: exo16(5) = 120
 */
int exo16(int n)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * Exercice 17: Ecrire une fonction recursive representant la suite de
 * Fibonacci. La suite de Fibonacci est une suite de nombres definie par la
 * relation de recurrence suivante:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2)
 */
int exo17(int n)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * Exercice 18: Ecrire une fonction recursive qui prend en parametre un entier 
 * n et qui renvoie le n-ieme terme de la suite de Syracuse. La suite de
 * Syracuse est une suite de nombres definie par la relation de recurrence
 * suivante:
 * Si n est pair, alors n = n / 2
 * Si n est impair, alors n = 3n + 1
 * La suite s'arrete quand n vaut 1.
 * Exemple: exo18(5) = 16
 */
int exo18(int n)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * Exercice 19: Ecrire une fonction recursive qui prend en parametre un entier
 * n et qui renvoie le n-ieme terme de la suite de Collatz. La suite de Collatz
 * est une suite de nombres definie par la relation de recurrence suivante:
 * Si n est pair, alors n = n / 2
 * Si n est impair, alors n = 3n + 1
 * La suite s'arrete quand n vaut 1.
 * Exemple: exo19(5) = 16
 */
int exo19(int n)
{
    // BEGIN FIXME
    return 0;
    // END FIXME
}

/**
 * Exercice 20: Ecrire une fonction recursive qui prend en parametre un tableau
 * d'entiers, sa taille et un entier representant un index,
 * et qui trie le tableau en utilisant le tri a bulles.
 * Le tri a bulles est un algorithme de tri qui consiste a parcourir le tableau
 * en echangeant les elements adjacents si ils sont dans le mauvais ordre.
 * On repete cette operation jusqu'a ce qu'il n'y ait plus d'echange a faire.
 * Exemple: [5, 3, 8, 1, 2] -> [3, 5, 1, 2, 8] -> [3, 1, 2, 5, 8] -> ...
 * On pourra utiliser la fonction de l'exercice 6 pour echanger deux valeurs.
 */
void exo20(int *tab, unsigned int taille, unsigned int index)
{
    // BEGIN FIXME
    // END FIXME
}

/**
 * La structure de la memoire et l'allocation dynamique:
 * En C, la memoire est divisee en plusieurs parties:
 * - La pile: c'est la partie de la memoire qui stocke les variables locales
 *   des fonctions, les parametres des fonctions, les adresses de retour, etc.
 * - Le tas: c'est la partie de la memoire qui stocke les variables allouees
 *   dynamiquement, c'est a dire les variables qui sont allouees a l'execution
 *   du programme, et qui sont liberees a la fin de l'execution.
 * - Le segment de donnees: c'est la partie de la memoire qui stocke les
 *   variables globales et statiques.
 * - Le segment de code: c'est la partie de la memoire qui stocke le code du
 *   programme.
 *
 * En C, on peut allouer de la memoire dynamiquement en utilisant les fonctions
 * malloc, calloc, realloc et free. Ces fonctions sont definies dans la
 * bibliotheque stdlib.h. On va alors allouer de la memoire sur le tas.
 * - malloc: alloue un bloc de memoire de taille donnee
 * - calloc: alloue un bloc de memoire de taille donnee et l'initialise a 0
 * - realloc: realloue un bloc de memoire de taille donnee
 * - free: libere un bloc de memoire alloue dynamiquement
 * Il est important de liberer la memoire allouee dynamiquement, sinon on
 * risque de creer des fuites memoire.
 *
 * En C, on peut aussi allouer de la memoire pour un tableau en utilisant la
 * notation suivante:
 * int *tab = malloc(taille * sizeof(int));
 *
 * Explication: sizeof(int) renvoie la taille d'un entier en octets, et donc
 * taille * sizeof(int) renvoie la taille du tableau en octets.
 * On alloue donc un espace memoire de taille taille * sizeof(int) octets que
 * l'on va pouvoir parcourir comme un tableau d'entiers.
 *
 * On peut aussi allouer de la memoire pour une structure en utilisant la
 * notation suivante:
 * struct Maison *m = malloc(sizeof(struct Maison));
 *
 * Explication: sizeof(struct Maison) renvoie la taille de la structure Maison
 * en octets, et donc malloc(sizeof(struct Maison)) renvoie un pointeur sur une
 * structure Maison allouee dynamiquement.
 *
 * A la fin, il faut liberer la memoire de la maniere suivante:
 * free(tab);
 * free(m);
 */
void example9(void)
{
    int *tab = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        tab[i] = i;
    }
    /* Le tableau tab contient desormais les valeurs de 0 a 9 */
    free(tab);
    /**
     * A partir de la, le tableau tab n'existe plus, si on tente d'acceder a une
     * valeur de tab, notre programme plante (il segfault) 
     */

    struct Maison *m = malloc(sizeof(struct Maison));
    m->pieces = 5;
    m->etages = 2;
    free(m);
    /**
     * La structure m n'existe plus, si on tente d'acceder a un champ de m, notre
     * programme plante (il segfault)
     */
}


/**
 * Exercice 21: Ecrire une fonction qui prend en parametre un entier n et qui
 * renvoie un tableau d'entiers de taille n alloue dynamiquement.
 */
int *exo21(unsigned int n)
{
    // BEGIN FIXME
    return NULL;
    // END FIXME
}

/**
 * Exercice 22: Ecrire une fonction qui prend en parametre un tableau d'entiers
 * et sa taille, et qui renvoie un tableau d'entiers contenant les elements du
 * tableau initial dans l'ordre inverse.
 */
int *exo22(int *tab, unsigned int taille)
{
    // BEGIN FIXME
    return NULL;
    // END FIXME
}

/**
 * Exercice 23: Ecrire une fonction qui prend en parametre un tableau d'entiers
 * et sa taille, et qui renvoie un tableau d'entiers contenant les elements du
 * tableau initial tries en ordre croissant.
 */
int *exo23(int *tab, unsigned int taille)
{
    // BEGIN FIXME
    return NULL;
    // END FIXME
}

/**
 * Exercice 24: Ecrire une fonction qui prend en parametre une structure
 * rectangle, et qui a partir de deux points, renvoie un rectangle qui a pour
 * longueur la distance entre les deux points en x, et pour hauteur la distance entre
 * les deux points en y.
 */
struct Rectangle* exo24(struct Point p1, struct Point p2)
{
    // BEGIN FIXME
    return NULL;
    // END FIXME
}

/**
 * Le cours est termine ! Vous avez appris les bases du langage C, et vous etes
 * maintenant capable de resoudre des problemes simples en C.
 */

/** 
 * A partir de la, ne pas prendre compte du code suivant, il s'agit de tests
 * unitaires pour verifier la validite des fonctions ecrites.
 */

TEST_CASE(test_exo1)
{
    ASSERT_EQUALS_INT(2, exo1(), "exo1()");
}
END_TEST_CASE

TEST_CASE(test_exo2)
{
    ASSERT_EQUALS_INT(5, exo2(2, 3), "exo2(2, 3)");
    ASSERT_EQUALS_INT(7, exo2(4, 3), "exo2(4, 3)");
    ASSERT_EQUALS_INT(9, exo2(8, 1), "exo2(8, 1)");
}
END_TEST_CASE

TEST_CASE(test_exo3)
{
    ASSERT_EQUALS_INT(1, exo3(2, 0), "exo3(2, 0)");
    ASSERT_EQUALS_INT(8, exo3(2, 3), "exo3(2, 3)");
    ASSERT_EQUALS_INT(1024, exo3(2, 10), "exo3(2, 10)");
    ASSERT_EQUALS_INT(65536, exo3(2, 16), "exo3(2, 16)");
}
END_TEST_CASE

TEST_CASE(test_exo4)
{
    ASSERT_EQUALS_INT(1, exo4(2, 0), "exo4(2, 0)");
    ASSERT_EQUALS_INT(8, exo4(2, 3), "exo4(2, 3)");
    ASSERT_EQUALS_INT(1024, exo4(2, 10), "exo4(2, 10)");
    ASSERT_EQUALS_INT(65536, exo4(2, 16), "exo4(2, 16)");
}
END_TEST_CASE

TEST_CASE(test_exo5)
{
    int b = 0;
    exo5(5, &b);
    ASSERT_EQUALS_INT(5, b, "exo5(5, &b)");
    exo5(8, &b);
    ASSERT_EQUALS_INT(8, b, "exo5(8, &b)");
}
END_TEST_CASE

TEST_CASE(test_exo6)
{
    long a = 3, b = 18;
    exo6(&a, &b);
    ASSERT_EQUALS_INT(18, a, "exo6(&a, &b), test a");
    ASSERT_EQUALS_INT(3, b, "exo6(&a, &b), test b");
    exo6(&a, &b);
    ASSERT_EQUALS_INT(3, a, "exo6(&a, &b), test a");
    ASSERT_EQUALS_INT(18, b, "exo6(&a, &b), test b");
}
END_TEST_CASE

TEST_CASE(test_exo7)
{
    struct Maison m;

    m.pieces = 5;
    m.etages = 2;
    ASSERT_EQUALS_INT(5, exo7(m), "exo7(m)");

    m.pieces = 10;
    m.etages = 3;
    ASSERT_EQUALS_INT(10, exo7(m), "exo7(m)");
}
END_TEST_CASE

TEST_CASE(test_exo8)
{
    struct Maison m;

    m.pieces = 5;
    m.etages = 2;
    exo8(&m);
    ASSERT_EQUALS_INT(1, m.pieces, "exo8(&m), test pieces");
    ASSERT_EQUALS_INT(2, m.etages, "exo8(&m), test etages");

    m.pieces = 10;
    m.etages = 3;
    exo8(&m);
    ASSERT_EQUALS_INT(1, m.pieces, "exo8(&m), test pieces");
    ASSERT_EQUALS_INT(3, m.etages, "exo8(&m), test etages");
}
END_TEST_CASE

TEST_CASE(test_exo9)
{
    int tab1[] = {1, 2, 3, 4, 5};
    ASSERT_EQUALS_INT(15, exo9(tab1, 5), "exo9(tab1, 5)");

    int tab2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQUALS_INT(55, exo9(tab2, 10), "exo9(tab2, 10)");
}
END_TEST_CASE

TEST_CASE(test_exo10)
{
    int tab1[] = {1, 2, 3, 4, 5};
    int min, max, mean, median;
    exo10(tab1, 5, &min, &max, &mean, &median);
    ASSERT_EQUALS_INT(1, min, "exo10(tab1, 5, &min, &max, &mean, &median), test min");
    ASSERT_EQUALS_INT(5, max, "exo10(tab1, 5, &min, &max, &mean, &median), test max");
    ASSERT_EQUALS_INT(3, mean, "exo10(tab1, 5, &min, &max, &mean, &median), test mean");
    ASSERT_EQUALS_INT(3, median, "exo10(tab1, 5, &min, &max, &mean, &median), test median");

    int tab2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    exo10(tab2, 10, &min, &max, &mean, &median);
    ASSERT_EQUALS_INT(1, min, "exo10(tab2, 10, &min, &max, &mean, &median), test min");
    ASSERT_EQUALS_INT(10, max, "exo10(tab2, 10, &min, &max, &mean, &median), test max");
    ASSERT_EQUALS_INT(5, mean, "exo10(tab2, 10, &min, &max, &mean, &median), test mean");
    ASSERT_EQUALS_INT(5, median, "exo10(tab2, 10, &min, &max, &mean, &median), test median");
}
END_TEST_CASE

TEST_CASE(test_exo11)
{
    ASSERT_EQUALS_INT(5, exo11("Hello"), "exo11(\"Hello\")");
    ASSERT_EQUALS_INT(0, exo11(""), "exo11(\"\")");
    ASSERT_EQUALS_INT(10, exo11("HelloWorld"), "exo11(\"HelloWorld\")");
}
END_TEST_CASE

TEST_CASE(test_exo12)
{
    ASSERT_EQUALS_INT(1, exo12("kayak"), "exo12(\"kayak\")");
    ASSERT_EQUALS_INT(0, exo12("hello"), "exo12(\"hello\")");
    ASSERT_EQUALS_INT(1, exo12("radar"), "exo12(\"radar\")");
    ASSERT_EQUALS_INT(1, exo12("hannah"), "exo12(\"hannah\")");
}
END_TEST_CASE

TEST_CASE(test_exo13)
{
    char chaine1[] = "hello";
    exo13(chaine1);
    ASSERT_EQUALS_STRING("HELLO", chaine1, "exo13(\"hello\")");

    char chaine2[] = "HeLlO";
    exo13(chaine2);
    ASSERT_EQUALS_STRING("HELLO", chaine2, "exo13(\"HeLlO\")");

    char chaine3[] = "36129";
    exo13(chaine3);
    ASSERT_EQUALS_STRING("36129", chaine3, "exo13(\"36129\")");
}
END_TEST_CASE

TEST_CASE(test_exo14)
{
    exo14(5);
    ASSERT_STDOUT("5\n", exo14(5), "exo14(5)");
}
END_TEST_CASE

// skip test_exo15 because it requires user input

TEST_CASE(test_exo16)
{
    ASSERT_EQUALS_INT(120, exo16(5), "exo16(5)");
    ASSERT_EQUALS_INT(720, exo16(6), "exo16(6)");
    ASSERT_EQUALS_INT(5040, exo16(7), "exo16(7)");
}
END_TEST_CASE

TEST_CASE(test_exo17)
{
    ASSERT_EQUALS_INT(0, exo17(0), "exo17(0)");
    ASSERT_EQUALS_INT(1, exo17(1), "exo17(1)");
    ASSERT_EQUALS_INT(1, exo17(2), "exo17(2)");
    ASSERT_EQUALS_INT(2, exo17(3), "exo17(3)");
    ASSERT_EQUALS_INT(3, exo17(4), "exo17(4)");
    ASSERT_EQUALS_INT(5, exo17(5), "exo17(5)");
    ASSERT_EQUALS_INT(8, exo17(6), "exo17(6)");
    ASSERT_EQUALS_INT(13, exo17(7), "exo17(7)");
}
END_TEST_CASE

TEST_CASE(test_exo18)
{
    ASSERT_EQUALS_INT(1, exo18(1), "exo18(1)");
    ASSERT_EQUALS_INT(16, exo18(5), "exo18(5)");
    ASSERT_EQUALS_INT(22, exo18(7), "exo18(7)");
    ASSERT_EQUALS_INT(111, exo18(27), "exo18(27)");
}
END_TEST_CASE

TEST_CASE(test_exo19)
{
    ASSERT_EQUALS_INT(1, exo19(1), "exo19(1)");
    ASSERT_EQUALS_INT(16, exo19(5), "exo19(5)");
    ASSERT_EQUALS_INT(22, exo19(7), "exo19(7)");
    ASSERT_EQUALS_INT(111, exo19(27), "exo19(27)");
}
END_TEST_CASE

TEST_CASE(test_exo20)
{
    int tab1[] = {5, 3, 8, 1, 2};
    exo20(tab1, 5, 0);
    ASSERT_EQUALS_INT(1, tab1[0], "exo20(tab1, 5, 0), test 0");
    ASSERT_EQUALS_INT(2, tab1[1], "exo20(tab1, 5, 0), test 1");
    ASSERT_EQUALS_INT(3, tab1[2], "exo20(tab1, 5, 0), test 2");
    ASSERT_EQUALS_INT(5, tab1[3], "exo20(tab1, 5, 0), test 3");
    ASSERT_EQUALS_INT(8, tab1[4], "exo20(tab1, 5, 0), test 4");

    int tab2[] = {5, 3, 8, 1, 2};
    exo20(tab2, 5, 1);
    ASSERT_EQUALS_INT(3, tab2[0], "exo20(tab2, 5, 1), test 0");
    ASSERT_EQUALS_INT(5, tab2[1], "exo20(tab2, 5, 1), test 1");
    ASSERT_EQUALS_INT(1, tab2[2], "exo20(tab2, 5, 1), test 2");
    ASSERT_EQUALS_INT(2, tab2[3], "exo20(tab2, 5, 1), test 3");
    ASSERT_EQUALS_INT(8, tab2[4], "exo20(tab2, 5, 1), test 4");
}
END_TEST_CASE

TEST_CASE(test_exo21)
{
    int *tab1 = exo21(5);
    ASSERT_NOT_NULL(tab1, "exo21(5)");
    free(tab1);

    int *tab2 = exo21(10);
    ASSERT_NOT_NULL(tab2, "exo21(10)");
    free(tab2);
}
END_TEST_CASE

TEST_CASE(test_exo22)
{
    int tab1[] = {1, 2, 3, 4, 5};
    int *tab2 = exo22(tab1, 5);
    ASSERT_NOT_NULL(tab2, "exo22(tab1, 5)");
    ASSERT_EQUALS_INT(5, tab2[0], "exo22(tab1, 5), test 0");
    ASSERT_EQUALS_INT(4, tab2[1], "exo22(tab1, 5), test 1");
    ASSERT_EQUALS_INT(3, tab2[2], "exo22(tab1, 5), test 2");
    ASSERT_EQUALS_INT(2, tab2[3], "exo22(tab1, 5), test 3");
    ASSERT_EQUALS_INT(1, tab2[4], "exo22(tab1, 5), test 4");
    free(tab2);

    int tab3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *tab4 = exo22(tab3, 10);
    ASSERT_NOT_NULL(tab4, "exo22(tab3, 10)");
    ASSERT_EQUALS_INT(10, tab4[0], "exo22(tab3, 10), test 0");
    ASSERT_EQUALS_INT(9, tab4[1], "exo22(tab3, 10), test 1");
    ASSERT_EQUALS_INT(8, tab4[2], "exo22(tab3, 10), test 2");
    ASSERT_EQUALS_INT(7, tab4[3], "exo22(tab3, 10), test 3");
    ASSERT_EQUALS_INT(6, tab4[4], "exo22(tab3, 10), test 4");
    ASSERT_EQUALS_INT(5, tab4[5], "exo22(tab3, 10), test 5");
    ASSERT_EQUALS_INT(4, tab4[6], "exo22(tab3, 10), test 6");
    ASSERT_EQUALS_INT(3, tab4[7], "exo22(tab3, 10), test 7");
    ASSERT_EQUALS_INT(2, tab4[8], "exo22(tab3, 10), test 8");
    ASSERT_EQUALS_INT(1, tab4[9], "exo22(tab3, 10), test 9");
    free(tab4);
}
END_TEST_CASE

TEST_CASE(test_exo23)
{
    int tab1[] = {5, 3, 8, 1, 2};
    int *tab2 = exo23(tab1, 5);
    ASSERT_NOT_NULL(tab2, "exo23(tab1, 5)");
    ASSERT_EQUALS_INT(1, tab2[0], "exo23(tab1, 5), test 0");
    ASSERT_EQUALS_INT(2, tab2[1], "exo23(tab1, 5), test 1");
    ASSERT_EQUALS_INT(3, tab2[2], "exo23(tab1, 5), test 2");
    ASSERT_EQUALS_INT(5, tab2[3], "exo23(tab1, 5), test 3");
    ASSERT_EQUALS_INT(8, tab2[4], "exo23(tab1, 5), test 4");
    free(tab2);

    int tab3[] = {5, 3, 8, 1, 2, 6, 4, 7, 9, 10};
    int *tab4 = exo23(tab3, 10);
    ASSERT_NOT_NULL(tab4, "exo23(tab3, 10)");
    ASSERT_EQUALS_INT(1, tab4[0], "exo23(tab3, 10), test 0");
    ASSERT_EQUALS_INT(2, tab4[1], "exo23(tab3, 10), test 1");
    ASSERT_EQUALS_INT(3, tab4[2], "exo23(tab3, 10), test 2");
    ASSERT_EQUALS_INT(4, tab4[3], "exo23(tab3, 10), test 3");
    ASSERT_EQUALS_INT(5, tab4[4], "exo23(tab3, 10), test 4");
    ASSERT_EQUALS_INT(6, tab4[5], "exo23(tab3, 10), test 5");
    ASSERT_EQUALS_INT(7, tab4[6], "exo23(tab3, 10), test 6");
    ASSERT_EQUALS_INT(8, tab4[7], "exo23(tab3, 10), test 7");
    ASSERT_EQUALS_INT(9, tab4[8], "exo23(tab3, 10), test 8");
    ASSERT_EQUALS_INT(10, tab4[9], "exo23(tab3, 10), test 9");
    free(tab4);
}
END_TEST_CASE

TEST_CASE(test_exo24)
{
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 4};
    struct Rectangle *r = exo24(p1, p2);
    ASSERT_NOT_NULL(r, "exo24(p1, p2)");
    ASSERT_EQUALS_INT(3, r->longueur, "exo24(p1, p2), test longueur");
    ASSERT_EQUALS_INT(4, r->hauteur, "exo24(p1, p2), test hauteur");
    free(r);
}
END_TEST_CASE

int main(void)
{
    RETURN_ON_FAILURE(test_exo1());
    RETURN_ON_FAILURE(test_exo2());
    RETURN_ON_FAILURE(test_exo3());
    RETURN_ON_FAILURE(test_exo4());
    RETURN_ON_FAILURE(test_exo5());
    RETURN_ON_FAILURE(test_exo6());
    RETURN_ON_FAILURE(test_exo7());
    RETURN_ON_FAILURE(test_exo8());
    RETURN_ON_FAILURE(test_exo9());
    RETURN_ON_FAILURE(test_exo10());
    RETURN_ON_FAILURE(test_exo11());
    RETURN_ON_FAILURE(test_exo12());
    RETURN_ON_FAILURE(test_exo13());
    RETURN_ON_FAILURE(test_exo14());
    RETURN_ON_FAILURE(test_exo16());
    RETURN_ON_FAILURE(test_exo17());
    RETURN_ON_FAILURE(test_exo18());
    RETURN_ON_FAILURE(test_exo19());
    RETURN_ON_FAILURE(test_exo20());
    RETURN_ON_FAILURE(test_exo21());
    RETURN_ON_FAILURE(test_exo22());
    RETURN_ON_FAILURE(test_exo23());
    RETURN_ON_FAILURE(test_exo24());
    return 0;
}

