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
	App->cutscene_manager->LoadCutscene();

	return true;
}

// Called each loop iteration
bool TestingScene::PreUpdate()
{

	if (App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += 10;

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= 10;

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += 10;

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= 10;

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
		App->cutscene_manager->SetExecuting(true);

	return true;
}

// Called each loop iteration
bool TestingScene::Update(float dt)
{

	App->cutscene_manager->ExecuteCutscene(dt);

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