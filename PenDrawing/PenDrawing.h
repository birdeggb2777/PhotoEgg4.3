#pragma once
#include <math.h> 
#define BGR2BGR 0
#define BGR2RGB 1
#define BGR2RBG 2
#define BGR2GRB 3
#define BGR2GBR 4
#define BGR2BRG 5
#include <thread>
#include <iostream>  
#include<cmath>
#include<algorithm>
#include <vector>
using namespace std;
using namespace System;

namespace PenDrawing {
	/*public ref class Brush {
	public:
		unsigned char R = 0;
		unsigned char G = 0;
		unsigned char B = 0;
		int width = 10;
		int height = 10;
		unsigned char** fp;
		Brush(unsigned char r, unsigned char g, unsigned char b, int size) {
			R = r;
			G = g;
			B = b;
			width = size;
			height = size;


			fp = new unsigned char* [height];
			for (int j = 0; j < height; j++)
				fp[j] = new unsigned char[width * 4];

			for (int h = 0;h < height;h++) {
				for (int w = 0; w < width; w += 4) {
					if (sqrt(h * h + w * w) <= size) {
						fp[h][w] = b;
						fp[h][w + 1] = g;
						fp[h][w + 2] = r;
						fp[h][w + 3] = 255;
					}
					else
					{
						fp[h][w] = 0;
						fp[h][w + 1] = 0;
						fp[h][w + 2] = 0;
						fp[h][w + 3] = 0;
					}
				}
			}
		}
		void createBrush() {


		}
	};*/
	public ref class DrawClass
	{
		// TODO: 請在此新增此類別的方法。



	public:
		unsigned Color_R = 0;
		unsigned Color_G = 0;
		unsigned Color_B = 0;

		//unsigned char** BrushFp;
		//Brush MyBrush;
		void Black(unsigned char* ptr, int width, int height, int channel, int pointX, int pointY, int size, int transparent)
		{
			unsigned char** fp = new unsigned char* [height];
			int Stride = width * channel, x = 0, y = 0;
			double trans = (double)transparent / 100;
			if (trans > 1)trans = 1;
			for (int j = 0; j < height; j++)
				fp[j] = ptr + (Stride * j);
			for (y = pointY; y < pointY + size; y++)
			{
				for (x = pointX * 4; x < (pointX + size) * 4; x += channel)
				{
					if (y < 0 || y >= height || x < 0 || x >= Stride)
					{
						continue;
					}
					fp[y][x] = (unsigned char)(fp[y][x] * (1 - trans) + Color_B * trans);
					fp[y][x + 1] = (unsigned char)(fp[y][x + 1] * (1 - trans) + Color_G * trans);
					fp[y][x + 2] = (unsigned char)(fp[y][x + 2] * (1 - trans) + Color_R * trans);
				}
			}
			delete[] fp;
		}

		void BlackBrush(unsigned char* ptr, int width, int height, int channel, int pointX, int pointY, int transparent)
		{
			if (!Brush_fp)return;
			unsigned char** fp = new unsigned char* [height];
			int Stride = width * channel, x = 0, y = 0;
			int x2 = 0; int y2 = 0;
			double trans = (double)transparent / 100;
			if (trans > 1)trans = 1;
			for (int j = 0; j < height; j++)
				fp[j] = ptr + (Stride * j);
			int pasteXPoint = pointX * channel;
			double trans2 = 0;
			for (y = 0, y2 = 0; y < height && y2 < Brush_height; y++, y2++)
			{
				for (x = 0, x2 = 0; x < Stride && x2 < Brush_width * 4; x += channel, x2 += channel)
				{
					if (x + pasteXPoint >= Stride || x + pasteXPoint < 0 || y + pointY >= height || y + pointY < 0)continue;
					if (x2 >= Brush_width * 4 || x2 < 0 || y2 >= Brush_height || y2 < 0)continue;
					if (Brush_fp[y2][x2 + 3] == 0)continue;
					trans2 =((double)Brush_fp[y2][x2 + 3] /255)*trans;
					fp[y + pointY][x + pasteXPoint] = (unsigned char)((double)fp[y + pointY][x + pasteXPoint]*(1 - trans2) + (double)Brush_fp[y2][x2]* trans2);
					fp[y + pointY][x + pasteXPoint + 1] = (unsigned char)((double)fp[y + pointY][x + pasteXPoint + 1]*(1 - trans2) + (double)Brush_fp[y2][x2+1] * trans2);
					fp[y + pointY][x + pasteXPoint + 2] = (unsigned char)((double)fp[y + pointY][x + pasteXPoint + 2]*(1 - trans2) + (double)Brush_fp[y2][x2+2] * trans2);
					//fp[y + pointY][x + pasteXPoint + 3] = /*fp[y + pointY][x + pasteXPoint + 3] * (1 - trans) + */Brush_fp[y2][x2 + 3]/* * trans*/;
				}
			}


			/*	for (y = pointY; y < pointY + size; y++)
				{
					for (x = pointX * 4; x < (pointX + size) * 4; x += channel)
					{
						if (y < 0 || y >= height || x < 0 || x >= Stride)
						{
							continue;
						}
						fp[y][x] = (unsigned char)(fp[y][x] * (1 - trans) + Color_B * trans);
						fp[y][x + 1] = (unsigned char)(fp[y][x + 1] * (1 - trans) + Color_G * trans);
						fp[y][x + 2] = (unsigned char)(fp[y][x + 2] * (1 - trans) + Color_R * trans);
					}
				}
				delete[] fp;*/
		}








		int Brush_width = 0;
		int Brush_height = 0;
		unsigned char** Brush_fp;
		void CreateBrush(int size,int  sawTouch) {
			if (sawTouch > 32)sawTouch = 32;
			if (sawTouch <= 0)sawTouch = 0;
			//sawTouch = 32 - sawTouch;

			for (int i = 0;i < Brush_height;i++) {
				delete Brush_fp[i];
			}
			Brush_width = size;
			Brush_height = size;

			Brush_fp = new unsigned char* [Brush_height];
			for (int j = 0; j < Brush_height; j++)
				Brush_fp[j] = new unsigned char[Brush_width * 4];
			double temp;
			for (int h = 0;h < Brush_height;h++) {
				for (int w = 0; w < Brush_width*4; w += 4) {
					if (pow(w/4- (Brush_width /2),2)+ pow(h - (Brush_height / 2), 2) < (size/2)*(size/2)) {
						Brush_fp[h][w] = Color_B;
						Brush_fp[h][w + 1] = Color_G;
						Brush_fp[h][w + 2] = Color_R;
						if ((double)(size / 2)-(sqrt(pow(w / 4 - (Brush_width / 2), 2) + pow(h - (Brush_height / 2), 2))) < sawTouch)
						{
							temp = ((1 - (sqrt(pow(w / 4 - (Brush_width / 2), 2) + pow(h - (Brush_height / 2), 2)) / (double)(size / 2)))
								* 255);
							if (temp > 255)temp = 255;
						}
						else temp = 255;
						//if (temp > 254 && temp < 256)temp = 0;
						Brush_fp[h][w + 3] =(unsigned char)temp;
						//Brush_fp[h][w + 0] = Brush_fp[h][w +1] = Brush_fp[h][w +2] = Brush_fp[h][w + 3];
						//Brush_fp[h][w + 3] =255;
					}
					else
					{
						Brush_fp[h][w] = 0;
						Brush_fp[h][w + 1] = 0;
						Brush_fp[h][w + 2] = 0;
						Brush_fp[h][w + 3] = 0;
					}
				}
			}
		}


















		static void colorOrder(unsigned char& b, unsigned char& g, unsigned char& r, int order)
		{
			unsigned char temp;
			if (order == BGR2BGR)
			{
				return;
			}
			else if (order == BGR2BRG)
			{
				temp = g;
				g = r;
				r = temp;
			}
			else if (order == BGR2RGB)
			{
				temp = b;
				b = r;
				r = temp;
			}
			else if (order == BGR2RBG)
			{
				temp = b;
				b = g;
				g = temp;
				temp = r;
				r = g;
				g = temp;
			}
			else if (order == BGR2GRB)
			{
				temp = b;
				b = r;
				r = temp;
				temp = g;
				g = r;
				r = temp;
			}
			else if (order == BGR2GBR)
			{
				temp = b;
				b = g;
				g = temp;
			}
		}
		static void ConvertHSV_(unsigned char* ptr, int width, int height, int H, int S, int V, int channel, bool fix, int order, int halfheight, int halfwidth)
		{
			unsigned char** fp = new unsigned char* [height];
			int Stride = width * channel, x = 0, y = 0;
			for (int j = 0; j < height; j++)
				fp[j] = ptr + (Stride * j);
			int heightBegin = 0;
			int heightEnd = height;
			if (halfheight == 0)heightBegin = 0; else heightBegin = height / 2;
			if (halfheight == 0)heightEnd = height / 2; else heightEnd = height;
			int widthBegin = 0;
			int widthEnd = Stride;
			int halfStride = Stride / 2;
			if (halfStride % 4 != 0)
			{
				for (int i = 0; i < 10; i++)
				{
					if (i == 9)return;
					if ((halfStride - i) % 4 == 0)
					{
						halfStride -= i;
						break;
					}
				}
			}
			if (halfwidth == 0)widthBegin = 0; else widthBegin = halfStride;
			if (halfwidth == 0)widthEnd = halfStride; else widthEnd = Stride;
			for (y = heightBegin; y < heightEnd; y++)
			{
				for (x = widthBegin; x < widthEnd; x += channel)
				{
					colorOrder(fp[y][x], fp[y][x + 1], fp[y][x + 2], order);
					BGRToHSV(H, S, V, fp[y][x], fp[y][x + 1], fp[y][x + 2], fix);
				}
			}
			delete[] fp;
		}
		void ConvertHSV(unsigned char* ptr, int width, int height, int H, int S, int V, int channel, bool fix, int order)
		{
			thread ThreadW0H0(ConvertHSV_, ptr, width, height, H, S, V, channel, fix, order, 0, 0);
			thread ThreadW0H1(ConvertHSV_, ptr, width, height, H, S, V, channel, fix, order, 0, 1);
			thread ThreadW1H0(ConvertHSV_, ptr, width, height, H, S, V, channel, fix, order, 1, 0);
			thread ThreadW1H1(ConvertHSV_, ptr, width, height, H, S, V, channel, fix, order, 1, 1);
			ThreadW0H0.join();
			ThreadW0H1.join();
			ThreadW1H0.join();
			ThreadW1H1.join();
		}
		/////////////////////////////
		//////////////////////////////

		static inline double HSVMin(double a, double b) {
			return a <= b ? a : b;
		}

		static inline double HSVMax(double a, double b) {
			return a >= b ? a : b;
		}

		static inline void BGRToHSV(int H, int S, int V, unsigned char& colorB, unsigned char& colorG, unsigned char& colorR, bool fix)
		{
			double delta, min;
			double h = 0, s, v;
			min = HSVMin(HSVMin(colorR, colorG), colorB);
			v = HSVMax(HSVMax(colorR, colorG), colorB);
			delta = v - min;
			if (v == 0.0)
				s = 0;
			else
				s = delta / v;
			if (s == 0)
				h = 0.0;
			else
			{
				if (colorR == v)
					h = (colorG - colorB) / delta;
				else if (colorG == v)
					h = 2 + (colorB - colorR) / delta;
				else if (colorB == v)
					h = 4 + (colorR - colorG) / delta;
				h *= 60;
				if (h < 0.0)
					h = h + 360;
			}
			if (fix == false)
				h += H;
			else
				h = H;
			if (h < 0.0)
				h = h + 360;
			if (h >= 360.0)
				h = h - 360;
			s += s * S / 100;
			if (s > 1.0) s = 1.0;
			if (s < 0) s = 0;
			v += V;
			if (v > 255) v = 255;
			if (v < 0) v = 0;
			HSVToBGR(h, s, v, colorB, colorG, colorR);
		}

		static inline void  HSVToBGR(double H, double S, double V, unsigned char& colorB, unsigned char& colorG, unsigned char& colorR)
		{
			if (S == 0)
			{
				colorR = V;
				colorG = V;
				colorB = V;
			}
			else
			{
				int i;
				double f, p, q, t;

				if (H == 360)
					H = 0;
				else
					H = H / 60;

				i = (int)trunc(H);
				f = H - i;

				p = V * (1.0 - S);
				q = V * (1.0 - (S * f));
				t = V * (1.0 - (S * (1.0 - f)));

				switch (i)
				{
				case 0:
					colorR = V;
					colorG = t;
					colorB = p;
					break;

				case 1:
					colorR = q;
					colorG = V;
					colorB = p;
					break;
				case 2:
					colorR = p;
					colorG = V;
					colorB = t;
					break;

				case 3:
					colorR = p;
					colorG = q;
					colorB = V;
					break;

				case 4:
					colorR = t;
					colorG = p;
					colorB = V;
					break;

				default:
					colorR = V;
					colorG = p;
					colorB = q;
					break;
				}
			}
		}
	};
}
