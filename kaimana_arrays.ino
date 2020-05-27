//  example.ino
//
//  Copyright 2013 Paradise Arcade Shop, ParadiseArcadeShop.com  
//  All rights reserved.  Use is subject to license terms.
//
//  Code is provided for entertainment purposes and use with the Kaimana controller.
//  Code may be copied, modified, resused with this Copyright notice.
//  No commercial use without written permission from Paradise Arcade Shop.
//
//  Paradise Arcade Shop Kaimana LED Driver Board
//  Initial Release October 15, 2013
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  Kaimana example based on original source released by ParadiseArcadeShop.com October 15, 2013
//
//  Created:  October 24, 2013    zonbipanda // gmail.com  -- Arduino 1.0.5 Support
//  Revised:  October 29, 2013    zonbipanda // gmail.com
//  Revised:  April   11, 2015    zonbipanda // gmail.com  -- Arduino 1.6.3 Support
//


#define __PROG_TYPES_COMPAT__
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "kaimana.h"
#include "kaimana_custom.h"
#include "animations.h"

//JOY_ON[1]
long JOY_ON[12];
long JOY_OFF[12];

// local function declarations
int  pollSwitches(void);
void showStartup(void);
void setLEDRandomColor(int index);


// ParadiseArcadeShop.com Kaimana features initialzied when Kaimana class instantiated
Kaimana kaimana;


// the setup routine runs first and once each time power is applied to the Kaimana board
void setup() 
{                
  // Set the Joystick Button LED list to the Virtua Stick array
  memcpy(JOY_ON, VIRTUA_ON, sizeof(JOY_ON));
  memcpy(JOY_OFF, VIRTUA_OFF, sizeof(JOY_OFF)); 

  // light up all leds at boot to demonstrate everything is functional
  showStartup();
}


// the loop routine repeats indefinitely and executes immediately following the setup() function
void loop() 
{
  unsigned long  ulTimeout;
  uint8_t i;

  // initialize timeout value to now + some seconds
  ulTimeout = millis() + ( (unsigned long)IDLE_TIMEOUT_SECONDS * 1000 );


  // infinite loop of read switches, update LEDs and idle animation when necessary
  while(true)
  {
    // active -- poll switches and update leds
    if( pollSwitches() != 0 )
    {
        // some switches were active so reset idle timeout to now + some seconds
        ulTimeout = millis() + ( (unsigned long)IDLE_TIMEOUT_SECONDS * 1000 );
    }
    else
    {
        // no switches active so test for start of idle timeout  
        if( millis() > ulTimeout )
        {
          animation_idle();
        }  
    }
    
    // delay a little to avoid flickering (yea, updates happens really, really fast!)
    delay( MAIN_LOOP_DELAY );
  } 
}


// ==============================================================
//
//  local functions start here
//
// ==============================================================


