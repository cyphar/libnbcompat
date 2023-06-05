/* $NetBSD: sha2-test.c,v 1.0 2023/06/06 16:12:53 cyphar Exp $ */

/*-
 * Copyright (c) 2023 Aleksa Sarai <cyphar@cyphar.com>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <nbcompat.h>
#include <nbcompat/stdio.h>
#include <nbcompat/sha2.h>

#include "private/test-helpers.h"

/*
 * All of these test vectors are the "short message" vectors provided by NIST
 * as part of the Cryptographic Algorithm Validation Program.
 * <https://csrc.nist.gov/projects/cryptographic-algorithm-validation-program>
 *
 * The script to generate these functions is in private/cavs2c.awk.
 */

DEFINE_TEST_FUNC(sha256, SHA256_Data);

int sha256(void)
{
	int err = 0;

	size_t len1 = 0;
	const char vector1[] = {'\x00',};
	const char *digest1 = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
	err |= test_sha256(vector1, len1, digest1);

	size_t len2 = 1;
	const char vector2[] = {'\xd3',};
	const char *digest2 = "28969cdfa74a12c82f3bad960b0b000aca2ac329deea5c2328ebc6f2ba9802c1";
	err |= test_sha256(vector2, len2, digest2);

	size_t len3 = 2;
	const char vector3[] = {'\x11','\xaf',};
	const char *digest3 = "5ca7133fa735326081558ac312c620eeca9970d1e70a4b95533d956f072d1f98";
	err |= test_sha256(vector3, len3, digest3);

	size_t len4 = 3;
	const char vector4[] = {'\xb4','\x19','\x0e',};
	const char *digest4 = "dff2e73091f6c05e528896c4c831b9448653dc2ff043528f6769437bc7b975c2";
	err |= test_sha256(vector4, len4, digest4);

	size_t len5 = 4;
	const char vector5[] = {'\x74','\xba','\x25','\x21',};
	const char *digest5 = "b16aa56be3880d18cd41e68384cf1ec8c17680c45a02b1575dc1518923ae8b0e";
	err |= test_sha256(vector5, len5, digest5);

	size_t len6 = 5;
	const char vector6[] = {'\xc2','\x99','\x20','\x96','\x82',};
	const char *digest6 = "f0887fe961c9cd3beab957e8222494abb969b1ce4c6557976df8b0f6d20e9166";
	err |= test_sha256(vector6, len6, digest6);

	size_t len7 = 6;
	const char vector7[] = {'\xe1','\xdc','\x72','\x4d','\x56','\x21',};
	const char *digest7 = "eca0a060b489636225b4fa64d267dabbe44273067ac679f20820bddc6b6a90ac";
	err |= test_sha256(vector7, len7, digest7);

	size_t len8 = 7;
	const char vector8[] = {'\x06','\xe0','\x76','\xf5','\xa4','\x42','\xd5',};
	const char *digest8 = "3fd877e27450e6bbd5d74bb82f9870c64c66e109418baa8e6bbcff355e287926";
	err |= test_sha256(vector8, len8, digest8);

	size_t len9 = 8;
	const char vector9[] = {'\x57','\x38','\xc9','\x29','\xc4','\xf4','\xcc','\xb6',};
	const char *digest9 = "963bb88f27f512777aab6c8b1a02c70ec0ad651d428f870036e1917120fb48bf";
	err |= test_sha256(vector9, len9, digest9);

	size_t len10 = 9;
	const char vector10[] = {'\x33','\x34','\xc5','\x80','\x75','\xd3','\xf4','\x13','\x9e',};
	const char *digest10 = "078da3d77ed43bd3037a433fd0341855023793f9afd08b4b08ea1e5597ceef20";
	err |= test_sha256(vector10, len10, digest10);

	size_t len11 = 10;
	const char vector11[] = {'\x74','\xcb','\x93','\x81','\xd8','\x9f','\x5a','\xa7','\x33','\x68',};
	const char *digest11 = "73d6fad1caaa75b43b21733561fd3958bdc555194a037c2addec19dc2d7a52bd";
	err |= test_sha256(vector11, len11, digest11);

	size_t len12 = 11;
	const char vector12[] = {'\x76','\xed','\x24','\xa0','\xf4','\x0a','\x41','\x22','\x1e','\xbf','\xcf',};
	const char *digest12 = "044cef802901932e46dc46b2545e6c99c0fc323a0ed99b081bda4216857f38ac";
	err |= test_sha256(vector12, len12, digest12);

	size_t len13 = 12;
	const char vector13[] = {'\x9b','\xaf','\x69','\xcb','\xa3','\x17','\xf4','\x22','\xfe','\x26','\xa9','\xa0',};
	const char *digest13 = "fe56287cd657e4afc50dba7a3a54c2a6324b886becdcd1fae473b769e551a09b";
	err |= test_sha256(vector13, len13, digest13);

	size_t len14 = 13;
	const char vector14[] = {'\x68','\x51','\x1c','\xdb','\x2d','\xbb','\xf3','\x53','\x0d','\x7f','\xb6','\x1c','\xbc',};
	const char *digest14 = "af53430466715e99a602fc9f5945719b04dd24267e6a98471f7a7869bd3b4313";
	err |= test_sha256(vector14, len14, digest14);

	size_t len15 = 14;
	const char vector15[] = {'\xaf','\x39','\x7a','\x8b','\x8d','\xd7','\x3a','\xb7','\x02','\xce','\x8e','\x53','\xaa','\x9f',};
	const char *digest15 = "d189498a3463b18e846b8ab1b41583b0b7efc789dad8a7fb885bbf8fb5b45c5c";
	err |= test_sha256(vector15, len15, digest15);

	size_t len16 = 15;
	const char vector16[] = {'\x29','\x4a','\xf4','\x80','\x2e','\x5e','\x92','\x5e','\xb1','\xc6','\xcc','\x9c','\x72','\x4f','\x09',};
	const char *digest16 = "dcbaf335360de853b9cddfdafb90fa75567d0d3d58af8db9d764113aef570125";
	err |= test_sha256(vector16, len16, digest16);

	size_t len17 = 16;
	const char vector17[] = {'\x0a','\x27','\x84','\x7c','\xdc','\x98','\xbd','\x6f','\x62','\x22','\x0b','\x04','\x6e','\xdd','\x76','\x2b',};
	const char *digest17 = "80c25ec1600587e7f28b18b1b18e3cdc89928e39cab3bc25e4d4a4c139bcedc4";
	err |= test_sha256(vector17, len17, digest17);

	size_t len18 = 17;
	const char vector18[] = {'\x1b','\x50','\x3f','\xb9','\xa7','\x3b','\x16','\xad','\xa3','\xfc','\xf1','\x04','\x26','\x23','\xae','\x76','\x10',};
	const char *digest18 = "d5c30315f72ed05fe519a1bf75ab5fd0ffec5ac1acb0daf66b6b769598594509";
	err |= test_sha256(vector18, len18, digest18);

	size_t len19 = 18;
	const char vector19[] = {'\x59','\xeb','\x45','\xbb','\xbe','\xb0','\x54','\xb0','\xb9','\x73','\x34','\xd5','\x35','\x80','\xce','\x03','\xf6','\x99',};
	const char *digest19 = "32c38c54189f2357e96bd77eb00c2b9c341ebebacc2945f97804f59a93238288";
	err |= test_sha256(vector19, len19, digest19);

	size_t len20 = 19;
	const char vector20[] = {'\x58','\xe5','\xa3','\x25','\x9c','\xb0','\xb6','\xd1','\x2c','\x83','\xf7','\x23','\x37','\x9e','\x35','\xfd','\x29','\x8b','\x60',};
	const char *digest20 = "9b5b37816de8fcdf3ec10b745428708df8f391c550ea6746b2cafe019c2b6ace";
	err |= test_sha256(vector20, len20, digest20);

	size_t len21 = 20;
	const char vector21[] = {'\xc1','\xef','\x39','\xce','\xe5','\x8e','\x78','\xf6','\xfc','\xdc','\x12','\xe0','\x58','\xb7','\xf9','\x02','\xac','\xd1','\xa9','\x3b',};
	const char *digest21 = "6dd52b0d8b48cc8146cebd0216fbf5f6ef7eeafc0ff2ff9d1422d6345555a142";
	err |= test_sha256(vector21, len21, digest21);

	size_t len22 = 21;
	const char vector22[] = {'\x9c','\xab','\x7d','\x7d','\xca','\xec','\x98','\xcb','\x3a','\xc6','\xc6','\x4d','\xd5','\xd4','\x47','\x0d','\x0b','\x10','\x3a','\x81','\x0c',};
	const char *digest22 = "44d34809fc60d1fcafa7f37b794d1d3a765dd0d23194ebbe340f013f0c39b613";
	err |= test_sha256(vector22, len22, digest22);

	size_t len23 = 22;
	const char vector23[] = {'\xea','\x15','\x7c','\x02','\xeb','\xaf','\x1b','\x22','\xde','\x22','\x1b','\x53','\xf2','\x35','\x39','\x36','\xd2','\x35','\x9d','\x1e','\x1c','\x97',};
	const char *digest23 = "9df5c16a3f580406f07d96149303d8c408869b32053b726cf3defd241e484957";
	err |= test_sha256(vector23, len23, digest23);

	size_t len24 = 23;
	const char vector24[] = {'\xda','\x99','\x9b','\xc1','\xf9','\xc7','\xac','\xff','\x32','\x82','\x8a','\x73','\xe6','\x72','\xd0','\xa4','\x92','\xf6','\xee','\x89','\x5c','\x68','\x67',};
	const char *digest24 = "672b54e43f41ee77584bdf8bf854d97b6252c918f7ea2d26bc4097ea53a88f10";
	err |= test_sha256(vector24, len24, digest24);

	size_t len25 = 24;
	const char vector25[] = {'\x47','\x99','\x13','\x01','\x15','\x6d','\x1d','\x97','\x7c','\x03','\x38','\xef','\xbc','\xad','\x41','\x00','\x41','\x33','\xae','\xfb','\xca','\x6b','\xcf','\x7e',};
	const char *digest25 = "feeb4b2b59fec8fdb1e55194a493d8c871757b5723675e93d3ac034b380b7fc9";
	err |= test_sha256(vector25, len25, digest25);

	size_t len26 = 25;
	const char vector26[] = {'\x2e','\x7e','\xa8','\x4d','\xa4','\xbc','\x4d','\x7c','\xfb','\x46','\x3e','\x3f','\x2c','\x86','\x47','\x05','\x7a','\xff','\xf3','\xfb','\xec','\xec','\xa1','\xd2','\x00',};
	const char *digest26 = "76e3acbc718836f2df8ad2d0d2d76f0cfa5fea0986be918f10bcee730df441b9";
	err |= test_sha256(vector26, len26, digest26);

	size_t len27 = 26;
	const char vector27[] = {'\x47','\xc7','\x70','\xeb','\x45','\x49','\xb6','\xef','\xf6','\x38','\x1d','\x62','\xe9','\xbe','\xb4','\x64','\xcd','\x98','\xd3','\x41','\xcc','\x1c','\x09','\x98','\x1a','\x7a',};
	const char *digest27 = "6733809c73e53666c735b3bd3daf87ebc77c72756150a616a194108d71231272";
	err |= test_sha256(vector27, len27, digest27);

	size_t len28 = 27;
	const char vector28[] = {'\xac','\x4c','\x26','\xd8','\xb4','\x3b','\x85','\x79','\xd8','\xf6','\x1c','\x98','\x07','\x02','\x6e','\x83','\xe9','\xb5','\x86','\xe1','\x15','\x9b','\xd4','\x3b','\x85','\x19','\x37',};
	const char *digest28 = "0e6e3c143c3a5f7f38505ed6adc9b48c18edf6dedf11635f6e8f9ac73c39fe9e";
	err |= test_sha256(vector28, len28, digest28);

	size_t len29 = 28;
	const char vector29[] = {'\x07','\x77','\xfc','\x1e','\x1c','\xa4','\x73','\x04','\xc2','\xe2','\x65','\x69','\x28','\x38','\x10','\x9e','\x26','\xaa','\xb9','\xe5','\xc4','\xae','\x4e','\x86','\x00','\xdf','\x4b','\x1f',};
	const char *digest29 = "ffb4fc03e054f8ecbc31470fc023bedcd4a406b9dd56c71da1b660dcc4842c65";
	err |= test_sha256(vector29, len29, digest29);

	size_t len30 = 29;
	const char vector30[] = {'\x1a','\x57','\x25','\x1c','\x43','\x1d','\x4e','\x6c','\x2e','\x06','\xd6','\x52','\x46','\xa2','\x96','\x91','\x50','\x71','\xa5','\x31','\x42','\x5e','\xcf','\x25','\x59','\x89','\x42','\x2a','\x66',};
	const char *digest30 = "c644612cd326b38b1c6813b1daded34448805aef317c35f548dfb4a0d74b8106";
	err |= test_sha256(vector30, len30, digest30);

	size_t len31 = 30;
	const char vector31[] = {'\x9b','\x24','\x5f','\xda','\xd9','\xba','\xeb','\x89','\x0d','\x9c','\x0d','\x0e','\xff','\x81','\x6e','\xfb','\x4c','\xa1','\x38','\x61','\x0b','\xc7','\xd7','\x8c','\xb1','\xa8','\x01','\xed','\x32','\x73',};
	const char *digest31 = "c0e29eeeb0d3a7707947e623cdc7d1899adc70dd7861205ea5e5813954fb7957";
	err |= test_sha256(vector31, len31, digest31);

	size_t len32 = 31;
	const char vector32[] = {'\x95','\xa7','\x65','\x80','\x9c','\xaf','\x30','\xad','\xa9','\x0a','\xd6','\xd6','\x1c','\x2b','\x4b','\x30','\x25','\x0d','\xf0','\xa7','\xce','\x23','\xb7','\x75','\x3c','\x91','\x87','\xf4','\x31','\x9c','\xe2',};
	const char *digest32 = "a4139b74b102cf1e2fce229a6cd84c87501f50afa4c80feacf7d8cf5ed94f042";
	err |= test_sha256(vector32, len32, digest32);

	size_t len33 = 32;
	const char vector33[] = {'\x09','\xfc','\x1a','\xcc','\xc2','\x30','\xa2','\x05','\xe4','\xa2','\x08','\xe6','\x4a','\x8f','\x20','\x42','\x91','\xf5','\x81','\xa1','\x27','\x56','\x39','\x2d','\xa4','\xb8','\xc0','\xcf','\x5e','\xf0','\x2b','\x95',};
	const char *digest33 = "4f44c1c7fbebb6f9601829f3897bfd650c56fa07844be76489076356ac1886a4";
	err |= test_sha256(vector33, len33, digest33);

	size_t len34 = 33;
	const char vector34[] = {'\x05','\x46','\xf7','\xb8','\x68','\x2b','\x5b','\x95','\xfd','\x32','\x38','\x5f','\xaf','\x25','\x85','\x4c','\xb3','\xf7','\xb4','\x0c','\xc8','\xfa','\x22','\x9f','\xbd','\x52','\xb1','\x69','\x34','\xaa','\xb3','\x88','\xa7',};
	const char *digest34 = "b31ad3cd02b10db282b3576c059b746fb24ca6f09fef69402dc90ece7421cbb7";
	err |= test_sha256(vector34, len34, digest34);

	size_t len35 = 34;
	const char vector35[] = {'\xb1','\x2d','\xb4','\xa1','\x02','\x55','\x29','\xb3','\xb7','\xb1','\xe4','\x5c','\x6d','\xbc','\x7b','\xaa','\x88','\x97','\xa0','\x57','\x6e','\x66','\xf6','\x4b','\xf3','\xf8','\x23','\x61','\x13','\xa6','\x27','\x6e','\xe7','\x7d',};
	const char *digest35 = "1c38bf6bbfd32292d67d1d651fd9d5b623b6ec1e854406223f51d0df46968712";
	err |= test_sha256(vector35, len35, digest35);

	size_t len36 = 35;
	const char vector36[] = {'\xe6','\x8c','\xb6','\xd8','\xc1','\x86','\x6c','\x0a','\x71','\xe7','\x31','\x3f','\x83','\xdc','\x11','\xa5','\x80','\x9c','\xf5','\xcf','\xbe','\xed','\x1a','\x58','\x7c','\xe9','\xc2','\xc9','\x2e','\x02','\x2a','\xbc','\x16','\x44','\xbb',};
	const char *digest36 = "c2684c0dbb85c232b6da4fb5147dd0624429ec7e657991edd95eda37a587269e";
	err |= test_sha256(vector36, len36, digest36);

	size_t len37 = 36;
	const char vector37[] = {'\x4e','\x3d','\x8a','\xc3','\x6d','\x61','\xd9','\xe5','\x14','\x80','\x83','\x11','\x55','\xb2','\x53','\xb3','\x79','\x69','\xfe','\x7e','\xf4','\x9d','\xb3','\xb3','\x99','\x26','\xf3','\xa0','\x0b','\x69','\xa3','\x67','\x74','\x36','\x60','\x00',};
	const char *digest37 = "bf9d5e5b5393053f055b380baed7e792ae85ad37c0ada5fd4519542ccc461cf3";
	err |= test_sha256(vector37, len37, digest37);

	size_t len38 = 37;
	const char vector38[] = {'\x03','\xb2','\x64','\xbe','\x51','\xe4','\xb9','\x41','\x86','\x4f','\x9b','\x70','\xb4','\xc9','\x58','\xf5','\x35','\x5a','\xac','\x29','\x4b','\x4b','\x87','\xcb','\x03','\x7f','\x11','\xf8','\x5f','\x07','\xeb','\x57','\xb3','\xf0','\xb8','\x95','\x50',};
	const char *digest38 = "d1f8bd684001ac5a4b67bbf79f87de524d2da99ac014dec3e4187728f4557471";
	err |= test_sha256(vector38, len38, digest38);

	size_t len39 = 38;
	const char vector39[] = {'\xd0','\xfe','\xfd','\x96','\x78','\x7c','\x65','\xff','\xa7','\xf9','\x10','\xd6','\xd0','\xad','\xa6','\x3d','\x64','\xd5','\xc4','\x67','\x99','\x60','\xe7','\xf0','\x6a','\xeb','\x8c','\x70','\xdf','\xef','\x95','\x4f','\x8e','\x39','\xef','\xdb','\x62','\x9b',};
	const char *digest39 = "49ba38db85c2796f85ffd57dd5ec337007414528ae33935b102d16a6b91ba6c1";
	err |= test_sha256(vector39, len39, digest39);

	size_t len40 = 39;
	const char vector40[] = {'\xb7','\xc7','\x9d','\x7e','\x5f','\x1e','\xec','\xcd','\xfe','\xdf','\x0e','\x7b','\xf4','\x3e','\x73','\x0d','\x44','\x7e','\x60','\x7d','\x8d','\x14','\x89','\x82','\x3d','\x09','\xe1','\x12','\x01','\xa0','\xb1','\x25','\x80','\x39','\xe7','\xbd','\x48','\x75','\xb1',};
	const char *digest40 = "725e6f8d888ebaf908b7692259ab8839c3248edd22ca115bb13e025808654700";
	err |= test_sha256(vector40, len40, digest40);

	size_t len41 = 40;
	const char vector41[] = {'\x64','\xcd','\x36','\x3e','\xcc','\xe0','\x5f','\xdf','\xda','\x24','\x86','\xd0','\x11','\xa3','\xdb','\x95','\xb5','\x20','\x6a','\x19','\xd3','\x05','\x40','\x46','\x81','\x9d','\xd0','\xd3','\x67','\x83','\x95','\x5d','\x7e','\x5b','\xf8','\xba','\x18','\xbf','\x73','\x8a',};
	const char *digest41 = "32caef024f84e97c30b4a7b9d04b678b3d8a6eb2259dff5b7f7c011f090845f8";
	err |= test_sha256(vector41, len41, digest41);

	size_t len42 = 41;
	const char vector42[] = {'\x6a','\xc6','\xc6','\x3d','\x61','\x8e','\xaf','\x00','\xd9','\x1c','\x5e','\x28','\x07','\xe8','\x3c','\x09','\x39','\x12','\xb8','\xe2','\x02','\xf7','\x8e','\x13','\x97','\x03','\x49','\x8a','\x79','\xc6','\x06','\x7f','\x54','\x49','\x7c','\x61','\x27','\xa2','\x39','\x10','\xa6',};
	const char *digest42 = "4bb33e7c6916e08a9b3ed6bcef790aaaee0dcf2e7a01afb056182dea2dad7d63";
	err |= test_sha256(vector42, len42, digest42);

	size_t len43 = 42;
	const char vector43[] = {'\xd2','\x68','\x26','\xdb','\x9b','\xae','\xaa','\x89','\x26','\x91','\xb6','\x89','\x00','\xb9','\x61','\x63','\x20','\x8e','\x80','\x6a','\x1d','\xa0','\x77','\x42','\x9e','\x45','\x4f','\xa0','\x11','\x84','\x09','\x51','\xa0','\x31','\x32','\x7e','\x60','\x5a','\xb8','\x2e','\xcc','\xe2',};
	const char *digest43 = "3ac7ac6bed82fdc8cd15b746f0ee7489158192c238f371c1883c9fe90b3e2831";
	err |= test_sha256(vector43, len43, digest43);

	size_t len44 = 43;
	const char vector44[] = {'\x3f','\x7a','\x05','\x9b','\x65','\xd6','\xcb','\x02','\x49','\x20','\x4a','\xac','\x10','\xb9','\xf1','\xa4','\xac','\x9e','\x58','\x68','\xad','\xeb','\xbe','\x93','\x5a','\x9e','\xb5','\xb9','\x01','\x9e','\x1c','\x93','\x8b','\xfc','\x4e','\x5c','\x53','\x78','\x99','\x7a','\x39','\x47','\xf2',};
	const char *digest44 = "bfce809534eefe871273964d32f091fe756c71a7f512ef5f2300bcd57f699e74";
	err |= test_sha256(vector44, len44, digest44);

	size_t len45 = 44;
	const char vector45[] = {'\x60','\xff','\xcb','\x23','\xd6','\xb8','\x8e','\x48','\x5b','\x92','\x0a','\xf8','\x1d','\x10','\x83','\xf6','\x29','\x1d','\x06','\xac','\x8c','\xa3','\xa9','\x65','\xb8','\x59','\x14','\xbc','\x2a','\xdd','\x40','\x54','\x4a','\x02','\x7f','\xca','\x93','\x6b','\xbd','\xe8','\xf3','\x59','\x05','\x1c',};
	const char *digest45 = "1d26f3e04f89b4eaa9dbed9231bb051eef2e8311ad26fe53d0bf0b821eaf7567";
	err |= test_sha256(vector45, len45, digest45);

	size_t len46 = 45;
	const char vector46[] = {'\x9e','\xcd','\x07','\xb6','\x84','\xbb','\x9e','\x0e','\x66','\x92','\xe3','\x20','\xce','\xc4','\x51','\x0c','\xa7','\x9f','\xcd','\xb3','\xa2','\x21','\x2c','\x26','\xd9','\x0d','\xf6','\x5d','\xb3','\x3e','\x69','\x2d','\x07','\x3c','\xc1','\x74','\x84','\x0d','\xb7','\x97','\x50','\x4e','\x48','\x2e','\xef',};
	const char *digest46 = "0ffeb644a49e787ccc6970fe29705a4f4c2bfcfe7d19741c158333ff6982cc9c";
	err |= test_sha256(vector46, len46, digest46);

	size_t len47 = 46;
	const char vector47[] = {'\x9d','\x64','\xde','\x71','\x61','\x89','\x58','\x84','\xe7','\xfa','\x3d','\x6e','\x9e','\xb9','\x96','\xe7','\xeb','\xe5','\x11','\xb0','\x1f','\xe1','\x9c','\xd4','\xa6','\xb3','\x32','\x2e','\x80','\xaa','\xf5','\x2b','\xf6','\x44','\x7e','\xd1','\x85','\x4e','\x71','\x00','\x1f','\x4d','\x54','\xf8','\x93','\x1d',};
	const char *digest47 = "d048ee1524014adf9a56e60a388277de194c694cc787fc5a1b554ea9f07abfdf";
	err |= test_sha256(vector47, len47, digest47);

	size_t len48 = 47;
	const char vector48[] = {'\xc4','\xad','\x3c','\x5e','\x78','\xd9','\x17','\xec','\xb0','\xcb','\xbc','\xd1','\xc4','\x81','\xfc','\x2a','\xaf','\x23','\x2f','\x7e','\x28','\x97','\x79','\xf4','\x0e','\x50','\x4c','\xc3','\x09','\x66','\x2e','\xe9','\x6f','\xec','\xbd','\x20','\x64','\x7e','\xf0','\x0e','\x46','\x19','\x9f','\xbc','\x48','\x2f','\x46',};
	const char *digest48 = "50dbf40066f8d270484ee2ef6632282dfa300a85a8530eceeb0e04275e1c1efd";
	err |= test_sha256(vector48, len48, digest48);

	size_t len49 = 48;
	const char vector49[] = {'\x4e','\xef','\x51','\x07','\x45','\x9b','\xdd','\xf8','\xf2','\x4f','\xc7','\x65','\x6f','\xd4','\x89','\x6d','\xa8','\x71','\x1d','\xb5','\x04','\x00','\xc0','\x16','\x48','\x47','\xf6','\x92','\xb8','\x86','\xce','\x8d','\x7f','\x4d','\x67','\x39','\x50','\x90','\xb3','\x53','\x4e','\xfd','\x7b','\x0d','\x29','\x8d','\xa3','\x4b',};
	const char *digest49 = "7c5d14ed83dab875ac25ce7feed6ef837d58e79dc601fb3c1fca48d4464e8b83";
	err |= test_sha256(vector49, len49, digest49);

	size_t len50 = 49;
	const char vector50[] = {'\x04','\x7d','\x27','\x58','\xe7','\xc2','\xc9','\x62','\x3f','\x9b','\xdb','\x93','\xb6','\x59','\x7c','\x5e','\x84','\xa0','\xcd','\x34','\xe6','\x10','\x01','\x4b','\xcb','\x25','\xb4','\x9e','\xd0','\x5c','\x7e','\x35','\x6e','\x98','\xc7','\xa6','\x72','\xc3','\xdd','\xdc','\xae','\xb8','\x43','\x17','\xef','\x61','\x4d','\x34','\x2f',};
	const char *digest50 = "7d53eccd03da37bf58c1962a8f0f708a5c5c447f6a7e9e26137c169d5bdd82e4";
	err |= test_sha256(vector50, len50, digest50);

	size_t len51 = 50;
	const char vector51[] = {'\x3d','\x83','\xdf','\x37','\x17','\x2c','\x81','\xaf','\xd0','\xde','\x11','\x51','\x39','\xfb','\xf4','\x39','\x0c','\x22','\xe0','\x98','\xc5','\xaf','\x4c','\x5a','\xb4','\x85','\x24','\x06','\x51','\x0b','\xc0','\xe6','\xcf','\x74','\x17','\x69','\xf4','\x44','\x30','\xc5','\x27','\x0f','\xda','\xe0','\xcb','\x84','\x9d','\x71','\xcb','\xab',};
	const char *digest51 = "99dc772e91ea02d9e421d552d61901016b9fd4ad2df4a8212c1ec5ba13893ab2";
	err |= test_sha256(vector51, len51, digest51);

	size_t len52 = 51;
	const char vector52[] = {'\x33','\xfd','\x9b','\xc1','\x7e','\x2b','\x27','\x1f','\xa0','\x4c','\x6b','\x93','\xc0','\xbd','\xea','\xe9','\x86','\x54','\xa7','\x68','\x2d','\x31','\xd9','\xb4','\xda','\xb7','\xe6','\xf3','\x2c','\xd5','\x8f','\x2f','\x14','\x8a','\x68','\xfb','\xe7','\xa8','\x8c','\x5a','\xb1','\xd8','\x8e','\xdc','\xcd','\xde','\xb3','\x0a','\xb2','\x1e','\x5e',};
	const char *digest52 = "cefdae1a3d75e792e8698d5e71f177cc761314e9ad5df9602c6e60ae65c4c267";
	err |= test_sha256(vector52, len52, digest52);

	size_t len53 = 52;
	const char vector53[] = {'\x77','\xa8','\x79','\xcf','\xa1','\x1d','\x7f','\xca','\xc7','\xa8','\x28','\x2c','\xc3','\x8a','\x43','\xdc','\xf3','\x76','\x43','\xcc','\x90','\x98','\x37','\x21','\x3b','\xd6','\xfd','\x95','\xd9','\x56','\xb2','\x19','\xa1','\x40','\x6c','\xbe','\x73','\xc5','\x2c','\xd5','\x6c','\x60','\x0e','\x55','\xb7','\x5b','\xc3','\x7e','\xa6','\x96','\x41','\xbc',};
	const char *digest53 = "c99d64fa4dadd4bc8a389531c68b4590c6df0b9099c4d583bc00889fb7b98008";
	err |= test_sha256(vector53, len53, digest53);

	size_t len54 = 53;
	const char vector54[] = {'\x45','\xa3','\xe6','\xb8','\x65','\x27','\xf2','\x0b','\x45','\x37','\xf5','\xaf','\x96','\xcf','\xc5','\xad','\x87','\x77','\xa2','\xdd','\xe6','\xcf','\x75','\x11','\x88','\x6c','\x55','\x90','\xec','\xe2','\x4f','\xc6','\x1b','\x22','\x67','\x39','\xd2','\x07','\xda','\xbf','\xe3','\x2b','\xa6','\xef','\xd9','\xff','\x4c','\xd5','\xdb','\x1b','\xd5','\xea','\xd3',};
	const char *digest54 = "4d12a849047c6acd4b2eee6be35fa9051b02d21d50d419543008c1d82c427072";
	err |= test_sha256(vector54, len54, digest54);

	size_t len55 = 54;
	const char vector55[] = {'\x25','\x36','\x2a','\x4b','\x9d','\x74','\xbd','\xe6','\x12','\x8c','\x4f','\xdc','\x67','\x23','\x05','\x90','\x09','\x47','\xbc','\x3a','\xda','\x9d','\x9d','\x31','\x6e','\xbc','\xf1','\x66','\x7a','\xd4','\x36','\x31','\x89','\x93','\x72','\x51','\xf1','\x49','\xc7','\x2e','\x06','\x4a','\x48','\x60','\x8d','\x94','\x0b','\x75','\x74','\xb1','\x7f','\xef','\xc0','\xdf',};
	const char *digest55 = "f8e4ccab6c979229f6066cc0cb0cfa81bb21447c16c68773be7e558e9f9d798d";
	err |= test_sha256(vector55, len55, digest55);

	size_t len56 = 55;
	const char vector56[] = {'\x3e','\xbf','\xb0','\x6d','\xb8','\xc3','\x8d','\x5b','\xa0','\x37','\xf1','\x36','\x3e','\x11','\x85','\x50','\xaa','\xd9','\x46','\x06','\xe2','\x68','\x35','\xa0','\x1a','\xf0','\x50','\x78','\x53','\x3c','\xc2','\x5f','\x2f','\x39','\x57','\x3c','\x04','\xb6','\x32','\xf6','\x2f','\x68','\xc2','\x94','\xab','\x31','\xf2','\xa3','\xe2','\xa1','\xa0','\xd8','\xc2','\xbe','\x51',};
	const char *digest56 = "6595a2ef537a69ba8583dfbf7f5bec0ab1f93ce4c8ee1916eff44a93af5749c4";
	err |= test_sha256(vector56, len56, digest56);

	size_t len57 = 56;
	const char vector57[] = {'\x2d','\x52','\x44','\x7d','\x12','\x44','\xd2','\xeb','\xc2','\x86','\x50','\xe7','\xb0','\x56','\x54','\xba','\xd3','\x5b','\x3a','\x68','\xee','\xdc','\x7f','\x85','\x15','\x30','\x6b','\x49','\x6d','\x75','\xf3','\xe7','\x33','\x85','\xdd','\x1b','\x00','\x26','\x25','\x02','\x4b','\x81','\xa0','\x2f','\x2f','\xd6','\xdf','\xfb','\x6e','\x6d','\x56','\x1c','\xb7','\xd0','\xbd','\x7a',};
	const char *digest57 = "cfb88d6faf2de3a69d36195acec2e255e2af2b7d933997f348e09f6ce5758360";
	err |= test_sha256(vector57, len57, digest57);

	size_t len58 = 57;
	const char vector58[] = {'\x4c','\xac','\xe4','\x22','\xe4','\xa0','\x15','\xa7','\x54','\x92','\xb3','\xb3','\xbb','\xfb','\xdf','\x37','\x58','\xea','\xff','\x4f','\xe5','\x04','\xb4','\x6a','\x26','\xc9','\x0d','\xac','\xc1','\x19','\xfa','\x90','\x50','\xf6','\x03','\xd2','\xb5','\x8b','\x39','\x8c','\xad','\x6d','\x6d','\x9f','\xa9','\x22','\xa1','\x54','\xd9','\xe0','\xbc','\x43','\x89','\x96','\x82','\x74','\xb0',};
	const char *digest58 = "4d54b2d284a6794581224e08f675541c8feab6eefa3ac1cfe5da4e03e62f72e4";
	err |= test_sha256(vector58, len58, digest58);

	size_t len59 = 58;
	const char vector59[] = {'\x86','\x20','\xb8','\x6f','\xbc','\xaa','\xce','\x4f','\xf3','\xc2','\x92','\x1b','\x84','\x66','\xdd','\xd7','\xba','\xca','\xe0','\x7e','\xef','\xef','\x69','\x3c','\xf1','\x77','\x62','\xdc','\xab','\xb8','\x9a','\x84','\x01','\x0f','\xc9','\xa0','\xfb','\x76','\xce','\x1c','\x26','\x59','\x3a','\xd6','\x37','\xa6','\x12','\x53','\xf2','\x24','\xd1','\xb1','\x4a','\x05','\xad','\xdc','\xca','\xbe',};
	const char *digest59 = "dba490256c9720c54c612a5bd1ef573cd51dc12b3e7bd8c6db2eabe0aacb846b";
	err |= test_sha256(vector59, len59, digest59);

	size_t len60 = 59;
	const char vector60[] = {'\xd1','\xbe','\x3f','\x13','\xfe','\xba','\xfe','\xfc','\x14','\x41','\x4d','\x9f','\xb7','\xf6','\x93','\xdb','\x16','\xdc','\x1a','\xe2','\x70','\xc5','\xb6','\x47','\xd8','\x0d','\xa8','\x58','\x35','\x87','\xc1','\xad','\x8c','\xb8','\xcb','\x01','\x82','\x43','\x24','\x41','\x1c','\xa5','\xac','\xe3','\xca','\x22','\xe1','\x79','\xa4','\xff','\x49','\x86','\xf3','\xf2','\x11','\x90','\xf3','\xd7','\xf3',};
	const char *digest60 = "02804978eba6e1de65afdbc6a6091ed6b1ecee51e8bff40646a251de6678b7ef";
	err |= test_sha256(vector60, len60, digest60);

	size_t len61 = 60;
	const char vector61[] = {'\xf4','\x99','\xcc','\x3f','\x6e','\x3c','\xf7','\xc3','\x12','\xff','\xdf','\xba','\x61','\xb1','\x26','\x0c','\x37','\x12','\x9c','\x1a','\xfb','\x39','\x10','\x47','\x19','\x33','\x67','\xb7','\xb2','\xed','\xeb','\x57','\x92','\x53','\xe5','\x1d','\x62','\xba','\x6d','\x91','\x1e','\x7b','\x81','\x8c','\xca','\xe1','\x55','\x3f','\x61','\x46','\xea','\x78','\x0f','\x78','\xe2','\x21','\x9f','\x62','\x93','\x09',};
	const char *digest61 = "0b66c8b4fefebc8dc7da0bbedc1114f228aa63c37d5c30e91ab500f3eadfcec5";
	err |= test_sha256(vector61, len61, digest61);

	size_t len62 = 61;
	const char vector62[] = {'\x6d','\xd6','\xef','\xd6','\xf6','\xca','\xa6','\x3b','\x72','\x9a','\xa8','\x18','\x6e','\x30','\x8b','\xc1','\xbd','\xa0','\x63','\x07','\xc0','\x5a','\x2c','\x0a','\xe5','\xa3','\x68','\x4e','\x6e','\x46','\x08','\x11','\x74','\x86','\x90','\xdc','\x2b','\x58','\x77','\x59','\x67','\xcf','\xcc','\x64','\x5f','\xd8','\x20','\x64','\xb1','\x27','\x9f','\xdc','\xa7','\x71','\x80','\x3d','\xb9','\xdc','\xa0','\xff','\x53',};
	const char *digest62 = "c464a7bf6d180de4f744bb2fe5dc27a3f681334ffd54a9814650e60260a478e3";
	err |= test_sha256(vector62, len62, digest62);

	size_t len63 = 62;
	const char vector63[] = {'\x65','\x11','\xa2','\x24','\x2d','\xdb','\x27','\x31','\x78','\xe1','\x9a','\x82','\xc5','\x7c','\x85','\xcb','\x05','\xa6','\x88','\x7f','\xf2','\x01','\x4c','\xf1','\xa3','\x1c','\xb9','\xba','\x5d','\xf1','\x69','\x5a','\xad','\xb2','\x5c','\x22','\xb3','\xc5','\xed','\x51','\xc1','\x0d','\x04','\x7d','\x25','\x6b','\x8e','\x34','\x42','\x84','\x2a','\xe4','\xe6','\xc5','\x25','\xf8','\xd7','\xa5','\xa9','\x44','\xaf','\x2a',};
	const char *digest63 = "d6859c0b5a0b66376a24f56b2ab104286ed0078634ba19112ace0d6d60a9c1ae";
	err |= test_sha256(vector63, len63, digest63);

	size_t len64 = 63;
	const char vector64[] = {'\xe2','\xf7','\x6e','\x97','\x60','\x6a','\x87','\x2e','\x31','\x74','\x39','\xf1','\xa0','\x3f','\xcd','\x92','\xe6','\x32','\xe5','\xbd','\x4e','\x7c','\xbc','\x4e','\x97','\xf1','\xaf','\xc1','\x9a','\x16','\xfd','\xe9','\x2d','\x77','\xcb','\xe5','\x46','\x41','\x6b','\x51','\x64','\x0c','\xdd','\xb9','\x2a','\xf9','\x96','\x53','\x4d','\xfd','\x81','\xed','\xb1','\x7c','\x44','\x24','\xcf','\x1a','\xc4','\xd7','\x5a','\xce','\xeb',};
	const char *digest64 = "18041bd4665083001fba8c5411d2d748e8abbfdcdfd9218cb02b68a78e7d4c23";
	err |= test_sha256(vector64, len64, digest64);

	size_t len65 = 64;
	const char vector65[] = {'\x5a','\x86','\xb7','\x37','\xea','\xea','\x8e','\xe9','\x76','\xa0','\xa2','\x4d','\xa6','\x3e','\x7e','\xd7','\xee','\xfa','\xd1','\x8a','\x10','\x1c','\x12','\x11','\xe2','\xb3','\x65','\x0c','\x51','\x87','\xc2','\xa8','\xa6','\x50','\x54','\x72','\x08','\x25','\x1f','\x6d','\x42','\x37','\xe6','\x61','\xc7','\xbf','\x4c','\x77','\xf3','\x35','\x39','\x03','\x94','\xc3','\x7f','\xa1','\xa9','\xf9','\xbe','\x83','\x6a','\xc2','\x85','\x09',};
	const char *digest65 = "42e61e174fbb3897d6dd6cef3dd2802fe67b331953b06114a65c772859dfc1aa";
	err |= test_sha256(vector65, len65, digest65);

	return err;
}

