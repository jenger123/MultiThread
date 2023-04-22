//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include <windows.h>
#include "winioctl.h"
#include "Unit3.h"
#include "Unit1.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	 Form1->path=L"\\\\.\\C:";
  VirtualStringTree1->NodeDataSize = sizeof(TreeData);
  Button2->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
ProgressBar1 ->Visible=true;
Form1->VirtualStringTree1->Clear();
Form1->bd = new Thread(true,"files.db");
Form1->disk = new TReadDisk(true,Form1->path);
Button1->Enabled =false;
Button2->Enabled =true;
  Timer1->Interval =500;
  Timer1->Enabled=true;
   disk->Resume();
 Label1->Caption ="Выполняется чтение диска";
 Label1->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
ProgressBar1->Position=int(Form1->disk->i * 100 / Form1->disk->DiskSize );
}
//---------------------------------------------------------------------------


void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
  TreeData* treeData = (TreeData*)Sender->GetNodeData(Node);
	switch (Column) {
		case 0:
			CellText = treeData->id;
			break;
		case 1:
			CellText = treeData->NumberCluster;
			break;
		case 2:
            CellText = treeData->type;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
auto mask = GetLogicalDrives();
	int o = 0;
    for (int x = 0; x < 26; x++) // прогоняем по битам
    {
        auto n = ((mask >> x) & 1); // определяем значение текущего бита
        if (n) // если единица - диск с номером x есть
        {
			o++;
			ComboBox1->Items->Add((char)(65 + x));
        }
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Select(TObject *Sender)
{
 Form1->path=L"\\\\.\\"+ ComboBox1->Items->Strings[ComboBox1->ItemIndex] +L":";
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
bd->Free();
disk->Free();
Timer1->Enabled =false;
Form1->ProgressBar1->Visible=false;
   Form1->Label1 -> Visible = false;
   Form1->Button1->Enabled =true;
   Form1->Button2->Enabled =false;


}
//---------------------------------------------------------------------------

