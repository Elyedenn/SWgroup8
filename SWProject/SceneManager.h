#pragma once

class Object;
class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Clear();

	void ChangeScene(SceneType sceneType);

	Scene* GetCurrentScene() { return _scene; }

	void Add(Object* object);
	void Remove(Object* object);
	vector<Object*>& GetObjects();

private:
	Scene* _scene;
	SceneType _sceneType = SceneType::None;

public:
	Vector GetCameraPos() { return _cameraPos; }
	void SetCameraPos(Vector cameraPos) { _cameraPos = cameraPos; }

private:
	Vector _cameraPos = { 0,0 };
};

