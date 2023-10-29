#pragma once
#ifndef GRAPHICSOBJ_3D_H
#define GRAPHICSOBJ_3D_H

#include "GraphicsObj.h"

using namespace Azul;

class GraphicsObj3D : public GraphicsObj
{
public:
	GraphicsObj3D() = delete;
	GraphicsObj3D(const GraphicsObj3D&) = delete;
	GraphicsObj3D& operator=(const GraphicsObj3D&) = delete;

	GraphicsObj3D(Mesh* mesh, const ShaderObj* shaderobj);
	virtual ~GraphicsObj3D();


	void Render() override;


};
#endif // !GRAPHICSOBJ_3D_H
