#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Path.h"
#include "Vector2D.h"
#include "utils.h"
#include "DecisionMakingAlgorithm.h"
#include "AgentStates.h" // Valorar si deixar-lo com abans, borrar-lo o no canviar-lo?
#include "FSMState_Chase.h" // Valorar qu� fem?
#include "FSMState_Patrol.h" // Valorar qu� fem?
#include "FSMState_Evade.h" // Valorar qu� fem?

class FSM;

class Agent
{
public:
	class SteeringBehavior
	{
	public:
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual void applySteeringForce(Agent *agent, float dtime) {};
	};
private:
	// Movement:
	SteeringBehavior *steering_behaviour;
	Vector2D position; // location in map (needed in FSM_State)
	Vector2D target; // target in map (needed in FSM_State)
	Vector2D velocity;

	// Pathfinding:
	Path path;
	int currentTargetIndex;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

	bool hasWeapon = false;
	float distanceThreshold = 50.f;

public:
	// FSM:
	FSM* _agentFSM;

	Agent* targetAgent;
	AgentStates agentStates;

	bool calculatedAlgorithm = false;
	DecisionMakingAlgorithm decisionMakingAlgorithm;

	Agent();
	~Agent();
	Vector2D getPosition();
	Vector2D getTarget();
	void setTarget(Vector2D target);
	Vector2D getVelocity();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();
	void setBehavior(SteeringBehavior *behavior);
	void setPosition(Vector2D position);
	void setVelocity(Vector2D velocity);
	void addPathPoint(Vector2D point);
	void setCurrentTargetIndex(int idx);
	int getCurrentTargetIndex();
	int getPathSize();
	Vector2D getPathPoint(int idx);
	void clearPath();
	void update(float dtime, SDL_Event *event);
	void draw();
	bool loadSpriteTexture(char* filename, int num_frames = 1);
	void SetDecisionMakingAlgorithm(DecisionMakingAlgorithm newDecisionMakingAlgorithm);
	Agent* GetTargetAgent();
	void SetTargetAgent(Agent* targAgent);
	bool GetHasWeapon();
	void SetHasWeapon(bool val);
	float GetDistanceTreshold();
};
