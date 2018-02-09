#include "MicroBit.h"
#include "stdlib.h" 

//call functions
MicroBitMessageBus bus;
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);
MicroBitDisplay display;


void onPressed(MicroBitEvent)

{
 //Print random number between 0 and 5	
 display.print(rand() % 5);
}

int main()
{
 //random seed is initialized to a value representing the calling time 
 //to generate a different value every time
 srand (time(NULL));

 //initialise the fiber scheduler
 scheduler_init(bus);
 
 //detect button a press
 bus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onPressed);
 //detect button b press
 bus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onPressed);	

 while(1)
     fiber_sleep(1000);
}