DEFINE_TEST_FUNC(sha384, SHA384_Data);

int sha384(void)
{
	int err = 0;

	size_t len1 = 0;
	const char vector1[] = {'\x00',};
	const char *digest1 = "38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b";
	err |= test_sha384(vector1, len1, digest1);

	size_t len2 = 1;
	const char vector2[] = {'\xc5',};
	const char *digest2 = "b52b72da75d0666379e20f9b4a79c33a329a01f06a2fb7865c9062a28c1de860ba432edfd86b4cb1cb8a75b46076e3b1";
	err |= test_sha384(vector2, len2, digest2);

	size_t len3 = 2;
	const char vector3[] = {'\x6e','\xce',};
	const char *digest3 = "53d4773da50d8be4145d8f3a7098ff3691a554a29ae6f652cc7121eb8bc96fd2210e06ae2fa2a36c4b3b3497341e70f0";
	err |= test_sha384(vector3, len3, digest3);

	size_t len4 = 3;
	const char vector4[] = {'\x1f','\xa4','\xd5',};
	const char *digest4 = "e4ca4663dff189541cd026dcc056626419028774666f5b379b99f4887c7237bdbd3bea46d5388be0efc2d4b7989ab2c4";
	err |= test_sha384(vector4, len4, digest4);

	size_t len5 = 4;
	const char vector5[] = {'\x50','\xe3','\x85','\x3d',};
	const char *digest5 = "936a3c3991716ba4c413bc03de20f5ce1c63703b3a5bdb6ab558c9ff70d537e46eb4a15d9f2c85e68d8678de5682695e";
	err |= test_sha384(vector5, len5, digest5);

	size_t len6 = 5;
	const char vector6[] = {'\x4b','\x5f','\xab','\x61','\xe0',};
	const char *digest6 = "fb390aa5b70b068a54d6d5127df6a6227becc4d6f891fd3f6068b917a883c9b66f318fddb6384d10be8c7af0d3132f03";
	err |= test_sha384(vector6, len6, digest6);

	size_t len7 = 6;
	const char vector7[] = {'\xda','\xd9','\x5a','\x4b','\x4d','\x37',};
	const char *digest7 = "3a2b40f453925bc3ce17d640757ee0e899390b4a8d984d0297c1bae6b60b9f2603bf71c323fd171011372335e5702e40";
	err |= test_sha384(vector7, len7, digest7);

	size_t len8 = 7;
	const char vector8[] = {'\x12','\x18','\x35','\xfe','\x37','\x00','\xb7',};
	const char *digest8 = "7bd06a94acba7beb3c5a9b9e8769c3da6691c482d78b1e5c7619b36630eba4e596d11c410a4c87006f4716b6f17bb9a0";
	err |= test_sha384(vector8, len8, digest8);

	size_t len9 = 8;
	const char vector9[] = {'\xde','\x60','\x27','\x5b','\xda','\xfc','\xe4','\xb1',};
	const char *digest9 = "a3d861d866c1362423eb21c6bec8e44b74ce993c55baa2b6640567560ebecdaeda07183dbbbd95e0f522caee5ddbdaf0";
	err |= test_sha384(vector9, len9, digest9);

	size_t len10 = 9;
	const char vector10[] = {'\x8d','\x45','\xa5','\x5d','\x5c','\xe1','\xf9','\x28','\xe6',};
	const char *digest10 = "de76683575a050e2eb5ef95ee201f82416478a1d14bf3d96d1fd4efd52b1a28fed8dfee1830070001dc102a21f761d20";
	err |= test_sha384(vector10, len10, digest10);

	size_t len11 = 10;
	const char vector11[] = {'\x5c','\x7d','\xde','\x9b','\x38','\x94','\xd7','\x3c','\xef','\xe1',};
	const char *digest11 = "f31b22115fa7178e78223e06aae870547ab93c6eb3c3910b0ee16e6106db55935d6c0eb820132a2078ece1067efc81c3";
	err |= test_sha384(vector11, len11, digest11);

	size_t len12 = 11;
	const char vector12[] = {'\x96','\x7f','\xa3','\x4c','\x07','\xe4','\x94','\x5a','\x77','\x05','\x1a',};
	const char *digest12 = "f8f24d81c4f8f23ecb42d76ed5d2b34c9cbc1f0a97234d1114804b5999759f3131c741d5768cc928163503c5f55f594b";
	err |= test_sha384(vector12, len12, digest12);

	size_t len13 = 12;
	const char vector13[] = {'\x22','\x09','\x11','\x2e','\xe7','\x79','\xbf','\x6d','\x95','\x71','\x11','\x05',};
	const char *digest13 = "09c54bf533a26c7447caa5783db2ec7ef5e55752da7f2a2c4e360982a94ec1ca2cb6a157d34eed28de978b4145e17ebc";
	err |= test_sha384(vector13, len13, digest13);

	size_t len14 = 13;
	const char vector14[] = {'\x20','\x44','\x2e','\x1c','\x3f','\x3c','\x88','\x91','\x9c','\x39','\x97','\x8b','\x78',};
	const char *digest14 = "50bc95b036e0f54d833032a80d45c2ac38b3d29e9c7f72a2eb14781e9241d2a4b8e8dba6ee6f4c9e46a758d5712dbd39";
	err |= test_sha384(vector14, len14, digest14);

	size_t len15 = 14;
	const char vector15[] = {'\x4d','\x43','\x70','\x2b','\xe4','\xf0','\x53','\x03','\x19','\x55','\x5d','\x7f','\x1a','\x33',};
	const char *digest15 = "83c8f0bb762801eb26cc5115abebb657c18ff811de500b32b7a568a220a287e900b6c75224fe7429169fbd534cb588e1";
	err |= test_sha384(vector15, len15, digest15);

	size_t len16 = 15;
	const char vector16[] = {'\x5e','\x2a','\x79','\xa5','\x44','\xaf','\x85','\xf1','\x50','\xf7','\xa9','\xd2','\x09','\xfd','\x44',};
	const char *digest16 = "8051ebc9cabb052cabe07e4023e2140808b77d25b07b96d2e3c22393f71b116c1a1e41bf62e57f73ff67871da7c93cf9";
	err |= test_sha384(vector16, len16, digest16);

	size_t len17 = 16;
	const char vector17[] = {'\xe1','\xbb','\x96','\x7b','\x5d','\x37','\x9a','\x4a','\xa3','\x90','\x50','\x27','\x4d','\x09','\xbd','\x93',};
	const char *digest17 = "3b04f96965ad2fbabd4df25d5d8c95589d069c312ee48539090b2d7b495d2446c31eb2b8f8ffb3012bdce065323d9f48";
	err |= test_sha384(vector17, len17, digest17);

	size_t len18 = 17;
	const char vector18[] = {'\xbb','\x84','\xa0','\x14','\xcd','\x17','\xcc','\x23','\x2c','\x98','\xae','\x8b','\x07','\x09','\x91','\x7e','\x9d',};
	const char *digest18 = "85227ae057f2082adf178cae996449100b6a3119e4c415a99e25be6ef20ba8c0eae818d60f71c5c83ff2d4c59aa75263";
	err |= test_sha384(vector18, len18, digest18);

	size_t len19 = 18;
	const char vector19[] = {'\xc3','\x41','\x1a','\x05','\x92','\xf1','\xf4','\xfa','\x69','\x88','\x15','\x23','\x89','\x97','\xdb','\x35','\x64','\x18',};
	const char *digest19 = "233ac44170d9f452a1a0231622030b15c104ff8ecaa3fccdb9e9e5031fd5b4220186a8edd032849c8b93dc183a5c8627";
	err |= test_sha384(vector19, len19, digest19);

	size_t len20 = 19;
	const char vector20[] = {'\xe8','\x31','\xb7','\x39','\xe8','\xeb','\x9f','\x78','\x7f','\x63','\xc0','\xbb','\x07','\x1d','\xdc','\xc9','\xf4','\x4c','\xab',};
	const char *digest20 = "91722d4b7aecc211bb8a5480c6855f3b71be4647e1dde0380c23afaa03f45c642606a24506e0317bf51506a483de28ac";
	err |= test_sha384(vector20, len20, digest20);

	size_t len21 = 20;
	const char vector21[] = {'\xb8','\xa7','\xbb','\xcc','\xde','\x46','\xe8','\x5f','\x12','\x23','\x23','\x7d','\x93','\x53','\xb7','\x8c','\x3b','\x19','\x72','\x7b',};
	const char *digest21 = "28ba69dc05e6e29de91924114d6c9fc7612f6d2a68b07fa001df059bcf98f7aa85389caeb966eaa299c79fe1fd1e40e3";
	err |= test_sha384(vector21, len21, digest21);

	size_t len22 = 21;
	const char vector22[] = {'\xcf','\x39','\x1b','\x8a','\xab','\xec','\x6f','\x81','\x28','\x8c','\x8b','\x7b','\x92','\x84','\x3b','\xe2','\x3d','\x2e','\x84','\x75','\x74',};
	const char *digest22 = "121e5ef697df491a53d7bae121416aa653d759a37db9d0b993031b18a0ef160ed98842a291e1ba2cea8b998bc5eee0b1";
	err |= test_sha384(vector22, len22, digest22);

	size_t len23 = 22;
	const char vector23[] = {'\x9d','\x65','\xd8','\x8b','\xff','\xed','\x76','\x4c','\x28','\x6f','\x34','\x89','\x4f','\x99','\x16','\x00','\xd1','\xa6','\x7d','\x62','\x23','\x82',};
	const char *digest23 = "84b6e0d6a45329daf47a793418ed5dbde01336b4b9468bb69e5da61c42b691e6794e6ed0e8fb1b8e7d4cd3cbaadc520a";
	err |= test_sha384(vector23, len23, digest23);

	size_t len24 = 23;
	const char vector24[] = {'\xba','\xb6','\xea','\x46','\xfb','\x71','\x7f','\x73','\xf0','\x62','\x81','\x32','\xa2','\xb9','\x6b','\xe3','\x83','\x77','\x4f','\x1e','\x5d','\x8b','\x6d',};
	const char *digest24 = "e969aca1b50e928cad29a0d756457f6de8d7a4e589fd41e53a1e758c3b20f9b81b36bf098a49102fbf869651ca9a98b5";
	err |= test_sha384(vector24, len24, digest24);

	size_t len25 = 24;
	const char vector25[] = {'\x88','\x53','\xb0','\x0e','\x86','\x97','\x64','\xad','\xb5','\x27','\xa0','\x7b','\x07','\x3c','\x85','\xa2','\x4e','\x6c','\x20','\x8b','\xa4','\x7e','\xef','\x4e',};
	const char *digest25 = "09ad44e85ac190e2d1c3ceb4efbea10ded34d0de961fe4ee268132c48e38660e6cf585bfffb8f7b00b0fad1514312b63";
	err |= test_sha384(vector25, len25, digest25);

	size_t len26 = 25;
	const char vector26[] = {'\x71','\xfe','\x1b','\xa5','\xd2','\x99','\x49','\x5d','\x2a','\x56','\x03','\x9c','\x64','\x03','\x2e','\xc6','\x26','\x3d','\x43','\x7f','\x55','\xe3','\xf5','\xbe','\xdb',};
	const char *digest26 = "b41a5d3b4af6d4b9c349e0788538e9a0311086894df7b72cf5aaf4091a7e039e4e89cc77a123474e6d1bac438e5e9f88";
	err |= test_sha384(vector26, len26, digest26);

	size_t len27 = 26;
	const char vector27[] = {'\x4e','\xbe','\x07','\xd0','\x3c','\x93','\xe8','\x49','\xb4','\xbb','\xfe','\x9f','\x2d','\x22','\x94','\xbf','\x6c','\xca','\xb4','\x57','\xf7','\x6d','\x3f','\x99','\xcb','\x64',};
	const char *digest27 = "beba464d7065185587fad89bfcea9635bf0ab775c3eb8c147b5b2bd8601db6dba0590b50dd1068733f20dc68e004a090";
	err |= test_sha384(vector27, len27, digest27);

	size_t len28 = 27;
	const char vector28[] = {'\x91','\x8a','\xc0','\xa9','\x7e','\xc1','\x63','\x29','\x08','\x48','\x9e','\x52','\x42','\xba','\x28','\x4b','\xc8','\x11','\xaa','\x71','\x97','\x24','\x2c','\xf7','\x22','\x6f','\xcd',};
	const char *digest28 = "c4baf6397a4c6e26492b63a4aab7dffdd0051d8f51938ac24cfd8dae2f7afed1a4aa2430d7aeb0be2a72b21a6c50198c";
	err |= test_sha384(vector28, len28, digest28);

	size_t len29 = 28;
	const char vector29[] = {'\x97','\x47','\x7f','\x72','\x72','\xd8','\xa8','\x9e','\x38','\xe7','\x96','\xc5','\x33','\xe9','\xf8','\xa8','\xae','\x4c','\x92','\xcc','\xaa','\x5d','\x90','\x7e','\xd2','\x6a','\x1a','\x15',};
	const char *digest29 = "d1ad524ebe908d7c5aff50e6cb780fd3a70e87c914a36b93c4e35f5b2cb03850b122b480ef8587d4a44f22467f4c480c";
	err |= test_sha384(vector29, len29, digest29);

	size_t len30 = 29;
	const char vector30[] = {'\x71','\x8e','\x0c','\xfe','\x13','\x86','\xcb','\x14','\x21','\xb4','\x79','\x9b','\x15','\x78','\x8b','\x86','\x2b','\xf0','\x3a','\x80','\x72','\xbb','\x30','\xd0','\x23','\x03','\x88','\x80','\x32',};
	const char *digest30 = "6d8b8a5bc7ea365ea07f11d3b12e95872a9633684752495cc431636caf1b273a35321044af31c974d8575d38711f56c6";
	err |= test_sha384(vector30, len30, digest30);

	size_t len31 = 30;
	const char vector31[] = {'\xd3','\xb0','\x7f','\x0f','\xd5','\xd4','\xcd','\x31','\x88','\xae','\xad','\x8d','\xc8','\x33','\x8d','\xe4','\x20','\x56','\xe2','\xe8','\x48','\x7e','\xca','\x51','\xec','\x37','\xef','\x2d','\xaf','\x27',};
	const char *digest31 = "adcc2e954c91db3db2d71d0dee1f030e723bee1a23816fe003ac5dc862a0872ef51ff386c18be6ebcaa493f32d1195b9";
	err |= test_sha384(vector31, len31, digest31);

	size_t len32 = 31;
	const char vector32[] = {'\x69','\x5b','\x9e','\xfe','\x18','\x09','\xab','\xd5','\xd4','\x4e','\xae','\x95','\x7d','\xdf','\x9c','\x2c','\xd3','\xc7','\x5f','\xae','\x2f','\x52','\x28','\x55','\x71','\x2a','\x07','\xc6','\x39','\xc0','\xb9',};
	const char *digest32 = "3bb95d164d94595a1187f77fc26c280ffbb08e74ec7947aa3e5b38bec7c6f8115c4d880788c2402dbb3e5b94afd130ee";
	err |= test_sha384(vector32, len32, digest32);

	size_t len33 = 32;
	const char vector33[] = {'\xbe','\x01','\xe5','\x20','\xe6','\x9f','\x04','\x17','\x4c','\xcf','\x95','\x45','\x5b','\x1c','\x81','\x44','\x52','\x98','\x26','\x4d','\x9a','\xdc','\x49','\x58','\x57','\x4a','\x52','\x84','\x3d','\x95','\xb8','\xba',};
	const char *digest33 = "c5cf54b8e3105b1c7bf7a43754d915b0947f28b6dc94a019182929b5c848e11441c9e4e90c7449f4c3cd12954f0f5d99";
	err |= test_sha384(vector33, len33, digest33);

	size_t len34 = 33;
	const char vector34[] = {'\x98','\xef','\x73','\x01','\xf9','\x57','\xd7','\x3d','\x4e','\x82','\x1d','\x58','\x73','\xe8','\xa9','\xb5','\x97','\x0f','\xbd','\x21','\x9d','\x5c','\xf7','\x4e','\xc2','\x29','\x1b','\x83','\x81','\x18','\x13','\x91','\xb4',};
	const char *digest34 = "b2564bbb159c3aeadbae0e4a4437f7c5111020e9ad0f4eb508147a961ac22a01e1a26df046b14ee5e8a49d9ed22b8cd1";
	err |= test_sha384(vector34, len34, digest34);

	size_t len35 = 34;
	const char vector35[] = {'\x87','\x3b','\xa7','\xf8','\xb7','\x15','\x17','\xec','\x50','\x29','\x7b','\x21','\xcf','\x94','\xcd','\xb7','\xa5','\x8a','\xbb','\xb8','\x82','\x92','\x06','\xf0','\xd3','\xf3','\x28','\xff','\x8a','\x69','\x39','\xac','\x1d','\x1d',};
	const char *digest35 = "7405fdd557d2b5d4f65e9e85f508d3791495f1820d37cabfc8dbb74d7b41df8613d995c612d378dd88337e00951d0280";
	err |= test_sha384(vector35, len35, digest35);

	size_t len36 = 35;
	const char vector36[] = {'\xe3','\xbd','\x4b','\xc3','\xa6','\x0c','\xdd','\xd2','\x6c','\x20','\xaa','\x86','\x36','\x4b','\xd4','\x4f','\x4a','\x07','\xf3','\x30','\x28','\x25','\xad','\x0a','\xc1','\x27','\x88','\x1d','\xe4','\xea','\xfb','\xcc','\xf9','\x88','\xcb',};
	const char *digest36 = "199d5423a0e26438f4cea0081a89e0b6c84ca93f7c3120c8104b51c6edc04e0f6a203bb77d59973a7411a0efbe93a09d";
	err |= test_sha384(vector36, len36, digest36);

	size_t len37 = 36;
	const char vector37[] = {'\x87','\x16','\xe4','\xb8','\x6d','\xef','\xf9','\xda','\x2a','\x8e','\xd5','\x5b','\xaa','\x43','\x58','\x2a','\x75','\x86','\xec','\x9c','\xd3','\x8a','\xc3','\xa9','\x33','\x15','\x61','\x58','\xcd','\x8e','\x5b','\x78','\x87','\x58','\x5e','\x91',};
	const char *digest37 = "0d2306d9c0a8ce57bc7869b439376c07ce352a41d86ab6cf4a5654cccd5c724fe1b62b2c1101c986222f5264ab3fdd66";
	err |= test_sha384(vector37, len37, digest37);

	size_t len38 = 37;
	const char vector38[] = {'\xf8','\xa5','\x03','\xaa','\xa2','\x5e','\xf2','\xce','\xa2','\x5e','\x31','\x93','\x0c','\x3a','\x90','\xdb','\x46','\x8c','\xd3','\xa8','\x62','\xf4','\xa9','\x3a','\xab','\x5d','\xe2','\x77','\x7e','\x82','\xdc','\x90','\x5c','\xb0','\x3e','\xe2','\x3c',};
	const char *digest38 = "773ee958fe93dfd1b73af24d27ddce33144a9249d5a671682a56df30d0bbf92b9327130022075185d396de752959304f";
	err |= test_sha384(vector38, len38, digest38);

	size_t len39 = 38;
	const char vector39[] = {'\x66','\x90','\x25','\x17','\x5e','\xa9','\x17','\xcd','\xd7','\xa7','\x1f','\xf4','\xec','\x0c','\x45','\xbf','\x12','\x46','\xd2','\xa6','\xf0','\x31','\xc0','\x0b','\x71','\xde','\x70','\x1e','\x17','\x93','\x9b','\xfe','\x92','\x12','\x8b','\x21','\x91','\x1e',};
	const char *digest39 = "9ff6be3f02c7c5d0206f4b944c0843cb68bea8f9b7c8cc0b729503db5005c7cd5cb14e3457d8f5eabf733fca9084f16b";
	err |= test_sha384(vector39, len39, digest39);

	size_t len40 = 39;
	const char vector40[] = {'\xb3','\x5f','\xb2','\x26','\x2e','\xdf','\xa1','\x49','\x38','\xa0','\xfb','\xa0','\x3e','\xb2','\xa2','\x5d','\x37','\x79','\x74','\xb1','\x1f','\x55','\x64','\x91','\xa7','\x81','\xd0','\xba','\x2b','\x3c','\x0f','\xf3','\xe4','\x27','\x49','\x92','\x5f','\xef','\x8b',};
	const char *digest40 = "835b05a4bf00c2594c3c8c13da6c273a0d9efdea0da72b71b19d326bf5ce968c2e577a7d99fc0f985afd23b46423129d";
	err |= test_sha384(vector40, len40, digest40);

	size_t len41 = 40;
	const char vector41[] = {'\x9d','\x86','\xb4','\x5d','\xf8','\xd7','\xda','\xe0','\xcf','\x6b','\x0b','\xc2','\x08','\x66','\x6e','\xe1','\x16','\x3a','\x39','\xe6','\x11','\x6d','\x6d','\x24','\x0c','\x9d','\xc1','\xc3','\xa3','\xc1','\xdb','\x1d','\xd3','\xb1','\xc6','\x68','\x0f','\xe9','\xa1','\x96',};
	const char *digest41 = "a84c469c24696f81d7df4ee8cd76aa584f8c9960eaa9908d3e3ebc5eea7d0b50afdded39deb94fd59323a21a6539e93f";
	err |= test_sha384(vector41, len41, digest41);

	size_t len42 = 41;
	const char vector42[] = {'\x41','\x4f','\x56','\x19','\xf6','\xdf','\xd4','\x58','\x53','\xbb','\xab','\xd2','\x24','\xcc','\x30','\x5d','\x77','\x35','\x0a','\xd2','\x53','\x35','\x89','\x10','\xa7','\x4f','\x3a','\x43','\x81','\xa9','\xb8','\x66','\x80','\xb3','\xc4','\x06','\x8c','\x08','\x98','\x49','\xc4',};
	const char *digest42 = "848d481e3bbf5dd726f625cf6a444d995b36262c9f80d583b77accf1707e3f49bb3dc480a560694d769aa1ce65d69428";
	err |= test_sha384(vector42, len42, digest42);

	size_t len43 = 42;
	const char vector43[] = {'\xe2','\x65','\x83','\x24','\x82','\x1a','\xe7','\xb0','\xfa','\xa0','\xcd','\xd6','\x3e','\xe9','\xef','\xb9','\xfc','\xbe','\x82','\x09','\x2d','\x04','\x69','\x6f','\xeb','\x3d','\xa9','\x2c','\x82','\x52','\x1d','\xfd','\xc9','\x8f','\x6b','\x41','\xb3','\xef','\x36','\x5d','\x21','\x9a',};
	const char *digest43 = "3ea5d0799f1a4dcab9149a40ab74bec9c8d76d8e392c1e63e080ddec2ec535f80be9f00927be281ec97ac0c882bb0bbf";
	err |= test_sha384(vector43, len43, digest43);

	size_t len44 = 43;
	const char vector44[] = {'\x7e','\x80','\x27','\x1b','\xb5','\xf2','\xcc','\x7d','\xda','\xe4','\x15','\x86','\x58','\xe4','\xe8','\xd0','\x6e','\x04','\xa3','\x93','\x85','\xda','\x0e','\xca','\xc1','\xcb','\x8e','\x91','\xd6','\x8a','\x9b','\xd2','\x1d','\xdb','\x73','\x20','\xe7','\x9d','\x10','\xe3','\x11','\x07','\x58',};
	const char *digest44 = "fa00bc0359a642dcb3559656094eb2fd4f63bc57f0d34abff26df5c54cc63dbeb4eac75905296e7fb69f871e134083f6";
	err |= test_sha384(vector44, len44, digest44);

	size_t len45 = 44;
	const char vector45[] = {'\x43','\xd2','\x82','\x8e','\x86','\xf7','\x85','\x6b','\x78','\xc6','\x6c','\xfa','\x3d','\x60','\x23','\x87','\xc2','\x90','\x97','\x5a','\xfd','\x02','\x1a','\x8b','\x76','\xaf','\x09','\x18','\x06','\x9c','\xac','\x35','\xde','\xc4','\x5d','\xe3','\xcc','\x52','\xed','\xc4','\xba','\x14','\x43','\x2e',};
	const char *digest45 = "6c9e367e066032ce47ba2575565932002cc786f533c5551656abfe7391e7dcb5f9d9e047adace23d32f8acedfd0cafc5";
	err |= test_sha384(vector45, len45, digest45);

	size_t len46 = 45;
	const char vector46[] = {'\x3f','\x49','\xbb','\x64','\x5c','\xce','\xd7','\x53','\x0b','\x8b','\x82','\xe6','\xcf','\x07','\xfb','\xf6','\x70','\xf7','\xef','\x0b','\xa0','\x58','\x3d','\x16','\xde','\xba','\xfc','\x63','\x9b','\xdf','\xbf','\xc9','\x9b','\x84','\x17','\x24','\x9f','\x7f','\x5a','\x05','\x41','\x0a','\xa3','\xa7','\x1f',};
	const char *digest46 = "2b301a14647a67429cc3e7da02c4093a739640f7b47a305251d2855e75e09e60e262b279a073077d1fb6d0f04788f2b8";
	err |= test_sha384(vector46, len46, digest46);

	size_t len47 = 46;
	const char vector47[] = {'\x31','\xaa','\xc0','\x6a','\x59','\xb7','\x4b','\xf4','\x78','\x61','\x7c','\x16','\x37','\xfa','\x6c','\x55','\x93','\xdf','\x16','\x8b','\x8d','\x58','\xb1','\xe9','\x23','\xbf','\x3e','\x3d','\x80','\xe5','\x5d','\x71','\x70','\xb1','\x64','\x54','\x16','\x0a','\xb2','\x9e','\xe1','\xf7','\x41','\x2e','\xbc','\x05',};
	const char *digest47 = "ddd245c9b29ceac60506fb6bd6e8037889cb73d6ecc669fd129060a8a8f58971ac572d3ec9b44404f81381d0fd35a649";
	err |= test_sha384(vector47, len47, digest47);

	size_t len48 = 47;
	const char vector48[] = {'\xc1','\x0b','\x28','\x52','\x05','\x4d','\x80','\x34','\xe0','\x79','\x06','\xc7','\xfc','\xe3','\xce','\x99','\x40','\x23','\x21','\xa6','\x48','\xbb','\x88','\x1f','\x13','\xfb','\x27','\x6a','\xfc','\x22','\x4c','\x6a','\xec','\xc6','\x48','\x00','\xcd','\x76','\x7e','\xd2','\x42','\x9d','\xb9','\x4b','\x95','\xa9','\xc3',};
	const char *digest48 = "a44640fb4ce6dfd4a10290a0aecdb453054a9b54f2583e97bb7dc2b005e5fa2b4fda17b1f75902f51c18c0caad35833c";
	err |= test_sha384(vector48, len48, digest48);

	size_t len49 = 48;
	const char vector49[] = {'\xb1','\xee','\xef','\x32','\x4b','\x49','\x9f','\x19','\xeb','\xa3','\x22','\x21','\x5f','\xe3','\xce','\x19','\xc9','\xf0','\x00','\xb6','\x98','\xd2','\xb2','\xda','\xb7','\x14','\x50','\x15','\x04','\x6c','\xc8','\x6d','\x04','\x9e','\xe1','\x5a','\xd5','\x9d','\xcd','\x15','\x64','\xf3','\x01','\x12','\xe0','\x64','\x44','\xcb',};
	const char *digest49 = "38742d18bfa6e918b888d68d1034e61f65dec0759172c2dbf08cf1e132b217eaf4ec29e15db7f4b07e08a70cc5662012";
	err |= test_sha384(vector49, len49, digest49);

	size_t len50 = 49;
	const char vector50[] = {'\x79','\x0d','\xbb','\xa0','\x99','\x65','\xc9','\x77','\x4d','\xd6','\x0a','\x32','\xe0','\x10','\xc5','\x0d','\x6d','\x51','\x89','\x68','\xa2','\x20','\x14','\x1d','\xc3','\x3e','\x74','\x10','\xf2','\xda','\x6c','\x08','\xad','\x04','\x19','\xbd','\x98','\x64','\xd5','\x32','\x7d','\x2c','\x5c','\x44','\x91','\x4b','\x2e','\x83','\xf9',};
	const char *digest50 = "9174958bc8f4ed4731eced999bea2f63032f52bc8c46bcd903232f3fbc5046f0d6c203d43a078b822fc05101404f2635";
	err |= test_sha384(vector50, len50, digest50);

	size_t len51 = 50;
	const char vector51[] = {'\xf7','\xb5','\x77','\xf1','\x39','\x6b','\x23','\xc2','\x7e','\xb6','\x37','\xe5','\x3d','\x3d','\x92','\x46','\x02','\x70','\xb0','\x01','\xcc','\x61','\x2f','\xd3','\xb4','\xd6','\x8b','\xcd','\xd0','\x9c','\x2d','\x50','\x57','\x1e','\xa4','\x35','\x06','\x36','\x32','\x4c','\xc2','\x42','\x8a','\x08','\x7e','\x7b','\xd8','\x78','\x5f','\x82',};
	const char *digest51 = "80afe111e44ad9aff9e39c4cf9e6b4c520072b4550e62b1740160a04f8d530612dc098917a556b44977d0e73df518bee";
	err |= test_sha384(vector51, len51, digest51);

	size_t len52 = 51;
	const char vector52[] = {'\x73','\x70','\xd9','\xb4','\x53','\x93','\x69','\x55','\xb9','\xc9','\xd3','\x36','\xf4','\xb2','\x83','\x23','\x79','\x86','\x23','\x2d','\xe0','\x07','\xbf','\x41','\x2f','\xb4','\x26','\xff','\x5b','\x40','\x93','\xc8','\x0c','\x42','\x8c','\x19','\xa1','\x2e','\x0b','\x18','\x74','\x84','\xdc','\x6d','\x5f','\x47','\x46','\x53','\x7f','\xb1','\xed',};
	const char *digest52 = "6cd29159820d34e5706dd867e6363758d312660d4daca8d2abf677f234746e97a0a6224eb054066a0b74e18c70965368";
	err |= test_sha384(vector52, len52, digest52);

	size_t len53 = 52;
	const char vector53[] = {'\xe8','\x62','\x01','\x70','\xf0','\xf3','\x93','\x28','\xbd','\xf8','\x88','\x81','\x48','\xcf','\xd1','\x77','\x30','\xf3','\x14','\xea','\x68','\xd8','\xfe','\xa0','\x2d','\x16','\xd9','\x8a','\x3c','\xca','\x61','\x48','\x41','\x39','\xd3','\xee','\x92','\xb7','\x48','\x09','\x1d','\xc8','\x41','\xdd','\xa0','\x84','\x83','\xf1','\x18','\x40','\x25','\xce',};
	const char *digest53 = "29c408a6a5045f397b56dfb5292c7c16028c63f068e699b86a891ff8501208ec9398dbaf463c00f39af7b2cbe45bac15";
	err |= test_sha384(vector53, len53, digest53);

	size_t len54 = 53;
	const char vector54[] = {'\x75','\xd4','\x21','\x6b','\xad','\x77','\x94','\x3b','\xfe','\x82','\xbe','\x21','\x61','\x57','\x84','\x3b','\x0d','\xa0','\xfd','\x16','\xee','\xee','\x84','\x71','\x53','\xa0','\x0b','\x43','\xe7','\x07','\xb2','\xff','\xe2','\xc8','\x98','\x16','\x80','\x81','\xf0','\xbd','\xb3','\xaf','\x58','\xf2','\x14','\xcf','\x67','\xb9','\x20','\xc3','\x85','\xac','\xa1',};
	const char *digest54 = "0170357385a20865a8d30c2df39406903ff88c7f70fa1a7a5aaa86711d64046c432a1b139668ae5abed637d1dc4107b7";
	err |= test_sha384(vector54, len54, digest54);

	size_t len55 = 54;
	const char vector55[] = {'\x2f','\xa9','\x0c','\x22','\x10','\xe3','\x09','\x6c','\xae','\xd1','\x22','\xb7','\x4e','\xb9','\x55','\x99','\x77','\x12','\x0e','\x5d','\x9a','\x97','\xee','\xb3','\xf9','\x9b','\xcb','\xa6','\xc1','\x9c','\xf8','\xcf','\x79','\x1a','\xc6','\xc8','\xa0','\xa9','\x4a','\xe4','\x92','\x46','\x61','\x1d','\xac','\xe7','\xf2','\x4e','\xb0','\x56','\x73','\xa3','\x6b','\x3e',};
	const char *digest55 = "6c2ced3fae94dbd92f4170b63f1ff6fcd8194f60937b22b4f3c95fc9e104b77148f9bc6c16a890de86d9ef1554c96fa0";
	err |= test_sha384(vector55, len55, digest55);

	size_t len56 = 55;
	const char vector56[] = {'\xa8','\xde','\x55','\x17','\x0c','\x6d','\xc0','\xd8','\x0d','\xe3','\x2f','\x50','\x8b','\xf4','\x9b','\x70','\x46','\xae','\xea','\x4b','\x97','\x5a','\x51','\x1b','\x5e','\xa3','\xdc','\x85','\x3b','\xfa','\x4b','\x1e','\x01','\x38','\x20','\x2d','\x67','\x85','\xf6','\xb3','\x01','\x79','\x14','\xa8','\x6f','\x82','\x42','\x88','\xd5','\x86','\xdc','\x0e','\x8b','\xc9','\x24',};
	const char *digest56 = "2bc3b10c148200f7919b57afe1d7db773ffd235e04fec6897dd94f13ad9c437ef50900a40937f82a39daf2aa2b3dfd68";
	err |= test_sha384(vector56, len56, digest56);

	size_t len57 = 56;
	const char vector57[] = {'\xac','\xcd','\x9d','\x05','\xfb','\x7e','\xf3','\x04','\x34','\x70','\x83','\x61','\x37','\x55','\x4a','\xf1','\x17','\x44','\x0b','\x3c','\xcc','\xa7','\xa2','\x80','\x28','\x54','\x94','\xf9','\x0d','\xfa','\xea','\x60','\xdc','\xbf','\x40','\xb2','\x30','\x27','\x19','\x32','\xcd','\x38','\x75','\xb1','\xd3','\xdc','\xa6','\x0d','\x38','\x86','\x5f','\xf8','\x74','\x18','\x0e','\xfa',};
	const char *digest57 = "b9e02df93e9254180d6a15288d77088b5a5ce517644109b4e2532be315f08dee43491608a1127dcdf69397406e23d231";
	err |= test_sha384(vector57, len57, digest57);

	size_t len58 = 57;
	const char vector58[] = {'\x32','\xb8','\x35','\xc1','\x80','\xcc','\x40','\x06','\xc1','\x1a','\x61','\xc6','\x5b','\x03','\xc0','\x99','\x51','\x0e','\x1d','\x4f','\x0a','\x94','\xb6','\x3d','\x54','\xbd','\x6b','\xd5','\xa8','\xab','\x20','\x7a','\xb0','\xf4','\x63','\x92','\x06','\x56','\x4e','\xdc','\x3f','\xa6','\xaf','\x03','\x28','\x0a','\x67','\x74','\x4f','\x68','\x10','\x6d','\xc5','\x1e','\xe3','\x57','\x23',};
	const char *digest58 = "df97a1c5dda6f9dde749f213e429db84f0dcd481d43bf58e6142968d629ecf05b262830a7dac87f67f4383975f3e821d";
	err |= test_sha384(vector58, len58, digest58);

	size_t len59 = 58;
	const char vector59[] = {'\x94','\x09','\xf9','\xef','\xad','\xbf','\x19','\x0b','\x25','\x33','\x67','\x62','\x9f','\x8f','\x36','\x8c','\x9d','\x5a','\xc2','\x62','\xe9','\x4a','\xb8','\x6f','\x35','\x59','\xf9','\xa1','\xfe','\x1a','\x9b','\x44','\xb6','\x4e','\x31','\x31','\x21','\xb3','\x4d','\x43','\x00','\x1c','\x43','\x0b','\xed','\xc6','\x2f','\xc5','\x86','\xea','\x39','\x8a','\xcd','\x8f','\x17','\xc7','\xcf','\xa2',};
	const char *digest59 = "e1a69388ee6b6d234108ec29402cd0afd74957d990c7bdb544cf11e8eb2ccd170b6b5a74431be70364d7a31b926ff53c";
	err |= test_sha384(vector59, len59, digest59);

	size_t len60 = 59;
	const char vector60[] = {'\x28','\x95','\x86','\xba','\xf8','\xda','\xce','\xd5','\x0d','\xb1','\x4c','\x93','\x65','\x29','\xa0','\xa6','\x43','\x8e','\xb5','\xda','\x8d','\x3d','\x46','\x91','\x72','\xb6','\xa0','\x6f','\x4f','\xf3','\xa9','\x56','\xd4','\xf9','\x21','\x95','\x63','\xac','\x28','\x5c','\xb8','\xe7','\x00','\x74','\xcf','\xcc','\x15','\x2c','\x02','\x59','\x3a','\x97','\x73','\x3c','\x36','\xf4','\xa9','\xe9','\x7f',};
	const char *digest60 = "509e996c1e11611c243021b8b78f2ad90c5a9263bbf35910db7c8ec102aa7c518066fff8ce88562fec2cd6dfe04056ae";
	err |= test_sha384(vector60, len60, digest60);

	size_t len61 = 60;
	const char vector61[] = {'\x15','\x65','\x30','\xcd','\x6e','\xd3','\xba','\xf1','\xfd','\x72','\x32','\xc7','\xff','\x20','\x4f','\x3c','\x7d','\x4d','\x10','\x60','\x16','\xaf','\xa3','\xbd','\xff','\x37','\x86','\xe8','\x48','\x43','\xec','\x55','\x61','\x15','\x62','\x6f','\xdc','\x84','\xb2','\xe8','\x74','\xf1','\x07','\x4e','\x4f','\x7d','\x53','\xe0','\x80','\x79','\xee','\x9f','\xd0','\x1f','\x80','\xa8','\xbe','\x7f','\x20','\xc0',};
	const char *digest61 = "7b8a598029ca0ed475a72c0644ac81c63d72fd51305dada07b0ab4a29e47422f59e12643179269ca3d7d10446b372b2c";
	err |= test_sha384(vector61, len61, digest61);

	size_t len62 = 61;
	const char vector62[] = {'\x30','\x65','\x5a','\x6b','\x5a','\x59','\x65','\xdb','\x99','\x2e','\x72','\x48','\xd2','\x41','\x41','\x05','\x5e','\x98','\x8d','\x72','\x6a','\xbb','\x8e','\x72','\x9d','\xc5','\xc2','\x1f','\xfc','\xba','\xed','\xbc','\x0b','\x1b','\x5f','\xea','\x35','\xb8','\x75','\x1f','\x6e','\xc6','\x62','\x55','\x17','\x31','\x2f','\xff','\x22','\x34','\x01','\x41','\x76','\x26','\x9b','\x60','\x95','\x97','\x23','\x78','\x7c',};
	const char *digest62 = "cfaf443e95deeb3cc1910771a2c0692a54b18b3633dc5414e71ae08877f0804818f67f7196c52e26b762dd12bb7a86ca";
	err |= test_sha384(vector62, len62, digest62);

	size_t len63 = 62;
	const char vector63[] = {'\x34','\x5c','\x3c','\x02','\x2e','\x20','\x14','\x4e','\x13','\x56','\x04','\x07','\x87','\x62','\xef','\x5c','\x8a','\x8f','\x03','\x8c','\xf1','\xb1','\xd6','\xa9','\x17','\x09','\xb5','\x9d','\xd0','\x68','\x39','\x6a','\x9e','\x97','\x1a','\xb6','\x28','\xf7','\x48','\x86','\xe7','\x65','\x38','\x4a','\x23','\x60','\x7c','\x1a','\x1e','\x6e','\x97','\x3f','\x8f','\xbb','\x0f','\xf5','\x51','\x04','\xc4','\x6f','\x5d','\xb3',};
	const char *digest63 = "bfb1d5ee3a0b629058ecc521c706c2f9241c48cda3dcfdba660a2601d832a7a872a2bb840f3b98d21c37e28f9041a5b2";
	err |= test_sha384(vector63, len63, digest63);

	size_t len64 = 63;
	const char vector64[] = {'\x0b','\x94','\xa0','\xf4','\x3a','\x92','\x40','\x89','\x63','\xa5','\x9d','\xed','\x01','\xa9','\x33','\x82','\x83','\xa6','\xff','\x1b','\xfb','\xac','\xd9','\x05','\x1a','\x01','\x04','\x44','\x5c','\x7f','\x04','\x1e','\x80','\x37','\xaf','\xde','\x3b','\x5a','\x87','\xd2','\x2d','\x5a','\x47','\x96','\x14','\x4c','\xbc','\x94','\x40','\x91','\xd6','\xcc','\x47','\xb5','\xff','\xd1','\xf9','\x97','\xab','\x14','\x96','\xca','\x31',};
	const char *digest64 = "07a045c9590e9901d0598e604c4649554a823de996fa438cc81a634344eeb98e5f3c0c234ba30e2285a4d7ab568f2610";
	err |= test_sha384(vector64, len64, digest64);

	size_t len65 = 64;
	const char vector65[] = {'\x93','\x03','\x5d','\x3a','\x13','\xae','\x1b','\x06','\xdd','\x03','\x3e','\x76','\x4a','\xca','\x01','\x24','\x96','\x1d','\xa7','\x9c','\x36','\x6c','\x6c','\x75','\x6b','\xc4','\xbc','\xc1','\x18','\x50','\xa3','\xa8','\xd1','\x20','\x85','\x4f','\x34','\x29','\x0f','\xff','\x7c','\x8d','\x6d','\x83','\x53','\x1d','\xbd','\xd1','\xe8','\x1c','\xc4','\xed','\x42','\x46','\xe0','\x0b','\xd4','\x11','\x3e','\xf4','\x51','\x33','\x4d','\xaa',};
	const char *digest65 = "8d46cc84b6c2deb206aa5c861798798751a26ee74b1daf3a557c41aebd65adc027559f7cd92b255b374c83bd55568b45";
	err |= test_sha384(vector65, len65, digest65);

	size_t len66 = 65;
	const char vector66[] = {'\xbf','\xb9','\x4d','\xfb','\xe0','\xd9','\xa5','\x09','\xb7','\x8d','\x16','\x4a','\x72','\x20','\x50','\x05','\x4d','\xad','\x91','\xc9','\xa8','\xe2','\x60','\x54','\x5d','\x03','\x7e','\xb4','\x50','\x32','\x1a','\xac','\x48','\xed','\x44','\x59','\xfd','\xd8','\xa4','\x15','\x72','\xbd','\x6c','\x9c','\x84','\xd1','\x8b','\x6e','\xc3','\x39','\x24','\x74','\x82','\xcc','\x3e','\xe5','\x2a','\x1b','\xbd','\x6b','\xd4','\xae','\x91','\x82','\x16',};
	const char *digest66 = "13af0be02986ea3176e8c65534ec9f32c23b53c93a73b15c26b9ecbd8a1181ae184a372e9f5e0596cd6606849aeae8e0";
	err |= test_sha384(vector66, len66, digest66);

	size_t len67 = 66;
	const char vector67[] = {'\x1c','\x89','\x24','\xa1','\x6f','\xa7','\xc6','\x02','\xaf','\xf5','\xee','\x96','\x17','\x98','\xbd','\x44','\xfe','\x53','\x79','\x8b','\xf4','\x4c','\x3d','\x6b','\x0d','\x13','\xef','\x83','\x7d','\xe0','\x73','\x77','\x65','\x1c','\x1e','\x94','\xed','\x23','\x6e','\xb7','\x93','\x49','\xf8','\x6a','\xc3','\x1b','\xa1','\x51','\xa7','\xe7','\x11','\xc5','\x40','\x7e','\x65','\xbe','\xb6','\x38','\x24','\xf6','\xec','\x39','\x75','\x4b','\x58','\xf3',};
	const char *digest67 = "5be6482851ddafde582f2804071a702ae39bacb688741b7c37bbae99821ce4d3f47d5b097fd8eefa0ef9248a34f5d3ce";
	err |= test_sha384(vector67, len67, digest67);

	size_t len68 = 67;
	const char vector68[] = {'\x18','\x42','\x15','\x14','\x5d','\xa4','\x9d','\xb4','\x17','\xe8','\xbd','\xd5','\x73','\xd6','\x28','\x2d','\xe0','\x73','\xe6','\x74','\xc3','\xde','\xa8','\x6b','\x6c','\x78','\x59','\x1d','\x49','\x47','\xf5','\x65','\x5a','\x9d','\x9e','\xb0','\xe5','\xf4','\xed','\x04','\x6b','\x1d','\x86','\x42','\xda','\x9a','\xef','\xa8','\x04','\x48','\xa2','\x99','\x50','\x41','\x60','\xa1','\xb0','\x00','\xc9','\xb4','\xd3','\xc6','\x2a','\xb6','\x9b','\x3d','\x96',};
	const char *digest68 = "8995cd7fc0956e124075440686beece17a6256b282e7988a0c998f790e3995c974383179893477bcc32d1f114129b496";
	err |= test_sha384(vector68, len68, digest68);

	size_t len69 = 68;
	const char vector69[] = {'\xca','\x7a','\x63','\xad','\xf4','\x1f','\x4d','\xa3','\x31','\x42','\x91','\x0c','\x96','\x77','\x06','\xb5','\xc8','\xa0','\x93','\x35','\x0e','\xb3','\xe6','\xd3','\xaa','\xbe','\x69','\xa4','\x6a','\x28','\x72','\xf4','\x7a','\x39','\xbb','\xe7','\x7c','\xdc','\x11','\x60','\xda','\xa4','\x50','\x22','\x5b','\x0e','\x8e','\x36','\xf5','\x06','\x97','\x8c','\xe3','\xac','\x9a','\xe5','\xf7','\x57','\x21','\xef','\x30','\xda','\x46','\xb2','\x8f','\x07','\x24','\x2c',};
	const char *digest69 = "b89cc12b11e3afa58908580c47b25407abbf584f8e8d4b5631e9f450464c7e53cfd7e9f9d3cf35e587a6f02957ce4c28";
	err |= test_sha384(vector69, len69, digest69);

	size_t len70 = 69;
	const char vector70[] = {'\x1d','\xa4','\x1a','\x0a','\xf2','\x02','\xb0','\x79','\x52','\x1d','\xeb','\x61','\x09','\xe3','\x12','\xc2','\xad','\xe4','\x85','\x44','\xd2','\xb4','\x98','\xc0','\x7e','\x91','\xa1','\x02','\xdd','\x46','\x50','\xce','\x35','\x4f','\x3f','\x20','\x1b','\x3e','\xca','\xb8','\xe8','\x5e','\x21','\xd6','\x67','\x95','\x9b','\x43','\xd0','\x8f','\x4e','\x90','\xfa','\x18','\xdc','\xa2','\xcc','\xca','\x8f','\x6f','\xf5','\xe9','\xa9','\x02','\xdc','\x8b','\xf5','\xc5','\xda',};
	const char *digest70 = "5c297e20c307aab7f325939fd4e2883b034fd547f1dd17fb6b97ade8b148e06ebbf3ff60cbf469e4933d5f48f0166cb7";
	err |= test_sha384(vector70, len70, digest70);

	size_t len71 = 70;
	const char vector71[] = {'\xde','\xce','\x42','\xc8','\x84','\x9b','\xe4','\x0c','\x78','\xb8','\xde','\x6d','\xa9','\x6c','\x2a','\x8d','\x7e','\x94','\x05','\x45','\xb9','\xf3','\xf3','\x9a','\xa1','\xca','\x03','\xec','\x60','\xa8','\x54','\x71','\xaa','\x84','\xd8','\xe2','\x9f','\x09','\x58','\x74','\xf3','\x31','\xb9','\x0a','\x4c','\x15','\x7d','\xa9','\xeb','\x04','\x8d','\x2c','\x8f','\xd2','\x35','\x39','\x96','\x72','\x70','\x73','\x66','\xc7','\x66','\xf1','\x0b','\xb8','\x33','\xf0','\x21','\x83',};
	const char *digest71 = "bb509e33e9ffcc4c01233146226ee9364cdac5658132460a76edf617a035b197c86434ee889438581458102618769382";
	err |= test_sha384(vector71, len71, digest71);

	size_t len72 = 71;
	const char vector72[] = {'\x95','\x20','\x08','\xeb','\xde','\xdd','\x48','\x04','\x49','\xbb','\x96','\xa0','\x25','\x57','\x6c','\x5f','\x61','\x7b','\xbb','\x83','\x07','\x95','\x8a','\x01','\x07','\x67','\xe0','\xd7','\x36','\xff','\xe5','\xa1','\x96','\xea','\x44','\x67','\xd8','\xa5','\xd3','\xba','\x1f','\x54','\x76','\xff','\x07','\xb6','\x41','\x0a','\xe6','\x59','\xdc','\xef','\x52','\x0a','\x2c','\x14','\xe3','\x90','\x2f','\x8b','\x39','\x9a','\x28','\x9f','\x41','\xf5','\xfd','\xad','\xb5','\x02','\xdd',};
	const char *digest72 = "9b63d9145bc714a8253dcdb8341b2f5714eb58b9d4b22ce45aae07f51297a3dc9c5b691a8a3cd438dc5bd18be400af21";
	err |= test_sha384(vector72, len72, digest72);

	size_t len73 = 72;
	const char vector73[] = {'\x10','\x01','\x32','\xc3','\x15','\xbf','\xc9','\xc4','\xfb','\x93','\x02','\x3f','\x5d','\x35','\x00','\xd7','\x20','\x8a','\x68','\xac','\xb4','\xd2','\xc6','\x30','\x96','\x23','\x2c','\x36','\x1a','\x16','\x1c','\x4c','\x67','\xc0','\xa7','\x4b','\xc3','\xe4','\xd7','\x2c','\x11','\x66','\x4b','\x1d','\x97','\x03','\x21','\xd4','\x05','\x40','\x19','\x24','\xb3','\xa0','\xf6','\xce','\x2b','\x1a','\x28','\x99','\xe7','\xca','\xa9','\xa5','\x5c','\xe7','\x25','\xfc','\x37','\xf5','\x5d','\x6a',};
	const char *digest73 = "b6ca04467ed3e623dba36f2e0248cefbe134cf555fdc14731175eaaf08e244ab0b15fca2f173a0ec98feaf359fb84a11";
	err |= test_sha384(vector73, len73, digest73);

	size_t len74 = 73;
	const char vector74[] = {'\x99','\xcb','\xa4','\x01','\x9f','\x54','\x78','\x78','\x9e','\x67','\x4e','\x08','\xfe','\x5d','\x6c','\xea','\xdd','\x69','\x8b','\x07','\x57','\xca','\x39','\xc6','\x05','\x45','\x7c','\x22','\xc3','\xd3','\xb8','\xff','\xb7','\x97','\xd2','\xbe','\x8f','\x12','\x96','\x0f','\x09','\x9a','\x56','\x06','\xb9','\x08','\xd4','\x72','\x07','\xb2','\x63','\x6a','\x77','\x99','\x48','\x28','\x2d','\xe3','\x66','\x1b','\xb0','\x8b','\x1b','\x37','\xee','\x57','\x65','\x90','\x80','\x0a','\x49','\x27','\x30',};
	const char *digest74 = "e5378c7c251ae96f0359a30b3134fd77d61d0db68c42a1a2aac293195a596df42f677e6cb98abec90d6722baac63fc86";
	err |= test_sha384(vector74, len74, digest74);

	size_t len75 = 74;
	const char vector75[] = {'\xbb','\x32','\x7a','\x0b','\xcb','\x25','\x74','\xdf','\x47','\x08','\x0e','\x8c','\x0d','\x8a','\x45','\xee','\x1c','\x04','\x24','\xae','\x04','\x14','\xdc','\x0a','\x9b','\x87','\x17','\xd9','\xf2','\x7d','\x8a','\xc9','\x87','\xc7','\xc9','\xec','\xbc','\x94','\x60','\x73','\x88','\x4d','\x1f','\xb9','\x6d','\xbd','\xb5','\x83','\xaa','\x75','\x81','\x86','\xb1','\x6f','\xa4','\x29','\xdb','\xf1','\x5b','\x8d','\x5b','\xb4','\x8c','\xca','\x71','\x46','\x9e','\x7c','\xe0','\xad','\x8e','\x7f','\xa1','\x4d',};
	const char *digest75 = "0f75e65ff8494ae28d9a0a2e65959653275fc34b2fa27b9e10faafff07c45addef3b8f25953d5a2e54e31ebe6d429d26";
	err |= test_sha384(vector75, len75, digest75);

	size_t len76 = 75;
	const char vector76[] = {'\x7f','\xd9','\xee','\xb5','\xff','\x36','\x80','\x40','\xd2','\x99','\xfd','\x17','\xa9','\x43','\xb2','\x1d','\x65','\xde','\xb2','\xec','\xcf','\x61','\x28','\xd1','\x8a','\x33','\xeb','\x17','\x46','\x93','\x53','\x89','\x35','\x37','\x4c','\x32','\xc3','\x33','\xa8','\x67','\x82','\x1d','\xba','\x08','\x63','\x6f','\x20','\x02','\x2c','\x2c','\xe0','\x18','\x26','\xc7','\xb7','\xe4','\x16','\x40','\xad','\x18','\x6f','\x90','\xed','\x0a','\xc6','\x47','\xd4','\x70','\x86','\x74','\x48','\x67','\xe5','\xc5','\x4b',};
	const char *digest76 = "007251a2a577add048b1edc79d96c7df8fd5b5fa0d7264f122e4cb54c50bc316a8bc5f4f9dfd4469e29e9b030f563a6d";
	err |= test_sha384(vector76, len76, digest76);

	size_t len77 = 76;
	const char vector77[] = {'\x7c','\xa9','\xe3','\x69','\xe8','\x21','\x86','\x98','\x4d','\x5f','\xc7','\x29','\xe1','\x11','\xa7','\xe5','\xd8','\xec','\x19','\xc5','\xd7','\x4e','\x13','\xb5','\xab','\x22','\xe4','\x99','\x3b','\x05','\xc8','\x8e','\xbb','\xa6','\xba','\x72','\x23','\x73','\x89','\xa6','\xe0','\x72','\x2e','\x12','\xc9','\x6c','\x5d','\x6a','\x54','\x51','\x5a','\xb0','\x0a','\xd8','\x0e','\xfb','\x38','\x66','\x5a','\x76','\xe8','\x31','\xab','\xab','\x0f','\xa5','\xcf','\x02','\x08','\x07','\x07','\x84','\x41','\x58','\x5d','\xe5',};
	const char *digest77 = "3ee8c4184de9ceaecd0d3aea16271835f3d45c873358c93a515539c38e819414ea63b08d0a109346793d5e0f703125eb";
	err |= test_sha384(vector77, len77, digest77);

	size_t len78 = 77;
	const char vector78[] = {'\x5b','\x4d','\x94','\x5d','\x55','\xde','\xa2','\x2e','\x37','\x82','\x1e','\xc3','\x96','\x47','\x6a','\x4b','\xfb','\x61','\x7d','\x2f','\x39','\x2a','\xd9','\x3a','\xfe','\x67','\xbc','\xfd','\xa9','\xcd','\x9b','\x72','\x5b','\xc4','\xcc','\xdf','\x51','\x6a','\x83','\xfd','\x71','\xdb','\xff','\x5a','\x22','\xb0','\x05','\xfc','\x61','\xc5','\x8e','\x47','\x12','\x40','\xbd','\x21','\x93','\xce','\x13','\x53','\x97','\x30','\xe6','\x32','\x32','\xf7','\x0f','\x80','\x30','\x8b','\xe4','\x8d','\xab','\x72','\x66','\xa1','\xdd',};
	const char *digest78 = "df82d242e4cdc2eb40bf3db6a56e1aa0a66e553f1914bedc65c8cc6ad9564b6e85df59f4c443cbe4e0aee05986f7d690";
	err |= test_sha384(vector78, len78, digest78);

	size_t len79 = 78;
	const char vector79[] = {'\xe8','\x65','\xf4','\xa4','\x2b','\xbb','\xd0','\xb7','\x3f','\xe2','\x75','\xb8','\xab','\x90','\xd3','\xa9','\xfb','\x74','\xec','\x50','\x70','\x19','\x2d','\x38','\xf6','\x0e','\xfe','\xf9','\x56','\x44','\x98','\xb9','\xad','\xb7','\x16','\xf3','\x1d','\x50','\xcf','\x77','\xc2','\x0a','\xe4','\xb2','\xe8','\x55','\x15','\x30','\x7b','\xb8','\xd9','\x5f','\xbe','\xb9','\xad','\x96','\x40','\x01','\xac','\x55','\x0d','\xbc','\x60','\xcf','\x21','\x3f','\xd8','\xa5','\x22','\xed','\xfa','\xf5','\x4e','\x5b','\x1b','\x93','\xb2','\xb2',};
	const char *digest79 = "091fa9ae2184e2268ef9ef23c7c809efad244536e00aa9e8b3a6c228d90e31da051b40f268a13bd6f62e69c91ae8cd2d";
	err |= test_sha384(vector79, len79, digest79);

	size_t len80 = 79;
	const char vector80[] = {'\x1d','\x40','\x8c','\x7b','\x68','\xe1','\x68','\xf4','\x1b','\xb4','\x6f','\x9b','\x2e','\x9c','\x8b','\x04','\xf9','\x68','\xe4','\x08','\x02','\x52','\x54','\x68','\x14','\xcc','\x1c','\xb2','\x91','\x7d','\xd5','\x69','\x08','\x86','\xa9','\x60','\x0a','\x09','\xc2','\x67','\x3a','\xec','\x03','\x29','\xa4','\xda','\xf6','\x55','\x50','\x8b','\x06','\xfc','\x16','\x46','\xef','\x3b','\xb3','\xa4','\x72','\x19','\x1d','\x96','\x4d','\xb2','\x14','\xa9','\x6a','\x96','\xfa','\x89','\x57','\x6c','\xe4','\xc4','\xf6','\xdb','\xf1','\xd1','\x76',};
	const char *digest80 = "7e23472c03431925f3b4559d886e8d5d837b3d39b8efe1b7a91e61a13810c4dbc2439634d7c6ababfc66e9b18e6541db";
	err |= test_sha384(vector80, len80, digest80);

	size_t len81 = 80;
	const char vector81[] = {'\x54','\xae','\x03','\x0a','\x4e','\x27','\xa0','\x5c','\x1e','\xa4','\xa1','\x2e','\x69','\xc6','\x75','\x44','\xaf','\x9b','\x40','\x44','\xcf','\x15','\x7d','\xc8','\xce','\xbb','\xe8','\xb2','\xd4','\x9f','\x9b','\xc0','\x77','\x90','\x77','\x60','\x3c','\x90','\xc5','\xc5','\x5b','\x89','\x1d','\x3a','\xc3','\x3b','\x87','\xb6','\x5e','\x79','\xe1','\xb1','\x96','\x95','\x81','\x37','\x18','\x19','\x1b','\x3b','\xd8','\xb7','\xe4','\x2d','\x55','\x83','\xf7','\xcf','\x1e','\x60','\xf8','\x44','\x95','\xb8','\xf8','\x69','\xf3','\x71','\x99','\x69',};
	const char *digest81 = "cb65f823585773cb8802b6339182f13752a82864c898b445be5a11a969657ac2dc4a3bbeb87ac0abb232a2b124171096";
	err |= test_sha384(vector81, len81, digest81);

	size_t len82 = 81;
	const char vector82[] = {'\xf7','\x3c','\xd3','\x86','\xf7','\x3d','\x0c','\x6a','\xde','\x05','\x77','\x1b','\x33','\x11','\x71','\x17','\xc6','\x02','\xe5','\x26','\x93','\xf0','\x5b','\x47','\xe9','\x00','\x32','\xea','\xcc','\x39','\x29','\x5f','\x97','\x93','\x25','\x8f','\xe6','\x51','\x2e','\xea','\xb2','\x91','\xba','\xa0','\xbe','\x22','\x2e','\x14','\x32','\x95','\xa2','\x8e','\x86','\x97','\xe4','\x2f','\xa2','\x7e','\xc0','\x2b','\x44','\x21','\x7f','\x32','\xa1','\xed','\xae','\x2f','\x4f','\x35','\x21','\x35','\x62','\xca','\x37','\xb6','\xd6','\xcc','\x5e','\xf7','\x2d',};
	const char *digest82 = "f665c4d17a83d65a7ff16bfce279b58558250d76af68b8eb943753e411a57ceb31c1a131e54bcb7672584416e3d5719e";
	err |= test_sha384(vector82, len82, digest82);

	size_t len83 = 82;
	const char vector83[] = {'\x1d','\x25','\x96','\x12','\xe6','\x86','\x7e','\x7d','\x78','\x8c','\x71','\xd0','\x3c','\x51','\x36','\x86','\x4a','\xd6','\xd8','\x4f','\x24','\xea','\xf9','\x13','\xa3','\x4e','\x69','\x33','\x31','\x16','\xf8','\x12','\x39','\x52','\x88','\xd4','\xdc','\xee','\x66','\x65','\xe6','\xd7','\xda','\xbd','\x00','\x5f','\xfc','\x63','\x27','\xe3','\xca','\x30','\x5c','\xab','\x78','\x56','\x9d','\x11','\x07','\xa1','\x15','\xe6','\x19','\xfc','\x90','\x11','\x04','\x36','\x31','\x79','\x25','\x06','\x67','\x26','\x77','\x4d','\x1d','\xa3','\x63','\x9c','\x31','\xa6',};
	const char *digest83 = "5dcf512e2b93d6ecdf7c3304534554ea79d22392e59bbe90df21e978c9fa3b34ff82e6dcfe8fe2236aa4af4e662e2a9d";
	err |= test_sha384(vector83, len83, digest83);

	size_t len84 = 83;
	const char vector84[] = {'\xda','\x87','\x34','\x41','\x4c','\x45','\xfc','\x1d','\x5a','\x75','\xa3','\xcb','\xac','\xad','\xb1','\xbf','\xb5','\x23','\xd6','\xfc','\x39','\x1f','\x88','\x2d','\x0d','\xb0','\xee','\xf2','\x1f','\x9f','\xfd','\x78','\xb6','\xa1','\xe1','\x4c','\xfa','\xd0','\x9e','\x71','\xb6','\x5c','\xf7','\xb0','\x5d','\x7e','\x8f','\x2f','\x4b','\xae','\x4e','\x45','\x4e','\x16','\x06','\x8d','\x65','\x46','\x56','\x39','\xc7','\x29','\xcf','\xa9','\x27','\x38','\x56','\x3d','\x37','\xed','\xc9','\x67','\x6b','\x7b','\xe6','\x04','\xff','\xbc','\x68','\xec','\x3b','\x6b','\x72',};
	const char *digest84 = "8b328a31adf67dc7aeb864a359628410d5814a2f0cc683303f61432ce32177e1f538feead7e5000343916c7042f8b3cd";
	err |= test_sha384(vector84, len84, digest84);

	size_t len85 = 84;
	const char vector85[] = {'\xb2','\x28','\xc7','\x59','\x03','\xd8','\x0f','\xbc','\x6d','\x1c','\xf6','\x29','\xff','\x1d','\x14','\xa9','\x2e','\xc4','\xbf','\x0e','\x12','\x1f','\xd9','\x7b','\xd3','\x06','\xed','\x26','\x5e','\xfe','\x7a','\x5d','\x5c','\x5d','\x8f','\xc7','\x64','\xaf','\x98','\xed','\x6f','\x59','\x78','\xf8','\x8d','\x7c','\xd8','\xbc','\xd7','\x1c','\xbe','\xf6','\xa5','\x82','\x61','\xd2','\x01','\xde','\x3c','\xb1','\x5b','\x31','\x61','\x28','\x7e','\x6a','\x10','\x4c','\xc2','\xcf','\x88','\x2d','\x83','\x9f','\x1d','\xa0','\xd3','\xf6','\x8b','\x42','\x6c','\xf0','\x8a','\xb9',};
	const char *digest85 = "fc92ba4eac9a1bf120a7b6c2cc30335b9615b1a98e55d14854ff872966e71040737401c6bc08db5842ceace14cb7e7ea";
	err |= test_sha384(vector85, len85, digest85);

	size_t len86 = 85;
	const char vector86[] = {'\xc9','\x0d','\x47','\x3a','\x6f','\xd3','\x0b','\xe9','\xa9','\x8b','\xf4','\x42','\xa9','\xad','\x65','\xa6','\x97','\xd4','\x62','\x9c','\x33','\xcd','\x51','\x7d','\xbb','\xed','\x02','\x71','\x0f','\xa8','\xee','\x99','\x13','\x60','\xbc','\x8e','\x55','\x7b','\x0a','\x0b','\xf0','\xb8','\x69','\xe6','\xb0','\xc3','\xa9','\x45','\x76','\x07','\x58','\x0e','\xde','\xc3','\x85','\x9f','\x20','\x60','\xc9','\xc0','\x34','\x02','\x89','\xd5','\x3a','\x5d','\x75','\x59','\x18','\xca','\x54','\x87','\x65','\x99','\x04','\x5a','\x86','\xa9','\xbc','\xb8','\x16','\x37','\x95','\xea','\x8c',};
	const char *digest86 = "807582b2520e990cfb74367343268b9148b2519b9e7cd9182edb3db9ae7afebedfe8ca118130e2ef9d31af9081da8222";
	err |= test_sha384(vector86, len86, digest86);

	size_t len87 = 86;
	const char vector87[] = {'\x6d','\xf8','\xc5','\xc2','\x8d','\x17','\x28','\x97','\x5a','\x0b','\x76','\x6c','\xd7','\xde','\x63','\xbb','\xe7','\xf4','\x8c','\x3d','\xb3','\xe6','\xfd','\x5a','\x4b','\x8d','\xf6','\xe3','\x90','\x5c','\xef','\x03','\x51','\xf3','\xd9','\x73','\xb4','\xf2','\xa7','\xee','\xd8','\x0b','\x0d','\xe5','\xb8','\x5c','\x87','\x73','\x53','\xfb','\x9e','\x93','\x0a','\xd2','\x67','\x91','\x49','\xad','\x4c','\xbe','\x69','\x91','\x0e','\x68','\xd5','\x50','\x0b','\x09','\x6c','\x5a','\xbd','\xbf','\x27','\xd6','\x84','\xfc','\xfc','\xf1','\xa5','\x7f','\x02','\x76','\x92','\x83','\xd5','\xa0',};
	const char *digest87 = "7bda57d21a4434aada6758e282e612a4c0f41b242f9c790804d5bee25b81a821dc6f2a0ba56f1b3704802c9a6e153d85";
	err |= test_sha384(vector87, len87, digest87);

	size_t len88 = 87;
	const char vector88[] = {'\x2c','\xfc','\x76','\xf8','\x8c','\xb6','\xfb','\x90','\x92','\x7b','\x69','\x52','\x6a','\xd5','\xf0','\x3d','\x6b','\xd3','\x35','\xf4','\xf7','\x5b','\x52','\xb6','\xa3','\xc2','\x1e','\x8f','\x98','\x9a','\xb0','\xd0','\x3a','\xcb','\x1e','\xbe','\x07','\xe6','\x8a','\x87','\xc1','\xb5','\x60','\x7a','\xcf','\x17','\xd9','\x76','\xe1','\x0a','\xc4','\xa3','\xd3','\x0a','\x85','\x61','\xd4','\x9a','\x5e','\x7e','\xc7','\x20','\xed','\xac','\xe9','\xf5','\xf6','\x32','\xb4','\xbd','\x63','\xe1','\x04','\xf4','\x89','\x4a','\x79','\xca','\xad','\x2e','\x1c','\x31','\xc7','\x36','\x45','\x34','\x85',};
	const char *digest88 = "e16670ea837c259e418d3c0e1eaad4948c3457e15b1573056e24da25bff5c66b7e95d24c6bc1b8d6c2b812f64adc9553";
	err |= test_sha384(vector88, len88, digest88);

	size_t len89 = 88;
	const char vector89[] = {'\x3f','\x05','\x10','\x8c','\x2f','\x33','\xd3','\x9b','\x3a','\xa9','\xe7','\x3e','\xfb','\xad','\x4b','\x01','\x1b','\x4e','\x9e','\x9f','\xba','\x40','\x9b','\x76','\x11','\xe7','\xe0','\x39','\x56','\xb2','\xf3','\xe5','\xe0','\xaa','\x86','\xf6','\x8c','\x4b','\xfa','\xda','\x5f','\x92','\x23','\xa6','\x6d','\x57','\x4b','\x08','\xf9','\xdd','\x79','\x7c','\xdd','\xa8','\xf3','\xc3','\x2d','\x8e','\x01','\x92','\x17','\x11','\xf4','\x87','\x0d','\xec','\x67','\x60','\x27','\xec','\xc5','\x6f','\xc2','\x01','\x0b','\x49','\x6e','\x95','\xcf','\xbf','\x07','\x1c','\x82','\x0f','\x21','\xed','\xf2','\x5b',};
	const char *digest89 = "b272bab680f3ab27de72d94df384323f8555f1d17facd2588ac8648def2451f82f9b99c05ead8316fd181a2cfb97483a";
	err |= test_sha384(vector89, len89, digest89);

	size_t len90 = 89;
	const char vector90[] = {'\x1f','\xfb','\xe1','\xaf','\xf0','\xa1','\xe7','\xfa','\x3e','\x68','\xbe','\x31','\xa7','\x46','\x12','\xa1','\x51','\x9b','\x59','\x39','\x7e','\x70','\x07','\xef','\x61','\xfc','\x01','\x5f','\x31','\x6d','\x55','\xb5','\x7b','\xe5','\x28','\xce','\xbc','\xc2','\xf0','\x9a','\x2f','\x22','\xe3','\xc5','\xe4','\xa6','\xae','\x96','\x12','\x77','\x6b','\x17','\xae','\x87','\xcd','\x76','\x3c','\x1a','\x9e','\xab','\xe6','\x84','\x6c','\x5b','\xcb','\x34','\x7f','\xfc','\x99','\xf1','\x0e','\x3b','\x5e','\x64','\xb2','\x9a','\x9b','\xd7','\x1a','\x5e','\x9b','\x3c','\x01','\xa8','\x02','\x71','\x5d','\xe2','\xa9',};
	const char *digest90 = "f08bda9d6762607519d53fecb0bffbfd3ff2924854833a759d631e910c42ca86741fc2e290af42e94b94898609b91390";
	err |= test_sha384(vector90, len90, digest90);

	size_t len91 = 90;
	const char vector91[] = {'\xf7','\x55','\xd6','\xb5','\x64','\x23','\x78','\xf2','\x84','\x78','\x93','\x90','\x1d','\x9a','\xa9','\x1c','\x54','\xa4','\xb7','\xab','\xb9','\x7c','\x5c','\x71','\x84','\x06','\x3e','\x8f','\x1e','\x97','\xaa','\x2d','\xe4','\xad','\x7a','\xc9','\x27','\xdd','\x3c','\xce','\x77','\x0c','\x90','\x69','\x21','\xe2','\xd2','\x98','\xf6','\x7c','\xf9','\x84','\x4e','\x61','\xbf','\x10','\x4d','\xb8','\x03','\xb2','\x65','\xb8','\x6b','\x82','\x1c','\x5f','\x4d','\x90','\x10','\x67','\xd0','\x7b','\x38','\x76','\x4e','\x3f','\x6c','\x95','\xfd','\x4f','\x28','\xe3','\xcf','\xe4','\x8d','\x8a','\x96','\x94','\xa8','\xf3',};
	const char *digest91 = "f85e98ea054455242280854e97c4ed399b85ee7bc5c5fc3d62910a76f3a9600c3d904c832b70b58d7d998db8dc978135";
	err |= test_sha384(vector91, len91, digest91);

	size_t len92 = 91;
	const char vector92[] = {'\x77','\x35','\x77','\xf3','\xa6','\x42','\xc4','\xf1','\x3b','\x1c','\xb1','\xf4','\x10','\x3e','\x9f','\x6b','\x2d','\xa8','\x62','\x68','\xa5','\x2f','\x44','\x9c','\xbb','\x17','\x4c','\x83','\x49','\xe3','\xc0','\xdc','\x63','\x6c','\xe8','\x5c','\x37','\x31','\x15','\xa3','\x37','\xee','\xe2','\x6f','\x7b','\x70','\xba','\x10','\x60','\xa7','\x9a','\x1c','\x76','\xfd','\x18','\x63','\x99','\xe6','\xa5','\x25','\x5d','\xb8','\x0f','\x83','\xb0','\xbe','\x4a','\x34','\xba','\x87','\x6f','\x79','\x08','\x84','\x05','\x53','\xea','\xd3','\x80','\xf3','\x19','\x55','\x07','\x72','\x9d','\x06','\x7a','\xc2','\xee','\x8e','\xb4',};
	const char *digest92 = "cc27869cd7e63695d19082446b068b77dde4e8604f8c0e9ce20a1b71aa9eff1460f32d5a54476275bdee8e7621491f46";
	err |= test_sha384(vector92, len92, digest92);

	size_t len93 = 92;
	const char vector93[] = {'\x65','\x15','\x89','\x92','\x7e','\x17','\xe1','\xae','\xf7','\x80','\x69','\x0f','\x31','\x00','\xa3','\x77','\xf0','\x17','\x9b','\x18','\xb3','\x1f','\xd5','\xb4','\x41','\x8c','\x84','\x03','\x85','\x73','\xfc','\x55','\x9b','\x49','\x6a','\x78','\x2b','\xee','\xc3','\xdc','\xf6','\xe9','\xfa','\xf5','\xae','\xf6','\x76','\xe1','\x0b','\xbe','\xc3','\x4b','\x1b','\xe5','\x88','\x8f','\xda','\x49','\xb9','\x1e','\x02','\x89','\x0d','\x25','\x24','\xc5','\xb3','\x69','\xf8','\xa5','\x41','\x75','\xf2','\x9d','\xed','\xf8','\x15','\x6f','\xff','\x69','\x0c','\xf1','\x86','\xec','\x77','\x10','\x4a','\x79','\x83','\x15','\x03','\x3b',};
	const char *digest93 = "da846042fb908eee5f5defd1055ff3e57103708278d379a8681f58bedc6ef89670b9f957c4e0edcaa42dfd8cd49df6ea";
	err |= test_sha384(vector93, len93, digest93);

	size_t len94 = 93;
	const char vector94[] = {'\x67','\x86','\x52','\x60','\x0e','\xee','\x42','\x58','\x0f','\x73','\x62','\x34','\x12','\xe9','\xc0','\x11','\xcc','\x02','\xde','\xc4','\xd4','\xcc','\x1b','\x79','\xb2','\x7b','\x6f','\x99','\x39','\x69','\x5b','\xf2','\x18','\x5b','\x20','\x12','\xab','\x06','\x30','\xf3','\x17','\xd2','\xe2','\xde','\x95','\xdd','\x69','\x89','\x0e','\x43','\x07','\x83','\xe9','\x9d','\x7e','\xd1','\x21','\xc7','\xc8','\xda','\x9a','\xe7','\x07','\x80','\xb5','\xaa','\xbf','\x90','\x22','\xd1','\x43','\x5c','\xf5','\xed','\x6d','\xa6','\xfc','\x66','\x92','\xc0','\x50','\xc2','\xb5','\xf2','\x2b','\x24','\xfb','\x1c','\xf9','\x13','\x5f','\x9c','\xb2',};
	const char *digest94 = "8a6ae41c9bccc16eac4860bd5fa91205a86fbfd09692578f7f36b3c135d96f9e9001c192dbeda975f7375bd43a23ba68";
	err |= test_sha384(vector94, len94, digest94);

	size_t len95 = 94;
	const char vector95[] = {'\x41','\x6d','\x3f','\xb7','\xb4','\x01','\xfa','\x5e','\x78','\xcd','\x96','\xd4','\x79','\xd8','\x86','\x0d','\xf1','\x47','\xee','\xf0','\x3a','\xdf','\x13','\xfc','\xe1','\xc6','\x11','\x31','\xfb','\x89','\xcc','\x2e','\xbc','\x63','\x28','\x97','\x45','\xbd','\x7d','\xb9','\xbe','\xf1','\x45','\x71','\xa5','\x53','\x18','\x49','\x65','\x72','\xdb','\xe5','\x2b','\x9b','\x34','\x9e','\xf5','\x9f','\x40','\x6c','\xec','\xd6','\x89','\x09','\xf3','\x64','\x32','\x53','\x80','\xbb','\x75','\xf3','\xaa','\x62','\x50','\x3c','\x84','\xf4','\x7a','\x55','\xaa','\x6b','\x9c','\x9b','\x19','\x9e','\xbe','\x41','\x44','\x09','\xff','\x39','\x64','\xcd',};
	const char *digest95 = "c5f20542e0c0ac1eb433de6229fe5baccfd4502e2c2275439385efda6374a1d0fc50cd9bba4233d470ad91a3356ea315";
	err |= test_sha384(vector95, len95, digest95);

	size_t len96 = 95;
	const char vector96[] = {'\x6f','\x09','\xe8','\x76','\xc0','\xb8','\x3c','\x99','\x34','\xff','\xb7','\x77','\xf0','\x06','\x33','\x8c','\x51','\x42','\xa3','\x13','\x75','\xe9','\xb2','\x1c','\xfe','\xa9','\xa7','\xde','\x12','\x99','\x8c','\x4e','\xa6','\x70','\x8f','\xf1','\xfd','\xf5','\xa8','\xee','\x6b','\xb6','\x7c','\x67','\x5f','\xfd','\x82','\x09','\xa1','\x00','\x64','\xe2','\xd7','\x58','\xa8','\x73','\x4e','\xb4','\x8f','\x07','\xf7','\xcf','\x3d','\x43','\xb0','\x9f','\x1b','\xfd','\xc5','\xd0','\x7a','\x52','\xb7','\x70','\x79','\xf2','\x3c','\xec','\x28','\xbf','\x86','\x3b','\xed','\x97','\xc8','\x59','\x27','\x6d','\xf7','\xf7','\x12','\x9f','\xce','\x71','\xeb',};
	const char *digest96 = "b3c968f3025f87dbd5cd3d364bf673e62827c35889532431becd87cfbe2cc75b7ef45696d19cd3452d0e7c2b69d09544";
	err |= test_sha384(vector96, len96, digest96);

	size_t len97 = 96;
	const char vector97[] = {'\x0d','\xc2','\xb2','\x26','\xb3','\x43','\x1c','\x69','\xa7','\x6a','\xdd','\xc0','\x18','\xfc','\xbd','\xa2','\x2b','\xd7','\x2c','\x8f','\xf0','\x1e','\xd6','\x54','\x95','\x96','\x79','\x8b','\xd9','\x50','\xf3','\x61','\xc4','\x89','\xa0','\x9c','\x95','\xce','\xe2','\xdc','\xfd','\x64','\x01','\x20','\x8a','\xe6','\x36','\x8d','\x66','\x30','\x02','\x6b','\x41','\x7c','\xc4','\x71','\x8c','\xcb','\x8b','\x42','\xe8','\x87','\x29','\x37','\xde','\x66','\x89','\x5f','\xd0','\x91','\x42','\xc4','\x2f','\x06','\x6b','\xf0','\xef','\x3a','\xb2','\xb0','\x38','\x03','\xa8','\x18','\x5f','\xb6','\x5f','\xc7','\x14','\x8c','\x37','\x6d','\xdd','\x4b','\xf5','\x8a',};
	const char *digest97 = "aa645a4f8f602411260ace24d381f3f5dff0000c246343eb528e3dd027cd743815737906ac5c74ea83c2755e56b99509";
	err |= test_sha384(vector97, len97, digest97);

	size_t len98 = 97;
	const char vector98[] = {'\x8d','\xc7','\x1c','\x84','\xc8','\x77','\x27','\x53','\xc8','\x6a','\xb6','\xaf','\xd8','\x0e','\x8d','\x1d','\xf9','\xb0','\xd7','\xe8','\xd6','\x9e','\xbe','\x67','\xfa','\x88','\x3a','\x82','\x41','\x2c','\x26','\x73','\x8c','\x33','\x99','\xca','\xb9','\x55','\x73','\xb4','\xd3','\xc4','\x36','\x7c','\x85','\xc8','\x18','\x52','\xd5','\xa6','\x56','\x4c','\x0f','\xc7','\xca','\xaa','\xfe','\x16','\xc0','\x5e','\x62','\xaa','\x06','\xcc','\x9f','\xa5','\x42','\xce','\xb3','\x5c','\x88','\xfb','\x6a','\xb8','\x2c','\x29','\xd5','\xdc','\xd5','\x30','\xf8','\x07','\xd3','\xf1','\xc3','\xbc','\xb3','\x97','\x44','\x21','\x10','\x1d','\x1a','\xa6','\xac','\x11','\x2d',};
	const char *digest98 = "12239813097124e6248e7dbec985a6a25f622b1d07295cfcfbaff33b847df7fd94265e439fa535f3becbdb576922ac41";
	err |= test_sha384(vector98, len98, digest98);

	size_t len99 = 98;
	const char vector99[] = {'\x3d','\xf3','\xed','\xd9','\xfc','\x93','\xbe','\x99','\x60','\xb5','\xa6','\x32','\xe2','\x84','\x7b','\x30','\xb1','\x01','\x87','\xc8','\xf8','\x3d','\xe5','\xb4','\x5f','\xcb','\x2e','\x3e','\xd4','\x75','\x56','\x9a','\x8b','\x2e','\xd0','\x78','\x43','\x48','\xf9','\xda','\xcc','\xe7','\xb3','\x23','\xc6','\xb6','\x50','\x71','\xab','\xd8','\xb3','\x2d','\x10','\x22','\xb1','\xe1','\x27','\x87','\xbd','\x49','\x89','\xd3','\xc5','\xac','\x32','\x9d','\x57','\x6c','\xcd','\x76','\x08','\xdd','\x33','\x67','\x16','\x53','\x2e','\x9b','\x4c','\x7f','\x82','\x58','\x26','\xfb','\x2e','\x34','\x36','\x23','\xef','\x85','\xc6','\x27','\x06','\x19','\xbf','\x5e','\x3b','\x27',};
	const char *digest99 = "f36590f5211a9cf84eeb0a3b2e5dc1164e813191cda7cb883f3f4a074605ce6780cf2f1a105658706fbd2829db8a2a58";
	err |= test_sha384(vector99, len99, digest99);

	size_t len100 = 99;
	const char vector100[] = {'\xce','\xd0','\xec','\x65','\x00','\xcb','\x89','\x1e','\x64','\x33','\xd1','\x04','\xba','\x5b','\x1c','\x1e','\xbc','\xa3','\x97','\xf3','\xa5','\xee','\xea','\xa0','\xf0','\x56','\x17','\x29','\x62','\x1e','\xa5','\x0d','\x4a','\xe7','\xff','\x1d','\x08','\x27','\x17','\x8d','\xcc','\xd8','\x4e','\x4c','\xa0','\x6d','\x98','\x91','\xa9','\x0a','\xdb','\xb7','\xa9','\xf4','\x99','\x4a','\xc9','\x47','\xcf','\x62','\x96','\xe7','\x1d','\x2f','\x49','\xb8','\x26','\xd6','\x4b','\x12','\x3a','\x7b','\xf8','\x6f','\x33','\x9f','\xa4','\x67','\x9c','\xad','\xdb','\xdf','\x19','\xcf','\xed','\x7d','\x02','\x06','\xaa','\x5f','\x52','\x7a','\x6b','\x0c','\xc0','\x0f','\x52','\xaa','\x2b',};
	const char *digest100 = "c2c2d7d65d0b9108648e3233d15fc4e4cb62ed8fee9cdd18ab44b8486e2100fbe45ddcf74f46c15eb77fb1c893c12202";
	err |= test_sha384(vector100, len100, digest100);

	size_t len101 = 100;
	const char vector101[] = {'\xaf','\xa4','\xa2','\xc4','\xfb','\xaf','\xfe','\x83','\x8d','\xd1','\x49','\xc7','\x8e','\xa7','\x85','\x1e','\xa9','\x39','\x63','\x04','\xb4','\x18','\x06','\xa0','\x93','\xa9','\x0a','\xae','\x59','\xc0','\xc5','\xbd','\xb1','\x70','\xcc','\x9a','\x7d','\x22','\xb9','\x0c','\xbc','\xe5','\x2c','\xc1','\xb1','\x05','\x10','\x89','\x42','\xdf','\x20','\xc2','\x9e','\xf3','\xa9','\x13','\x22','\x3b','\x91','\x5e','\x7e','\xbc','\x98','\xef','\x13','\x5a','\xde','\xfa','\xa0','\xf0','\xa6','\x44','\x1e','\xa0','\x59','\x20','\xe8','\x68','\xce','\x9d','\x1f','\xf6','\xc8','\xfe','\x4d','\xbe','\xc0','\x6a','\x48','\x49','\xe5','\xe5','\x5a','\xd0','\x62','\x7f','\x9e','\x09','\xdf','\xcb',};
	const char *digest101 = "cf6ef91d8567414f5c7f0b1f4ad09a976afc7c8327a382fca90f5a136b19be33100a664390a377f8d8a3015fb882125b";
	err |= test_sha384(vector101, len101, digest101);

	size_t len102 = 101;
	const char vector102[] = {'\x00','\xf6','\x5a','\x48','\x5b','\xfd','\x38','\x11','\x13','\xd6','\xe7','\x9b','\xf9','\xe0','\xd5','\xe5','\x18','\xc8','\x91','\x98','\x8c','\x07','\x3b','\xa1','\x98','\xac','\x3a','\x20','\xf2','\x5c','\x2c','\x81','\x61','\x97','\x23','\xe8','\x8a','\x3c','\x0e','\xd3','\x07','\x50','\x75','\xfb','\xba','\xfb','\x6a','\x7b','\x61','\xd3','\xbc','\x33','\x6a','\x5e','\x6d','\x6f','\x08','\xd1','\x66','\xc4','\x86','\x1e','\x6a','\x3b','\xdc','\x2e','\x49','\xb2','\x80','\x6b','\x56','\x7e','\x7e','\x82','\x1a','\x55','\xcb','\x67','\x4a','\x6c','\xd6','\x99','\xf7','\xdc','\x61','\xa7','\x05','\x4a','\x8f','\xf3','\xde','\xc7','\x3e','\xb6','\x67','\xf5','\x96','\x44','\x34','\x6b','\xe2',};
	const char *digest102 = "809c6b5d41da7cd10df90b02b193ac7d40cf2e46c139e9dbd208a988da2b25002cdbad1db2ecc1322da20b7d054e5fe6";
	err |= test_sha384(vector102, len102, digest102);

	size_t len103 = 102;
	const char vector103[] = {'\xb9','\xce','\x38','\x2e','\x1e','\x82','\xa8','\x73','\xcc','\x44','\x42','\x48','\xa3','\x00','\x8c','\x2c','\xf6','\x4d','\x18','\x75','\x90','\x57','\xab','\xe8','\xf9','\x1c','\x9d','\x87','\xf5','\xdc','\x83','\xaa','\x4e','\xca','\x0c','\x51','\xd3','\x08','\x29','\xb9','\xa1','\xd2','\x71','\x2d','\xa1','\xfa','\xc3','\x1f','\x52','\x94','\x2d','\x77','\xc9','\xf2','\x0c','\x2b','\xf6','\xd3','\x75','\x10','\x28','\xd7','\xd4','\xf0','\xd3','\x36','\xd3','\xdc','\x92','\xb2','\x7e','\xc3','\x68','\xca','\xa4','\x44','\x4b','\x31','\x80','\xc1','\xe3','\x7e','\x98','\xb5','\x8f','\x25','\xe6','\x47','\xa9','\xa6','\x36','\x1f','\x0b','\x04','\xcf','\x78','\xd1','\x79','\x55','\x76','\x61','\x68',};
	const char *digest103 = "18cd10b3ea907b3770e8eb91c974666e2da2525afe7020b872b3ec6689e5e1cd0059dd4fd49ce44d75dc4c8430c322d6";
	err |= test_sha384(vector103, len103, digest103);

	size_t len104 = 103;
	const char vector104[] = {'\x67','\x78','\xd8','\x2f','\x3a','\x98','\xee','\xcd','\xfa','\xc5','\x5d','\xde','\xeb','\xc5','\x24','\x76','\xa0','\x70','\x09','\x4f','\xbd','\x65','\x83','\x18','\x01','\xfd','\xd6','\x0f','\x83','\x7d','\x80','\xd2','\x3b','\x90','\xd4','\x72','\xc5','\xf4','\xe5','\xca','\x62','\x73','\xa5','\x0f','\x40','\x15','\x4e','\xa8','\xfb','\x94','\x01','\x3f','\x63','\x10','\xad','\x18','\x80','\x04','\x33','\xa1','\xd3','\x79','\xc8','\x4b','\xdf','\x79','\x9a','\x99','\xe8','\xc7','\xb6','\x76','\xfb','\xcd','\x29','\xcc','\x2e','\xd6','\x65','\x52','\x29','\x7d','\xe7','\xa6','\xe5','\x65','\x17','\x9b','\xb4','\x2b','\x70','\xd4','\x82','\x99','\xe0','\x92','\x5a','\x1d','\x72','\xca','\x2c','\x79','\x2a',};
	const char *digest104 = "71f08d9333df5cb885fd23d6cbb1db84f9b55908d069df50fa4795cc713a18439bcab8daca078356f5c75a619f2f8782";
	err |= test_sha384(vector104, len104, digest104);

	size_t len105 = 104;
	const char vector105[] = {'\xba','\x3a','\x54','\xa7','\x7d','\x7c','\x2b','\x8c','\xce','\xc6','\xd5','\x31','\x36','\xcd','\x48','\x82','\x7c','\x87','\xac','\xdd','\x1c','\xd8','\x6a','\xd1','\xf5','\x6e','\x86','\x26','\x42','\xea','\x2e','\x1d','\xcb','\x40','\x93','\xf8','\x5d','\x60','\xf7','\xbd','\x77','\x16','\x07','\x38','\x46','\x2e','\x6c','\x3f','\xd3','\xdd','\x9d','\x3a','\x7c','\x5c','\xf7','\xe2','\xa1','\xd6','\x0f','\x48','\x9f','\x84','\x47','\x19','\x02','\x17','\x9f','\x21','\xf6','\x56','\xce','\x0f','\xff','\x08','\x92','\x78','\xea','\x14','\x44','\x1e','\x04','\xe7','\xaf','\x71','\x89','\x16','\x22','\x56','\x5f','\x44','\xc4','\x28','\x04','\x47','\x28','\xfc','\xc6','\x86','\x21','\x2a','\x32','\xa5','\xd8','\x09',};
	const char *digest105 = "3cc154f0542d8e3cacf9d79f231416816178a7ef2275fb257a48a2f763ffa2e15a33c27b970a416a057925aa0412d268";
	err |= test_sha384(vector105, len105, digest105);

	size_t len106 = 105;
	const char vector106[] = {'\x7e','\xec','\x4f','\x4f','\x49','\x1b','\x4e','\xea','\xeb','\x1c','\xdb','\xdb','\x95','\xe9','\x51','\x1c','\x28','\x72','\x37','\x2b','\xf6','\x4a','\x1f','\x61','\xcd','\xa1','\xcd','\x80','\x32','\x72','\x9c','\x8b','\xea','\xfd','\x1e','\xda','\xbf','\x78','\x03','\x6d','\x80','\x02','\x3c','\x81','\x4a','\xd8','\x60','\x61','\x06','\xcb','\x4e','\x7f','\x33','\xf2','\x14','\xc3','\xe6','\x9c','\x0f','\x23','\x0e','\x88','\x54','\x74','\xfd','\x59','\x4f','\x7f','\x24','\x44','\xaa','\x58','\x1e','\x0c','\x70','\xeb','\xf1','\x30','\x73','\xd8','\x90','\x63','\xeb','\x81','\xa4','\x3c','\x5f','\x60','\x8b','\x2f','\xc9','\x9f','\xa1','\xbc','\xf5','\xe2','\xbf','\xe6','\x2a','\x68','\x02','\xe7','\x0c','\x52','\xce',};
	const char *digest106 = "2f8c5682a07438043e55f0b7759fe7eea5d9bdfc8b0f89800ebcf777bc05a941ea7f3cac45d4659de0f505d814590b6b";
	err |= test_sha384(vector106, len106, digest106);

	size_t len107 = 106;
	const char vector107[] = {'\xf3','\x71','\x5b','\x9e','\x3d','\xdd','\x78','\x62','\xe1','\x5e','\xe8','\x7a','\xa2','\x3f','\x1a','\xaa','\x05','\x80','\x59','\x1e','\x55','\xcf','\xf3','\xfe','\xe9','\xb4','\x9b','\x42','\xaa','\x0c','\x0c','\xc8','\xcf','\xb8','\xef','\xa3','\xeb','\x96','\xff','\xb7','\x2a','\xb0','\x6b','\x83','\xd7','\xb4','\x7b','\x3d','\x22','\xa5','\x77','\x24','\x21','\xcf','\xc5','\x12','\x14','\x00','\x51','\x50','\xed','\xf5','\x32','\xaf','\x10','\x13','\x8a','\xd4','\x57','\x58','\xad','\xd4','\x59','\x90','\x86','\x01','\xec','\xcc','\x37','\x03','\xe8','\x10','\x00','\x2a','\x2e','\x4c','\x62','\x02','\xe9','\x8d','\x84','\x28','\x14','\x75','\xd5','\x5d','\x3d','\xe9','\xf3','\xd9','\x88','\x09','\xcc','\xe1','\xf6','\x65',};
	const char *digest107 = "04e7d55b0eb4bc3d3a21cfd2941dbb4dc44706588967186b40da54902aeea97b262c97f75e37ebe3cd60a804e7b9feca";
	err |= test_sha384(vector107, len107, digest107);

	size_t len108 = 107;
	const char vector108[] = {'\xdf','\xd7','\xd7','\x92','\xe1','\x62','\xbf','\x7a','\x88','\x91','\x09','\x55','\x0a','\x0f','\xc4','\xc4','\x15','\x23','\x2a','\xf0','\xc0','\xd7','\x2d','\xcb','\xc2','\x59','\x52','\x99','\xe1','\xa1','\xc2','\xae','\xae','\x54','\x9f','\x79','\x70','\xe9','\x94','\xc1','\x5e','\x0a','\xb0','\x2f','\x11','\x3d','\x74','\x0d','\x38','\xc3','\x2a','\x4d','\x8e','\xc0','\x79','\xcd','\x09','\x9d','\x37','\xd9','\x54','\xab','\x7e','\xf2','\x80','\x09','\x02','\xcd','\xf7','\xc7','\xa1','\x9f','\xb1','\x4b','\x3c','\x98','\xaa','\xf4','\xc6','\xad','\x93','\xfe','\x9a','\x9b','\xc7','\xa6','\x12','\x29','\x82','\x8e','\x55','\xad','\x4d','\x62','\x70','\xd1','\xbd','\xbc','\xa9','\x97','\x5d','\x45','\x0f','\x9b','\xe9','\x1e','\x56',};
	const char *digest108 = "08e5ef57d0c2aa23edfc75cfae39e6bc1a43b5db08b2e27bc9823114edf760367db9cf3cd9c3779755f6d39e219b7079";
	err |= test_sha384(vector108, len108, digest108);

	size_t len109 = 108;
	const char vector109[] = {'\xff','\xbc','\x7c','\x47','\xf5','\x2e','\x69','\xf5','\xc6','\x67','\xf4','\xed','\x57','\x8b','\x46','\xff','\x45','\x92','\x04','\x8f','\x78','\x90','\x81','\xf3','\xfb','\x39','\x32','\x1d','\x0a','\xa4','\x62','\x7a','\x6d','\x4f','\x26','\x19','\x05','\x64','\x94','\x10','\xa5','\x3a','\x30','\x1c','\x23','\x1f','\xa7','\x87','\xae','\x55','\xc0','\x4f','\x61','\x5a','\x8f','\x84','\x19','\x6c','\xec','\xf2','\x84','\x4d','\x23','\x00','\x7b','\x44','\xed','\xd8','\x92','\x64','\x9f','\xc8','\xed','\x10','\xa2','\xe8','\x55','\xbf','\x23','\xfe','\x8a','\xfd','\x0b','\x9e','\xdb','\xb3','\x32','\x96','\xf5','\xa7','\xcf','\x89','\xf9','\x46','\x34','\xd9','\xd1','\xa2','\xb8','\xca','\xc3','\xb7','\xf4','\xe5','\x46','\xf2','\x32','\x9b',};
	const char *digest109 = "be10c7baf94608408a0accfbc8ce95e159d08d8ca75dd6c273f935947a7ec3463e10a58d3ceaa0b2198b0887a3a24a29";
	err |= test_sha384(vector109, len109, digest109);

	size_t len110 = 109;
	const char vector110[] = {'\xa3','\x9f','\x20','\x2d','\x86','\x6e','\x8e','\x96','\x76','\x5f','\xbb','\x53','\xb6','\x77','\x25','\x37','\xde','\xc0','\x43','\x32','\x2f','\x4a','\x74','\x75','\x24','\x70','\x36','\xd7','\x49','\x5c','\x98','\x78','\x50','\xce','\xf2','\xa4','\x62','\x18','\xd3','\xfa','\xb3','\x6e','\x3b','\xcd','\x59','\x5c','\x0a','\xca','\x5e','\x98','\xb9','\xdb','\x14','\xfa','\x48','\x4c','\xa8','\xc9','\x77','\x2d','\xfa','\x38','\x39','\xf7','\xac','\x30','\x66','\x72','\x7a','\x50','\xb0','\xd5','\xc9','\x33','\xd8','\x2f','\x82','\xf1','\x22','\x07','\x20','\xe8','\x06','\x3f','\x08','\xbc','\x28','\x3f','\x19','\x9c','\x8a','\x4f','\x85','\xc7','\x00','\x43','\xdf','\x4f','\xe5','\x5e','\x75','\x1d','\x0d','\x71','\xdf','\x36','\xfa','\x43','\xd8',};
	const char *digest110 = "3b2664ccb555a1b1f3ec996860146ea75ef7f3bd62028a19c26f63339399f4275a07f3c064d34766ebe8e4dd532f6629";
	err |= test_sha384(vector110, len110, digest110);

	size_t len111 = 110;
	const char vector111[] = {'\xb2','\xc8','\x26','\x18','\x53','\xe2','\x21','\x8d','\xfa','\x13','\x5c','\xb5','\x38','\x78','\x10','\x35','\x2b','\x89','\x62','\xe9','\x4e','\x9f','\xdc','\x86','\x95','\xb4','\x1e','\x7d','\xba','\x6a','\xd1','\x22','\xd1','\x4f','\xdd','\x0d','\x23','\x60','\xdc','\xc0','\x39','\xcc','\xce','\x8b','\x37','\xfa','\x0e','\xad','\x6c','\xcc','\x85','\xbc','\x26','\x26','\x1d','\x47','\xcb','\xaa','\x78','\xb9','\x25','\xc6','\xe3','\x80','\xfe','\xf1','\x85','\x6f','\xed','\x31','\xdc','\x61','\x6f','\xe1','\x6b','\x20','\x39','\xb1','\xac','\x85','\xcd','\xee','\x4c','\xe0','\x4c','\x04','\x97','\x99','\x8b','\x41','\x32','\x18','\x68','\xdb','\x08','\xe3','\x5f','\x35','\x86','\x06','\x58','\x5e','\x0b','\xb8','\xc3','\xda','\x9a','\x3b','\xe7','\xa6',};
	const char *digest111 = "45b286f49fd05c45c921b7bfdbe2cb024441c372e07394dcccae0de834cd541f13a79dbb3e5078896e88438542bd2f12";
	err |= test_sha384(vector111, len111, digest111);

	size_t len112 = 111;
	const char vector112[] = {'\xa0','\x4f','\x39','\x0a','\x9c','\xc2','\xef','\xfa','\xd0','\x5d','\xb8','\x0d','\x90','\x76','\xa8','\xd4','\xb6','\xcc','\x8b','\xba','\x97','\xb2','\x7b','\x42','\x36','\x70','\xb2','\x90','\xb8','\xe6','\x9c','\x2b','\x18','\x72','\x30','\x01','\x1c','\x14','\x81','\xac','\x88','\xd0','\x90','\xf3','\x91','\x54','\x65','\x94','\x94','\xdb','\x5e','\x41','\x08','\x51','\xc6','\xe8','\xb2','\xb8','\xa9','\x37','\x17','\xca','\xe7','\x60','\x37','\xe0','\x88','\x19','\x78','\x12','\x4f','\xe7','\xe1','\xa0','\x92','\x9d','\x88','\x91','\x49','\x1f','\x4e','\x99','\x64','\x6c','\xc9','\x40','\x62','\xdc','\x82','\x41','\x1f','\xa6','\x61','\x30','\xed','\xa4','\x65','\x60','\xe7','\x5b','\x98','\x04','\x82','\x36','\x43','\x94','\x65','\x12','\x5e','\x73','\x7b',};
	const char *digest112 = "e7089d72945cef851e689b4409cfb63d135f0b5cdfb0dac6c3a292dd70371ab4b79da1997d7992906ac7213502662920";
	err |= test_sha384(vector112, len112, digest112);

	size_t len113 = 112;
	const char vector113[] = {'\xf4','\x19','\x49','\x4c','\x3c','\x6d','\x07','\x27','\xb3','\x39','\x5a','\x48','\x3a','\x21','\x67','\x18','\x2a','\x72','\x52','\xf4','\xfd','\x09','\x9c','\x2d','\x4b','\x71','\xb0','\x53','\xf9','\x4b','\xb8','\xb3','\xad','\xf3','\xb5','\x1e','\x84','\x60','\xcf','\xec','\x08','\x4c','\xe9','\x41','\x5c','\x95','\x79','\x8f','\xba','\xe4','\x97','\x5c','\x20','\x8c','\x54','\x46','\x45','\xb5','\x4c','\x44','\xd2','\xb9','\x7f','\x2e','\xcf','\xce','\x5c','\x80','\x5b','\xe6','\x1f','\x5b','\xa1','\xd3','\x5d','\xcc','\x07','\xaf','\xdd','\x51','\xa8','\x7b','\xaa','\x99','\x05','\x06','\x66','\x8c','\xf7','\x10','\xe1','\x8b','\xe9','\xb0','\xeb','\xf9','\x43','\xf3','\x66','\xfa','\x29','\xc6','\x9f','\x7a','\x66','\x16','\xde','\x72','\xa3','\x35','\x3b','\x66',};
	const char *digest113 = "aead8688c58c6ba4e9cadb4756b465dce0fb06f1cfaa478197f2ea89414e47e9572034adfed160703c79b82b3fd7ab78";
	err |= test_sha384(vector113, len113, digest113);

	size_t len114 = 113;
	const char vector114[] = {'\xaa','\xf7','\x58','\x4d','\x53','\x00','\x6c','\xbf','\x2d','\x20','\x40','\xe5','\x1b','\x7f','\xee','\xbd','\x2b','\xbf','\x1e','\x9f','\x6d','\x81','\x7c','\xd8','\x06','\x2a','\x6a','\x96','\x80','\xe7','\xf1','\x04','\x64','\xee','\xfe','\xb5','\x0b','\x07','\xcb','\x46','\xb1','\x4b','\x9b','\x3f','\xcb','\x2c','\xaa','\x3b','\x9a','\xb6','\x64','\x49','\x01','\x15','\xd5','\x91','\x94','\x56','\x61','\x3b','\xf1','\x72','\xb5','\x8c','\x53','\x88','\xfd','\x52','\x64','\x6a','\x57','\x83','\x53','\x5b','\x88','\x21','\x27','\x17','\xef','\x60','\x53','\x14','\xb7','\x0b','\x8a','\x08','\x50','\x24','\xd4','\xab','\x1f','\xcb','\xe2','\xbe','\x74','\x60','\x9e','\x4c','\xbd','\xec','\x07','\x30','\xfa','\xbd','\x3c','\xd7','\x71','\x51','\xd6','\x47','\xa3','\x76','\x7b',};
	const char *digest114 = "e6e79d8c61d0ea9fc70dd4dec1fa432849c3396e717b170badbd87a4c7974efc590ab8c1183a6232beff14534f004b02";
	err |= test_sha384(vector114, len114, digest114);

	size_t len115 = 114;
	const char vector115[] = {'\xa4','\x67','\xf7','\x73','\x69','\x73','\x02','\x01','\xf2','\x81','\x22','\x04','\xfd','\x63','\xad','\x0d','\x27','\x57','\xbe','\x58','\x0d','\x93','\x7d','\xfe','\xb2','\x21','\xa0','\x6b','\x21','\xed','\x32','\x13','\x53','\x1d','\x93','\x61','\x52','\xa0','\xc1','\xf0','\x9f','\x0a','\xd5','\xfe','\xd1','\x9f','\xd1','\x1e','\x80','\xad','\x98','\x2c','\x61','\x20','\x3e','\x86','\xb2','\x50','\x82','\x79','\xd9','\x1d','\x99','\xfa','\x48','\x3e','\x2e','\x97','\xa3','\xd6','\xa6','\xad','\x25','\x48','\xa8','\xda','\x40','\x4d','\xdd','\xb5','\x83','\x44','\xf4','\xbd','\xc1','\xc9','\xea','\x90','\x70','\x88','\x88','\x5e','\x4f','\x53','\x2d','\x9c','\x4c','\x73','\xcd','\xfd','\xa4','\x3c','\x3a','\x9e','\x4c','\xe5','\xa2','\x80','\x90','\x96','\x59','\x3c','\xfa','\xc1',};
	const char *digest115 = "5a7508c2cc096bf65a4d4d337aea22008edb9a3bae869f94e09fb526a52c3368e9b28576fb950f078b7e43b5562120e6";
	err |= test_sha384(vector115, len115, digest115);

	size_t len116 = 115;
	const char vector116[] = {'\x01','\xab','\xc9','\x0e','\x91','\x80','\xfc','\x9b','\xb8','\xea','\x67','\xa4','\x05','\x07','\x3e','\xd6','\x84','\x8b','\xf3','\x30','\x48','\x07','\x65','\x66','\x47','\x6c','\x55','\x83','\x6b','\xcb','\x19','\xd3','\xe5','\x5e','\x94','\x00','\xc5','\xcc','\x65','\x7b','\xc7','\xa9','\x5f','\x1d','\x70','\x3c','\x39','\x0f','\x5a','\x86','\x87','\xe7','\xcd','\x7f','\xe9','\x13','\x8e','\xa3','\x83','\x7b','\xfc','\xad','\xad','\x62','\x58','\xa3','\xeb','\x8d','\x65','\x12','\x1f','\xa8','\x31','\x9b','\xfd','\xe5','\x32','\xae','\xc0','\xe6','\x94','\x96','\x1b','\xdd','\xd2','\xb6','\x73','\xf2','\x84','\x12','\x4b','\xe5','\x78','\x11','\x00','\xf4','\x03','\x81','\xb6','\xff','\x99','\xdb','\x92','\xea','\x9c','\xc8','\x2a','\x43','\x72','\xe5','\x39','\x24','\xda','\xc3','\x98',};
	const char *digest116 = "96b209d7cb2c2033b38350744767fa5c253e1bfdb99fe8418bff83804df02248140fe3b77b0bfd4a79b51f70405a434b";
	err |= test_sha384(vector116, len116, digest116);

	size_t len117 = 116;
	const char vector117[] = {'\xb5','\x55','\xd9','\x90','\x56','\x36','\x2b','\xfc','\x2b','\xac','\x2a','\x1b','\xbb','\x71','\xba','\x11','\x2d','\x64','\x4e','\x50','\xb8','\x2b','\x01','\x5e','\x5a','\x1c','\xe3','\xd9','\xcd','\x5e','\x90','\xb8','\xb7','\x4b','\x08','\xd3','\x21','\x19','\xba','\xa6','\x2a','\xba','\xe2','\x51','\xfc','\x00','\x15','\xe4','\x00','\x05','\x1a','\xda','\x4e','\xca','\xfc','\xe3','\x68','\x1e','\x5d','\xe7','\x27','\xc2','\x0d','\x47','\xf5','\xca','\xdc','\x66','\x3d','\x46','\xac','\x68','\x20','\x22','\xca','\x39','\x6a','\x4b','\x7e','\xd1','\xc4','\x13','\xe0','\xb7','\x2b','\xd7','\xee','\xc4','\xa0','\xdf','\xdc','\x2a','\x21','\x85','\xab','\xb5','\xd9','\x9a','\xfd','\x50','\x94','\x05','\x28','\xca','\x75','\xad','\x89','\xda','\xeb','\x9a','\x1b','\x61','\xe1','\x57','\x47','\xf0',};
	const char *digest117 = "abd39f79d72c6cd2e8e130f3603032fe3cef4177c3563930096df1f10b87e79cd4e2059cf1b9f8252184bb26f659a5da";
	err |= test_sha384(vector117, len117, digest117);

	size_t len118 = 117;
	const char vector118[] = {'\x14','\xfb','\x01','\xae','\x9d','\x60','\x15','\xec','\xb3','\xe5','\x6d','\x6e','\xcd','\xfa','\x4b','\xc0','\x53','\x31','\x86','\xad','\xf8','\x45','\x7f','\x5e','\x4a','\x5c','\x57','\xc6','\x87','\x89','\x5f','\x3d','\xb3','\x95','\xd0','\x6a','\xe7','\xff','\xbd','\x67','\xec','\x41','\x45','\x20','\x09','\x55','\x0d','\xfc','\x18','\x78','\xee','\xc0','\xdf','\x2e','\xea','\xb0','\x9e','\x86','\x65','\xf7','\xe5','\x9f','\x91','\x48','\xa8','\x6b','\x2b','\xc6','\x95','\xb3','\x65','\x21','\xa5','\x5b','\x23','\x02','\xf2','\xe8','\x69','\xaa','\xc8','\x3f','\x14','\xd6','\xfe','\xaf','\xc9','\xe5','\x87','\x32','\x2c','\x3c','\x44','\xf0','\x52','\xea','\x1c','\x05','\x78','\x88','\x4f','\x84','\xf5','\x63','\x07','\xbc','\x6d','\xde','\x31','\xba','\x48','\x11','\x8a','\x0f','\x62','\xb6','\xfd',};
	const char *digest118 = "fc9b9a95a8ce1c157720cb63101a7594df24f4cc74baf735b0ccf6abb925478ad507cd048d30cde1c788806f43ed3a81";
	err |= test_sha384(vector118, len118, digest118);

	size_t len119 = 118;
	const char vector119[] = {'\x11','\xae','\x0c','\xbf','\xee','\x7b','\xb3','\xdf','\x90','\xce','\x58','\x5f','\x09','\xb9','\xcf','\x8f','\xf5','\xbe','\xa6','\x9a','\x68','\xee','\xb6','\xc2','\x25','\x53','\xf8','\xed','\x11','\x8c','\x9a','\x61','\xe7','\xb7','\x52','\xcc','\x2c','\x94','\xf3','\x87','\x66','\xe6','\x3e','\x1b','\x89','\x1d','\xfa','\x05','\xb2','\x33','\x47','\xb6','\x17','\xd4','\x2f','\xde','\x3e','\xc1','\x7e','\xea','\x6e','\x76','\xd3','\xcb','\x64','\x0b','\xf8','\xfa','\x46','\x58','\x6f','\xb9','\xdd','\x5c','\x4d','\x9b','\xfe','\xe0','\x4c','\x46','\x49','\x57','\x1b','\x78','\x17','\x09','\xf8','\x48','\xad','\x70','\x81','\xaf','\xb6','\xe2','\xc7','\x46','\xf0','\x71','\xa5','\x51','\x25','\x10','\x50','\xfd','\x5d','\xf7','\x2e','\xe6','\x52','\x48','\xec','\xdc','\x24','\xf2','\xcb','\xe7','\x4e','\xd5',};
	const char *digest119 = "3214b5feec925059149fa852e3ae285a6eb377df926504e2f824572a3aebd2050a20144e7bede7e7fe238ee83e69f72c";
	err |= test_sha384(vector119, len119, digest119);

	size_t len120 = 119;
	const char vector120[] = {'\xa5','\xc4','\xa4','\x7a','\x04','\xf4','\x71','\x42','\x69','\xd5','\xd9','\x22','\xba','\x46','\x94','\x06','\x0a','\xa2','\xdf','\x49','\x19','\x37','\x20','\xc8','\x19','\xfa','\xc9','\x3b','\xb8','\x78','\x7e','\xc5','\x5a','\x10','\x7a','\xc9','\xa6','\x60','\x2f','\x00','\x45','\xfd','\x2c','\xc8','\xe6','\x67','\x44','\xbf','\x86','\x3c','\xed','\x91','\xee','\xab','\xe6','\x0e','\x7d','\x2c','\x1d','\x80','\x27','\x6e','\xcf','\x3b','\xbe','\x91','\xf1','\x75','\x70','\x96','\xcf','\x58','\x92','\x14','\xf3','\x56','\x9c','\x2c','\x48','\xbd','\x74','\xbe','\x7f','\x8b','\xef','\xdd','\xb2','\x83','\x95','\x81','\x47','\x80','\xa4','\x7c','\x18','\x0a','\x58','\xb0','\xd0','\x27','\x6a','\x7e','\x98','\x73','\xd6','\x82','\xf4','\x73','\xe2','\x7d','\xe7','\x27','\x5c','\x92','\x5e','\xde','\x23','\xb6','\xcc',};
	const char *digest120 = "6bd9e1303579d815f58e8c6c9855850133251778a632f7b312c4b3163b29b5ef6cb9511a08a31a237d9a7604afbfa056";
	err |= test_sha384(vector120, len120, digest120);

	size_t len121 = 120;
	const char vector121[] = {'\x75','\x26','\x47','\x74','\xaf','\x69','\xec','\x7e','\xe3','\x12','\x5e','\x20','\x5b','\xd6','\xd1','\xcb','\x8f','\xdb','\x22','\xf7','\xea','\x6d','\xbe','\x72','\xd1','\xf2','\xc0','\xf7','\xe2','\x20','\x59','\x02','\x79','\x6d','\x75','\xe3','\x79','\xc7','\x9b','\x11','\x49','\x86','\x15','\xc2','\x1c','\x9f','\x52','\xb8','\x76','\x1a','\x88','\x5e','\xec','\xc6','\x9d','\x13','\x2b','\x2b','\x48','\xc6','\x3b','\xc0','\x74','\xc3','\x05','\x5e','\xe5','\xcc','\x13','\xf5','\x1d','\x6c','\x98','\x7e','\x81','\x88','\xb0','\x30','\xb8','\x37','\xe8','\xf7','\x54','\xd4','\x01','\x22','\xb4','\x51','\xf1','\x5b','\x28','\xcd','\x2b','\xdd','\x57','\x69','\x20','\xe1','\xde','\x58','\x06','\x59','\x3a','\x36','\xd8','\xe1','\xe8','\x9b','\x9e','\xf3','\xca','\xef','\xee','\x5a','\xcd','\x80','\xb3','\xe9','\xc9','\xd1',};
	const char *digest121 = "ffa9e4e856d06227c1ccb959be558309cc10633173f4b66ceb382923b52b9150acfb08a7393500477a6ee4425a827e76";
	err |= test_sha384(vector121, len121, digest121);

	size_t len122 = 121;
	const char vector122[] = {'\x79','\x1a','\x36','\xd7','\x48','\x69','\x5e','\x62','\xdb','\x50','\x03','\xa8','\xad','\x36','\x7d','\xf1','\xf0','\x51','\xc1','\xac','\x6a','\x21','\xd7','\x11','\x82','\x3e','\x8e','\x06','\x9b','\x54','\x6e','\x3f','\xa0','\x6c','\xee','\xaa','\xe0','\x6d','\xe7','\x0a','\x1d','\xe2','\x49','\xe1','\xdf','\xfd','\x0d','\x94','\x0e','\xdc','\x6a','\xca','\xc0','\x0c','\x4c','\x15','\x50','\x4c','\x02','\xd4','\xb0','\x93','\x36','\x58','\x00','\x54','\x23','\x45','\x5f','\x00','\x02','\x3b','\x01','\xcd','\xc5','\xb6','\x81','\xb6','\x08','\x33','\x79','\xc2','\x45','\x95','\x51','\x8a','\x47','\xc6','\x54','\xf5','\xe1','\xa1','\x09','\x47','\xdf','\x10','\xc0','\x5a','\x3d','\x71','\x6b','\x2a','\x97','\x3f','\xaf','\x98','\xe1','\xee','\x3b','\x67','\x58','\x16','\x59','\x8b','\xb8','\xd4','\xc2','\xa3','\xb0','\x6e','\xb7',};
	const char *digest122 = "f8d33369680524ed6c6a716d4c502de3eac891f340f40e82e37501be1a90fb61d26e5daafe92bc6ef5ec0ae431168842";
	err |= test_sha384(vector122, len122, digest122);

	size_t len123 = 122;
	const char vector123[] = {'\x74','\xcd','\x86','\xbb','\xed','\x14','\xd8','\x95','\x30','\x1d','\x8a','\x54','\xb2','\x95','\x6b','\x1c','\x5c','\xd1','\x45','\x1e','\xeb','\xab','\x62','\x0b','\x97','\x8d','\x4e','\xce','\xf2','\xcb','\xdf','\x7a','\x14','\x36','\x73','\x81','\xf5','\xee','\x79','\x28','\x1a','\x77','\x33','\x37','\x74','\x0f','\xb9','\xf5','\x85','\x3f','\x42','\x53','\xc4','\xb1','\x9f','\x68','\x43','\x41','\x08','\x1d','\x8f','\x56','\x1b','\x2a','\xd7','\x73','\x22','\x41','\x51','\x09','\x95','\x88','\xda','\x90','\xe0','\x4d','\xdd','\xd5','\x65','\xf6','\x75','\x96','\xc5','\x36','\xd6','\x4c','\x5b','\x87','\xe9','\x48','\x0a','\xd4','\x36','\x01','\x39','\x75','\x07','\xad','\x1b','\x61','\xca','\x0e','\x34','\x9f','\xb8','\x8f','\x19','\xfe','\xb4','\x8f','\x77','\x06','\x76','\xfd','\x56','\x2e','\xe8','\x25','\x9f','\x50','\xd0','\xc9',};
	const char *digest123 = "73ee8d29c30821dcdfa4441639f037fb6ba3a9ca596dc43428043785756608f6207d80b7f78e573174fb9dfd42f0b8cd";
	err |= test_sha384(vector123, len123, digest123);

	size_t len124 = 123;
	const char vector124[] = {'\x46','\x61','\x2e','\x1a','\x4d','\x01','\x6c','\x41','\x70','\x0a','\x3b','\x5c','\xcb','\x38','\x32','\x33','\x53','\xbd','\x8d','\xa5','\xb9','\x94','\x2c','\x9c','\x92','\x12','\xdf','\x40','\xb4','\xbe','\xe0','\x6b','\xe3','\x62','\xa1','\x5d','\xad','\x62','\xc8','\xb2','\x92','\x4d','\x78','\x91','\x68','\xb2','\xd3','\x25','\xfe','\x35','\xbd','\x51','\x00','\xe1','\xe2','\x9f','\x1a','\xc0','\xfa','\x7a','\x60','\xa9','\x4c','\x9e','\xee','\x5a','\x70','\xcc','\xcb','\xc7','\x5a','\xc2','\x14','\xb1','\x94','\x6a','\x56','\x79','\xcb','\x52','\x3b','\x37','\x8d','\x5c','\x69','\x07','\x51','\xb7','\xa7','\xa3','\xb8','\x0d','\x41','\x37','\x12','\xfe','\xae','\x70','\x24','\xce','\x71','\xd6','\x29','\x5a','\x3d','\x5d','\x16','\x51','\x5c','\x36','\x22','\xa0','\x52','\xeb','\x86','\x2e','\xbd','\xab','\x81','\xca','\x7f','\xe3','\xa0',};
	const char *digest124 = "cac13a3784225be03d526f9abc1eb50a762e72c0e01172a15d578801089e5c9f26e53cc00ff755909453e2964d7df838";
	err |= test_sha384(vector124, len124, digest124);

	size_t len125 = 124;
	const char vector125[] = {'\x1a','\x85','\x7c','\x1f','\x10','\x5d','\x06','\x8c','\xea','\xb0','\xb1','\xe1','\x24','\x94','\x89','\x0e','\xc1','\x96','\x36','\x2a','\x48','\xb0','\x20','\x0a','\x0d','\x75','\xd7','\x12','\xb1','\x8f','\xb1','\x4b','\xec','\x6b','\xb5','\xb6','\x8a','\x33','\xb7','\xe0','\xb4','\xfd','\xc5','\xb7','\x71','\x42','\xc2','\x9c','\x6d','\x91','\x51','\xb9','\xf8','\x84','\xf5','\x95','\x51','\xf4','\x76','\xe5','\x25','\x69','\x86','\xa6','\x53','\xd4','\xa4','\x68','\xf2','\x81','\x41','\xed','\x95','\x47','\x21','\xf2','\xcd','\x02','\x05','\x4d','\xf0','\x43','\x87','\x38','\x19','\x45','\x45','\xed','\x70','\x23','\x41','\x73','\xac','\x49','\x88','\xb7','\xd6','\x28','\x12','\xde','\x4f','\x2f','\xea','\xda','\x14','\xf6','\x8e','\x3b','\x41','\xbc','\x99','\x48','\xd4','\x13','\x9f','\x4f','\xb4','\xda','\x59','\x39','\xf2','\x6c','\x02','\x61',};
	const char *digest125 = "b75d92b5cd3772846f7b68064a3567ae43e5010099f2b649f35087e7592aeec176646fc8c2629288944261cd35b5fcba";
	err |= test_sha384(vector125, len125, digest125);

	size_t len126 = 125;
	const char vector126[] = {'\x9d','\x36','\x81','\x8d','\x0c','\x5a','\x00','\x8b','\xe7','\x90','\x4d','\x19','\x17','\xaa','\x3e','\xcc','\xb5','\xef','\x4f','\x38','\xce','\xcb','\x8c','\x4e','\x63','\xc4','\xb2','\xe9','\xb4','\xb0','\x91','\xa3','\xbf','\x25','\xb4','\xed','\x03','\x32','\x44','\x5f','\x89','\x4c','\x2a','\x4c','\x25','\x8b','\x74','\x9a','\xfa','\x17','\xfa','\xd0','\x3c','\xdd','\x41','\x71','\x3a','\x86','\x9f','\x89','\x9b','\xa9','\xa0','\x85','\xe7','\x3f','\xa9','\x47','\x4a','\x58','\xdb','\x7a','\x95','\x0d','\x3a','\x23','\x86','\xb6','\x0f','\x79','\x49','\x5d','\x8b','\xf7','\x3e','\x72','\xac','\xaf','\xfd','\xbf','\x65','\xe1','\x98','\x9f','\xf9','\xcc','\x20','\x6b','\xa8','\xc4','\x6a','\x36','\x8d','\x85','\x12','\xba','\xc7','\xc7','\xc1','\x91','\xd7','\x13','\xac','\xa9','\x49','\xd4','\x5d','\xf2','\x97','\xb1','\xb6','\x59','\x4a','\x1a','\x33',};
	const char *digest126 = "a88da844579f3e3725d00daa8e1e287da4bfbb2d931ebe8d3b16021154be503341d6371d382ada744f86f5bbb56cdcfa";
	err |= test_sha384(vector126, len126, digest126);

	size_t len127 = 126;
	const char vector127[] = {'\x4a','\xe5','\x0e','\xd6','\x26','\xee','\x60','\xdc','\x5e','\xa5','\x56','\xe3','\xce','\x0d','\x3c','\x18','\xb9','\xe6','\x22','\x5b','\x56','\x20','\x81','\x4e','\x8b','\x96','\x21','\xac','\xf8','\xf9','\x39','\xdd','\x37','\x0a','\xd9','\xc7','\x62','\x0d','\x85','\xe6','\xd6','\x7a','\x22','\x9f','\x37','\xf5','\x17','\xd1','\xb5','\x80','\xac','\xae','\x8d','\xf0','\xb5','\xc9','\xd2','\x9d','\x75','\x6f','\x6d','\x5e','\xbd','\x3b','\x63','\xb5','\x54','\xe5','\x56','\x46','\x9b','\x5b','\x4f','\x8e','\x71','\x13','\xba','\xd1','\x55','\x9f','\xb2','\x54','\xca','\x82','\x7f','\xcd','\x00','\x42','\x5d','\x18','\xb0','\xbe','\x7f','\x2b','\x48','\xc2','\x54','\x4c','\x48','\xd9','\x09','\x82','\xec','\x62','\x4f','\x49','\x0b','\xe6','\x5e','\x89','\x3f','\xa9','\x3a','\xc9','\x46','\x7f','\x35','\xa0','\xa8','\xe1','\xb5','\x6d','\x9a','\x40','\x37','\x48',};
	const char *digest127 = "f8cd943f429333c7c8d30a8576827f92c92ae18e0dbcae770601b79687bccf8c23e9e589dfeb45c3b9bcafdd545e45e7";
	err |= test_sha384(vector127, len127, digest127);

	size_t len128 = 127;
	const char vector128[] = {'\xdb','\xed','\x76','\x12','\x44','\x8d','\x46','\xcb','\xe0','\xa3','\x84','\xd1','\xc9','\x32','\x33','\xf0','\x2f','\xfd','\x1c','\x98','\x4b','\xa7','\x65','\x29','\x95','\x18','\x65','\x6d','\x37','\x23','\xb7','\x66','\xc1','\x65','\x8d','\x4b','\x1e','\x70','\x47','\xcd','\xc7','\x29','\x45','\x9e','\x36','\x6e','\xf9','\x34','\x9e','\xfc','\x40','\xcb','\xd9','\x90','\xf2','\xa9','\xa2','\x4d','\xb7','\xa5','\x04','\x5e','\x1d','\xea','\x12','\xdc','\xe8','\xf9','\xd9','\xf2','\xaa','\xed','\x93','\x3f','\x93','\x03','\x1e','\x7b','\x89','\x59','\xac','\x5e','\x7b','\xf6','\xbb','\xbd','\xf3','\x0b','\x48','\xf7','\xeb','\x78','\x3f','\x8f','\xe2','\x92','\x37','\x1a','\x2f','\x24','\x5c','\x5c','\x94','\xb4','\xac','\xae','\x16','\x07','\x67','\xa2','\x0c','\xe7','\xc0','\xea','\x77','\x23','\xd9','\x76','\x91','\xd8','\xee','\xdd','\xa9','\xef','\xd1','\xfe','\x2d',};
	const char *digest128 = "fb531a1ed181c732311e56f4b56ed91dcacc0dd6bf1eb4a44be6f87dd7cb1ef9dfb0310f4a79eaaa3f32bf3914d8624e";
	err |= test_sha384(vector128, len128, digest128);

	size_t len129 = 128;
	const char vector129[] = {'\x3b','\xf5','\x2c','\xc5','\xee','\x86','\xb9','\xa0','\x19','\x0f','\x39','\x0a','\x5c','\x03','\x66','\xa5','\x60','\xb5','\x57','\x00','\x0d','\xbe','\x51','\x15','\xfd','\x9e','\xe1','\x16','\x30','\xa6','\x27','\x69','\x01','\x15','\x75','\xf1','\x58','\x81','\x19','\x8f','\x22','\x78','\x76','\xe8','\xfe','\x68','\x5a','\x69','\x39','\xbc','\x8b','\x89','\xfd','\x48','\xa3','\x4e','\xc5','\xe7','\x1e','\x13','\x14','\x62','\xb2','\x88','\x67','\x94','\xdf','\xfa','\x68','\xcc','\xc6','\xd5','\x64','\x73','\x3e','\x67','\xff','\xef','\x25','\xe6','\x27','\xc6','\xf4','\xb5','\x46','\x07','\x96','\xe3','\xbc','\xe6','\x7b','\xf5','\x8c','\xa6','\xe8','\xe5','\x55','\xbc','\x91','\x6a','\x85','\x31','\x69','\x7a','\xc9','\x48','\xb9','\x0d','\xc8','\x61','\x6f','\x25','\x10','\x1d','\xb9','\x0b','\x50','\xc3','\xd3','\xdb','\xc9','\xe2','\x1e','\x42','\xff','\x38','\x71','\x87',};
	const char *digest129 = "12b6cb35eda92ee37356ddee77781a17b3d90e563824a984faffc6fdd1693bd7626039635563cfc3b9a2b00f9c65eefd";
	err |= test_sha384(vector129, len129, digest129);

	return err;
}

