const int FLIPPER_PORT = 0;
const int FLIPPER_LEFT = 1570;
const int FLIPPER_RIGHT = 417;

void moveFlipperLeft();
void moveFlipperRight();

void moveFlipperLeft()
{
 	//printf("moving flipper left");
    set_servo_position(FLIPPER_PORT, FLIPPER_LEFT);   
}
void moveFlipperRight()
{
 	//printf("moving flipper right");
    set_servo_position(FLIPPER_PORT, FLIPPER_RIGHT);   
}
