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
	protected:
		static int counter;
		float x1;			// window coordinates
		float x2;
		float y1;
		float y2;
		int id;
	
		virtual void drawBorders();
	private:
			
	public:
		int value;
		MenuButton(float x1, float x2, float y1, float y2, void (*function)(int,MenuButton*));
		MenuButton() { };
		void (*function)(int button, MenuButton*);		// what to do on mouseclick
		virtual void draw();
		int getX1();
		int getX2();
		int getY1();
		int getY2();
		


	
};
#endif