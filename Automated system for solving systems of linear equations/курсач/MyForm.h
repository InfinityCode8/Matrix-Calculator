#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;
int rows = 2;
int Colums = 2;
float boot[6][6][6];
float detAm[5][5];
namespace курсач {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		
		void counter1() {// Зміна розміру матриці для першого повзунка
			if (Colums < Convert::ToInt16(numericUpDown1->Value)) {

				for (int i = Colums; i < Convert::ToInt16(numericUpDown1->Value); i++) {
					dataGridView1->Columns->Add(Convert::ToString(""), Convert::ToString("b"));
					dataGridView1->Columns[i + 1]->Width = 50;
					dataGridView1->Columns[i]->HeaderCell->Value = "X"+(i+1);
				}
				Colums = Convert::ToInt16(numericUpDown1->Value);
			}
			else if (Colums > Convert::ToInt16(numericUpDown1->Value)) {
				for (int i = Colums; i > Convert::ToInt16(numericUpDown1->Value); i--) {
					dataGridView1->Columns->RemoveAt(i);
					dataGridView1->Columns[i-1]->HeaderCell->Value = "b";
				}
				Colums = Convert::ToInt16(numericUpDown1->Value);
			}
		}
		void counter2() {// Зміна розміру матриці для першого повзунка
			if (rows < Convert::ToInt16(numericUpDown2->Value)) {
				dataGridView1->Rows->Add(Convert::ToInt16(numericUpDown2->Value) - rows);
				rows = Convert::ToInt16(numericUpDown2->Value);
			}
			else if (rows > Convert::ToInt16(numericUpDown2->Value)) {
				for (int i = 0; i < rows - Convert::ToInt16(numericUpDown2->Value); i++) {
					dataGridView1->Rows->RemoveAt(0);
				}
				rows = Convert::ToInt16(numericUpDown2->Value);

			}
		}
		

		// обчислення матриці 3 на 3
		float Kramer3x3(int det, string A)
		{
			
			
			fstream fs;
			fs.open("BootString.txt", fstream::in | fstream::out | fstream::app);
			fs.precision(3);
			float detA = boot[0][0][1] * boot[1][1][1] * boot[2][2][1] + boot[1][0][1] * boot[2][1][1] * boot[0][2][1] + boot[0][1][1] * boot[1][2][1] * boot[2][0][1] - boot[0][2][1] * boot[1][1][1] * boot[2][0][1] - boot[1][0][1] * boot[0][1][1] * boot[2][2][1] - boot[2][1][1] * boot[1][2][1] * boot[0][0][1];
			fs << std::left << "              " << setw(6) << "|" << setw(6) << boot[0][0][1] << setw(6)  << boot[0][1][1] << setw(6) << boot[0][2][1] << setw(1) << "|\r\n";
			fs << std::left << "det"<<A<< det << "= " << setw(6) << "|" << setw(6) << boot[1][0][1] << setw(6)  << boot[1][1][1] << setw(6)  << boot[1][2][1] << setw(1) << "|  = "  << boot[0][0][1] << "*"  << boot[1][1][1] << "*"  << boot[2][2][1] << " + "  << boot[1][0][1] << "*"
				 << boot[2][1][1] << "*"  << boot[0][2][1] << " + "  << boot[0][1][1] << "*"  << boot[1][2][1] << "*" << boot[2][0][1] << " - "  << boot[0][2][1] << "*"  << boot[1][1][1] << "*"  << boot[2][0][1] << " - "  << boot[1][0][1] << "*"  << boot[0][1][1] << "*"  << boot[2][2][1] << " - "  << boot[2][1][1] << "*"  << boot[1][2][1] << "*"  << boot[0][0][1] << " = "  <<
				detA << "\r\n";
			fs << std::left << "              " << setw(6) << "|" << setw(6) << boot[2][0][1] << setw(6)  << boot[2][1][1] << setw(6)  << boot[2][2][1] << "|\r\n\r\n";
			fs.close();
			return detA;
		}

