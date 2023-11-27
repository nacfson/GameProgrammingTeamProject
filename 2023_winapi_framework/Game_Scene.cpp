#include "pch.h"
#include "Game_Scene.h"

Game_Scene::Game_Scene()
{
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::Init()
{
}

bool Game_Scene::CanChangeNextScene()
{
	return Scene::CanChangeNextScene();
}
bool Game_Scene::CanChangePrevScene()
{
	return Scene::CanChangePrevScene();
}
