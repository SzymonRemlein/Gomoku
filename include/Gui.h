#ifndef GUI_H
#define GUI_H

#include<string.h>
#include<fstream>
#include"resources.h"
#include"button.h"

enum type { BASIC = 1, BEST_OF_THREE, BEST_OF_FIVE, BEST_OF_SEVEN, AMOUNT };
enum positionSign { HORIZONTALLY, VERTICALLY, DIAGONALLY };
enum Playrt { NONE, FIRST_PLAYER, SECOND_PLAYER };

class Gui  
{

private:
	sf::RenderWindow* window;
	sf::Sprite background;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Font font;
	GameState gameState;

	sf::Texture texture;

	std::string typeGame;
	std::string name;

	std::fstream stream;

	int basicVariable;
	int frame;

	short WIDTH;
	short HEIGHT;
	short variable;
	short player;
	short sendPlayer;

	bool start;
	bool vsync;


public:

	Gui();
	~Gui();
	

	void initVariables();
	void addBackground();
	void initFonts();
	void addWindow();


	void mousePosition();


	const sf::Vector2f& getMousePos()const;
 sf::RenderWindow* getWindow();
 sf::RenderTarget* getTarget();
	const sf::Font& getFont()const;
	GameState& getGameState();
	const sf::Sprite& getBackground() const;
	const sf::Texture& getTexture()const;

	void renderBackground(sf::RenderTarget* target);


	const short& getHEIGHT()const;
	const short& getWIDTH()const;
	 short& getVariable();

	 int& getBasicVariable();
	 short& getPlayer();
	 short& getSendPlayer();
	 bool& startStatus();

	 std::string& getTypeGame();

};

#endif