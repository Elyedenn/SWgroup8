#pragma once

class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {}; // ������ �ڵ�
	HDC _hdc = {}; // ��ȭ��

private:
	// ���� ���۸�
	RECT _rect;
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};
};

