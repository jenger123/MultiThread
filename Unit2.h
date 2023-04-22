//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "sqlite3.h"
//---------------------------------------------------------------------------
class Thread : public TThread
{
private:
int id;
sqlite3 * DB;
sqlite3_stmt * State;
char * errmsg;

protected:
	void __fastcall Execute();
public:
	__fastcall Thread(bool CreateSuspended,const char * path);
	void __fastcall ProgressBarChange();
	void __fastcall UpdateVST();
	__fastcall ~Thread();

};
//---------------------------------------------------------------------------
#endif