DEFINE_TEST_FUNC(sha512, SHA512_Data);

int sha512(void)
{
	int err = 0;

	size_t len1 = 0;
	const char vector1[] = {'\x00',};
	const char *digest1 = "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e";
	err |= test_sha512(vector1, len1, digest1);

	size_t len2 = 1;
	const char vector2[] = {'\x21',};
	const char *digest2 = "3831a6a6155e509dee59a7f451eb35324d8f8f2df6e3708894740f98fdee23889f4de5adb0c5010dfb555cda77c8ab5dc902094c52de3278f35a75ebc25f093a";
	err |= test_sha512(vector2, len2, digest2);

	size_t len3 = 2;
	const char vector3[] = {'\x90','\x83',};
	const char *digest3 = "55586ebba48768aeb323655ab6f4298fc9f670964fc2e5f2731e34dfa4b0c09e6e1e12e3d7286b3145c61c2047fb1a2a1297f36da64160b31fa4c8c2cddd2fb4";
	err |= test_sha512(vector3, len3, digest3);

	size_t len4 = 3;
	const char vector4[] = {'\x0a','\x55','\xdb',};
	const char *digest4 = "7952585e5330cb247d72bae696fc8a6b0f7d0804577e347d99bc1b11e52f384985a428449382306a89261ae143c2f3fb613804ab20b42dc097e5bf4a96ef919b";
	err |= test_sha512(vector4, len4, digest4);

	size_t len5 = 4;
	const char vector5[] = {'\x23','\xbe','\x86','\xd5',};
	const char *digest5 = "76d42c8eadea35a69990c63a762f330614a4699977f058adb988f406fb0be8f2ea3dce3a2bbd1d827b70b9b299ae6f9e5058ee97b50bd4922d6d37ddc761f8eb";
	err |= test_sha512(vector5, len5, digest5);

	size_t len6 = 5;
	const char vector6[] = {'\xeb','\x0c','\xa9','\x46','\xc1',};
	const char *digest6 = "d39ecedfe6e705a821aee4f58bfc489c3d9433eb4ac1b03a97e321a2586b40dd0522f40fa5aef36afff591a78c916bfc6d1ca515c4983dd8695b1ec7951d723e";
	err |= test_sha512(vector6, len6, digest6);

	size_t len7 = 6;
	const char vector7[] = {'\x38','\x66','\x7f','\x39','\x27','\x7b',};
	const char *digest7 = "85708b8ff05d974d6af0801c152b95f5fa5c06af9a35230c5bea2752f031f9bd84bd844717b3add308a70dc777f90813c20b47b16385664eefc88449f04f2131";
	err |= test_sha512(vector7, len7, digest7);

	size_t len8 = 7;
	const char vector8[] = {'\xb3','\x9f','\x71','\xaa','\xa8','\xa1','\x08',};
	const char *digest8 = "258b8efa05b4a06b1e63c7a3f925c5ef11fa03e3d47d631bf4d474983783d8c0b09449009e842fc9fa15de586c67cf8955a17d790b20f41dadf67ee8cdcdfce6";
	err |= test_sha512(vector8, len8, digest8);

	size_t len9 = 8;
	const char vector9[] = {'\x6f','\x8d','\x58','\xb7','\xca','\xb1','\x88','\x8c',};
	const char *digest9 = "a3941def2803c8dfc08f20c06ba7e9a332ae0c67e47ae57365c243ef40059b11be22c91da6a80c2cff0742a8f4bcd941bdee0b861ec872b215433ce8dcf3c031";
	err |= test_sha512(vector9, len9, digest9);

	size_t len10 = 9;
	const char vector10[] = {'\x16','\x2b','\x0c','\xf9','\xb3','\x75','\x0f','\x94','\x38',};
	const char *digest10 = "ade217305dc34392aa4b8e57f64f5a3afdd27f1fa969a9a2608353f82b95cfb4ae84598d01575a578a1068a59b34b5045ff6d5299c5cb7ee17180701b2d1d695";
	err |= test_sha512(vector10, len10, digest10);

	size_t len11 = 10;
	const char vector11[] = {'\xba','\xd7','\xc6','\x18','\xf4','\x5b','\xe2','\x07','\x97','\x5e',};
	const char *digest11 = "5886828959d1f82254068be0bd14b6a88f59f534061fb20376a0541052dd3635edf3c6f0ca3d08775e13525df9333a2113c0b2af76515887529910b6c793c8a5";
	err |= test_sha512(vector11, len11, digest11);

	size_t len12 = 11;
	const char vector12[] = {'\x62','\x13','\xe1','\x0a','\x44','\x20','\xe0','\xd9','\xb7','\x70','\x37',};
	const char *digest12 = "9982dc2a04dff165567f276fd463efef2b369fa2fbca8cee31ce0de8a79a2eb0b53e437f7d9d1f41c71d725cabb949b513075bad1740c9eefbf6a5c6633400c7";
	err |= test_sha512(vector12, len12, digest12);

	size_t len13 = 12;
	const char vector13[] = {'\x63','\x32','\xc3','\xc2','\xa0','\xa6','\x25','\xa6','\x1d','\xf7','\x18','\x58',};
	const char *digest13 = "9d60375d9858d9f2416fb86fa0a2189ee4213e8710314fd1ebed0fd158b043e6e7c9a76d62c6ba1e1d411a730902309ec676dd491433c6ef66c8f116233d6ce7";
	err |= test_sha512(vector13, len13, digest13);

	size_t len14 = 13;
	const char vector14[] = {'\xf4','\x7b','\xe3','\xa2','\xb0','\x19','\xd1','\xbe','\xed','\xed','\xf5','\xb8','\x0c',};
	const char *digest14 = "b94292625caa28c7be24a0997eb7328062a76d9b529c0f1d568f850df6d569b5e84df07e9e246be232033ffac3adf2d18f92ab9dacfc0ecf08aff7145f0b833b";
	err |= test_sha512(vector14, len14, digest14);

	size_t len15 = 14;
	const char vector15[] = {'\xb1','\x71','\x5f','\x78','\x2f','\xf0','\x2c','\x6b','\x88','\x93','\x7f','\x05','\x41','\x16',};
	const char *digest15 = "ee1a56ee78182ec41d2c3ab33d4c41871d437c5c1ca060ee9e219cb83689b4e5a4174dfdab5d1d1096a31a7c8d3abda75c1b5e6da97e1814901c505b0bc07f25";
	err |= test_sha512(vector15, len15, digest15);

	size_t len16 = 15;
	const char vector16[] = {'\x9b','\xcd','\x52','\x62','\x86','\x8c','\xd9','\xc8','\xa9','\x6c','\x9e','\x82','\x98','\x7f','\x03',};
	const char *digest16 = "2e07662a001b9755ae922c8e8a95756db5341dc0f2e62ae1cf827038f33ce055f63ad5c00b65391428434ddc01e5535e7fecbf53db66d93099b8e0b7e44e4b25";
	err |= test_sha512(vector16, len16, digest16);

	size_t len17 = 16;
	const char vector17[] = {'\xcd','\x67','\xbd','\x40','\x54','\xaa','\xa3','\xba','\xa0','\xdb','\x17','\x8c','\xe2','\x32','\xfd','\x5a',};
	const char *digest17 = "0d8521f8f2f3900332d1a1a55c60ba81d04d28dfe8c504b6328ae787925fe0188f2ba91c3a9f0c1653c4bf0ada356455ea36fd31f8e73e3951cad4ebba8c6e04";
	err |= test_sha512(vector17, len17, digest17);

	size_t len18 = 17;
	const char vector18[] = {'\x6b','\xa0','\x04','\xfd','\x17','\x67','\x91','\xef','\xb3','\x81','\xb8','\x62','\xe2','\x98','\xc6','\x7b','\x08',};
	const char *digest18 = "112e19144a9c51a223a002b977459920e38afd4ca610bd1c532349e9fa7c0d503215c01ad70e1b2ac5133cf2d10c9e8c1a4c9405f291da2dc45f706761c5e8fe";
	err |= test_sha512(vector18, len18, digest18);

	size_t len19 = 18;
	const char vector19[] = {'\xc6','\xa1','\x70','\x93','\x65','\x68','\x65','\x10','\x20','\xed','\xfe','\x15','\xdf','\x80','\x12','\xac','\xda','\x8d',};
	const char *digest19 = "c36c100cdb6c8c45b072f18256d63a66c9843acb4d07de62e0600711d4fbe64c8cf314ec3457c90308147cb7ac7e4d073ba10f0ced78ea724a474b32dae71231";
	err |= test_sha512(vector19, len19, digest19);

	size_t len20 = 19;
	const char vector20[] = {'\x61','\xbe','\x0c','\x9f','\x5c','\xf6','\x27','\x45','\xc7','\xda','\x47','\xc1','\x04','\x59','\x71','\x94','\xdb','\x24','\x5c',};
	const char *digest20 = "b379249a3ca5f14c29456710114ba6f6136b34c3fc9f6fb91b59d491af782d6b237eb71aaffdd38079461cf690a46d9a4ddd602d19808ab6235d1d8aa01e8200";
	err |= test_sha512(vector20, len20, digest20);

	size_t len21 = 20;
	const char vector21[] = {'\xe0','\x70','\x56','\xd4','\xf7','\x27','\x7b','\xc5','\x48','\x09','\x95','\x77','\x72','\x0a','\x58','\x1e','\xec','\x94','\x14','\x1d',};
	const char *digest21 = "59f1856303ff165e2ab5683dddeb6e8ad81f15bb578579b999eb5746680f22cfec6dba741e591ca4d9e53904837701b374be74bbc0847a92179ac2b67496d807";
	err |= test_sha512(vector21, len21, digest21);

	size_t len22 = 21;
	const char vector22[] = {'\x67','\xeb','\xda','\x0a','\x35','\x73','\xa9','\xa5','\x87','\x51','\xd4','\x16','\x9e','\x10','\xc7','\xe8','\x66','\x3f','\xeb','\xb3','\xa8',};
	const char *digest22 = "13963f81cfabfca71de4739fd24a10ce3897bba1d716907fc0a28490c192a7fc3ccb8db1f91af7a2d250d6617f0dfd1519d221d618a02e3e3fa9041cf35ed1ea";
	err |= test_sha512(vector22, len22, digest22);

	size_t len23 = 22;
	const char vector23[] = {'\x63','\xe0','\x9d','\xb9','\x9e','\xb4','\xcd','\x62','\x38','\x67','\x78','\x59','\xa5','\x67','\xdf','\x31','\x3c','\x85','\x20','\xd8','\x45','\xb4',};
	const char *digest23 = "9083e5348b08eb9810b2d15781d8265845410de54fe61750d4b93853690649adc6e72490bc2b7c365e2390573d9414becc0939719e0cb78eca6b2c80c2fda920";
	err |= test_sha512(vector23, len23, digest23);

	size_t len24 = 23;
	const char vector24[] = {'\xf3','\xe0','\x6b','\x4b','\xd7','\x9e','\x38','\x0a','\x65','\xcb','\x67','\x9a','\x98','\xcc','\xd7','\x32','\x56','\x3c','\xc5','\xeb','\xe8','\x92','\xe2',};
	const char *digest24 = "6b315f106b07c59eedc5ab1df813b3c0b903060e7217cc010e9070278512a885008dac8b2472a521e77835a7f4deadc1d591aa23b624b69948a99bb60121c54e";
	err |= test_sha512(vector24, len24, digest24);

	size_t len25 = 24;
	const char vector25[] = {'\x16','\xb1','\x70','\x74','\xd3','\xe3','\xd9','\x75','\x57','\xf9','\xed','\x77','\xd9','\x20','\xb4','\xb1','\xbf','\xf4','\xe8','\x45','\xb3','\x45','\xa9','\x22',};
	const char *digest25 = "6884134582a760046433abcbd53db8ff1a89995862f305b887020f6da6c7b903a314721e972bf438483f452a8b09596298a576c903c91df4a414c7bd20fd1d07";
	err |= test_sha512(vector25, len25, digest25);

	size_t len26 = 25;
	const char vector26[] = {'\x3e','\xdf','\x93','\x25','\x13','\x49','\xd2','\x28','\x06','\xbe','\xd2','\x53','\x45','\xfd','\x5c','\x19','\x0a','\xac','\x96','\xd6','\xcd','\xb2','\xd7','\x58','\xb8',};
	const char *digest26 = "299e0daf6605e5b0c30e1ec8bb98e7a3bd7b33b388bdb457452dab509594406c8e7b841e6f4e75c8d6fbd614d5eb9e56c359bfafb4285754787ab72b46dd33f0";
	err |= test_sha512(vector26, len26, digest26);

	size_t len27 = 26;
	const char vector27[] = {'\xb2','\xd5','\xa1','\x4f','\x01','\xe6','\xb7','\x78','\x88','\x8c','\x56','\x2a','\x05','\x9e','\xc8','\x19','\xad','\x89','\x99','\x2d','\x16','\xa0','\x9f','\x7a','\x54','\xb4',};
	const char *digest27 = "ab2e7d745d8ad393439af2a3fbc9cdc25510d4a04e78b526e12b1c0be3b22966872ebe652e2f46ed5c5acecd2f233a9175dd295ebeb3a0706fc66fa1b137042b";
	err |= test_sha512(vector27, len27, digest27);

	size_t len28 = 27;
	const char vector28[] = {'\x84','\x4b','\x66','\xf1','\x2b','\xa0','\xc5','\xf9','\xe9','\x27','\x31','\xf5','\x71','\x53','\x9d','\x1e','\xef','\x33','\x2e','\x15','\x49','\xa4','\x9d','\xbf','\xa4','\xc6','\xde',};
	const char *digest28 = "c3f9c5781925774783ae9d839772d7513dfcea8c5af8da262c196f9fe80135b2b0c8c6ca0a1604e0a3460247620de20b299f2db7871982d27c2176ae5fa7ad65";
	err |= test_sha512(vector28, len28, digest28);

	size_t len29 = 28;
	const char vector29[] = {'\x6b','\x6c','\xc6','\x92','\xd3','\x98','\x60','\xb1','\xf3','\x02','\x03','\x65','\x3e','\x25','\xd0','\x9c','\x01','\xe6','\xa8','\x04','\x3c','\x1a','\x9c','\xb8','\xb2','\x49','\xa4','\x1e',};
	const char *digest29 = "2e5263d9a4f21b210e0e161ed39df44102864325788647261a6e70ea4b1ee0abb57b57499bc82158d82336dd53f1ef4464c6a08126e138b2cc0892f765f6af85";
	err |= test_sha512(vector29, len29, digest29);

	size_t len30 = 29;
	const char vector30[] = {'\xab','\x1f','\xc9','\xee','\x84','\x5e','\xeb','\x20','\x5e','\xc1','\x37','\x25','\xda','\xf1','\xfb','\x1f','\x5d','\x50','\x62','\x9b','\x14','\xea','\x9a','\x22','\x35','\xa9','\x35','\x0a','\x88',};
	const char *digest30 = "72d188a9df5f3b00057bca22c92c0f8228422d974302d22d4b322e7a6c8fc3b2b50ec74c6842781f29f7075c3d4bd065878648846c39bb3e4e2692c0f053f7ed";
	err |= test_sha512(vector30, len30, digest30);

	size_t len31 = 30;
	const char vector31[] = {'\x59','\x4e','\xd8','\x2a','\xcf','\xc0','\x3c','\x0e','\x35','\x9c','\xc5','\x60','\xb8','\xe4','\xb8','\x5f','\x6e','\xe7','\x7e','\xe5','\x9a','\x70','\x02','\x3c','\x2b','\x3d','\x5b','\x32','\x85','\xb2',};
	const char *digest31 = "5ef322cb4014ecbb713a13659612a222225984d31c187debc4459ba7901f03dac775400acfe3510b306b79894fb0e8437b412150c9193ee5a2164306ebb78301";
	err |= test_sha512(vector31, len31, digest31);

	size_t len32 = 31;
	const char vector32[] = {'\xf2','\xc6','\x6e','\xfb','\xf2','\xa7','\x6c','\x5b','\x04','\x18','\x60','\xea','\x57','\x61','\x03','\xcd','\x8c','\x6b','\x25','\xe5','\x0e','\xca','\x9f','\xf6','\xa2','\xfa','\x88','\x08','\x3f','\xe9','\xac',};
	const char *digest32 = "7978f93ef7ed02c4a24abecba124d14dd214e1492ff1e168304c0eab89637da0f7a569c43dc4562bdb9404a018b6314fe0eebaccfb25ba76506aa7e9dcd956a7";
	err |= test_sha512(vector32, len32, digest32);

	size_t len33 = 32;
	const char vector33[] = {'\x8c','\xcb','\x08','\xd2','\xa1','\xa2','\x82','\xaa','\x8c','\xc9','\x99','\x02','\xec','\xaf','\x0f','\x67','\xa9','\xf2','\x1c','\xff','\xe2','\x80','\x05','\xcb','\x27','\xfc','\xf1','\x29','\xe9','\x63','\xf9','\x9d',};
	const char *digest33 = "4551def2f9127386eea8d4dae1ea8d8e49b2add0509f27ccbce7d9e950ac7db01d5bca579c271b9f2d806730d88f58252fd0c2587851c3ac8a0e72b4e1dc0da6";
	err |= test_sha512(vector33, len33, digest33);

	size_t len34 = 33;
	const char vector34[] = {'\x9f','\x8c','\x49','\x32','\x0a','\xf9','\x37','\x0c','\xd3','\xdb','\x20','\xe9','\xb5','\x0d','\x3e','\xaa','\x59','\xa6','\x23','\x2d','\x7a','\x86','\xfb','\x7d','\x47','\x2f','\x12','\x45','\x08','\xd7','\x96','\x8b','\x05',};
	const char *digest34 = "81b002f15c4d48be8517f7ed89df302fb1435c9435efefed58f3eb8ea11910623f1eb9028a66e02121a7f08a7c604226f2324f483e91548dbbd2c441ab704ce5";
	err |= test_sha512(vector34, len34, digest34);

	size_t len35 = 34;
	const char vector35[] = {'\x4a','\xb9','\xaa','\x06','\x94','\x75','\xe5','\x4b','\x25','\xe5','\x68','\x8a','\x52','\xdd','\x4a','\xcd','\x13','\x41','\x69','\xc8','\x58','\x10','\x5f','\x01','\xa0','\xa1','\xb1','\x34','\xc7','\x2d','\x4a','\xf5','\x1f','\x8e',};
	const char *digest35 = "48ba5a63aba7e7bd8e420475331125a947928c67fdb00f65c4080d9a0b99c0672424e76a1ba6bd76dfe492c730f6f9adccaee7bb11571aadb31f6bb628cfa933";
	err |= test_sha512(vector35, len35, digest35);

	size_t len36 = 35;
	const char vector36[] = {'\xf0','\xc1','\xd3','\x40','\x7d','\xe9','\x2e','\xf7','\x42','\x1e','\x42','\xdf','\x5c','\x9a','\xb3','\x1d','\x2e','\xc0','\xa7','\x50','\xa9','\x52','\x28','\x69','\xcb','\xe4','\xca','\xbd','\x66','\x90','\x8d','\x58','\x23','\xec','\x04',};
	const char *digest36 = "9e75c5bca2c2af1d7739787f46e1d981c4f98e493d0724b5252c2fbae3c526719f1d27e6ccd0d705240281e8fbf3db75b9b3205c1413436d3b5d140004b8cca1";
	err |= test_sha512(vector36, len36, digest36);

	size_t len37 = 36;
	const char vector37[] = {'\xae','\x8c','\x9f','\x8f','\xb4','\x1b','\x51','\x9b','\x6d','\x94','\x38','\x33','\xfe','\x1c','\x32','\xd1','\xc4','\x29','\x2f','\xb1','\xdd','\xf1','\xdb','\xe2','\xeb','\x22','\x7d','\x9e','\x14','\xd3','\x1e','\xd7','\x4e','\xba','\xef','\x12',};
	const char *digest37 = "042f9fd0a4ed3d9fec3655ae11011c6f2bc7e457e8812b6d8be2cd45fc6c432a94558c88f22c01439618865e8e49e509c448b342ca914b120344aaf7bcbdca18";
	err |= test_sha512(vector37, len37, digest37);

	size_t len38 = 37;
	const char vector38[] = {'\xda','\x39','\xfb','\x86','\x23','\x7f','\x00','\x30','\x38','\x44','\xe6','\x1f','\xc6','\xcf','\xe7','\x79','\xe4','\x2a','\xf5','\x33','\x49','\x83','\x95','\x90','\xbc','\xd2','\xf0','\xe4','\xcb','\xbc','\x27','\x9e','\xc0','\xb7','\xe8','\x85','\xd1',};
	const char *digest38 = "ecb43de8c233a731b38e30c5696f8876761b7ea72efe283fd07bedf20029f47c6d2a4427823e100fb087abaf22d7eff42a951c97c3dd05f48a20163fa4367cba";
	err |= test_sha512(vector38, len38, digest38);

	size_t len39 = 38;
	const char vector39[] = {'\x3e','\x72','\x71','\xd2','\x07','\x0e','\xf0','\x95','\x39','\x46','\x20','\xc4','\xb0','\x16','\x57','\x6c','\x15','\x0f','\x34','\xbe','\xa6','\x07','\x84','\x61','\x3a','\x0f','\x66','\x0d','\x7f','\xa5','\xae','\x56','\x87','\x2b','\x88','\xc5','\x83','\x98',};
	const char *digest39 = "8154d0da634ab2266061acc123acb407650ffe9164a22de3fe29bf05393b2aece92cf4db00ea5b4341c31ddb7de151683c8a71b5a44d5c3175790feac67d18ee";
	err |= test_sha512(vector39, len39, digest39);

	size_t len40 = 39;
	const char vector40[] = {'\x31','\x1f','\xb6','\x7f','\x6a','\x07','\x84','\xbb','\x01','\xa2','\xd5','\xa3','\xf3','\x09','\x2c','\x40','\x7a','\x9d','\x33','\x22','\x31','\x9d','\xff','\x9a','\x79','\xf8','\x94','\x29','\x1c','\x5f','\xac','\x37','\x31','\x9f','\xb4','\x08','\x40','\x2e','\x18',};
	const char *digest40 = "1870fe913abb0a4b4f53b6581ae18322cd05328514556607f3f4d7b6a2ac8e9185d94d947d8b9c88e0efa66d89b59f7439c75fdadd1816f7412306ab2b59d664";
	err |= test_sha512(vector40, len40, digest40);

	size_t len41 = 40;
	const char vector41[] = {'\x76','\x51','\xab','\x49','\x1b','\x8f','\xa8','\x6f','\x96','\x9d','\x42','\x97','\x7d','\x09','\xdf','\x5f','\x8b','\xee','\x3e','\x58','\x99','\x18','\x0b','\x52','\xc9','\x68','\xb0','\xdb','\x05','\x7a','\x6f','\x02','\xa8','\x86','\xad','\x61','\x7a','\x84','\x91','\x5a',};
	const char *digest41 = "f35e50e2e02b8781345f8ceb2198f068ba103476f715cfb487a452882c9f0de0c720b2a088a39d06a8a6b64ce4d6470dfeadc4f65ae06672c057e29f14c4daf9";
	err |= test_sha512(vector41, len41, digest41);

	size_t len42 = 41;
	const char vector42[] = {'\xdb','\xe5','\xdb','\x68','\x5e','\xd7','\xcb','\x84','\x8c','\x09','\x45','\x24','\xc1','\x72','\x35','\x19','\xd4','\x9d','\xc6','\x6e','\xf9','\xfe','\x6d','\x57','\xe6','\x86','\x2a','\x64','\x35','\x75','\x0b','\xfa','\x0a','\x70','\xf1','\x04','\xf5','\xd3','\x96','\xe6','\x1a',};
	const char *digest42 = "2fa6e5b2c443a68050f093e7fb713bd6b18f6274c061ed61d79bf0688a61dba1940bcc30998276860943ab038902896d0fbf59b88b07c80de927037097150c40";
	err |= test_sha512(vector42, len42, digest42);

	size_t len43 = 42;
	const char vector43[] = {'\x9f','\xa8','\x3e','\x96','\xb2','\xa6','\xdf','\x23','\xfb','\x37','\x28','\x95','\x01','\x56','\x78','\xe0','\xb2','\xc9','\xcd','\x18','\xa8','\x54','\x2c','\x3e','\xaa','\x2c','\x43','\x5a','\x76','\xae','\x4d','\xc9','\xbd','\x51','\x36','\xd9','\x70','\xda','\xff','\x93','\x3a','\xcf',};
	const char *digest43 = "3a2c0ec88a3e5347cf0ea9c078838300ef7356f9a6c342063277c106b880a00ed2be205c13064097bd372fde38007bc306561eb4e74bba2bb20bd354aa690ca6";
	err |= test_sha512(vector43, len43, digest43);

	size_t len44 = 43;
	const char vector44[] = {'\x8a','\x5a','\x45','\xe3','\x98','\xba','\xc1','\xd9','\xb8','\x96','\xb5','\xa2','\xb4','\xe3','\x56','\x6b','\x91','\xd8','\x0a','\xd2','\x0c','\x97','\x7e','\xa7','\x45','\x0f','\xf2','\xef','\xb5','\x21','\xd8','\x2f','\x65','\x01','\x9e','\xe7','\x62','\xe0','\xc8','\x5c','\x6c','\xc8','\x41',};
	const char *digest44 = "3c704620f4066d79c1ff67752980f39ef3d9c1023fa5a213a5265376b14a15166ffe069b51df7710d8907fef9406bf375d502ce086ac82aff17229aaa7a5a334";
	err |= test_sha512(vector44, len44, digest44);

	size_t len45 = 44;
	const char vector45[] = {'\x49','\xcf','\xff','\xda','\xf4','\xd0','\x31','\xe3','\x3b','\x1d','\x28','\xa4','\x47','\x45','\x05','\x45','\xf6','\xc4','\x29','\x3b','\x38','\xd5','\xaf','\xbc','\xb9','\x88','\x39','\x76','\xc0','\x14','\xf0','\x80','\x57','\x6e','\xc6','\x91','\xac','\x1b','\xff','\x70','\xb7','\x42','\xef','\xab',};
	const char *digest45 = "8bcc4f1ea2b7862ef1591bfa73916665de8faf65439ddf5cc1be43cebfd5f60f205e835a2b186b675b041258c5cff42669316ce25b46a2f4d4218e102f0f5d6f";
	err |= test_sha512(vector45, len45, digest45);

	size_t len46 = 45;
	const char vector46[] = {'\x2f','\xf8','\x45','\xd8','\x5e','\xfb','\xc4','\xfa','\x56','\x37','\xe9','\x44','\x8d','\x95','\x04','\x96','\xf1','\x9d','\x8d','\x57','\xda','\x99','\xb7','\xbd','\x3d','\xf7','\x47','\x48','\x22','\xf0','\xa7','\x90','\x58','\x67','\x36','\x41','\x67','\x14','\xe3','\x64','\xc6','\xe1','\xfa','\xe0','\x4e',};
	const char *digest46 = "236f6f4ed6e858c02d51787e60c578f731f694f8e52b5df4ecd5b04dff14c78e56bad1028d6f626c29d85aeee151a2a2846d3eed5cfafa9854a69fea8af6d04a";
	err |= test_sha512(vector46, len46, digest46);

	size_t len47 = 46;
	const char vector47[] = {'\xcf','\xca','\x05','\xfd','\x89','\x3c','\x0f','\x00','\x5f','\x5f','\xf7','\x96','\xf4','\xda','\x19','\xba','\x27','\xa1','\xe7','\x29','\x95','\x6b','\x8b','\x71','\x5e','\x67','\xce','\x4b','\x2d','\x2a','\x38','\x2a','\x72','\xec','\x78','\x14','\xf2','\xf5','\x07','\xb1','\x82','\x52','\x09','\xa2','\x0f','\xcc',};
	const char *digest47 = "d80969284a4565add4dad6ab9b3bdf53446142f84aaf92d4b23dd22ee7241e6c81489ac8b246edcb6df9bd7b23d91a0c517f546feba4ed5790a2be6e165c1709";
	err |= test_sha512(vector47, len47, digest47);

	size_t len48 = 47;
	const char vector48[] = {'\xcf','\xc4','\x25','\x75','\x9a','\x9c','\x36','\xbb','\x9f','\x4b','\x32','\xee','\xd7','\x76','\x7a','\xf6','\x56','\x6f','\x68','\xde','\xd0','\xad','\xea','\xe2','\x5c','\x7a','\x70','\xca','\x78','\xec','\x09','\x77','\x4d','\x16','\xc8','\xbc','\x35','\x7f','\x6d','\x6f','\x7b','\xd4','\x41','\xbf','\x62','\xd9','\x42',};
	const char *digest48 = "b587a785cdf455cc9c544e756c1e306300aa3c59f8725012e68ab4d54020b6d227a164d9f83c905e86f8cebeef708a69f976d6e7b18b9bf78e9b98cc4a5cd1b6";
	err |= test_sha512(vector48, len48, digest48);

	size_t len49 = 48;
	const char vector49[] = {'\x09','\x7c','\x9d','\xb9','\x19','\x51','\x52','\x42','\xc9','\x9d','\x97','\x3a','\xcb','\x1d','\xc4','\xed','\x48','\x27','\x68','\xf9','\x74','\xeb','\x83','\xb4','\x65','\xf9','\xf6','\xc8','\x25','\x03','\x37','\x20','\x06','\xe4','\x49','\x08','\x35','\xe2','\xec','\x8f','\x92','\x30','\x11','\x30','\xbf','\xb7','\x90','\xb2',};
	const char *digest49 = "ff5a376f938e73014caef7fe3962944a7230d020b7087869ebe7ec70302721cd06fcdc981c893a425d05e2f99fe198e4db50a088aee2bf1263212110efed422c";
	err |= test_sha512(vector49, len49, digest49);

	size_t len50 = 49;
	const char vector50[] = {'\x77','\xe7','\x3d','\x38','\x7e','\x7b','\xc8','\x04','\x19','\xeb','\xf5','\x48','\x2b','\x61','\xd5','\x25','\x5c','\xaf','\x81','\x9f','\xb5','\x92','\x51','\xff','\x6a','\x38','\x4e','\x75','\xf6','\x01','\xea','\x02','\x6d','\x83','\xef','\x95','\x0e','\xd0','\xb6','\x75','\x18','\xfb','\x99','\xde','\xe0','\xd8','\xaa','\xef','\x1f',};
	const char *digest50 = "c4c89cd882ec945cc888fb9a0127d35e585ecc14a75e4b5b3d8330538d22da28cf6af1ebec96dc247f109cd2aaab9756e6946a3d80db8363a4da3e6ddbb510a1";
	err |= test_sha512(vector50, len50, digest50);

	size_t len51 = 50;
	const char vector51[] = {'\x31','\x7e','\x5d','\x9a','\xc7','\x3e','\xd0','\x63','\x3f','\xa1','\x8e','\xbe','\xbb','\xca','\x79','\x09','\xec','\x3a','\x5e','\xf7','\x90','\x47','\x8f','\x9c','\x38','\xca','\xce','\xc4','\x4f','\x19','\x6d','\x89','\x58','\x35','\xb4','\x25','\x77','\x44','\x83','\x04','\x33','\x41','\x38','\x1e','\x7a','\xf2','\xd3','\x83','\xe5','\x1a',};
	const char *digest51 = "b10bb04491b9c0c334709b407cda1d503efb6b63ee944f2d366b6855e6e63e5b80115be4be7ff63edecdfb5923792e68123976d79212b3884dec2179d1fcf382";
	err |= test_sha512(vector51, len51, digest51);

	size_t len52 = 51;
	const char vector52[] = {'\x20','\x94','\x61','\xf2','\x06','\x66','\xa3','\x46','\xfe','\xdf','\x4a','\x53','\x0f','\x41','\xa6','\xfa','\x28','\x0c','\x43','\x66','\x57','\x67','\xbe','\x92','\x3b','\xc1','\xd8','\x0b','\xbc','\xb8','\xc9','\xf8','\xf9','\x3a','\xd7','\x57','\x82','\xea','\x26','\x89','\xc8','\xc5','\xd2','\x11','\xd2','\x05','\x3b','\x99','\x31','\x45','\xa0',};
	const char *digest52 = "67b7a328d9444056a52ca2f695c5d3f3baafb625a14fb32eee8ff26a40ccb296bec1771a826b55f7ddb6170d4caf7795b612448e66a0f19356fe505927149b47";
	err |= test_sha512(vector52, len52, digest52);

	size_t len53 = 52;
	const char vector53[] = {'\x5d','\x61','\xaa','\x45','\xc4','\x46','\xf3','\xbf','\x93','\x60','\x4b','\x05','\x11','\x31','\x3b','\x4e','\x2f','\x30','\x6d','\x6b','\x04','\x6f','\xbd','\x94','\x79','\x7b','\x92','\x67','\x46','\x83','\x6f','\x2e','\x1d','\xbd','\xc5','\x61','\x24','\x06','\x0c','\x6c','\xa9','\xc9','\x11','\xb1','\x12','\x21','\x92','\xd1','\x12','\x42','\x08','\x27',};
	const char *digest53 = "d3931bde2bde8271ed18ca0b9148b12f6f16161e637e376fc961f65bc33bcacf2f6addf26a3eaa81b196653cc37e8a739ec5b3df870d8c38c8f28691c22a39bb";
	err |= test_sha512(vector53, len53, digest53);

	size_t len54 = 53;
	const char vector54[] = {'\x92','\x88','\xc7','\x95','\xbb','\x0b','\x86','\xc0','\x41','\x9d','\x9c','\x56','\x37','\xdc','\xc3','\x7b','\x39','\xbf','\xa1','\x8d','\x44','\x1e','\x3f','\xbf','\xca','\x75','\xbc','\x03','\x06','\xe5','\x43','\x2e','\x8e','\x7b','\x3a','\x56','\x27','\xb5','\xbc','\x7f','\xdc','\x42','\x4a','\x77','\x52','\x0a','\xbd','\xff','\x56','\x6e','\x7f','\x2b','\xb8',};
	const char *digest54 = "e363d0e95d8cd18c384016ebeed6d99c4fa2768e2bd58fca019c5108b9cde1cb46f3f884028a55ce282ec310a10037faa1b16b4a6a669957f0b00f350bbd63d0";
	err |= test_sha512(vector54, len54, digest54);

	size_t len55 = 54;
	const char vector55[] = {'\x78','\x04','\x27','\xdc','\x16','\x4b','\x2f','\x69','\xb8','\xc7','\xd5','\x69','\x26','\x6f','\x46','\x1e','\x2d','\x30','\xc8','\x8c','\x4c','\xd6','\x05','\x7f','\xb0','\x30','\xa6','\xcf','\x63','\x6f','\x24','\xe3','\xc0','\xd0','\xdb','\x74','\x2a','\x7b','\x61','\x93','\xfd','\xaa','\x15','\xee','\xc5','\x0d','\xfb','\x4f','\xae','\x6e','\xc7','\x65','\x3c','\x91',};
	const char *digest55 = "2964b009fb1bf996de12e030b9d6e0608ae8b9dbf2acfb9beb76fc5361cc104ee85c2a46fb7b4cee90848312da302de49afe61c546477e2b25d223d5e3d33560";
	err |= test_sha512(vector55, len55, digest55);

	size_t len56 = 55;
	const char vector56[] = {'\xec','\x2a','\x92','\xe4','\x7f','\x69','\x2b','\x53','\xc1','\x35','\x54','\x75','\xc7','\x1c','\xef','\xf0','\xb0','\x95','\x2a','\x8b','\x35','\x41','\xb2','\x93','\x82','\x70','\x24','\x7d','\x44','\xe7','\xc5','\xcc','\x04','\xe1','\x72','\x36','\xb3','\x53','\xda','\x02','\x86','\x74','\xea','\xb4','\x04','\x7d','\x89','\xec','\x5d','\xad','\x86','\x8c','\xfd','\x91','\xce',};
	const char *digest56 = "c83aca6147bfcbbc72c377efa8d53654ba0830c5a6a89e1d2a19b713e68fb534640deb833ca512247166dd273b5897e57d526f88eef58f6ff97baee0b4ee5644";
	err |= test_sha512(vector56, len56, digest56);

	size_t len57 = 56;
	const char vector57[] = {'\xc9','\x9e','\x31','\xad','\x4e','\x23','\xac','\x68','\xe1','\x5e','\x60','\x5d','\x0b','\x02','\x43','\x7f','\x81','\x47','\xc4','\x4f','\x54','\x45','\xa5','\x5b','\x68','\xa1','\x09','\x05','\x27','\x6c','\xce','\x86','\x76','\x48','\x1c','\x33','\xe8','\xcd','\x3e','\xfe','\x32','\x2b','\xb1','\x3f','\xe0','\x10','\x7b','\xb5','\x46','\xcc','\xbe','\xc7','\xb8','\xb3','\x8d','\x10',};
	const char *digest57 = "52992d45a88221d972958e9f2854adaa9a21d2bf7051e1f1019ae78004da50c5b55c144a02afffe539d753949a2b056534f5b4c21f248a05baa52a6c38c7f5dd";
	err |= test_sha512(vector57, len57, digest57);

	size_t len58 = 57;
	const char vector58[] = {'\x9a','\xa3','\xe8','\xad','\x92','\x77','\x7d','\xfe','\xb1','\x21','\xa6','\x46','\xce','\x2e','\x91','\x8d','\x1e','\x12','\xb3','\x07','\x54','\xbc','\x09','\x47','\x0d','\x6d','\xa4','\xaf','\x6c','\xc9','\x64','\x2b','\x01','\x2f','\x04','\x1f','\xf0','\x46','\x56','\x9d','\x4f','\xd8','\xd0','\xdc','\xcf','\xe4','\x48','\xe5','\x9f','\xee','\xfc','\x90','\x8d','\x9a','\xd5','\xaf','\x6f',};
	const char *digest58 = "994d1cda4de40aff4713237cf9f78f7033af83369ac9c64e504091ea2f1caff6c5152d6a0c5608f82886c0093b3d7fbadd49dfd1f9e0f85accf23bc7dad48904";
	err |= test_sha512(vector58, len58, digest58);

	size_t len59 = 58;
	const char vector59[] = {'\x58','\x42','\x51','\x2c','\x37','\x31','\x25','\x11','\xa3','\xd8','\xae','\x41','\xf5','\x80','\x1d','\xf6','\x0c','\xd6','\x82','\xd5','\x8b','\x4a','\x99','\x73','\x42','\xb6','\xe7','\x17','\xe9','\x40','\x06','\xc2','\x14','\x81','\x3e','\x6c','\x63','\xe7','\x55','\x91','\xf9','\x57','\xa7','\xec','\x30','\x17','\x79','\x83','\x8b','\xec','\x8a','\xe3','\xed','\x7f','\xeb','\xad','\x08','\x05',};
	const char *digest59 = "9763c43331ad0eb279d704c5f6e97e02da8724115026827f889e9fcda21f60fd230894ab35abb719890f3afa51afd31bc6852183b9c51059910af460abd2474d";
	err |= test_sha512(vector59, len59, digest59);

	size_t len60 = 59;
	const char vector60[] = {'\xca','\x14','\xe2','\xea','\x2f','\x37','\xc7','\x8f','\x78','\xef','\x28','\x0f','\x58','\x70','\x7e','\xc5','\x49','\xa3','\x1a','\x94','\x36','\x10','\x73','\xe3','\x77','\x01','\xbf','\xe5','\x03','\xe4','\xc0','\x1e','\xe1','\xf2','\xe1','\x23','\xe0','\x0e','\x81','\xa1','\x88','\xf0','\x8f','\xa0','\x50','\x82','\x57','\x09','\x12','\x8a','\x9b','\x66','\xbb','\x8a','\xe6','\xea','\x47','\xe4','\x1d',};
	const char *digest60 = "4600e022a02258739f67fdd367cc1e662631fb087918768352062b9b3c8de8dbca0e9ec751b91f284694fbddb8d325c0637bccb21dd2efa92e48dbab2e5e9c26";
	err |= test_sha512(vector60, len60, digest60);

	size_t len61 = 60;
	const char vector61[] = {'\x64','\x76','\x29','\xc7','\x79','\xb2','\x4c','\x1e','\x76','\xf4','\x17','\x44','\xab','\xa1','\x71','\x59','\x48','\x75','\x32','\xa0','\x15','\x6a','\x7d','\x82','\x64','\xdb','\x50','\xd6','\x45','\xe9','\x59','\x5f','\xf8','\x1e','\x0c','\x96','\xa8','\x50','\xf2','\xaa','\x56','\xc8','\x44','\xc6','\x13','\xa4','\xb8','\x92','\x72','\x7a','\x9b','\xfc','\x3d','\x3e','\x20','\x38','\x67','\x66','\xf8','\x05',};
	const char *digest61 = "5bc842fc2d3b7eb31d2d3044df3ec32af114feaa7cfc27ebc8630f46ab6f0c543f59b812e776e5303861d17da3f1f16097641f3b808d4d5cb3e483946409746c";
	err |= test_sha512(vector61, len61, digest61);

	size_t len62 = 61;
	const char vector62[] = {'\x1c','\x5d','\xc0','\xd1','\xdd','\x2e','\x4c','\x71','\x76','\x35','\xff','\x3e','\x9b','\x67','\xca','\xf9','\x57','\xae','\xc0','\xf8','\xf6','\x3c','\x1b','\x1e','\x22','\x1e','\x80','\x0a','\x4c','\x14','\x84','\x8f','\x4e','\xa0','\x6e','\x64','\x4e','\x5d','\x3e','\x1d','\xe5','\x92','\xef','\x5a','\x80','\x07','\xfa','\x3f','\x07','\x17','\x1b','\x24','\xbd','\x07','\x57','\x8d','\x68','\x96','\x3e','\x5c','\xb1',};
	const char *digest62 = "cbf1ea86fa5b3dbf67be82fac41e84cccd0d296c757169b37837d273ccc015eecd102b9ce1cff68fdc7f05d22f2b774734f62ded54c8ee0bf57a5a82010d74f5";
	err |= test_sha512(vector62, len62, digest62);

	size_t len63 = 62;
	const char vector63[] = {'\x8a','\x55','\x5e','\x75','\x47','\x7d','\x06','\x5b','\x3a','\xf7','\xe6','\x15','\x47','\x5f','\x37','\xc0','\xa6','\x67','\xf7','\x3a','\x4c','\x7a','\xf5','\xe4','\xa6','\x9f','\x28','\xa6','\x8d','\x9f','\x44','\x34','\x77','\x6a','\x8f','\x90','\xea','\xb7','\xf1','\xd1','\x37','\xeb','\x4b','\x22','\x64','\x3c','\x0a','\x0d','\x6a','\x16','\xfc','\xfa','\xa1','\xbd','\x62','\xf2','\x78','\x35','\x46','\xa9','\x69','\x5f',};
	const char *digest63 = "c088e4a3d7da2f6f99a8f3f717361108872b8ffef921b383c24b8061d4e7c27fc56f4f20dc8f952a14043c5650b5a9e777c49c41cfeb3f2de97ee2e16b2c3924";
	err |= test_sha512(vector63, len63, digest63);

	size_t len64 = 63;
	const char vector64[] = {'\xeb','\xb3','\xe2','\xad','\x78','\x03','\x50','\x8b','\xa4','\x6e','\x81','\xe2','\x20','\xb1','\xcf','\xf3','\x3e','\xa8','\x38','\x15','\x04','\x11','\x0e','\x9f','\x80','\x92','\xef','\x08','\x5a','\xfe','\xf8','\x4d','\xb0','\xd4','\x36','\x93','\x1d','\x08','\x5d','\x0e','\x1b','\x06','\xbd','\x21','\x8c','\xf5','\x71','\xc7','\x93','\x38','\xda','\x31','\xa8','\x3b','\x4c','\xb1','\xec','\x6c','\x06','\xd6','\xb9','\x87','\x68',};
	const char *digest64 = "f33428d8fc67aa2cc1adcb2822f37f29cbd72abff68190483e415824f0bcecd447cb4f05a9c47031b9c50e0411c552f31cd04c30cea2bc64bcf825a5f8a66028";
	err |= test_sha512(vector64, len64, digest64);

	size_t len65 = 64;
	const char vector65[] = {'\xc1','\xca','\x70','\xae','\x12','\x79','\xba','\x0b','\x91','\x81','\x57','\x55','\x8b','\x49','\x20','\xd6','\xb7','\xfb','\xa8','\xa0','\x6b','\xe5','\x15','\x17','\x0f','\x20','\x2f','\xaf','\xd3','\x6f','\xb7','\xf7','\x9d','\x69','\xfa','\xd7','\x45','\xdb','\xa6','\x15','\x05','\x68','\xdb','\x1e','\x2b','\x72','\x85','\x04','\x11','\x3e','\xea','\xc3','\x4f','\x52','\x7f','\xc8','\x2f','\x22','\x00','\xb4','\x62','\xec','\xbf','\x5d',};
	const char *digest65 = "046e46623912b3932b8d662ab42583423843206301b58bf20ab6d76fd47f1cbbcf421df536ecd7e56db5354e7e0f98822d2129c197f6f0f222b8ec5231f3967d";
	err |= test_sha512(vector65, len65, digest65);

	size_t len66 = 65;
	const char vector66[] = {'\xd3','\xdd','\xdd','\xf8','\x05','\xb1','\x67','\x8a','\x02','\xe3','\x92','\x00','\xf6','\x44','\x00','\x47','\xac','\xbb','\x06','\x2e','\x4a','\x2f','\x04','\x6a','\x3c','\xa7','\xf1','\xdd','\x6e','\xb0','\x3a','\x18','\xbe','\x00','\xcd','\x1e','\xb1','\x58','\x70','\x6a','\x64','\xaf','\x58','\x34','\xc6','\x8c','\xf7','\xf1','\x05','\xb4','\x15','\x19','\x46','\x05','\x22','\x2c','\x99','\xa2','\xcb','\xf7','\x2c','\x50','\xcb','\x14','\xbf',};
	const char *digest66 = "bae7c5d590bf25a493d8f48b8b4638ccb10541c67996e47287b984322009d27d1348f3ef2999f5ee0d38e112cd5a807a57830cdc318a1181e6c4653cdb8cf122";
	err |= test_sha512(vector66, len66, digest66);

	size_t len67 = 66;
	const char vector67[] = {'\x8e','\x8e','\xf8','\xaa','\x33','\x6b','\x3b','\x98','\x89','\x4c','\x31','\x26','\xc7','\x18','\x78','\x91','\x06','\x18','\x83','\x8c','\x00','\xac','\x85','\x90','\x17','\x3c','\x91','\x74','\x99','\x72','\xff','\x3d','\x42','\xa6','\x11','\x37','\x02','\x9a','\xd7','\x45','\x01','\x68','\x4f','\x75','\xe1','\xb8','\xd1','\xd7','\x43','\x36','\xaa','\x90','\x8c','\x44','\x08','\x2a','\xe9','\xeb','\x16','\x2e','\x90','\x18','\x67','\xf5','\x49','\x05',};
	const char *digest67 = "41672931558a93762522b1d55389ecf1b8c0feb8b88f4587fbd417ca809055b0cb630d8bea133ab7f6cf1f21c6b35e2e25c0d19583258808e6c23e1a75336103";
	err |= test_sha512(vector67, len67, digest67);

	size_t len68 = 67;
	const char vector68[] = {'\x52','\x76','\x1e','\x1d','\xac','\x0e','\xae','\xa8','\x98','\xe0','\xb0','\x7c','\xd2','\x4f','\x4b','\x2e','\x6b','\xb7','\xbc','\x20','\x0e','\xa4','\xb0','\x52','\x88','\x42','\xf1','\x7b','\x87','\x15','\x45','\x59','\xa2','\xea','\x94','\x45','\x9a','\x0e','\x48','\x0a','\xe0','\xbd','\xf9','\xf7','\x57','\xdd','\x4a','\x33','\x5a','\xed','\x0e','\x51','\x01','\x38','\xb0','\x24','\xa0','\x4e','\xd1','\xd5','\x91','\xb4','\x32','\x32','\x34','\xdb','\xd5',};
	const char *digest68 = "b826fe80494e19c51b42f2582b2d080ba6b90512f35f2db67dd7fd5ee532eaa16498afba08b4996cbcfdf8d1a2df6b1da939e8265115a48aefa42f38205db436";
	err |= test_sha512(vector68, len68, digest68);

	size_t len69 = 68;
	const char vector69[] = {'\x38','\x04','\xeb','\xc4','\x3c','\xbe','\xa8','\x0c','\x2b','\xd7','\xe4','\xfd','\xa5','\xc5','\x51','\x55','\x00','\xcd','\x2d','\x2b','\x84','\x6a','\x13','\x78','\xdb','\xf2','\x18','\xd5','\xc3','\x77','\x13','\x86','\x06','\xeb','\x3c','\xb8','\xac','\x88','\xf9','\x07','\x6f','\x6f','\xf4','\x43','\x6f','\x90','\x71','\x74','\x27','\xc9','\xdf','\x1b','\xa0','\x52','\xac','\xbb','\xe4','\x58','\x5e','\x98','\xb6','\xe8','\xe0','\xbf','\x80','\x0f','\x19','\x46',};
	const char *digest69 = "17dd6d87bc6773051e52047fd444996afa8124b0483fe121877f98553448772bd0e7751fc655e9cc2d29830211015d310f191474ca6adc0477a187c03b8fe252";
	err |= test_sha512(vector69, len69, digest69);

	size_t len70 = 69;
	const char vector70[] = {'\x22','\x49','\xd6','\x98','\xc4','\xd8','\x07','\xa8','\xe7','\xb4','\xde','\x21','\xc4','\x85','\x73','\x89','\x59','\xa0','\xd6','\x7e','\x5d','\x2c','\xa6','\xf7','\x79','\x83','\xdf','\xcc','\xb5','\xdb','\xf4','\x79','\x31','\x26','\x1e','\x1f','\x15','\x37','\xf3','\xcb','\xca','\x25','\x3a','\xfb','\x6b','\xf4','\xfe','\x5e','\x76','\x72','\xe1','\xdc','\xc8','\x60','\xb3','\xd6','\xc8','\xd2','\x43','\xaf','\xe2','\xd9','\x75','\x8b','\x37','\x5e','\x95','\x56','\x92',};
	const char *digest70 = "6af44563fc468d51182f6c3be58d45932af1d985c6f283976c91a9ff421f383fe21dc7322f397ccead583e26b3e3fda067976a7f34665df25a2ced7b4b09cdec";
	err |= test_sha512(vector70, len70, digest70);

	size_t len71 = 70;
	const char vector71[] = {'\x32','\xa9','\xc1','\x70','\x33','\x65','\x8c','\x54','\xf2','\x2c','\x71','\x35','\xdd','\xfc','\x87','\x9d','\xe9','\x4d','\x79','\x59','\x3e','\xf2','\xdc','\x7d','\x30','\x41','\xbf','\xa8','\x72','\x73','\x83','\x89','\x86','\x4e','\xed','\xa2','\x78','\x01','\x79','\x4c','\xcc','\x4f','\xf1','\xfc','\xb5','\xef','\x3f','\xc4','\x88','\x33','\x80','\x1d','\x6f','\xe9','\x59','\xe3','\x62','\x7f','\x8e','\xa1','\x53','\x6a','\xd0','\x0f','\xa9','\xc7','\xd7','\xd9','\xf0','\x43',};
	const char *digest71 = "6a47699dd3ada2f11bc4ea42072b06cc20857bf164497df1285400c250f5848b6f71957dbdc845f5daeab913036661f69387893fc2d61c25fa59b9d85b19f401";
	err |= test_sha512(vector71, len71, digest71);

	size_t len72 = 71;
	const char vector72[] = {'\x3d','\x65','\xf6','\x9a','\x59','\x0a','\x5b','\xaa','\xab','\xcd','\x27','\x4f','\xe3','\xef','\x9e','\x88','\x92','\x0f','\xfc','\x7a','\xdf','\x05','\xc1','\x6d','\x7b','\x0f','\x4d','\x18','\xd7','\x2b','\xac','\x1e','\x94','\xc3','\xb3','\xd8','\x3b','\x8f','\x4c','\x55','\x2e','\xb8','\x0e','\x9f','\xde','\x39','\x11','\x40','\x3f','\x8b','\x00','\x05','\x79','\x81','\x6f','\x02','\xe1','\x71','\x6f','\xd6','\x27','\x94','\x60','\x31','\xd0','\xaf','\x07','\x93','\xe7','\xf3','\xe1',};
	const char *digest72 = "ffb2d9450943c24b5933c24812459b75d3d9f380344c9bc06fa3e17ee448eca2f98ff79f7e2235ccd9f9a8176f68a2254bbc9b834d6ac8d2bfdbc1597c432c9f";
	err |= test_sha512(vector72, len72, digest72);

	size_t len73 = 72;
	const char vector73[] = {'\x76','\xff','\x8b','\x20','\xa1','\x8c','\xf1','\x04','\xf6','\xcd','\xb6','\x5e','\x2b','\xa8','\xf6','\x6e','\xcf','\x84','\x4a','\xf7','\xe8','\x5e','\x8e','\xf2','\xda','\x19','\xe8','\x84','\x8a','\x16','\x05','\x2e','\xc4','\x05','\xa6','\x44','\xda','\xfb','\x5c','\xa0','\x8e','\xc4','\x8f','\x97','\x32','\x7a','\xc5','\x2c','\x0e','\x56','\x21','\x84','\x02','\xc7','\x2a','\x9a','\x6d','\xc1','\xcf','\x34','\x4d','\x58','\xa7','\x16','\xa7','\x8d','\x7d','\x75','\x29','\x68','\x0b','\xae',};
	const char *digest73 = "f8858144c6d709dd0689a526a548a43f17494950ba2ac20544799e8ea27201d78bce5b921e29a7b4029278e68341ef2a0ca4ba3894566b3c8f8950e3e545a689";
	err |= test_sha512(vector73, len73, digest73);

	size_t len74 = 73;
	const char vector74[] = {'\xca','\x88','\xdd','\xdf','\xc8','\x76','\xa1','\x2f','\x45','\xf1','\x95','\x62','\xbc','\x9c','\xa2','\x50','\xf4','\x32','\x67','\xab','\x25','\x1a','\x7f','\x34','\x5c','\x3c','\x02','\x2e','\x20','\x14','\x4e','\x13','\x56','\x04','\x07','\x87','\x62','\xef','\x5c','\x8a','\x8f','\x03','\x8c','\xf1','\xb1','\xd6','\xa9','\x17','\x09','\xb5','\x9d','\xd0','\x68','\x39','\x6a','\x9e','\x97','\x1a','\xb6','\x28','\xf7','\x48','\x86','\xe7','\x65','\x38','\x4a','\x23','\x60','\x7c','\x1a','\x1e','\x6e',};
	const char *digest74 = "4f3d9eeef349ca51a7e419af1686f42795abde58a85335ce68d496e81e4436a80a61dc143a4300008c23a3e71f4ba98743195a3694a8d02fee11bd314569abc0";
	err |= test_sha512(vector74, len74, digest74);

	size_t len75 = 74;
	const char vector75[] = {'\x0a','\x78','\xb1','\x6b','\x40','\x26','\xf7','\xec','\x06','\x3d','\xb4','\xe7','\xb7','\x7c','\x42','\xa2','\x98','\xe5','\x24','\xe2','\x68','\x09','\x3c','\x50','\x38','\x85','\x3e','\x21','\x7d','\xcd','\x65','\xf6','\x64','\x28','\x65','\x01','\x65','\xfc','\xa0','\x6a','\x1b','\x4c','\x9c','\xf1','\x53','\x7f','\xb5','\xd4','\x63','\x63','\x0f','\xf3','\xbd','\x71','\xcf','\x32','\xc3','\x53','\x8b','\x1f','\xdd','\xa3','\xfe','\xd5','\xc9','\xf6','\x01','\x20','\x33','\x19','\xb7','\xe1','\x86','\x9a',};
	const char *digest75 = "6095c3df5b9db7ce524d76123f77421ce888b86a477ae8c6db1d0be8d326d22c852915ab03c0c81a5b7ac71e2c14e74bda17a78d2b10585fa214f6546eb710a0";
	err |= test_sha512(vector75, len75, digest75);

	size_t len76 = 75;
	const char vector76[] = {'\x20','\xf1','\x0e','\xf9','\xa0','\xe6','\x12','\x86','\x75','\x34','\x01','\x71','\xcd','\x24','\x8d','\xf3','\x0b','\x58','\x65','\x57','\x62','\x0b','\x61','\x5c','\xa3','\x9a','\x00','\xdb','\x53','\x43','\x15','\xa9','\x01','\x2d','\xbd','\xbf','\xd6','\xa9','\x94','\x98','\x6e','\xb8','\x29','\xdb','\xe6','\xcd','\xaf','\x3a','\x37','\xd4','\xf5','\x9a','\xc2','\x72','\x98','\x74','\x2c','\x8f','\x77','\x7b','\x6b','\x12','\x67','\x7f','\x21','\xeb','\x28','\x91','\x29','\x57','\x98','\x68','\x70','\x5f','\x27',};
	const char *digest76 = "b4ead3f860eabbd36c770d66c7356f8107acd1485c7c94178c2eaabd50266d7645d009972586ef83ed43ed92882137df5117b88f35231b894ec1741ae7501145";
	err |= test_sha512(vector76, len76, digest76);

	size_t len77 = 76;
	const char vector77[] = {'\x99','\x5c','\x8f','\x74','\x7e','\xa4','\x18','\xf7','\xd6','\x3a','\xba','\x22','\x60','\xb3','\x4a','\xc3','\xc7','\xdc','\xee','\xbb','\x78','\x43','\x8c','\xa4','\xb1','\xf9','\x82','\xb7','\xdb','\x97','\x98','\xec','\x1a','\x7f','\x32','\x62','\x22','\x64','\xcb','\x02','\x4c','\x0d','\x9e','\x60','\xe9','\x55','\xa6','\xe1','\xd6','\x77','\xc9','\x23','\x51','\x88','\x51','\x99','\x0a','\x45','\x9b','\x76','\x7d','\x0f','\x13','\xcd','\x80','\x34','\x60','\xf6','\x18','\x70','\xdb','\x33','\x91','\xb4','\x46','\x93',};
	const char *digest77 = "a00a601edeaca83041dc452d438a8de549594e25d843c2cf60a0e009fb92d87abe28a72690ab657c8d35b43cd02d22ec0755de229d1f922fa6ca18a6d6c2aaae";
	err |= test_sha512(vector77, len77, digest77);

	size_t len78 = 77;
	const char vector78[] = {'\x0f','\xeb','\x23','\xc7','\xe4','\xa1','\x9b','\xcb','\xd7','\x0b','\xd3','\x00','\xd7','\x6e','\xc9','\x04','\x5d','\x69','\x6f','\x8c','\x96','\x87','\xf4','\x9e','\xc4','\x15','\x44','\x00','\xe2','\x31','\xd2','\xf0','\x86','\x24','\x95','\x15','\x0c','\xf2','\x50','\xb6','\xf1','\x2f','\x17','\x2a','\x7d','\x13','\x0f','\x8f','\xa5','\xd1','\x75','\xbf','\x2f','\x25','\xe2','\x80','\x17','\x2c','\xcd','\xfb','\x32','\x79','\x51','\x70','\x11','\x65','\x30','\x27','\x28','\xa6','\x19','\xaa','\x2f','\x24','\x26','\x31','\xc9',};
	const char *digest78 = "eeb6dee30c119fb1e1eb5c15ff2b32d8b9c7464a4e4cc6815cd251a6bae29b49961dd5c2fa9c44a9b142ca062c7072cbf3db04299b767789040196bf0c06aa76";
	err |= test_sha512(vector78, len78, digest78);

	size_t len79 = 78;
	const char vector79[] = {'\xac','\x59','\xa1','\x10','\x62','\x3f','\x1a','\x64','\x66','\x6f','\x16','\x0e','\xd3','\x29','\x26','\x67','\x6c','\xb5','\xbe','\x25','\xdd','\x9d','\x96','\x2f','\x44','\x19','\x51','\xb0','\xef','\xcb','\x5d','\x6a','\x67','\xac','\x1a','\x4e','\xae','\x47','\x3e','\x49','\xc6','\x25','\x78','\x60','\x72','\x88','\x53','\xff','\x41','\x5c','\x5e','\x8e','\xc7','\x6a','\x8a','\x46','\x2e','\xcf','\xd3','\x43','\xee','\xac','\x22','\xda','\xd8','\x20','\x72','\x2c','\x59','\x73','\x32','\xfb','\xfd','\x94','\xeb','\xbd','\x32','\xc6',};
	const char *digest79 = "f65ea942ae0a47e73b02b1442e5b26083db79307f64dd34a039c476faf18d5c514bb77a2c412a6074a7afc326ea66c74e5705fe2abbabf274333325a15b61fd9";
	err |= test_sha512(vector79, len79, digest79);

	size_t len80 = 79;
	const char vector80[] = {'\x9e','\x3e','\x10','\x77','\xe1','\x33','\x3a','\x1f','\xb1','\xaa','\x63','\x3c','\xcf','\x2f','\x74','\x65','\x88','\xad','\x42','\x64','\x89','\xea','\x08','\xdf','\xf5','\x51','\x14','\x38','\xb5','\xf4','\xc0','\xb1','\x10','\xd1','\xa4','\xd4','\x7b','\x54','\x0a','\x12','\xb2','\x1e','\xa2','\xaa','\x07','\x05','\x78','\xcc','\xfa','\x5c','\x22','\xfe','\x0b','\x74','\x3e','\xc0','\xcc','\x62','\x1c','\x6b','\x3a','\x03','\xb7','\x5f','\x4d','\x3e','\xea','\x5d','\xce','\x89','\xe0','\x32','\x69','\xaf','\xcd','\x96','\x03','\xd0','\xdb',};
	const char *digest80 = "4b5c5df80c344c12388c723856cd06965b2190af652480476747dc2195ea3716f87c1762359583a5f31522f83f7833bec30f1f47d14540417dd463f5d258cd4a";
	err |= test_sha512(vector80, len80, digest80);

	size_t len81 = 80;
	const char vector81[] = {'\xe8','\x81','\xe3','\x28','\x4c','\x79','\xd8','\xf5','\x23','\x7e','\x69','\x9e','\x4f','\xbc','\xa8','\x40','\x90','\xc6','\x64','\xbb','\x53','\x22','\x9f','\x58','\xcb','\x08','\x42','\xb0','\x43','\x67','\x10','\xc9','\xb3','\x29','\xd9','\x81','\x91','\xb8','\xf0','\x30','\xe9','\xc1','\xdf','\x89','\xb0','\x38','\x58','\xc1','\x56','\x9c','\x6f','\xf4','\x9a','\x7c','\x07','\xc4','\xa2','\x3a','\x8a','\x43','\x4b','\x0f','\xde','\x13','\xbe','\x4f','\x94','\xcb','\x44','\xee','\x62','\x9d','\x5b','\x44','\xd3','\x36','\x09','\x0d','\x3d','\xe6',};
	const char *digest81 = "147d8071c7871ef9256cff32aa63ea031404fa5ee4ec09c56afdd5da919b0cc84a9d35d142c417715203316011cc620cd6855bb117063a5e52867facc680d5f4";
	err |= test_sha512(vector81, len81, digest81);

	size_t len82 = 81;
	const char vector82[] = {'\xe5','\x85','\x21','\x09','\x89','\x11','\x50','\x3d','\xe8','\x43','\x11','\x38','\x7d','\x37','\x5c','\x25','\x92','\x9e','\x6e','\x55','\x07','\x6e','\xb6','\x93','\x4f','\xd8','\xf2','\xb1','\xbb','\x7b','\x96','\x67','\xfb','\xd7','\x6d','\x5e','\xe2','\x04','\x82','\x87','\x69','\xa3','\x41','\xb1','\xf7','\x16','\xda','\x5b','\xdf','\xec','\xe6','\xc6','\x2a','\x9f','\x4d','\x4f','\x98','\x82','\x67','\xfc','\xe1','\xf5','\x61','\x55','\x40','\xdb','\xe3','\x75','\x32','\x4e','\xef','\x60','\x7c','\x91','\x0d','\x97','\x6b','\x45','\xa5','\xea','\x5f',};
	const char *digest82 = "f97ba056fa41f43b8e1987072a09e828c71c5ff6ad4e37f9ab6b89e2a078933dd23052fa72c6615b613904259e9ff9b55ef7b923b89bc8752f6babddd256e117";
	err |= test_sha512(vector82, len82, digest82);

	size_t len83 = 82;
	const char vector83[] = {'\x37','\x96','\xcf','\x51','\xb8','\x72','\x66','\x52','\xa4','\x20','\x47','\x33','\xb8','\xfb','\xb0','\x47','\xcf','\x00','\xfb','\x91','\xa9','\x83','\x7e','\x22','\xec','\x22','\xb1','\xa2','\x68','\xf8','\x8e','\x2c','\x9f','\x13','\x3e','\x5f','\x85','\x27','\xf1','\xb1','\x84','\x83','\x0e','\x07','\xc3','\x45','\x8c','\x83','\xa8','\xca','\x9f','\x9d','\x9c','\x69','\x98','\x76','\x0e','\x61','\x06','\x68','\xba','\x0f','\x22','\xe2','\x2b','\x65','\x6a','\x73','\x7e','\x97','\x8b','\x24','\x6a','\x17','\x84','\x0b','\x7d','\xc4','\x09','\x1d','\xa8','\x5f',};
	const char *digest83 = "c8a466199acbcbc93f2ce042968508c046901631e3118a2d0bf39a9b42b4197a379b3a86cdeca9df2de1a3eb71b79ae9bf2d6575eadf1878029c4093133f54d3";
	err |= test_sha512(vector83, len83, digest83);

	size_t len84 = 83;
	const char vector84[] = {'\x9a','\xf6','\x08','\xd0','\x31','\xcc','\xf3','\x09','\xd7','\x27','\x3c','\x60','\x7a','\x8e','\x5e','\x36','\x84','\x0d','\x44','\x9b','\x55','\xdb','\x5b','\x13','\xf0','\x3a','\xeb','\x9a','\xf4','\x9f','\xa7','\xe7','\xcf','\x13','\x83','\xee','\x2e','\xd9','\xc5','\xa8','\xb7','\x51','\x5f','\x16','\xfb','\x1c','\x7c','\x84','\xa6','\x81','\x59','\x0b','\xf9','\x0f','\x56','\x59','\x7b','\x84','\x4d','\xb5','\xeb','\xee','\x22','\x3d','\x78','\x10','\x9b','\x72','\x35','\x07','\x72','\xf7','\xc7','\x2e','\xa9','\x96','\x60','\x3e','\x1e','\x84','\xf2','\xba','\x5f',};
	const char *digest84 = "f0ded9495b4f64cac585be8a737cfa14247a4a81cdf7f01ebcb134ace71f5a83df2cd72e7773fea1e82beae17e13857372792c8231e2ab9fbeb633e399d5f0ae";
	err |= test_sha512(vector84, len84, digest84);

	size_t len85 = 84;
	const char vector85[] = {'\xd0','\xdf','\x1b','\xdf','\x1d','\xf6','\x20','\x32','\x41','\x72','\x2f','\xb9','\xc9','\xc1','\xcf','\x74','\x05','\x01','\x74','\x97','\xae','\x15','\x45','\x38','\xcc','\xf9','\x22','\x4a','\xd7','\x52','\xe6','\xce','\x1d','\x4a','\xe9','\x48','\x63','\x9a','\xca','\x70','\xcf','\xe8','\x6b','\x2b','\x06','\x54','\x3c','\xb9','\x91','\x4e','\xbd','\x30','\x85','\xaa','\x3e','\x29','\x63','\xf6','\xe9','\xb9','\x3d','\x0b','\x03','\xa3','\x1a','\xe2','\x6f','\xcb','\x9c','\xa9','\x74','\xee','\xe0','\x16','\xc0','\x91','\xa6','\xfc','\xac','\x37','\xb2','\x1c','\xc1','\xd7',};
	const char *digest85 = "c2da3ea3c8a3fd88a5bc5dea2bc076f861abedefae5a5fbd941ddfd1c41cc3312eb2dc826c2c0f65414fe72ebee447d2f9b1a6a56302660d1f86632ee80a175f";
	err |= test_sha512(vector85, len85, digest85);

	size_t len86 = 85;
	const char vector86[] = {'\x8c','\xbc','\x94','\x80','\x55','\x3a','\xce','\xf7','\xbc','\xdb','\xa9','\x71','\x6e','\xa8','\xd6','\x6b','\x41','\x31','\x78','\x09','\x17','\xde','\x2b','\x0b','\x04','\x80','\x45','\xfc','\xb3','\x2b','\x5c','\xac','\x05','\x48','\x08','\xe1','\xfc','\xe6','\xe9','\x4a','\xd8','\x51','\xec','\xb4','\x7f','\xe6','\xcb','\x80','\x22','\x25','\xd3','\x55','\x1e','\x08','\xea','\x12','\x20','\x93','\xd0','\x07','\x8d','\xad','\xa5','\x64','\x21','\x2e','\xac','\xf1','\xd6','\x39','\x4e','\x00','\x07','\xcc','\x62','\xa1','\xd5','\x95','\xab','\x14','\xca','\x08','\xa2','\x84','\xbc',};
	const char *digest86 = "63b39b88ceb848188b37316e04560e75a5340ab8d417932d231c997e892b41daa69d9fe3e9a14dd19ccfbbfa01488c208e7b946cfaf16ca2b1bf7c8d8da4e6b2";
	err |= test_sha512(vector86, len86, digest86);

	size_t len87 = 86;
	const char vector87[] = {'\x38','\xf1','\x84','\x44','\x8f','\x3c','\xf8','\x2a','\x54','\xca','\xfc','\x55','\x6a','\xff','\x33','\x6f','\x23','\xf9','\x14','\x9e','\x61','\x21','\x34','\xb3','\xfc','\x00','\xc8','\xa5','\x64','\x55','\x65','\x3d','\x88','\x64','\x0b','\x12','\xf6','\x90','\x62','\xb8','\x43','\x2c','\x43','\x35','\xad','\x8f','\x7a','\xb4','\xff','\x66','\xcb','\x7e','\xb5','\x4f','\x33','\x25','\x61','\xa3','\x6f','\x02','\x4d','\x92','\xc3','\xe2','\x62','\x76','\xf4','\xfd','\x48','\x61','\x96','\x28','\xcf','\xf8','\x8e','\x4b','\x8e','\x85','\xcf','\x14','\xca','\x47','\x67','\xed','\x99','\x0d',};
	const char *digest87 = "9a49265fc641c59f1a91872cdae490d3da73c0c60fd59648e1d17dba1a647a5b95629392bb4ff5163d1a3cb45427c1437a3b2e1d9f030c0a8bcc5ed22da9e2ed";
	err |= test_sha512(vector87, len87, digest87);

	size_t len88 = 87;
	const char vector88[] = {'\x70','\x90','\x06','\x18','\xb1','\xe9','\xe9','\xdb','\x62','\x29','\x6f','\xb6','\xc6','\x59','\x0c','\x9f','\x10','\xb0','\xa6','\x32','\x76','\x5c','\x48','\x9c','\x88','\x7f','\x1a','\xb7','\xc0','\x77','\x91','\x76','\x5a','\x62','\xe3','\x84','\x65','\xe1','\xbe','\x28','\x1b','\x1d','\x39','\x6c','\x6e','\x08','\x0b','\x7e','\xe3','\xe6','\xfa','\x56','\xa3','\x0b','\x97','\x99','\xd0','\xe6','\x29','\xbe','\x15','\x3e','\xe7','\x6f','\x81','\xbc','\x6a','\x32','\x95','\xaa','\x61','\x48','\x9b','\xfa','\x87','\xd5','\x3a','\x8a','\xd2','\x42','\x48','\xa6','\xed','\xe0','\xdf','\xcf','\xe9',};
	const char *digest88 = "1c8c3357ff1f8d6ac4defb3af462a73e09159e3a20c6506edd8cd3052df941c81f68c5fbb893912619e28640977fe8eaae8e9d5d4e7d5f132552cefab4540bac";
	err |= test_sha512(vector88, len88, digest88);

	size_t len89 = 88;
	const char vector89[] = {'\x4e','\x6d','\xda','\xe0','\xd8','\x05','\xaf','\xcd','\x10','\xa0','\x55','\xbc','\xe5','\x84','\xc8','\x48','\xd0','\x50','\xfb','\x29','\xfe','\x8f','\x1c','\x64','\xb1','\x8e','\x1a','\xbf','\xe4','\x6b','\x65','\x78','\x2e','\x6f','\xf5','\x36','\xe8','\x9d','\x8d','\x40','\x92','\x8b','\x41','\xed','\x73','\x71','\x36','\x5c','\x80','\x80','\xa9','\x64','\x7f','\x75','\x32','\xce','\x6c','\x6d','\x4a','\xc2','\x1c','\xfb','\x0c','\x80','\x20','\x78','\x38','\x51','\xec','\x9a','\x7d','\xbc','\x39','\x48','\xf8','\xfc','\xa7','\xad','\xf8','\xb2','\xa7','\x8c','\x04','\xd8','\x98','\xd3','\x1f','\xf6',};
	const char *digest89 = "5c2f996c779b91b3c4639311f54fabbdde7e2212b53dbae4828c8399588fc00d3b2ae60918aaaf6bb48bc757e52b2bcea84f5d15bf4ec25d5519fb54f6f26e1b";
	err |= test_sha512(vector89, len89, digest89);

	size_t len90 = 89;
	const char vector90[] = {'\x69','\x68','\x25','\xf6','\xd6','\xea','\x81','\x73','\xec','\x47','\xd0','\x95','\x9a','\x40','\x1c','\x4d','\xdf','\x69','\xf8','\xf0','\x8d','\xdd','\x67','\x8a','\x4d','\x2f','\xf9','\x76','\xe3','\xa4','\x37','\x2b','\xb3','\x9f','\x41','\x59','\x84','\x5c','\xb6','\x35','\x85','\xe1','\xd4','\x10','\x8d','\x32','\xe1','\x2f','\xa7','\xc5','\xc9','\xd7','\xce','\x35','\x08','\xa7','\xf5','\x3a','\xca','\x2b','\x4b','\xd9','\x51','\xad','\xbc','\xd8','\x98','\x4e','\xbb','\x75','\x36','\x56','\x3f','\x58','\x84','\xc9','\x0b','\xc5','\x02','\x3b','\x33','\x16','\xf7','\xe4','\xdc','\x69','\x58','\xf7','\x43',};
	const char *digest90 = "3ce940ca96b00011375daa95c65f66907d69b3eb3b8d779e6fc971afcc05e990bc4c541f434590f6b18b68c080d0f24475a3e764e9cb85343301314ee2fb661e";
	err |= test_sha512(vector90, len90, digest90);

	size_t len91 = 90;
	const char vector91[] = {'\x79','\xec','\xdf','\xd4','\x7a','\x29','\xa7','\x42','\x20','\xa5','\x28','\x19','\xce','\x45','\x89','\x74','\x7f','\x2b','\x30','\xb3','\x64','\xd0','\x85','\x2c','\xce','\x52','\xf9','\x1e','\x4f','\x0f','\x48','\xe6','\x1c','\x72','\xfa','\x76','\xb6','\x0d','\x30','\x02','\xca','\xe8','\x9d','\xfc','\x55','\x19','\xd3','\x43','\x0b','\x95','\xc0','\x98','\xfa','\x46','\x78','\x51','\x6b','\x5e','\x35','\x51','\x09','\xea','\x9b','\x37','\x45','\xaa','\x41','\xd6','\xf8','\x20','\x6e','\xe6','\x4a','\xe7','\x20','\xf8','\xd4','\x46','\x53','\xb0','\x01','\x05','\x7f','\x2e','\xba','\x7f','\x63','\xcd','\x42','\xf9',};
	const char *digest91 = "ba3d0fe04470f4cf8f08c46d82ae3afd1caea8c13bebbe026b5c1777aa59860af2e3da7751844e0be24072af48bc8a6fd77678aaee04e08f63395f5c8a465763";
	err |= test_sha512(vector91, len91, digest91);

	size_t len92 = 91;
	const char vector92[] = {'\x92','\x63','\xfe','\x75','\xe8','\xf6','\xc7','\xd5','\xd6','\x42','\xe2','\xca','\x6a','\x6e','\xea','\x4f','\x44','\xe9','\xa0','\xf2','\x49','\x51','\x3e','\xd7','\x9c','\x94','\x09','\xff','\xca','\x55','\x26','\xca','\x44','\x91','\xae','\xbb','\x13','\x82','\x05','\x7c','\xc7','\xc3','\x67','\x22','\xb0','\xb6','\xc3','\xb1','\x51','\x23','\xcd','\xe3','\x12','\x21','\x4f','\x25','\x35','\x3a','\xbf','\xe3','\x0b','\xca','\x17','\x05','\x68','\xa8','\xe1','\xba','\x54','\x08','\x91','\x74','\x03','\xa0','\x18','\x34','\x08','\x0a','\xb6','\x07','\xc5','\x6a','\x10','\xd0','\x26','\x50','\x82','\x49','\x8f','\xe0','\xb6',};
	const char *digest92 = "7736d7a7fc1eb05857ce7d88abfffa87f58c670bfdfc0a8031f60f379e4b6ad94ac8f13ffe28c697809b5cfac7f13be01e7496a85237c4025539051fb2e32fb6";
	err |= test_sha512(vector92, len92, digest92);

	size_t len93 = 92;
	const char vector93[] = {'\x78','\xc1','\x7b','\xfe','\x0e','\x02','\xeb','\x52','\x6d','\x1a','\x44','\xa1','\xac','\x12','\x7b','\xe0','\x82','\x18','\x14','\x52','\xb6','\x25','\x39','\x4b','\xd6','\xdc','\x09','\x3a','\x2c','\xb4','\x32','\xe6','\xee','\x59','\xc2','\xf8','\xb5','\x50','\x3a','\xba','\x30','\xda','\xe4','\x1e','\x1a','\x1c','\x67','\x02','\x69','\x7c','\x99','\xb2','\xc9','\x4e','\x94','\xaf','\x48','\xb0','\x0c','\xaf','\x53','\xb2','\xe0','\xe4','\xe1','\xbb','\xee','\x81','\xee','\x28','\x2c','\x7b','\x2b','\x35','\xf5','\x8c','\xf4','\x21','\xa0','\x7e','\x82','\x8d','\x57','\xa6','\x62','\x26','\x26','\xaf','\x25','\x83','\x53','\x99',};
	const char *digest93 = "b56b6e343166328523e0d1693e5174da643ae83cf69c85a7b3c3bee247b77b84702069d9e6b4cab03bf17fe612009bf4239683ca78ca7e876aca7d07603ba714";
	err |= test_sha512(vector93, len93, digest93);

	size_t len94 = 93;
	const char vector94[] = {'\x29','\x8b','\xb3','\x04','\xa9','\x20','\xf9','\x60','\x44','\x7d','\x8f','\xd3','\x8b','\x06','\x1b','\xf8','\xfe','\x4a','\xc1','\xf8','\x71','\xd8','\xa0','\xfe','\xb4','\x54','\x9f','\xeb','\x72','\xca','\x69','\x4a','\x5a','\x41','\xb6','\x86','\x7d','\x94','\xcd','\x5a','\xf7','\x7d','\x46','\x8a','\xd2','\xf3','\x15','\xd1','\x27','\xb6','\xc4','\x1a','\x86','\x28','\x00','\xf3','\x98','\x5e','\x57','\x3e','\x03','\x77','\x40','\x29','\x8e','\x2c','\x5c','\x61','\x86','\xa9','\xfb','\x83','\x60','\x9b','\xe2','\xd4','\x9f','\x8b','\x4c','\x31','\xf9','\x6a','\x2e','\x49','\xb5','\x6d','\xbf','\x09','\x57','\x1b','\x38','\x58','\x7f',};
	const char *digest94 = "34e3878627904ffbbbd85266cc973c34f931e3cab5d4c31f841c553dd69f84838206067df4f9f3b9102001be19267151e673f5c2d4c2f8438a6999a0a325487d";
	err |= test_sha512(vector94, len94, digest94);

	size_t len95 = 94;
	const char vector95[] = {'\xa3','\xcf','\x71','\x4b','\xf1','\x12','\x64','\x7e','\x72','\x7e','\x8c','\xfd','\x46','\x49','\x9a','\xcd','\x35','\xa6','\x40','\xdd','\x39','\x3d','\xdd','\x26','\x3c','\xd8','\x5c','\xf6','\x22','\x5f','\x59','\x89','\x0a','\x06','\x86','\xda','\xd1','\xc5','\x4e','\xb8','\xd8','\x09','\xb8','\x1c','\x08','\xa9','\x8d','\xba','\x13','\x1b','\xbd','\xd6','\xfc','\xe8','\xff','\x59','\xd9','\x5d','\xb8','\x24','\xd8','\x83','\x1e','\xa4','\x80','\x52','\x9d','\xa7','\x39','\x22','\x7a','\x6e','\x0f','\x62','\xb6','\x03','\xb3','\x8c','\x35','\xcd','\xc2','\x58','\x1f','\x61','\x4a','\x31','\x87','\x9b','\x8b','\xe5','\x4a','\xee','\xfa','\xa0',};
	const char *digest95 = "6f230ae4903ddbef0ba384c2e3506eab318bfd1a46ea76099f65a3fd529c91bc2865b9fd943e346de64626b8529f9db1377bf2c5e0129c66b50c6a5cfb364b3a";
	err |= test_sha512(vector95, len95, digest95);

	size_t len96 = 95;
	const char vector96[] = {'\x0a','\x42','\x7a','\xe5','\x5e','\xf3','\xa7','\xe6','\x04','\x4a','\x08','\xcf','\x61','\x28','\xcb','\xaa','\xab','\xfd','\x77','\x6c','\x4e','\x93','\x74','\x70','\x8f','\x2e','\xce','\x24','\x6f','\xd7','\x36','\x03','\xd2','\xf5','\x4a','\xc3','\xe0','\x1d','\x16','\xcf','\xac','\x2b','\xda','\xf7','\x13','\x92','\x0d','\x66','\xe8','\xf0','\xa3','\xd5','\x4e','\xe6','\x8c','\xff','\x64','\x26','\x7d','\x55','\x28','\xcd','\xf2','\xf2','\x95','\xf4','\x74','\xd1','\x0f','\x81','\x17','\x3e','\x01','\x43','\x48','\x8a','\xc5','\x3f','\xc5','\x03','\xc4','\x44','\xed','\x23','\xde','\xc6','\x3a','\x08','\x0c','\xe9','\x0c','\x24','\x43','\xdb','\xa8',};
	const char *digest96 = "f6bbe5d0cf13ddf41c1436748a5d1ccae2948547b452c2171c7c8e8b66c6ae4de3c0e8b2962bcb60d3de3608479f80e455c9024d9716c38f6f1206861ab1eaac";
	err |= test_sha512(vector96, len96, digest96);

	size_t len97 = 96;
	const char vector97[] = {'\x2c','\xbb','\xb8','\x75','\x11','\xf4','\x94','\x8e','\xfe','\xc3','\xa6','\x1b','\x51','\x1e','\xde','\xdb','\x1d','\xda','\x8b','\x6e','\xcf','\xc0','\x21','\x0c','\x11','\xe4','\x3a','\x77','\xee','\x32','\xdc','\x2e','\x37','\x4a','\xfa','\xe4','\x26','\x8e','\x3d','\x30','\x42','\x78','\x04','\x86','\x82','\x32','\xa9','\x66','\xb5','\x60','\x06','\xd3','\x21','\x40','\x37','\x07','\x6b','\xf6','\xa2','\x65','\xb7','\x21','\x35','\xaf','\x0f','\xb2','\xef','\x79','\x09','\xfe','\xa2','\xde','\xa4','\x12','\xf7','\x71','\x74','\x46','\xb2','\x76','\xff','\x15','\x37','\x53','\x66','\x2b','\x4d','\x41','\x48','\xc0','\x23','\x47','\xe3','\x25','\x91','\x69',};
	const char *digest97 = "76897b87a8a1cf835c434f6d391c9e5227351af9d3e20a3389c796b98b424281a59068d9c8d567ec2bebc435b0126b059e2d86394a9854d6611e1c922f385496";
	err |= test_sha512(vector97, len97, digest97);

	size_t len98 = 97;
	const char vector98[] = {'\x2b','\x23','\x32','\x4c','\x99','\x92','\xf6','\x0a','\x7f','\xc0','\x10','\x15','\x9a','\x03','\xcb','\x9a','\x2b','\x29','\x0d','\xf4','\xfa','\x6a','\x82','\x35','\x9b','\x9a','\xf6','\x02','\xf0','\xa4','\x03','\xa5','\xef','\x33','\xed','\x5d','\xa5','\xb2','\xca','\xf8','\x7b','\x77','\xe6','\xa4','\xb9','\x3b','\x65','\x03','\x48','\xce','\x2a','\x7d','\xbc','\x08','\xf8','\xda','\x92','\x03','\xd7','\x10','\xb5','\x87','\xba','\x59','\x47','\xc6','\x5e','\x89','\x9f','\x4a','\x75','\x9f','\x8e','\x2b','\x04','\x9a','\xe7','\x85','\x0a','\x8e','\x3e','\x29','\x62','\xf6','\xef','\x93','\xea','\x4c','\x63','\x1d','\xe5','\xd7','\x8e','\x72','\x9e','\xc5','\xbc',};
	const char *digest98 = "3beea0b373ed09cf1c919c51d86d642c9125e0ee81698dc4cbadf02e9e6925efb562fd9b87301a6377ca192be79c4118deabc450b54639000c2e312945451fb5";
	err |= test_sha512(vector98, len98, digest98);

	size_t len99 = 98;
	const char vector99[] = {'\x40','\x22','\xf9','\x30','\xc7','\x03','\x3b','\x00','\xd9','\x86','\xc6','\x5f','\xf6','\xbb','\xbd','\xf9','\xeb','\xd0','\xe5','\x8c','\x52','\x84','\x4f','\xf6','\x58','\xdf','\x38','\x93','\xc3','\x20','\x2d','\xc5','\x33','\xf8','\x73','\xd4','\xa7','\xf5','\xa5','\xf9','\x44','\x41','\x9f','\xb5','\x52','\x8c','\x9b','\x67','\x88','\x47','\x9a','\x1e','\x89','\x13','\x06','\xac','\xae','\x79','\x95','\xfc','\x06','\xdb','\x70','\xa5','\x9b','\xaa','\x95','\xbe','\xf7','\xda','\x79','\xf5','\xe7','\x93','\xf2','\xdb','\x7f','\x2a','\x55','\x82','\x5e','\x4f','\xdb','\x4a','\x34','\x88','\x4a','\xf8','\x81','\xde','\xd1','\x08','\x9f','\xd5','\x33','\x45','\x02','\xa2',};
	const char *digest99 = "0358775bbb733ccc49e78f544aeee512370d480d0e13c7e8d5c444c423e592146b45fdb91a1b694d35e36b60e4bc8397fca8bb9790e619339778b9cd1abe3fe9";
	err |= test_sha512(vector99, len99, digest99);

	size_t len100 = 99;
	const char vector100[] = {'\x1c','\xb7','\x7b','\xa4','\x3c','\xe7','\x7e','\x23','\x6b','\x9f','\xc9','\x25','\xf5','\x89','\xb1','\xc0','\x70','\x78','\x0a','\x84','\xf9','\x9e','\x8f','\x50','\xc1','\xff','\x84','\x6a','\xc9','\x25','\x99','\xcf','\xe9','\x16','\x12','\xc8','\x17','\x83','\x25','\xbe','\xe6','\x42','\xa3','\x4f','\x4d','\xff','\xdb','\xa2','\xaa','\x2e','\xbc','\xf7','\x06','\x43','\x39','\x82','\x9b','\x26','\xf2','\x79','\x93','\xe1','\x10','\x6c','\x13','\x9c','\x70','\xd5','\x78','\xcc','\x05','\xf0','\xe1','\xa7','\x77','\xcc','\xed','\xdb','\x10','\xa2','\xc6','\x7f','\xd9','\x67','\x5e','\x4a','\x00','\x9d','\xf8','\x03','\x7d','\x6e','\xeb','\x38','\xf5','\xfb','\xa2','\x33','\xdf',};
	const char *digest100 = "6502f46551a3fab3a96428fb97801d7a4aa2f17fef6603238df84e17c74309ed3d9489c8b16a9384ee634a3f86d0b3ba9a4dbc9c51ec8bd4bf8d61de6d3d87d7";
	err |= test_sha512(vector100, len100, digest100);

	size_t len101 = 100;
	const char vector101[] = {'\x52','\x16','\x7d','\xe2','\xd6','\xc5','\x02','\xd9','\x9f','\xa1','\x0c','\x27','\xb2','\xab','\x62','\x03','\xbd','\xeb','\xc2','\xca','\xfb','\xbf','\xde','\xf1','\x58','\x72','\xa4','\x3d','\xd6','\x10','\xc2','\x36','\x2f','\x79','\x6a','\xd9','\xbc','\xb5','\x52','\x8d','\x95','\x87','\x00','\x58','\xfa','\x45','\x44','\x53','\xf1','\xe6','\x06','\x5b','\x31','\x5d','\x41','\x0a','\x3f','\x26','\x50','\xe5','\xd7','\x1e','\x69','\xd7','\x8d','\x97','\x67','\xdf','\xb4','\xac','\xcc','\x05','\x7f','\xd2','\x06','\x92','\x66','\xb0','\xf1','\x80','\xcb','\x31','\x9e','\x30','\xde','\xd7','\x53','\x5b','\xbe','\x52','\xd2','\x4b','\xe1','\x51','\xde','\x4b','\xb5','\x98','\xfc','\x5c',};
	const char *digest101 = "25cb3ed3983a91b4cf37a65193916c5e3e211b63e943e2f7b50a85d349a463b941aad33eff16561bdfdc92fda06a4e1d94b162de48f06d3c626940b31020925f";
	err |= test_sha512(vector101, len101, digest101);

	size_t len102 = 101;
	const char vector102[] = {'\xce','\xde','\x66','\x97','\xd4','\x22','\xdd','\xaa','\x78','\xe2','\xd5','\x5a','\xe0','\x80','\xb8','\xb9','\xe9','\x35','\x6c','\x69','\xbc','\x55','\x82','\x01','\xa2','\xd4','\xb0','\xb3','\x19','\x0a','\x81','\x2c','\x27','\xb3','\x4b','\xbc','\xee','\x3a','\x62','\xb7','\x81','\x37','\x8b','\x1b','\xf6','\x36','\xb3','\x72','\xbc','\xba','\xe1','\xfa','\x2f','\x81','\x6a','\x04','\x6a','\x0a','\x64','\x9a','\x5c','\x55','\x5c','\x64','\x1f','\xea','\x4c','\xcd','\x84','\x1c','\xc7','\x61','\xf3','\x8f','\x77','\x79','\x72','\xf8','\xc9','\x1b','\x03','\x24','\xe7','\x1c','\x33','\x3c','\xe7','\x87','\xf0','\x47','\x41','\x43','\x9b','\xf0','\x87','\xef','\x5e','\x89','\x50','\x11','\xc0',};
	const char *digest102 = "0be42a25d77ac6ad995c6be48e783380bad25a61732f87cefb0cce1a769cd69081f494a1a12d657664ef2b4d9c41f2ee83f6e9a84327d8756af9f985595e7d3b";
	err |= test_sha512(vector102, len102, digest102);

	size_t len103 = 102;
	const char vector103[] = {'\x56','\xd1','\x8d','\x3e','\x2e','\x49','\x64','\x40','\xd0','\xa5','\xc9','\xe1','\xbc','\xb4','\x64','\xfa','\xf5','\xbc','\x70','\xa8','\xb5','\x62','\x12','\x4f','\x5f','\xc9','\xe9','\xde','\xb5','\xfe','\xe6','\x54','\x4b','\x94','\x5e','\x83','\x3b','\x8b','\x5d','\x13','\x1b','\x77','\x3e','\xcb','\x2c','\xdd','\x78','\x0c','\xd4','\xe1','\xbb','\x9e','\x4f','\x1e','\x3c','\xb0','\xa1','\xd6','\x4d','\x19','\xcf','\x4b','\x30','\xe4','\x4e','\x6c','\x2d','\x0c','\xbc','\xb4','\xe2','\x84','\xce','\x50','\xdb','\x7a','\x8a','\x80','\x62','\xdd','\xb6','\x3f','\x98','\x1d','\x90','\x26','\xc5','\x32','\xbf','\x8e','\xed','\xdf','\x8a','\xf5','\xa4','\x38','\x48','\xa3','\x22','\x62','\x17','\x8c',};
	const char *digest103 = "982dc61c91a93770582eee8025aa55da8e9edb966bf5cf70d4a6534c0d53a2789a8c4fb65b7fed478cda02ed1e0d198d85c5c735b2417c5fab5d34e969fc8e7e";
	err |= test_sha512(vector103, len103, digest103);

	size_t len104 = 103;
	const char vector104[] = {'\x25','\xa7','\x32','\x0d','\xfa','\xec','\x5a','\xf6','\x5d','\xa4','\xd0','\xf8','\x68','\x8e','\x29','\xe8','\xe9','\x55','\x32','\xec','\xc1','\x66','\x79','\xea','\x8a','\xff','\x0f','\x40','\x7d','\x89','\x8d','\xb6','\x92','\x28','\x55','\xb0','\xe8','\x90','\x1a','\xa9','\x68','\x1a','\xa3','\xdc','\xa6','\x17','\xcb','\x44','\x07','\x64','\xcd','\xc7','\x29','\x3f','\xbe','\xaf','\x7f','\x58','\x5b','\x59','\x3c','\x2b','\x05','\x31','\x73','\x8e','\x0a','\xde','\x7c','\x86','\x26','\xb9','\x99','\x5f','\x4a','\x84','\xd9','\xfc','\x9b','\x59','\x3d','\x6b','\xbe','\xe0','\x1a','\xbc','\x53','\xc5','\xbe','\x14','\xbf','\x69','\x56','\xfd','\x2f','\xd8','\x10','\x00','\xda','\xfc','\x7c','\x76','\x86',};
	const char *digest104 = "749c928c3d5510925bfe98659025b0ed7c01acd4d59a9bf1c54863a088091771dc9d407bdbf83b0f44b0902e10349ba79c84d0981d5e8c4f5c733a117fed0790";
	err |= test_sha512(vector104, len104, digest104);

	size_t len105 = 104;
	const char vector105[] = {'\x3d','\x71','\x77','\xb2','\x8f','\xfd','\x91','\x6e','\x7e','\x06','\x34','\x89','\x58','\x33','\xba','\x0b','\xd9','\xe0','\x65','\x3d','\xf2','\xcc','\x42','\x02','\xc8','\x11','\x53','\x6a','\x00','\x5a','\xec','\x85','\x3a','\x50','\x5e','\x75','\xdb','\x55','\xd3','\xc7','\x10','\x75','\x79','\x04','\x10','\x99','\xe3','\x82','\xa1','\xfe','\xac','\x80','\xdd','\xe6','\x5d','\x72','\x36','\x8e','\x90','\x9a','\xb8','\x5f','\x56','\xd8','\x8e','\x68','\xd7','\xc3','\xc8','\x0c','\x38','\xf8','\x5b','\xf8','\xc2','\xb3','\x69','\x59','\x40','\x9c','\xc3','\x4b','\xa8','\xe3','\xad','\x94','\xfe','\x8e','\xe1','\x92','\x76','\x12','\xd6','\x72','\xd9','\x21','\x41','\xa3','\x29','\xc4','\xdd','\x8a','\x88','\xa9',};
	const char *digest105 = "14a331508cd7d94fcce56a66bf65f20870a281c8442f8dbd4c2371454a2b66f8d0994a0b67692e771efc6a5e0b887acae7d6f4ec7338e1aa89f2abc7034c4e4c";
	err |= test_sha512(vector105, len105, digest105);

	size_t len106 = 105;
	const char vector106[] = {'\xc0','\x33','\xe4','\xa5','\x12','\x29','\x7c','\xae','\xcd','\xbe','\xad','\x89','\x2b','\x11','\xa9','\xf7','\x00','\x7a','\xf9','\xa7','\x4b','\xca','\xb8','\x9e','\x0b','\xd4','\xff','\xdd','\x54','\x2c','\xa0','\x3e','\xa1','\x2e','\x17','\xa0','\x6c','\x42','\xbd','\x43','\xfc','\x5f','\x3f','\x75','\x7f','\xce','\x4f','\x6f','\x58','\x31','\x99','\x7a','\xba','\xc3','\xf9','\x56','\x76','\xe1','\xeb','\xdb','\x11','\xca','\x43','\xe1','\x1a','\xa3','\x1e','\x5e','\xba','\xbe','\x18','\xce','\x8d','\x1b','\xbf','\xd8','\xb0','\x2f','\x48','\x2e','\x1c','\xe5','\x81','\xb5','\x32','\xe3','\x07','\xe6','\x96','\x0e','\xb9','\x74','\x41','\x50','\x6c','\x2e','\xd2','\x99','\xe1','\x28','\x25','\x23','\xf4','\x15','\x27',};
	const char *digest106 = "95ac9b7d22aa458921874c4b4331e7d64761853217c3f83c601abcbccd7e2eaa6ca6ce9a22ebcfe5046d52f8a09097f043ab8bc59243fd770090bb432c3155e9";
	err |= test_sha512(vector106, len106, digest106);

	size_t len107 = 106;
	const char vector107[] = {'\x69','\xff','\xf0','\xf1','\xa3','\xdb','\xfb','\x36','\xe3','\x2f','\x02','\x58','\x19','\xfa','\x99','\xea','\x9a','\x0e','\xda','\xef','\x73','\x14','\x5b','\xf7','\xfc','\xd0','\x5d','\x8b','\xb0','\xa6','\x46','\xcb','\x3b','\x5d','\x52','\x56','\xd5','\x24','\x85','\x6a','\xcf','\xd2','\xe4','\x4d','\x6b','\x72','\xe4','\xeb','\xf1','\xff','\x23','\xc0','\xff','\x6c','\x56','\xf8','\x21','\xe7','\x82','\xd5','\xa1','\x5f','\x70','\x52','\xa1','\x44','\x5b','\x06','\x66','\x8e','\xeb','\x4a','\xf7','\x00','\x67','\x9e','\xe7','\xae','\x26','\x49','\x6f','\xbd','\x46','\x40','\xc0','\x6a','\xa1','\x49','\x96','\x4d','\xfd','\x60','\x11','\xdf','\x83','\x5a','\xc1','\x3b','\x73','\xc8','\xff','\x21','\x15','\x1e','\x84','\x40',};
	const char *digest107 = "45d4daa652558d1c12beb0f5662c712f325b4c802fc6eb9ee039c949d002bb786f1a732712be941f9c5c79b3e5c43064d63a38578e5a54ee526acb735b9ad45f";
	err |= test_sha512(vector107, len107, digest107);

	size_t len108 = 107;
	const char vector108[] = {'\xb2','\xc4','\x39','\xc9','\x7a','\xb7','\xc6','\x37','\x36','\xb3','\x79','\x63','\x24','\xd6','\x8e','\xeb','\x7a','\x47','\x1e','\xd1','\x42','\xbd','\x96','\x22','\x68','\x41','\x67','\xd6','\x12','\x34','\xff','\xf8','\x2f','\x93','\xf9','\x07','\x53','\x7a','\x90','\x9b','\xc2','\xe7','\x5a','\x4b','\xcb','\xc1','\x33','\xcf','\x57','\x19','\x76','\x62','\xc1','\xaf','\x74','\x6a','\xe8','\xb8','\x1e','\x5b','\x83','\xde','\x05','\xd9','\xb5','\x89','\x85','\x1d','\xe2','\x5d','\x3c','\x99','\xc0','\x04','\xc1','\xdf','\xb1','\x2d','\x93','\xbf','\x50','\xd4','\x50','\xaf','\x49','\xc4','\x28','\x71','\x6f','\x5b','\x90','\xef','\x08','\x8e','\x3b','\x6a','\x6b','\x2c','\x46','\xd3','\xce','\x67','\xb3','\x79','\x59','\x90','\x18',};
	const char *digest108 = "c48ec83be5fa669e6ec8db90aca9676cfe2ec0d5e8e7a2431687bb953c0a300be3db4075cca3bac4dfa4d971baf0fa1aff46639db4b238856ff36d1dfcd520f1";
	err |= test_sha512(vector108, len108, digest108);

	size_t len109 = 108;
	const char vector109[] = {'\xc0','\x16','\xf5','\x22','\xf2','\x6b','\x74','\x70','\xe9','\x22','\xb9','\xa2','\x87','\xe6','\xd4','\x5f','\x6c','\x28','\x81','\x3b','\x68','\xc1','\x45','\x7e','\x36','\xd9','\xba','\x26','\x67','\x08','\x27','\x2f','\x9c','\xbc','\x54','\x11','\xf8','\xdb','\x9d','\x8b','\xd5','\xa9','\x44','\x9f','\xb6','\xeb','\x0c','\xde','\x7d','\x4d','\x03','\xe5','\xdf','\x01','\x9f','\x28','\x14','\xa9','\x0c','\xee','\xd3','\x77','\xc5','\x9d','\x7d','\x92','\x62','\x38','\x99','\xbc','\xb0','\x26','\x80','\x33','\x07','\x35','\x59','\xd4','\xd8','\xde','\x48','\x86','\x86','\xcb','\xe3','\xd6','\x77','\x96','\xe6','\xdf','\x6a','\xd4','\x27','\x6d','\x0b','\x52','\xcc','\x62','\xc4','\x9e','\xbb','\x58','\xd7','\xc9','\x52','\x87','\xaa','\x6c',};
	const char *digest109 = "7402f1a99b47e102b3b73140c6771b07ee6c33b3715e9c4027c441bee40511b735d95e508baea78da26fded9b7038e9a53defa58448aba40dc1e62d7ec592107";
	err |= test_sha512(vector109, len109, digest109);

	size_t len110 = 109;
	const char vector110[] = {'\xa7','\x66','\xb2','\xa7','\xef','\x91','\x67','\x21','\xf4','\x67','\x7b','\x67','\xdb','\xc6','\x5e','\xf9','\xb4','\xd1','\xbd','\xa1','\xad','\x4e','\x53','\xfc','\x85','\x4b','\x02','\x36','\x44','\x08','\x22','\x15','\x2a','\x11','\x19','\x39','\xe5','\xab','\x2b','\xa2','\x07','\x71','\x94','\x72','\xb6','\x3f','\xd4','\xf4','\xa5','\x4f','\x4b','\xde','\x44','\xa2','\x05','\xd3','\x34','\xa2','\xd7','\x2c','\xfe','\x05','\xab','\xf8','\x04','\xf4','\x18','\x41','\xb8','\x6d','\x36','\x92','\x0b','\xe6','\xb0','\xb5','\x29','\x33','\x1a','\xc1','\x63','\xa9','\x85','\x55','\x6c','\x84','\x51','\x1e','\xc9','\x86','\x43','\x9f','\x83','\xe1','\xd7','\x31','\x1f','\x57','\xd8','\x48','\xcf','\xa0','\x2d','\xf9','\xea','\x0c','\xf6','\xb9','\x9a',};
	const char *digest110 = "ddd60f93a3babc78299cf763e7919d45ac6f479700e1adb05ab137acdf89c1521ecb9dfeacd091e58ca57a1db964a9c3cd1fa39192cc1e9f734caa1c5fa62975";
	err |= test_sha512(vector110, len110, digest110);

	size_t len111 = 110;
	const char vector111[] = {'\x10','\xf2','\xbe','\x77','\xa4','\x05','\x57','\x71','\xa6','\x70','\x07','\xcd','\x86','\x30','\xe3','\x23','\x0e','\x38','\x28','\x84','\x99','\xcb','\x16','\x03','\x80','\x29','\x01','\x74','\xd6','\x6d','\xa5','\x74','\x55','\xb6','\xba','\xaa','\x97','\x85','\xc8','\x4c','\x8a','\x66','\x3d','\xe4','\x1e','\xd3','\xbd','\x54','\x40','\x55','\xb9','\x17','\x0c','\xec','\x43','\xcb','\x3e','\xb1','\x20','\xec','\xea','\xba','\x1f','\xe3','\x6e','\x3e','\xaa','\x3f','\xa4','\xf9','\x9b','\x42','\x5c','\xd2','\x51','\x9f','\x09','\xbc','\x02','\x82','\xba','\xda','\x52','\xd1','\x4c','\xe6','\x25','\xb1','\xde','\xd3','\xb2','\x4d','\x86','\xb1','\xda','\xd3','\x42','\xd2','\xb7','\xbe','\x32','\x2b','\x77','\x5b','\x04','\xfc','\x6b','\x86','\xaf','\xb4',};
	const char *digest111 = "a872fa33d463b3343cec57c20c66979c33e1ad067bfc703454696aab5dd0003bc194318f4a8ebbc74503feb7211a472dadee991efe3e38f21a1310f8a76eac80";
	err |= test_sha512(vector111, len111, digest111);

	size_t len112 = 111;
	const char vector112[] = {'\x32','\x45','\x33','\xe6','\x85','\xf1','\x85','\x2e','\x35','\x8e','\xea','\x8e','\xa8','\xb8','\x1c','\x28','\x8b','\x3f','\x3b','\xeb','\x1f','\x2b','\xc2','\xb8','\xd3','\xfd','\xba','\xc3','\x18','\x38','\x2e','\x3d','\x71','\x20','\xde','\x30','\xc9','\xc2','\x37','\xaa','\x0a','\x34','\x83','\x1d','\xeb','\x1e','\x5e','\x06','\x0a','\x79','\x69','\xcd','\x3a','\x97','\x42','\xec','\x1e','\x64','\xb3','\x54','\xf7','\xeb','\x29','\x0c','\xba','\x1c','\x68','\x1c','\x66','\xcc','\x7e','\xa9','\x94','\xfd','\xf5','\x61','\x4f','\x60','\x4d','\x1a','\x27','\x18','\xaa','\xb5','\x81','\xc1','\xc9','\x49','\x31','\xb1','\x38','\x7e','\x4b','\x7d','\xc7','\x36','\x35','\xbf','\x3a','\x73','\x01','\x17','\x40','\x75','\xfa','\x70','\xa9','\x22','\x7d','\x85','\xd3',};
	const char *digest112 = "3b26c5170729d0814153becb95f1b65cd42f9a6d0649d914e4f69d938b5e9dc041cd0f5c8da0b484d7c7bc7b1bdefb08fe8b1bfedc81109345bc9e9a399feedf";
	err |= test_sha512(vector112, len112, digest112);

	size_t len113 = 112;
	const char vector113[] = {'\x51','\x89','\x85','\x97','\x7e','\xe2','\x1d','\x2b','\xf6','\x22','\xa2','\x05','\x67','\x12','\x4f','\xcb','\xf1','\x1c','\x72','\xdf','\x80','\x53','\x65','\x83','\x5a','\xb3','\xc0','\x41','\xf4','\xa9','\xcd','\x8a','\x0a','\xd6','\x3c','\x9d','\xee','\x10','\x18','\xaa','\x21','\xa9','\xfa','\x37','\x20','\xf4','\x7d','\xc4','\x80','\x06','\xf1','\xaa','\x3d','\xba','\x54','\x49','\x50','\xf8','\x7e','\x62','\x7f','\x36','\x9b','\xc2','\x79','\x3e','\xde','\x21','\x22','\x32','\x74','\x49','\x2c','\xce','\xb7','\x7b','\xe7','\xee','\xa5','\x0e','\x5a','\x50','\x90','\x59','\x92','\x9a','\x16','\xd3','\x3a','\x9f','\x54','\x79','\x6c','\xde','\x57','\x70','\xc7','\x4b','\xd3','\xec','\xc2','\x53','\x18','\x50','\x3f','\x1a','\x41','\x97','\x64','\x07','\xaf','\xf2',};
	const char *digest113 = "c00926a374cde55b8fbd77f50da1363da19744d3f464e07ce31794c5a61b6f9c85689fa1cfe136553527fd876be91673c2cac2dd157b2defea360851b6d92cf4";
	err |= test_sha512(vector113, len113, digest113);

	size_t len114 = 113;
	const char vector114[] = {'\x91','\x59','\x76','\x72','\x75','\xba','\x6f','\x79','\xcb','\xb3','\xd5','\x8c','\x01','\x08','\x33','\x9d','\x8c','\x6a','\x41','\x13','\x89','\x91','\xab','\x7a','\xa5','\x8b','\x14','\x79','\x3b','\x54','\x5b','\x04','\xbd','\xa6','\x1d','\xd2','\x55','\x12','\x7b','\x12','\xcc','\x50','\x1d','\x5a','\xaa','\xd4','\x76','\xe0','\x9f','\xa1','\x4a','\xec','\x21','\x62','\x6e','\x8d','\x57','\xb7','\xd0','\x8c','\x36','\xcd','\xb7','\x9e','\xea','\x31','\x4b','\xdd','\x77','\xe6','\x57','\x79','\xa0','\xb5','\x4e','\xab','\x08','\xc4','\x8c','\xeb','\x97','\x6a','\xdf','\x63','\x1f','\x42','\x46','\xa3','\x3f','\x7e','\xf8','\x96','\x88','\x7e','\xa8','\xb5','\xdf','\xa2','\x08','\x7a','\x22','\x5c','\x8c','\x18','\x0f','\x89','\x70','\x69','\x61','\x01','\xfc','\x28','\x3b',};
	const char *digest114 = "3cd3380a90868de17dee4bd4d7f90d7512696f0a92b2d089240d61a9d20cd3af094c78bf466c2d404dd2f662ec5f4a299be2adeadf627b98e50e1c072b769d62";
	err |= test_sha512(vector114, len114, digest114);

	size_t len115 = 114;
	const char vector115[] = {'\xfe','\x2d','\x8a','\xe2','\x00','\xe6','\x65','\x7f','\xdc','\x74','\x94','\xaf','\x5a','\x12','\xb2','\xae','\x94','\x03','\x48','\xf1','\xf9','\x83','\xf0','\xba','\x98','\xfe','\xbb','\xe9','\x9c','\x80','\xd1','\x15','\x12','\x6d','\x57','\xdb','\xf3','\x72','\x96','\x76','\x5e','\xbb','\x59','\x90','\x25','\x66','\x96','\x58','\x8b','\x38','\x51','\xd5','\x4c','\x8f','\xbe','\x7a','\xde','\x98','\xa6','\xfa','\xf7','\xc2','\x0b','\x5e','\x4f','\x73','\x0f','\x54','\xa7','\xf9','\x12','\xca','\x0a','\xc3','\x1b','\xbb','\x53','\xd1','\x79','\x49','\xef','\x69','\xaa','\x0d','\xe4','\x0c','\x7b','\xab','\x12','\xa8','\x71','\xa9','\xb9','\x0f','\x68','\x81','\x3c','\xa8','\x7a','\xf4','\x25','\x64','\x22','\xa2','\x68','\xf4','\xa1','\xd8','\xec','\x3a','\xa1','\xa9','\x47','\xfd',};
	const char *digest115 = "8025a8608df0f6a01c34cdec012d4cb25852e1b100b68172fc4e86ac8b7126b64859cb9e767a7e59060989cedbd925afc475ca7369bd43f85ae590e224e036dd";
	err |= test_sha512(vector115, len115, digest115);

	size_t len116 = 115;
	const char vector116[] = {'\xdc','\x28','\x48','\x4e','\xbf','\xd2','\x93','\xd6','\x2a','\xc7','\x59','\xd5','\x75','\x4b','\xdf','\x50','\x24','\x23','\xe4','\xd4','\x19','\xfa','\x79','\x02','\x08','\x05','\x13','\x4b','\x2c','\xe3','\xdf','\xf7','\x38','\xc7','\x55','\x6c','\x91','\xd8','\x10','\xad','\xba','\xd8','\xdd','\x21','\x0f','\x04','\x12','\x96','\xb7','\x3c','\x21','\x85','\xd4','\x64','\x6c','\x97','\xfc','\x0a','\x5b','\x69','\xed','\x49','\xac','\x8c','\x7c','\xed','\x0b','\xd1','\xcf','\xd7','\xe3','\xc3','\xcc','\xa4','\x73','\x74','\xd1','\x89','\x24','\x7d','\xa6','\x81','\x1a','\x40','\xb0','\xab','\x09','\x70','\x67','\xed','\x4a','\xd4','\x0a','\xde','\x2e','\x47','\x91','\xe3','\x92','\x04','\xe3','\x98','\xb3','\x20','\x49','\x71','\x44','\x58','\x22','\xa1','\xbe','\x0d','\xd9','\x3a','\xf8',};
	const char *digest116 = "615115d2e8b62e345adaa4bdb95395a3b4fe27d71c4a111b86c1841463c5f03d6b20d164a39948ab08ae060720d05c10f6022e5c8caf2fa3bca2e04d9c539ded";
	err |= test_sha512(vector116, len116, digest116);

	size_t len117 = 116;
	const char vector117[] = {'\x5a','\xf8','\xc0','\xf2','\x6d','\xb4','\xe9','\x9b','\x47','\xec','\x2e','\x4a','\x01','\xa7','\x86','\xe7','\x78','\x99','\xe4','\x6d','\x46','\x4a','\xc3','\x37','\xf1','\x75','\x02','\x7b','\x61','\xae','\xf3','\x14','\x98','\x48','\xaf','\x84','\x9d','\x76','\xac','\x39','\xb9','\xb0','\x91','\x0f','\xe6','\x59','\x48','\x17','\x85','\x9e','\x55','\x97','\x4f','\xa1','\x67','\x51','\x8e','\xd7','\x2d','\x08','\x8d','\xae','\x6b','\x41','\x4d','\x74','\x4d','\x47','\x79','\x74','\xfb','\x71','\x9c','\x62','\x6d','\xa7','\x92','\xf9','\x81','\x23','\x3d','\xe2','\x4b','\x75','\x79','\xd8','\xac','\xca','\x51','\x0a','\x26','\x6d','\x73','\xc0','\xee','\x8e','\xe1','\x42','\x43','\x43','\xea','\xf6','\xff','\xcc','\x59','\xc8','\x6c','\x1b','\xec','\xce','\x58','\x94','\x07','\x2c','\x6c','\x11',};
	const char *digest117 = "09da284d5b6556508be54c8ab6c97bbd472995c6bbd585917ecdb54ea9167208daaa070a7b2b7d8e93ce1315f0d1ef8d69667429c44dc5ee1499de57b229a398";
	err |= test_sha512(vector117, len117, digest117);

	size_t len118 = 117;
	const char vector118[] = {'\x49','\xcd','\x0b','\xa0','\xdf','\x5b','\xb3','\xf4','\x3f','\x68','\x46','\x4e','\x3e','\x83','\xe9','\xcb','\xd5','\xd5','\xee','\x07','\x7f','\xfa','\x55','\x91','\xe3','\x0f','\x93','\x9c','\xb3','\x0c','\x93','\xf7','\xd4','\x54','\xfb','\x3f','\xbf','\x8b','\xb0','\x53','\x27','\xa8','\x9c','\x08','\xdc','\x4b','\xaf','\x1e','\xef','\x50','\x23','\x73','\x17','\xa4','\x05','\x77','\x53','\x57','\xf1','\xe0','\xd1','\xf3','\x1d','\x9f','\x0f','\x0d','\x98','\x12','\x40','\x19','\xd4','\x7b','\xf1','\x83','\x63','\xb1','\xec','\xfb','\xfe','\x15','\x5c','\x10','\xcb','\xc8','\x33','\x00','\xe0','\x1b','\xc9','\xce','\x03','\x47','\xc5','\x96','\xb3','\x5f','\x41','\x1e','\x6d','\x82','\x29','\xad','\x28','\x55','\xe4','\x20','\x22','\xb0','\x37','\x3a','\xde','\x98','\x66','\x3c','\x6d','\x6e','\x9c',};
	const char *digest118 = "30cbf0679a97c871574d2fc05d7aa760c6bc8a864b7d246c39b9e812f9b7ff7b4ef5197dd5b69493306688b8564de1ad47d75505c913ba6a78788f8caf5788bd";
	err |= test_sha512(vector118, len118, digest118);

	size_t len119 = 118;
	const char vector119[] = {'\xa8','\xa3','\x7d','\xfc','\x08','\x3a','\xd2','\xf4','\x7f','\xff','\x46','\x87','\x38','\xbf','\x8b','\x72','\x8e','\xb7','\xf1','\x90','\x7e','\x42','\x7f','\xa1','\x5c','\xb4','\x42','\x4b','\xc6','\x85','\xe5','\x5e','\xd7','\xb2','\x82','\x5c','\x9c','\x60','\xb8','\x39','\xcc','\xc2','\xfe','\x5f','\xb3','\x3e','\x36','\xf5','\x70','\xcb','\x86','\x61','\x60','\x9e','\x63','\x0b','\xda','\x05','\xee','\x64','\x1d','\x93','\x84','\x28','\x86','\x7d','\x90','\xe0','\x07','\x44','\xa4','\xaa','\xd4','\x94','\xc9','\x3c','\x5f','\x6d','\x13','\x27','\x87','\x80','\x78','\x59','\x0c','\xdc','\xe1','\xe6','\x47','\xc9','\x82','\x08','\x18','\xf4','\x67','\x64','\x1f','\xcd','\x50','\x8e','\x2f','\x2e','\xbf','\xd0','\xff','\x3d','\x4f','\x27','\x23','\x93','\x47','\x8f','\x3b','\x9e','\x6f','\x80','\x6b','\x43',};
	const char *digest119 = "8e1c91729be8eb40226f6c58a029380ef7edb9dc166a5c3cdbcefe90bd30d85cb7c4b248e66abf0a3a4c842281299bef6db88858d9e5ab5244f70b7969e1c072";
	err |= test_sha512(vector119, len119, digest119);

	size_t len120 = 119;
	const char vector120[] = {'\x36','\xaf','\x17','\x59','\x54','\x94','\xef','\x79','\x3c','\x42','\xf4','\x84','\x10','\x24','\x6d','\xf0','\x7d','\x05','\x93','\x6a','\x91','\x8a','\xfe','\x74','\xcd','\x00','\x5e','\x53','\x7c','\x58','\x6b','\x28','\x43','\x70','\x1f','\x5d','\xf8','\x95','\x22','\x42','\xb7','\x45','\x86','\xf8','\x33','\x39','\xb4','\x8f','\x4b','\xa3','\xa6','\x6b','\xde','\xb4','\x57','\xec','\xdf','\x61','\x78','\x4e','\xac','\x67','\x65','\xcd','\x9b','\x8c','\x57','\x0d','\xd6','\x28','\xdb','\xba','\x6a','\xe5','\x83','\x6b','\x9a','\xc3','\xdb','\xcd','\x79','\x5f','\x9e','\xfd','\xb8','\x74','\x2a','\x35','\xbc','\xa2','\x32','\xab','\xf3','\x6e','\xb3','\xb6','\x69','\x8b','\x29','\x33','\x96','\x58','\x02','\x27','\x7b','\xa9','\x53','\xa6','\xed','\xca','\xca','\xf3','\x30','\xc1','\xe4','\xe8','\xc7','\xd4','\x5f',};
	const char *digest120 = "158bfc348a30b4fabbe355a7d44bdc2122a4c850444c03f289003ce01bfc1ebf3ecc0febb6a8ff523d25db7681b05bdce048d11943ab476c1967cf6556c4a120";
	err |= test_sha512(vector120, len120, digest120);

	size_t len121 = 120;
	const char vector121[] = {'\x42','\xd6','\x6e','\xdc','\x5f','\x22','\xe0','\xc1','\x3c','\x25','\x50','\x4c','\x51','\x01','\xa5','\xd1','\x72','\xd2','\xdb','\x72','\x09','\xe4','\x61','\xef','\xa3','\x23','\xc0','\xbf','\xae','\xd2','\x7e','\x5f','\x80','\x80','\x42','\xea','\x9c','\x38','\x38','\xea','\x31','\xf9','\xb7','\x6d','\xe4','\x65','\x22','\x5c','\xcf','\xbd','\x0c','\x09','\xca','\x0d','\x9f','\x07','\xe9','\xa4','\x3e','\x3e','\x46','\xc7','\x69','\x3e','\x00','\xa7','\xe1','\xd4','\x83','\x90','\x0d','\xdb','\x0a','\x62','\x9d','\x55','\x63','\x45','\x6d','\xbb','\xf2','\x99','\xac','\x91','\xf9','\x2c','\x3d','\x3c','\x17','\xb0','\x5d','\x18','\x0e','\x6c','\x87','\xc6','\xc9','\x31','\x94','\xc3','\x9d','\x90','\x27','\x3f','\xcf','\x4a','\x48','\x2c','\x56','\x08','\x4f','\x95','\xe3','\x4c','\x04','\x31','\x1f','\xa8','\x04','\x38',};
	const char *digest121 = "061afb119a3c60876e04c10f12ad0f4b977593dc5a2d21096a57e7d3f7d4d44fdef934b2c17d7530674e4f4a1c176dbdcc54811a22e1b8712e4192fc2d4bf8e8";
	err |= test_sha512(vector121, len121, digest121);

	size_t len122 = 121;
	const char vector122[] = {'\xf9','\x1b','\xb2','\xe1','\xa9','\xc4','\xcd','\x96','\xbf','\x25','\x04','\x26','\xb3','\xa6','\xaf','\xd9','\xb8','\x7a','\xc5','\x1e','\x93','\x25','\x4d','\x2d','\xae','\x3b','\x16','\xec','\x68','\x6b','\xa8','\x0f','\xb0','\xbd','\x7a','\x84','\xd2','\x18','\x66','\x0e','\x90','\x07','\x59','\x30','\x75','\xbc','\x4f','\x4c','\x66','\x56','\x7f','\x0c','\x7a','\x5f','\xd2','\x01','\x0c','\x99','\x9a','\x8a','\x0e','\xfa','\x81','\xf8','\x9f','\xf5','\xbf','\xef','\xe0','\xfb','\x91','\x0f','\x04','\x42','\xe6','\xd4','\xa7','\xc5','\x5b','\xbb','\x61','\x8c','\x69','\xa7','\x9a','\x2d','\xdd','\x82','\xa0','\x93','\x89','\x27','\xf6','\xfe','\x3a','\x80','\xf0','\x4b','\xea','\xeb','\x7c','\x76','\x36','\xe3','\x43','\x5d','\x12','\xdc','\xf1','\xc6','\xbb','\x6e','\xd0','\xa4','\xed','\xb6','\x9c','\x96','\x57','\xfa','\x93',};
	const char *digest122 = "6e692c8c694ee0a3565f37a299e0006b85ab4a821b20e76798220229f656efc6a20211a4e7e4ed77facde0d70e4d5d95bc8ed1d7a56d8df1446d562f044b344c";
	err |= test_sha512(vector122, len122, digest122);

	size_t len123 = 122;
	const char vector123[] = {'\xd1','\xeb','\x96','\x1c','\xa6','\xa8','\xf6','\x7c','\x49','\xb6','\x1e','\x4d','\x3c','\xea','\xa2','\xa1','\xde','\x6f','\x0e','\xa9','\x27','\xb1','\x32','\xbf','\x98','\x7a','\xbd','\xaa','\x72','\x5b','\x0e','\x1e','\x27','\x4e','\x46','\x83','\x0e','\x99','\xa2','\xf7','\x5a','\xf6','\x08','\x96','\x4d','\xf0','\xdf','\xf9','\xa9','\x90','\x24','\xfc','\x68','\x39','\xba','\xc5','\xac','\xd1','\x02','\x02','\xf9','\x21','\xac','\x71','\xa2','\x7f','\xcd','\xa6','\x81','\xaa','\x31','\x09','\xeb','\xf5','\xf2','\x1e','\xe3','\xa8','\x49','\x09','\x8e','\xa3','\xa5','\x51','\xe8','\x44','\xfa','\xe4','\xb4','\x8b','\x5c','\x5b','\xb9','\x7c','\xcc','\x80','\x2b','\xc5','\x52','\x0d','\x68','\xa1','\x4c','\xb7','\xe5','\xfc','\x05','\x6b','\x67','\xd8','\x89','\xd8','\x76','\xef','\xb8','\x2d','\x0e','\x9a','\x9a','\x24','\x99','\xf1',};
	const char *digest123 = "39b2c76ec207120de4b320c7fe069e602c9c38f257596da7369395e87eb64b3acff988c1839ac269d5012c093f9edd4b7cabf13bdea7d42e969ab108269c6ab0";
	err |= test_sha512(vector123, len123, digest123);

	size_t len124 = 123;
	const char vector124[] = {'\xad','\xf2','\x26','\x32','\x00','\xf3','\x76','\x88','\x6b','\xa7','\xb6','\xf5','\xe4','\x41','\x1d','\x5f','\x07','\xf7','\xd9','\xd1','\x01','\x59','\x0c','\x73','\xac','\xe1','\x14','\xba','\xfb','\xcb','\x0f','\xdc','\x99','\x26','\x9e','\x87','\xcd','\x2c','\xea','\xd2','\xa1','\xcf','\xe5','\x74','\x43','\x94','\xd3','\x33','\xab','\xa4','\x08','\xa0','\x7e','\x21','\xf3','\x02','\x33','\xb6','\x5b','\x90','\x74','\x72','\xe9','\xe3','\xc7','\xd6','\xe7','\xaa','\x6d','\x2c','\x47','\xa0','\x8a','\x1b','\xe7','\xbb','\x87','\x79','\x13','\xa6','\xb5','\x60','\x4c','\x72','\x33','\x84','\x47','\x89','\x11','\xc3','\x39','\xe3','\xb5','\xfe','\x52','\x7c','\x7e','\x28','\x87','\x05','\xa8','\x9c','\x95','\xd9','\x70','\xb4','\x43','\x34','\x78','\x97','\xe7','\x9f','\x6c','\x52','\x2b','\xaf','\xe6','\x2b','\x11','\xef','\x8f','\x31','\x35',};
	const char *digest124 = "3c23d2d8cf4db6ac6a42e27208180f37668bef5ee0a3f879483c8e604e7f42583f202037b8d242c04a87345b8be6dc8b121d6484b9edad0d73c894c1288f5cae";
	err |= test_sha512(vector124, len124, digest124);

	size_t len125 = 124;
	const char vector125[] = {'\x18','\xe7','\x5b','\x47','\xd8','\x98','\xac','\x62','\x9c','\x48','\xe8','\x0d','\xbf','\xb7','\x5d','\xae','\x1e','\x17','\x00','\xb7','\x71','\x16','\x5e','\xcc','\xdb','\x18','\xd6','\x28','\xbf','\xc4','\x06','\x3d','\xd6','\xc3','\x83','\x9a','\x7e','\xc4','\xcd','\x12','\x55','\xc4','\x82','\x1b','\x07','\x8c','\xd1','\x74','\x64','\x7b','\x32','\x0b','\xb6','\x85','\x54','\x1d','\x51','\x7c','\x57','\x9f','\x6b','\x8e','\x3c','\xdd','\x2e','\x10','\x9a','\x61','\x0c','\x7a','\x92','\x16','\x53','\xb2','\x04','\xad','\x01','\x8d','\x03','\x40','\xd9','\x93','\x87','\x35','\xb6','\x02','\x62','\x66','\x20','\x16','\x76','\x7e','\x1d','\x88','\x24','\xa6','\x49','\x54','\x08','\x62','\x29','\xc0','\xe3','\xb5','\xbd','\x9a','\xd8','\x8c','\x54','\xc1','\xdc','\x5a','\xa4','\xe7','\x68','\xff','\x1a','\x94','\x70','\xee','\x6f','\x6e','\x99','\x8f',};
	const char *digest125 = "01c756b7c20b5f95fd2b079ab6a50f28b946fb16266b07c6060945dc4fe9e0d279c5b1505b9ec7d8f8f3c9ebf0c5ee9365aec08cf278d65b64daeccc19d3cbf4";
	err |= test_sha512(vector125, len125, digest125);

	size_t len126 = 125;
	const char vector126[] = {'\xc2','\x96','\x33','\x42','\xcf','\xaa','\x88','\xcc','\xd1','\x02','\xa2','\x58','\xe6','\xd6','\x29','\xf6','\xb0','\xd3','\x67','\xdd','\x55','\x11','\x65','\x02','\xca','\x44','\x51','\xea','\x52','\x36','\x23','\xbc','\x41','\x75','\x81','\x9a','\x06','\x48','\xdf','\x31','\x68','\xe8','\xea','\x8f','\x10','\xed','\x27','\x35','\x48','\x07','\xd7','\x6e','\x02','\xee','\x1f','\xdf','\x1c','\x9c','\x65','\x5e','\xe2','\xb9','\xfd','\x08','\xd5','\x57','\x05','\x8d','\xab','\xdf','\x8d','\xcf','\x96','\x4b','\xfc','\xac','\xc9','\x96','\xae','\x17','\x39','\x71','\xe2','\x6e','\xa0','\x38','\xd4','\x07','\xc8','\x24','\x26','\x0d','\x06','\xc2','\x84','\x8a','\x04','\xa4','\x88','\xc4','\xc4','\x56','\xdb','\xcd','\xe2','\x93','\x9e','\x56','\x1a','\xb9','\x08','\xc4','\x09','\x7b','\x50','\x86','\x38','\xd6','\xcd','\xa5','\x56','\x46','\x5c','\x9c','\xc5',};
	const char *digest126 = "a4d2f59393a5fea612c3c745f4bb9f41aaf3a3ce1679aa8afc1a62baa4ed452819418c8ae1a1e658757976692390fc43d4decf7d855cd8b498b6dc60cae05a90";
	err |= test_sha512(vector126, len126, digest126);

	size_t len127 = 126;
	const char vector127[] = {'\x85','\x36','\x0c','\x3d','\x42','\x57','\xd9','\x87','\x8e','\x2f','\x5c','\x16','\xd3','\xcd','\x7d','\x07','\x47','\xdf','\x3d','\x23','\x1e','\x1a','\x8f','\x63','\xfd','\xdc','\x69','\xb3','\xb1','\x10','\x1a','\xf7','\x21','\x53','\xde','\x4c','\x81','\x54','\xb0','\x90','\xc9','\x81','\x5f','\x24','\x66','\xe0','\xe4','\xf0','\x2f','\x3a','\xf3','\xa8','\x9a','\x7f','\xd0','\x4e','\x30','\x66','\x64','\xf9','\x3e','\x54','\x90','\xd4','\xce','\x7f','\xc1','\x69','\xd5','\x53','\xc5','\x20','\xae','\x15','\xdd','\x02','\xc7','\xc6','\x13','\xc3','\x9b','\x4a','\xcd','\x00','\xe0','\xc9','\xa3','\xc5','\x01','\x56','\x6e','\x52','\xce','\xce','\xa1','\x1f','\x73','\x03','\xdd','\x1d','\xa6','\x1a','\xbf','\x3f','\x25','\x32','\xfd','\x39','\x60','\x47','\xb1','\x88','\x72','\x55','\xf4','\xb2','\x56','\xc0','\xaf','\xcf','\x58','\xf3','\xae','\x48','\xc9','\x47',};
	const char *digest127 = "e8352ddcac59e377ea0f9c32bbb43dfd1b6c829fad1954240c41b7c45b0b09db11064b64e2442a96f6530aac2c4abf3beb1eae77f2bce4efe88fee1a70cf5423";
	err |= test_sha512(vector127, len127, digest127);

	size_t len128 = 127;
	const char vector128[] = {'\xc1','\x3e','\x6c','\xa3','\xab','\xb8','\x93','\xaa','\x5f','\x82','\xc4','\xa8','\xef','\x75','\x44','\x60','\x62','\x8a','\xf6','\xb7','\x5a','\xf0','\x21','\x68','\xf4','\x5b','\x72','\xf8','\xf0','\x9e','\x45','\xed','\x12','\x7c','\x20','\x3b','\xc7','\xbb','\x80','\xff','\x0c','\x7b','\xd9','\x6f','\x8c','\xc6','\xd8','\x11','\x08','\x68','\xeb','\x2c','\xfc','\x01','\x03','\x7d','\x80','\x58','\x99','\x2a','\x6c','\xf2','\xef','\xfc','\xbf','\xe4','\x98','\xc8','\x42','\xe5','\x3a','\x2e','\x68','\xa7','\x93','\x86','\x79','\x68','\xba','\x18','\xef','\xc4','\xa7','\x8b','\x21','\xcd','\xf6','\xa1','\x1e','\x5d','\xe8','\x21','\xdc','\xab','\xab','\x14','\x92','\x1d','\xdb','\x33','\x62','\x5d','\x48','\xa1','\x3b','\xaf','\xfa','\xd6','\xfe','\x82','\x72','\xdb','\xdf','\x44','\x33','\xbd','\x0f','\x7b','\x81','\x3c','\x98','\x12','\x69','\xc3','\x88','\xf0','\x01',};
	const char *digest128 = "6e56f77f6883d0bd4face8b8d557f144661989f66d51b1fe4b8fc7124d66d9d20218616fea1bcf86c08d63bf8f2f21845a3e519083b937e70aa7c358310b5a7c";
	err |= test_sha512(vector128, len128, digest128);

	size_t len129 = 128;
	const char vector129[] = {'\xfd','\x22','\x03','\xe4','\x67','\x57','\x4e','\x83','\x4a','\xb0','\x7c','\x90','\x97','\xae','\x16','\x45','\x32','\xf2','\x4b','\xe1','\xeb','\x5d','\x88','\xf1','\xaf','\x77','\x48','\xce','\xff','\x0d','\x2c','\x67','\xa2','\x1f','\x4e','\x40','\x97','\xf9','\xd3','\xbb','\x4e','\x9f','\xbf','\x97','\x18','\x6e','\x0d','\xb6','\xdb','\x01','\x00','\x23','\x0a','\x52','\xb4','\x53','\xd4','\x21','\xf8','\xab','\x9c','\x9a','\x60','\x43','\xaa','\x32','\x95','\xea','\x20','\xd2','\xf0','\x6a','\x2f','\x37','\x47','\x0d','\x8a','\x99','\x07','\x5f','\x1b','\x8a','\x83','\x36','\xf6','\x22','\x8c','\xf0','\x8b','\x59','\x42','\xfc','\x1f','\xb4','\x29','\x9c','\x7d','\x24','\x80','\xe8','\xe8','\x2b','\xce','\x17','\x55','\x40','\xbd','\xfa','\xd7','\x75','\x2b','\xc9','\x5b','\x57','\x7f','\x22','\x95','\x15','\x39','\x4f','\x3a','\xe5','\xce','\xc8','\x70','\xa4','\xb2','\xf8',};
	const char *digest129 = "a21b1077d52b27ac545af63b32746c6e3c51cb0cb9f281eb9f3580a6d4996d5c9917d2a6e484627a9d5a06fa1b25327a9d710e027387fc3e07d7c4d14c6086cc";
	err |= test_sha512(vector129, len129, digest129);

	return err;
}

int main(void)
{
	int err = 0;

	err |= sha256();
	err |= sha384();
	err |= sha512();

	return err;
}
