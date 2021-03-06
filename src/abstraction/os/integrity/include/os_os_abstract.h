/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
 *
 *   Licensed under the ADLINK Software License Agreement Rev 2.7 2nd October
 *   2014 (the "License"); you may not use this file except in compliance with
 *   the License.
 *   You may obtain a copy of the License at:
 *                      $OSPL_HOME/LICENSE
 *
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef PA_INTEGRITY_ABSTRACT_H
#define PA_INTEGRITY_ABSTRACT_H

#if defined (__cplusplus)
extern "C" {
#endif

/* include OS specific PLATFORM definition file */

#if defined(__LittleEndian) || defined(LittleEndian) || defined(__LITTLE_ENDIAN__)
#define PA__LITTLE_ENDIAN
#else
#define PA__BIG_ENDIAN
#endif

#ifdef __x86_64__
#define PA__64BIT
#endif

/* Implementation will be generated by osplconf2c */
int os_getIsSingleProcess(void);

#define OPENSPLICE_ENTRYPOINT_DECL(n) int n ()

#ifndef OPENSPLICE_ENTRYPOINT
#ifdef COMPILE_ENTRYPOINT_AS_MAIN
#define OPENSPLICE_ENTRYPOINT(n) int main (int argc, char ** argv)
#else
#define OSPL_PRAGMA(x) _Pragma(#x)

#define OPENSPLICE_ENTRYPOINT(n) \
   OSPL_PRAGMA( weak main = n ) \
   int n (int argc, char ** argv)

#define OPENSPLICE_SERVICE_ENTRYPOINT(n, instancename)	    \
   OSPL_PRAGMA( weak main = n##_main ) \
   int n##_main (int dummyargc, char** dummyargv) \
   { \
      char *argv[4]; \
      int argc = 3; \
\
      Error err; \
      Semaphore serviceStartSem = SemaphoreObjectNumber(13); \
\
      err = WaitForSemaphore(serviceStartSem); \
      assert ( err == Success ); \
      err = ReleaseSemaphore(serviceStartSem); \
      assert ( err == Success ); \
      (void) err; \
      argv[0] = #n; \
      argv[1] = #instancename; \
      argv[2] = "osplcfg://ospl.xml"; \
      argv[3] = NULL; \
      return(n(argc,argv)); \
   } \
   int n (int argc, char ** argv)
#endif
#endif

#define CONF_PARSER_NOFILESYS

#if defined (__cplusplus)
}
#endif

#endif /* PA_INTEGRITY_ABSTRACT_H */