		// обчислення матриці 4 на 4
		float Kramer4x4(int det1) {
			fstream fs;
			fs.open("BootString.txt", fstream::in | fstream::out | fstream::app);
			fs.precision(3);
			fs << std::left << "                " << setw(6) << "|" << setw(6)  << boot[0][0][2] << setw(6)  << boot[0][1][2] << setw(6)  << boot[0][2][2] << setw(6)  << boot[0][3][2] << setw(1) << "|\r\n";
			fs << std::left << "detM"<< det1 << "=  " << setw(6) << "|" << setw(6)  << boot[1][0][2] << setw(6)  << boot[1][1][2] << setw(6)  << boot[1][2][2] << setw(6)  << boot[1][3][2] << setw(1) << "|  = "  << boot[0][0][2] << "*A1 - "  << boot[0][1][2] << "*A2 + "  << boot[0][2][2] << "*A3 - "  << boot[0][3][2] << "*A4" << "\r\n";
			fs << std::left << "                " << setw(6) << "|" << setw(6)  << boot[2][0][2] << setw(6)  << boot[2][1][2] << setw(6)  << boot[2][2][2] << setw(6)  << boot[2][3][2] << setw(1) << "|\r\n";
			fs << std::left << "                " << setw(6) << "|" << setw(6)  << boot[3][0][2] << setw(6) << boot[3][1][2] << setw(6) << boot[3][2][2] << setw(6)  << boot[3][3][2] << setw(1) << "|\r\n\r\n";
			for (int i = 1; i <= 3; i++) {
				for (int f = 1; f <= 3; f++) {
					boot[i - 1][f - 1][1] = boot[i][f][2];

				}
			}

			int det = 1;
			detAm[0][0] = Kramer3x3(det, "A");
			det++;
			for (int i = 1; i <= 3; i++) {
				boot[i - 1][0][1] = boot[i][0][2];

			}
			detAm[1][0] = Kramer3x3(det, "A");
			det++;
			for (int i = 1; i <= 3; i++) {
				boot[i - 1][1][1] = boot[i][1][2];
			}

			detAm[2][0] = Kramer3x3(det, "A");
			det++;
			for (int i = 1; i < Colums; i++) {
				boot[i - 1][2][1] = boot[i][2][2];

			}
			detAm[3][0] = Kramer3x3(det, "A");


			fs << "detM"<< det1 <<"=" << boot[0][0][2] * detAm[0][0] << " - " << boot[0][1][2] * detAm[1][0] << " + " << boot[0][2][2] * detAm[2][0] << " - " << boot[0][3][2] * detAm[3][0] << " = " << boot[0][0][2] * detAm[0][0] - boot[0][1][2] * detAm[1][0] + boot[0][2][2] * detAm[2][0] - boot[0][3][2] * detAm[3][0] << "\r\n";
			fs << "___________________________________________________________________________________________________________________________\r\n";
			fs.close();
			return boot[0][0][2] * detAm[0][0] - boot[0][1][2] * detAm[1][0] + boot[0][2][2] * detAm[2][0] - boot[0][3][2] * detAm[3][0];
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:

	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;








	private: System::Windows::Forms::TextBox^ displayText;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::PictureBox^ pictureBox2;

private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ X1;










	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->X1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->displayText = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Silver;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->X1 });
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(33, 61);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(338, 147);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// X1
			// 
			this->X1->HeaderText = L"X1";
			this->X1->MinimumWidth = 50;
			this->X1->Name = L"X1";
			this->X1->Width = 50;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::Silver;
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(131, 21);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(70, 24);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->BackColor = System::Drawing::Color::Silver;
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown2->Location = System::Drawing::Point(33, 21);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(70, 24);
			this->numericUpDown2->TabIndex = 2;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Silver;
			this->label1->Location = System::Drawing::Point(108, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Silver;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(997, 418);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 46);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Обчислити";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Silver;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(859, 532);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 47);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Очистити";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Silver;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(580, 133);
			this->radioButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(133, 21);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Метод Крамера\r\n";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Silver;
			this->radioButton2->Location = System::Drawing::Point(580, 160);
			this->radioButton2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(197, 21);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Метод оберненої матриці";
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Silver;
			this->radioButton3->Location = System::Drawing::Point(580, 187);
			this->radioButton3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(113, 21);
			this->radioButton3->TabIndex = 10;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Метод Гауса";
			this->radioButton3->UseVisualStyleBackColor = false;
			// 
			// displayText
			// 
			this->displayText->BackColor = System::Drawing::Color::White;
			this->displayText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayText->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->displayText->ForeColor = System::Drawing::Color::Black;
			this->displayText->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->displayText->Location = System::Drawing::Point(33, 318);
			this->displayText->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->displayText->MaxLength = 10;
			this->displayText->Multiline = true;
			this->displayText->Name = L"displayText";
			this->displayText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->displayText->ShortcutsEnabled = false;
			this->displayText->Size = System::Drawing::Size(715, 291);
			this->displayText->TabIndex = 13;
			this->displayText->WordWrap = false;
			this->displayText->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->displayText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::displayText_KeyPress);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Silver;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(997, 507);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(128, 71);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Завантажити файл\r\n";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(1023, 34);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(109, 102);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Silver;
			this->label2->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(340, 290);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 25);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Етапи розвязку";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Silver;
			this->pictureBox2->Location = System::Drawing::Point(571, 126);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(225, 91);
			this->pictureBox2->TabIndex = 17;
			this->pictureBox2->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Текстовые файлы|*.txt|Все файлы|*.*";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1155, 622);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->displayText);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Автоматизована система розв\'язку лінійних рівнянь";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {



		counter2(); // Зміна розміру матриці
		numericUpDown1->Value= rows;
		counter1(); 

		
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
			
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {



		counter1(); // Зміна розміру матриці
		numericUpDown2->Value = Colums;
		counter2();
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Columns->Add(Convert::ToString(2), Convert::ToString("X2"));
		dataGridView1->Columns[1]->Width = 50;
		dataGridView1->Columns->Add(Convert::ToString(3), Convert::ToString("b"));
		dataGridView1->Columns[2]->Width = 50;
		dataGridView1->Rows->Add(2);
	}
		 
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		
		// Перевірка і запис даних в буфер обміну (boot)
			for (int i = 0; i < rows; i++) {
				for (int f = 0; f <= Colums; f++) {
					try {
						if (Convert::ToString(dataGridView1->Rows[i]->Cells[f]->Value) == "") {
							boot[i][f][0] = 0;
						}
						else {
							boot[i][f][0] = Convert::ToDouble(dataGridView1->Rows[i]->Cells[f]->Value);
						}
				}
					catch (Exception^ ex) {
						//Если при конвертировании возникает ошибка - показываем окно ошибки и стираем значение ячейки
						MessageBox::Show("Введіть дійсне число");
						this->dataGridView1->Rows[i]->Cells[f]->Value = "";
					}
				}
			}
			ofstream out;
			out.open("BootString.txt");
			float detA;
			float detA1;
			float detA2;
			float detA3;
			// обчислення методом Крамери матриць від 2 на 2 до 4 на 4
			if (radioButton1->Checked) {
				switch (rows) {

				case 2:
					out.precision(3);
					detA = boot[0][0][0] * boot[1][1][0] - boot[0][1][0] * boot[1][0][0];
					if (detA == 0) {
						out << std::left << "Error!!! detA = 0, the matrix is not solved \r\n";
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << "|\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << " - " << boot[0][1][0] << "*" << boot[1][0][0] << " = " << detA << "\r\n\r\n";

					}
					else {
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << "|\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << " - "  << boot[0][1][0] << "*"  << boot[1][0][0] << " = " << detA << "\r\n\r\n";

						detA1 = boot[0][2][0] * boot[1][1][0] - boot[0][1][0] * boot[1][2][0];
						out << std::left << "detA1 = " << setw(6) << "|" << setw(6) << boot[0][2][0] << setw(6) << boot[0][1][0] << setw(1) << "|\r\n";
						out << std::left << "              " << setw(6) << "|" << setw(6) << boot[1][2][0] << setw(6) << boot[1][1][0] << setw(1) << "|  = " << boot[0][2][0] << "*" << boot[1][1][0] << " - " << boot[0][1][0] << "*" << boot[1][2][0] << " = " << detA1 << "\r\n\r\n";

						detA2 = boot[0][0][0] * boot[1][2][0] - boot[0][2][0] * boot[1][0][0];
						out << std::left << "detA2 = " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][2][0] << setw(1) << "|\r\n";
						out << std::left << "              " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][2][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][2][0] << " - " << boot[0][2][0] << "*" << boot[1][0][0] << " = " << detA2 << "\r\n\r\n";
						out << "X1 = detA1/detA = "  << (detA1 / detA)  << "\r\n";
						out << "X2 = detA2/detA = "  << (detA2 / detA)  << "\r\n";
					}
					out.close();
					break;
				case 3:
					out.precision(3);
					detA = boot[0][0][0] * boot[1][1][0] * boot[2][2][0] + boot[1][0][0] * boot[2][1][0] * boot[0][2][0] + boot[0][1][0] * boot[1][2][0] * boot[2][0][0] - boot[0][2][00] * boot[1][1][0] * boot[2][0][0] - boot[1][0][0] * boot[0][1][0] * boot[2][2][0] - boot[2][1][0] * boot[1][2][0] * boot[0][0][0];

					if (detA == 0) {
						
						out << std::left << "Error!!! detA = 0, the matrix is not solved \r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << setw(6) << boot[0][2][0] << setw(1) << "|\r\n";
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(6) << boot[1][2][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << "*" << boot[2][2][0] << " + " << boot[1][0][0] << "*"
							<< boot[2][1][0] << "*" << boot[0][2][0] << " + " << boot[0][1][0] << "*" << boot[1][2][0] << "*" << boot[2][0][0] << " - " << boot[0][2][0] << "*" << boot[1][1][0] << "*" << boot[2][0][0] << " - " << boot[1][0][0] << "*" << boot[0][1][0] << "*" << boot[2][2][0] << " - " << boot[2][1][0] << "*" << boot[1][2][0] << "*" << boot[0][0][0] << " = " <<
							detA << "\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[2][0][0] << setw(6) << boot[2][1][0] << setw(6) << boot[2][2][0] << "|\r\n\r\n";

					}
					else {
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << setw(6) << boot[0][2][0] << setw(1) << "|\r\n";
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(6) << boot[1][2][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << "*" << boot[2][2][0] << " + " << boot[1][0][0] << "*"
							<< boot[2][1][0] << "*" << boot[0][2][0] << " + " << boot[0][1][0] << "*" << boot[1][2][0] << "*" << boot[2][0][0] << " - " << boot[0][2][0] << "*" << boot[1][1][0] << "*" << boot[2][0][0] << " - " << boot[1][0][0] << "*" << boot[0][1][0] << "*" << boot[2][2][0] << " - " << boot[2][1][0] << "*" << boot[1][2][0] << "*" << boot[0][0][0] << " = " <<
							detA << "\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[2][0][0] << setw(6) << boot[2][1][0] << setw(6) << boot[2][2][0] << "|\r\n\r\n";

						detA1 = boot[0][3][0] * boot[1][1][0] * boot[2][2][0] + boot[1][3][0] * boot[2][1][0] * boot[0][2][0] + boot[0][1][0] * boot[1][2][0] * boot[2][3][0] - boot[0][2][0] * boot[1][1][0] * boot[2][3][0] - boot[1][3][0] * boot[0][1][0] * boot[2][2][0] - boot[2][1][0] * boot[1][2][0] * boot[0][3][0];
						out << std::left << "               " << setw(6) << "|" << setw(6) << boot[0][3][0] << setw(6) << boot[0][1][0] << setw(6) << boot[0][2][0] << setw(1) << "|\r\n";
						out << std::left << "detA1 =  " << setw(6) << "|" << setw(6) << boot[1][3][0] << setw(6) << boot[1][1][0] << setw(6) << boot[1][2][0] << setw(1) << "|  = " << boot[0][3][0] << "*" << boot[1][1][0] << "*" << boot[2][2][0] << " + " << boot[1][3][0] << "*"
							<< boot[2][1][0] << "*" << boot[0][2][0] << " + " << boot[0][1][0] << "*" << boot[1][2][0] << "*" << boot[2][3][0] << " - " << boot[0][2][0] << "*" << boot[1][1][0] << "*" << boot[2][3][0] << " - " << boot[1][3][0] << "*" << boot[0][1][0] << "*" << boot[2][2][0] << " - " << boot[2][1][0] << "*" << boot[1][2][0] << "*" << boot[0][3][0] << " = " <<
							detA1 << "\r\n";
						out << std::left << "               " << setw(6) << "|" << setw(6) << boot[2][3][0] << setw(6) << boot[2][1][0] << setw(6) << boot[2][2][0] << "|\r\n\r\n";

						detA2 = boot[0][0][0] * boot[1][3][0] * boot[2][2][0] + boot[1][0][0] * boot[2][3][0] * boot[0][2][0] + boot[0][3][0] * boot[1][2][0] * boot[2][0][0] - boot[0][2][0] * boot[1][3][0] * boot[2][0][0] - boot[1][0][0] * boot[0][3][0] * boot[2][2][0] - boot[2][3][0] * boot[1][2][0] * boot[0][0][0];
						out << std::left << "               " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][3][0] << setw(6) << boot[0][2][0] << setw(1) << "|\r\n";
						out << std::left << "detA2 =  " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][3][0] << setw(6) << boot[1][2][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][3][0] << "*" << boot[2][2][0] << " + " << boot[1][0][0] << "*"
							<< boot[2][3][0] << "*" << boot[0][2][0] << " + " << boot[0][3][0] << "*" << boot[1][2][0] << "*" << boot[2][0][0] << " - " << boot[0][2][0] << "*" << boot[1][3][0] << "*" << boot[2][0][0] << " - " << boot[1][0][0] << "*" << boot[0][3][0] << "*" << boot[2][2][0] << " - " << boot[2][3][0] << "*" << boot[1][2][0] << "*" << boot[0][0][0] << " = " <<
							detA2 << "\r\n";
						out << std::left << "               " << setw(6) << "|" << setw(6) << boot[2][0][0] << setw(6) << boot[2][3][0] << setw(6) << boot[2][2][0] << "|\r\n\r\n";

						detA3 = boot[0][0][0] * boot[1][1][0] * boot[2][3][0] + boot[1][0][0] * boot[2][1][0] * boot[0][3][0] + boot[0][1][0] * boot[1][3][0] * boot[2][0][0] - boot[0][3][0] * boot[1][1][0] * boot[2][0][0] - boot[1][0][0] * boot[0][1][0] * boot[2][3][0] - boot[2][1][0] * boot[1][3][0] * boot[0][0][0];
						out << std::left << "               " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << setw(6) << boot[0][3][0] << setw(1) << "|\r\n";
						out << std::left << "detA3 =  " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(6) << boot[1][3][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << "*" << boot[2][3][0] << " + " << boot[1][0][0] << "*"
							<< boot[2][1][0] << "*" << boot[0][3][0] << " + " << boot[0][1][0] << "*" << boot[1][3][0] << "*" << boot[2][0][0] << " - " << boot[0][3][0] << "*" << boot[1][1][0] << "*" << boot[2][0][0] << " - " << boot[1][0][0] << "*" << boot[0][1][0] << "*" << boot[2][3][0] << " - " << boot[2][1][0] << "*" << boot[1][3][0] << "*" << boot[0][0][0] << " = " <<
							detA3 << "\r\n";
						out << std::left << "               " << setw(6) << "|" << setw(6) << boot[2][0][0] << setw(6) << boot[2][1][0] << setw(6) << boot[2][3][0] << "|\r\n\r\n";
						out << "X1 = detA1/detA = " << (detA1 / detA) << "\r\n";
						out << "X2 = detA2/detA = " << (detA2 / detA) << "\r\n";
						out << "X3 = detA3/detA = " << (detA3 / detA) << "\r\n";
					}
					out.close();
					break;
				case 4:
					out.precision(3);
					float detAm[5];
					out.close();
					for (int i = 0; i <= 3; i++) {
						for (int f = 0; f <= 3; f++) {
							boot[i][f][2] = boot[i][f][0];

						}
					}
					int det = 0;
					detAm[0] = Kramer4x4(det);
					if (detAm[0] == 0) {
						ofstream out;
						out.open("BootString.txt");
						out << std::left << "Error!!! detM0 = 0, the matrix is not solved \r\n";
						out.close();
						Kramer4x4(det);

					}
					else {
						for (int i = 0; i <= 3; i++) {
							boot[i][0][2] = boot[i][4][0];
						}
						det++;
						detAm[1] = Kramer4x4(det);
						for (int i = 0; i <= 3; i++) {
							boot[i][1][2] = boot[i][4][0];
						}
						for (int i = 0; i <= 3; i++) {
							boot[i][0][2] = boot[i][0][0];
						}
						det++;
						detAm[2] = Kramer4x4(det);
						for (int i = 0; i <= 3; i++) {
							boot[i][2][2] = boot[i][4][0];
						}
						for (int i = 0; i <= 3; i++) {
							boot[i][1][2] = boot[i][1][0];
						}
						det++;
						detAm[3] = Kramer4x4(det);

						for (int i = 0; i <= 3; i++) {
							boot[i][2][2] = boot[i][2][0];
						}
						for (int i = 0; i <= 3; i++) {
							boot[i][3][2] = boot[i][4][0];
						}
						det++;
						detAm[4] = Kramer4x4(det);
						fstream fs;
						fs.open("BootString.txt", fstream::in | fstream::out | fstream::app);
						fs.precision(3);
						fs << "X1=detM1/detM0 = " << detAm[1] / detAm[0] << endl;
						fs << "X2=detM2/detM0 = " << detAm[2] / detAm[0] << endl;
						fs << "X3=detM3/detM0 = " << detAm[3] / detAm[0] << endl;
						fs << "X4=detM4/detM0 = " << detAm[4] / detAm[0] << endl;
						fs.close();
					}
					
					break;
				}
			}
			else if (radioButton2->Checked) { // матричний метод
				float x[3];
				switch (rows) {

				case 2: {
					out.precision(3);
					detA = boot[0][0][0] * boot[1][1][0] - boot[0][1][0] * boot[1][0][0];
					if (detA == 0) {
						out << std::left << "Error!!! detA = 0, the matrix is not solved \r\n";
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << "|\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << " - " << boot[0][1][0] << "*" << boot[1][0][0] << " = " << detA << "\r\n\r\n";

					}
					else {
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << setw(1) << "|\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << " - " << boot[0][1][0] << "*" << boot[1][0][0] << " = " << detA << "\r\n\r\n";


						out << std::left << "detM11 = " << boot[1][1][0] << "\r\n";
						out << std::left << "detM12 = " << -boot[1][0][0] << "\r\n";
						out << std::left << "detM21 = " << -boot[0][1][0] << "\r\n";
						out << std::left << "detM22 = " << boot[0][0][0] << "\r\n\r\n";

						out << std::left << "A^-1*(1/detA) = " << setw(6) << "|" << setw(6) << boot[1][1][0] << setw(6) << -boot[0][1][0] << setw(1) << "| * |      " << setw(6) << boot[0][2][0] << "|\r\n";
						out << std::left << "                            " << setw(6) << "|" << setw(6) << -boot[1][0][0] << setw(6) << boot[0][0][0] << setw(1) << "|    |      " << setw(6) << boot[1][2][0] << "|  *  1/" << detA << "  = \r\n\r\n";

						x[0] = (boot[1][1][0] * boot[0][2][0] - boot[0][1][0] * boot[1][2][0]) * (1 / detA);
						x[1] = (-boot[1][0][0] * boot[0][2][0] + boot[0][0][0] * boot[1][2][0]) * (1 / detA);
						out << std::left << "= |" << setw(9) << boot[1][1][0] * boot[0][2][0] * (1 / detA) << setw(6) << " + " << setw(9) << -boot[0][1][0] * boot[1][2][0] * (1 / detA) << "|    |  " << setw(9) << x[0] << "  |\r\n";
						out << std::left << "   |" << setw(9) << -boot[1][0][0] * boot[0][2][0] * (1 / detA) << setw(6) << " + " << setw(9) << boot[0][0][0] * boot[1][2][0] * (1 / detA) << "| = |  " << setw(9) << x[1] << "  |\r\n\r\n";

						out << std::left << "X1= " << x[0] << "\r\n";
						out << std::left << "X2= " << x[1];
					}
					out.close();
					break; }
				case 3: {
					
					float detM[3][3];
					for (int i = 0; i < 3; i++) {
						for (int f = 0; f < 3; f++) {
							boot[i][f][1] = boot[i][f][0];

						}
					}
					detA = boot[0][0][0] * boot[1][1][0] * boot[2][2][0] + boot[1][0][0] * boot[2][1][0] * boot[0][2][0] + boot[0][1][0] * boot[1][2][0] * boot[2][0][0] - boot[0][2][00] * boot[1][1][0] * boot[2][0][0] - boot[1][0][0] * boot[0][1][0] * boot[2][2][0] - boot[2][1][0] * boot[1][2][0] * boot[0][0][0];

					if (detA == 0) {

						out << std::left << "Error!!! detA = 0, the matrix is not solved \r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << setw(6) << boot[0][2][0] << setw(1) << "|\r\n";
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(6) << boot[1][2][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << "*" << boot[2][2][0] << " + " << boot[1][0][0] << "*"
							<< boot[2][1][0] << "*" << boot[0][2][0] << " + " << boot[0][1][0] << "*" << boot[1][2][0] << "*" << boot[2][0][0] << " - " << boot[0][2][0] << "*" << boot[1][1][0] << "*" << boot[2][0][0] << " - " << boot[1][0][0] << "*" << boot[0][1][0] << "*" << boot[2][2][0] << " - " << boot[2][1][0] << "*" << boot[1][2][0] << "*" << boot[0][0][0] << " = " <<
							detA << "\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[2][0][0] << setw(6) << boot[2][1][0] << setw(6) << boot[2][2][0] << "|\r\n\r\n";

					}
					else {
						out.close();
						float detA = Kramer3x3(0, "A");
						detM[0][0] = boot[1][1][0] * boot[2][2][0] - boot[1][2][0] * boot[2][1][0];
						detM[0][1] = -(boot[1][0][0] * boot[2][2][0] - boot[1][2][0] * boot[2][0][0]);
						detM[0][2] = boot[1][0][0] * boot[2][1][0] - boot[1][1][0] * boot[2][0][0];
						detM[1][0] = -(boot[0][1][0] * boot[2][2][0] - boot[0][2][0] * boot[2][1][0]);
						detM[1][1] = boot[0][0][0] * boot[2][2][0] - boot[0][2][0] * boot[2][0][0];
						detM[1][2] = -(boot[0][0][0] * boot[2][1][0] - boot[0][1][0] * boot[2][0][0]);
						detM[2][0] = boot[0][1][0] * boot[1][2][0] - boot[0][2][0] * boot[1][1][0];
						detM[2][1] = -(boot[0][0][0] * boot[1][2][0] - boot[0][2][0] * boot[1][0][0]);
						detM[2][2] = boot[0][0][0] * boot[1][1][0] - boot[0][1][0] * boot[1][0][0];

						fstream fs;
						fs.open("BootString.txt", fstream::in | fstream::out | fstream::app);
						fs.precision(3);
						for (int i = 0; i < 3; i++) {
							for (int b = 0; b < 3; b++) {
								fs << "detM" << i + 1 << b + 1 << "= " << detM[i][b] << "\r\n";
							}
						}
						fs << std::left << "                             " << setw(6) << "|" << setw(6) << detM[0][0] << setw(6) << detM[1][0] << setw(6) << detM[2][0] << setw(1) << "|    |      " << setw(6) << boot[0][3][0] << "|\r\n";
						fs << std::left << "A^-1*(1/detA) = " << setw(6) << "|" << setw(6) << detM[0][1] << setw(6) << detM[1][1] << setw(6) << detM[2][1] << setw(1) << "| * |      " << setw(6) << boot[1][3][0] << "|  *  1/" << detA << "  = \r\n";
						fs << std::left << "                             "  << setw(6) << "|" << setw(6) << detM[0][2] << setw(6) << detM[1][2] << setw(6) << detM[2][2] << setw(1) << "|    |      " << setw(6) << boot[2][3][0] << "|\r\n\r\n";
						x[0] = (detM[0][0] * boot[0][3][0] + detM[1][0] * boot[1][3][0] + detM[2][0] * boot[2][3][0]) * (1 / detA);
						x[1] = (detM[0][1] * boot[0][3][0] + detM[1][1] * boot[1][3][0] + detM[2][1] * boot[2][3][0]) * (1 / detA);
						x[2] = (detM[0][2] * boot[0][3][0] + detM[1][2] * boot[1][3][0] + detM[2][2] * boot[2][3][0]) * (1 / detA);

						fs << std::left << "   |" << setw(9) << detM[0][0] * boot[0][3][0] * (1 / detA) << setw(6) << " + " << setw(9) << detM[1][0] * boot[1][3][0] * (1 / detA) << " + " << setw(9) << detM[2][0] * boot[2][3][0] * (1 / detA) << "|  |  " << setw(9) << x[0] << "  |\r\n";
						fs << std::left << "= |" << setw(9) << detM[0][1] * boot[0][3][0] * (1 / detA) << setw(6) << " + " << setw(9) << detM[1][1] * boot[1][3][0] * (1 / detA) << " + " << setw(9) << detM[2][1] * boot[2][3][0] * (1 / detA) << "|  =  |  " << setw(9) << x[1] << "  |\r\n";
						fs << std::left << "   |" << setw(9) << detM[0][2] * boot[0][3][0] * (1 / detA) << setw(6) << " + " << setw(9) << detM[1][2] * boot[1][3][0] * (1 / detA) << " + " << setw(9) << detM[2][2] * boot[2][3][0] * (1 / detA) << "|  |  " << setw(9) << x[2] << "  |\r\n\r\n";
						fs << std::left << "X1= " << x[0] << "\r\n";
						fs << std::left << "X2= " << x[1] << "\r\n";
						fs << std::left << "X3= " << x[2] << "\r\n";
						fs.close();
					}
					break;
				}
				case 4: {
					out.close();
					float detA;
					float detM[5][5];
					for (int i = 0; i <= 3; i++) {
						for (int f = 0; f <= 3; f++) {
							boot[i][f][2] = boot[i][f][0];

						}
					}
					detA = Kramer4x4(0);
					if (detA == 0) {
						ofstream out;
						out.open("BootString.txt");
						out << std::left << "Error!!! detM0 = 0, the matrix is not solved \r\n";
						out.close();
						Kramer4x4(0);
					}
					else {
						for (int i = 1; i <= 3; i++) {
							for (int f = 1; f <= 3; f++) {
								boot[i - 1][f - 1][1] = boot[i][f][2];

							}
						}
						int det = 1;
						detM[0][0] = Kramer3x3(det, "C1");
						det++;
						for (int i = 1; i <= 3; i++) {
							boot[i - 1][0][1] = boot[i][0][2];

						}
						detM[0][1] = -Kramer3x3(det, "C1");
						det++;
						for (int i = 1; i <= 3; i++) {
							boot[i - 1][1][1] = boot[i][1][2];
						}

						detM[0][2] = Kramer3x3(det, "C1");
						det++;
						for (int i = 1; i < Colums; i++) {
							boot[i - 1][2][1] = boot[i][2][2];

						}
						detM[0][3] = -Kramer3x3(det, "C1");

						for (int i = 1; i <= 3; i++) {
							for (int f = 1; f <= 3; f++) {
								boot[i - 1][f - 1][1] = boot[i][f][2];

							}
						}
						for (int i = 0; i < 3; i++) {
							boot[0][i][1] = boot[0][i + 1][0];
						}
						det = 1;
						detM[1][0] = -Kramer3x3(det, "C2");
						det++;
						for (int i = 1; i <= 3; i++) {
							boot[i - 1][0][1] = boot[i][0][2];

						}
						boot[0][0][1] = boot[0][0][0];
						detM[1][1] = Kramer3x3(det, "C2");
						det++;
						for (int i = 1; i <= 3; i++) {
							boot[i - 1][1][1] = boot[i][1][2];
						}
						boot[0][1][1] = boot[0][1][0];
						detM[1][2] = -Kramer3x3(det, "C2");
						det++;
						for (int i = 1; i < Colums; i++) {
							boot[i - 1][2][1] = boot[i][2][2];

						}
						boot[0][2][1] = boot[0][2][0];
						detM[1][3] = Kramer3x3(det, "C2");

						for (int i = 0; i < 3; i++) {
							for (int f = 1; f <= 3; f++) {
								boot[i][f - 1][1] = boot[i][f][2];

							}
						}
						for (int i = 0; i < 3; i++) {
							boot[2][i][1] = boot[3][i + 1][0];
						}
						det = 1;
						detM[2][0] = Kramer3x3(det, "C3");
						det++;
						for (int i = 0; i < 3; i++) {
							boot[i][0][1] = boot[i][0][2];

						}
						boot[2][0][1] = boot[3][0][0];
						detM[2][1] = -Kramer3x3(det, "C3");
						det++;
						for (int i = 0; i < 3; i++) {
							boot[i][1][1] = boot[i][1][2];
						}
						boot[2][1][1] = boot[3][1][0];
						detM[2][2] = Kramer3x3(det, "C3");
						det++;
						for (int i = 0; i < 4; i++) {
							boot[i][2][1] = boot[i][2][2];

						}
						boot[2][2][1] = boot[3][2][0];
						detM[2][3] = -Kramer3x3(det, "C3");


						for (int i = 0; i < 3; i++) {
							for (int f = 1; f <= 3; f++) {
								boot[i][f - 1][1] = boot[i][f][2];

							}
						}
						det = 1;
						detM[3][0] = -Kramer3x3(det, "C4");
						det++;
						for (int i = 0; i < 3; i++) {
							boot[i][0][1] = boot[i][0][2];

						}
						detM[3][1] = Kramer3x3(det, "C4");
						det++;
						for (int i = 0; i < 3; i++) {
							boot[i][1][1] = boot[i][1][2];
						}

						detM[3][2] = -Kramer3x3(det, "C4");
						det++;
						for (int i = 0; i < Colums; i++) {
							boot[i][2][1] = boot[i][2][2];

						}
						detM[3][3] = Kramer3x3(det, "C4");


						fstream fs;
						fs.precision(3);
						fs.open("BootString.txt", fstream::in | fstream::out | fstream::app);
						fs << std::left << "                             "  << setw(6) << "|" << setw(6) << detM[0][0] << setw(6) << detM[1][0] << setw(6) << detM[2][0] << setw(6) << detM[3][0] << setw(1) << "|    |      " << setw(6) << boot[0][4][0] << "|\r\n";
						fs << std::left << "A^-1*(1/detA) = " << setw(6) << "|" << setw(6) << detM[0][1] << setw(6) << detM[1][1] << setw(6) << detM[2][1] << setw(6) << detM[3][1] << setw(1) << "| * |      " << setw(6) << boot[1][4][0] << "|  *  1/" << detA << "  = \r\n";
						fs << std::left << "                             "  << setw(6) << "|" << setw(6) << detM[0][2] << setw(6) << detM[1][2] << setw(6) << detM[2][2] << setw(6) << detM[3][2] << setw(1) << "|    |      " << setw(6) << boot[2][4][0] << "|\r\n";
						fs << std::left << "                             "  << setw(6) << "|" << setw(6) << detM[0][3] << setw(6) << detM[1][3] << setw(6) << detM[2][3] << setw(6) << detM[3][3] << setw(1) << "|    |      " << setw(6) << boot[2][4][0] << "|\r\n\r\n";
						x[0] = (detM[0][0] * boot[0][4][0] + detM[1][0] * boot[1][4][0] + detM[2][0] * boot[2][4][0] + detM[3][0] * boot[3][4][0]) * (1 / detA);
						x[1] = (detM[0][1] * boot[0][4][0] + detM[1][1] * boot[1][4][0] + detM[2][1] * boot[2][4][0] + detM[3][1] * boot[3][4][0]) * (1 / detA);
						x[2] = (detM[0][2] * boot[0][4][0] + detM[1][2] * boot[1][4][0] + detM[2][2] * boot[2][4][0] + detM[3][2] * boot[3][4][0]) * (1 / detA);
						x[3] = (detM[0][3] * boot[0][4][0] + detM[1][3] * boot[1][4][0] + detM[2][3] * boot[2][4][0] + detM[3][3] * boot[3][4][0]) * (1 / detA);

						fs << std::left << "   |" << setw(9) << detM[0][0] * boot[0][3][0] * (1 / detA) << setw(6) << " + " << setw(9) << detM[1][0] * boot[1][3][0] * (1 / detA) << " + " << setw(9) << detM[2][0] * boot[2][3][0] * (1 / detA) << " + " << setw(9) << detM[3][0] * boot[3][4][0] * (1 / detA) << "|      |  " << setw(9) << x[0] << "  |\r\n";
						fs << std::left << "= |" << setw(9) << detM[0][1] * boot[0][3][0] * (1 / detA) << setw(6) << " + " << setw(9) << detM[1][1] * boot[1][3][0] * (1 / detA) << " + " << setw(9) << detM[2][1] * boot[2][3][0] * (1 / detA) << " + " << setw(9) << detM[3][1] * boot[3][4][0] * (1 / detA) << "|  =  |  " << setw(9) << x[1] << "  |\r\n";
						fs << std::left << "   |" << setw(9) << detM[0][2] * boot[0][3][0] * (1 / detA) << setw(6) << " + " << setw(9) << detM[1][2] * boot[1][3][0] * (1 / detA) << " + " << setw(9) << detM[2][2] * boot[2][3][0] * (1 / detA) << " + " << setw(9) << detM[3][2] * boot[3][4][0] * (1 / detA) << "|      |  " << setw(9) << x[2] << "  |\r\n";
						fs << std::left << "   |" << setw(9) << detM[0][3] * boot[0][3][0] * (1 / detA) << setw(6) << " + " << setw(9) << detM[1][3] * boot[1][3][0] * (1 / detA) << " + " << setw(9) << detM[2][3] * boot[2][3][0] * (1 / detA) << " + " << setw(9) << detM[3][3] * boot[3][4][0] * (1 / detA) << "|      |  " << setw(9) << x[3] << "  |\r\n\r\n";
						fs << std::left << "X1= " << x[0] << "\r\n";
						fs << std::left << "X2= " << x[1] << "\r\n";
						fs << std::left << "X3= " << x[2] << "\r\n";
						fs << std::left << "X4= " << x[3] << "\r\n";
						fs.close();
					}
					break;
				}
				}
			
			}
			else if (radioButton3->Checked) { // Метод Гауса
		

			
				switch (rows) {

				case 2: {
					out.precision(3);

					detA = boot[0][0][0] * boot[1][1][0] - boot[0][1][0] * boot[1][0][0];
					if (detA == 0) {
						out << std::left << "Error!!! detA = 0, the matrix is not solved \r\n";
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << "|\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << " - " << boot[0][1][0] << "*" << boot[1][0][0] << " = " << detA << "\r\n\r\n";

					}

					else {

						bool flag[9];
						flag[0] = 1;
						flag[1] = 1;



						out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << "| " << setw(9) << boot[0][2][0] << "|\r\n";
						out << std::left << " |  " << setw(9) << boot[1][0][0] << setw(9) << boot[1][1][0] << "| " << setw(9) << boot[1][2][0] << "|\r\n\r\n";
						float a = -boot[1][0][0] / boot[0][0][0];
						if (boot[0][0][0] == 0) {
							flag[0] = 0;
						}
						else {
							out << "Rows 2 add: " << a << " * Rows 1.\r\n";
							for (int i = 0; i < 4; i++) {
								boot[1][i][0] = (a * boot[0][i][0]) + boot[1][i][0];
							}
							out << std::left << " |  " << setw(14) << boot[0][0][0] << setw(14) << boot[0][1][0] << "| " << setw(14) << boot[0][2][0] << "|\r\n";
							out << std::left << " |  " << setw(14) << "0" << setw(14) << boot[1][1][0] << "| " << setw(14) << boot[1][2][0] << "|\r\n\r\n";
						}
						a = -boot[0][1][0] / boot[1][1][0];
						if (boot[1][1][0] == 0) {
							flag[1] = 0;
						}
						else {
							out << "Rows 1 add: " << a << " * Rows 2.\r\n";
							for (int i = 0; i < 4; i++) {
								boot[0][i][0] = (a * boot[1][i][0]) + boot[0][i][0];
							}
							out << std::left << " |  " << setw(14) << boot[0][0][0] << setw(14) << "0" << "| " << setw(14) << boot[0][2][0] << "|\r\n";
							out << std::left << " |  " << setw(14) << "0" << setw(14) << boot[1][1][0] << "| " << setw(14) << boot[1][2][0] << "|\r\n\r\n";
						}
						if (flag[0] == 0 && flag[1] == 0) {
							out << "X1= " << boot[1][2][0] / boot[1][0][0] << "\r\n";
							out << "X2= " << boot[0][2][0] / boot[0][1][0] << "\r\n";
						}
						else {
							out << "X1= " << boot[0][2][0] / boot[0][0][0] << "\r\n";
							out << "X2= " << boot[1][2][0] / boot[1][1][0] << "\r\n";
						}


					}
					break;
				}
				case 3: {
					out.precision(3);
					int flag1 = 1;
					detA = boot[0][0][0] * boot[1][1][0] * boot[2][2][0] + boot[1][0][0] * boot[2][1][0] * boot[0][2][0] + boot[0][1][0] * boot[1][2][0] * boot[2][0][0] - boot[0][2][00] * boot[1][1][0] * boot[2][0][0] - boot[1][0][0] * boot[0][1][0] * boot[2][2][0] - boot[2][1][0] * boot[1][2][0] * boot[0][0][0];

					if (detA == 0) {
						flag1 = 0;
						out << std::left << "Error!!! det = 0, the matrix is not solved \r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[0][0][0] << setw(6) << boot[0][1][0] << setw(6) << boot[0][2][0] << setw(1) << "|\r\n";
						out << std::left << "detA = " << setw(6) << "|" << setw(6) << boot[1][0][0] << setw(6) << boot[1][1][0] << setw(6) << boot[1][2][0] << setw(1) << "|  = " << boot[0][0][0] << "*" << boot[1][1][0] << "*" << boot[2][2][0] << " + " << boot[1][0][0] << "*"
							<< boot[2][1][0] << "*" << boot[0][2][0] << " + " << boot[0][1][0] << "*" << boot[1][2][0] << "*" << boot[2][0][0] << " - " << boot[0][2][0] << "*" << boot[1][1][0] << "*" << boot[2][0][0] << " - " << boot[1][0][0] << "*" << boot[0][1][0] << "*" << boot[2][2][0] << " - " << boot[2][1][0] << "*" << boot[1][2][0] << "*" << boot[0][0][0] << " = " <<
							detA << "\r\n";
						out << std::left << "            " << setw(6) << "|" << setw(6) << boot[2][0][0] << setw(6) << boot[2][1][0] << setw(6) << boot[2][2][0] << "|\r\n\r\n";


					}
					if ((boot[0][0][0] == 0 || boot[2][2][0] == 0) && flag1 == 1) {
						out << std::left << "change the first and third lines, so that the zeros are in the corners \r\n";
						for (int i = 0; i < 4; i++) {
							boot[0][i][1] = boot[0][i][0];
							boot[2][i][1] = boot[2][i][0];
						}
						for (int i = 0; i < 4; i++) {
							boot[2][i][0] = boot[0][i][1];
							boot[0][i][0] = boot[2][i][1];
						}
					}

					if (flag1 == 1) {
						float a[3];
						out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << setw(9) << boot[0][2][0] << "| " << setw(9) << boot[0][3][0] << "|\r\n";
						out << std::left << " |  " << setw(9) << boot[1][0][0] << setw(9) << boot[1][1][0] << setw(9) << boot[1][2][0] << "| " << setw(9) << boot[1][3][0] << "|\r\n";
						out << std::left << " |  " << setw(9) << boot[2][0][0] << setw(9) << boot[2][1][0] << setw(9) << boot[2][2][0] << "| " << setw(9) << boot[2][3][0] << "|\r\n\r\n";
						a[0] = -boot[1][0][0] / boot[0][0][0];
						a[1] = -boot[2][0][0] / boot[0][0][0];

						if (boot[0][0][0] == 0) {
						}
						else {
							out << "Rows 2 add: " << a[0] << " * Rows 1.\r\n";
							out << "Rows 3 add: " << a[1] << " * Rows 1.\r\n";

							for (int i = 0; i <= 4; i++) {
								boot[1][i][0] = (a[0] * boot[0][i][0]) + boot[1][i][0];
							}
							for (int i = 0; i <= 4; i++) {
								boot[2][i][0] = (a[1] * boot[0][i][0]) + boot[2][i][0];
							}

							a[2] = -boot[2][1][0] / boot[1][1][0];
							if (boot[1][1][0] == 0) {
								a[2] = 0;
							}
							out << "Rows 3 add: " << a[2] << " * Rows 2.\r\n";

							for (int i = 0; i <= 4; i++) {
								boot[2][i][0] = (a[2] * boot[1][i][0]) + boot[2][i][0];
							}
							out << std::left << " |  " << setw(14) << boot[0][0][0] << setw(14) << boot[0][1][0] << setw(14) << boot[0][2][0] << "| " << setw(14) << boot[0][3][0] << "|\r\n";
							out << std::left << " |  " << setw(14) << "0" << setw(14) << boot[1][1][0] << setw(14) << boot[1][2][0] << "| " << setw(14) << boot[1][3][0] << "|\r\n";
							out << std::left << " |  " << setw(14) << "0" << setw(14) << "0" << setw(14) << boot[2][2][0] << "| " << setw(14) << boot[2][3][0] << "|\r\n\r\n";
						}

						a[0] = -boot[0][2][0] / boot[2][2][0];
						a[1] = -boot[1][2][0] / boot[2][2][0];


						if (boot[2][2][0] == 0) {
						}
						else {
							out << "Rows 1 add: " << a[0] << " * Rows 3.\r\n";
							out << "Rows 2 add: " << a[1] << " * Rows 3.\r\n";

							for (int i = 0; i <= 4; i++) {
								boot[0][i][0] = (a[0] * boot[2][i][0]) + boot[0][i][0];
							}
							for (int i = 0; i <= 4; i++) {
								boot[1][i][0] = (a[1] * boot[2][i][0]) + boot[1][i][0];
							}
							a[2] = -boot[0][1][0] / boot[1][1][0];
							if (boot[1][1][0] == 0) {
								a[2] = 0;
							}
							out << "Rows 1 add: " << a[2] << " * Rows 2.\r\n";
							for (int i = 0; i <= 4; i++) {
								boot[0][i][0] = (a[2] * boot[1][i][0]) + boot[0][i][0];
							}

							out << std::left << " |  " << setw(14) << boot[0][0][0] << setw(14) << "0" << setw(14) << "0" << "| " << setw(14) << boot[0][3][0] << "|\r\n";
							out << std::left << " |  " << setw(14) << "0" << setw(14) << boot[1][1][0] << setw(14) << "0" << "| " << setw(14) << boot[1][3][0] << "|\r\n";
							out << std::left << " |  " << setw(14) << "0" << setw(14) << "0" << setw(14) << boot[2][2][0] << "| " << setw(14) << boot[2][3][0] << "|\r\n\r\n";
						}
						if ((boot[0][3][0] / boot[0][0][0]) > 0.001 || -(boot[0][3][0] / boot[0][0][0]) > 0.001) {
							out << "X1= " << boot[0][3][0] / boot[0][0][0] << "\r\n";
						}
						else {
							out << "X1= 0" << "\r\n";
						}
						if ((boot[1][3][0] / boot[1][1][0]) > 0.001 || -(boot[1][3][0] / boot[1][1][0]) > 0.001) {
							out << "X2= " << boot[1][3][0] / boot[1][1][0] << "\r\n";
						}
						else {
							out << "X2= 0" << "\r\n";
						}
						if ((boot[2][3][0] / boot[2][2][0]) > 0.001 || -(boot[2][3][0] / boot[2][2][0]) > 0.001) {
							out << "X3= " << boot[2][3][0] / boot[2][2][0] << "\r\n";
						}
						else {
							out << "X3= 0" << "\r\n";
						}
						break;
					}

				}
				case 4: {
					out.precision(3);
					for (int i = 0; i <= 3; i++) {
						for (int f = 0; f <= 3; f++) {
							boot[i][f][2] = boot[i][f][0];

						}
					}
					detA = Kramer4x4(0);
					if (detA == 0) {
						ofstream out;
						out.open("BootString.txt");
						out << std::left << "Error!!! detM0 = 0, the matrix is not solved \r\n";
						out.close();
						Kramer4x4(0);
					}
					else {
						if (boot[0][0][0] == 0 || boot[3][3][0] == 0) {
							out << std::left << "change the first and third lines, so that the zeros are in the corners \r\n";
							for (int i = 0; i <= 4; i++) {
								boot[0][i][1] = boot[0][i][0];
								boot[3][i][1] = boot[3][i][0];
							}
							for (int i = 0; i <= 4; i++) {
								boot[3][i][0] = boot[0][i][1];
								boot[0][i][0] = boot[3][i][1];
							}
						}
						if (boot[1][1][0] == 0 || boot[2][2][0] == 0) {
							out << std::left << "change the first and third lines, so that the zeros are in the corners \r\n";
							for (int i = 0; i <= 4; i++) {
								boot[0][i][1] = boot[0][i][0];
								boot[1][i][1] = boot[1][i][0];
							}
							for (int i = 0; i <= 4; i++) {
								boot[1][i][0] = boot[0][i][1];
								boot[0][i][0] = boot[1][i][1];
							}
						}

						float a[8];
						out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << setw(9) << boot[0][2][0] << setw(9) << boot[0][3][0] << "| " << setw(9) << boot[0][4][0] << "|\r\n";
						out << std::left << " |  " << setw(9) << boot[1][0][0] << setw(9) << boot[1][1][0] << setw(9) << boot[1][2][0] << setw(9) << boot[1][3][0] << "| " << setw(9) << boot[1][4][0] << "|\r\n";
						out << std::left << " |  " << setw(9) << boot[2][0][0] << setw(9) << boot[2][1][0] << setw(9) << boot[2][2][0] << setw(9) << boot[2][3][0] << "| " << setw(9) << boot[2][4][0] << "|\r\n";
						out << std::left << " |  " << setw(9) << boot[3][0][0] << setw(9) << boot[3][1][0] << setw(9) << boot[3][2][0] << setw(9) << boot[3][3][0] << "| " << setw(9) << boot[3][4][0] << "|\r\n\r\n";

						
	
							a[0] = -boot[1][0][0] / boot[0][0][0];
							a[1] = -boot[2][0][0] / boot[0][0][0];
							a[2] = -boot[3][0][0] / boot[0][0][0];
							if (boot[0][0][0] == 0) {
								a[0] = 0;
								a[1] = 0;
								a[2] = 0;
							}
							out << "Rows 2 add: " << a[0] << " * Rows 1.\r\n";
							out << "Rows 3 add: " << a[1] << " * Rows 1.\r\n";
							out << "Rows 4 add: " << a[2] << " * Rows 1.\r\n";

							for (int i = 0; i <= 5; i++) {
								boot[1][i][0] = (a[0] * boot[0][i][0]) + boot[1][i][0];
							}
							for (int i = 0; i <= 5; i++) {
								boot[2][i][0] = (a[1] * boot[0][i][0]) + boot[2][i][0];
							}
							for (int i = 0; i <= 5; i++) {
								boot[3][i][0] = (a[2] * boot[0][i][0]) + boot[3][i][0];
							}
							out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << setw(9) << boot[0][2][0] << setw(9) << boot[0][3][0] << "| " << setw(9) << boot[0][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[1][1][0] << setw(9) << boot[1][2][0] << setw(9) << boot[1][3][0] << "| " << setw(9) << boot[1][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[2][1][0] << setw(9) << boot[2][2][0] << setw(9) << boot[2][3][0] << "| " << setw(9) << boot[2][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[3][1][0] << setw(9) << boot[3][2][0] << setw(9) << boot[3][3][0] << "| " << setw(9) << boot[3][4][0] << "|\r\n\r\n";

							a[3] = -boot[3][1][0] / boot[2][1][0];
							a[4] = -boot[2][1][0] / boot[1][1][0];
							
							if (boot[2][1][0] == 0) {
								a[3] = 0;
							}
							if (boot[1][1][0] == 0) {
								a[4] = 0;
							}
							out << "Rows 4 add: " << a[3] << " * Rows 2.\r\n";
							for (int i = 0; i <= 4; i++) {
								boot[3][i][0] = (a[3] * boot[2][i][0]) + boot[3][i][0];
							}
							out << "Rows 3 add: " << a[4] << " * Rows 2.\r\n";
							for (int i = 0; i <= 4; i++) {
								boot[2][i][0] = (a[4] * boot[1][i][0]) + boot[2][i][0];
							}
							out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << setw(9) << boot[0][2][0] << setw(9) << boot[0][3][0] << "| " << setw(9) << boot[0][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[1][1][0] << setw(9) << boot[1][2][0] << setw(9) << boot[1][3][0] << "| " << setw(9) << boot[1][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[2][2][0] << setw(9) << boot[2][3][0] << "| " << setw(9) << boot[2][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[3][2][0] << setw(9) << boot[3][3][0] << "| " << setw(9) << boot[3][4][0] << "|\r\n\r\n";

							a[5] = -boot[3][2][0] / boot[2][2][0];
							if (boot[2][2][0] == 0) {
								a[5] = 0;
							}
							out << "Rows 4 add: " << a[5] << " * Rows 3.\r\n";
							for (int i = 0; i <= 4; i++) {
								boot[3][i][0] = (a[5] * boot[2][i][0]) + boot[3][i][0];
							}

							out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << setw(9) << boot[0][2][0] << setw(9) << boot[0][3][0] << "| " << setw(9) << boot[0][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[1][1][0] << setw(9) << boot[1][2][0] << setw(9) << boot[1][3][0] << "| " << setw(9) << boot[1][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[2][2][0] << setw(9) << boot[2][3][0] << "| " << setw(9) << boot[2][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[3][3][0] << "| " << setw(9) << boot[3][4][0] << "|\r\n\r\n";
							
						
						
						
							a[0] = -boot[0][3][0] / boot[3][3][0];
							a[1] = -boot[1][3][0] / boot[3][3][0];
							a[2] = -boot[2][3][0] / boot[3][3][0];
							if (boot[3][3][0] == 0) {
								a[0] = 0;
								a[1] = 0;
								a[2] = 0;
							}
							out << "Rows 1 add: " << a[0] << " * Rows 4.\r\n";
							out << "Rows 2 add: " << a[1] << " * Rows 4.\r\n";
							out << "Rows 3 add: " << a[2] << " * Rows 4.\r\n";

							for (int i = 0; i <= 4; i++) {
								boot[0][i][0] = (a[0] * boot[3][i][0]) + boot[0][i][0];
							}
							for (int i = 0; i <= 4; i++) {
								boot[1][i][0] = (a[1] * boot[3][i][0]) + boot[1][i][0];
							}
							for (int i = 0; i <= 4; i++) {
								boot[2][i][0] = (a[2] * boot[3][i][0]) + boot[2][i][0];
							}
							out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << setw(9) << boot[0][2][0] << setw(9) << "0" << "| " << setw(9) << boot[0][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[1][1][0] << setw(9) << boot[1][2][0] << setw(9) << "0" << "| " << setw(9) << boot[1][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[2][2][0] << setw(9) << "0" << "| " << setw(9) << boot[2][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[3][3][0] << "| " << setw(9) << boot[3][4][0] << "|\r\n\r\n";


							a[3] = -boot[0][2][0] / boot[2][2][0];
							a[4] = -boot[1][2][0] / boot[2][2][0];

							if (boot[2][2][0] == 0) {
								a[3] = 0;
								a[4] = 0;
							}
							
							out << "Rows 1 add: " << a[3] << " * Rows 3.\r\n";
							for (int i = 0; i <= 4; i++) {
								boot[0][i][0] = (a[3] * boot[2][i][0]) + boot[0][i][0];
							}
							out << "Rows 2 add: " << a[4] << " * Rows 3.\r\n";
							for (int i = 0; i <= 4; i++) {
								boot[1][i][0] = (a[4] * boot[2][i][0]) + boot[1][i][0];
							}
							out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << boot[0][1][0] << setw(9) << "0" << setw(9) << "0" << "| " << setw(9) << boot[0][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[1][1][0] << setw(9) << "0" << setw(9) << "0" << "| " << setw(9) << boot[1][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[2][2][0] << setw(9) << "0" << "| " << setw(9) << boot[2][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[3][3][0] << "| " << setw(9) << boot[3][4][0] << "|\r\n\r\n";

							a[5] = -boot[0][1][0] / boot[1][1][0];
							if (boot[1][1][0] == 0) {
								a[5] = 0;
								
							}
							out << "Rows 1 add: " << a[5] << " * Rows 2.\r\n";
							for (int i = 0; i <= 4; i++) {
								boot[0][i][0] = (a[5] * boot[1][i][0]) + boot[0][i][0];
							}
							out << std::left << " |  " << setw(9) << boot[0][0][0] << setw(9) << "0" << setw(9) << "0" << setw(9) << "0" << "| " << setw(9) << boot[0][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << boot[1][1][0] << setw(9) << "0" << setw(9) << "0" << "| " << setw(9) << boot[1][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[2][2][0] << setw(9) << "0" << "| " << setw(9) << boot[2][4][0] << "|\r\n";
							out << std::left << " |  " << setw(9) << "0" << setw(9) << "0" << setw(9) << "0" << setw(9) << boot[3][3][0] << "| " << setw(9) << boot[3][4][0] << "|\r\n\r\n";

						

						if ((boot[0][4][0] / boot[0][0][0]) > 0.001 || -(boot[0][4][0] / boot[0][0][0]) > 0.001) {
							out << "X1= " << boot[0][4][0] / boot[0][0][0] << "\r\n";
						}
						else {
							out << "X1= 0" << "\r\n";
						}
						if ((boot[1][4][0] / boot[1][1][0]) > 0.001 || -(boot[1][4][0] / boot[1][1][0]) > 0.001) {
							out << "X2= " << boot[1][4][0] / boot[1][1][0] << "\r\n";
						}
						else {
							out << "X2= 0" << "\r\n";
						}
						if ((boot[2][4][0] / boot[2][2][0]) > 0.001 || -(boot[2][4][0] / boot[2][2][0]) > 0.001) {
							out << "X3= " << boot[2][4][0] / boot[2][2][0] << "\r\n";
						}
						else {
							out << "X3= 0" << "\r\n";
						}
						if ((boot[3][4][0] / boot[3][3][0]) > 0.001 || -(boot[3][4][0] / boot[3][3][0]) > 0.001) {
							out << "X4= " << boot[3][4][0] / boot[3][3][0] << "\r\n";
						}
						else {
							out << "X4= 0" << "\r\n";
						}
					}
					
				}
				break;
				}
			
			}
			out.close();
			// Виведення в текстове вікно
		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("BootString.txt");
		System::String^ text = sr->ReadToEnd();
		displayText->Text = text;
		sr->Close();

	
		

	
	}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Метод очищення матриці
	for (int i = 0; i < rows; i++) {
		for (int f = 0; f <= Colums; f++) {
			dataGridView1->Rows[i]->Cells[f]->Value = "";

		}
	}
}
private: System::Void displayText_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		e->Handled = true; // Заборона дрокувати символи
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Запис з файлу
	
	if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ fileName = openFileDialog1->FileName;
		std::string vsSt = "";
		for (int i = 0; i < fileName->Length; i++) {
			vsSt += (char)fileName[i];
		}
		const char* stt = vsSt.c_str();
		std::string a, r;
		
		fstream fs;
		fs.open(stt, fstream::in | fstream::out | fstream::app);
		
		while (!fs.eof()) {
			fs>>a;
			r += a;
		}
		fs.close();
		for (int i = 0; i < 5; i++) {
			for (int c = 0; c < 5; c++) {
				boot[i][c][0] = 0;
			}
		}
		int i = 0;
		int b = 0;
		int q = 0;
		int z = 0;
		bool flag = 0;
		bool flag1 = 0;
		int con = int(r[0]) - 48;
		while (b < con) {
			if (int(r[i + 1]) == '-') {
				flag = 1;
			}

			if (int(r[i + 1]) == ',') {
				flag1 = 1;
				i++;
			}

			if (int(r[i + 1]) == '.') {
				if (flag == 1) {
					boot[b][q][0] = -boot[b][q][0];
					flag = 0;
				}

				if (flag1 == 1) {
					z++;
				}
				if (flag1 == 1) {
					boot[b][q][0] = boot[b][q][0] / pow(10, z+1);
					z = 0;
					flag1 = 0;
				}
					b++;
					i++;
					q = 0;
				
			}
			

			if (int(r[i+1]) == ';') {
				if (flag == 1) {
					boot[b][q][0] = -boot[b][q][0];
					flag = 0;
				}
				if (flag1 == 1) {
					z++;
				}
				if (flag1 == 1) {
					boot[b][q][0] = boot[b][q][0] / pow(10, z+1);
					z = 0;
					flag1 = 0;
				}
				q++;
				
			}
			else {
				if (boot[b][q][0] < 1) {
					boot[b][q][0] = int(r[i + 1]) - 48;
				}
				else {
					boot[b][q][0] = (boot[b][q][0] * 10) + int(r[i + 1]) - 48;
				}
				
			}
			
			i++;
		}
		numericUpDown1->Value = con;
		System::Void numericUpDown1_ValueChanged(System::Object ^ sender, System::EventArgs ^ e);
		// Виведення інформації в таблицю
		if (con == 2) {
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->Add(boot[0][0][0], boot[0][1][0], boot[0][2][0]);
			dataGridView1->Rows->Add(boot[1][0][0], boot[1][1][0], boot[1][2][0]);
		}
		if (con == 3) {
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->Add(boot[0][0][0], boot[0][1][0], boot[0][2][0], boot[0][3][0]);
			dataGridView1->Rows->Add(boot[1][0][0], boot[1][1][0], boot[1][2][0], boot[1][3][0]);
			dataGridView1->Rows->Add(boot[2][0][0], boot[2][1][0], boot[2][2][0], boot[2][3][0]);
		}
		if (con == 4) {
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->RemoveAt(0);
			dataGridView1->Rows->Add(boot[0][0][0], boot[0][1][0], boot[0][2][0], boot[0][3][0], boot[0][4][0]);
			dataGridView1->Rows->Add(boot[1][0][0], boot[1][1][0], boot[1][2][0], boot[1][3][0], boot[1][4][0]);
			dataGridView1->Rows->Add(boot[2][0][0], boot[2][1][0], boot[2][2][0], boot[2][3][0], boot[2][4][0]);
			dataGridView1->Rows->Add(boot[3][0][0], boot[3][1][0], boot[3][2][0], boot[3][3][0], boot[3][4][0]);
		}
		
			

		

	}
	

}

private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {

	
}

};

	
}