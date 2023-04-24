void pickuppoms(int servo);
void pickuppoms(int servo){    
   int x=1;
    // this is to collect all the poms and to score us all the points. If this fails we lose.

 
 while(x<5)
   {
        lineFollow(int Lmp, int Rmp, int Speed, int Tpp, int black);
       enable_servos();
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
}

}