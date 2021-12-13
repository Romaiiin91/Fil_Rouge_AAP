#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

//#define CLEAR2CONTINUE
#include "include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "avl.h"

int main(int argc, char ** argv) {
	T_avl root = NULL; 
	T_avlNode * pAux = NULL;


	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	outputPath = "output_Prog1";
	
	char *filename;
	
	filename = malloc(sizeof(filename));
	sprintf(filename, "%s",argv[1]); 
    

	//Ouverture Fichier

    FILE *in_file = fopen(filename, "r");
    int nb_ligne = 0;
    int ligne_max = atoi(argv[2]);

    struct stat sb;
    stat(filename, &sb);

    char *file_contents = malloc(sb.st_size);

    while (fscanf(in_file, "%[^\n] ", file_contents) != EOF && nb_ligne++ < ligne_max) {
        insertAVL(&root, file_contents);
        createDotAVL(root, "displayAVL");
        
    }

    fclose(in_file);
    printAVL(root,0);

	return 0;
}