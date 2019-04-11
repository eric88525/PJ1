#pragma once
#include"DataManager.h"
#define nL System::Environment::NewLine
//#define DEBUG
Vector calV(std::string str, std::vector<Vector> vectors);
Matrix calM(std::string str, std::vector<Matrix> matrices);
Vector getV(std::string str, std::vector<Vector> vectors);
Matrix getM(std::string str, std::vector<Matrix> matrices);
namespace WindowsFormsApplication_cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm ���K�n
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			lastInputLength = -1;
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;



	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  OutputLabel;
	private: System::Windows::Forms::TextBox^  Output;

	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  VectorLabel;
	private: System::Windows::Forms::ListBox^  VectorList;



	protected:
	protected:

	private:
		/// <summary>
			DataManager* dataManager;
			String^ userInput;
			int lastInputLength;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputLabel = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->VectorLabel = (gcnew System::Windows::Forms::Label());
			this->VectorList = (gcnew System::Windows::Forms::ListBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->OutputLabel = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1079, 24);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->LoadVectorToolStripMenuItem });
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->FileToolStripMenuItem->Text = L"File";
			// 
			// LoadVectorToolStripMenuItem
			// 
			this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->LoadVectorToolStripMenuItem->Text = L"Load Data";
			this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				43.34975F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				56.65025F)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 491)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1079, 564);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->InputLabel);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
			this->flowLayoutPanel1->Controls->Add(this->VectorList);
			this->flowLayoutPanel1->Location = System::Drawing::Point(470, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(597, 558);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// InputLabel
			// 
			this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InputLabel->AutoSize = true;
			this->InputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->InputLabel->Location = System::Drawing::Point(3, 95);
			this->InputLabel->Name = L"InputLabel";
			this->InputLabel->Size = System::Drawing::Size(41, 16);
			this->InputLabel->TabIndex = 0;
			this->InputLabel->Text = L"Input";
			this->InputLabel->Click += gcnew System::EventHandler(this, &WindowsForm::InputLabel_Click);
			// 
			// Input
			// 
			this->Input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Input->Location = System::Drawing::Point(50, 3);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(533, 200);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			// 
			// VectorLabel
			// 
			this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VectorLabel->AutoSize = true;
			this->VectorLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->VectorLabel->Location = System::Drawing::Point(3, 359);
			this->VectorLabel->Name = L"VectorLabel";
			this->VectorLabel->Size = System::Drawing::Size(47, 16);
			this->VectorLabel->TabIndex = 2;
			this->VectorLabel->Text = L"Vector";
			// 
			// VectorList
			// 
			this->VectorList->FormattingEnabled = true;
			this->VectorList->ItemHeight = 12;
			this->VectorList->Location = System::Drawing::Point(56, 209);
			this->VectorList->Name = L"VectorList";
			this->VectorList->Size = System::Drawing::Size(533, 316);
			this->VectorList->TabIndex = 3;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
			this->flowLayoutPanel2->Controls->Add(this->Output);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(452, 558);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// OutputLabel
			// 
			this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OutputLabel->AutoSize = true;
			this->OutputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->OutputLabel->Location = System::Drawing::Point(3, 0);
			this->OutputLabel->Name = L"OutputLabel";
			this->OutputLabel->Size = System::Drawing::Size(52, 16);
			this->OutputLabel->TabIndex = 0;
			this->OutputLabel->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Output->Location = System::Drawing::Point(3, 19);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(449, 522);
			this->Output->TabIndex = 1;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			// 
			// WindowsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1079, 589);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Name = L"WindowsForm";
			this->Text = L"VectorExample";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//�}��Dialog
	openFileDialog1->ShowDialog();
}
	private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
