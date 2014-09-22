/*
 ============================================================================
 Name        : test.c
 Author      : José M. Martínez Ruiz
 Version     :
 Copyright   : copyright 2.014 Computerwizards Co.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 9 									//maximos carracteres del array monedas
#define MAXMON 15 									//maximas monedas definibles

struct currency{
	int cantidad;
	float valor;
	int val_imp;
	char sufijo[MAXCAR];
};

struct currency euros[] = { 						//Rgistro de todas las monedas y billetes de euro
		{0,50000,500,"Euros"},
		{0,20000,200,"Euros"},
		{0,10000,100,"Euros"},
		{0,5000,50,"Euros"},
		{0,2000,20,"Euros"},
		{0,1000,10,"Euros"},
		{0,500,5,"Euros"},
		{0,200,2,"Euros"},
		{0,100,1,"Euro"},
		{0,50,50,"Centimos"},
		{0,20,20,"Centimos"},
		{0,10,10,"Centimos"},
		{0,5,5,"Centimos"},
		{0,2,2,"Centimos"},
		{0,1,1,"Centimo"},
};

void imprimir (struct currency *);					// modulo de impresion extendida de monedas que sobran
void suma (struct currency *);						// modulo de incremento de cantidad en los registro de monedas
int diferencia (float x,double y); 					// modulo de resta
void impresion (float x, float y, int z); 			// modulo de impresion inicial
void modulo1(); 									// modulo principal de ejecucion
int monedas (int x, struct currency *);				// modulo para el numero minimo de monedas


int main(void) {
	modulo1();
	return EXIT_SUCCESS;
}
void suma (struct currency *ptrcurrency){
	ptrcurrency->cantidad=ptrcurrency->cantidad + 1;
}
void imprimir (struct currency *ptrcurrency){
int i;
	for (i=0; i<MAXMON; i++){
		if (ptrcurrency->cantidad !=0){
			printf("%d ",ptrcurrency->cantidad);
			if (ptrcurrency->cantidad >1)
				printf("monedas de ");
			else
				printf("moneda de ");

		printf("%d",ptrcurrency->val_imp);
		printf(" %s\n",ptrcurrency->sufijo);
		}
		ptrcurrency++;
	}
}
int diferencia (float moneda, double precio){
	return (int)(moneda*100) - (int)(precio*100);
}
void impresion (float moneda, float precio, int difer){
	float reg;
	reg = (difer/100.0);

	printf ("El cliente nos entrega %5.2f Euros y \nel precio de la entrada es de %4.2f Euros.\npor lo que le sobran %4.2f Euros.\n", moneda, precio, reg);

}
void modulo1(){
	float moneda = 1000;
	double precio = 7.2;
	int  difer;
	int num;
	struct currency *ptrcurrency;
	ptrcurrency = euros;
	difer = diferencia(moneda,precio);
	impresion(moneda,precio,difer);
	num = monedas(difer,euros);
	printf ("El numero de monedas y billetes total es de: %d\n",num);
	imprimir(euros);
}
int monedas (int difer, struct currency *ptrcurrency){
	int mon;
	int acumulado = 0;
	ptrcurrency = euros;
	while (difer != 0)
	{
		mon = ptrcurrency->valor;
		if (mon <= difer)
		{
			acumulado++;
			suma(ptrcurrency);
			difer = difer - mon;
		}
		else
			ptrcurrency++;
	}
	return acumulado;
}
