#include <kipr/wombat.h>
void pomsweep(int leftmotorport, int rightmotorport);

void pomsweep(int leftmotorport, int rightmotorport)
{
    //ASSUMPTION: already connected to create
    
    //Constant variables
/*    
    const int INITIAL_ANGLE=0;
    const int RIGHT_TURNING_ANGLE1=-10;
    const int CW_SPIN_SPEED=100;
    
    const int INITIAL_DISTANCE=0;
    const int PUSH_DISTANCE=250;
    const int FORWARD_STRAIGHT_SPEED=100;
    const int RIGHT_TURNING_ANGLE2=45;
    const int CCW_SPIN_SPEED=100;
    const int FINAL_ANGLE=5; */
    const int SWEEP_COUNT=2;
    const int GENERAL_MSLEEP_TIME=100;
    const int SPEED = 700;
    int x=1;
    int lefttirerotation = 1500;
    int righttirerotation;
    while(x<=SWEEP_COUNT)
    {
        printf("in pom sweep \n");
        cmpc(rightmotorport);
        cmpc(leftmotorport);
        // We are going to turn the robot to the right to position to sweep the poms into the Data Center
        while (gmpc(leftmotorport) <= lefttirerotation)
        {        
            printf("in get motor position counter \n");
        	mav(rightmotorport, 0);
        	mav(leftmotorport, SPEED);
        	msleep(GENERAL_MSLEEP_TIME);
        }
        mav(rightmotorport, SPEED);
        mav(leftmotorport, SPEED);
        msleep(GENERAL_MSLEEP_TIME);
        while (gmpc(rightmotorport) <= lefttirerotation)
        {
            mav(rightmotorport, SPEED);
        	mav(leftmotorport, 0);
        	msleep(GENERAL_MSLEEP_TIME);
        }
        
        
        ao();
        cmpc(rightmotorport);
        cmpc(leftmotorport);	
        mav(leftmotorport, 0);
        	mav(rightmotorport, SPEED);
        	msleep(GENERAL_MSLEEP_TIME);
        ao();
        righttirerotation = gmpc(rightmotorport);
        lefttirerotation = gmpc(leftmotorport);
        cmpc(rightmotorport);
        cmpc(leftmotorport);	

        while(gmpc(leftmotorport)< lefttirerotation)
        {
            mav(leftmotorport, 100);
        	mav(rightmotorport, 0);
        	msleep(100);
        }
        ao();
        
        /*
        //We're gonna turn the bucket clockwise (to the right) before moving
    	//set the angle of the create to 0
    	set_create_total_angle(INITIAL_ANGLE);
        
    	//turn create clockwise until -18 degrees
   	 	while(get_create_total_angle()>RIGHT_TURNING_ANGLE1)
   		{
        	printf("angle=%i\n",get_create_total_angle());
        	create_spin_CW(CW_SPIN_SPEED);
       		msleep(GENERAL_MSLEEP_TIME);
   		}
        
  		//After turning, we move forward unti we are able to sweep the poms to the data center
   		set_create_distance(INITIAL_DISTANCE);
   		//drive straight for 265 mm
   		while(get_create_distance()<PUSH_DISTANCE)
    	{
        	create_drive_straight(FORWARD_STRAIGHT_SPEED);
        	msleep(GENERAL_MSLEEP_TIME);
   		 }
        
   		 //We rotate to the left to push the poms into the data center
   		 while(get_create_total_angle()<RIGHT_TURNING_ANGLE2)
    	{
        	create_spin_CCW(CCW_SPIN_SPEED);
        	msleep(GENERAL_MSLEEP_TIME);
   		}
        
   		// Straighten the robot back to center/align with the black line
    	while(get_create_total_angle()>FINAL_ANGLE)
    	{
        	create_spin_CW(CW_SPIN_SPEED);
        	msleep(GENERAL_MSLEEP_TIME);
    	}*/
        
    	//we repeat the process for the second pom cluster
        x=x+1;
    }
}