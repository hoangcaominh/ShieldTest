#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class NewProgressBar : public System::Windows::Forms::ProgressBar
{
public:
	NewProgressBar()
	{
		this->SetStyle(ControlStyles.UserPaint, true);
	}

protected:
	 System::Void OnPaint(PaintEventArgs^ e)
	{
		System::Drawing::Rectangle^ rec = e.ClipRectangle;

		rec->Width = (int)(rec->Width * ((double)Value / Maximum)) - 4;
		if (ProgressBarRenderer.IsSupported)
			ProgressBarRenderer.DrawHorizontalBar(e.Graphics, e.ClipRectangle);
		rec->Height = rec->Height - 4;
		e.Graphics.FillRectangle(Brushes.Red, 2, 2, rec->Width, rec->Height);
	}
}