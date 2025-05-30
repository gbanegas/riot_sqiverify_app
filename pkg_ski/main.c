/*
 * Copyright (C) 2021 Koen Zandberg
 *               2021 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     tests
 * @{
 *
 * @file
 * @brief       Tests hash-sigs package
 *
 * @author      Koen Zandberg <koen@bergzand.net>
 *
 * @}
 */

#include <string.h>

#include "xtimer.h"
#include "sqisign.h"
#include "embUnit.h"



#define MSG_SIZE 10
#define SMLEN 158



static void test_sqisign_verify(void)
{

    unsigned char msg[10] = {
        'H', 'e', 'l', 'l', 'o', /* 0–4  */
        'W', 'o', 'r', 'l', 'd' /* 5–9  */
    };

    printf("msg: %s\n", msg);

    unsigned char pk[65] = {
        0xE1, 0x02, 0x5C, 0x52, 0x52, 0xEA, 0x1B, 0x47,
        0x95, 0x15, 0x3B, 0xF3, 0x45, 0x6B, 0x38, 0x41,
        0x8F, 0xCD, 0xAA, 0xA0, 0x82, 0x03, 0xE2, 0x45,
        0xE1, 0xA4, 0x73, 0x5D, 0x44, 0x22, 0x26, 0x02,
        0xE5, 0xA5, 0x9D, 0x9A, 0x6C, 0x8E, 0x25, 0xFD,
        0x2F, 0x6A, 0x70, 0x68, 0x94, 0x25, 0x3F, 0x6C,
        0xEA, 0xCD, 0x67, 0x6D, 0xBC, 0x15, 0x96, 0xF1,
        0x51, 0xC5, 0x8E, 0x85, 0x7B, 0xF8, 0xF7, 0x01,
        0x0B
    };
	unsigned char sig[158] = {
        0xEB, 0x93, 0x73, 0x7D, 0x9D, 0xA9, 0xBD, 0x0D,
         0xD5, 0x78, 0x17, 0xA9, 0x09, 0xB3, 0x6E, 0x42,
         0x55, 0xE4, 0x73, 0xA5, 0xC1, 0x1B, 0xA0, 0x04,
         0x98, 0x86, 0x8A, 0xB7, 0x5F, 0xA6, 0xC0, 0x04,
         0xBD, 0x62, 0x14, 0x8C, 0x29, 0x0E, 0x43, 0xBC,
         0x0B, 0xDD, 0xC9, 0x98, 0x88, 0x19, 0x9D, 0xAB,
         0x91, 0xAA, 0x7A, 0x6E, 0xE9, 0xC9, 0x70, 0x82,
         0xD7, 0xB8, 0xDC, 0xE2, 0x85, 0x4C, 0xD2, 0x04,
         0x00, 0x00, 0x67, 0xE5, 0x64, 0xFC, 0xA4, 0xD6,
         0xE4, 0x6F, 0xF9, 0x42, 0x25, 0x35, 0x4D, 0x62,
         0x3C, 0x2A, 0x09, 0x3D, 0x1F, 0xB5, 0x49, 0x43,
         0x74, 0x2E, 0x83, 0x6A, 0xC9, 0x32, 0x65, 0x69,
         0xC0, 0xF4, 0x71, 0x9D, 0x78, 0x51, 0x99, 0x98,
         0x0A, 0x34, 0xB1, 0xD4, 0x60, 0x76, 0xBB, 0x35,
         0xEF, 0xC4, 0x96, 0x99, 0x3F, 0x56, 0x2B, 0x44,
         0x2E, 0x31, 0x9D, 0x4A, 0x06, 0xA0, 0x7F, 0xAB,
         0xD9, 0x7B, 0x02, 0x89, 0xF4, 0xEB, 0x62, 0xA0,
         0x42, 0xCC, 0xF5, 0x5D, 0xDD, 0x94, 0xF4, 0xAD,
         0xAD, 0x01, 0x04, 0x0A, 0x48, 0x65, 0x6C, 0x6C,
         0x6F, 0x57, 0x6F, 0x72, 0x6C, 0x64
    };
    
    int res = sqisign_verify(msg, MSG_SIZE, sig, SMLEN, pk);
	TEST_ASSERT_EQUAL_INT(res, 0);

}

Test *sqi_sigs_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_sqisign_verify)
    };

    EMB_UNIT_TESTCALLER(sqi_sigs_tests, NULL, NULL, fixtures);
    return (Test*)&sqi_sigs_tests;
}

int main(void)
{
    TESTS_START();
    TESTS_RUN(sqi_sigs_tests());
    TESTS_END();

    return 0;
}
