#include <kipr/wombat.h>
#include <Eddie.h>
#include <Gracie.h>
#include <Eli.h>
#include <Matthew.h>
#include <Noah.h>
#include <Theresa.h>
const int RM=0;//right motor
const int LM=1;//left motor
const int SR=1;//servo
const int TP=0;//top hat
const int speed=900;
void getfirstpoms(int speed);
void moveFlipperRight();
void pickuppoms(int speed);
int main()
{ 
    enable_servos();
    moveFlipperRight();
    getfirstpoms(speed);
  	pickuppoms(speed);
   
    return 0;
}
