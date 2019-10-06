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
	public ref class DrawClass
	{
		// TODO: 請在此新增此類別的方法。
	public:
		unsigned Color_R = 0;
		unsigned Color_G = 0;
		unsigned Color_B = 0;
		void Black(unsigned char* ptr, int width, int height, int channel,int pointX,int pointY,int size)
		{
			unsigned char** fp = new unsigned char* [height];
			int Stride = width * channel, x = 0, y = 0;
			for (int j = 0; j < height; j++)
				fp[j] = ptr + (Stride * j);
			for (y = pointY; y < pointY+ size; y++)
			{
				for (x = pointX*4; x < (pointX+ size)*4; x += channel)
				{
					if (y  < 0 || y  >= height || x  < 0 || x  >= Stride)
					{
						continue;
					}
					fp[y][x] = Color_B;
					fp[y][x + 1] = Color_G;
					fp[y][x + 2] = Color_R;
				}
			}
			delete[] fp;
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
