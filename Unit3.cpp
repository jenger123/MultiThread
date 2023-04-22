//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "winioctl.h"
#include <string>
#include <windows.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TReadDisk::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

   bool __fastcall ispng(BYTE * Cluster)
{
BYTE png[4]{0x89,0x50,0x4e,0x47};
for(int i=0;i<4;++i)
{
if(Cluster[i]!=png[i])
return False;
}
 return True;
}

bool __fastcall isjpg(BYTE * Cluster)
{
 BYTE jpg[10]{0xff,0xd8,0xff,0xe0,0x00,0x10,0x4a,0x46,0x49,0x46};
for(int i=0;i<sizeof(jpg);++i)
{
if(Cluster[i]!=jpg[i])
return False;
}
 return True;
}

bool __fastcall isbmp(BYTE * Cluster)
{
 BYTE bmp[4]{0x42,0x4d,0x36,0x5d};
for(int i=0;i<sizeof(bmp);++i)
{
if(Cluster[i]!=bmp[i])
return False;
}
 return True;
}


__fastcall TReadDisk::TReadDisk(bool CreateSuspended,std::wstring path)
	: TThread(CreateSuspended)
{
	this->DiskHandle =CreateFileW(path.c_str(),GENERIC_READ,
	FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	DeviceIoControl(this->DiskHandle,IOCTL_DISK_GET_LENGTH_INFO, NULL,
	 0, &this->DiskSize	, sizeof(this->DiskSize	), NULL, NULL);
	 this->ClusterSize =4096;
	 this->Cluster = new BYTE[ClusterSize];
	 this->NumberCluster = 0;

}


//---------------------------------------------------------------------------
void __fastcall TReadDisk::Execute()
{

   FreeOnTerminate = true;
   DWORD BytesRead;

   for(this->i=0,this->NumberCluster=0;this->i<=this->DiskSize;this->i+=this->ClusterSize,++this->NumberCluster)
   {


   this->sign=NULL;
   auto ReadCluster = ReadFile(this->DiskHandle,this->Cluster,this->ClusterSize,
   &BytesRead,NULL);
   if(!ReadCluster || ClusterSize!=BytesRead)  break;
   if (Form1->CheckListBox1->Checked[0])
   {
   if (isjpg(this->Cluster))
   {
   this->sign = ".jpg/jpeg";
   }
   }
	  if (Form1->CheckListBox1->Checked[1])
   {
   if (isbmp(this->Cluster))
   {
   this->sign = ".bmp";
   }
   }

	  if (Form1->CheckListBox1->Checked[2])
   {
   if (ispng(this->Cluster))
   {
   this->sign = ".png";
   }
   }
   if(this->sign!= NULL)
   Synchronize(&ToWrite);

   }
	Synchronize(&UpdateTimer);

}
//---------------------------------------------------------------------------
__fastcall TReadDisk::~TReadDisk()
{
 delete[] this->Cluster;
  CloseHandle(this->DiskHandle);
}

void __fastcall TReadDisk::ToWrite()
{
 Form1->bd->Resume();
 this->Suspend();
}
void __fastcall TReadDisk::UpdateTimer()
{
Form1->Timer1->Enabled=false;
   Form1->ProgressBar1 ->Position=100;
   Sleep(500);
   Form1->ProgressBar1->Visible=false;
   Form1->Label1 -> Visible = false;
   Form1->Button1->Enabled =true;
   Form1->Button2->Enabled =false;
   ShowMessage("Готово!");
}
