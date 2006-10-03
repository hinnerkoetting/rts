/////////////////////////////////////////////////////////////////
//
//					
//					errors.h
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "windows.h"
#include "errors.h"
/*
 *
 *message box
 *
 */
void Error::MesBoxOk(char* chText, char* chTitel) {
	MessageBoxEx(0, chText, chTitel, MB_OK, LANG_ENGLISH);
}