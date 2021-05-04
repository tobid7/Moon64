#ifndef MOON_WRAPPER
#define MOON_WRAPPER
#ifndef __cplusplus

#include "types.h"

void moon_init_languages(char *executable, char *gamedir);
u8 * moon_language_get_key( char* key );
void moon_set_language( int id );
const char* moon_get_language_name( int id );

void moon_draw_ui();
void moon_change_ui(int index);
u8   moon_ui_open();
void moon_ui_toggle();

void moon_modules_init();
void moon_modules_update();
void moon_update_window(void* window);

#endif
#endif