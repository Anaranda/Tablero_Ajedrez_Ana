#pragma once
#include "ListaPeones.h"
#include "ListaFichas.h"
#include "Ficha.h"
#include <stdio.h>
#include "Mouse.h"
#include "ETSIDI.h"


#define M 8 //dimensi�n del tablero
//dimension tablero
#define PX_X 800
#define PX_Y 800

using namespace std;


class Tablero
{
private:
	//Ficha tablero[M][M];
	//ListaPeones peones;
	ListaFichas fichas;

public:
	//NUEVO/////////////////////////////////
	Color turno=BLANCO; // es el del color de ficha, en este caso solo podr� ser o ROJO o BLANCO
	Ficha* ficha_Selec = NULL;
	enum  Estado { ESPERANDO_1CLICK, ESPERANDO_2CLICK }; // los dos estados en los que puede estar el tablero a la hora de jugar
	Estado estado;
	//////////////////////////////////////////////

	/*enum Turno { blancas, rojas };
	Turno turno;
	bool seleccionada;
	int pos[2];
	int pos_verde[2];*/
	Tablero();
	//void dibuja();
	void Inicializa();
	void DibujaTablero();
	void TexturaTablero();
	/*int GetX();
	int GetY();*/
	void SelecFicha(int button, int state, int mouseX, int mouseY);
	bool reglaCasillaNegra(int i, int j);
	//bool seleccionValida(int i, int j);

	//NUEVO////////////////
	void paso_a_indices(int button, int state, int mouseX, int mouseY, int* indices);
	bool ficha_mia(Ficha* ficha); //en un principio no le paso el color porque el turno corresponde con el color de tu ficha;
	void cambio_turno();
	void cambio_estado();
	bool dentro_de_tablero(int i, int j);
	
	bool movimiento_simple(int posX, int posY, int posVerdeX, int posVerdeY);
	bool movimiento_comida_simple(int posX,int posY, int posVerdeX, int posVerdeY);//similar a movimiento_simple pero para comer
	bool direccion_correcta(int posX, int posY, int posVerdeX, int posVerdeY);

	bool muevo_a_vacio_simple(int posX, int posY, int posVerdeX, int posVerdeY);
	bool muevo_y_como(int posX, int posY, int posVerdeX, int posVerdeY);//movimiento de salto de ficha simple

	bool fin_de_juego(Color turno);
};

