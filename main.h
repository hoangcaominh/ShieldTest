#pragma once
#include "enemy.h"
#include <fstream>
#include <cmath>

namespace ShieldTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;

	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
		System::Double HP, SP, HP_MAX, SP_MAX, ATK, shield_LVL = 0;
		Enemy^ enemy = gcnew Enemy(2);

	private: System::Windows::Forms::Button^  atk_button;
	private: System::Windows::Forms::Button^  recover_button;
	private: System::Windows::Forms::Label^  hp_label;
	private: System::Windows::Forms::Label^  sp_label;
	private: System::ComponentModel::BackgroundWorker^  recover_thread;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: System::Windows::Forms::Label^  hp_point;
	private: System::Windows::Forms::ListBox^  log;
	private: System::Windows::Forms::Label^  health_bar;
	private: System::Windows::Forms::Label^  shield_bar;
	private: System::ComponentModel::BackgroundWorker^  heal_thread;
	private: System::Windows::Forms::Button^  heal_button;


	private: System::Windows::Forms::Label^  sp_point;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->atk_button = (gcnew System::Windows::Forms::Button());
			this->recover_button = (gcnew System::Windows::Forms::Button());
			this->hp_label = (gcnew System::Windows::Forms::Label());
			this->sp_label = (gcnew System::Windows::Forms::Label());
			this->recover_thread = (gcnew System::ComponentModel::BackgroundWorker());
			this->hp_point = (gcnew System::Windows::Forms::Label());
			this->sp_point = (gcnew System::Windows::Forms::Label());
			this->log = (gcnew System::Windows::Forms::ListBox());
			this->health_bar = (gcnew System::Windows::Forms::Label());
			this->shield_bar = (gcnew System::Windows::Forms::Label());
			this->heal_thread = (gcnew System::ComponentModel::BackgroundWorker());
			this->heal_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// atk_button
			// 
			this->atk_button->Location = System::Drawing::Point(12, 406);
			this->atk_button->Name = L"atk_button";
			this->atk_button->Size = System::Drawing::Size(75, 23);
			this->atk_button->TabIndex = 0;
			this->atk_button->Text = L"Attack";
			this->atk_button->UseVisualStyleBackColor = true;
			this->atk_button->Click += gcnew System::EventHandler(this, &main::atk_button_Click);
			// 
			// recover_button
			// 
			this->recover_button->Enabled = false;
			this->recover_button->Location = System::Drawing::Point(174, 406);
			this->recover_button->Name = L"recover_button";
			this->recover_button->Size = System::Drawing::Size(75, 23);
			this->recover_button->TabIndex = 1;
			this->recover_button->Text = L"Recover";
			this->recover_button->UseVisualStyleBackColor = true;
			this->recover_button->Click += gcnew System::EventHandler(this, &main::recover_button_Click);
			// 
			// hp_label
			// 
			this->hp_label->AutoSize = true;
			this->hp_label->Location = System::Drawing::Point(9, 9);
			this->hp_label->Name = L"hp_label";
			this->hp_label->Size = System::Drawing::Size(22, 13);
			this->hp_label->TabIndex = 2;
			this->hp_label->Text = L"HP";
			// 
			// sp_label
			// 
			this->sp_label->AutoSize = true;
			this->sp_label->Location = System::Drawing::Point(10, 34);
			this->sp_label->Name = L"sp_label";
			this->sp_label->Size = System::Drawing::Size(21, 13);
			this->sp_label->TabIndex = 3;
			this->sp_label->Text = L"SP";
			// 
			// recover_thread
			// 
			this->recover_thread->WorkerReportsProgress = true;
			this->recover_thread->WorkerSupportsCancellation = true;
			this->recover_thread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &main::recover_thread_DoWork);
			this->recover_thread->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &main::recover_thread_ProgressChanged);
			// 
			// hp_point
			// 
			this->hp_point->AutoSize = true;
			this->hp_point->Location = System::Drawing::Point(144, 9);
			this->hp_point->Name = L"hp_point";
			this->hp_point->Size = System::Drawing::Size(0, 13);
			this->hp_point->TabIndex = 6;
			// 
			// sp_point
			// 
			this->sp_point->AutoSize = true;
			this->sp_point->Location = System::Drawing::Point(144, 34);
			this->sp_point->Name = L"sp_point";
			this->sp_point->Size = System::Drawing::Size(0, 13);
			this->sp_point->TabIndex = 7;
			// 
			// log
			// 
			this->log->FormattingEnabled = true;
			this->log->Location = System::Drawing::Point(356, 295);
			this->log->Name = L"log";
			this->log->Size = System::Drawing::Size(256, 134);
			this->log->TabIndex = 8;
			// 
			// health_bar
			// 
			this->health_bar->BackColor = System::Drawing::Color::Red;
			this->health_bar->Location = System::Drawing::Point(37, 9);
			this->health_bar->Name = L"health_bar";
			this->health_bar->Size = System::Drawing::Size(100, 13);
			this->health_bar->TabIndex = 9;
			// 
			// shield_bar
			// 
			this->shield_bar->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->shield_bar->Location = System::Drawing::Point(37, 34);
			this->shield_bar->Name = L"shield_bar";
			this->shield_bar->Size = System::Drawing::Size(100, 13);
			this->shield_bar->TabIndex = 10;
			// 
			// heal_thread
			// 
			this->heal_thread->WorkerReportsProgress = true;
			this->heal_thread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &main::heal_thread_DoWork);
			this->heal_thread->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &main::heal_thread_ProgressChanged);
			// 
			// heal_button
			// 
			this->heal_button->Enabled = false;
			this->heal_button->Location = System::Drawing::Point(93, 406);
			this->heal_button->Name = L"heal_button";
			this->heal_button->Size = System::Drawing::Size(75, 23);
			this->heal_button->TabIndex = 11;
			this->heal_button->Text = L"Heal";
			this->heal_button->UseVisualStyleBackColor = true;
			this->heal_button->Click += gcnew System::EventHandler(this, &main::heal_button_Click);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->heal_button);
			this->Controls->Add(this->shield_bar);
			this->Controls->Add(this->health_bar);
			this->Controls->Add(this->log);
			this->Controls->Add(this->sp_point);
			this->Controls->Add(this->hp_point);
			this->Controls->Add(this->sp_label);
			this->Controls->Add(this->hp_label);
			this->Controls->Add(this->recover_button);
			this->Controls->Add(this->atk_button);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"main";
			this->Text = L"Shield Test";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &main::main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void main_Load(System::Object^  sender, System::EventArgs^  e)
	{
		ParseData();
		UpdateUI();
	}

	private: System::Void main_FormClosing(System::Object^ sender, FormClosingEventArgs^ e)
	{
		FileStream^ data = gcnew FileStream("data.txt", FileMode::OpenOrCreate, FileAccess::Write);
		StreamWriter^ write = gcnew StreamWriter(data);
		write->WriteLine(this->HP);
		write->WriteLine(this->HP_MAX);
		write->WriteLine(this->SP);
		write->WriteLine(this->SP_MAX);
		write->WriteLine(this->ATK);
		write->WriteLine(this->enemy->ATK);

		write->Close();
		data->Close();
		Application::Exit();
	}

	private: System::Void ParseData()
	{
		FileStream^ data = gcnew FileStream("data.txt", FileMode::OpenOrCreate, FileAccess::Read);
		if (data->Length == 0)
		{
			this->HP = this->HP_MAX = this->SP = this->SP_MAX = 30.0;
			this->enemy->ATK = 16.0;
			data->Close();
			return;
		}

		StreamReader^ read = gcnew StreamReader(data);
		this->HP = Convert::ToDouble(read->ReadLine());
		this->HP_MAX = Convert::ToDouble(read->ReadLine());
		this->SP = Convert::ToDouble(read->ReadLine());
		this->SP_MAX = Convert::ToDouble(read->ReadLine());
		this->ATK = Convert::ToDouble(read->ReadLine());
		this->enemy->ATK = Convert::ToDouble(read->ReadLine());
		read->Close();
		data->Close();
	}

	private: System::Void UpdateUI()
	{
		// Update UI
		this->health_bar->Width = (System::Int32)((this->HP / this->HP_MAX) * 100);
		this->hp_point->Text = (Math::Ceiling(this->HP) + L"/" + Math::Ceiling(this->HP_MAX));
		this->shield_bar->Width = (System::Int32)((this->SP / this->SP_MAX) * 100);
		this->sp_point->Text = (Math::Ceiling(this->SP) + L"/" + Math::Ceiling(this->SP_MAX));

		if (Math::Ceiling(HP) < Math::Ceiling(this->HP_MAX))
		{
			this->heal_button->Enabled = true;
		}
		if (Math::Ceiling(SP) < Math::Ceiling(this->SP_MAX))
		{
			this->recover_button->Enabled = true;
		}

		// Update log
		this->log->Items->Add("The enemy attacked you! " + Math::Ceiling(this->enemy->ATK) + " damage!");

		if (this->HP == 0)
		{
			this->log->Items->Add(L"You lost");
		}

		while (this->log->Items->Count > 9)
		{
			this->log->Items->RemoveAt(0);
		}
	}

	private: System::Void atk_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		/*	Disable enemy hp drain
		enemy->HP = System::Math::Max(enemy->HP - this->ATK, 0ll);
		this->log->Items->Add(L"Enemy's HP: " + enemy->HP);
		if (enemy->HP == 0)
		{
			delete enemy;
			this->log->Items->Add(L"You won");
		}
		*/

		// Enemy Attacks
		if (this->recover_thread->IsBusy)
		{
			this->HP = Math::Max(this->HP - this->enemy->ATK, 0.0);
		}
		else
		{
			this->SP -= this->enemy->ATK;

			// Automatically recover SP if SP <= 0
			if (this->SP <= 0)
			{
				// Reduce HP by the rest of the enemy's ATK
				this->HP = Math::Max(this->HP + this->SP, 0.0);
				this->SP = 0.0;
				this->recover_button->Enabled = false;
				this->recover_thread->RunWorkerAsync();
			}
		}

		// Enemy's increment format
		this->enemy->ATK += this->enemy->ATK * 5 / 100;
		UpdateUI();
	}

	private: System::Void recover_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->recover_button->Enabled = false;
		if (!this->recover_thread->IsBusy)
		{
			this->recover_thread->RunWorkerAsync();
		}
	}

	private: System::Void recover_thread_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		// SP_MAX increment format
		this->SP_MAX += (this->SP_MAX - this->SP) * 15 / 100;
		// SP increment format
		// divided by 1000 to increase every milisecond
		// Quick-recover formula (squared cubic root)
		// System::Double increment = cbrt(this->SP_MAX) * cbrt(this->SP_MAX) / 1000;
		// Square root formula
		// System::Double increment = sqrt(this->SP_MAX) / 1000;
		// Cubic root formula
		System::Double increment = cbrt(this->SP_MAX) / 1000;
		// Super-slow-recover formula (log2)
		// System::Double increment = log2(this->SP_MAX) / 1000;
		while (this->SP < this->SP_MAX)
		{
			this->SP = Math::Min(this->SP + increment, this->SP_MAX);

			this->recover_thread->ReportProgress((System::Int32)Math::Ceiling(this->SP / this->SP_MAX * 100));
			System::Threading::Thread::Sleep(1);
		}
	}

	private: System::Void recover_thread_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		this->shield_bar->Width = e->ProgressPercentage;
		this->sp_point->Text = (Math::Ceiling(this->SP) + L"/" + Math::Ceiling(this->SP_MAX));
	}

	private: System::Void heal_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->heal_button->Enabled = false;
		if (!this->heal_thread->IsBusy)
		{
			this->heal_thread->RunWorkerAsync();
		}
	}

	private: System::Void heal_thread_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		while (this->HP < this->HP_MAX)
		{
			this->HP = Math::Min(++this->HP, this->HP_MAX);

			this->heal_thread->ReportProgress((System::Int32)Math::Ceiling(this->HP / this->HP_MAX * 100));
			// Healing speed
			System::Threading::Thread::Sleep(500);
		}
	}
			 
	private: System::Void heal_thread_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		this->health_bar->Width = e->ProgressPercentage;
		this->hp_point->Text = (Math::Ceiling(this->HP) + L"/" + Math::Ceiling(this->HP_MAX));
	}
};
}
