
//  kaimana_custom.h Generated from jasensCustoms.com Kaimana Khameleon Code Generator
//  KK Code Generator: http://brightstick.freecade.org
//  Code is provided for entertainment purposes and use with the Kaimana Khameleon and Panzer Fight Stick 2.
//  Code may be copied, modified, resused with this Copyright notice.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  Based on code originally released by ParadiseArcadeShop.com
//  Generator Created:  November 4, 2015    jasenhicks // jasenscustoms.com -- Cavalier Mannitude Encouragement
//
// THIS FILE GENERATED ON: Wednesday 15th of April 2020 12:20:21 AM


#ifndef __kaimana_local_h__
#define __kaimana_local_h__
#define __PROG_TYPES_COMPAT__
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "Arduino.h"
#include "kaimana.h"


const long VIRTUA_ON[12] = {0x00FF55, 0x00FF55, 0x00FF55, 0x00FF55, 0x00FF55, 0x0080FF, 0xFF8080, 0x00FF55, 0x00FF55, 0xFF0000, 0xFF0000, 0xFF0000};
const long VIRTUA_OFF[12] = {0x00CC55, 0x00CC55, 0x00CC55, 0x00CC55, 0x00CC55, 0x0080CC, 0xCC8080, 0x00CC55, 0x00CC55, 0xCC0000, 0xCC0000, 0xCC0000};

// Nintendo Style
# define JOY_BUTTONS           = {     JOY,       P1,       P2,       P3,       P4,       K1,       K2,       K3,       K4, };
# define PSX_BUTTONS           = {     JOY,   SQUARE, TRIANGLE,       R1,       L1,    CROSS,   CIRCLE,       R2,       L2, };
const long ARCADE_OFF[12]      = {0xCCCCCC, 0xCC0000, 0xCCCCCC, 0x0000CC, 0x0000CC, 0xCC0000, 0xCCCCCC, 0x000000, 0xCCCC00};
const long ARCADE_ON[12]       = {0xFFFFFF, 0xFF0000, 0xFFFFFF, 0x0000FF, 0x0000FF, 0xFF0000, 0xFFFFFF, 0x000000, 0xFFFF00};
const long NEOGEO_CD_OFF[12]   = {0xCCCCCC, 0x00CC00, 0x0000CC, 0xCCCCCC, 0xCCCCCC, 0xCC0000, 0xCCCC00, 0xCCCCCC, 0xCCCCCC};
const long NEOGEO_CD_ON[12]    = {0xFFFFFF, 0x00FF00, 0x0000FF, 0xFFFFFF, 0xFFFFFF, 0xFF0000, 0xFFFF00, 0xFFFFFF, 0xFFFFFF};
const long NEOGEO_ABCD_OFF[12] = {0xCCCCCC, 0xCC0000, 0xCCCC00, 0xCCCCCC, 0xCCCCCC, 0x00CC00, 0x0000CC, 0xCCCCCC, 0xCCCCCC};
const long NEOGEO_ABCD_ON[12]  = {0xFFFFFF, 0xFF0000, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0x00FF00, 0x0000FF, 0xFFFFFF, 0xFFFFFF};
const long NEOGEO_MINI_OFF[12] = {0xCCCCCC, 0xCC0000, 0x00CC00, 0xCCCCCC, 0xCCCCCC, 0xCCCC00, 0x0000CC, 0xCCCCCC, 0xCCCCCC};
const long NEOGEO_MINI_ON[12]  = {0xFFFFFF, 0xFF0000, 0x00FF00, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0x0000FF, 0xFFFFFF, 0xFFFFFF};
const long NEOGEO_2_OFF[12]    = {0xCCCCCC, 0xCC0000, 0xCCCC00, 0xCCCCCC, 0x00CC00, 0x0000CC, 0xCCCCCC, 0xCCCCCC, 0xCCCCCC};
const long NEOGEO_2_ON[12]     = {0xFFFFFF, 0xFF0000, 0xFFFF00, 0xFFFFFF, 0x00FF00, 0x0000FF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF};
const long NEOGEO_OFF[12]      = {0xCCCCCC, 0xCCCC00, 0x00CC00, 0xCCCCCC, 0x0000CC, 0xCC0000, 0xCCCCCC, 0xCCCCCC, 0xCCCCCC};
const long NEOGEO_ON[12]       = {0xFFFFFF, 0xFFFF00, 0x00FF00, 0xFFFFFF, 0x0000FF, 0xFF0000, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF};
const long NEOGEO_ALT_OFF[12]  = {0xCCCCCC, 0x000000, 0x000000, 0x00CC00, 0x000000, 0xCC0000, 0xCCCC00, 0x0000CC, 0x000000};
const long NEOGEO_ALT_ON[12]   = {0xFFFFFF, 0x000000, 0x000000, 0x00FF00, 0x000000, 0xFF0000, 0xFFFF00, 0x0000FF, 0x000000};
const long GG_OFF[12]          = {0xCCCCCC, 0x000000, 0x000000, 0x00CC66, 0x000000, 0xCC5555, 0x1111CC, 0xCC0000, 0xCC8800};
const long GG_ON[12]           = {0xFFFFFF, 0x000000, 0x000000, 0x00FF66, 0x000000, 0xFF5555, 0x1111FF, 0xFF0000, 0xFF8800};
// Soul Calibur / Tekken Arcade Layout
const long NAMCO_OFF[12]       = {0xCC0000, 0xCC0000, 0xCC0000, 0x000000, 0xCC0000, 0xCCCC00, 0xCCCC00, 0x000000, 0x000000};
const long NAMCO_ON[12]        = {0xFF0000, 0xFF0000, 0xFF0000, 0x000000, 0xFF0000, 0xFFFF00, 0xFFFF00, 0x000000, 0x000000};
const long PLAYSTATION_OFF[12] = {0xCCCCCC, 0xCC5555, 0x00CC66, 0xCCCCCC, 0xCCCCCC, 0x1111CC, 0xFF0000, 0xCCCCCC, 0xCCCCCC};
const long PLAYSTATION_ON[12]  = {0xFFFFFF, 0xFF5555, 0x00FF66, 0xFFFFFF, 0xFFFFFF, 0x1111FF, 0xFF0000, 0xFFFFFF, 0xEEEEEE};
// Namco Playstation Pad Layout
const long TEKKEN_OFF[12]      = {0xDDDD00, 0xCCCC00, 0xCCCC00, 0x000000, 0x000000, 0xCCCC00, 0xCCCC00, 0x000000, 0x000000};
const long TEKKEN_ON[12]       = {0xFFFF00, 0xFFFF00, 0xFFFF00, 0x000000, 0x000000, 0xFFFF00, 0xFFFF00, 0x000000, 0x000000};
const long SATURN_OFF[12]      = {0xCCCCCC, 0xCCCCCC, 0xCCCCCC, 0x0000CC, 0xCCCCCC, 0x00CC00, 0xCCCC00, 0xCC0000, 0xCC0000};
const long SATURN_ON[12]       = {0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0x0000FF, 0xFFFFFF, 0x00FF00, 0xFFFF00, 0xFF0000, 0xFF0000};
const long SFC_OFF[12]         = {0xCCCCCC, 0x00CC00, 0x0000CC, 0xCCCCCC, 0xCCCCCC, 0xCCCC00, 0xCC0000, 0xCCCCCC, 0xCCCCCC};
const long SFC_ON[12]          = {0xFFFFFF, 0x00FF00, 0x0000FF, 0xFFFFFF, 0xFFFFFF, 0xFFFF00, 0xFF0000, 0xFFFFFF, 0xEEEEEE};
const long SNES_OFF[12]        = {0xAAAAAA, 0xDD99DD, 0xDD99DD, 0xAAAAAA, 0xAAAAAA, 0xDD00DD, 0xDD00DD, 0xAAAAAA, 0xAAAAAA};
const long SNES_ON[12]         = {0xFFFFFF, 0xFF99FF, 0xFF99FF, 0xFFFFFF, 0xFFFFFF, 0xFF00FF, 0xFF00FF, 0xFFFFFF, 0xEEEEEE};
const long TATSUNOKO_OFF[12]   = {0xCCCCCC, 0x60AACC, 0x60AACC, 0xCCCCCC, 0x60AACC, 0x60AACC, 0xCCCCCC, 0xCCCCCC, 0xCCCCCC};
const long TATSUNOKO_ON[12]    = {0xFFFFFF, 0x60AAFF, 0x60AAFF, 0xFFFFFF, 0x60AAFF, 0x60AAFF, 0xFFFFFF, 0xFFFFFF, 0xEEEEEE};
const long XBOX_OFF[12]        = {0xCCCCCC, 0x0000CC, 0xCCCC00, 0xCCCCCC, 0xCCCCCC, 0x00CC00, 0xCC0000, 0xCCCCCC, 0xCCCCCC};
const long XBOX_ON[12]         = {0xFFFFFF, 0x0000FF, 0xFFFF00, 0xFFFFFF, 0xFFFFFF, 0x00FF00, 0xFF0000, 0xFFFFFF, 0xFFFFFF};

