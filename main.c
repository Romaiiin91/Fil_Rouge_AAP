#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "avl.h"

int main(int argc, char ** argv) {
	
	T_avl root = NULL; 
	T_avlNode * pAux = NULL;

	T_elt srch; 
	

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	
	outputPath = "output";
	
	// 8, 11, 16, 5, 7, 14, 6, 1, 3, 10, 12,16
	insertAVL(&root, 8);
	insertAVL(&root, 11);
	insertAVL(&root, 16);
	insertAVL(&root, 5);
	insertAVL(&root, 7);
	insertAVL(&root, 14);
	insertAVL(&root, 6);
	insertAVL(&root, 1);
	insertAVL(&root, 3);
	insertAVL(&root, 10);
	insertAVL(&root, 12);

	printAVL(root, 0); 


	srch = 16;
	pAux = searchAVL_it(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	pAux = searchAVL_rec(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	
	if (root==NULL) printf("null");
	printf("hauteur : %d\n",heightAVL(root));
	printf("nb noeuds : %d\n",nbNodesAVL(root));

	
	createDotAVL(root, "root");

	return 0;
}







