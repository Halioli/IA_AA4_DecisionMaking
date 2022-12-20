#include "SceneFSM.h"

using namespace std;

SceneFSM::SceneFSM()
{
	draw_grid = false;
	maze = new Grid("../res/maze.csv");

	loadTextures("../res/maze.png", "../res/coin.png");

	graph = new PathFindingGraph(maze->getNumCellX(), maze->getNumCellY(), maze);
	greedyBFS = new GreedyBFS();

	srand((unsigned int)time(NULL));

	Agent *agent = new Agent;
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agent->setBehavior(new PathFollowing);
	agent->setTarget(Vector2D(-20,-20));
	agent->SetDecisionMakingAlgorithm(algorithmFSM);
	agent->SetHasWeapon(false); // Som mamahuevos.
	agents.push_back(agent);

	// set agent position coords to the center of a random cell
	Vector2D rand_cell(-1,-1);
	while (!maze->isValidCell(rand_cell))
		rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	agents[0]->setPosition(maze->cell2pix(rand_cell));

	// set the coin in a random cell (but at least 3 cells far from the agent)
	coinPosition = Vector2D(-1,-1);
	while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, rand_cell)<3))
		coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
}

SceneFSM::~SceneFSM()
{
	if (background_texture)
		SDL_DestroyTexture(background_texture);
	if (coin_texture)
		SDL_DestroyTexture(coin_texture);

	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneFSM::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_grid = !draw_grid;
		else if (event->key.keysym.scancode == SDL_SCANCODE_Z)
		{
			_numberOfEnemies = 2;
			InitEnemies();
		}
		else if (event->key.keysym.scancode == SDL_SCANCODE_W)
		{
			playerAgentHasWeapon = !playerAgentHasWeapon;
			agents[0]->SetHasWeapon(playerAgentHasWeapon);
		}
		break;
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			Vector2D cell = maze->pix2cell(Vector2D((float)(event->button.x), (float)(event->button.y)));
			if (maze->isValidCell(cell)) {
				agents[0]->addPathPoint(maze->cell2pix(cell));
			}
		}
		break;
	default:
		break;
	}

	agents[0]->update(dtime, event);

	// if we have arrived to the coin, replace it in a random cell!
	if ((agents[0]->getCurrentTargetIndex() == -1) && (maze->pix2cell(agents[0]->getPosition()) == coinPosition))
	{
		coinPosition = Vector2D(-1, -1);
		while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, maze->pix2cell(agents[0]->getPosition()))<3))
			coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	}
	

	// ENEMIES:
	for (int i = 0; i < zomboAgents.size(); i++)
	{
		// FSM State Logic:
		zomboAgents[i]->_agentFSM->Update(zomboAgents[i], dtime, GetRandomGridPos());

		// FSM Movement Logic:
		zomboAgents[i]->update(dtime, event);

		if ((zomboAgents[i]->getCurrentTargetIndex() == -1) && (maze->pix2cell(zomboAgents[i]->getPosition()) == maze->pix2cell(zomboAgents[i]->getTarget())))
		{
			//zomboAgents[i]->setTarget(GetRandomGridPos());
			// Ask the agent for a valid position
			// Depending on their state they'll give a valid position (random for patrol / player pos for chase / etc)

			zomboAgents[i]->calculatedAlgorithm = false;
		}

		if (!zomboAgents[i]->calculatedAlgorithm)
		{
			DoGreedyBFS(zomboAgents[i]);
			zomboAgents[i]->calculatedAlgorithm = true;
		}
	}
}

void SceneFSM::draw()
{
	drawMaze();
	drawCoin();

	if (draw_grid)
	{
		SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 255, 127);
		for (int i = 0; i < SRC_WIDTH; i+=CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), i, 0, i, SRC_HEIGHT);
		}
		for (int j = 0; j < SRC_HEIGHT; j = j += CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 0, j, SRC_WIDTH, j);
		}
	}

	// We draw the agents:
		// Monke:
	agents[0]->draw();

		// Zombos:
	for (Agent* a : zomboAgents)
	{
		a->draw();
	}
}

const char* SceneFSM::getTitle()
{
	return "SDL Path Finding :: PathFinding Mouse Demo";
}

