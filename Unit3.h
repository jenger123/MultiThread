//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <string>
#include <windows.h>
//---------------------------------------------------------------------------
bool __fastcall isbmp(BYTE *);
bool __fastcall isjpg(BYTE *);
bool __fastcall ispng(BYTE *);


class TReadDisk : public TThread
{
private:

   HANDLE DiskHandle;
   int ClusterSize;

   BYTE * Cluster ;

protected:
	void __fastcall Execute();
public:
	__fastcall TReadDisk(bool CreateSuspended,std::wstring);
    __fastcall ~TReadDisk();
   const char * sign;
   int NumberCluster;
   ULONGLONG DiskSize;
   ULONGLONG i;
   void __fastcall ToWrite();
   void __fastcall UpdateTimer();





};
//---------------------------------------------------------------------------
#endif
