#pragma once

// From SDL_scancode.h
#define ENG_SCANCODE_A   4 
#define ENG_SCANCODE_B   5 
#define ENG_SCANCODE_C   6 
#define ENG_SCANCODE_D   7 
#define ENG_SCANCODE_E   8 
#define ENG_SCANCODE_F   9 
#define ENG_SCANCODE_G   10 
#define ENG_SCANCODE_H   11 
#define ENG_SCANCODE_I   12 
#define ENG_SCANCODE_J   13 
#define ENG_SCANCODE_K   14 
#define ENG_SCANCODE_L   15 
#define ENG_SCANCODE_M   16 
#define ENG_SCANCODE_N   17 
#define ENG_SCANCODE_O   18 
#define ENG_SCANCODE_P   19 
#define ENG_SCANCODE_Q   20 
#define ENG_SCANCODE_R   21 
#define ENG_SCANCODE_S   22 
#define ENG_SCANCODE_T   23 
#define ENG_SCANCODE_U   24 
#define ENG_SCANCODE_V   25 
#define ENG_SCANCODE_W   26 
#define ENG_SCANCODE_X   27 
#define ENG_SCANCODE_Y   28 
#define ENG_SCANCODE_Z   29 

#define ENG_SCANCODE_1   30 
#define ENG_SCANCODE_2   31 
#define ENG_SCANCODE_3   32 
#define ENG_SCANCODE_4   33 
#define ENG_SCANCODE_5   34 
#define ENG_SCANCODE_6   35 
#define ENG_SCANCODE_7   36 
#define ENG_SCANCODE_8   37 
#define ENG_SCANCODE_9   38 
#define ENG_SCANCODE_0   39 

#define ENG_SCANCODE_RETURN   40 
#define ENG_SCANCODE_ESCAPE   41 
#define ENG_SCANCODE_BACKSPACE   42 
#define ENG_SCANCODE_TAB   43 
#define ENG_SCANCODE_SPACE   44 

