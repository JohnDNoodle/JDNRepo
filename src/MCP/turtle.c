/*
 * turtle.c
 *
 *  Created on: 05.01.2016
 *      Author: JohnD_2
 */

#include "turtle.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dos.h>


/* global pointers to the local static variables of stepper.
 * NG: Ein wenig unschön, wegen globalen variablen, mann könnte auch gleich die localen static variablen global machen, ich interpretiere die Angabe ao als müsste die funktion stepper die variablen speichern.
 * Oder man könnte die Funktionsdeklaration ändern um Setter-Parameter hinzuzufügen.
*/
int* px = NULL;
int* py = NULL;
int* pa = NULL;

/*NG: Da durch die vorgabe von int zentimetern der minimale drehwinkel 2 grad beträgt,
 * habe ich den DatenTyp von int in double umgeändert um auch bei kürzeren Achsenlängen um 1 grad drehen zu können.
 */
void stepper(motor_t motor, direction_t richtung, double zentimeter)
{
	static int xpos = 0;
	static int ypos = 0;
	static int angle = 0;

	px = &xpos;
	py = &ypos;
	pa = &angle;

	int steps = zentimeter*STEPSCM;
	char *dir = "VOR";
	char *mot = "NONE";

	if(richtung == RUECK)
	{
		steps= -steps;
		dir = "RUECK";
	}
	switch (motor)
	{
	case M1:
		angle = (int)round(angle +((steps*CMSTEP/AXLEWIDTH)*180/M_PI))%360;
		mot = "M1";
		break;
	case M2:
		angle = (int)round(angle - ((steps*CMSTEP/AXLEWIDTH)*180/M_PI))%360;
		mot = "M2";
		break;
	case BOTH:

		xpos += (int)round(cos(2*M_PI*angle/360)*steps*CMSTEP);
		ypos += (int)round(sin(2*M_PI*angle/360)*steps*CMSTEP);
		mot = "BOTH";
		break;
	}
	steps = (int)(zentimeter*STEPSCM);

	drawLawn();
	/*
	if(zentimeter != 0.0)
	{
		printf("input:\t %s, %s, %5.2f cm.\n", mot, dir,zentimeter);
		printf("Distance traveled: %5.2f cm, %d steps.\n", zentimeter, steps);
		printf("Position: (%d, %d) Heading: %d\n", xpos, ypos, (int)angle);
		printf("------------------------------------------\n");
	}*/
}

int turtle(befehl_t befehl, int p1, int p2)
{
	int retval = -1;

	if ((strcmp(befehl, "fd") == 0) && (p2 == NOP) && (p1 >= 0))
	{
		stepper(BOTH,VOR, p1);
		retval = 1;
	}
	else if((strcmp(befehl, "bk") == 0) && (p2 == NOP) && (p1 >= 0))
	{
		stepper(BOTH,RUECK, p1);
		retval = 1;
	}
	/* NG: Mit achsenabschnitt 25 cm kann man nicht nur um 1 grad drehen, da die drehung um 1 grad 0,47cm lauflänge beträgt.
	 * Dies wird entweder abgerundet auf 0 und nicht gedreht oder auf 1 und um 2 grad gedreht.
	 * Die Steppermethode hat jedoch die Vorgabe das der Parameter distanz in cm angegeben wird.
	*/
	else if((strcmp(befehl, "rt") == 0) && (p2 == NOP) && (p1 >= 0))
	{
		stepper(M1,VOR, (p1*CMDEG));
		retval = 1;
	}
	else if((strcmp(befehl, "lt") == 0) && (p2 == NOP) && (p1 >= 0))
	{
		stepper(M1,RUECK, (p1*CMDEG));
		retval = 1;
	}
	else if(strcmp(befehl, "go") == 0)
	{
		int i =0;
		do
		{
			int newx = p1-*px;
			int newy = p2-*py;
			double newh;

			/*if((newx == 0) || (newy == 0))
				newh = *pa;
			else*/
			{
				newh = atan2(newy,newx);
				if(newh >= 0)
					newh = (newh * 180 / (M_PI));
				else
					 newh = ((2*M_PI + newh) * 180 / (M_PI));
			}

			if((p1 == *pa) && (p2 == *py))
			{
				retval = 1;
			}
			else
			{
					turtle((befehl_t)"sh",(int)round(newh), NOP);
					turtle((befehl_t)"fd", (int)sqrt(newx*newx+newy*newy), NOP);
			}
			i++;
		}
		while(i<2); // NG: doppelt go ausführen weil wegen ungenauigkeit beim ersten mal die position knapp daneben liegt, zweiter lauf zur korrektur.


	}
	else if((strcmp(befehl, "sx") == 0) && (p2 == NOP))
	{
		*px = p1;
		retval = 1;
	}
	else if((strcmp(befehl, "sy") == 0) && (p2 == NOP))
	{
		*py = p1;
		retval = 1;
	}
	else if ((strcmp(befehl, "sh") == 0) && (p2 == NOP) && (p1 >= 0) && (p1 < 360))
	{
		if (p1 > *pa)
		{
			turtle((befehl_t)"rt",abs(*pa-p1), NOP);
		}
		else
		{
			turtle((befehl_t)"rt",360 - abs(*pa-p1), NOP);
		}
		retval = 1;
	}
	else if((strcmp(befehl, "ho") == 0) && (p2 == NOP) && (p1 == NOP))
	{
		turtle((befehl_t)"go", 0, 0);
		retval = 1;
	}
	return retval;
}

