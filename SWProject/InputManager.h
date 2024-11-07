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
	None,	// (�ȴ�����)
	Press,	// (������ ������)
	Down,	// (������ �����Ҷ�)
	Up,		// (���� �����Ҷ�)

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

	// ��ư ���� ����
	bool GetButton(KeyType key) { return GetState(key) == KeyState::Press; }
	// ��ư ������ ����
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }
	// ��ư ���� ����
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }
	POINT GetMousePos() { return _mousePos; }
	

private:
	HWND _hwnd = 0;
	vector<KeyState>_states;
	POINT _mousePos;
};