#ifndef DEBUG

		std::vector<Vector> vectors = dataManager->GetVectors();
		std::vector<Matrix> matrices = dataManager->GetMatrices();
		if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
		{
			//�N�ϥΪ̿�J�r��(�buserInput��)�A�̪ťէ@����
			array<String^> ^inp = userInput->Split(' ',',');
			std::vector<std::string> userCommand(inp->Length),str;	
			
			for (int s = 0; s < inp->Length;s++) {
				MarshalString(inp[s], userCommand[s]);
			}
			if (inp->Length > 2) {
				userCommand[1].erase(0, 1);
				userCommand[userCommand.size() - 1].pop_back();
			}
			Vector v,v1,vResult;
			Matrix m, m1, mResult;
			//�r�����A�Y���O��"print"�����p
			Output->Text += userInput + System::Environment::NewLine;
			if (userCommand[0]=="printV") {
				vResult = calV(userCommand[1], vectors);
				Output->Text += vResult.getResult();
			}
			else if (userCommand[0] == "calV") {
				vResult = calV(userCommand[1],vectors);
				Output->Text += vResult.getResult();
			}
			else if (userCommand[0] == "Norm") {
				vResult = calV(userCommand[1], vectors);
				double db = norm(vResult);
				Output->Text += db + System::Environment::NewLine;
			}
			else if (userCommand[0]== "Normal") {
				vResult = calV(userCommand[1], vectors);
				vResult = normalization(vResult);
				Output->Text += vResult.getResult();
			}
			else if (userCommand[0] == "Cross") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				vResult = crossProduct(v, v1);
				Output->Text += vResult.getResult();
			}
			else if (userCommand[0]== "Com") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				vResult = component(v, v1);
				Output->Text += vResult.getResult();
			}
			else if (userCommand[0]== "Proj") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				vResult = projection(v, v1);
				Output->Text += vResult.getResult();
			}
			else if (userCommand[0]== "Area") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				double db = area(v,v1);
				Output->Text += db+ System::Environment::NewLine;;
			}
			else if (userCommand[0] == "isParallel") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				if (isParallel(v, v1)) {
					Output->Text += "Yes"+ System::Environment::NewLine;;
				}
				else {
					Output->Text += "No"+ System::Environment::NewLine;;
				}
			}
			else if (userCommand[0]== "isOrthogonal") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				if (isOrthogonal(v, v1)) {
					Output->Text += "Yes" + System::Environment::NewLine;;
				}
				else {
					Output->Text += "No" + System::Environment::NewLine;;
				}
			}
			else if (userCommand[0] == "angle") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				double db = angle(v, v1);
				Output->Text += db + System::Environment::NewLine;;
			}
			else if (userCommand[0]== "PN") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				vResult = pN(v, v1);
				Output->Text += vResult.getResult();
			}
			else if (userCommand[0]== "IsLI") {
				v = calV(userCommand[1], vectors);
				v1 = calV(userCommand[2], vectors);
				if (isLI(v, v1)) {
					Output->Text += "Yes" + System::Environment::NewLine;;
				}
				else {
					Output->Text += "No" + System::Environment::NewLine;;
				}
			}
			else if (userCommand[0]== "Ob") {
				std::vector<Vector> varr;
				std::vector<Vector> op;
				for (int i = 1; i < userCommand.size();i++) {
					varr.push_back(calV(userCommand[i],vectors));
				}
				op = Ob(varr);
				for (auto i:op) {
					Output->Text += i.getResult();
				}
			}
			else if (userCommand[0]== "calM") {
				mResult = calM(userCommand[1],matrices);
				//Output->Text += .getResult();
			}else if (userCommand[0] == "printM") {
				mResult = calM(userCommand[1], matrices);
				Output->Text += mResult.getResult();
			}
			else if (userCommand[0]== "Rank") {
				mResult = calM(userCommand[1], matrices);
				int rk = rank(mResult);
				Output->Text += rk + System::Environment::NewLine;
			}
			else if (userCommand[0] == "Trans") {
				mResult = calM(userCommand[1], matrices);
				mResult = transpose(mResult);
				Output->Text += mResult.getResult();
			}
			else if (userCommand[0] == "Sol") {
				m = calM(userCommand[1], matrices);
				m1 = calM(userCommand[2], matrices);
				mResult = m / m1;
				Output->Text += mResult.getResult();
			}
			else if (userCommand[0] == "Det") {
				mResult = calM(userCommand[1], matrices);
				double db = determinants(mResult);
				Output->Text += db + Environment::NewLine;
			}
			else if (userCommand[0] == "Inverse") {
				mResult = calM(userCommand[1],matrices);
				mResult = inverse(mResult);
				Output->Text += mResult.getResult();
			}
			else if (userCommand[0] == "Adj") {
				mResult = calM(userCommand[1], matrices);
				mResult = Adj(mResult);
				Output->Text += mResult.getResult();
			}
			else if (userCommand[0] == "PM") {
				mResult = calM(userCommand[1], matrices);
				double db=0;
				mResult = pm(mResult,db);
				Output->Text += "v="+ System::Environment::NewLine + mResult.getResult()+ System::Environment::NewLine;
				Output->Text += "d=" + System::Environment::NewLine + db + System::Environment::NewLine;
			}
			else if (userCommand[0] == "eigen") {
				std::vector<double> eigenValues;
				mResult = calM(userCommand[1], matrices);
				mResult = eigen(mResult,eigenValues);
				Output->Text += "v =" + nL+mResult.getResult()+nL+"d ="+nL;
				for (int i = 0; i < eigenValues.size(); i++) {
					for (int j = 0; j < eigenValues.size(); j++) {
						if (i == j)Output->Text += eigenValues[i];
						else Output->Text += 0;
						Output->Text += "   ";
					}
					Output->Text += nL;
				}
					
			}
			else if (userCommand[0] == "rref") {
				
				mResult = calM(userCommand[1], matrices);

				std::vector<Matrix> result= rref(mResult);
				Output->Text += result[1].getResult() + System::Environment::NewLine;
				Output->Text += result[0].getResult() + System::Environment::NewLine;
			}
			else if (userCommand[0] == "LeastSquare") {
				m = calM(userCommand[1], matrices);
				m1 = calM(userCommand[2], matrices);
				mResult = LeastSquare(m,m1);
				Output->Text += mResult.getResult();
			}
			else
			{
				Output->Text += "-Command not found-" + Environment::NewLine;
			}
			userInput = "";
		}
		else
		{
			//�N�ϥΪ̿�J�r��(�bText box��)�A��'\n'�@����
			array<String^> ^userCommand = Input->Text->Split('\n');
			//�ñN�̫�@��A�@���ثe�ϥΪ̿�J���O
			userInput = userCommand[userCommand->Length - 1];
		}

