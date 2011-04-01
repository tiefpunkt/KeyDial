#define MOD_CONTROL_LEFT    (1<<0)
#define MOD_SHIFT_LEFT      (1<<1)
#define MOD_ALT_LEFT        (1<<2)
#define MOD_GUI_LEFT        (1<<3)
#define MOD_CONTROL_RIGHT   (1<<4)
#define MOD_SHIFT_RIGHT     (1<<5)
#define MOD_ALT_RIGHT       (1<<6)
#define MOD_GUI_RIGHT       (1<<7)

#define KEY_A       4
#define KEY_B       5
#define KEY_C       6
#define KEY_D       7
#define KEY_E       8
#define KEY_F       9
#define KEY_G       10
#define KEY_H       11
#define KEY_I       12
#define KEY_J       13
#define KEY_K       14
#define KEY_L       15
#define KEY_M       16
#define KEY_N       17
#define KEY_O       18
#define KEY_P       19
#define KEY_Q       20
#define KEY_R       21
#define KEY_S       22
#define KEY_T       23
#define KEY_U       24
#define KEY_V       25
#define KEY_W       26
#define KEY_X       27
#define KEY_Y       28
#define KEY_Z       29
#define KEY_1       30
#define KEY_2       31
#define KEY_3       32
#define KEY_4       33
#define KEY_5       34
#define KEY_6       35
#define KEY_7       36
#define KEY_8       37
#define KEY_9       38
#define KEY_0       39

#define KEY_ENTER   40
#define KEY_SPACE   44
#define KEY_RARROW  79
#define KEY_LARROW  80
#define KEY_DOWN  81
#define KEY_UP    82

#define KEY_F1      58
#define KEY_F2      59
#define KEY_F3      60
#define KEY_F4      61
#define KEY_F5      62
#define KEY_F6      63
#define KEY_F7      64
#define KEY_F8      65
#define KEY_F9      66
#define KEY_F10     67
#define KEY_F11     68
#define KEY_F12     69

static const uchar  keyReport[17][2] PROGMEM = {
/* none */  {0, 0},                     /* no key pressed */
/*  1 */    {0, KEY_A},//hoch
/*  2 */    {0, KEY_B},//runter
/*  3 */    {MOD_SHIFT_RIGHT, KEY_LARROW},  //links
/*  4 */    {MOD_SHIFT_RIGHT, KEY_RARROW},  //rechts
/*  5 */    {0, KEY_ENTER},          //OK
/*  6 */    {0, KEY_N},            //CH+
/*  7 */    {0, KEY_P},            //CH-
/*  8 */    {MOD_CONTROL_LEFT, KEY_UP},    //Vol+
/*  9 */    {MOD_CONTROL_LEFT, KEY_DOWN},  //Vol-
/* 10 */    {0, KEY_P},            //rewind
/* 11 */    {0, KEY_SPACE},          //play
/* 12 */    {0, KEY_N},            //forward
/* 13 */    {0, KEY_S},            //stop
/* 14 */    {0, KEY_SPACE},          //pause
/* 15 */    {MOD_ALT_RIGHT, KEY_D},      //videotext, DualView
/* 16 */    {MOD_ALT_LEFT, KEY_F4},      //ausschalten

};
