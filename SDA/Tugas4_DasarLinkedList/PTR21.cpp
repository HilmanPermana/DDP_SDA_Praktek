#include<stdlib.h> 
#include<stdio.h>


/*Definisi akses komponen type, standard kuliah Algoritma dan pemrograman*/ 
#define info(P) (P)->info
#define next(P) (P)->next 
#define Nil NULL

/* Definisi TYPE global (sebenarnya untuk soal ini tidak perlu global) */
/* Element list linier */ 
typedef int infotype;
typedef struct tElmtlist *address; 
typedef struct tElmtlist {
	infotype info; 
	address next;
} ElmtList;

/* Program Utama */ 
int main()
{
	/* kamus */ 
		address First; 
		address P, Q,add;
	
	/* program */
	
	/* Create list kosong */ 
		First = Nil;
	/* Alokasi, insert as first elemen */
		P = (address) malloc(sizeof (ElmtList)); 
		info(P) = 10;
		next(P) = Nil;
		First = P;
	
	/* Alokasi, insert as first elemen */
		Q = (address) malloc(sizeof (ElmtList)); 
		info(Q) = 20;
		next(Q) = Nil; 
		next(Q) = First; 
		First = Q;
		
		/* Alokasi, insert as first elemen */
		P = (address) malloc(sizeof (ElmtList)); 
		info(P) = 30;
		next(P) = Nil; 
		next(P) = First; 
		First = P;
		
		/*Alokasi, insert between elemen*/
		add=(address) malloc(sizeof(ElmtList));
		info(add) = 25;
		next(add) = Nil;
		next(add) = Q;
		next(P) = add;
		
		//dealloc
		P = Nil;
		Q = Nil;
		add = Nil;
		
		free(P);
		free(Q);
		free(add);
		
		printf("%d \n", info(next(next(next(First)))));

return 0;
}