#define ENG_SCANCODE_MINUS   45 
#define ENG_SCANCODE_EQUALS   46 
#define ENG_SCANCODE_LEFTBRACKET   47 
#define ENG_SCANCODE_RIGHTBRACKET   48 
#define ENG_SCANCODE_BACKSLASH   49  /**< Located at the lower left of the return
                              *   key on ISO keyboards and at the right end
                              *   of the QWERTY row on ANSI keyboards.
                              *   Produces REVERSE SOLIDUS (backslash) and
                              *   VERTICAL LINE in a US layout  REVERSE
                              *   SOLIDUS and VERTICAL LINE in a UK Mac
                              *   layout  NUMBER SIGN and TILDE in a UK
                              *   Windows layout  DOLLAR SIGN and POUND SIGN
                              *   in a Swiss German layout  NUMBER SIGN and
                              *   APOSTROPHE in a German layout  GRAVE
                              *   ACCENT and POUND SIGN in a French Mac
                              *   layout  and ASTERISK and MICRO SIGN in a
                              *   French Windows layout.
                              */
    #define ENG_SCANCODE_NONUSHASH   50  /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key  but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So  as an implementor  unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently 
                                  *   you should generate #define ENG_SCANCODE_BACKSLASH
                                  *   instead of this code. As a user  you
                                  *   should not rely on this code because #define ENG
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    #define ENG_SCANCODE_SEMICOLON   51 
    #define ENG_SCANCODE_APOSTROPHE   52 
    #define ENG_SCANCODE_GRAVE   53  /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards  GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout  SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards  SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards)  CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards)  SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout  COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards  and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German  German  or French Mac
                              *   layout on ANSI keyboards.
                              */
    #define ENG_SCANCODE_COMMA   54 
    #define ENG_SCANCODE_PERIOD   55 
    #define ENG_SCANCODE_SLASH   56 

    #define ENG_SCANCODE_CAPSLOCK   57 

    #define ENG_SCANCODE_F1   58 
    #define ENG_SCANCODE_F2   59 
    #define ENG_SCANCODE_F3   60 
    #define ENG_SCANCODE_F4   61 
    #define ENG_SCANCODE_F5   62 
    #define ENG_SCANCODE_F6   63 
    #define ENG_SCANCODE_F7   64 
    #define ENG_SCANCODE_F8   65 
    #define ENG_SCANCODE_F9   66 
    #define ENG_SCANCODE_F10   67 
    #define ENG_SCANCODE_F11   68 
    #define ENG_SCANCODE_F12   69 

    #define ENG_SCANCODE_PRINTSCREEN   70 
    #define ENG_SCANCODE_SCROLLLOCK   71 
    #define ENG_SCANCODE_PAUSE   72 
    #define ENG_SCANCODE_INSERT   73  /**< insert on PC  help on some Mac keyboards (but
                                   does send code 73  not 117) */
    #define ENG_SCANCODE_HOME   74 
    #define ENG_SCANCODE_PAGEUP   75 
    #define ENG_SCANCODE_DELETE   76 
    #define ENG_SCANCODE_END   77 
    #define ENG_SCANCODE_PAGEDOWN   78 
    #define ENG_SCANCODE_RIGHT   79 
    #define ENG_SCANCODE_LEFT   80 
    #define ENG_SCANCODE_DOWN   81 
    #define ENG_SCANCODE_UP   82 

    #define ENG_SCANCODE_NUMLOCKCLEAR   83  /**< num lock on PC  clear on Mac keyboards
                                     */
    #define ENG_SCANCODE_KP_DIVIDE   84 
    #define ENG_SCANCODE_KP_MULTIPLY   85 
    #define ENG_SCANCODE_KP_MINUS   86 
    #define ENG_SCANCODE_KP_PLUS   87 
    #define ENG_SCANCODE_KP_ENTER   88 
    #define ENG_SCANCODE_KP_1   89 
    #define ENG_SCANCODE_KP_2   90 
    #define ENG_SCANCODE_KP_3   91 
    #define ENG_SCANCODE_KP_4   92 
    #define ENG_SCANCODE_KP_5   93 
    #define ENG_SCANCODE_KP_6   94 
    #define ENG_SCANCODE_KP_7   95 
    #define ENG_SCANCODE_KP_8   96 
    #define ENG_SCANCODE_KP_9   97 
    #define ENG_SCANCODE_KP_0   98 
    #define ENG_SCANCODE_KP_PERIOD   99 

    #define ENG_SCANCODE_NONUSBACKSLASH   100  /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones 
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout  REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout  and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German  German  or French
                                        *   layout. */
    #define ENG_SCANCODE_APPLICATION   101  /**< windows contextual menu  compose */
    #define ENG_SCANCODE_POWER   102  /**< The USB document says this is a status flag 
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
    #define ENG_SCANCODE_KP_EQUALS   103 
    #define ENG_SCANCODE_F13   104 
    #define ENG_SCANCODE_F14   105 
    #define ENG_SCANCODE_F15   106 
    #define ENG_SCANCODE_F16   107 
    #define ENG_SCANCODE_F17   108 
    #define ENG_SCANCODE_F18   109 
    #define ENG_SCANCODE_F19   110 
    #define ENG_SCANCODE_F20   111 
    #define ENG_SCANCODE_F21   112 
    #define ENG_SCANCODE_F22   113 
    #define ENG_SCANCODE_F23   114 
    #define ENG_SCANCODE_F24   115 
    #define ENG_SCANCODE_EXECUTE   116 
    #define ENG_SCANCODE_HELP   117     /**< AL Integrated Help Center */
    #define ENG_SCANCODE_MENU   118     /**< Menu (show menu) */
    #define ENG_SCANCODE_SELECT   119 
    #define ENG_SCANCODE_STOP   120     /**< AC Stop */
    #define ENG_SCANCODE_AGAIN   121    /**< AC Redo/Repeat */
    #define ENG_SCANCODE_UNDO   122     /**< AC Undo */
    #define ENG_SCANCODE_CUT   123      /**< AC Cut */
    #define ENG_SCANCODE_COPY   124     /**< AC Copy */
    #define ENG_SCANCODE_PASTE   125    /**< AC Paste */
    #define ENG_SCANCODE_FIND   126     /**< AC Find */
    #define ENG_SCANCODE_MUTE   127 
    #define ENG_SCANCODE_VOLUMEUP   128 
    #define ENG_SCANCODE_VOLUMEDOWN   129 
    /* not sure whether there's a reason to enable these */
    /*     #define ENG_SCANCODE_LOCKINGCAPSLOCK   130   */
    /*     #define ENG_SCANCODE_LOCKINGNUMLOCK   131  */
    /*     #define ENG_SCANCODE_LOCKINGSCROLLLOCK   132  */
    #define ENG_SCANCODE_KP_COMMA   133 
    #define ENG_SCANCODE_KP_EQUALSAS400   134 

    #define ENG_SCANCODE_INTERNATIONAL1   135  /**< used on Asian keyboards  see
                                            footnotes in USB doc */
    #define ENG_SCANCODE_INTERNATIONAL2   136 
    #define ENG_SCANCODE_INTERNATIONAL3   137  /**< Yen */
    #define ENG_SCANCODE_INTERNATIONAL4   138 
    #define ENG_SCANCODE_INTERNATIONAL5   139 
    #define ENG_SCANCODE_INTERNATIONAL6   140 
    #define ENG_SCANCODE_INTERNATIONAL7   141 
    #define ENG_SCANCODE_INTERNATIONAL8   142 
    #define ENG_SCANCODE_INTERNATIONAL9   143 
    #define ENG_SCANCODE_LANG1   144  /**< Hangul/English toggle */
    #define ENG_SCANCODE_LANG2   145  /**< Hanja conversion */
    #define ENG_SCANCODE_LANG3   146  /**< Katakana */
    #define ENG_SCANCODE_LANG4   147  /**< Hiragana */
    #define ENG_SCANCODE_LANG5   148  /**< Zenkaku/Hankaku */
    #define ENG_SCANCODE_LANG6   149  /**< reserved */
    #define ENG_SCANCODE_LANG7   150  /**< reserved */
    #define ENG_SCANCODE_LANG8   151  /**< reserved */
    #define ENG_SCANCODE_LANG9   152  /**< reserved */

    #define ENG_SCANCODE_ALTERASE   153     /**< Erase-Eaze */
    #define ENG_SCANCODE_SYSREQ   154 
    #define ENG_SCANCODE_CANCEL   155       /**< AC Cancel */
    #define ENG_SCANCODE_CLEAR   156 
    #define ENG_SCANCODE_PRIOR   157 
    #define ENG_SCANCODE_RETURN2   158 
    #define ENG_SCANCODE_SEPARATOR   159 
    #define ENG_SCANCODE_OUT   160 
    #define ENG_SCANCODE_OPER   161 
    #define ENG_SCANCODE_CLEARAGAIN   162 
    #define ENG_SCANCODE_CRSEL   163 
    #define ENG_SCANCODE_EXSEL   164 

    #define ENG_SCANCODE_KP_00   176 
    #define ENG_SCANCODE_KP_000   177 
    #define ENG_SCANCODE_THOUSANDSSEPARATOR   178 
    #define ENG_SCANCODE_DECIMALSEPARATOR   179 
    #define ENG_SCANCODE_CURRENCYUNIT   180 
    #define ENG_SCANCODE_CURRENCYSUBUNIT   181 
    #define ENG_SCANCODE_KP_LEFTPAREN   182 
    #define ENG_SCANCODE_KP_RIGHTPAREN   183 
    #define ENG_SCANCODE_KP_LEFTBRACE   184 
    #define ENG_SCANCODE_KP_RIGHTBRACE   185 
    #define ENG_SCANCODE_KP_TAB   186 
    #define ENG_SCANCODE_KP_BACKSPACE   187 
    #define ENG_SCANCODE_KP_A   188 
    #define ENG_SCANCODE_KP_B   189 
    #define ENG_SCANCODE_KP_C   190 
    #define ENG_SCANCODE_KP_D   191 
    #define ENG_SCANCODE_KP_E   192 
    #define ENG_SCANCODE_KP_F   193 
    #define ENG_SCANCODE_KP_XOR   194 
    #define ENG_SCANCODE_KP_POWER   195 
    #define ENG_SCANCODE_KP_PERCENT   196 
    #define ENG_SCANCODE_KP_LESS   197 
    #define ENG_SCANCODE_KP_GREATER   198 
    #define ENG_SCANCODE_KP_AMPERSAND   199 
    #define ENG_SCANCODE_KP_DBLAMPERSAND   200 
    #define ENG_SCANCODE_KP_VERTICALBAR   201 
    #define ENG_SCANCODE_KP_DBLVERTICALBAR   202 
    #define ENG_SCANCODE_KP_COLON   203 
    #define ENG_SCANCODE_KP_HASH   204 
    #define ENG_SCANCODE_KP_SPACE   205 
    #define ENG_SCANCODE_KP_AT   206 
    #define ENG_SCANCODE_KP_EXCLAM   207 
    #define ENG_SCANCODE_KP_MEMSTORE   208 
    #define ENG_SCANCODE_KP_MEMRECALL   209 
    #define ENG_SCANCODE_KP_MEMCLEAR   210 
    #define ENG_SCANCODE_KP_MEMADD   211 
    #define ENG_SCANCODE_KP_MEMSUBTRACT   212 
    #define ENG_SCANCODE_KP_MEMMULTIPLY   213 
    #define ENG_SCANCODE_KP_MEMDIVIDE   214 
    #define ENG_SCANCODE_KP_PLUSMINUS   215 
    #define ENG_SCANCODE_KP_CLEAR   216 
    #define ENG_SCANCODE_KP_CLEARENTRY   217 
    #define ENG_SCANCODE_KP_BINARY   218 
    #define ENG_SCANCODE_KP_OCTAL   219 
    #define ENG_SCANCODE_KP_DECIMAL   220 
    #define ENG_SCANCODE_KP_HEXADECIMAL   221 

    #define ENG_SCANCODE_LCTRL   224 
    #define ENG_SCANCODE_LSHIFT   225 
    #define ENG_SCANCODE_LALT   226  /**< alt  option */
    #define ENG_SCANCODE_LGUI   227  /**< windows  command (apple)  meta */
    #define ENG_SCANCODE_RCTRL   228 
    #define ENG_SCANCODE_RSHIFT   229 
    #define ENG_SCANCODE_RALT   230  /**< alt gr  option */
    #define ENG_SCANCODE_RGUI   231  /**< windows  command (apple)  meta */

    #define ENG_SCANCODE_MODE   257     /**< I'm not sure if this is really not covered
                                 *   by any of the above  but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

                                 /* @} *//* Usage page 0x07 */

                                 /**
                                  *  \name Usage page 0x0C
                                  *
                                  *  These values are mapped from usage page 0x0C (USB consumer page).
                                  *  See https://usb.org/sites/default/files/hut1_2.pdf
                                  *
                                  *  There are way more keys in the spec than we can represent in the
                                  *  current scancode range  so pick the ones that commonly come up in
                                  *  real world usage.
                                  */
                                  /* @{ */

    #define ENG_SCANCODE_AUDIONEXT   258 
    #define ENG_SCANCODE_AUDIOPREV   259 
    #define ENG_SCANCODE_AUDIOSTOP   260 
    #define ENG_SCANCODE_AUDIOPLAY   261 
    #define ENG_SCANCODE_AUDIOMUTE   262 
    #define ENG_SCANCODE_MEDIASELECT   263 
    #define ENG_SCANCODE_WWW   264              /**< AL Internet Browser */
    #define ENG_SCANCODE_MAIL   265 
    #define ENG_SCANCODE_CALCULATOR   266       /**< AL Calculator */
    #define ENG_SCANCODE_COMPUTER   267 
    #define ENG_SCANCODE_AC_SEARCH   268        /**< AC Search */
    #define ENG_SCANCODE_AC_HOME   269          /**< AC Home */
    #define ENG_SCANCODE_AC_BACK   270          /**< AC Back */
    #define ENG_SCANCODE_AC_FORWARD   271       /**< AC Forward */
    #define ENG_SCANCODE_AC_STOP   272          /**< AC Stop */
    #define ENG_SCANCODE_AC_REFRESH   273       /**< AC Refresh */
    #define ENG_SCANCODE_AC_BOOKMARKS   274     /**< AC Bookmarks */

    /* @} *//* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
     /* @{ */

    #define ENG_SCANCODE_BRIGHTNESSDOWN   275 
    #define ENG_SCANCODE_BRIGHTNESSUP   276 
    #define ENG_SCANCODE_DISPLAYSWITCH   277  /**< display mirroring/dual display
                                           switch  video mode switch */
    #define ENG_SCANCODE_KBDILLUMTOGGLE   278 
    #define ENG_SCANCODE_KBDILLUMDOWN   279 
    #define ENG_SCANCODE_KBDILLUMUP   280 
    #define ENG_SCANCODE_EJECT   281 
    #define ENG_SCANCODE_SLEEP   282            /**< SC System Sleep */

    #define ENG_SCANCODE_APP1   283 
    #define ENG_SCANCODE_APP2   284 

    /* @} *//* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
     /* @{ */

    #define ENG_SCANCODE_AUDIOREWIND   285 
    #define ENG_SCANCODE_AUDIOFASTFORWARD   286 

    /* @} *//* Usage page 0x0C (additional media keys) */

    /**
     *  \name Mobile keys
     *
     *  These are values that are often used on mobile phones.
     */
     /* @{ */

    #define ENG_SCANCODE_SOFTLEFT   287  /**< Usually situated below the display on phones and
                                      used as a multi-function feature key for selecting
                                      a software defined function shown on the bottom left
                                      of the display. */
    #define ENG_SCANCODE_SOFTRIGHT   288  /**< Usually situated below the display on phones and
                                       used as a multi-function feature key for selecting
                                       a software defined function shown on the bottom right
                                       of the display. */
    #define ENG_SCANCODE_CALL   289  /**< Used for accepting phone calls. */
    #define ENG_SCANCODE_ENDCALL   290  /**< Used for rejecting phone calls. */

    /* @} *//* Mobile keys */

    /* Add any other keys here. */

    #define ENG_NUM_SCANCODES   512 /**< not a key  just marks the number of scancodes
                                 for array bounds */