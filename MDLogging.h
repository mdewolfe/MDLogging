//
//  MDLogging.h
//  
//
//  Created by Mike De Wolfe on 2013-06-09.
//
//

/*
 * Some basic logging functions.
 * The place option for using this file is to include it the taregt's pre-compiled header file (.pch).
 * This will make these macros available to all translation units for the given target.
 */

#ifndef _MDLogging_h
#define _MDLogging_h

/*
 * Defines a logging macro that is will only log information when the 'DEBUG' flag is defined. Prints,
 * the class, method, line number, and the format string passed in. Its usage is exactly like 'NSLog().'
 * Usage Example:
 *  1 - MMDebugLog( @"hello, world" );
 *      - Output: "[SomeClass someMethod] (linenumber) -> hello, world"
 *  2 - MMDebugLog( @"Some number: %d", 5 );
 *      - Output: "[SomeClass someMethod] (linenumber) -> Some Number: 5"
 *
 * For distribution, release builds, and any other build where the 'DEBUG' flag is NOT set, 'MDDebugLog()'
 * is replaced by an emdpty block.
 *
 * 'MDDebugLog()' is intended ONLY to help debugging, and should be used only when it would be beneficial
 * to log data while testing and debugging, but would otherwise be unnecessary for production builds.
 */
#ifdef DEBUG
#define MDDebugLog(fmt, ...) NSLog((@"[%@ %@] (%d) -> " fmt), self.class, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#else
#define MDDebugLog(fmt, ...) {}
#endif

/*
 * Defines a general logging function where logging data for both DEBUG builds and production builds.
 * With the DEBUG flag set, it will use 'MDDebugLog()' from above, and logs all the information listed in
 * the notes for 'MDDebugLog().'
 *
 * Without the DEBUG flag, this method will instead use the standard 'NSLog()' function, without the
 * extra information acssociated with 'MDDebugLog().' Only the format passed in will get logged.
 *
 * Its usage is identical to calling 'NSLog()' directly.
 *
 * NOTE: Do NOT use this macro to log sensitive information, since it will be logged as plain text.
 */
#ifdef DEBUG
#define MDLog(fmt, ...) MDDebugLog(fmt, ##__VA_ARGS__)
#else
#define MDLog(fmt, ...) NSLog(fmt, ##__VA_ARGS__)
#endif



#endif
