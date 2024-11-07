#pragma once
class Utils
{
public:
	static void DrawText(HDC hdc, Pos pos, const std::wstring& str);
	static void DrawCircle(HDC hdc, Pos pos, int32 rad);
	static void DrawRect(HDC hdc, Pos pos, int32 w, int32 h);
	static void DrawLine(HDC hdc, Pos start, Pos end);

};

