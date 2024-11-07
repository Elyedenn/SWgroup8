#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	// 키보드
	BYTE asciiKeys[256];
	if (::GetKeyboardState(asciiKeys) == false)
		return;

	for (int32 i = 0; i < KEY_TYPE_COUNT; i++)
	{
		// 키가 눌려 있으면 true
		if (asciiKeys[i] & 0x80)
		{
			if (_states[i] == KeyState::Down || _states[i] == KeyState::Press)
				_states[i] = KeyState::Press;
			else
				_states[i] = KeyState::Down;
		}

		// 키가 안눌려있으면
		else
		{
			if (_states[i] == KeyState::Press || _states[i] == KeyState::Down)
				_states[i] = KeyState::Up;
			else
				_states[i] = KeyState::None;
		}
	}

	// 마우스
	::GetCursorPos(&_mousePos); // 커서의 좌표를 알아옴.
	::ScreenToClient(_hwnd, &_mousePos); // 이게 없으면 창(클라)에 대한 좌표가 아니라 모니터의 좌표가 나온다. (0, 0) 이 창 왼쪽 위가 아니라 모니터 왼쪽 위임.
}
