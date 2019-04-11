#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Map.h"
#include "TestingScene.h"
#include "CutsceneManager.h"
#include "EntityManager.h"


TestingScene::TestingScene() : Scene()
{

}

// Destructor
TestingScene::~TestingScene()
{}

// Called before the first frame
bool TestingScene::Start()
{
	App->render->camera = { 0, -200 };

	return true;
}

// Called each loop iteration
bool TestingScene::PreUpdate()
{

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
		App->cutscene_manager->PlayCutscene("xml/cutscene.xml");

	return true;
}

// Called each loop iteration
bool TestingScene::Update(float dt)
{

	App->map->Draw();

	return true;
}

// Called each loop iteration
bool TestingScene::PostUpdate()
{
	bool ret = true;

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool TestingScene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}