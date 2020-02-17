/* ====================================================================
 *
 *
 *   BSD LICENSE
 *
 *   Copyright(c) 2016-2020 Intel Corporation.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * ====================================================================
 */

/*****************************************************************************
 * @file qat_fork.h
 *
 * This file provides an interface for forking in engine
 *
 *****************************************************************************/

#ifndef QAT_FORK_H
# define QAT_FORK_H

# ifndef OPENSSL_MULTIBUFF_OFFLOAD
#  include "qat_init.h"
# else
#  include "multibuff_init.h"
# endif


/******************************************************************************
 * function:
 *         void engine_init_child_at_fork_handler(void)
 *
 * description:
 *   This function is registered, by the call to pthread_atfork(), as
 *   a function to be invoked in the child process prior to fork() returning.
 ******************************************************************************/
void engine_init_child_at_fork_handler(void);

/******************************************************************************
 * function:
 *         void engine_finish_before_fork_handler(void)
 *
 * description:
 *   This function is registered, by the call to pthread_atfork(), as
 *   a function to be run (by the parent process) before a fork() function.
 ******************************************************************************/
void engine_finish_before_fork_handler(void);

/******************************************************************************
 * function:
 *         int qat_set_instance_for_thread(long instanceNum)
 *
 * @param instanceNum [IN] - logical instance number
 *
 * description:
 *   Bind the current thread to a particular logical Cy instance. Note that if
 *   instanceNum is greater than the number of configured instances, the
 *   modulus operation is used.
 *
 ******************************************************************************/
int qat_set_instance_for_thread(long instanceNum);

#endif   /* QAT_FORK_H */
