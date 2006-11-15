// create worldModel::fields, partys, units etc.

#ifndef INIT_H_DEF
#define INIT_H_DEF

class Init {
	private:
		static void createWorld(int x, int y);
		static void createEdges();
		static void calcFields();
		static void newHeroes(const int);
		static void newUnits(int);
		static void newGoldMines();
		static void newVillages();
		static void newPartys(int);
		static void menu();
	public:
		static void start();
};
#endif