//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include <windows.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Thread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall Thread::Thread(bool CreateSuspended,const char * sql_path)
	: TThread(CreateSuspended)
{
 int dbopen = sqlite3_open(sql_path,&this->DB);
  int result= sqlite3_prepare_v2(this->DB,"CREATE TABLE IF NOT EXISTS\
   clusters(id integer primary key autoincrement,number_cluster\
	integer,type varchar(255));",-1,&this->State,NULL);
	if(result!=SQLITE_OK)
	ShowMessage("Запрос создания таблицы не подготовлен");
	result = sqlite3_step(State);
	if(result!=SQLITE_DONE)
	ShowMessage("Запрос создания таблицы не выполнен");
	auto tableClear=sqlite3_exec(DB,"delete from clusters;",NULL,NULL,&errmsg);
auto incrementClear =sqlite3_exec(DB,"delete from sqlite_sequence where \
 name='clusters';",NULL,NULL,&errmsg);
 if (incrementClear!=SQLITE_OK || tableClear!=SQLITE_OK)
ShowMessage("Не удалось очистить таблицу!");

}
//---------------------------------------------------------------------------
void __fastcall Thread::Execute()
{
this->id =0;
FreeOnTerminate =True;
int result = sqlite3_prepare_v2(DB,"insert into clusters(number_cluster,type) \
 values(?,?);",-1,&State,NULL);
 if(result!= SQLITE_OK)
 ShowMessage("Не удалось подготовить запрос") ;
while (!Form1->disk->Finished)
{
 sqlite3_bind_int(State,1,Form1->disk->NumberCluster);
 sqlite3_bind_text(State,2,Form1->disk->sign,strlen(Form1->disk->sign),NULL);
 sqlite3_step(State);
 sqlite3_reset(State);
 Synchronize(&UpdateVST);
 this->id++;
 this->Suspend();
}
}

__fastcall Thread::~Thread()
{
sqlite3_finalize(this->State);
sqlite3_close(this->DB);
}
//---------------------------------------------------------------------------
void __fastcall Thread::UpdateVST()
{
 Form1->VirtualStringTree1->BeginUpdate();
 PVirtualNode Node = Form1->VirtualStringTree1->AddChild(NULL);
 TreeData* treeData = (TreeData*)Form1->VirtualStringTree1->GetNodeData(Node);
 treeData->id = this->id;
 treeData->NumberCluster  = Form1->disk->NumberCluster;
 treeData->type	 = Form1->disk->sign;

Form1->VirtualStringTree1->EndUpdate();
Form1->disk->Resume();
}
