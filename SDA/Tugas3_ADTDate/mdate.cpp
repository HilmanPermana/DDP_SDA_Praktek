/* Nama Program : mdate.cpp
	Deskripsi : Driver untuk menggunakan unit ADT Date
			yang ada di date.h dan date.cpp
*/

// Asumsi bulan genap 30 hari kecualir desember dan februari
// Bulan ganjil 31 hari

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "date.h"
using namespace std;

/* P R O G R A M   U T A M A   */
int main()
{
	char in;
	date D1, D2;
	 
		
		printf("=============================");
		printf("\n|          DATE 1           |");
		printf("\n=============================\n\n");
		//Input Date ke - 1
		BacaDate(&D1);
		CreateDate (&D1);
		
		system("pause");
		system("cls");
		printf ("\nHasil input Date ke - 1 : \n\n");
		PrintObj (D1);
		printf("\n=============================\n");
		DateBefore(D1);
		printf("\n=============================\n");
		NextDate(D1);
		printf("\n=============================\n\n\n\n\n");
		
		system("pause");
		system("cls");
		printf("=============================");
		printf("\n|          DATE 2           |");
		printf("\n=============================\n\n");
		//Input Date ke - 2
		BacaDate(&D2);
		CreateDate (&D2);
		
		system("pause");
		system("cls");
		printf ("\nHasil input Date ke - 2 : \n\n");
		PrintObj (D2);
		printf("\n=============================\n");
		DateBefore(D2);
		printf("\n=============================\n");
		NextDate(D2);
		printf("\n=============================\n\n");
		
		system("pause");
		system("cls");
		SelisihDate(D1,D2);
		
		
	return 0;
}

