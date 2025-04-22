#pragma once

/**
 * Used as a mask when testing buttons in buttonstate.
 *
 * - Button 1: Left mouse button
 * - Button 2: Middle mouse button
 * - Button 3: Right mouse button
 */
// From ENG_mouse.h
#define ENG_BUTTON(X)       (1 << ((X)-1))
#define ENG_BUTTON_LEFT     1
#define ENG_BUTTON_MIDDLE   2
#define ENG_BUTTON_RIGHT    3
#define ENG_BUTTON_X1       4
#define ENG_BUTTON_X2       5
#define ENG_BUTTON_LMASK    ENG_BUTTON(ENG_BUTTON_LEFT)
#define ENG_BUTTON_MMASK    ENG_BUTTON(ENG_BUTTON_MIDDLE)
#define ENG_BUTTON_RMASK    ENG_BUTTON(ENG_BUTTON_RIGHT)
#define ENG_BUTTON_X1MASK   ENG_BUTTON(ENG_BUTTON_X1)
#define ENG_BUTTON_X2MASK   ENG_BUTTON(ENG_BUTTON_X2)