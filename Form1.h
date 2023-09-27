#pragma once
#include "omp.h"
#include <cstdlib>

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		int nThreads;
		int rows;
		float** matrixA;
		float** matrixB;
		float** matrixR;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ Amatrix;
	private: System::Windows::Forms::TextBox^ Bmatrix;
	private: System::Windows::Forms::TextBox^ Rmatrix;




	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Diagnostics::PerformanceCounter^ performanceCounter1;
	private: System::Windows::Forms::Button^ button3;
		   String^ message;
	public:
		Form1(void)
		{
			InitializeComponent();
			nThreads = 1;
			rows = 5;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Amatrix = (gcnew System::Windows::Forms::TextBox());
			this->Bmatrix = (gcnew System::Windows::Forms::TextBox());
			this->Rmatrix = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->performanceCounter1 = (gcnew System::Diagnostics::PerformanceCounter());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->performanceCounter1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Set threads";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(62, 206);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Go";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::Go_click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(62, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 20);
			this->textBox1->TabIndex = 2;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) { L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8" });
			this->comboBox1->Location = System::Drawing::Point(74, 33);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"4", L"5", L"6", L"7", L"8", L"9", L"10", L"11",
					L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"30", L"40", L"50", L"60", L"70", L"80", L"90", L"100", L"250",
					L"500", L"1000", L"3000"
			});
			this->comboBox2->Location = System::Drawing::Point(74, 71);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Set size";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(265, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Matrix A";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(529, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Matrix B";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(401, 214);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Matrix R";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// Amatrix
			// 
			this->Amatrix->Location = System::Drawing::Point(268, 33);
			this->Amatrix->Multiline = true;
			this->Amatrix->Name = L"Amatrix";
			this->Amatrix->Size = System::Drawing::Size(181, 141);
			this->Amatrix->TabIndex = 9;
			this->Amatrix->TextChanged += gcnew System::EventHandler(this, &Form1::Amatrix_TextChanged);
			// 
			// Bmatrix
			// 
			this->Bmatrix->Location = System::Drawing::Point(532, 33);
			this->Bmatrix->Multiline = true;
			this->Bmatrix->Name = L"Bmatrix";
			this->Bmatrix->Size = System::Drawing::Size(181, 141);
			this->Bmatrix->TabIndex = 10;
			this->Bmatrix->TextChanged += gcnew System::EventHandler(this, &Form1::Bmatrix_TextChanged);
			// 
			// Rmatrix
			// 
			this->Rmatrix->Location = System::Drawing::Point(345, 230);
			this->Rmatrix->Multiline = true;
			this->Rmatrix->Name = L"Rmatrix";
			this->Rmatrix->Size = System::Drawing::Size(181, 141);
			this->Rmatrix->TabIndex = 11;
			this->Rmatrix->TextChanged += gcnew System::EventHandler(this, &Form1::Rmatrix_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(239, 230);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Initialize";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::Initialize_click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(62, 166);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 169);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"% CPU";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 130);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Tiempo";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// performanceCounter1
			// 
			this->performanceCounter1->CategoryName = L"Procesador";
			this->performanceCounter1->CounterName = L"% de tiempo de procesador";
			this->performanceCounter1->InstanceName = L"_Total";
			this->performanceCounter1->MachineName = L"DESKTOP-OS0MI64";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(657, 348);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(756, 402);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Rmatrix);
			this->Controls->Add(this->Bmatrix);
			this->Controls->Add(this->Amatrix);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Ejercicio1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->performanceCounter1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Go_click(System::Object^ sender, System::EventArgs^ e) {
		backgroundWorker1->RunWorkerAsync();

		if (rows <= 20) {
			Rmatrix->ResetText();
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < rows; j++) {
					Rmatrix->AppendText(String::Concat(Convert::ToString(matrixR[i][j]), " "));
				}
				Rmatrix->AppendText("\r\n");
			}
		}
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		nThreads = int::Parse(comboBox1->Text);
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		rows = int::Parse(comboBox2->Text);
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		double stime = omp_get_wtime();
		#pragma omp parallel num_threads(nThreads)
		{
		
			// Bucle optimizado
		#pragma omp for schedule(static, 1)
			for (int i = 0; i < rows; i++)
				for (int k = 0; k < rows; k++)
					for (int j = 0; j < rows; j++) {
						matrixR[i][j] += matrixA[i][k] * matrixB[k][j];
					}

		/*  Bucle que se nos proporciona en la practica
		#pragma omp for schedule(static, 1)
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < rows; j++)
					for (int k = 0; k < rows; k++) {
						matrixR[i][j] += matrixA[i][k] * matrixB[k][j];
					}
		*/

		}
		this->textBox2->Text = Convert::ToString(performanceCounter1->NextValue());
		stime = omp_get_wtime() - stime;
		message = String::Concat("Elapsed time: ", Convert::ToString(stime), "seconds");
		SetText(message);
	}
	private: void SetText(String^ texto) {
		if (this->textBox1->InvokeRequired) {
			SetTextDelegate^ d = gcnew SetTextDelegate(this, &Form1::SetText);
			this->Invoke(d, gcnew array<Object^> {texto});
		}
		else {
			this->textBox1->Text = texto;
		}
	}
	protected:
		delegate void SetTextDelegate(String^ message);
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   
	private: System::Void Initialize_click(System::Object^ sender, System::EventArgs^e) {
		matrixA = new float* [rows];
		matrixB = new float* [rows];
		matrixR = new float* [rows];

		this->textBox1->Text = " ";

		for (int i = 0; i < rows; i++) 
			matrixA[i] = new float[rows];
		
		for (int i = 0; i < rows; i++) 
			matrixB[i] = new float[rows];
		
		for (int i = 0; i < rows; i++) 
			matrixR[i] = new float[rows];
		
		for (int i = 0; i < rows; i++) 
			for (int j = 0; j < rows; j++) {
				matrixA[i][j] = matrixB[i][j] = i + j;
				matrixR[i][j] = 0;
			}

			Amatrix->ResetText();
			Bmatrix->ResetText();
			Rmatrix->ResetText();

			if (rows <= 20) {
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < rows; j++) {
						Amatrix->AppendText(String::Concat(Convert::ToString(matrixA[i][j]), " "));
						Bmatrix->AppendText(String::Concat(Convert::ToString(matrixB[i][j]), " "));
						Rmatrix->AppendText(String::Concat(Convert::ToString(matrixR[i][j]), " "));
					}
					Amatrix->AppendText("\r\n");
					Bmatrix->AppendText("\r\n");
					Rmatrix->AppendText("\r\n");
				}
			}
			
	}
	private: System::Void Rmatrix_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Amatrix_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Bmatrix_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		this->textBox2->Text = Convert::ToString(performanceCounter1->NextValue());
	}
	// Acción del boton exit, termina el proceso
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
};
}
