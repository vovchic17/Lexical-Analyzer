#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace System::Collections::Generic;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ closeButtonBt;
		Bitmap^ maximizeButtonBt;
		array<Point>^ maxIcon;
		Bitmap^ minimizeButtonBt;
		Graphics^ closeButtonGr;
		Graphics^ maximizeButtonGr;
		Graphics^ minimizeButtonGr;
		Boolean isDragging = false;
		Boolean isBusy = false;
		Point startPos, startCoord;
		ArrayList alphabet;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ autoLabel;
	private: System::Windows::Forms::Label^ manualLabel;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;

	public:
		MyForm(void)
		{
			InitializeComponent();
			closeButtonBt = gcnew Bitmap(30, 30);
			maximizeButtonBt = gcnew Bitmap(30, 30);
			minimizeButtonBt = gcnew Bitmap(30, 30);
			closeButtonGr = Graphics::FromImage(closeButtonBt);
			maximizeButtonGr = Graphics::FromImage(maximizeButtonBt);
			minimizeButtonGr = Graphics::FromImage(minimizeButtonBt);
			closeButtonGr->DrawLine(Pens::White, 8, 8, 22, 22);
			closeButtonGr->DrawLine(Pens::White, 8, 22, 22, 8);
			maxIcon = gcnew array<Point>{
				Point(18, 19),
					Point(18, 24),
					Point(7, 24),
					Point(7, 13),
					Point(13, 13),
					Point(13, 7),
					Point(24, 7),
					Point(24, 18),
					Point(18, 18),
					Point(18, 13),
					Point(14, 13),
			};
			maximizeButtonGr->DrawLines(Pens::White, maxIcon);
			minimizeButtonGr->DrawLine(Pens::White, 7, 15, 23, 15);
			closeButton->Image = closeButtonBt;
			maximizeButton->Image = maximizeButtonBt;
			minimizeButton->Image = minimizeButtonBt;
			alphabet.Add(L"a");
			alphabet.Add(L"b");
			alphabet.Add(L"c");
			dataGridView1->Columns->Add("", "");
			dataGridView1->Columns->Add("", "");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ closeButton;
	private: System::Windows::Forms::Label^ maximizeButton;
	private: System::Windows::Forms::Label^ minimizeButton;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->minimizeButton = (gcnew System::Windows::Forms::Label());
			this->maximizeButton = (gcnew System::Windows::Forms::Label());
			this->closeButton = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->autoLabel = (gcnew System::Windows::Forms::Label());
			this->manualLabel = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel1->Controls->Add(this->minimizeButton);
			this->panel1->Controls->Add(this->maximizeButton);
			this->panel1->Controls->Add(this->closeButton);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(400, 30);
			this->panel1->TabIndex = 0;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
			// 
			// minimizeButton
			// 
			this->minimizeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minimizeButton->Location = System::Drawing::Point(310, 0);
			this->minimizeButton->Margin = System::Windows::Forms::Padding(0);
			this->minimizeButton->Name = L"minimizeButton";
			this->minimizeButton->Size = System::Drawing::Size(30, 30);
			this->minimizeButton->TabIndex = 2;
			this->minimizeButton->Click += gcnew System::EventHandler(this, &MyForm::minimizeButton_Click);
			this->minimizeButton->MouseLeave += gcnew System::EventHandler(this, &MyForm::minimizeButton_MouseLeave);
			this->minimizeButton->MouseHover += gcnew System::EventHandler(this, &MyForm::minimizeButton_MouseHover);
			// 
			// maximizeButton
			// 
			this->maximizeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->maximizeButton->Location = System::Drawing::Point(340, 0);
			this->maximizeButton->Margin = System::Windows::Forms::Padding(0);
			this->maximizeButton->Name = L"maximizeButton";
			this->maximizeButton->Size = System::Drawing::Size(30, 30);
			this->maximizeButton->TabIndex = 1;
			this->maximizeButton->Click += gcnew System::EventHandler(this, &MyForm::maximizeButton_Click);
			this->maximizeButton->MouseLeave += gcnew System::EventHandler(this, &MyForm::maximizeButton_MouseLeave);
			this->maximizeButton->MouseHover += gcnew System::EventHandler(this, &MyForm::maximizeButton_MouseHover);
			// 
			// closeButton
			// 
			this->closeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->closeButton->Location = System::Drawing::Point(370, 0);
			this->closeButton->Margin = System::Windows::Forms::Padding(0);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(30, 30);
			this->closeButton->TabIndex = 1;
			this->closeButton->Click += gcnew System::EventHandler(this, &MyForm::closeButton_Click);
			this->closeButton->MouseLeave += gcnew System::EventHandler(this, &MyForm::closeButton_MouseLeave);
			this->closeButton->MouseHover += gcnew System::EventHandler(this, &MyForm::closeButton_MouseHover);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(213, 30);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Лексический анализатор";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseDown);
			this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseMove);
			this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->ForeColor = System::Drawing::Color::White;
			this->richTextBox1->HideSelection = false;
			this->richTextBox1->Location = System::Drawing::Point(30, 70);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(340, 360);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// autoLabel
			// 
			this->autoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->autoLabel->ForeColor = System::Drawing::Color::White;
			this->autoLabel->Location = System::Drawing::Point(0, 30);
			this->autoLabel->Margin = System::Windows::Forms::Padding(0);
			this->autoLabel->Name = L"autoLabel";
			this->autoLabel->Size = System::Drawing::Size(200, 24);
			this->autoLabel->TabIndex = 13;
			this->autoLabel->Text = L"Автоматический режим";
			this->autoLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->autoLabel->Click += gcnew System::EventHandler(this, &MyForm::autoLabel_Click);
			// 
			// manualLabel
			// 
			this->manualLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->manualLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->manualLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->manualLabel->ForeColor = System::Drawing::Color::White;
			this->manualLabel->Location = System::Drawing::Point(200, 30);
			this->manualLabel->Margin = System::Windows::Forms::Padding(0);
			this->manualLabel->Name = L"manualLabel";
			this->manualLabel->Size = System::Drawing::Size(200, 24);
			this->manualLabel->TabIndex = 14;
			this->manualLabel->Text = L"Ручной режим";
			this->manualLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->manualLabel->Click += gcnew System::EventHandler(this, &MyForm::manualLabel_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->dataGridView1->Location = System::Drawing::Point(30, 550);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 4;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->Size = System::Drawing::Size(340, 395);
			this->dataGridView1->TabIndex = 15;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox2->ForeColor = System::Drawing::Color::White;
			this->richTextBox2->HideSelection = false;
			this->richTextBox2->Location = System::Drawing::Point(30, 112);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(0);
			this->richTextBox2->Multiline = false;
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox2->Size = System::Drawing::Size(340, 60);
			this->richTextBox2->TabIndex = 16;
			this->richTextBox2->Text = L"";
			this->richTextBox2->Visible = false;
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox2_TextChanged);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox3->ForeColor = System::Drawing::Color::White;
			this->richTextBox3->HideSelection = false;
			this->richTextBox3->Location = System::Drawing::Point(30, 347);
			this->richTextBox3->Margin = System::Windows::Forms::Padding(0);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(340, 416);
			this->richTextBox3->TabIndex = 17;
			this->richTextBox3->Text = L"";
			this->richTextBox3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->ClientSize = System::Drawing::Size(400, 800);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->manualLabel);
			this->Controls->Add(this->autoLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лексический анализатор";
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void closeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void closeButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		closeButtonGr->Clear(Color::FromArgb(200, 80, 100));
		closeButtonGr->DrawLine(Pens::White, 8, 8, 22, 22);
		closeButtonGr->DrawLine(Pens::White, 8, 22, 22, 8);
		closeButton->Image = closeButtonBt;
		Refresh();
	}
	private: System::Void closeButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		closeButtonGr->Clear(Color::Transparent);
		closeButtonGr->DrawLine(Pens::White, 8, 8, 22, 22);
		closeButtonGr->DrawLine(Pens::White, 8, 22, 22, 8);
		closeButton->Image = closeButtonBt;
		Refresh();
	}
	private: System::Void maximizeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (WindowState != FormWindowState::Maximized)
			WindowState = FormWindowState::Maximized;
		else WindowState = FormWindowState::Normal;
	}
	private: System::Void minimizeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		WindowState = FormWindowState::Minimized;
	}
	private: System::Void maximizeButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		maximizeButtonGr->Clear(Color::LightGray);
		maximizeButtonGr->DrawLines(Pens::White, maxIcon);
		maximizeButton->Image = maximizeButtonBt;
		Refresh();
	}
	private: System::Void maximizeButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		maximizeButtonGr->Clear(Color::Transparent);
		maximizeButtonGr->DrawLines(Pens::White, maxIcon);
		maximizeButton->Image = maximizeButtonBt;
		Refresh();
	}
	private: System::Void minimizeButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		minimizeButtonGr->Clear(Color::LightGray);
		minimizeButtonGr->DrawLine(Pens::White, 7, 15, 23, 15);
		minimizeButton->Image = minimizeButtonBt;
		Refresh();
	}
	private: System::Void minimizeButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		minimizeButtonGr->Clear(Color::Transparent);
		minimizeButtonGr->DrawLine(Pens::White, 7, 15, 23, 15);
		minimizeButton->Image = minimizeButtonBt;
		Refresh();
	}

	private: System::Void panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDragging = true;
		startPos.X = e->X;
		startPos.Y = e->Y;
		startCoord.X = Left;
		startCoord.Y = Top;
	}
	private: System::Void panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDragging = false;
	}
	private: System::Void panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isDragging) {
			if (WindowState == FormWindowState::Maximized) {
				WindowState = FormWindowState::Normal;
				Location = Point(e->Location.X - Width / 2, e->Location.Y - 10);
				startPos.X = panel1->Width / 2;
				startPos.Y = panel1->Height / 2;
				startCoord.X = Left;
				startCoord.Y = -4; // makes it impossible to maximize right after it minimized
			}
			else {
				if (Top <= 0 && startCoord.Y - Top > 10) {
					WindowState = FormWindowState::Maximized;
					isDragging = false;
				}
				Location = Point(
					Location.X + e->X - startPos.X,
					Location.Y + e->Y - startPos.Y
				);
			}
		}
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		this->richTextBox1->Font = gcnew Drawing::Font(L"Bahnschrift", Math::Min(Width / 12, Height / 12),
			FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(204));
		this->richTextBox2->Height = Math::Min(Width / 8, Height / 8);
		this->richTextBox2->Font = gcnew Drawing::Font(L"Bahnschrift", Math::Min(Width / 12, Height / 12),
			FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(204));
		this->richTextBox3->Font = gcnew Drawing::Font(L"Bahnschrift", Math::Min(Width / 20, Height / 20),
			FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(204));
		dataGridView1->Rows->Clear();
		DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
			static_cast<System::Int32>(static_cast<System::Byte>(80)));
		dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", Math::Min(Width / 35, Height / 35), System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
		dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
		dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
		richTextBox1_TextChanged(sender, e);
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (isBusy) return;
		if (richTextBox1->TextLength) { // if textbox is not empty
			isBusy = true;
			List<String^> valid, invalid;
			auto symb = richTextBox1->Text[richTextBox1->SelectionStart - 1]; // the last symbol
			auto sel = richTextBox1->SelectionStart; // save the original selection index
			if (richTextBox1->SelectionStart == richTextBox1->TextLength) // if the printed char was the last one
				richTextBox1->Text = richTextBox1->Text->Substring(0, richTextBox1->SelectionStart); // cut the last symb
			else
				richTextBox1->Text = richTextBox1->Text->Substring(0, richTextBox1->SelectionStart) +
				richTextBox1->Text->Substring(richTextBox1->SelectionStart + 1); // cut the symb
			if (alphabet.Contains(richTextBox1->Text[richTextBox1->TextLength - 1].ToString()->ToLower()) ||
				richTextBox1->Text[richTextBox1->TextLength - 1] == ' ') {
				richTextBox1->Text = richTextBox1->Text->ToLower(); // ignoring symb case
			}
			else {
				richTextBox1->Text = richTextBox1->Text->Substring(0, richTextBox1->TextLength - 1); // cut the wrong symbs
			}
			String^ last = (richTextBox1->TextLength && richTextBox1->Text[richTextBox1->TextLength - 1] == ' ') ? " " : "";
			auto words = richTextBox1->Text->Split(
				gcnew array<String^>{" "},
				StringSplitOptions::RemoveEmptyEntries
			);
			String^ rtf = "{\\rtf\\ansi{\\colortbl;\\red100\\green200\\blue100;\\red200\\green30\\blue30;}";
			for (int i = 0; i < words->Length; i++) {
				if (isValid(words[i])) {
					valid.Add(words[i]);
					rtf += "{\\highlight1" + words[i];
				}
				else {
					invalid.Add(words[i]);
					rtf += "{\\highlight2" + words[i];
				}
				rtf += "}";
				rtf += (i != words->Length - 1) ? " " : "";
			}
			rtf += last;
			rtf += "}";
			richTextBox1->Rtf = rtf;
			richTextBox1->SelectionStart = sel; // get the original selection back
			isBusy = false;
			if (valid.Count || invalid.Count) {
				dataGridView1->Rows->Clear();
				dataGridView1->Rows->Add(1);
				dataGridView1->Rows[0]->Cells[0]->Value = "Правильные строки";
				dataGridView1->Rows[0]->Cells[1]->Value = "Неправильные строки";
				dataGridView1->Rows->Add(Math::Max(valid.Count, invalid.Count));
				for (short i = 0; i < valid.Count; i++) {
					dataGridView1->Rows[i+1]->Cells[0]->Value = valid[i];
				}
				for (short i = 0; i < invalid.Count; i++) {
					dataGridView1->Rows[i+1]->Cells[1]->Value = invalid[i];
				}
				for each (DataGridViewColumn ^ col in dataGridView1->Columns) {
					col->Width = dataGridView1->Width / dataGridView1->Columns->Count - 1;
				}
				for each (DataGridViewRow ^ row in dataGridView1->Rows) {
					row->Height = Math::Min(Width / 20, Height / 20);
					dataGridView1->Location = System::Drawing::Point(30, Height *.7);;
				}
			}
		}
	}

	private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (isBusy) return;
		if (richTextBox2->TextLength) {
			isBusy = true;
			List<String^> valid, invalid;
			auto symb = richTextBox2->Text[richTextBox2->SelectionStart - 1];
			auto sel = richTextBox2->SelectionStart;
			if (richTextBox2->SelectionStart == richTextBox2->TextLength)
				richTextBox2->Text = richTextBox2->Text->Substring(0, richTextBox2->SelectionStart);
			else
				richTextBox2->Text = richTextBox2->Text->Substring(0, richTextBox2->SelectionStart) +
				richTextBox2->Text->Substring(richTextBox2->SelectionStart + 1);
			if (alphabet.Contains(richTextBox2->Text[richTextBox2->TextLength - 1].ToString()->ToLower())) {
				richTextBox2->Text = richTextBox2->Text->ToLower();
			}
			else {
				richTextBox2->Text = richTextBox2->Text->Substring(0, richTextBox2->TextLength - 1);
			}
			richTextBox2->SelectionStart = sel;
			isBusy = false;
			richTextBox3->Clear();
			if (isValid(richTextBox2->Text))
				richTextBox3->Text += "Правильная строка";
			else
				richTextBox3->Text += "Неправильная строка";
		}
	}

	private: Boolean isValid(String^ word) {
		int state = 1;
		for each (Char c in word) {
			switch (state) {
			case 1:
				switch (c) {
				case 'a':
					state = 2;
					richTextBox3->Text += "(1, a) -> 2\n";
					break;
				case 'b':
					state = 3;
					richTextBox3->Text += "(1, b) -> 3\n";
					break;
				case 'c':
					state = 4;
					richTextBox3->Text += "(1, c) -> 4\n";
					break;
				}
				break;
			case 2:
				switch (c) {
				case 'a':
					state = 2;
					richTextBox3->Text += "(2, a) -> 2\n";
					break;
				case 'b':
					state = 5;
					richTextBox3->Text += "(2, b) -> 5\n";
					break;
				case 'c':
					state = 4;
					richTextBox3->Text += "(2, c) -> 4\n";
					break;
				}
				break;
			case 3:
				switch (c) {
				case 'a':
					state = 2;
					richTextBox3->Text += "(3, a) -> 2\n";
					break;
				case 'b':
					state = 3;
					richTextBox3->Text += "(3, b) -> 3\n";
					break;
				case 'c':
					state = 4;
					richTextBox3->Text += "(3, c) -> 4\n";
					break;
				}
				break;
			case 4:
				switch (c) {
				case 'a':
					state = 2;
					richTextBox3->Text += "(4, a) -> 2\n";
					break;
				case 'b':
					state = 3;
					richTextBox3->Text += "(4, b) -> 3\n";
					break;
				case 'c':
					state = 4;
					richTextBox3->Text += "(4, c) -> 4\n";
					break;
				}
				break;
			case 5:
				switch (c) {
				case 'a':
					state = 2;
					richTextBox3->Text += "(5, c) -> 2\n";
					break;
				case 'b':
					state = 6;
					richTextBox3->Text += "(5, b) -> 6\n";
					break;
				case 'c':
					state = 4;
					richTextBox3->Text += "(5, c) -> 4\n";
					break;
				}
				break;
			case 6:
				switch (c) {
				case 'a':
					state = 7;
					richTextBox3->Text += "(6, a) -> 7\n";
					break;
				case 'b':
					state = 8;
					richTextBox3->Text += "(6, b) -> 8\n";
					break;
				case 'c':
					state = 9;
					richTextBox3->Text += "(6, c) -> 9\n";
					break;
				}
				break;
			case 7:
				switch (c) {
				case 'a':
					state = 7;
					richTextBox3->Text += "(7, a) -> 7\n";
					break;
				case 'b':
					state = 10;
					richTextBox3->Text += "(7, b) -> 10\n";
					break;
				case 'c':
					state = 9;
					richTextBox3->Text += "(7, c) -> 9\n";
					break;
				}
				break;
			case 8:
				switch (c) {
				case 'a':
					state = 7;
					richTextBox3->Text += "(8, a) -> 7\n";
					break;
				case 'b':
					state = 8;
					richTextBox3->Text += "(8, b) -> 8\n";
					break;
				case 'c':
					state = 9;
					richTextBox3->Text += "(8, c) -> 9\n";
					break;
				}
				break;
			case 9:
				switch (c) {
				case 'a':
					state = 7;
					richTextBox3->Text += "(9, a) -> 7\n";
					break;
				case 'b':
					state = 8;
					richTextBox3->Text += "(9, b) -> 8\n";
					break;
				case 'c':
					state = 1;
					richTextBox3->Text += "(9, c) -> 1\n";
					break;
				}
				break;
			case 10:
				switch (c) {
				case 'a':
					state = 7;
					richTextBox3->Text += "(10, a) -> 7\n";
					break;
				case 'b':
					state = 11;
					richTextBox3->Text += "(10, b) -> 11\n";
					break;
				case 'c':
					state = 9;
					richTextBox3->Text += "(10, c) -> 9\n";
					break;
				}
				break;
			case 11:
				switch (c) {
				case 'a':
					state = 11;
					richTextBox3->Text += "(11, a) -> 11\n";
					break;
				case 'b':
					state = 11;
					richTextBox3->Text += "(11, b) -> 11\n";
					break;
				case 'c':
					state = 11;
					richTextBox3->Text += "(11, c) -> 11\n";
					break;
				}
				break;
			}
		}
		return
			state == 1 || state == 2 ||
			state == 3 || state == 4 ||
			state == 5;
	}
	private: System::Void autoLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Show();
		manualLabel->BackColor = Color::FromArgb(29, 33, 66);
		autoLabel->BackColor = Color::FromArgb(40, 40, 80);
		dataGridView1->Show();
		richTextBox2->Hide();
		richTextBox3->Hide();
		richTextBox3->Clear();
	}
	private: System::Void manualLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Clear();
		richTextBox1->Hide();
		manualLabel->BackColor = Color::FromArgb(40, 40, 80);
		autoLabel->BackColor = Color::FromArgb(29, 33, 66);
		dataGridView1->Hide();
		richTextBox2->Show();
		richTextBox3->Show();
		richTextBox3->Clear();
	}
};
}
