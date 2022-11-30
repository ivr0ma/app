#include "MyForm.h"
#include <Windows.h>
using namespace app1;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

//
// ���������� ������� ��� ������� ����
//
System::Void app1::MyForm::���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Classifier cl;          // ������ ������
	double c1, c2, x1, x2;  // ����-�� ��� ��������������� ������� 

	// ������� ������
	for (int i = 0; i < 6; i++) {
		this->chart1->Series[i]->Points->Clear();
	}

	// �������� ������� ��� �������������� ���������� �������
	this->chart1->Series[2]->IsVisibleInLegend = 0;
	this->chart1->Series[3]->IsVisibleInLegend = 0;
	this->chart1->Series[5]->IsVisibleInLegend = 0;

	// 1-�� ����
	if (radioButton1->Checked) {
		this->chart1->ChartAreas[0]->AxisX->Title = "������� " + Convert::ToString(n1_pr1+1);
		this->chart1->ChartAreas[0]->AxisY->Title = "������� " + Convert::ToString(n1_pr2+1);

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(cl.cl_A[i][n1_pr1], cl.cl_A[i][n1_pr2]); // ��������� ��������� ����� ������ �
			this->chart1->Series[0]->Points->AddXY(cl.cl_C[i][n1_pr1], cl.cl_C[i][n1_pr2]); // ��������� ��������� ����� ������ C
			this->chart1->Series[1]->Points->AddXY(cl.cl_B[i][n1_pr1], cl.cl_B[i][n1_pr2]); // ��������� ��������� ����� ������ B
			this->chart1->Series[1]->Points->AddXY(cl.cl_D[i][n1_pr1], cl.cl_D[i][n1_pr2]); // ��������� ��������� ����� ������ D
			this->chart1->Series[0]->LegendText = "����� AC";
			this->chart1->Series[1]->LegendText = "����� BD";
			this->chart1->Series[0]->IsVisibleInLegend = 1;
			this->chart1->Series[1]->IsVisibleInLegend = 1;
		}

		// ���������� ��������������� �������
		c1 = n1_c1;
		c2 = n1_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 20 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // ��������� ��������� ����� �� ������
		}
	}
	// 2-�� ����
	else if (radioButton2->Checked) {
		this->chart1->ChartAreas[0]->AxisX->Title = "������� " + Convert::ToString(n2_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "������� " + Convert::ToString(n2_pr2 + 1);

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(cl.cl_A[i][n2_pr1], cl.cl_A[i][n2_pr2]); // ��������� ��������� ����� ������ A
			this->chart1->Series[1]->Points->AddXY(cl.cl_C[i][n2_pr1], cl.cl_C[i][n2_pr2]); // ��������� ��������� ����� ������ C
			this->chart1->Series[0]->LegendText = "����� A";
			this->chart1->Series[1]->LegendText = "����� C";
		}

		// ���������� ��������������� �������
		c1 = n2_c1;
		c2 = n2_c2;
		for (int i = 0; i < 2; i++) {
			//x2 = 40 * i + 20;
			x2 = 10 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // ��������� ��������� ����� �� ������
		}
	}
	// 3-�� ����
	else {
		this->chart1->ChartAreas[0]->AxisX->Title = "������� " + Convert::ToString(n3_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "������� " + Convert::ToString(n3_pr2 + 1);

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(cl.cl_B[i][n3_pr1], cl.cl_B[i][n3_pr2]); // ��������� ��������� ����� ������ B
			this->chart1->Series[1]->Points->AddXY(cl.cl_D[i][n3_pr1], cl.cl_D[i][n3_pr2]); // ��������� ��������� ����� ������ D
			this->chart1->Series[0]->LegendText = "����� B";
			this->chart1->Series[1]->LegendText = "����� D";
		}

		// ���������� ��������������� �������
		c1 = n3_c1;
		c2 = n3_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 60 * i + 10;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // ��������� ��������� ����� �� ������
		}
	}

	return System::Void();
}

//
// ������� ������� ���������� ������� ��� ������� ����
//
System::Void app1::MyForm::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ������� ������
	for (int i = 0; i < 6; i++) {
		this->chart1->Series[i]->Points->Clear();
	}

	return System::Void();
}

