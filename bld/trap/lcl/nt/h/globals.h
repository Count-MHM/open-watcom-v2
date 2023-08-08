/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2023 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  Global definitions for Win32 trap file.
*
****************************************************************************/


#ifdef TRPGLOBINIT
#define TRPGLOBAL
#else
#define TRPGLOBAL extern
#define TRPGLOBINIT(x)
#endif

TRPGLOBAL DWORD         DebugeePid;
TRPGLOBAL DWORD         DebugeeTid;
TRPGLOBAL process_info  ProcessInfo;
TRPGLOBAL bool          DebugeeEnded;
TRPGLOBAL DWORD         LastExceptionCode;
TRPGLOBAL DWORD         CurrentModule TRPGLOBINIT( 1 );
TRPGLOBAL DWORD         ModuleTop;
TRPGLOBAL WORD          FlatCS;
TRPGLOBAL WORD          FlatDS;
TRPGLOBAL bool          StopForDLLs;
TRPGLOBAL LPSTR         DLLPath;
TRPGLOBAL subsystems    DebugeeSubsystem;
TRPGLOBAL msg_list      *DebugString;
TRPGLOBAL DEBUG_EVENT   DebugEvent;
#if MADARCH & MADARCH_X64
TRPGLOBAL bool          IsWOW64;
#else
TRPGLOBAL bool          IsWOW;
TRPGLOBAL bool          IsWinNT;
TRPGLOBAL bool          IsDOS;
TRPGLOBAL bool          IsWin32s;
TRPGLOBAL bool          IsWin95;
TRPGLOBAL bool          UseVDMStuff;
#endif
TRPGLOBAL char          CurrEXEName[MAX_PATH];
TRPGLOBAL bool          DidWaitForDebugEvent;
TRPGLOBAL bool          Slaying;
TRPGLOBAL HWND          DebuggerWindow;
TRPGLOBAL DWORD         LastDebugEventTid;
TRPGLOBAL bool          BreakOnKernelMessage;
TRPGLOBAL bool          PendingProgramInterrupt;
TRPGLOBAL char          *MsgPrefix TRPGLOBINIT( NULL );
TRPGLOBAL bool          Supporting8ByteBreakpoints TRPGLOBINIT( false );    /* Start disabled */
TRPGLOBAL bool          SupportingExactBreakpoints TRPGLOBINIT( false );    /* Start disabled */
TRPGLOBAL opcode_type   BreakOpcode;

#if defined( WOW )
  #if MADARCH & MADARCH_X86
TRPGLOBAL wow_info      WOWAppInfo;
  #endif
#endif

TRPGLOBAL fn_OpenThread                 *pOpenThread;
TRPGLOBAL fn_QueryDosDevice             *pQueryDosDevice;
TRPGLOBAL fn_GetMappedFileName          *pGetMappedFileName;
TRPGLOBAL fn_CreateToolhelp32Snapshot   *pCreateToolhelp32Snapshot;
TRPGLOBAL fn_Module32First              *pModule32First;
TRPGLOBAL fn_Module32Next               *pModule32Next;
#ifdef WOW
TRPGLOBAL fn_VDMModuleFirst             *pVDMModuleFirst;
TRPGLOBAL fn_VDMModuleNext              *pVDMModuleNext;
TRPGLOBAL fn_VDMEnumProcessWOW          *pVDMEnumProcessWOW;
TRPGLOBAL fn_VDMProcessException        *pVDMProcessException;
TRPGLOBAL fn_VDMGetModuleSelector       *pVDMGetModuleSelector;
TRPGLOBAL fn_VDMGetThreadContext        *pVDMGetThreadContext;
TRPGLOBAL fn_VDMSetThreadContext        *pVDMSetThreadContext;
TRPGLOBAL fn_VDMGetThreadSelectorEntry  *pVDMGetThreadSelectorEntry;
#endif

#undef TRPGLOBAL
#undef TRPGLOBINIT