#endif // !DEBUG

}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	//�bDialog���UOK�K�|�i�J���禡
	//�r�����string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//�N�ɮ׸��|�W�ٶǤJdataManager
	dataManager->SetFileName(tempFileName);
	//�qŪ��Ū���V�q���
	if (dataManager->LoadData())
	{
		//�NVectorList�����إ����M��
		VectorList->Items->Clear();	
		//���o�Ҧ��V�q���
		std::vector<Vector> vectors = dataManager->GetVectors();
		std::vector<Matrix> matrices = dataManager->GetMatrices();
		if (vectors.size()) {
			for (unsigned int i = 0; i < vectors.size(); i++)
			{
				//�N�ɮצW�٦s�J�Ȧs
				std::string tempString = vectors[i].Name;
				//�N��X�榡�s�J�Ȧs
				tempString += " [";
				//�N��X��Ʀs�J�Ȧs
				for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[i].Data[j]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (j != vectors[i].Data.size() - 1)
						tempString += ",";
				}
				//�N��X�榡�s�J�Ȧs
				tempString += "]";
				//�N���إ[�JVectorList��
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
		}
		else if (matrices.size()) {
			for (auto i : matrices)
			{
				std::string tempString = i.Name;
				tempString += " [";
				for (int row = 0; row < i.row; row++) {
					for (int col = 0; col < i.col; col++) {
						std::string scalarString = std::to_string(i.Data[row][col]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if (!(row == i.row - 1 && col == i.col - 1))
							tempString += ",";
					}
				}
				tempString += "]";
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
		}
	}
}










private: System::Void InputLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}

};
}
