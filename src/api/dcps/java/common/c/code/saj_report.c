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

#include "os_stdlib.h"
#include "os_report.h"
#include "saj__report.h"
#include "saj_utilities.h"

void
saj_report_stack (
    void)
{
    os_report_stack ();
}

void
saj_report (
    const os_char *file,
    os_int32 line,
    const os_char *function,
    os_int32 code,
    const os_char *format,
    ...)
{
    os_reportType reportType = OS_ERROR;
    const os_char *retcode = NULL;
    /* os_report truncates messages to <OS_REPORT_BUFLEN> bytes */
    os_char buffer[OS_REPORT_BUFLEN];
    os_size_t offset = 0;
    va_list args;

    assert (file != NULL);
    assert (function != NULL);
    assert (format != NULL);
    /* probably never happens, but you can never be to sure */
    assert (OS_REPORT_BUFLEN > 0);

    switch (code) {
        case SAJ_RETCODE_ERROR:
            retcode = "Error: ";
            break;
        case SAJ_RETCODE_UNSUPPORTED:
            retcode = "Unsupported: ";
            break;
        case SAJ_RETCODE_BAD_PARAMETER:
            retcode = "Bad parameter: ";
            break;
        case SAJ_RETCODE_PRECONDITION_NOT_MET:
            retcode = "Precondition not met: ";
            break;
        case SAJ_RETCODE_OUT_OF_RESOURCES:
            retcode = "Out of resources: ";
            break;
        case SAJ_RETCODE_NOT_ENABLED:
            retcode = "Not enabled: ";
            break;
        case SAJ_RETCODE_IMMUTABLE_POLICY:
            retcode = "Immutable policy: ";
            break;
        case SAJ_RETCODE_INCONSISTENT_POLICY:
            retcode = "Inconsistent policy: ";
            break;
        case SAJ_RETCODE_ALREADY_DELETED:
            retcode = "Already deleted: ";
            break;
        case SAJ_RETCODE_TIMEOUT:
            retcode = "Timeout: ";
            break;
        case SAJ_RETCODE_NO_DATA:
            retcode = "No data: ";
            break;
        case SAJ_RETCODE_ILLEGAL_OPERATION:
            retcode = "Illegal operation: ";
            break;
        default:
            assert (code == SAJ_RETCODE_OK);
            reportType = OS_WARNING;
            break;
    }

    if (retcode != NULL) {
        assert (offset <= OS_REPORT_BUFLEN);
        offset = strlen(retcode);
        (void)memcpy(buffer, retcode, offset);
    }

    va_start(args, format);
    (void)os_vsnprintf(buffer + offset, sizeof(buffer) - offset, format, args);
    va_end(args);

    os_report_noargs(reportType, function, file, line, code, buffer);
}

void
saj_report_deprecated (
    const os_char *file,
    os_int32 line,
    const os_char *function,
    const os_char *format,
    ...)
{
    /* os_report truncates messages to <OS_REPORT_BUFLEN> bytes */
    os_char buffer[OS_REPORT_BUFLEN];
    va_list args;

    assert (file != NULL);
    assert (function != NULL);
    assert (format != NULL);
    /* probably never happens, but you can never be to sure */
    assert (OS_REPORT_BUFLEN > 0);

    va_start(args, format);
    (void)os_vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    os_report_noargs(OS_API_INFO, function, file, line, 0, buffer);
}

void
saj_report_flush (
    const os_char *file,
    os_int32 line,
    const os_char *function,
    os_int32 flush)
{
    if (flush) {
        assert (file != NULL);
        assert (function != NULL);
    }

    os_report_stack_unwind((os_boolean)flush, function, file, line, -1);
}
