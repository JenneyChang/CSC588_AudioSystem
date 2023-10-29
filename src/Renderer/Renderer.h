#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include "AnimTime.h"

using namespace Azul;

class Renderer
{
public:
	// deleted functions
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

	static void Init();
	static void Load(const int width, const int height);
	static void UnLoad();
	static void Update(Azul::AnimTime t);
	static void Draw();


private:
	Renderer() = default;
	~Renderer() = default;

	static Renderer* Instance();


};
#endif // !RENDERER_H