// light up all leds at boot to demonstrate everything is functional
//
void showStartup(void)
{


  kaimana.setALL( BLACK );
  delay( BOOT_COLOR_DELAY );
  kaimana.setALL( RED );
  delay( BOOT_COLOR_DELAY );
  kaimana.setALL( GREEN );
  delay( BOOT_COLOR_DELAY );
  kaimana.setALL( BLUE );
  delay( BOOT_COLOR_DELAY );

  if((digitalRead(PIN_P1)) && digitalRead(PIN_P2) && digitalRead(PIN_P3) && digitalRead(PIN_P4) && digitalRead(PIN_K1) && digitalRead(PIN_K2) && digitalRead(PIN_K3) && digitalRead(PIN_K4))
	  {
	  if(!digitalRead(PIN_RIGHT)){ memcpy(JOY_OFF, GG_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, GG_ON, sizeof(JOY_ON)); }
	  if(!digitalRead(PIN_LEFT)){ memcpy(JOY_OFF, NAMCO_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, NAMCO_ON, sizeof(JOY_ON)); }
	  if(!digitalRead(PIN_UP)){ memcpy(JOY_OFF, ARCADE_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, ARCADE_ON, sizeof(JOY_ON)); }
	  if(!digitalRead(PIN_DOWN)){ memcpy(JOY_OFF, NEOGEO_ALT_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, NEOGEO_ALT_ON, sizeof(JOY_ON)); }
	  }
  else if(!digitalRead(PIN_K1) && !digitalRead(PIN_K2)){memcpy(JOY_OFF, SATURN_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, SATURN_ON, sizeof(JOY_ON));}
  	else{
	  if(!digitalRead(PIN_P1) || !digitalRead(PIN_P2)) { memcpy(JOY_OFF, PLAYSTATION_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, PLAYSTATION_ON, sizeof(JOY_ON)); }
	  if(!digitalRead(PIN_P1) && !digitalRead(PIN_P2)) { memcpy(JOY_OFF, TEKKEN_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, TEKKEN_ON, sizeof(JOY_ON)); }
	  if(!digitalRead(PIN_K1)){ 
		  memcpy(JOY_OFF, SFC_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, SFC_ON, sizeof(JOY_ON)); 
		  if(!digitalRead(PIN_DOWN)){ memcpy(JOY_OFF, TATSUNOKO_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, TATSUNOKO_ON, sizeof(JOY_ON)); }
		  if(!digitalRead(PIN_UP)){ memcpy(JOY_OFF, SNES_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, SNES_ON, sizeof(JOY_ON)); }
		  if(!digitalRead(PIN_RIGHT)){ memcpy(JOY_OFF, SNES_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, SNES_ON, sizeof(JOY_ON)); }
	  	}
	  if(!digitalRead(PIN_K2)){ memcpy(JOY_OFF, XBOX_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, XBOX_ON, sizeof(JOY_ON)); }
	  if(!digitalRead(PIN_K3)){
		  memcpy(JOY_OFF, NEOGEO_CD_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, NEOGEO_CD_ON, sizeof(JOY_ON)); 
		  if(!digitalRead(PIN_DOWN)){ memcpy(JOY_OFF, NEOGEO_ALT_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, NEOGEO_ALT_ON, sizeof(JOY_ON)); }
		  if(!digitalRead(PIN_LEFT)){ memcpy(JOY_OFF, NEOGEO_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, NEOGEO_ON, sizeof(JOY_ON)); }
		  if(!digitalRead(PIN_RIGHT)){ memcpy(JOY_OFF, NEOGEO_MINI_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, NEOGEO_MINI_ON, sizeof(JOY_ON)); }
		  }
	  if(!digitalRead(PIN_P4)){ memcpy(JOY_OFF, XBOX_OFF, sizeof(JOY_OFF)); memcpy(JOY_ON, XBOX_ON, sizeof(JOY_ON)); }
	}

  kaimana.setALL( BLACK );
  delay( BOOT_COMPLETE_DELAY );
} 


// set LED to one of 8 predefined colors selected at random
//
void setLEDRandomColor(int index)
{
  switch(random(1,8))    // pick a random color between 1 and 8
  {
    case 1:
      kaimana.setLED(index, COLOR_RANDOM_1);
      break;
    case 2:
      kaimana.setLED(index, COLOR_RANDOM_2);
      break;
    case 3:
      kaimana.setLED(index, COLOR_RANDOM_3);
      break;
    case 4:
      kaimana.setLED(index, COLOR_RANDOM_4);
      break;
    case 5:
      kaimana.setLED(index, COLOR_RANDOM_5);
      break;
    case 6:
      kaimana.setLED(index, COLOR_RANDOM_6);
      break;
    case 7:
      kaimana.setLED(index, COLOR_RANDOM_7);
      break;
    case 8:
      kaimana.setLED(index, COLOR_RANDOM_8);
      break;
    default:   // any undefined value so discard data and set led to BLACK
      kaimana.setLED(index, BLACK);    
      break;
  }  
}



