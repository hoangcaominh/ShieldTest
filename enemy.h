#pragma once

namespace ShieldTest
{
	using namespace System;
	using namespace System::Windows::Forms;

	public ref class Enemy
	{
	public:
		Enemy()	// Default
		{
			HP = 50;
			ATK = 20;
		}
		Enemy(System::Int64 lvl)	// Based on level
		{
			if (lvl < 2)
			{
				Enemy();
			}
			else
			{
				HP = 50 + 9.0 * lvl;
				ATK = 10 + 7.0 * lvl;
			}
		}
		Enemy(System::Double hp, System::Double atk)	// Custom
		{
			HP = hp;
			ATK = atk;
		}
	public:
		System::Double HP, ATK;
	};

}