//ON BUTTON STATE
#define LED_SELECT_COLOR_ON 255,0,0
#define LED_HOME_COLOR_ON 255,0,0
#define LED_START_COLOR_ON 255,0,0


//OFF BUTTON STATE 
#define LED_SELECT_COLOR_OFF 255,0,0
#define LED_HOME_COLOR_OFF 255,0,0
#define LED_START_COLOR_OFF 255,0,0


//RANDOM COLORS SET
#define COLOR_RANDOM_1 255,0,0
#define COLOR_RANDOM_2 255,255,0
#define COLOR_RANDOM_3 255,255,255
#define COLOR_RANDOM_4 0,0,255
#define COLOR_RANDOM_5 0,255,255
#define COLOR_RANDOM_6 255,0,255
#define COLOR_RANDOM_7 127,255,0
#define COLOR_RANDOM_8 255,0,127
  
//BOOT AND IDLE SEQUENCE TIMING
#define  BOOT_COLOR_DELAY         250
#define  BOOT_COMPLETE_DELAY      500
#define  MAIN_LOOP_DELAY           50
#define IDLE_TIMEOUT_SECONDS      300
#define IDLE_ANIMATION_DELAY        8
#define BRIGHTNESS                  1

// R2, JOY, R1, L1, TRI, CIRCLE, SQUARE, CROSS, L2
// 3K, JOY, 3P, 4P, 2P, 2K, 1P, 1K, 4

//LED INDEX
#define  LED_JOY        2
#define  LED_P4         5
#define  LED_P4_B       6
#define  LED_P3         3
#define  LED_P3_B       4
#define  LED_P2         7
#define  LED_P2_B       8
#define  LED_P1         11
#define  LED_P1_B       12
#define  LED_K4         15
#define  LED_K4_B       16
#define  LED_K3         0
#define  LED_K3_B       1
#define  LED_K2         9
#define  LED_K2_B       10
#define  LED_K1         13
#define  LED_K1_B       14
#define  LED_SELECT     17
#define  LED_SELECT_B   18
#define  LED_HOME       19
#define  LED_HOME_B     20
#define  LED_START      21
#define  LED_START_B    22
#define  LED_COUNT      18

#endif
