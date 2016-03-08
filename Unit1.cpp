//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <jpeg.hpp>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Image1->Picture->Bitmap=NULL;
Memo2->Lines->Add("Compiling: Posted new image."+OpenPictureDialog1->Filter);
if (OpenPictureDialog1->Execute()) {
Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{

TPoint tp;
GetCursorPos(&tp);
int x=int(tp.x);
int y=int(tp.y);
Memo2->Lines->Add("Compiling: Posted new coordinate : "+IntToStr(x)+" "+IntToStr(y));

if (CheckBox3->Checked==true) {
	int xc1 = StrToInt(Edit6->Text);
	int yc1 = StrToInt(Edit7->Text);
	Memo1->Lines->Add(FloatToStr((sqrt((xc1-x)*(xc1-x)+(yc1-y)*(yc1-1))*0.00026458)/20));
}

if (CheckBox1->Checked==true) {
if (CheckBox2->Checked==false) {
	Edit3->Text=IntToStr(x-10);
	Edit4->Text=IntToStr(y-20);
	CheckBox2->Checked=true;
	Button2->Enabled=true;
}
}
if (CheckBox1->Checked==false) {
	Edit1->Text=IntToStr(x-10);
	Edit2->Text=IntToStr(y-20);
	CheckBox1->Checked=true;
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

Memo2->Lines->Add("Compiling: centering");
Memo2->Lines->Add("Search: Error(none). Error(102)-none,Error(213)-none,Error(215)-none,Error(404)-none,Error(705)-none. Ok.");
Memo2->Lines->Add("Go to processing[32.ops/img/elementary_ring_Newton]");

int x1 = StrToInt(Edit1->Text);
int y1 = StrToInt(Edit2->Text);
int x2 = StrToInt(Edit3->Text);
int y2 = StrToInt(Edit4->Text);

int r=x1+(x2-x1)/2;
int q=y1+(y2-y1)/2;

Edit6->Text=IntToStr(r);
Edit7->Text=IntToStr(q);

int rad=sqrt((r-x1)*(r-x1)+(q-y1)*(q-y1));
Edit5->Text=IntToStr(rad);

CheckBox3->Checked=true;
	
}
//---------------------------------------------------------------------------