void SceneFSM::drawMaze()
{
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
	SDL_Rect rect;
	Vector2D coords;
	for (int j = 0; j < maze->getNumCellY(); j++)
	{
		for (int i = 0; i < maze->getNumCellX(); i++)
		{		
			if (!maze->isValidCell(Vector2D((float)i, (float)j)))
			{
				SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
				coords = maze->cell2pix(Vector2D((float)i, (float)j)) - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
				rect = { (int)coords.x, (int)coords.y, CELL_SIZE, CELL_SIZE };
				SDL_RenderFillRect(TheApp::Instance()->getRenderer(), &rect);
			} 
			else 
			{
				// Do not draw if it is not necessary (bg is already black)
			}
					
			
		}
	}
	//Alternative: render a backgroud texture:
	//SDL_RenderCopy(TheApp::Instance()->getRenderer(), background_texture, NULL, NULL );
}

void SceneFSM::drawCoin()
{
	Vector2D coin_coords = maze->cell2pix(coinPosition);
	int offset = CELL_SIZE / 2;
	SDL_Rect dstrect = {(int)coin_coords.x-offset, (int)coin_coords.y - offset, CELL_SIZE, CELL_SIZE};
	SDL_RenderCopy(TheApp::Instance()->getRenderer(), coin_texture, NULL, &dstrect);
}


bool SceneFSM::loadTextures(char* filename_bg, char* filename_coin)
{
	SDL_Surface *image = IMG_Load(filename_bg);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	background_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	image = IMG_Load(filename_coin);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	coin_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	return true;
}

void SceneFSM::DoGreedyBFS(Agent* _agent)
{
	_agent->clearPath();

	// call greedyBFS
	greedyBFS->startingNode = graph->GetNodeByPosition(maze->pix2cell(_agent->getPosition()));
	greedyBFS->SetGoalPosition(_agent->getTarget());

	greedyBFS->GreedyBFSAlgorithm(graph);

	//agents[0]->addPathPoint //<-- add each path node here transformed into cell2pix(cell)
	for (auto point : greedyBFS->pathToGoal)
	{
		_agent->addPathPoint(maze->cell2pix(point->GetPos()));
	}
}

void SceneFSM::InitEnemies() 
{
	int value = zomboAgents.size();
	int value2 = _numberOfEnemies;

	if (zomboAgents.size() >= _numberOfEnemies)
	{
		Vector2D rand_cell(-1, -1);

		for (int i = 0; i < zomboAgents.size(); i++)
		{
			// randomize starting position
			while (!maze->isValidCell(rand_cell))
				rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

			zomboAgents[i]->setPosition(maze->cell2pix(rand_cell));

			// We reset the value of "rand_cell":
			rand_cell = Vector2D(-1, -1);

			// randomize enemy target
			zomboAgents[i]->setTarget(Vector2D(-1, -1));
			while ((!maze->isValidCell(zomboAgents[i]->getTarget())) || (Vector2D::Distance(zomboAgents[i]->getTarget(), maze->pix2cell(zomboAgents[i]->getPosition())) < 3))
				zomboAgents[i]->setTarget(Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY())));
		}

		return;
	}


	for (int i = 0; i < _numberOfEnemies; i++)
	{
		Agent* enemyAgent = new Agent;
		enemyAgent->loadSpriteTexture("../res/zombie1.png", 8);
		enemyAgent->setBehavior(new PathFollowing);
		enemyAgent->setTarget(Vector2D(-20, -20));
		enemyAgent->_agentFSM = new FSM();
		enemyAgent->_agentFSM->currentState = new FSMState_Patrol();
		enemyAgent->targetAgent = agents[0];
		zomboAgents.push_back(enemyAgent);
	}

	Vector2D rand_cell(-1, -1);

	for (int i = 0; i < zomboAgents.size(); i++)
	{
		// randomize starting position
		while (!maze->isValidCell(rand_cell))
			rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

		zomboAgents[i]->setPosition(maze->cell2pix(rand_cell));
		zomboAgents[i]->SetDecisionMakingAlgorithm(algorithmFSM);

		// We reset the value of "rand_cell":
		rand_cell = Vector2D(-1, -1);

		// randomize enemy target
		zomboAgents[i]->setTarget(GetRandomGridPos());
	}
}

Vector2D SceneFSM::GetRandomGridPos()
{
	Vector2D randomPos = Vector2D(-1.0f, -1.0f);

	while (!maze->isValidCell(randomPos) || (Vector2D::Distance(randomPos, maze->pix2cell(randomPos))) < 3)
		randomPos = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

	return randomPos;
}
