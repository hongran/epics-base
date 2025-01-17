/*************************************************************************\
* Copyright (c) 2008 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* SPDX-License-Identifier: EPICS
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

#ifndef INC_osiNTPTime_H
#define INC_osiNTPTime_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Use NTP_TIME_DISABLE_TIME_PROVIDER as the argument to NTPTime_Init
 * if NTP is bring provided by ntpd. EPICS general time will ask the
 * operating system for the time:
 *
 *    NTPTime_Init(NTP_TIME_DISABLE_TIME_PROVIDER);
 */
#define NTP_TIME_DISABLE_TIME_PROVIDER 0

void NTPTime_Init(int priority);
void NTPTime_Shutdown(void *dummy);
int  NTPTime_Report(int level);

#ifdef __cplusplus
}
#endif

#endif
