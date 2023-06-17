/*
 * app.c
 *
 * created: 1/14/2023 9:14:12 pm
 *  author: mohamed_gamal
 */ 
# include "app.h"


// initial mode of operation 
En_MODE_t mode = normal ;
// initial click status
En_first_click_t click = unclicked ;
// flag for blocking timers when interrupt is enabled
extern En_blocking_t isBlocked;
// initial states for car LEDS
En_CAR_LED_ON_t current_state = green_c;
En_CAR_LED_ON_t previous_state = yellow_c;

void APP_init(void)
{
	//1-car led initialization
	LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	//2-pedestrian led initialization
	LED_init(LED_PED_PORT,LED_PED_G_PIN);
	LED_init(LED_PED_PORT,LED_PED_Y_PIN);
	LED_init(LED_PED_PORT,LED_PED_R_PIN);
	
	//3- interrupt button initialization
	BUTTON_init(INT_BUTTON_PORT,INT_BUTTON_PIN);
	
	
	//4-interrupt initialization
	
	//1.enable global interrupts
	sei();
	
	//2. choosing interrupt sense
	falling_edge_setup();
	//3. enabling external into
	setup_int0();
		
	
}

void APP_start(void)
{ 
   
   switch(mode)
   {
	   case normal:
	   if(!isBlocked)
	   {
		   
	   
		   if(current_state==green_c && previous_state == yellow_c ) // starting with green led
		   {
		   
 			   // turn on car green LED
 			   LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
 			   // wait 5 secs
 			   LED_normal_delay (delay_5sec) ;
 			   //turn off car green LED
 			   LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
			   // go to next state if not blocked
			   if(!isBlocked)
			   {
			   			   current_state = yellow_c ;
			   			   previous_state = green_c ;
			   }
   
		   }
	   
		   else if (current_state==yellow_c && previous_state == green_c)
		   {
			   LED_blink_CAR(delay_Halfsec,LED_CAR_PORT,LED_CAR_Y_PIN); // blink yellow LED for 5 secs
			   // go to next state
			   if(!isBlocked)
			   {
			   			   current_state = red_c;
			   			   previous_state = yellow_c;
			   }

		   }
		   else if (current_state == red_c && previous_state == yellow_c)
		   {
 			   // turn on car red LED
 			   LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
 			   // wait 5 secs
 			   LED_normal_delay (delay_5sec) ;
 			   //turn off car green LED
 			   LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
			   // go to next state
				if(!isBlocked)
				{
			   				current_state = yellow_c ;
			   				previous_state = red_c ;
				}

	     
		   }
		   else if (current_state == yellow_c && previous_state == red_c)
		   {
				LED_blink_CAR(delay_Halfsec,LED_CAR_PORT,LED_CAR_Y_PIN); // blink  car yellow LED for 5 secs
				// go to next state
				if(!isBlocked)
				{
							current_state = green_c;
							previous_state = yellow_c;
				}

		   }
	   }
	   break;
	   case pedestrian:
	   if(current_state==red_c && previous_state==yellow_c )
	   {
			isBlocked = unblocked;  // To make timers work as usual 
		    // turn on car red LED
		    LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
		    // turn on pedestrian green LED
		    LED_on(LED_PED_PORT,LED_PED_G_PIN);
		    // wait 5 secs
		    LED_normal_delay (delay_5sec) ;
			
			//// car's red LED off 
			LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
			// blink  yellow LEDS for 5 secs
			LED_blink_both(delay_Halfsec,LED_CAR_PORT,LED_CAR_Y_PIN,LED_PED_PORT,LED_PED_Y_PIN); // blink  car and pedestrian yellow LEDs for 5 secs
			//
		    //////turn off pedestrian green LED and both yellow LEDS
			LED_off(LED_PED_PORT,LED_PED_Y_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_G_PIN);
			////
			////// turn on pedestrian red LED and car green LED for 5 secs
			LED_on(LED_PED_PORT,LED_PED_R_PIN);
			LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
		    // wait 5 secs
			LED_normal_delay (delay_5sec) ;
			
			// turn off pedestrian red LED
			LED_off(LED_PED_PORT,LED_PED_R_PIN);

		   //  go to normal mode
			mode = normal ; 
			// go to initial states
			 current_state = green_c;
			 previous_state = yellow_c;
			// make the button ready for use
			click=unclicked;
	      }
		 else if((current_state==green_c && previous_state == yellow_c) || (current_state == yellow_c && previous_state == red_c) || (current_state==yellow_c && previous_state == green_c) )
			{ // green car LED on or Yellow car LED blinking (whether previous state is green LED or red LED)
				
				isBlocked = unblocked;  // To make timers work as usual 
				// turn off all car LEDS at first 
				LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
				//// Pedestrian's red LED on
				LED_on(LED_PED_PORT,LED_PED_R_PIN);
				// blink  yellow LEDS for 5 secs
				LED_blink_both(delay_Halfsec,LED_CAR_PORT,LED_CAR_Y_PIN,LED_PED_PORT,LED_PED_Y_PIN); // blink  car and pedestrian yellow LEDs for 5 secs
				//// Pedestrian's red LED off and both yellow LEDs off
				LED_off(LED_PED_PORT,LED_PED_R_PIN); 
				LED_off(LED_PED_PORT,LED_PED_Y_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				
				// Green pedestrian LED on
				LED_on(LED_PED_PORT,LED_PED_G_PIN);
				// Red car led on
				LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
				// wait 5 secs
				LED_normal_delay(delay_5sec) ;

				// Red car LED off
				LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
				// blink  yellow LEDS for 5 secs
				LED_blink_both(delay_Halfsec,LED_CAR_PORT,LED_CAR_Y_PIN,LED_PED_PORT,LED_PED_Y_PIN); // blink  car and pedestrian yellow LEDs for 5 secs
				
				//turn off pedestrian green LED and both yellow LEDS
				LED_off(LED_PED_PORT,LED_PED_Y_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_PED_PORT,LED_PED_G_PIN);
	
				// turn on pedestrian red LED and car green LED for 5 secs
				LED_on(LED_PED_PORT,LED_PED_R_PIN);
				LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
				// wait 5 secs
				LED_normal_delay (delay_5sec) ;
							
				// turn off pedestrian red LED
				LED_off(LED_PED_PORT,LED_PED_R_PIN);

				//  go to normal mode
				mode = normal ;
				// go to initial states
				current_state = green_c;
				previous_state = yellow_c;
				// make the button ready for use 
				click=unclicked;
		
				
			}  
				 break;
	   }
	
   
   }  


ISR(EXT_INT_0)
{   
	if(click==unclicked)
	{
	mode = pedestrian ;
	click = first ; 
	isBlocked = blocked ;
	} 
	
}