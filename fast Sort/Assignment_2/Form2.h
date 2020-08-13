#pragma once

#include <sstream> 
#include <fstream>
#include <chrono> 
#include<vector>
#include <ctime>
#include <time.h>


namespace Assignment2 {

	using namespace std::chrono;
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		//------------------------------Quick Sort Code
		int part(int arr[], int l, int h)
		{
			int piv = arr[h];
			int i = (l - 1);

			for (int j = l; j <= h - 1; j++)
			{
				if (arr[j] < piv)
				{
					i++;
					swap(arr[i], arr[j]);
				}
			}
			swap(arr[i + 1], arr[h]);
			return (i + 1);
		}

		void quickSort(int arr[], int l, int h)
		{
			if (l < h)
			{
				int pi = part(arr, l, h);

				quickSort(arr, l, pi - 1);
				quickSort(arr, pi + 1, h);
			}
		}
		// ----------------------------------------!

		//MERGE SORT---------------------------------!
		void merge(int arr[], int l, int m, int r)
		{
			int i, j, k;
			 int  a1 = m - l + 1;
			 int   a2 = r - m;

			 int* L = new int[a1];
			 int *R = new int [a2];

			for (i = 0; i < a1; i++)
				L[i] = arr[l + i];
			for (j = 0; j < a2; j++)
				R[j] = arr[m + 1 + j];


			i = 0;
			j = 0;
			k = l;
			while (i < a1 && j < a2)
			{
				if (L[i] <= R[j])
				{
					arr[k] = L[i];
					i++;
				}
				else
				{
					arr[k] = R[j];
					j++;
				}
				k++;
			}


			while (i < a1)
			{
				arr[k] = L[i];
				i++;
				k++;
			}

			while (j < a2)
			{
				arr[k] = R[j];
				j++;
				k++;
			}
		}

		void mergeSort(int arr[], int l, int r)
		{
			if (l < r)
			{

				int m = l + (r - l) / 2;


				mergeSort(arr, l, m);
				mergeSort(arr, m + 1, r);

				merge(arr, l, m, r);
			}
		}
//-------------------------------------!

		//HEAP SORT------------------------!
		void heapify(int arr[], int n, int i)
		{
			int greater = i;
			int l = 2 * i + 1;
			int r = 2 * i + 2;

			if (l < n && arr[l] > arr[greater])
				greater = l;

			if (r < n && arr[r] > arr[greater])
				greater = r;

			if (greater != i)
			{
				swap(arr[i], arr[greater]);

				heapify(arr, n, greater);
			}
		}

		void heapSort(int arr[], int n)
		{

			for (int i = n / 2 - 1; i >= 0; i--)
				heapify(arr, n, i);

			for (int i = n - 1; i >= 0; i--)
			{

				swap(arr[0], arr[i]);

				heapify(arr, i, 0);
			}
		}
//---------------------------------------------!

		//Count sort -----------------------------!

		int getMax(int array[], int n)
		{
			int max = array[0];
			for (int i = 1; i < n; i++)
				if (array[i] > max)
					max = array[i];
			return max;
		}
		void countSort(int array[], int size)
		{
			int* output = new int[size + 1];
			int max = getMax(array, size);
			int* count = new int[max + 1];
			 max = array[0];
			for (int i = 1; i < size; i++)
			{
				if (array[i] > max)
					max = array[i];
			}

			for (int i = 0; i <= max; ++i)
			{
				count[i] = 0;
			}

			for (int i = 0; i < size; i++)
			{
				count[array[i]]++;
			}
			for (int i = 1; i <= max; i++)
			{
				count[i] += count[i - 1];
			}
			for (int i = size - 1; i >= 0; i--)
			{
				output[count[array[i]] - 1] = array[i];
				count[array[i]]--;
			}
			for (int i = 0; i < size; i++)
			{
				array[i] = output[i];
			}
		}
		//-----------------------------------------!

		//Radix Sort-------------------------------!
		int getMax1(int array[], int n)
		{
			int max = array[0];
			for (int i = 1; i < n; i++)
				if (array[i] > max)
					max = array[i];
			return max;
		}
		void countingSort(int array[],  int size, int place)
		{
			const int max = 10;
			int *output =new int [size];
			int count[max];

			for (int i = 0; i < max; ++i)
				count[i] = 0;

			for (int i = 0; i < size; i++)
				count[(array[i] / place) % 10]++;

			for (int i = 1; i < max; i++)
				count[i] += count[i - 1];

			for (int i = size - 1; i >= 0; i--)
			{
				output[count[(array[i] / place) % 10] - 1] = array[i];
				count[(array[i] / place) % 10]--;
			}

			for (int i = 0; i < size; i++)
				array[i] = output[i];
		}
		void radixsort(int array[], int size)
		{
			int max = getMax1(array, size);

			for (int place = 1; max / place > 0; place *= 10)
				countingSort(array, size, place);
		}
		//-----------------------------------------------!
		// Bucket Sort------------------------------------!

