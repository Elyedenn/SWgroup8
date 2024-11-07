#include "pch.h"
#include "Utils.h"

void Utils::DrawText(HDC hdc, Pos pos, const std::wstring& str)
{
	::TextOut(hdc, pos.x, pos.y, str.c_str(), static_cast<int32>(str.size()));
}

void Utils::DrawCircle(HDC hdc, Pos pos, int32 rad)
{
	::Ellipse(hdc, pos.x - rad, pos.y - rad, pos.x + rad, pos.y + rad);
}

void Utils::DrawRect(HDC hdc, Pos pos, int32 w, int32 h)
{
	::Rectangle(hdc, pos.x - w / 2, pos.y - h / 2, pos.x + w / 2, pos.y + h / 2);
}

void Utils::DrawLine(HDC hdc, Pos start, Pos end)
{
	::MoveToEx(hdc, start.x, start.y, nullptr);
	::LineTo(hdc, end.x, end.y);
}