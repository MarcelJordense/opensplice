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

#ifndef U__SERVICEMANAGER_H
#define U__SERVICEMANAGER_H

#include "u_serviceManager.h"

#if defined (__cplusplus)
extern "C" {
#endif

v_serviceState
u_serviceManagerGetServiceState(
    const u_serviceManager s,
    const c_char *name);

u_result
u_serviceManagerSetListener(
    const u_serviceManager _this,
    const u_serviceSplicedaemonListener callback,
    const void *usrData);

#if defined (__cplusplus)
}
#endif

#endif /* U__SERVICEMANAGER_H */
