#include <kipr/wombat.h>
#include <debug.h>
#include <getfirstpoms.h>

int speed = 700;
int main ()
{
enable_servos(); 
    moveFlipperRight();
getfirstpoms(speed);

    
    disable_servos();
	return 0;
}