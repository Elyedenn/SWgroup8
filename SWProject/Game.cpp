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
	// Manager 클리어
	GET_SINGLE(SceneManager)->Clear();

	// 가장 마지막에...
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(_hwnd);

	// 더블 버퍼링
	::GetClientRect(_hwnd, &_rect);

	_hdcBack = ::CreateCompatibleDC(_hdc); // _hdc 랑 호환되는 또다른 도화지 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); // _hdc 와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack); // DC 와 BMP 를 연결. 이전에 사용했던 비트맵을 뱉음
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
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000)); // 이게 WCHAR 보다 현대적.

		Pos pos(650, 10);
		Utils::DrawText(_hdcBack, pos, str);
	}

	{
		POINT mouse = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"mouse({0}, {1})", mouse.x, mouse.y);

		Pos pos = {0, 0};
		Utils::DrawText(_hdcBack, pos, str);
	}



	// 더블 버퍼링
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); // 비트 블릿 : 고속 복사 
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS); // 백버퍼를 하얀색으로 밀어주기
}
