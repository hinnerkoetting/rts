/////////////////////////////////////////////////////////////////
//
//					
//					menu_button.h
//					
//					
//
/////////////////////////////////////////////////////////////////
#ifndef DEF_MENUBUTTON
#define DEF_MENUBUTTON


class MenuButton {
	private:
		static int counter;

		
	public:
		MenuButton(int x1, int x2, int y1, int y2, void (*function)(int));
		void (*function)(int button);		// what to do on mouseclick
		void draw();
		//MenuButton* nextButton;
		int x1;			// window coordinates
		int x2;
		int y1;
		int y2;
		int id;		

	
};
#endif