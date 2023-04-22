//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "Unit2.h"
#include "Unit3.h"
#include <Vcl.ExtCtrls.hpp>
#include <windows.h>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.CheckLst.hpp>
#include "VirtualTrees.hpp"

typedef struct{
 int id;
 int NumberCluster;
 UnicodeString type;
}TreeData;

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *ProgressBar1;
	TButton *Button1;
	TLabel *Label1;
	TTimer *Timer1;
	TCheckListBox *CheckListBox1;
	TVirtualStringTree *VirtualStringTree1;
	TButton *Button2;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);

private:	// User declarations
std::wstring path;

public:		// User declarations

Thread * bd;
TReadDisk * disk;


	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
