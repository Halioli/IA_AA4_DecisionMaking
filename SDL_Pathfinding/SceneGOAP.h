#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <map>
#include "Scene.h"
#include "Agent.h"
#include "Seek.h"
#include "PathFollowing.h"
#include "Grid.h"
#include "SceneElements.h"
#include "GOAPWorldState.h"

//class GOAPWorldState;
class KeyElement;

class SceneGOAP :
	public Scene
{
public:
	char* color_strings[8] = { "White", "Black", "Red", "Orange", "Yellow", "Green", "Blue", "Purple" };

	SceneGOAP();
	~SceneGOAP();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
	std::vector<Agent*> agents;
	Vector2D coinPosition;
	Vector2D keyPositions[8];

	Grid *maze;
	bool draw_grid;

	GOAPWorldState worldState;
	std::vector<KeyElement*> keyElements;

	// This map st wores the information of the current world state (keys / coin collected)
	//std::map<SceneElements, bool> worldState;
	// TODO:
	// - Implement neighbour system correctly (compare precondition with worldState & update it)
		// - Neighbours will have a map of type <SceneElements, bool> (we will need to include the header file).
			// - This variable will store the preconditions of the said key (ex: map<Blue, true> means -> Needs Blue key).
		// - Neighbours will have another map of type <SceneElements, bool>.
			// - This variable will store the effects of the said key.
		
	void drawMaze();
	void drawCoin();
	SDL_Texture *background_texture;
	SDL_Texture *coin_texture;
	SDL_Texture *keys_texture;
	bool loadTextures(char* filename_bg, char* filename_coin, char* filename_keys);
};
