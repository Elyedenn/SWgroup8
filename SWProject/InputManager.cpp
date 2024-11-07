#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	// Ű����
	BYTE asciiKeys[256];
	if (::GetKeyboardState(asciiKeys) == false)
		return;

	for (int32 i = 0; i < KEY_TYPE_COUNT; i++)
	{
		// Ű�� ���� ������ true
		if (asciiKeys[i] & 0x80)
		{
			if (_states[i] == KeyState::Down || _states[i] == KeyState::Press)
				_states[i] = KeyState::Press;
			else
				_states[i] = KeyState::Down;
		}

		// Ű�� �ȴ���������
		else
		{
			if (_states[i] == KeyState::Press || _states[i] == KeyState::Down)
				_states[i] = KeyState::Up;
			else
				_states[i] = KeyState::None;
		}
	}

	// ���콺
	::GetCursorPos(&_mousePos); // Ŀ���� ��ǥ�� �˾ƿ�.
	::ScreenToClient(_hwnd, &_mousePos); // �̰� ������ â(Ŭ��)�� ���� ��ǥ�� �ƴ϶� ������� ��ǥ�� ���´�. (0, 0) �� â ���� ���� �ƴ϶� ����� ���� ����.
}
