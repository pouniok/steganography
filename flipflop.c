#include <stdio.h>

/**
 * Transformation d'un flux binaire en utilisant les T Flip Flop
 *
 * Fonctionnement : 
 * On enregistre un état du tff (0 par défaut), et chaque fois qu'un bit à 1
 * est lu, on change l'état de la variable. On écrit après chaque lecture l'état
 * courant du tff pour avoir la valeur décryptée.
 *
 * Par simplicité le flux est d'abord converti en chaine de caractères de 0 et de 1.
 *
 * La lecture des données se fait via l'entrée standard, ce qui permet de pipe le programme :
 * <pre>
 * cat file.bin | binarystring | rev | flipflop | bin2ascii
 * </pre>
 */
int main() {
    int byte; // Caractère en cours de lecture (0 ou 1)
    int Q = '0'; // Etat du flip flop

    // Lecture des octets depuis stdin
    while ((byte = getchar()) != EOF) {
        // On inverse l'état du flip flop quand on lit un 1
        if (byte == '1') {
            Q = Q == '0' ? '1' : '0';
        }

        putchar(Q);
    }

    return 0;
}
