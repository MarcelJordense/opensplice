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
#ifndef Q_BUILTIN_TOPIC_H
#define Q_BUILTIN_TOPIC_H

struct proxy_participant;
struct proxy_writer;
struct proxy_reader;

struct nn_plist;

/* Functions called at proxy entity creation/deletion time, so they
   can do whatever is necessary to get the builtin topics function
   correctly.

   These probably should return an error code, but I don't quite know
   how to handle it yet and this way we have Coverity on our side.
   Implementation is outside the common core.

   These may assume the proxy entities are stable, without parallel QoS
   changes. */
void write_builtin_topic_proxy_participant (const struct proxy_participant *proxypp);
void write_builtin_topic_proxy_participant_cm (const struct proxy_participant *proxypp);
void dispose_builtin_topic_proxy_participant (const struct proxy_participant *proxypp, int isimplicit);
void write_builtin_topic_proxy_writer (const struct proxy_writer *pwr);
void dispose_builtin_topic_proxy_writer (const struct proxy_writer *pwr, int isimplicit);
void write_builtin_topic_proxy_reader (const struct proxy_reader *prd);
void dispose_builtin_topic_proxy_reader (const struct proxy_reader *prd, int isimplicit);
void write_builtin_topic_proxy_group (const struct proxy_group *pgroup);
void dispose_builtin_topic_proxy_group (const struct proxy_group *pgroup, int isimplicit);

void write_builtin_topic_proxy_topic (const struct nn_plist *datap);

#endif

/* SHA1 not available (unoffical build.) */