		void b_sort(int sarray[], int size) 
{
	int bucket[10][301];
	for (int x = 0; x<10; x++) bucket[x][300] = 0;
	for (int digit = 1; digit <= 1000000000; digit *= 10) {
		for (int i = 0; i < size; i++) {
			int dig = (sarray[i] / digit) % 10;
			bucket[dig][bucket[dig][size]++] = sarray[i];
		}
		int count = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < bucket[i][size]; j++) {
				sarray[count++] = bucket[i][j];
			}
			bucket[i][size] = 0;
		}
	}
}
//---------------------------------------------!


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(73, 395);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Unsorted Roll no\'s";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(410, 315);
			this->label1->TabIndex = 1;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(272, 298);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(121, 335);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Note :Enter 0 to 9";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(397, 294);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 33);
			this->button2->TabIndex = 4;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Lime;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(316, 395);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(179, 39);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Sorted Roll no\'s";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(501, 395);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(46, 39);
			this->button4->TabIndex = 6;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form2";
			this->Text = L"Fast Sort";
			this->TransparencyKey = System::Drawing::Color::Black;
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		System::IO::Stream^ mystream;


		String^ Readfile = System::IO::File::ReadAllText("Students.txt");
		MessageBox::Show(Readfile, "Unsorted Roll numbers File");

		mystream->Null;
	}

	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	
		String ^ d = textBox1->Text;
		int data = System::Convert::ToInt16(d);
		fstream get_data;
		int count = 300;
		get_data.open("Students.txt");
		int  rollnos;
		
		int * arr=new int [count];
		while (!get_data.eof())
		{
			for (int i = 0; i < count; i++)
			{
				get_data >> rollnos;
				arr[i] = rollnos;
			}
		}
		get_data.close();
	
		switch (data)
		{
		case 0:
		{
			Application::Exit();
			break;
		}
		case 1: //insertion sort
		{

			const clock_t begin_time = clock();
			// function of sorting -----------------------!
			int i, key, j;
			for (i = 1; i < count; i++)
			{
				key = arr[i];
				j = i - 1;


				while (j >= 0 && arr[j] > key)
				{
					arr[j + 1] = arr[j];
					j = j - 1;
				}
				arr[j + 1] = key;
			}
			//!--------------------------------------------! 
			
			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Insertion Sort)");

			get.close();
			break;
		}

		case 2: //Bubble sort
		{
			const clock_t begin_time = clock();

			// function of sorting -----------------------!

			int i, j;
			for (i = 0; i < count - 1; i++)
				for (j = 0; j < count - i - 1; j++)
					if (arr[j] > arr[j + 1])
						swap(arr[j], arr[j + 1]);
			//!--------------------------------------------! 

			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Bubble Sort)");

			get.close();
			break;
		}
		case  3: //Selection sort
		{
			const clock_t begin_time = clock();

			// function of sorting -----------------------!
			int i, j, min_idx;


			for (i = 0; i < count - 1; i++)
			{
				min_idx = i;
				for (j = i + 1; j < count; j++)
					if (arr[j] < arr[min_idx])
						min_idx = j;
				swap(arr[min_idx], arr[i]);
			}

			//!--------------------------------------------! 

			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Selection Sort)");

			get.close();
			break;
		}
		case 4: 
		{
			const clock_t begin_time = clock();

			// function of sorting -----------------------!
			
			mergeSort(arr, 0, count - 1);
			//!--------------------------------------------! 

			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Merge Sort)");

			get.close();
			break;
		}
		case 5:  //QUICK SORT  
		{
			const clock_t begin_time = clock();
			// function of sorting -----------------------!
			quickSort(arr, 0, count- 1);

			//!--------------------------------------------! 

			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Quick Sort)");

			get.close();
			break;
		}
		case 6:
		{
			const clock_t begin_time = clock();
			// function of sorting -----------------------!

			heapSort(arr, count);

			//!--------------------------------------------! 

			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Heap Sort)");

			get.close();
			break;
		}

		case 7: //Count sort
		{
			const clock_t begin_time = clock();
			// function of sorting -----------------------!
			
			countSort(arr, count);
			
			//!--------------------------------------------! 
			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Count Sort)");

			get.close();
			break;
		}
		case 8: //Radix sort
		{

			const clock_t begin_time = clock();
			// function of sorting -----------------------!
			radixsort(arr, count);
			
			//!--------------------------------------------! 
			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			MessageBox::Show("Time taken by function: "
				+ float(clock() - begin_time) / CLOCKS_PER_SEC + " seconds", "Number are sorted (Radix Sort)");

			get.close();
			break;
		}

		case 9: //Bucket sort
		{
			const clock_t begin_time = clock();

			// function of sorting -----------------------!
			b_sort(arr, count);

			//!--------------------------------------------! 
			fstream get;
			get.open("Sorted.txt");

			for (int i = 0; i < count; i++)
			{
				rollnos = arr[i];
				get << rollnos << endl;

			}
			
			
			float measure =float(clock() - begin_time) / CLOCKS_PER_SEC;
			
			//auto duration = duration_cast<microseconds>(stop - start);
			MessageBox::Show("Time taken by function: "+ measure
			/*+ duration.count()*/ + "seconds", "Number are sorted (Bucket Sort)");

			get.close();
			break;
		}
		
		default:
		{
			MessageBox::Show("You Enter Wrong Commond", "Error Message");
			break;
		}

		}

	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		System::IO::Stream^ mystream;


		String^ Readfile = System::IO::File::ReadAllText("Sorted.txt");
		MessageBox::Show(Readfile, "Sorted Roll numbers File");

		mystream->Null;

	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		ofstream ofs;
		ofs.open("Sorted.txt", ios::out | ios::trunc);
		ofs.close();

		System::IO::Stream^ mystream;
		String^ Readfile = System::IO::File::ReadAllText("Sorted.txt");
		MessageBox::Show(Readfile, "Sorted Roll numbers File Empty");

		mystream->Null;
	}
	
	};
}
