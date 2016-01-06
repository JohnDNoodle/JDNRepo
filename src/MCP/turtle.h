/*
 * turtle.h
 *
 *  Created on: 05.01.2016
 *      Author: JohnD_2
 */

#ifndef TURTLE_H_
#define TURTLE_H_

#define NOP -1

#define WHEELCIRC 15.7	// wheel circumference in cm
#define AXLEWIDTH 25	// distance between the 2 wheels in cm
#define STEPSCM 12.75		// steps per centimeter (157 mm / 200 = 0,785375 mm/step => 12.75 step/cm)
#define STEPSDEG 5.55		// steps per degree (2.78 if method of turning is with both wheels active, 5.55 else)
#define CMSTEP 0.07854		// distance in cm per step.
#define CMDEG (M_PI/180)*AXLEWIDTH	// distance in cm per degree of turn.
#define MAXCOMMANDLENGTH 50	// maximum number of chars in a command
#define FILEPATH "C:\\Users\\JohnD_2\\workspace\\MC_Turtle\\Debug\\TurtleCommands.txt"	// patch of the commandfile, this one is located in the same directory as the executable

#define LAWNMAX_X 600
#define LAWNMAX_Y 500
#define RANDMOVE_MAX 50
#define RANDTURN_MAX 180

typedef enum Motor{M1, M2, BOTH} motor_t;
typedef enum Direction{VOR, RUECK} direction_t;
typedef unsigned char* befehl_t;

typedef enum Borders{NORTH, EAST, SOUTH, WEST, INSIDE} border_t;

typedef struct
  {
  befehl_t befehl;
  int p1;
  int p2;
  } turtle_t;


void stepper(motor_t, direction_t,double);
int turtle(befehl_t, int, int);
int do_it(turtle_t*, int);
int parseCommandFile(char*,turtle_t **, int *);
border_t checkBorder(void);
void drawLawn(void);

#endif /* TURTLE_H_ */