//
// ����� �� ����������
//
System::Void app1::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("�� ����� ������ �����?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

//
// ������ ��������� ������������� �������
//
System::Void app1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	obj = new int[10];     // ������� ������ ��� �������� ��������� �������
	Classifier cl;         // ������ ������
	double c1, c2, x1, x2; // ��������� ��������������� �������
	char res;              // ��������� �������������
	int pr1, pr2;          // ������ ���. ���������

	// ������������� �������� ���������� (�������� �� ���������)
	for (int i = 0; i < 10; i++) {
		obj[i] = 0;
	}

	// ���������� ������� ���������� ����������
	if (textBox1->Text != "") {
		obj[0] = Convert::ToInt32(textBox1->Text);
	}
	if (textBox2->Text != "") {
		obj[1] = Convert::ToInt32(textBox2->Text);
	}
	if (textBox3->Text != "") {
		obj[2] = Convert::ToInt32(textBox3->Text);
	}
	if (textBox4->Text != "") {
		obj[3] = Convert::ToInt32(textBox4->Text);
	}
	if (textBox5->Text != "") {
		obj[4] = Convert::ToInt32(textBox5->Text);
	}
	if (textBox6->Text != "") {
		obj[5] = Convert::ToInt32(textBox6->Text);
	}
	if (textBox7->Text != "") {
		obj[6] = Convert::ToInt32(textBox7->Text);
	}
	if (textBox8->Text != "") {
		obj[7] = Convert::ToInt32(textBox8->Text);
	}
	if (textBox9->Text != "") {
		obj[8] = Convert::ToInt32(textBox9->Text);
	}
	if (textBox10->Text != "") {
		obj[9] = Convert::ToInt32(textBox10->Text);
	}

	// ������� ������
	for (int i = 0; i < 6; i++) {
		this->chart1->Series[i]->Points->Clear();
	}

	// ���������� ������� ��� ������� ����� ���������� �������
	this->chart1->Series[2]->IsVisibleInLegend = 1;
	this->chart1->Series[3]->IsVisibleInLegend = 1;
	this->chart1->Series[5]->IsVisibleInLegend = 1;

	res = cl.recognize(obj); // �������������
	
	// ���� ������ ������ A
	if (res == 'A') {
		this->label12->Text = "������ ������: A"; 
		this->chart1->ChartAreas[0]->AxisX->Title = "������� " + Convert::ToString(n2_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "������� " + Convert::ToString(n2_pr2 + 1);
		pr1 = n2_pr1;
		pr2 = n2_pr2;

		// ���������� ��������������� �������
		c1 = n2_c1;
		c2 = n2_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 10 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // �������� ��������� �����
		}
	}
	// ���� ������ ������ B
	if (res == 'B') {
		this->label12->Text = "������ ������: B";
		this->chart1->ChartAreas[0]->AxisX->Title = "������� " + Convert::ToString(n3_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "������� " + Convert::ToString(n3_pr2 + 1);
		pr1 = n3_pr1;
		pr2 = n3_pr2;

		// ���������� ��������������� �������
		c1 = n3_c1;
		c2 = n3_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 60 * i + 10;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // �������� ��������� �����
		}
	}
	// ���� ������ ������ C
	if (res == 'C') {
		this->label12->Text = "������ ������: C";
		this->chart1->ChartAreas[0]->AxisX->Title = "������� " + Convert::ToString(n2_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "������� " + Convert::ToString(n2_pr2 + 1);
		pr1 = n2_pr1;
		pr2 = n2_pr2;

		// ���������� ��������������� �������
		c1 = n2_c1;
		c2 = n2_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 10 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // �������� ��������� �����
		}
	}
	// ���� ������ ������ D
	if (res == 'D') {
		this->label12->Text = "������ ������: D";
		this->chart1->ChartAreas[0]->AxisX->Title = "������� " + Convert::ToString(n3_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "������� " + Convert::ToString(n3_pr2 + 1);
		pr1 = n3_pr1;
		pr2 = n3_pr2;

		// ���������� ��������������� �������
		c1 = n3_c1;
		c2 = n3_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 60 * i + 10;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // �������� ��������� �����
		}
	}

	// ���������� ������� ������� A,B,C,D
	for (int i = 0; i < 15; i++) {
		this->chart1->Series[0]->Points->AddXY(cl.cl_D[i][pr1], cl.cl_D[i][pr2]);
		this->chart1->Series[1]->Points->AddXY(cl.cl_A[i][pr1], cl.cl_A[i][pr2]);
		this->chart1->Series[2]->Points->AddXY(cl.cl_B[i][pr1], cl.cl_B[i][pr2]);
		this->chart1->Series[3]->Points->AddXY(cl.cl_C[i][pr1], cl.cl_C[i][pr2]);
		this->chart1->Series[0]->LegendText = "����� D";
		this->chart1->Series[1]->LegendText = "����� A";
		this->chart1->Series[2]->LegendText = "����� B";
		this->chart1->Series[3]->LegendText = "����� C";
	}

	// ���������� ��������� ������
	this->chart1->Series[5]->Points->AddXY(obj[pr1], obj[pr2]);

	delete[] obj; // ������� ���������� ������

	return System::Void();
}

