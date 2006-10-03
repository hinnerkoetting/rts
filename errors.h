/////////////////////////////////////////////////////////////////
//
//					
//					errors.h
//					structs of errors
//					
//
/////////////////////////////////////////////////////////////////

#ifndef ERRORS_H_DEF
#define ERRORS_H_DEF


namespace Error {	
	struct err {
	};
	struct _errString {			
		char* pchErr;
		_errString(char* chp) { pchErr = chp; }
	};
	void MesBoxOk(char* chText, char* chTitel);
}
#endif