/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR PrismTech
 *   Limited, its affiliated companies and licensors. All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef S_SHMMONITOR_H
#define S_SHMMONITOR_H

#include "s_types.h"
#include "report.h"

#if defined (__cplusplus)
extern "C" {
#endif

#define s_shmMonitor(shm) ((s_shmMonitor)(shm))

s_shmMonitor
s_shmMonitorNew(
    spliced splicedaemon);

void
s_shmMonitorFree(
    s_shmMonitor _this);

c_bool
s_shmMonitorIsClean(
    s_shmMonitor _this);

#if defined (__cplusplus)
}
#endif

#endif /* S_SHMMONITOR_H */
