//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
#include "Game.h"
#include "InputMan.h"
#include "KeyPress.h"
#include "Renderer.h"
#include "AudioEngine.h"
#include "SoundManager.h"
#include "SoundCallback.h"
#include "UserFileCallback.h"
#include "UserSoundCallback.h"
#include "Demo1.h"
#include "Demo2.h"
#include "Demo3.h"

using namespace Azul;

KeyPress pKey1(Keyboard::Key::KEY_1);
KeyPress pKey2(Keyboard::Key::KEY_2);
KeyPress pKey3(Keyboard::Key::KEY_3);


//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game(const char *const pWindowName, const int Width, const int Height)
	:Engine(pWindowName, Width, Height)
{
	assert(pWindowName);
	this->globalTimer.Tic();
}


//-----------------------------------------------------------------------------
//  Game::~Game()
//		Game Engine destructor
//-----------------------------------------------------------------------------
Game::~Game()
{ }


//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{ 
	Renderer::Init();
	AudioEngine::Init();
}


//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	InputMan::Create();
	Renderer::Load(info.windowWidth, info.windowHeight);

	// Load Audio Files
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::FIDDLE, "..\\..\\Data\\fiddle.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::BASSOON, "..\\..\\Data\\Bassoon.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::OBOE, "..\\..\\Data\\Oboe2_mono.wav");

	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD0, "..\\..\\Data\\seinfeld0.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD1, "..\\..\\Data\\seinfeld1.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD2, "..\\..\\Data\\seinfeld2.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD3, "..\\..\\Data\\seinfeld3.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD4, "..\\..\\Data\\seinfeld4.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD5, "..\\..\\Data\\seinfeld5.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD6, "..\\..\\Data\\seinfeld6.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD7, "..\\..\\Data\\seinfeld7.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD8, "..\\..\\Data\\seinfeld8.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::SEINFELD9, "..\\..\\Data\\seinfeld9.wav");

	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::WATERFALL, "..\\..\\Data\\waterfall.wav");
	AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::BEETHOVEN_LAENDLER, "..\\..\\Data\\Beethoven_Laendler.wav");

	// Load Playlists (Loading Playlist Manager Reference)
	// Note: assume playlist are loaded in statically...like a script...loaded as a Proto?
	AudioEngine::LoadPlaylist(PlaylistRef::ID::FIDDLE, Wave::ID::FIDDLE);
	AudioEngine::LoadPlaylist(PlaylistRef::ID::BASSOON, Wave::ID::BASSOON);
	AudioEngine::LoadPlaylist(PlaylistRef::ID::OBOE, Wave::ID::OBOE);
	AudioEngine::LoadPlaylist(PlaylistRef::ID::SEINFELD, Wave::ID::SEINFELD0);
	AudioEngine::LoadPlaylist(PlaylistRef::ID::WATERFALL, Wave::ID::WATERFALL);
	AudioEngine::LoadPlaylist(PlaylistRef::ID::BEETHOVEN_LAENDLER, Wave::ID::BEETHOVEN_LAENDLER);
	AudioEngine::LoadPlaylist(PlaylistRef::ID::CHOPIN_BOURREE, Wave::ID::CHOPIN_BOURREE);
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------

void Game::Update(float )
{
	InputMan::Update();
	Renderer::Update(this->globalTimer.Toc());
	AudioEngine::Update(this->globalTimer.Toc());
	
	if (pKey1)
	{
		std::thread t(Demos::Demo1);
		Debug::SetName(t, "-Demo 1-");
		t.detach();
	}
	if (pKey2)
	{
		std::thread t(Demos::Demo2);
		Debug::SetName(t, "-Demo 2-");
		t.detach();
	}
	if (pKey3)
	{
		std::thread t(Demos::Demo3);
		Debug::SetName(t, "-Demo 3-");
		t.detach();
	}
}


//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	Renderer::Draw();
}


//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{ 
	Renderer::UnLoad();
	AudioEngine::Destroy();
	InputMan::Destroy();
}


//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
#ifdef _DEBUG	
	const GLfloat color[] = { 0.2f, 0.2f, 0.2f, 1.0f };
#else
	const GLfloat color[] = { 0.85f, 0.7f, 0.7f, 1.0f };
#endif
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, color);
	glClearBufferfv(GL_DEPTH, 0, &one);
}


// --- End of File ---
