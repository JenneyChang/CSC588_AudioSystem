#ifndef GAME_H
#define GAME_H

#include "sb7.h"
#include "Engine.h"
#include "AnimTimer.h"

using namespace Azul;

class Game : public Engine
{
public:
	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator = (Game&&) = delete;

	// constructor
	Game(const char *windowName, const int Width, const int Height);
	~Game();


private:
	virtual void Initialize() override;
	virtual void LoadContent() override;
	virtual void Update(float currentTime) override;
	virtual void Draw() override;
	virtual void UnLoadContent() override;
	virtual void ClearBufferFunc() override;


public:
	// Nice and Clean
	AnimTimer	intervalTimer;
	AnimTimer	globalTimer;


};
#endif

// --- End of File ---

