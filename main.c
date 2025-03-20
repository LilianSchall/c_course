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
    for (int i = 0; i < n; i++)
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

int main(void)
{
    return 0;
}
