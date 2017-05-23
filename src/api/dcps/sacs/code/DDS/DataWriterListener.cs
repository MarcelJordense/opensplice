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
 */

using System;
using System.Collections.Generic;
using DDS.OpenSplice.CustomMarshalers;

namespace DDS
{
    public abstract class DataWriterListener : IDataWriterListener
    {
        public virtual void OnOfferedDeadlineMissed(IDataWriter entityInterface, OfferedDeadlineMissedStatus status)
        {
        }
        public virtual void OnOfferedIncompatibleQos(IDataWriter entityInterface, OfferedIncompatibleQosStatus status)
        {
        }
        public virtual void OnLivelinessLost(IDataWriter entityInterface, LivelinessLostStatus status)
        {
        }
        public virtual void OnPublicationMatched(IDataWriter entityInterface, PublicationMatchedStatus status)
        {
        }


    }
}
