/*
 * app.c
 *
 * Created: 14/10/2022 06:19:59 ص
 *  Author: Eldeeb
 */ 
#include "app.h"

uint8_t CAR_Cod = 0;
uint8_t Yellow_Stat = 0;
uint8_t Sec_Counter = 0;
uint8_t Count_overflow0 = 0;
void app_init(void)
 {
	//Initialization for Car_Leds
	LED_Init(CAR_Port,Car_Green_PIN);
	LED_Init(CAR_Port,Car_Yellow_PIN);
	LED_Init(CAR_Port,Car_Red_PIN); 
	
	//Initialization for PED_Leds
	LED_Init(PED_Port ,PED_Green_PIN);
	LED_Init(PED_Port ,PED_Yellow_PIN);
	LED_Init(PED_Port ,PED_Red_PIN);
	
	//Initialization for Button
	 BUTTON_Init(PED_Button_PIN, BUT_Port);
	 
	 //PULL Up For this Pin
	 PORTD |= (1<<Pin2);
	
	 //Enable Global interrupt
	 sei();
	 
	 //Sensed in Raising edge
	 SET_BIT(MCUCR,ISC00);
	 SET_BIT(MCUCR,ISC01);
	 
	 //Enable External interrupt 0
	 SET_BIT(GICR,INT0);
	 
	 //Enable Over Flow interrupt for Timer0
	 SET_BIT(TIMSK,TOIE0);
	 
	 //Timer0 Initialization
	 Timer0_Set(Normal_Mode);
	 
	 //Timer 0 Starts
	 Timer0_Start(Prescaller_1024,12);
 }
 
 void app_star(void) 
  {
	  while (1)
	   {
		   //to validate CAR_Cod in Range
		  if(CAR_Cod > Yellow_Cond_2)
		  {
			  CAR_Cod = Green_Cond;
		  }
		  else
		  {
			  switch(CAR_Cod){
				  case Green_Cond:
				   
				    //Cars LEDs
				    LED_on(CAR_Port,Car_Green_PIN);
				    LED_off(CAR_Port,Car_Yellow_PIN);
				    LED_off(CAR_Port,Car_Red_PIN);
					
					 //pedestrian LEDs
				    LED_off(PED_Port,PED_Green_PIN);
				    LED_off(PED_Port,PED_Yellow_PIN);
				    LED_on(PED_Port,PED_Red_PIN);
					Yellow_Stat = 0;
					break;
				 case Yellow_Cond_1:
				    Yellow_Stat =1;
				  
				    //Cars LEDs
				    LED_off(CAR_Port,Car_Green_PIN);
				    LED_off(CAR_Port,Car_Red_PIN);
				   
				    //pedestrian LEDs
				    LED_off(PED_Port,PED_Green_PIN);
				    LED_off(PED_Port,PED_Red_PIN);
				    break;
				 case Red_Cond:
				    
					//Cars LEDs
				   LED_off(CAR_Port,Car_Green_PIN);
				   LED_off(CAR_Port,Car_Yellow_PIN);
				   LED_on(CAR_Port,Car_Red_PIN);
				   
				   //pedestrian LEDs
				   LED_on(PED_Port,PED_Green_PIN);
				   LED_off(PED_Port,PED_Yellow_PIN);
				   LED_off(PED_Port,PED_Red_PIN);
				   Yellow_Stat = 0;
				   break;
				case Yellow_Cond_2:
				   Yellow_Stat =1;
				  
				   //Cars LEDs
				   LED_off(CAR_Port,Car_Green_PIN);
				   LED_off(CAR_Port,Car_Red_PIN);
				   
				   //pedestrian LEDs
				   LED_off(PED_Port,PED_Green_PIN);
				   LED_off(PED_Port,PED_Red_PIN);
				  break;
				default: 
				   //Error Handling
				 break;
			  }
		  }
	   }
  }
  





ISR(TIMER0_OVF_vect)
 {
	     //Check if Count_overflow0 reach to N_OverFlow0
	 if (Count_overflow0 >= N_OverFlow0) 
	  {
		  //every reach it will count 1 sec
		  Sec_Counter++;
	     if(Yellow_Stat == 1)
		   {
			   //Toggle both Yellow Leds
			   LED_toggle(CAR_Port,Car_Yellow_PIN);
			   LED_toggle(PED_Port,PED_Yellow_PIN);
		   }
	     if( Sec_Counter == 5)
		   {
			   //Every five seconds the car condition is increment by 1 then clear counter
			   CAR_Cod++;
			   Sec_Counter=0;
		   }
		   //clear Count_overflow0
		   Count_overflow0 = 0;
	       }
  if(Count_overflow0 < N_OverFlow0)
	{
		//increase Count_overflow0 N_OverFlow0
		Count_overflow0++;
	}
 }
 
 ISR(INT0_vect) 
   {
	   //Every Raising Edge by Button 
	   if(CAR_Cod == Green_Cond)
	     {
			 //Jump to Yellow_1_Cond
			 CAR_Cod++;
			 //clear Sec_Counter and Count_overflow0
			 Sec_Counter = 0;
			 Count_overflow0 = 0;
		 }
	  if ( CAR_Cod == Yellow_Cond_1 ||CAR_Cod == Yellow_Cond_2 || CAR_Cod == Red_Cond)
	    {
			//in these states Conditions not change
		}
	   
   }
