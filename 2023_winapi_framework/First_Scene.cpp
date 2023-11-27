#include "pch.h"
#include "First_Scene.h"

First_Scene::First_Scene()
{

}

First_Scene::~First_Scene()
{

}

bool First_Scene::CanChangeNextScene()
{
	return Scene::CanChangeNextScene();
}
