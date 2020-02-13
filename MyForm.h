#pragma once

#include "ManagerDataBase.h"
#include "ManagerXML.h"
#include "Movie.h"
#include "ManagerOMDb.h"
#include <msclr\marshal_cppstd.h>

namespace filmotekav2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		ManagerDataBase * db;
		System::Timers::Timer^ timer;

	public:
		MyForm(void)
		{
			InitializeComponent();
			db = new ManagerDataBase("FILMOTEKA");
			timer = gcnew System::Timers::Timer(5000);
			timer->BeginInit();
			timer->AutoReset = false;
			timer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &MyForm::timer_elapsed);
			timer->EndInit();

		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Title;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Release_Year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rating;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Watched;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ dataGridViewCheckBoxColumn1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label4;

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Release_Year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rating = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Watched = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewCheckBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(12, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Delete movie ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 58);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 20);
			this->button2->TabIndex = 2;
			this->button2->Text = L"XML Export";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Title,
					this->Release_Year, this->Rating, this->Watched
			});
			this->dataGridView1->Location = System::Drawing::Point(108, 32);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(423, 179);
			this->dataGridView1->TabIndex = 3;
			// 
			// Title
			// 
			this->Title->HeaderText = L"Title";
			this->Title->Name = L"Title";
			this->Title->ReadOnly = true;
			this->Title->Width = 200;
			// 
			// Release_Year
			// 
			this->Release_Year->HeaderText = L"Release Year";
			this->Release_Year->Name = L"Release_Year";
			this->Release_Year->ReadOnly = true;
			this->Release_Year->Width = 60;
			// 
			// Rating
			// 
			this->Rating->HeaderText = L"Rating";
			this->Rating->Name = L"Rating";
			this->Rating->Width = 60;
			// 
			// Watched
			// 
			this->Watched->HeaderText = L"Watched";
			this->Watched->Name = L"Watched";
			this->Watched->Width = 60;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 130);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Sort by title";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 159);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Sort by rating";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::Button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 188);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(90, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Sort by year";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::Button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 244);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 20);
			this->textBox1->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(154, 225);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Title";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(241, 225);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Release year";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(244, 244);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(66, 20);
			this->textBox2->TabIndex = 10;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(329, 242);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Add movie";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::Button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(726, 243);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(93, 23);
			this->button7->TabIndex = 12;
			this->button7->Text = L"OMDb search";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::Button7_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewCheckBoxColumn1
			});
			this->dataGridView2->Location = System::Drawing::Point(585, 32);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(423, 179);
			this->dataGridView2->TabIndex = 13;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Title";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 200;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Release Year";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 60;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Rating";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 60;
			// 
			// dataGridViewCheckBoxColumn1
			// 
			this->dataGridViewCheckBoxColumn1->HeaderText = L"Watched";
			this->dataGridViewCheckBoxColumn1->Name = L"dataGridViewCheckBoxColumn1";
			this->dataGridViewCheckBoxColumn1->Width = 60;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(585, 245);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(120, 20);
			this->textBox3->TabIndex = 14;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(922, 242);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 15;
			this->button8->Text = L"XML Import";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::Button8_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(631, 225);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Title";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"SWTxt", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button9->Location = System::Drawing::Point(537, 107);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(42, 46);
			this->button9->TabIndex = 17;
			this->button9->Text = L"<-";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::Button9_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(29, 297);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(10, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L" ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1022, 328);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"FILMOTEKA";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void data_grid_update(System::Windows::Forms::DataGridView^ dataGridView, std::vector<Movie> &movies)
	{
		dataGridView->Rows->Clear();
		for (size_t i = 0; i < movies.size(); i++)
		{
			//create new string and register it for garbage collector
			//this object will be deleted when it is no longer needed
			System::String^ xtitle = gcnew System::String(movies[i].title.c_str());
			dataGridView->Rows->Add(xtitle,
				movies[i].year,
				movies[i].rating,
				movies[i].watched);
		}
	}
	private: void data_grid_movie_add(System::Windows::Forms::DataGridView^ dataGridView, Movie &movie)
	{
		System::String^ xtitle = gcnew System::String(movie.title.c_str());
		dataGridView->Rows->Add(xtitle,
			movie.year,
			movie.rating,
			movie.watched);
	}
	private: void timer_elapsed(Object^ state, System::Timers::ElapsedEventArgs^ e)
	{
		label4->Text = "";
	}
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::vector<Movie> movies = db->export_database();
		data_grid_update(dataGridView1, movies);
		dataGridView1->CellValueChanged += 
			gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::DataGridView1_CellValueChanged);
	}
private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<Movie> movies = db->sort_by_title();
	data_grid_update(dataGridView1, movies);
}

