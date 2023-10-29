#include "Renderer.h"
#include "AnimTimer.h"
#include "Camera3DMan.h"
#include "GameObjMan.h"
#include "MeshNodeMan.h"
#include "ShaderMan.h"
#include "TextureMan.h"

#include "ShaderGraphics.h"
#include "ProtoMesh.h"
#include "GameObj_Rigid.h"
#include "GraphicsObj_Texture.h"


using namespace Azul;

void Renderer::Init()
{
	// Instantiate our renderer...
	Renderer* pRenderer = Renderer::Instance();
	assert(pRenderer);
}

void Renderer::Load(const int width, const int height)
{
	// LOAD MANAGERS
	Camera3DMan::Create();
	ShaderMan::Create();
	TextureMan::Create();
	MeshNodeMan::Create();
	GameObjMan::Create();

	// CAMERA SETUP
	Camera3D* pCam0 = Camera3DMan::Add(Camera::Name::CAMERA_0);
	pCam0->SetViewport(0, 0, width, height);
	pCam0->SetPerspective(35.0f, float(pCam0->GetScreenWidth()) / float(pCam0->GetScreenHeight()), 1.0f, 10000.0f);
	pCam0->SetOrient_Pos(Vec3(0.0f, 1.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 8.0f));
	pCam0->UpdateCamera();
	Camera3DMan::SetCurrCam(pCam0);

	// LOAD SHADER
	ShaderObj* pTextureShader = new ShaderGraphics(ShaderObj::Name::TEXTURE, "texture");
	ShaderMan::Add(pTextureShader);

	// LOAD TEXTURE & MESH
	Texture* pFrigateTex = TextureMan::Add("..\\..\\Data\\space_frigate_tex.proto.azul", Texture::Name::FRIGATE);
	Mesh* pFrigateMesh = new ProtoMesh("..\\..\\Data\\space_frigate.proto.azul", pFrigateTex);
	MeshNodeMan::Add(Mesh::Name::FRIGATE, pFrigateMesh);

	// SETUP MODEL
	GraphicsObj* pGraphicsObj = new GraphicsObj_Texture(pFrigateMesh, pTextureShader, pFrigateTex);
	GameObj_Rigid* pFrigateObj = new GameObj_Rigid((GraphicsObj3D*)pGraphicsObj);
	pFrigateObj->SetName("Frigate");
	pFrigateObj->SetScale(0.05f, 0.05f, 0.05f);
	pFrigateObj->SetDeltaY(0.006f);
	pFrigateObj->SetDeltaX(0.003f);
	GameObjMan::Add(pFrigateObj, GameObjMan::GetRoot());
}

void Renderer::UnLoad()
{
	Camera3DMan::Destroy();
	ShaderMan::Destroy();
	TextureMan::Destroy();
	MeshNodeMan::Destroy();
	GameObjMan::Destroy();
}

void Renderer::Update(Azul::AnimTime t)
{
	Camera* cam = Camera3DMan::GetCurrCam();
	cam->UpdateCamera();

	// Update Game Objs
	GameObjMan::Update(t);
}

void Renderer::Draw()
{
	// Render objects
	GameObjMan::Draw();
}

Renderer* Renderer::Instance()
{
	static Renderer poInstance;
	return &poInstance;
}