int pollSwitches(void)
{
  static int  iLED[LED_COUNT];
  static int  iActiveSwitchCount;
  static int  i;  
  static int  j;  
  static int  firsttime;
  static uint16_t  joystickDirection;
  static uint16_t  switchActivity;

  // reset LED status
  if (firsttime == 1)
  {
    for(i=0;i<LED_COUNT;++i)
    {
      iLED[i] = false;
      firsttime = 0;
    }
  }

  // read arduino pins and save results in the mapped LED if button is pressed (pin grounded)

  // complex special case for joystick but it's worth the effort
  joystickDirection = ATTACK_NONE;

  if(!digitalRead(PIN_RIGHT))    
    joystickDirection |= ATTACK_RIGHT;
  if(!digitalRead(PIN_LEFT))
    joystickDirection |= ATTACK_LEFT;
  if(!digitalRead(PIN_DOWN))
    joystickDirection |= ATTACK_DOWN;
  if(!digitalRead(PIN_UP))
    joystickDirection |= ATTACK_UP;

  switch(joystickDirection)
  {
    case ATTACK_RIGHT:    // right
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    case ATTACK_LEFT:    // left
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    case ATTACK_DOWN:    // down
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    case ATTACK_DOWN + ATTACK_RIGHT:    // down + right
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    case ATTACK_DOWN + ATTACK_LEFT:    // down + left
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    case ATTACK_UP:    // up
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    case ATTACK_UP + ATTACK_RIGHT:    // up + right
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    case ATTACK_UP + ATTACK_LEFT:   // up + left
      #ifdef RANDOM_COLOR_JOY_ON
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_ON[0]);
      #endif
      iLED[LED_JOY] = true;
      break;
    default:   // zero or any undefined value on an 8 way stick like UP+DOWN which is not happening on my watch
      #ifdef RANDOM_COLOR_JOY_OFF
        setLEDRandomColor(LED_JOY);
      #else
        kaimana.setLEDhtml(LED_JOY, JOY_OFF[0]);
      #endif    
      iLED[LED_JOY] = false;
      break;
  }  
  
  

  // clear results for switch activity
  switchActivity = ATTACK_NONE;
  
  // test switch and set LED based on result       // HOME = GUIDE
  if(!digitalRead(PIN_HOME))
  {
    if(!digitalRead(PIN_K2)) { memcpy(JOY_ON, NEOGEO_MINI_ON, sizeof(JOY_ON)); memcpy(JOY_OFF, NEOGEO_MINI_OFF, sizeof(JOY_OFF));}
    if(!digitalRead(PIN_K3)) { memcpy(JOY_ON, NEOGEO_ABCD_ON, sizeof(JOY_ON)); memcpy(JOY_OFF, NEOGEO_ABCD_OFF, sizeof(JOY_OFF));}
    if(!digitalRead(PIN_P2)) { memcpy(JOY_ON, NEOGEO_CD_ON, sizeof(JOY_ON)); memcpy(JOY_OFF, NEOGEO_CD_OFF, sizeof(JOY_OFF));}
    if(!digitalRead(PIN_P3)) { memcpy(JOY_ON, NEOGEO_ON, sizeof(JOY_ON)); memcpy(JOY_OFF, NEOGEO_OFF, sizeof(JOY_OFF));}
    if(!digitalRead(PIN_P1)) { memcpy(JOY_ON, NEOGEO_ALT_ON, sizeof(JOY_ON)); memcpy(JOY_OFF, NEOGEO_ALT_OFF, sizeof(JOY_OFF));}
    if(!digitalRead(PIN_K1)) { memcpy(JOY_ON, NEOGEO_2_ON, sizeof(JOY_ON)); memcpy(JOY_OFF, NEOGEO_2_OFF, sizeof(JOY_OFF));}

    // switch is active
    if(iLED[LED_HOME] == true)
    {
      //maintain color while switch is active
      iLED[LED_HOME] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_HOME_ON      
        setLEDRandomColor(LED_HOME);  
      #else
         kaimana.setLED(LED_HOME, LED_HOME_COLOR_ON);
      #endif
      iLED[LED_HOME] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_HOME_OFF
        setLEDRandomColor(LED_HOME);
      #else
        kaimana.setLED(LED_HOME, LED_HOME_COLOR_OFF);
      #endif    
      iLED[LED_HOME] = false;
  }


  // test switch and set LED based on result    // SELECT = BACK 
  if(!digitalRead(PIN_SELECT))
  {
    // switch is active
    if(iLED[LED_SELECT] == true)
    {
      //maintain color while switch is active
      iLED[LED_SELECT] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_SELECT_ON        //mwolak 11-01-2015 switch between random or solid colors
        setLEDRandomColor(LED_SELECT);  //mappings in kaimana_custom.h
      #else
         kaimana.setLED(LED_SELECT, LED_SELECT_COLOR_ON);
      #endif
      iLED[LED_SELECT] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_SELECT_OFF
        setLEDRandomColor(LED_SELECT);
      #else
        kaimana.setLED(LED_SELECT, LED_SELECT_COLOR_OFF);
      #endif       
      iLED[LED_SELECT] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_START))
  {
    // switch is active
    if(iLED[LED_START] == true)
    {
      //maintain color while switch is active
      iLED[LED_START] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_START_ON        //mwolak 11-01-2015 switch between random or solid colors
        setLEDRandomColor(LED_START);  //mappings in kaimana_custom.h
      #else
         kaimana.setLED(LED_START, LED_START_COLOR_ON);
      #endif
      iLED[LED_START] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_START_OFF
        setLEDRandomColor(LED_START);
      #else
        kaimana.setLED(LED_START, LED_START_COLOR_OFF);
      #endif      
      iLED[LED_START] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_P1))
  {
    switchActivity |= ATTACK_P1;
    
    // switch is active
    if(iLED[LED_P1] == true)
    {
      //maintain color while switch is active
      iLED[LED_P1] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P1_ON
        setLEDRandomColor(LED_P1);
      #else
         kaimana.setLEDhtml(LED_P1, JOY_ON[1]);
      #endif
      iLED[LED_P1] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_P1_OFF
        setLEDRandomColor(LED_P1);
      #else
        kaimana.setLEDhtml(LED_P1, JOY_OFF[1]);
      #endif     
      iLED[LED_P1] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_P2))
  {
    switchActivity |= ATTACK_P2;
    
    // switch is active
    if(iLED[LED_P2] == true)
    {
      //maintain color while switch is active
      iLED[LED_P2] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P2_ON
        setLEDRandomColor(LED_P2);
      #else
         kaimana.setLEDhtml(LED_P2, JOY_ON[2]);
      #endif
      iLED[LED_P2] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_P2_OFF
        setLEDRandomColor(LED_P2);
      #else
        kaimana.setLEDhtml(LED_P2, JOY_OFF[2]);
      #endif    
      iLED[LED_P2] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_P3))
  {
    switchActivity |= ATTACK_P3;
    
    // switch is active
    if(iLED[LED_P3] == true)
    {
      //maintain color while switch is active
      iLED[LED_P3] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P3_ON
        setLEDRandomColor(LED_P3);
      #else
         kaimana.setLEDhtml(LED_P3, JOY_ON[3]);
      #endif
      iLED[LED_P3] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_P3_OFF
        setLEDRandomColor(LED_P3);
      #else
        kaimana.setLEDhtml(LED_P3, JOY_OFF[3]);
      #endif   
      iLED[LED_P3] = false;
  }
  

  // test switch and set LED based on result
  if(!digitalRead(PIN_P4))
  {
    switchActivity |= ATTACK_P4;
    
    // switch is active
    if(iLED[LED_P4] == true)
    {
      //maintain color while switch is active
      iLED[LED_P4] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P4_ON
        setLEDRandomColor(LED_P4);
      #else
         kaimana.setLEDhtml(LED_P4, JOY_ON[4]);
      #endif
      iLED[LED_P4] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_P4_OFF
        setLEDRandomColor(LED_P4);
      #else
        kaimana.setLEDhtml(LED_P4, JOY_OFF[4]);
      #endif 
      iLED[LED_P4] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K1))
  {
    switchActivity |= ATTACK_K1;
    
    // switch is active
    if(iLED[LED_K1] == true)
    {
      //maintain color while switch is active
      iLED[LED_K1] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K1_ON
        setLEDRandomColor(LED_K1);
      #else
         kaimana.setLEDhtml(LED_K1, JOY_ON[5]);
      #endif
      iLED[LED_K1] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_K1_OFF
        setLEDRandomColor(LED_K1);
      #else
        kaimana.setLEDhtml(LED_K1, JOY_OFF[5]);
      #endif    
      iLED[LED_K1] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K2))
  {
    switchActivity |= ATTACK_K2;
    
    // switch is active
    if(iLED[LED_K2] == true)
    {
      //maintain color while switch is active
      iLED[LED_K2] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K2_ON
        setLEDRandomColor(LED_K2);
      #else
         kaimana.setLEDhtml(LED_K2, JOY_ON[6]);
      #endif
      iLED[LED_K2] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_K2_OFF
        setLEDRandomColor(LED_K2);
      #else
        kaimana.setLEDhtml(LED_K2, JOY_OFF[6]);
      #endif      
      iLED[LED_K2] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K3))
  {
    switchActivity |= ATTACK_K3;
    
    // switch is active
    if(iLED[LED_K3] == true)
    {
      //maintain color while switch is active
      iLED[LED_K3] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K3_ON
        setLEDRandomColor(LED_K3);
      #else
         kaimana.setLEDhtml(LED_K3, JOY_ON[7]);
      #endif
      iLED[LED_K3] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_K3_OFF
        setLEDRandomColor(LED_K3);
      #else
        kaimana.setLEDhtml(LED_K3, JOY_OFF[7]);
      #endif    
      iLED[LED_K3] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K4))
  {
    switchActivity |= ATTACK_K4;
    
    // switch is active
    if(iLED[LED_K4] == true)
    {
      //maintain color while switch is active
      iLED[LED_K4] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K4_ON
        setLEDRandomColor(LED_K4);
      #else
         kaimana.setLEDhtml(LED_K4, JOY_ON[8]);
      #endif
      iLED[LED_K4] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_K4_OFF
        setLEDRandomColor(LED_K4);
      #else
        kaimana.setLEDhtml(LED_K4, JOY_OFF[8]);
      #endif       
      iLED[LED_K4] = false;
  }



  // convert joystick, P1-P4, K1-K4 into a single unsigned int
  switchActivity = joystickDirection + switchActivity;
  kaimana.switchHistorySet(switchActivity);
  

  // test for combinations from most complext to least complex
  // test for switches in reverse order (newest to oldest)


  // combo #6
  // test for: Ultra 2 (Metsu Shoryuken)
  // combo is: DOWN, DOWN+RIGHT, RIGHT, DOWN, DOWN+RIGHT, RIGHT, RIGHT+K3
  if( kaimana.switchHistoryTest( COMBO_PATTERN_6A ) )
      animation_combo_6();

  // combo #5
  // test for: Ultra 1 (Metsu Hadouken)
  // combo is: DOWN, DOWN+RIGHT, RIGHT, <NONE>, DOWN, DOWN+RIGHT, RIGHT, RIGHT+P3
  if( kaimana.switchHistoryTest( COMBO_PATTERN_5A ) )
      animation_combo_5();

  // combo #4
  // test for: Super (Shinkuu Hadouken)
  // combo is: DOWN, DOWN+RIGHT, RIGHT, <NONE>, DOWN, DOWN+RIGHT, RIGHT, RIGHT+P1
  if( kaimana.switchHistoryTest( COMBO_PATTERN_4A ) )
      animation_combo_4();

  // combo #3
  // test for: Tatsumaki Senpukyaku (Hurricane Kick)
  // combo is: DOWN, DOWN+LEFT, LEFT, LEFT+K1 or LEFT+K2
  if( kaimana.switchHistoryTest( COMBO_PATTERN_3A ) )
      animation_combo_3();
  if( kaimana.switchHistoryTest( COMBO_PATTERN_3B ) )
      animation_combo_3();

  // combo #2
  // test for: Ryu Shoryuken (Dragon Punch)
  // combo is: RIGHT, <NONE>, DOWN, DOWN+RIGHT, DOWN+RIGHT+P1 or DOWN+RIGHT+P2
  if( kaimana.switchHistoryTest( COMBO_PATTERN_2A ) )
      animation_combo_2();
  if( kaimana.switchHistoryTest( COMBO_PATTERN_2B ) )
      animation_combo_2();

  // combo #1
  // test for: Ryu Hadouken (Fireball) 
  // combo is: DOWN, DOWN+RIGHT, RIGHT, RIGHT+P1 or RIGHT+P2  
  if( kaimana.switchHistoryTest( COMBO_PATTERN_1A ) )
      animation_combo_1();
  if( kaimana.switchHistoryTest( COMBO_PATTERN_1B ) )
      animation_combo_1();


  // zero active switch counter (note: 4 way joystick counts as 1)
  iActiveSwitchCount = 0;
  
  // set LED color based on switch
  for(i=0;i<LED_COUNT;++i)
  {
    if(iLED[i] == true)
      ++iActiveSwitchCount;
  }  

  // update the leds with new/current colors in the array
  kaimana.updateALL();
  
  // return number of active switches
  return(iActiveSwitchCount);
}  



 

