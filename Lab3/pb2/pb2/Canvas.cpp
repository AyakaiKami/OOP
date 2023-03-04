#include "Canvas.h"
Canvas::Canvas(int width,int height)
{
	cw = width;
	che = height;
	Canv = new char* [height];
	for (int i = 0; i < height; i++)
	{
		Canv[i] = new char[width];
		for (int j = 0; j < width; j++)
			Canv[i][j] = 32;
	}

}
void Canvas::Print()
{
	for (int i = 0; i < che; i++)
	{
		for (int j = 0; j < cw; j++)
			std::cout << Canv[i][j]<<" ";
		std::cout << std::endl;
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < che; i++)
	{
		for (int j = 0; j < cw; j++)
			Canv[i][j] = 32;
	}
}
void Canvas::SetPoint(int x,int y,char ch)
{
	Canv[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int error = dx + dy,e2;
	while (true)
	{
		SetPoint(x1, y1,ch);
		if (x1 == x2 && y1 == y2)break;
		e2 = 2 * error;
		if (e2 >= dy)
		{	if (x1 == x2)break;
		
			error += dy; 
			x1 += sx;
		}
		if (e2 <= dx)
		{	if (y1 == y2)break;
			
				error += dx;
				y1 += sy;
		}
	}
	
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	
	for (int i = 1; i <= 360; i++)
	{

		if ((y+sin(i) * ray >= 0 && x+cos(i) * ray >= 0) && (int(y+sin(i)*ray)<che && int( x+ cos(i)*ray)<cw))
			SetPoint(x+cos(i) * ray,y+ sin(i) * ray,ch);
	}


}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, top, right, top,ch);
	DrawLine(left, bottom, right, bottom,ch);
	DrawLine(left, top, left, bottom, ch);
	DrawLine(right, top, right, bottom, ch);
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		DrawLine(i, top, i, bottom, ch);
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 1; i <= ray; i++)
		DrawCircle(x, y, i, ch);
}