#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "Scene.h"
#include "Agent.h"
#include "Seek.h"
#include "PathFollowing.h"
#include "Grid.h"
#include "FSM.h"
#include "GreedyBFS.h"
#include "PathFindingGraph.h"

class SceneFSM :
	public Scene
{
public:
	SceneFSM();
	~SceneFSM();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
	Vector2D GetRandomGridPos();

private:
	std::vector<Agent*> agents;
	Vector2D coinPosition;

	Grid *maze;
	bool draw_grid;
	
	FSM algorithmFSM;

	int _numberOfEnemies = 0;
	std::vector<Agent*> zomboAgents;

	GreedyBFS* greedyBFS;
	PathFindingGraph* graph;

	void drawMaze();
	void drawCoin();
	SDL_Texture *background_texture;
	SDL_Texture *coin_texture;
	bool loadTextures(char* filename_bg, char* filename_coin);

	void DoGreedyBFS(Agent* _agent);
	void InitEnemies();
};
