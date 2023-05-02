void pickuppoms();
const int Tpp=0;
const int clicks1=1800;
const int clicks2=4000;
const int clicks3=6500;
const int clicks4=8000;
const int clicks5=11500;
const int clicks6=13250;

const int sleeptime= 0;
//const int Speed=300;
const int Rmp=0;
const int Lmp=1;   
const int black=3400;
const int nclicks=500;
const int nflips=6; // total number of flips
int cflips=1; // flips counter
void moveFlipperLeft();
void moveFlipperRight();

void pickuppoms(int Speed){    
    // this is to collect all the poms and to score us all the points. If this fails we lose.

enable_servos();
    cmpc(Lmp);
 /*while(gmpc(Lmp) >= -nclicks)
 {
     mav(Rmp,-1*Speed);
     mav(Lmp,-1*Speed);
 }*/  
 while(cflips <= 6)
   {
     if (analog(Tpp) < black) //white
     {
         // turn right
         mav(Rmp,0.5*Speed);
         mav(Lmp,1.5*Speed); 
     }
     else //black
     {
         //turn left
         mav(Rmp,1.5*Speed);
         mav(Lmp,0.5*Speed);
     }
     // need to move flipper at intervals
     if (gmpc(Lmp)>=clicks1 && cflips < 2)
     {
         printf("first reached\n");
         moveFlipperLeft();
         cflips = cflips + 1;
         msleep(sleeptime);
     }
     else if (gmpc(Lmp)>=clicks2 && cflips < 3)
     {
         printf("second reached\n");
         moveFlipperRight();
         cflips = cflips + 1;
         msleep(sleeptime);
     }
     else if (gmpc(Lmp)>=clicks3 && cflips < 4)
     {
         printf("third reached\n");
         moveFlipperLeft();
         cflips = cflips + 1;
         msleep(sleeptime);
     }
     else if (gmpc(Lmp)>=clicks4 && cflips < 5)
     {
         printf("fourth reached\n");
         moveFlipperRight();
         cflips = cflips + 1;
         msleep(sleeptime);
     }
     else if (gmpc(Lmp)>=clicks5 && cflips < 6)
     {
         printf("fifth reached\n");
         moveFlipperLeft();
         cflips = cflips + 1;
         msleep(sleeptime);
     }
     else if (gmpc(Lmp)>=clicks6 && cflips < 7)
     {
         printf("fifth reached\n");
         moveFlipperRight();
         cflips = cflips + 1;
         msleep(sleeptime);
     ao();
     }
    
    }
/*     enable_servos();
       motor(1,70);
       motor(0,70);
      msleep(1500);
       printf("stop 1");
    set_servo_position(0,481);
      motor(01,50);
       motor(0,50);
    msleep(1500);
    set_servo_position(0,1440);
    x=x+1;
*/
}

