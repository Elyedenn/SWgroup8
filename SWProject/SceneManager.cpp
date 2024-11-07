#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
//#include "DevScene.h"
//#include "GameScene.h"
//#include "EditScene.h"

void SceneManager::Init()
{
	if (_scene)
		_scene->Init();
}

void SceneManager::Update()
{
	if (_scene)
		_scene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
		_scene->Render(hdc);
}

void SceneManager::Clear()
{
	SAFE_DELETE(_scene);
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (sceneType == _sceneType)
		return;

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	//case SceneType::DevScene:
	//	newScene = new DevScene();
	//	break;

	//case SceneType::GameScene:
	//	newScene = new GameScene();
	//	break;

	//case SceneType::EditScene:
	//	newScene = new EditScene();
	//	break;



	}

	SAFE_DELETE(_scene);

	_sceneType = sceneType;
	_scene = newScene;

	_scene->Init();
}

void SceneManager::Add(Object* object)
{
	if (object != nullptr)
		_scene->Add(object);
}

void SceneManager::Remove(Object* object)
{
	if (object != nullptr)
		_scene->Remove(object); // ±¦ÂúÀ»±î..?
}

vector<Object*>& SceneManager::GetObjects()
{
	return _scene->GetObjects();
}
