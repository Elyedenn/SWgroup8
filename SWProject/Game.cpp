#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
}

Game::~Game()
{
	// Manager Ŭ����
	GET_SINGLE(SceneManager)->Clear();

	// ���� ��������...
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(_hwnd);

	// ���� ���۸�
	::GetClientRect(_hwnd, &_rect);

	_hdcBack = ::CreateCompatibleDC(_hdc); // _hdc �� ȣȯ�Ǵ� �Ǵٸ� ��ȭ�� ����
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); // _hdc �� ȣȯ�Ǵ� ��Ʈ�� ����
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack); // DC �� BMP �� ����. ������ ����ߴ� ��Ʈ���� ����
	::DeleteObject(prev);

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(_hwnd);
	//GET_SINGLE(SceneManager)->Init();
	//GET_SINGLE(ResourceManager)->Init(_hwnd, L"");

	//GET_SINGLE(SceneManager)->ChangeScene(SceneType::DevScene);
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	//GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	GET_SINGLE(SceneManager)->Render(_hdcBack);

	{
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000)); // �̰� WCHAR ���� ������.

		Pos pos(650, 10);
		Utils::DrawText(_hdcBack, pos, str);
	}

	{
		POINT mouse = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"mouse({0}, {1})", mouse.x, mouse.y);

		Pos pos = {0, 0};
		Utils::DrawText(_hdcBack, pos, str);
	}



	// ���� ���۸�
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); // ��Ʈ �� : ��� ���� 
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS); // ����۸� �Ͼ������ �о��ֱ�
}