private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<Movie> movies = db->sort_by_rating();
	data_grid_update(dataGridView1, movies);
}
private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<Movie> movies = db->sort_by_year();
	data_grid_update(dataGridView1, movies);
}

private: System::Void Button6_Click(System::Object^ sender, System::EventArgs^ e) {
	// system::string to std::string
	std::string title = msclr::interop::marshal_as<std::string>(textBox1->Text);
	int year;
	bool result = db->check_if_movie_exist(title);
	if (result == false)
	{
		if (int::TryParse(textBox2->Text, year)) //system::string to int
		{
			Movie movie(title, year, 0, false);
			db->add_movie(movie);
			data_grid_movie_add(dataGridView1, movie);
		}
	}
	else 
	{
		label4->Text = "There is already a movie with this title in FILMOTEKA";
		timer->Start();
	}
}
private: System::Void Button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < dataGridView1->SelectedRows->Count; i++)
	{
		std::string title = msclr::interop::marshal_as<std::string>
			(dynamic_cast<System::String^>(dataGridView1->SelectedRows[i]->Cells[DATABASE_TITLE_INDEX]->Value));
		dataGridView1->Rows->Remove(dataGridView1->SelectedRows[i]);
		db->delete_movie_by_title(title.c_str());
	}
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	ManagerXML xml;
	saveFileDialog1->Filter = "(*.xml)|*.xml";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::string path = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
		xml.write(path, db->export_database());
	}
}
private: System::Void DataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->ColumnIndex == DATABASE_RATING_INDEX)
	{
		int rating = System::Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[DATABASE_RATING_INDEX]->Value);
		std::string title = msclr::interop::marshal_as<std::string>
			(dynamic_cast<System::String^>(dataGridView1->Rows[e->RowIndex]->Cells[DATABASE_TITLE_INDEX]->Value));
		bool result = db->validate_rating(rating);
		if (result == true)
		{
			db->give_rating_by_title(rating, title.c_str());
		}
		else
		{
			label4->Text = "You can give ratings only from 0 to 10";
			timer->Start();
			int count = db->get_rating_by_title(title);
			dataGridView1->Rows[e->RowIndex]->Cells[DATABASE_RATING_INDEX]->Value = count;
		}
	}
	else if (e->ColumnIndex == DATABASE_WATCHED_INDEX)
	{
		bool watched = System::Convert::ToBoolean(dataGridView1->Rows[e->RowIndex]->Cells[DATABASE_WATCHED_INDEX]->Value);
		std::string title = msclr::interop::marshal_as<std::string>
			(dynamic_cast<System::String^>(dataGridView1->Rows[e->RowIndex]->Cells[DATABASE_TITLE_INDEX]->Value));
		db->set_watched_by_title(watched, title.c_str());
	}
}
private: System::Void Button8_Click(System::Object^ sender, System::EventArgs^ e) {
	ManagerXML xml;
	openFileDialog1->Filter = "(*.xml)|*.xml";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::string path = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
		std::vector<Movie> movies = xml.read(path);
		data_grid_update(dataGridView2, movies);
	}
}
private: System::Void Button9_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < dataGridView2->SelectedRows->Count; i++)
	{
		std::string title = msclr::interop::marshal_as<std::string>
			(dynamic_cast<System::String^>(dataGridView2->SelectedRows[i]->Cells[DATABASE_TITLE_INDEX]->Value));
		int year = System::Convert::ToInt32(dataGridView2->SelectedRows[i]->Cells[DATABASE_YEAR_INDEX]->Value);
		int rating = System::Convert::ToInt32(dataGridView2->SelectedRows[i]->Cells[DATABASE_RATING_INDEX]->Value);
		bool watched = System::Convert::ToBoolean(dataGridView2->SelectedRows[i]->Cells[DATABASE_WATCHED_INDEX]->Value);
		bool result = db->check_if_movie_exist(title);
		if (result == false)
		{
			dataGridView2->Rows->Remove(dataGridView2->SelectedRows[i]);
			Movie movie(title, year, rating, watched);
			db->add_movie(movie);
			data_grid_movie_add(dataGridView1, movie);
		}
		else
		{
			label4->Text = "There is already a movie with this title in FILMOTEKA";
			timer->Start();
		}
	}
}
private: System::Void Button7_Click(System::Object^ sender, System::EventArgs^ e) {
	ManagerOMDb omdb;
	ManagerXML xml;

	std::string title = msclr::interop::marshal_as<std::string>(textBox3->Text);
	std::string xml_response = omdb.search_by_title(title);
	std::vector<Movie> movies_vec = xml.parse_OMDb_response(xml_response);
	data_grid_update(dataGridView2, movies_vec);
}
};
}

