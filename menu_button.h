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
		float x1;			// image coordinates
		float x2;
		float y1;
		float y2;
		int id;				
		MenuButton() { };
		virtual void drawBorders();
	private:
		void (*function)(int button, MenuButton*);	//usually called by click() function	
	public:
		
		MenuButton(float x1, float x2, float y1, float y2, void (*function)(int,MenuButton*), int id);
		
			
		virtual void draw();
		int getX1();
		int getX2();
		int getY1();
		int getY2();
		virtual void click(int button);				// what to do on mouseclick
		


	
};
#endif