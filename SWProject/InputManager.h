#pragma once

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	Q = 'Q',
	E = 'E',

	Spacebar = VK_SPACE,

	KEY_1 = '1',
	KEY_2 = '2',
	KEY_3 = '3',
};

enum class KeyState
{
	None,	// (안누를때)
	Press,	// (누르고 있을때)
	Down,	// (누르기 시작할때)
	Up,		// (떼기 시작할때)

	End		
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End)
};

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hwnd);
	void Update();

	// 버튼 누른 상태
	bool GetButton(KeyType key) { return GetState(key) == KeyState::Press; }
	// 버튼 누르기 시작
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }
	// 버튼 떼기 시작
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }
	POINT GetMousePos() { return _mousePos; }
	

private:
	HWND _hwnd = 0;
	vector<KeyState>_states;
	POINT _mousePos;
};

