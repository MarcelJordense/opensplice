/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
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

#ifndef V__TOPIC_ADAPTER_H
#define V__TOPIC_ADAPTER_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "v_event.h"
#include "v_topicAdapter.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */


OS_API void
v_topicAdapterDeinit(
    v_topicAdapter adapter);

/**
 * for every notify method the observer lock must be locked!
 */
OS_API void
v_topicAdapterNotify (
    v_topicAdapter _this,
    v_event event,
    c_voidp userData);

OS_API v_result
v_topicAdapterGetInconsistentTopicStatus(
    v_topicAdapter _this,
    c_bool reset,
    v_statusAction action,
    c_voidp arg);

OS_API v_result
v_topicAdapterGetAllDataDisposedStatus(
   v_topicAdapter _this,
   c_bool reset,
   v_statusAction action,
   c_voidp arg);


#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
