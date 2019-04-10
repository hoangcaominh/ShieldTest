#pragma once
#include "enemy.h"

namespace ShieldTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			HP = HP_MAX = SP = SP_MAX = 100.0;
			ATK = 16.0;

			this->hp_point->Text = (HP + L"/" + HP_MAX);
			this->sp_point->Text = (SP + L"/" + SP_MAX);
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
	private: System::Windows::Forms::ProgressBar^  health_bar;
	private: System::Windows::Forms::ProgressBar^  shield_bar;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: System::Windows::Forms::Label^  hp_point;
	private: System::Windows::Forms::ListBox^  log;

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
			this->health_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->shield_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->hp_point = (gcnew System::Windows::Forms::Label());
			this->sp_point = (gcnew System::Windows::Forms::Label());
			this->log = (gcnew System::Windows::Forms::ListBox());
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
			this->recover_button->Location = System::Drawing::Point(93, 406);
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
			this->recover_thread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &main::recover_thread_DoWork);
			this->recover_thread->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &main::recover_thread_ProgressChanged);
			this->recover_thread->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &main::recover_thread_RunWorkerCompleted);
			// 
			// health_bar
			// 
			this->health_bar->Location = System::Drawing::Point(37, 9);
			this->health_bar->Name = L"health_bar";
			this->health_bar->Size = System::Drawing::Size(100, 13);
			this->health_bar->TabIndex = 4;
			this->health_bar->Value = 100;
			// 
			// shield_bar
			// 
			this->shield_bar->Location = System::Drawing::Point(37, 34);
			this->shield_bar->Name = L"shield_bar";
			this->shield_bar->Size = System::Drawing::Size(100, 13);
			this->shield_bar->TabIndex = 5;
			this->shield_bar->Value = 100;
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
			this->log->Location = System::Drawing::Point(492, 295);
			this->log->Name = L"log";
			this->log->Size = System::Drawing::Size(120, 134);
			this->log->TabIndex = 8;
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->log);
			this->Controls->Add(this->sp_point);
			this->Controls->Add(this->hp_point);
			this->Controls->Add(this->shield_bar);
			this->Controls->Add(this->health_bar);
			this->Controls->Add(this->sp_label);
			this->Controls->Add(this->hp_label);
			this->Controls->Add(this->recover_button);
			this->Controls->Add(this->atk_button);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"main";
			this->Text = L"Shield Test";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
		if (recover_thread->IsBusy)
		{
			this->HP = Math::Max(this->HP - enemy->ATK, 0.0);
		}
		else
		{
			this->recover_button->Enabled = true;
			this->SP = Math::Max(this->SP - enemy->ATK, 0.0);

			// Automatically recover SP if SP = 0
			if (this->SP == 0)
			{
				// Reduce HP by 20% of SP_MAX if SP = 0
				this->HP = Math::Max(this->HP - this->SP_MAX * 20 / 100, 0.0);
				this->recover_button->Enabled = false;
				recover_thread->RunWorkerAsync();
			}
		}
		enemy->ATK++;
		// Update UI
		this->health_bar->Value = (System::Int32)((HP / HP_MAX) * 100);
		this->hp_point->Text = (Math::Ceiling(HP) + L"/" + Math::Ceiling(HP_MAX));
		this->shield_bar->Value = (System::Int32)((SP / SP_MAX) * 100);
		this->sp_point->Text = (Math::Ceiling(SP) + L"/" + Math::Ceiling(SP_MAX));
		if (this->HP == 0)
		{
			this->log->Items->Add(L"You lost");
		}
	}

	private: System::Void recover_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->recover_button->Enabled = false;
		if (!recover_thread->IsBusy)
		{
			recover_thread->RunWorkerAsync();
		}
	}

	private: System::Void recover_thread_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		// SP_MAX calculating format
		SP_MAX += ((SP_MAX - SP) / SP_MAX * 100) * SP_MAX / (100 + ++shield_LVL) * 15 / 100;
		while (this->SP < this->SP_MAX)
		{
			SP++;
			SP = Math::Min(SP, SP_MAX);

			recover_thread->ReportProgress((System::Int32)Math::Ceiling(SP / SP_MAX * 100));
			// Recover speed
			System::Threading::Thread::Sleep(10);
		}
	}

	private: System::Void recover_thread_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		this->shield_bar->Value = e->ProgressPercentage;
		this->sp_point->Text = (Math::Ceiling(SP) + L"/" + Math::Ceiling(SP_MAX));
	}

	private: System::Void recover_thread_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
	{

	}

	private: System::Void main_Load(System::Object^  sender, System::EventArgs^  e)
	{

	}
};
}
