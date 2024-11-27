#pragma once
#include "..\lab3_stack\TCalc.h"
#include <msclr\marshal_cppstd.h>
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		  this->button1 = (gcnew System::Windows::Forms::Button());
		  this->textBox1 = (gcnew System::Windows::Forms::TextBox());
		  this->label1 = (gcnew System::Windows::Forms::Label());
		  this->SuspendLayout();
		  // 
		  // button1
		  // 
		  this->button1->Location = System::Drawing::Point(195, 125);
		  this->button1->Name = L"button1";
		  this->button1->Size = System::Drawing::Size(75, 23);
		  this->button1->TabIndex = 0;
		  this->button1->Text = L"button1";
		  this->button1->UseVisualStyleBackColor = true;
		  this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		  // 
		  // textBox1
		  // 
		  this->textBox1->Location = System::Drawing::Point(12, 125);
		  this->textBox1->Name = L"textBox1";
		  this->textBox1->Size = System::Drawing::Size(177, 22);
		  this->textBox1->TabIndex = 1;
		  // 
		  // label1
		  // 
		  this->label1->AutoSize = true;
		  this->label1->Location = System::Drawing::Point(13, 87);
		  this->label1->Name = L"label1";
		  this->label1->Size = System::Drawing::Size(44, 16);
		  this->label1->TabIndex = 2;
		  this->label1->Text = L"label1";
		  // 
		  // MyForm
		  // 
		  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		  this->ClientSize = System::Drawing::Size(282, 253);
		  this->Controls->Add(this->label1);
		  this->Controls->Add(this->textBox1);
		  this->Controls->Add(this->button1);
		  this->Name = L"MyForm";
		  this->Text = L"MyForm";
		  this->ResumeLayout(false);
		  this->PerformLayout(); 
		}
		
#pragma endregion
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	  TCalc calc;
	  calc.setInfix(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
	  calc.toPostfix();
	  double res = calc.calc();
	  this->label1->Text = msclr::interop::marshal_as<System::String^>(std::to_string(res));
	}
	
	};
}
