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
#ifndef SD_STRING_H
#define SD_STRING_H

#include "c_base.h"


C_CLASS(sd_string);

sd_string
sd_stringNew (
    c_ulong size);

void
sd_stringFree (
    sd_string str);

void
sd_stringAdd (
    sd_string     str,
    const c_char *format,
    ...);

const c_char *
sd_stringContents (
    sd_string str);


#endif
