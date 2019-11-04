#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#define T 50
#define CH 100

/* Définition d'une Liste */

typedef struct List

{

int value;

struct List *next;

}List;


/*---------------------------------------------------------------------*/

//Creation LL

List* cree_list(int value)
{
    List* li=(List*)malloc(sizeof(List));

    if(li==NULL)
    {
        printf("Pas de memoire");

        exit(1);
    }

    li->value=value;

    li->next=NULL;

    return li;
}



/*---------------------------------------------------------------------*/

//Libere une Liste

void free_list(List* li)
{
if(li != NULL)
{
free_list(li->next);

free(li);
}
}



/*---------------------------------------------------------------------*/

//Affiche une Liste

void print_list(List* li)
{
if(li != NULL)
{
printf("%d ", li->value);

print_list(li->next);
}
else

printf("\n");

}

/*---------------------------------------------------------------------*/

// Ajoute en fin de Liste

List* push_back_list(List* li, int x)
{
    if(list_length(li) > 2 )
    	return NULL;
    List* last = cree_list(x);

    List* first = li;

    if(li == NULL)
        return last;

    while(li->next  != NULL)
    	li=li->next;

    li->next=last;

    return  first;

}

/*---------------------------------------------------------------------*/

// Ajoute  en début de Liste

List* push_front_list(List* li, int x)
{
    List* first=cree_list(x);

    first->next=li;

    return first;

}


int list_length(List* li)
{
int size = 0;
if(li == NULL)
return NULL;

while(li != NULL)
{
size++;

li = li->next;
}

return size;

}
/*---------------------------------------------------------------------*/

//Fonction addition

List* ADD(List* li)
{
int s = 0;
	if(list_length(li) < 2 )
		return NULL;
    if(li == NULL)
    	return 0;

while(li != NULL)
{
s = s + li->value;

li = li->next;
}

free_list(li);

return  push_back_list(li,s);

}
/*---------------------------------------------------------------------*/

//Fonction multiplication

List* MUL(List* li)
{
int m = 1;
    if(list_length(li) < 2 )
return NULL;

if(li == NULL)

return 0;

while(li != NULL)
{
m = m * li->value;

li = li->next;
}

free_list(li);

return push_back_list(li,m);

}
/*---------------------------------------------------------------------*/

//Fonction soustraction

List* SUB(List* li)
{

int s = 0;
    if(list_length(li) < 2 )
return NULL;

    if(li == NULL)
    return 0;

while(li != NULL)
{
s = s - li->value;

li = li->next;

}

free_list(li);

return  push_back_list(li,s);
    }
/*---------------------------------------------------------------------*/

//Fonction Modulo

List* MOD(List* li)
{
    if(list_length(li) < 2 )
return NULL;
int s = 0;
if(li == NULL)
return 0;

while(li != NULL)
{
    s = s % li->value;

li = li->next;
}

free_list(li);

return push_back_list(li,s);


}
/*---------------------------------------------------------------------*/

//Fonction SWP

List* SWP(List* li)
{
    if(list_length(li) < 2 )
return NULL;

List* noeud;

List* b;

noeud = li;

b= li;

while (noeud->next != NULL)
{
    b=noeud;
noeud = noeud->next;

}

int a;

a = b->value;

b->value=noeud->value;

noeud->value = a;

return li;

}
/*---------------------------------------------------------------------*/

//Fonction Division
List* DIV(List* li)
{
if(list_length(li) < 2 )
return NULL;

int s=0;

while (li != NULL)
{
if(li->next != NULL)

s = s + li->value;

else if (li->value == 0)

return NULL;

else
s = s/li->value;

    li = li->next;

}

free_list(li);

return push_back_list(li,s);

}

int compare(char* chaine1, char* chaine2)

{
    int vrai = 0;
    while(*chaine1 != '\0' || *chaine2 != '\0')
    {
        if(*chaine1 != *chaine2)
        {
            vrai = 1;
        }

      chaine1++;

      chaine2++;

    }

    return vrai;

}



int main(){

int N;

int i,s;

char chaine[CH];

/***** Création de la liste ********/

List* noeud;
       // printf("Entrez nombre instructions\n");
   scanf("%d", &N);

   strcpy(chaine,"");

   for (int i = 0; i < N; i++) {

       char instruction[T];
           // printf("Entrez instructions\n");
       scanf("%s", instruction);

    if(compare(instruction,"ADD") == 0){
       	noeud = ADD(noeud);

       }else if(compare(instruction,"MUL") == 0){

       	noeud = MUL(noeud);

       }else if(compare(instruction,"SUB") == 0){

       	noeud = SUB(noeud);

       }else if(compare(instruction,"MOD") == 0){

       	noeud = MOD(noeud);

       }else if(compare(instruction,"SWP") == 0){

       	noeud = SWP(noeud);

       }else if(compare(instruction,"DIV") == 0){

       	noeud = DIV(noeud);

       }else{

       	int nombre = atoi(instruction);
       	noeud = push_back_list(noeud, nombre) ;
       }

      strcat(chaine,instruction);

     strcat(chaine," ");
   }

 printf("Entrée\n");

   printf(" %d \n",N);

  printf("%s  \n ",chaine);

   printf(" Sortie \n");
         if(noeud == NULL)
   	printf("ERROR");
    else
   print_list(noeud);


}

