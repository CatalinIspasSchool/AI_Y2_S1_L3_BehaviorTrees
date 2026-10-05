
#ifndef AI_ACTOR_GUARD_H
#define AI_ACTOR_GUARD_H

#pragma once
#include <SFML/Graphics.hpp>
#include "../AI_Framework/framework.h"


/*
Class AIActor_Guard represents the NPC Guards that patrol the level
*/
class AIActor_Guard: 
	public AIActorBase

{
public:

	// movement stages the Guard can be in
	enum GuardState { Moving, Stationary, Running , Healing};

	// constants
	const float hearRange = 256.f;
	const float walkEneryUse = 1.f;
	const float runEnergyUse = 3.f;
	const float restEnergyGain = 3.f;
	const float energyCap = 20.f;


	AIActor_Guard();
	~AIActor_Guard();

	// AIActorBase overrides
	bool Init(std::string _id, AIConstructorBase& _constructor) override;
	void Update(float _dt) override;
	void PreTransition() override;//State Transition Functions


	// position tracking
	float posX;
	float posY;
	float rotation;
	
	//status
	bool isActive;
	GuardState guardState;


	// Behaviour Functions - should be called each frame to progress the behaviour
	ActionStatus Patrol();
	ActionStatus Investigate();
	ActionStatus Chase();
	ActionStatus Rest();
	ActionStatus Sprint();
	ActionStatus RaiseAlarm();
	ActionStatus GetPatrolPath();
	ActionStatus GetAlarmPath();
	ActionStatus GetInvestigatePath();

	// Initialisation
	void Spawn(float _x, float _y);
	void SetPatrolBounds(int _x, int _y);

	
	


	//Status Functions
	bool CanSeePoint(sf::Vector2f _point);
	bool CanHearPoint(sf::Vector2f _point);

	void UpdateCanSeePlayer(float _x, float _y);
	void UpdateCannotSeePlayer();
	void UpdateCanHearPlayer(float _x, float _y);
	void UpdateCannotHearPlayer();

	bool IsPlayerSeen();
	bool IsPlayerHeard();

private:

	const float moveSpeed = 92.f;
	const float chaseRefresh = 0.5f;
	const float sightRefresh = 1.0f;
	const sf::Vector2f alarmPoint = sf::Vector2f(700,500);
	const float sprintMultiplier = 2.f;

	int patrolMaxX = 0;
	int patrolMaxY = 0;

	// movement tracking
	sf::Vector2f moveTarget;
	sf::Vector2f moveOrigin;
	bool hasMoveTarget;
	float moveTime;
	float movePoint;
	float chaseCounter = 0;
	float sightCounter = 0;
	bool isRaisingAlarm = false;
	float dt;//convenience

	//movement functions
	void Move(float _dt);
	void UpdateEnergyLevel(float _dt);
	sf::Vector2f GetRandomPatrolPoint();
	void MoveToPoint(sf::Vector2f _target, bool _sprint);


	//Global Access
	AIRandom_Global* _random;
	AIMath_Global* _math;

};


#endif