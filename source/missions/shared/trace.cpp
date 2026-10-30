// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Shared/Trace.cpp @353698f (verbatim) | deathmatch01.pdb lists the module with no procedures (release build: TraceA's body is the empty branch and nothing references it) | status: ported
#ifdef WIN32
#include <Windows.h>
#endif
#include <stdio.h>

#include "trace.h"

// Dumps out items to the debugging console, in a debug build

#ifndef WIN32
#define __cdecl
#endif

void __cdecl TraceA(const char *fmt, ...)
{
#ifdef _DEBUG

	va_list v_args;
	char Text[2048];
	
	va_start (v_args, fmt);     
	_vsnprintf(Text, sizeof(Text)-1,fmt, v_args);
	va_end (v_args);            
	
	OutputDebugString	(Text);
	printf("%s",Text);
#else
	(fmt); // avoid a compiler warning
#endif	
}
