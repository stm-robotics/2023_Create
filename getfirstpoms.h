#include <kipr/wombat.h>
#include <Flipper.h>
// step 2 of proccess flow.
// drive foreward until black (keep track of clicks)
// step 3 of proccess flow
// flipper left
// step 4 of proccess flow
// go back n clicks
// step 5 of proccess flow
// turn right m clicks
// step 6 of proccess flow
// drive foreward untill black line then foreward till not black line 
// step 7 of proccess flow
// turn right
// step 8 of proccess flow
// flipper right
// step 9 of proccess flow
// line follow
void getfirstpoms(int speed);

const int THRESHOLD = 3400;
const int TOPHAT = 0;
const int RIGHTMOTOR = 0;
const int LEFTMOTOR = 1;
int Nclick; //Nclick is the amount we move foreward and back 
int Mclicks=350; // Mclick is moving right slightly
int Cclicks=800; // Cclick is moving right 90 deg
void getfirstpoms(int speed)
{
    debugPrint("Getting first poms...");
    // Clear left motor possition 
    cmpc(LEFTMOTOR);
    // Move foreward untill back
    while (analog(TOPHAT)<THRESHOLD)
    {
        printf("Tophat=%i\n",analog(TOPHAT));
        mav(RIGHTMOTOR, speed);
        mav(LEFTMOTOR, speed);  
    }
    ao();
    // Determan how far we have traveled
    Nclick=gmpc(LEFTMOTOR);   
    // Move Flipper left
    moveFlipperLeft();
    // clear motor possition counter
    cmpc(LEFTMOTOR);
    // Keeps going untill motor turns Nclick
    while (gmpc(LEFTMOTOR) > -Nclick)
    {
        mav(RIGHTMOTOR, -speed);
        mav(LEFTMOTOR, -speed);  
    }
     ao();
    // Turn right slightly
    cmpc(LEFTMOTOR);
    while (gmpc(LEFTMOTOR) < Mclicks)
        {
        mav(RIGHTMOTOR, -speed);
        mav(LEFTMOTOR, speed);  
        }
     ao();
    //drive foreward untill black 
     while (analog(TOPHAT)<THRESHOLD)
    {
        mav(RIGHTMOTOR, speed);
        mav(LEFTMOTOR, speed);  
    }
     ao();
     //drive foreward till not black
     while (analog(TOPHAT)>THRESHOLD)
    {
        mav(RIGHTMOTOR, speed);
        mav(LEFTMOTOR, speed);  
    }
     ao();
   // Turning right Cclicks
    cmpc(LEFTMOTOR);
    while (gmpc(LEFTMOTOR) < Cclicks)
        {
        mav(RIGHTMOTOR, -speed);
        mav(LEFTMOTOR, speed);  
        }
     ao();
    moveFlipperRight();
    ao();
}
// gmpc(moter port)
// cmpc(moter port)


     

