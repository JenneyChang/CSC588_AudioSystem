#include "GraphicsObj_Null.h"

//------------------------------------------------------------------------
//	CONSTRUCTOR
//------------------------------------------------------------------------

GraphicsObj_Null::GraphicsObj_Null(Mesh* _mesh, const ShaderObj* _shaderObj)
	: GraphicsObj(_mesh, _shaderObj)
{ 
	//does nothing by default
}

GraphicsObj_Null::~GraphicsObj_Null()
{ 
	//does nothing by default

}

//------------------------------------------------------------------------
//	OVERRIDDEN METHODS
//------------------------------------------------------------------------

void GraphicsObj_Null::Render()
{
	//does nothing
}