int do_it(turtle_t *befehle, int anzahl)
{
	int i;
	for (i = 0; i < anzahl; i++)
	{
		turtle(befehle[i].befehl,befehle[i].p1,befehle[i].p2);
	}
}

int parseCommandFile(char*filename,turtle_t **commandArray, int *commNumber)
{
	int retval = -1;
	FILE *file;
	int commandNR = 0;
	int varFilled = 0;
	int i;

	if((file =fopen(filename, "r")) != NULL)
	{
		char line[MAXCOMMANDLENGTH + 1];
		char command[3];
		turtle_t *tarr;
		int par1, par2;
		while (fgets(line, sizeof(line), file))
			commandNR++;
		rewind(file);
		tarr = (turtle_t*)calloc(commandNR,sizeof(**commandArray));
		commandNR = 0;
		while (fgets(line, sizeof(line), file))
		{
			varFilled = sscanf(line, "%s %d %d", command, &par1, &par2);
			if (varFilled == 3)
			{

				tarr[commandNR].befehl = malloc(sizeof(command));
				strcpy(tarr[commandNR].befehl, command);
				tarr[commandNR].p1 = par1;
				tarr[commandNR].p2 = par2;

;			}
			else if(varFilled == 2)
			{

				tarr[commandNR].befehl = (befehl_t) malloc(sizeof(command));
				strcpy(tarr[commandNR].befehl, command);
				tarr[commandNR].p1 = par1;
				tarr[commandNR].p2 = NOP;

			}
			else if(varFilled == 1)
			{

				tarr[commandNR].befehl = (befehl_t) malloc(sizeof(command));
				strcpy(tarr[commandNR].befehl, command);
				tarr[commandNR].p1 = NOP;
				tarr[commandNR].p2 = NOP;

			}else
			{
				fprintf(stderr,"Command could not be read from file.");
				exit(-1);
			}
			commandNR++;

		}
		fclose(file);

		*commandArray = tarr;
		retval = 1;
	}
	else
	{
		fprintf(stderr,"File could not be opened.");
	}

	*commNumber = commandNR;
	return retval;

}

void lawnmower(void)
{

	srand(time(NULL));
	border_t check;
	while(1)
	{
		turtle("fd", rand()%RANDMOVE_MAX, NOP);
		check = checkBorder();
		switch (check)
		{
		case INSIDE:
			turtle("sh", rand()%360, NOP);
			break;
		case NORTH:
			turtle("sh", 90 +rand()%RANDTURN_MAX, NOP);
			break;
		case EAST:
			turtle("sh", 180 +rand()%RANDTURN_MAX, NOP);
			break;
		case SOUTH:
			turtle("sh", (270 +rand()%RANDTURN_MAX)%360, NOP);
			break;
		case WEST:
			turtle("sh", rand()%RANDTURN_MAX, NOP);
			break;
		}
	}
}

border_t checkBorder(void)
{
	border_t retbord = INSIDE;
	if(*px < 0)
		retbord = SOUTH;
	else if (*px > LAWNMAX_X)
		retbord = NORTH;
	else if (*py < 0)
		retbord = WEST;
	else if (*py> LAWNMAX_Y)
		retbord = EAST;
	return retbord;
}

void drawLawn(void)
{
	static char lawn[60][50];
	int i,j;
	system("cls");
	for(i = ((LAWNMAX_X/10) -1); i >= 0; i--)
	{
		for(j = 0; j < (LAWNMAX_Y/10); j++)
		{
			if ( (*px/10 == i) && (*py/10 == j))
				printf("*");
			else
				printf("_");
		}
		printf("\n");
	}
}

int main(void)
{
	//init
	stepper(BOTH,VOR,0);// initalize so that the global pointers are initialized for the turtle()-function

	/*
	turtle_t *commands;
	int commandNumber;
	parseCommandFile(FILEPATH, &commands, &commandNumber);
	do_it(commands,commandNumber);
	free(commands);*/

	lawnmower();

	return 0;
}

