#include "GraphicsObj3D.h"

using namespace Azul;

//--------------------------------------------------------------------------
//	CONSTRUCTION
//--------------------------------------------------------------------------

GraphicsObj3D::GraphicsObj3D(Mesh* mesh, const ShaderObj* shaderobj)
	: GraphicsObj(mesh, shaderobj)
{
	assert(mesh);
	assert(shaderobj);
}

GraphicsObj3D::~GraphicsObj3D()
{ 
}

//--------------------------------------------------------------------------
//	PUBLIC METHODS
//--------------------------------------------------------------------------

void GraphicsObj3D::Render()
{
	this->SetState();
	this->SetGPUData();
	this->Draw();
	this->ResetState();
}