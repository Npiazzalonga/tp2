/*********************************************************************************************************
*                                               <Module name>
*						<Module description>
*
*						<Copyright>
*
*						<Copyright or distribution terms>
*
*
*********************************************************************************************************/

/*********************************************************************************************************
*                                               <File description>
*
* Filename	: Filename
* Version	: Module version					
* Programmer(s) : Programmer initial(s)
**********************************************************************************************************
*  Note(s):
*
*
*
*********************************************************************************************************/

/*********************************************************************************************************
 *
 * \file		${file_name}
 * \brief		Descripcion del modulo
 * \date		${date}
 * \author		Nicolas Ferragamo nferragamo@frba.utn.edu.ar
 * \version 
*********************************************************************************************************/

/*********************************************************************************************************
 *** INCLUDES
*********************************************************************************************************/

#include <Arduino.h>
#include <util/delay.h>

/*********************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
*********************************************************************************************************/
#define boton1 ((PIND >> 4) & 0X01)
#define boton2 ((PIND >> 5) & 0X01)
#define boton3 ((PIND >> 6) & 0X01)
#define boton4 ((PIND >> 7 )& 0X01)
/*********************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
*********************************************************************************************************/
#define SET_PIN(PORT, PIN) (PORT |= (1 << PIN)) 
#define CLEAR_PIN(PORT, PIN) (PORT &= ~(1 << PIN)) 
/*********************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
*********************************************************************************************************/

/*********************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
*********************************************************************************************************/



/*********************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 *   se escriben en CamelCase y están precedidas por la identificación del 
 *   módulo seguida de un _ 
 *   ej: MEM_POOL  Mem_PoolHeap; 
*********************************************************************************************************/
char cont = 1;
char FLAG_BT1 = 0;

/*********************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 *   se declaran con static y se escriben en CamelCase y están precedidas por la 
 *   identificación del módulo seguida de un _ y usan _ para separar las palabras
 *   cuando tienen nombres compuestos
 *   ej: static MEM_POOL  Mem_Pool_Heap; 
*********************************************************************************************************/



/*********************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 * se declaran como estaticas y se escriben en CamelCase, están precedidas por la
 * identificación del módulo seguida de un _. No se decaran en el .h
 * ej static void Clk_DateTimer(parametros)
*********************************************************************************************************/



/*********************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
*********************************************************************************************************/
void mostrar_led (char);


/*********************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
*********************************************************************************************************/

int main(void)
{
 DDRD&==~ (1<<PD4);										
 DDRD&==~ (1<<PD5);
 DDRD&==~ (1<<PD6);
 DDRD&==~ (1<<PD7);
 DDRD |= (1<<PD2); 
 DDRD |= (1<<PD3); 
 DDRB |= (1<<PB0); 
 DDRB |= (1<<PB1); 
 DDRB |= (1<<PB2); 
 DDRB |= (1<<PB3); 
 DDRB |= (1<<PB4); 
  PORTD|= (1<<PD4);
  PORTD|= (1<<PD5);
  PORTD|= (1<<PD6);
  PORTD|= (1<<PD7);
 while(1) 
 
    while(1) 
    {
        if(boton1==0)
        { 
            FLAG_BT1=1;
        }
        if (FLAG_BT1==1)
        {
            cont++; 

            if (cont==7)
            {
                cont=1;
            }
       
            mostrar_led(cont);        
            _delay_ms(65);  

        }  
      
        if (boton2==0)         
       {
           FLAG_BT1=0;
       }
       if (boton3 == 0 || boton4 == 0)
       {
         CLEAR_PIN(PORTD,PD2);
         CLEAR_PIN(PORTD,PD3);
         CLEAR_PIN(PORTB,PB0);
         CLEAR_PIN(PORTB,PB1);        
         CLEAR_PIN(PORTB,PB2);
         CLEAR_PIN(PORTB,PB3);
         CLEAR_PIN(PORTB,PB4);

       }


         
    }   
}

void mostrar_led (char num )
{

   CLEAR_PIN(PORTD,PD2);
   CLEAR_PIN(PORTD,PD3);
   CLEAR_PIN(PORTB,PB0);
   CLEAR_PIN(PORTB,PB1);        
   CLEAR_PIN(PORTB,PB2);  
   CLEAR_PIN(PORTB,PB3);
   CLEAR_PIN(PORTB,PB4);

 switch (num)
{
  
 case 1:  
        SET_PIN(PORTB,PB4); 

    break;


 case 2: 
         SET_PIN(PORTD,PD2);
         SET_PIN(PORTB,PB3); 

  break;

  case 3: 
         
        SET_PIN(PORTD,PD2);
        SET_PIN(PORTB,PB4);
        SET_PIN(PORTB,PB3);

    break;

    case 4:

         SET_PIN(PORTD,PD2); 
         SET_PIN(PORTB,PB0);
         SET_PIN(PORTB,PB1);
         SET_PIN(PORTB,PB3);

    break;

     case 5:

         SET_PIN(PORTD,PD2); 
         SET_PIN(PORTB,PB0);
         SET_PIN(PORTB,PB1);
         SET_PIN(PORTB,PB3);
         SET_PIN(PORTB,PB4);

    break;

     case 6:

         SET_PIN(PORTD,PD2); 
         SET_PIN(PORTD,PD3);
         SET_PIN(PORTB,PB0);
         SET_PIN(PORTB,PB1);
         SET_PIN(PORTB,PB2);
         SET_PIN(PORTB,PB3);
         SET_PIN(PORTB,PB4);

    break;

 }
}