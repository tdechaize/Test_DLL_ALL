//*********************    File : dll_core.c (main core of dll)    *****************
// #define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "dll_share.h"

/*------------------------------------------------------------------------
 Procedure:     DllMain / LibMain / DllEntryPoint (depend of compilers)
 Purpose:       Dll entry point. Called when a dll is loaded or
                unloaded by a process, and when new threads are
                created or destroyed.
 Input:         hinstDll: 		Instance handle of the dll
                dwReason: 		event: attach/detach
                reserved: 	    not used
 Output:        The return value is used only when the dwReason is
                DLL_PROCESS_ATTACH. True means that the dll has
                sucesfully loaded, False means that the dll is unable
                to initialize and should be unloaded immediately.
 Errors:

 Remark : FUNCAPI used here only for Borland C/C++ and Digital Mars
        Compiler C/C++ with value is __declspec(dllexport) in case
        of build DLL, and value is __declspec(dllimport) in case of
		use DLL.
------------------------------------------------------------------------*/
#if defined(__LCC__)
BOOL WINAPI LibMain(
#elif defined(__BORLANDC__)
BOOL WINAPI FUNCAPI DllEntryPoint(
#elif defined(__DMC__)
BOOL APIENTRY FUNCAPI DllMain(
#else
BOOL WINAPI DllMain(
#endif
                    void 		  *hinstDll,
					unsigned long dwReason,
					void 		  *reserved)
{
    switch( dwReason ) {
    case DLL_PROCESS_ATTACH:
        printf( "Message from DLL : DLL attaching to process...\n" );
        break;
    case DLL_PROCESS_DETACH:
        printf( "Message from DLL : DLL detaching from process...\n" );
        break;
		// The attached process creates a new thread.
	case DLL_THREAD_ATTACH:
		printf("The attached process creating a new thread...\n");
		break;
		// The thread of the attached process terminates.
	case DLL_THREAD_DETACH:
		printf("The thread of the attached process terminates...\n");
		break;
	default:
		printf("Reason called not matched, error if any : %ld...\n", GetLastError());
		break;
    }
    return( 1 );    /* Indicate success */
}

/*------------------------------------------------------------------------

 Another instructions : 		list of exported functions of DLL.

 All functions must be declared in dll_share.h, but instancied here
 with body described all instructions to execute "really" that for
 which each function is defined.
 Noted prefix FUNCAPI valued at :
		__declspec(dllexport) when generate DLL
		__declspec(dllimport) when use DLL

 Remark : FUNCAPI not used for LCC Compiler 64 bits only.
		To integrate this, I must create a totally new
		variable during compilation "__LCC64__"

------------------------------------------------------------------------*/
#ifdef __LCC64__
int Hello(void)
#else
FUNCAPI int Hello(void)
#endif
 {
    printf( "Hello from a DLL!\n" );
    return( 0 );
 }

#ifdef __LCC64__
int Addint(int i1, int i2)
#else
FUNCAPI int Addint(int i1, int i2)
#endif
 {
	return i1 + i2;
 }

#ifdef __LCC64__
int Subint(int i1, int i2)
#else
FUNCAPI int Subint(int i1, int i2)
#endif
 {
	return i1 - i2;
 }

#ifdef __LCC64__
int Multint(int i1, int i2)
#else
FUNCAPI int Multint(int i1, int i2)
#endif
 {
   return i1 * i2;
 }

#ifdef __LCC64__
int Divint(int i1, int i2)
#else
FUNCAPI int Divint(int i1, int i2)
#endif
 {
  if (i2 == 0) {
     printf("La division par zero n'est pas autorisee, le retour vaut 1 par défaut.\n");
     return(1);
  } else {
	  return (i1/i2);
  }
 }

#ifdef __LCC64__
int Squarint(int i)
#else
FUNCAPI int Squarint(int i)
#endif
 {
   return i * i;
 }

#ifdef __LCC64__
double Adddbl(double i1, double i2)
#else
FUNCAPI double Adddbl(double i1, double i2)
#endif
 {
	return i1 + i2;
 }

#ifdef __LCC64__
double Subdbl(double i1, double i2)
#else
FUNCAPI double Subdbl(double i1, double i2)
#endif
 {
	return i1 - i2;
 }

#ifdef __LCC64__
double Multdbl(double i1, double i2)
#else
FUNCAPI double Multdbl(double i1, double i2)
#endif
 {
   return i1 * i2;
 }

#ifdef __LCC64__
double Divdbl(double i1, double i2)
#else
FUNCAPI double Divdbl(double i1, double i2)
#endif
 {
  if (i2 == 0.0) {
     printf("La division par zero n'est pas autorisee, le retour vaut 1 par défaut.\n");
     return(1.0);
  } else   {
	  return (i1/i2);
  }
 }

#ifdef __LCC64__
double Squardbl(double i)
#else
FUNCAPI double Squardbl(double i)
#endif
 {
   return i * i;
 }
 //******************************    End file : dll_core.c   *********************************
