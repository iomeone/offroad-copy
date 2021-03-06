//*************** KONZOLE *****************
//* funkce pro vystup textu na obrazovku	*
//*			multiplatformnni implementace			*
//* 					Milan Timko 2007						*
//*					milantimko@seznam.cz					*
//*****************************************


/*
Offroad - 2008 Edition
Copyright (C) 2014  Milan Timko
http://www.milantimko.info

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/gpl-3.0.txt>.
*/


#include "konzole.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#define KONZOLE 0

const char PREFIX_CHYBA[] = "Error: ";
const char STATUSBAR_ELEMENT = '=';
const char STATUSBAR_ZACATEK = '[';
const char STATUSBAR_KONEC = ']';


void Vypis(char *text){
#if KONZOLE
	cout << text << endl;
#endif
}


void VypisStatusBar(char *nazev, int stav, int delka)
{
#if KONZOLE
  Cls();
  cout << nazev << " " << STATUSBAR_ZACATEK;
 	for (int i = 0; i < delka; i++)
 		if (i <= (int)((((float)stav) / 100.0) * ((float)delka)))
 			cout << STATUSBAR_ELEMENT;
 		else cout << " ";
	cout << STATUSBAR_KONEC << endl;
#endif
}



void Chyba(char *text)
{
#if KONZOLE
  cout << PREFIX_CHYBA << text << endl;
  #ifndef __unix__
  system("pause");
  #endif
#endif
  exit(1);
}



void Cls()
{
#if KONZOLE
	#ifdef __unix__
		system("clear");
	#else
		system("cls");
	#endif
#endif
}

