/////////////////////////////////////////////////////////////////
//
//					
//					input.h
//					_Input class
//					
//
/////////////////////////////////////////////////////////////////
#ifndef INPUT_H_DEF
#define INPUT_H_DEF
class _Input {
	public:
		bool pressed;				// key is pressed
		bool locked;				// if key is hold
		int iIntervallHold;			// time key is hold
};
#endif