/* ====================================================================
 * Copyright (c) 2003-2007 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@openssl.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <string.h>
#include <openssl/err.h>
#include <openssl/fips.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/opensslconf.h>

#ifdef OPENSSL_FIPS

static unsigned char n[] =
"\x00\xBB\xF8\x2F\x09\x06\x82\xCE\x9C\x23\x38\xAC\x2B\x9D\xA8\x71"
"\xF7\x36\x8D\x07\xEE\xD4\x10\x43\xA4\x40\xD6\xB6\xF0\x74\x54\xF5"
"\x1F\xB8\xDF\xBA\xAF\x03\x5C\x02\xAB\x61\xEA\x48\xCE\xEB\x6F\xCD"
"\x48\x76\xED\x52\x0D\x60\xE1\xEC\x46\x19\x71\x9D\x8A\x5B\x8B\x80"
"\x7F\xAF\xB8\xE0\xA3\xDF\xC7\x37\x72\x3E\xE6\xB4\xB7\xD9\x3A\x25"
"\x84\xEE\x6A\x64\x9D\x06\x09\x53\x74\x88\x34\xB2\x45\x45\x98\x39"
"\x4E\xE0\xAA\xB1\x2D\x7B\x61\xA5\x1F\x52\x7A\x9A\x41\xF6\xC1\x68"
"\x7F\xE2\x53\x72\x98\xCA\x2A\x8F\x59\x46\xF8\xE5\xFD\x09\x1D\xBD"
"\xCB";


static int setrsakey(RSA *key)
    {
    static const unsigned char e[] = "\x11";

    static const unsigned char d[] =
"\x00\xA5\xDA\xFC\x53\x41\xFA\xF2\x89\xC4\xB9\x88\xDB\x30\xC1\xCD"
"\xF8\x3F\x31\x25\x1E\x06\x68\xB4\x27\x84\x81\x38\x01\x57\x96\x41"
"\xB2\x94\x10\xB3\xC7\x99\x8D\x6B\xC4\x65\x74\x5E\x5C\x39\x26\x69"
"\xD6\x87\x0D\xA2\xC0\x82\xA9\x39\xE3\x7F\xDC\xB8\x2E\xC9\x3E\xDA"
"\xC9\x7F\xF3\xAD\x59\x50\xAC\xCF\xBC\x11\x1C\x76\xF1\xA9\x52\x94"
"\x44\xE5\x6A\xAF\x68\xC5\x6C\x09\x2C\xD3\x8D\xC3\xBE\xF5\xD2\x0A"
"\x93\x99\x26\xED\x4F\x74\xA1\x3E\xDD\xFB\xE1\xA1\xCE\xCC\x48\x94"
"\xAF\x94\x28\xC2\xB7\xB8\x88\x3F\xE4\x46\x3A\x4B\xC8\x5B\x1C\xB3"
"\xC1";

    static const unsigned char p[] =
"\x00\xEE\xCF\xAE\x81\xB1\xB9\xB3\xC9\x08\x81\x0B\x10\xA1\xB5\x60"
"\x01\x99\xEB\x9F\x44\xAE\xF4\xFD\xA4\x93\xB8\x1A\x9E\x3D\x84\xF6"
"\x32\x12\x4E\xF0\x23\x6E\x5D\x1E\x3B\x7E\x28\xFA\xE7\xAA\x04\x0A"
"\x2D\x5B\x25\x21\x76\x45\x9D\x1F\x39\x75\x41\xBA\x2A\x58\xFB\x65"
"\x99";

    static const unsigned char q[] =
"\x00\xC9\x7F\xB1\xF0\x27\xF4\x53\xF6\x34\x12\x33\xEA\xAA\xD1\xD9"
"\x35\x3F\x6C\x42\xD0\x88\x66\xB1\xD0\x5A\x0F\x20\x35\x02\x8B\x9D"
"\x86\x98\x40\xB4\x16\x66\xB4\x2E\x92\xEA\x0D\xA3\xB4\x32\x04\xB5"
"\xCF\xCE\x33\x52\x52\x4D\x04\x16\xA5\xA4\x41\xE7\x00\xAF\x46\x15"
"\x03";

    static const unsigned char dmp1[] =
"\x54\x49\x4C\xA6\x3E\xBA\x03\x37\xE4\xE2\x40\x23\xFC\xD6\x9A\x5A"
"\xEB\x07\xDD\xDC\x01\x83\xA4\xD0\xAC\x9B\x54\xB0\x51\xF2\xB1\x3E"
"\xD9\x49\x09\x75\xEA\xB7\x74\x14\xFF\x59\xC1\xF7\x69\x2E\x9A\x2E"
"\x20\x2B\x38\xFC\x91\x0A\x47\x41\x74\xAD\xC9\x3C\x1F\x67\xC9\x81";

    static const unsigned char dmq1[] =
"\x47\x1E\x02\x90\xFF\x0A\xF0\x75\x03\x51\xB7\xF8\x78\x86\x4C\xA9"
"\x61\xAD\xBD\x3A\x8A\x7E\x99\x1C\x5C\x05\x56\xA9\x4C\x31\x46\xA7"
"\xF9\x80\x3F\x8F\x6F\x8A\xE3\x42\xE9\x31\xFD\x8A\xE4\x7A\x22\x0D"
"\x1B\x99\xA4\x95\x84\x98\x07\xFE\x39\xF9\x24\x5A\x98\x36\xDA\x3D";
    
    static const unsigned char iqmp[] =
"\x00\xB0\x6C\x4F\xDA\xBB\x63\x01\x19\x8D\x26\x5B\xDB\xAE\x94\x23"
"\xB3\x80\xF2\x71\xF7\x34\x53\x88\x50\x93\x07\x7F\xCD\x39\xE2\x11"
"\x9F\xC9\x86\x32\x15\x4F\x58\x83\xB1\x67\xA9\x67\xBF\x40\x2B\x4E"
"\x9E\x2E\x0F\x96\x56\xE6\x98\xEA\x36\x66\xED\xFB\x25\x79\x80\x39"
"\xF7";

    key->n = BN_bin2bn(n, sizeof(n)-1, key->n);
    key->e = BN_bin2bn(e, sizeof(e)-1, key->e);
    key->d = BN_bin2bn(d, sizeof(d)-1, key->d);
    key->p = BN_bin2bn(p, sizeof(p)-1, key->p);
    key->q = BN_bin2bn(q, sizeof(q)-1, key->q);
    key->dmp1 = BN_bin2bn(dmp1, sizeof(dmp1)-1, key->dmp1);
    key->dmq1 = BN_bin2bn(dmq1, sizeof(dmq1)-1, key->dmq1);
    key->iqmp = BN_bin2bn(iqmp, sizeof(iqmp)-1, key->iqmp);
    return 1;
    }

void FIPS_corrupt_rsa()
    {
    n[0]++;
    }

/* Known Answer Test (KAT) data for the above RSA private key signing
 * kat_tbs.
 */

static const unsigned char kat_tbs[] = "OpenSSL FIPS 140-2 Public Key RSA KAT";

static const unsigned char kat_RSA_PSS_SHA1[] = {
  0x2D, 0xAF, 0x6E, 0xC2, 0x98, 0xFB, 0x8A, 0xA1, 0xB9, 0x46, 0xDA, 0x0F,
  0x01, 0x1E, 0x37, 0x93, 0xC2, 0x55, 0x27, 0xE4, 0x1D, 0xD2, 0x90, 0xBB,
  0xF4, 0xBF, 0x4A, 0x74, 0x39, 0x51, 0xBB, 0xE8, 0x0C, 0xB7, 0xF8, 0xD3,
  0xD1, 0xDF, 0xE7, 0xBE, 0x80, 0x05, 0xC3, 0xB5, 0xC7, 0x83, 0xD5, 0x4C,
  0x7F, 0x49, 0xFB, 0x3F, 0x29, 0x9B, 0xE1, 0x12, 0x51, 0x60, 0xD0, 0xA7,
  0x0D, 0xA9, 0x28, 0x56, 0x73, 0xD9, 0x07, 0xE3, 0x5E, 0x3F, 0x9B, 0xF5,
  0xB6, 0xF3, 0xF2, 0x5E, 0x74, 0xC9, 0x83, 0x81, 0x47, 0xF0, 0xC5, 0x45,
  0x0A, 0xE9, 0x8E, 0x38, 0xD7, 0x18, 0xC6, 0x2A, 0x0F, 0xF8, 0xB7, 0x31,
  0xD6, 0x55, 0xE4, 0x66, 0x78, 0x81, 0xD4, 0xE6, 0xDB, 0x9F, 0xBA, 0xE8,
  0x23, 0xB5, 0x7F, 0xDC, 0x08, 0xEA, 0xD5, 0x26, 0x1E, 0x20, 0x25, 0x84,
  0x26, 0xC6, 0x79, 0xC9, 0x9B, 0x3D, 0x7E, 0xA9
};

static const unsigned char kat_RSA_PSS_SHA224[] = {
  0x39, 0x4A, 0x6A, 0x20, 0xBC, 0xE9, 0x33, 0xED, 0xEF, 0xC5, 0x58, 0xA7,
  0xFE, 0x81, 0xC4, 0x36, 0x50, 0x9A, 0x2C, 0x82, 0x98, 0x08, 0x95, 0xFA,
  0xB1, 0x9E, 0xD2, 0x55, 0x61, 0x87, 0x21, 0x59, 0x87, 0x7B, 0x1F, 0x57,
  0x30, 0x9D, 0x0D, 0x4A, 0x06, 0xEB, 0x52, 0x37, 0x55, 0x54, 0x1C, 0x89,
  0x83, 0x75, 0x59, 0x65, 0x64, 0x90, 0x2E, 0x16, 0xCC, 0x86, 0x05, 0xEE,
  0xB1, 0xE6, 0x7B, 0xBA, 0x16, 0x75, 0x0D, 0x0C, 0x64, 0x0B, 0xAB, 0x22,
  0x15, 0x78, 0x6B, 0x6F, 0xA4, 0xFB, 0x77, 0x40, 0x64, 0x62, 0xD1, 0xB5,
  0x37, 0x1E, 0xE0, 0x3D, 0xA8, 0xF9, 0xD2, 0xBD, 0xAA, 0x38, 0x24, 0x49,
  0x58, 0xD2, 0x74, 0x85, 0xF4, 0xB5, 0x93, 0x8E, 0xF5, 0x03, 0xEA, 0x2D,
  0xC8, 0x52, 0xFA, 0xCF, 0x7E, 0x35, 0xB0, 0x6A, 0xAF, 0x95, 0xC0, 0x00,
  0x54, 0x76, 0x3D, 0x0C, 0x9C, 0xB2, 0xEE, 0xC0
};

static const unsigned char kat_RSA_PSS_SHA256[] = {
  0x6D, 0x3D, 0xBE, 0x8F, 0x60, 0x6D, 0x25, 0x14, 0xF0, 0x31, 0xE3, 0x89,
  0x00, 0x97, 0xFA, 0x99, 0x71, 0x28, 0xE5, 0x10, 0x25, 0x9A, 0xF3, 0x8F,
  0x7B, 0xC5, 0xA8, 0x4A, 0x74, 0x51, 0x36, 0xE2, 0x8D, 0x7D, 0x73, 0x28,
  0xC1, 0x77, 0xC6, 0x27, 0x97, 0x00, 0x8B, 0x00, 0xA3, 0x96, 0x73, 0x4E,
  0x7D, 0x2E, 0x2C, 0x34, 0x68, 0x8C, 0x8E, 0xDF, 0x9D, 0x49, 0x47, 0x05,
  0xAB, 0xF5, 0x01, 0xD6, 0x81, 0x47, 0x70, 0xF5, 0x1D, 0x6D, 0x26, 0xBA,
  0x2F, 0x7A, 0x54, 0x53, 0x4E, 0xED, 0x71, 0xD9, 0x5A, 0xF3, 0xDA, 0xB6,
  0x0B, 0x47, 0x34, 0xAF, 0x90, 0xDC, 0xC8, 0xD9, 0x6F, 0x56, 0xCD, 0x9F,
  0x21, 0xB7, 0x7E, 0xAD, 0x7C, 0x2F, 0x75, 0x50, 0x47, 0x12, 0xE4, 0x6D,
  0x5F, 0xB7, 0x01, 0xDF, 0xC3, 0x11, 0x6C, 0xA9, 0x9E, 0x49, 0xB9, 0xF6,
  0x72, 0xF4, 0xF6, 0xEF, 0x88, 0x1E, 0x2D, 0x1C
};

static const unsigned char kat_RSA_PSS_SHA384[] = {
  0x40, 0xFB, 0xA1, 0x21, 0xF4, 0xB2, 0x40, 0x9A, 0xB4, 0x31, 0xA8, 0xF2,
  0xEC, 0x1C, 0xC4, 0xC8, 0x7C, 0x22, 0x65, 0x9C, 0x57, 0x45, 0xCD, 0x5E,
  0x86, 0x00, 0xF7, 0x25, 0x78, 0xDE, 0xDC, 0x7A, 0x71, 0x44, 0x9A, 0xCD,
  0xAA, 0x25, 0xF4, 0xB2, 0xFC, 0xF0, 0x75, 0xD9, 0x2F, 0x78, 0x23, 0x7F,
  0x6F, 0x02, 0xEF, 0xC1, 0xAF, 0xA6, 0x28, 0x16, 0x31, 0xDC, 0x42, 0x6C,
  0xB2, 0x44, 0xE5, 0x4D, 0x66, 0xA2, 0xE6, 0x71, 0xF3, 0xAC, 0x4F, 0xFB,
  0x91, 0xCA, 0xF5, 0x70, 0xEF, 0x6B, 0x9D, 0xA4, 0xEF, 0xD9, 0x3D, 0x2F,
  0x3A, 0xBE, 0x89, 0x38, 0x59, 0x01, 0xBA, 0xDA, 0x32, 0xAD, 0x42, 0x89,
  0x98, 0x8B, 0x39, 0x44, 0xF0, 0xFC, 0x38, 0xAC, 0x87, 0x1F, 0xCA, 0x6F,
  0x48, 0xF6, 0xAE, 0xD7, 0x45, 0xEE, 0xAE, 0x88, 0x0E, 0x60, 0xF4, 0x55,
  0x48, 0x44, 0xEE, 0x1F, 0x90, 0x18, 0x4B, 0xF1
};

static const unsigned char kat_RSA_PSS_SHA512[] = {
  0x07, 0x1E, 0xD8, 0xD5, 0x05, 0xE8, 0xE6, 0xE6, 0x57, 0xAE, 0x63, 0x8C,
  0xC6, 0x83, 0xB7, 0xA0, 0x59, 0xBB, 0xF2, 0xC6, 0x8F, 0x12, 0x53, 0x9A,
  0x9B, 0x54, 0x9E, 0xB3, 0xC1, 0x1D, 0x23, 0x4D, 0x51, 0xED, 0x9E, 0xDD,
  0x4B, 0xF3, 0x46, 0x9B, 0x6B, 0xF6, 0x7C, 0x24, 0x60, 0x79, 0x23, 0x39,
  0x01, 0x1C, 0x51, 0xCB, 0xD8, 0xE9, 0x9A, 0x01, 0x67, 0x5F, 0xFE, 0xD7,
  0x7C, 0xE3, 0x7F, 0xED, 0xDB, 0x87, 0xBB, 0xF0, 0x3D, 0x78, 0x55, 0x61,
  0x57, 0xE3, 0x0F, 0xE3, 0xD2, 0x9D, 0x0C, 0x2A, 0x20, 0xB0, 0x85, 0x13,
  0xC5, 0x47, 0x34, 0x0D, 0x32, 0x15, 0xC8, 0xAE, 0x9A, 0x6A, 0x39, 0x63,
  0x2D, 0x60, 0xF5, 0x4C, 0xDF, 0x8A, 0x48, 0x4B, 0xBF, 0xF4, 0xA8, 0xFE,
  0x76, 0xF2, 0x32, 0x1B, 0x9C, 0x7C, 0xCA, 0xFE, 0x7F, 0x80, 0xC2, 0x88,
  0x5C, 0x97, 0x70, 0xB4, 0x26, 0xC9, 0x14, 0x8B
};

static const unsigned char kat_RSA_SHA1[] = {
  0x71, 0xEE, 0x1A, 0xC0, 0xFE, 0x01, 0x93, 0x54, 0x79, 0x5C, 0xF2, 0x4C,
  0x4A, 0xFD, 0x1A, 0x05, 0x8F, 0x64, 0xB1, 0x6D, 0x61, 0x33, 0x8D, 0x9B,
  0xE7, 0xFD, 0x60, 0xA3, 0x83, 0xB5, 0xA3, 0x51, 0x55, 0x77, 0x90, 0xCF,
  0xDC, 0x22, 0x37, 0x8E, 0xD0, 0xE1, 0xAE, 0x09, 0xE3, 0x3D, 0x1E, 0xF8,
  0x80, 0xD1, 0x8B, 0xC2, 0xEC, 0x0A, 0xD7, 0x6B, 0x88, 0x8B, 0x8B, 0xA1,
  0x20, 0x22, 0xBE, 0x59, 0x5B, 0xE0, 0x23, 0x24, 0xA1, 0x49, 0x30, 0xBA,
  0xA9, 0x9E, 0xE8, 0xB1, 0x8A, 0x62, 0x16, 0xBF, 0x4E, 0xCA, 0x2E, 0x4E,
  0xBC, 0x29, 0xA8, 0x67, 0x13, 0xB7, 0x9F, 0x1D, 0x04, 0x44, 0xE5, 0x5F,
  0x35, 0x07, 0x11, 0xBC, 0xED, 0x19, 0x37, 0x21, 0xCF, 0x23, 0x48, 0x1F,
  0x72, 0x05, 0xDE, 0xE6, 0xE8, 0x7F, 0x33, 0x8A, 0x76, 0x4B, 0x2F, 0x95,
  0xDF, 0xF1, 0x5F, 0x84, 0x80, 0xD9, 0x46, 0xB4
};

static const unsigned char kat_RSA_SHA224[] = {
  0x62, 0xAA, 0x79, 0xA9, 0x18, 0x0E, 0x5F, 0x8C, 0xBB, 0xB7, 0x15, 0xF9,
  0x25, 0xBB, 0xFA, 0xD4, 0x3A, 0x34, 0xED, 0x9E, 0xA0, 0xA9, 0x18, 0x8D,
  0x5B, 0x55, 0x9A, 0x7E, 0x1E, 0x08, 0x08, 0x60, 0xC5, 0x1A, 0xC5, 0x89,
  0x08, 0xE2, 0x1B, 0xBD, 0x62, 0x50, 0x17, 0x76, 0x30, 0x2C, 0x9E, 0xCD,
  0xA4, 0x02, 0xAD, 0xB1, 0x6D, 0x44, 0x6D, 0xD5, 0xC6, 0x45, 0x41, 0xE5,
  0xEE, 0x1F, 0x8D, 0x7E, 0x08, 0x16, 0xA6, 0xE1, 0x5E, 0x0B, 0xA9, 0xCC,
  0xDB, 0x59, 0x55, 0x87, 0x09, 0x25, 0x70, 0x86, 0x84, 0x02, 0xC6, 0x3B,
  0x0B, 0x44, 0x4C, 0x46, 0x95, 0xF4, 0xF8, 0x5A, 0x91, 0x28, 0x3E, 0xB2,
  0x58, 0x2E, 0x06, 0x45, 0x49, 0xE0, 0x92, 0xE2, 0xC0, 0x66, 0xE6, 0x35,
  0xD9, 0x79, 0x7F, 0x17, 0x5E, 0x02, 0x73, 0x04, 0x77, 0x82, 0xE6, 0xDC,
  0x40, 0x21, 0x89, 0x8B, 0x37, 0x3E, 0x1E, 0x8D
};

static const unsigned char kat_RSA_SHA256[] = {
  0x0D, 0x55, 0xE2, 0xAA, 0x81, 0xDB, 0x8E, 0x82, 0x05, 0x17, 0xA5, 0x23,
  0xE7, 0x3B, 0x1D, 0xAF, 0xFB, 0x8C, 0xD0, 0x81, 0x20, 0x7B, 0xAA, 0x23,
  0x92, 0x87, 0x8C, 0xD1, 0x53, 0x85, 0x16, 0xDC, 0xBE, 0xAD, 0x6F, 0x35,
  0x98, 0x2D, 0x69, 0x84, 0xBF, 0xD9, 0x8A, 0x01, 0x17, 0x58, 0xB2, 0x6E,
  0x2C, 0x44, 0x9B, 0x90, 0xF1, 0xFB, 0x51, 0xE8, 0x6A, 0x90, 0x2D, 0x18,
  0x0E, 0xC0, 0x90, 0x10, 0x24, 0xA9, 0x1D, 0xB3, 0x58, 0x7A, 0x91, 0x30,
  0xBE, 0x22, 0xC7, 0xD3, 0xEC, 0xC3, 0x09, 0x5D, 0xBF, 0xE2, 0x80, 0x3A,
  0x7C, 0x85, 0xB4, 0xBC, 0xD1, 0xE9, 0xF0, 0x5C, 0xDE, 0x81, 0xA6, 0x38,
  0xB8, 0x42, 0xBB, 0x86, 0xC5, 0x9D, 0xCE, 0x7C, 0x2C, 0xEE, 0xD1, 0xDA,
  0x27, 0x48, 0x2B, 0xF5, 0xAB, 0xB9, 0xF7, 0x80, 0xD1, 0x90, 0x27, 0x90,
  0xBD, 0x44, 0x97, 0x60, 0xCD, 0x57, 0xC0, 0x7A
};

static const unsigned char kat_RSA_SHA384[] = {
  0x1D, 0xE3, 0x6A, 0xDD, 0x27, 0x4C, 0xC0, 0xA5, 0x27, 0xEF, 0xE6, 0x1F,
  0xD2, 0x91, 0x68, 0x59, 0x04, 0xAE, 0xBD, 0x99, 0x63, 0x56, 0x47, 0xC7,
  0x6F, 0x22, 0x16, 0x48, 0xD0, 0xF9, 0x18, 0xA9, 0xCA, 0xFA, 0x5D, 0x5C,
  0xA7, 0x65, 0x52, 0x8A, 0xC8, 0x44, 0x7E, 0x86, 0x5D, 0xA9, 0xA6, 0x55,
  0x65, 0x3E, 0xD9, 0x2D, 0x02, 0x38, 0xA8, 0x79, 0x28, 0x7F, 0xB6, 0xCF,
  0x82, 0xDD, 0x7E, 0x55, 0xE1, 0xB1, 0xBC, 0xE2, 0x19, 0x2B, 0x30, 0xC2,
  0x1B, 0x2B, 0xB0, 0x82, 0x46, 0xAC, 0x4B, 0xD1, 0xE2, 0x7D, 0xEB, 0x8C,
  0xFF, 0x95, 0xE9, 0x6A, 0x1C, 0x3D, 0x4D, 0xBF, 0x8F, 0x8B, 0x9C, 0xCD,
  0xEA, 0x85, 0xEE, 0x00, 0xDC, 0x1C, 0xA7, 0xEB, 0xD0, 0x8F, 0x99, 0xF1,
  0x16, 0x28, 0x24, 0x64, 0x04, 0x39, 0x2D, 0x58, 0x1E, 0x37, 0xDC, 0x04,
  0xBD, 0x31, 0xA2, 0x2F, 0xB3, 0x35, 0x56, 0xBF
};

static const unsigned char kat_RSA_SHA512[] = {
  0x69, 0x52, 0x1B, 0x51, 0x5E, 0x06, 0xCA, 0x9B, 0x16, 0x51, 0x5D, 0xCF,
  0x49, 0x25, 0x4A, 0xA1, 0x6A, 0x77, 0x4C, 0x36, 0x40, 0xF8, 0xB2, 0x9A,
  0x15, 0xEA, 0x5C, 0xE5, 0xE6, 0x82, 0xE0, 0x86, 0x82, 0x6B, 0x32, 0xF1,
  0x04, 0xC1, 0x5A, 0x1A, 0xED, 0x1E, 0x9A, 0xB6, 0x4C, 0x54, 0x9F, 0xD8,
  0x8D, 0xCC, 0xAC, 0x8A, 0xBB, 0x9C, 0x82, 0x3F, 0xA6, 0x53, 0x62, 0xB5,
  0x80, 0xE2, 0xBC, 0xDD, 0x67, 0x2B, 0xD9, 0x3F, 0xE4, 0x75, 0x92, 0x6B,
  0xAF, 0x62, 0x7C, 0x52, 0xF0, 0xEE, 0x33, 0xDF, 0x1B, 0x1D, 0x47, 0xE6,
  0x59, 0x56, 0xA5, 0xB9, 0x5C, 0xE6, 0x77, 0x78, 0x16, 0x63, 0x84, 0x05,
  0x6F, 0x0E, 0x2B, 0x31, 0x9D, 0xF7, 0x7F, 0xB2, 0x64, 0x71, 0xE0, 0x2D,
  0x3E, 0x62, 0xCE, 0xB5, 0x3F, 0x88, 0xDF, 0x2D, 0xAB, 0x98, 0x65, 0x91,
  0xDF, 0x70, 0x14, 0xA5, 0x3F, 0x36, 0xAB, 0x84
};

static const unsigned char kat_RSA_X931_SHA1[] = {
  0x86, 0xB4, 0x18, 0xBA, 0xD1, 0x80, 0xB6, 0x7C, 0x42, 0x45, 0x4D, 0xDF,
  0xE9, 0x2D, 0xE1, 0x83, 0x5F, 0xB5, 0x2F, 0xC9, 0xCD, 0xC4, 0xB2, 0x75,
  0x80, 0xA4, 0xF1, 0x4A, 0xE7, 0x83, 0x12, 0x1E, 0x1E, 0x14, 0xB8, 0xAC,
  0x35, 0xE2, 0xAA, 0x0B, 0x5C, 0xF8, 0x38, 0x4D, 0x04, 0xEE, 0xA9, 0x97,
  0x70, 0xFB, 0x5E, 0xE7, 0xB7, 0xE3, 0x62, 0x23, 0x4B, 0x38, 0xBE, 0xD6,
  0x53, 0x15, 0xF7, 0xDF, 0x87, 0xB4, 0x0E, 0xCC, 0xB1, 0x1A, 0x11, 0x19,
  0xEE, 0x51, 0xCC, 0x92, 0xDD, 0xBC, 0x63, 0x29, 0x63, 0x0C, 0x59, 0xD7,
  0x6F, 0x4C, 0x3C, 0x37, 0x5B, 0x37, 0x03, 0x61, 0x7D, 0x24, 0x1C, 0x99,
  0x48, 0xAF, 0x82, 0xFE, 0x32, 0x41, 0x9B, 0xB2, 0xDB, 0xEA, 0xED, 0x76,
  0x8E, 0x6E, 0xCA, 0x7E, 0x4E, 0x14, 0xBA, 0x30, 0x84, 0x1C, 0xB3, 0x67,
  0xA3, 0x29, 0x80, 0x70, 0x54, 0x68, 0x7D, 0x49
};

static const unsigned char kat_RSA_X931_SHA256[] = {
  0x7E, 0xA2, 0x77, 0xFE, 0xB8, 0x54, 0x8A, 0xC7, 0x7F, 0x64, 0x54, 0x89,
  0xE5, 0x52, 0x15, 0x8E, 0x52, 0x96, 0x4E, 0xA6, 0x58, 0x92, 0x1C, 0xDD,
  0xEA, 0xA2, 0x2D, 0x5C, 0xD1, 0x62, 0x00, 0x49, 0x05, 0x95, 0x73, 0xCF,
  0x16, 0x76, 0x68, 0xF6, 0xC6, 0x5E, 0x80, 0xB8, 0xB8, 0x7B, 0xC8, 0x9B,
  0xC6, 0x53, 0x88, 0x26, 0x20, 0x88, 0x73, 0xB6, 0x13, 0xB8, 0xF0, 0x4B,
  0x00, 0x85, 0xF3, 0xDD, 0x07, 0x50, 0xEB, 0x20, 0xC4, 0x38, 0x0E, 0x98,
  0xAD, 0x4E, 0x49, 0x2C, 0xD7, 0x65, 0xA5, 0x19, 0x0E, 0x59, 0x01, 0xEC,
  0x7E, 0x75, 0x89, 0x69, 0x2E, 0x63, 0x76, 0x85, 0x46, 0x8D, 0xA0, 0x8C,
  0x33, 0x1D, 0x82, 0x8C, 0x03, 0xEA, 0x69, 0x88, 0x35, 0xA1, 0x42, 0xBD,
  0x21, 0xED, 0x8D, 0xBC, 0xBC, 0xDB, 0x30, 0xFF, 0x86, 0xF0, 0x5B, 0xDC,
  0xE3, 0xE2, 0xE8, 0x0A, 0x0A, 0x29, 0x94, 0x80
};

static const unsigned char kat_RSA_X931_SHA384[] = {
  0x5C, 0x7D, 0x96, 0x35, 0xEC, 0x7E, 0x11, 0x38, 0xBB, 0x7B, 0xEC, 0x7B,
  0xF2, 0x82, 0x8E, 0x99, 0xBD, 0xEF, 0xD8, 0xAE, 0xD7, 0x39, 0x37, 0xCB,
  0xE6, 0x4F, 0x5E, 0x0A, 0x13, 0xE4, 0x2E, 0x40, 0xB9, 0xBE, 0x2E, 0xE3,
  0xEF, 0x78, 0x83, 0x18, 0x44, 0x35, 0x9C, 0x8E, 0xD7, 0x4A, 0x63, 0xF6,
  0x57, 0xC2, 0xB0, 0x08, 0x51, 0x73, 0xCF, 0xCA, 0x99, 0x66, 0xEE, 0x31,
  0xD8, 0x69, 0xE9, 0xAB, 0x13, 0x27, 0x7B, 0x41, 0x1E, 0x6D, 0x8D, 0xF1,
  0x3E, 0x9C, 0x35, 0x95, 0x58, 0xDD, 0x2B, 0xD5, 0xA0, 0x60, 0x41, 0x79,
  0x24, 0x22, 0xE4, 0xB7, 0xBF, 0x47, 0x53, 0xF6, 0x34, 0xD5, 0x7C, 0xFF,
  0x0E, 0x09, 0xEE, 0x2E, 0xE2, 0x37, 0xB9, 0xDE, 0xC5, 0x12, 0x44, 0x35,
  0xEF, 0x01, 0xE6, 0x5E, 0x39, 0x31, 0x2D, 0x71, 0xA5, 0xDC, 0xC6, 0x6D,
  0xE2, 0xCD, 0x85, 0xDB, 0x73, 0x82, 0x65, 0x28
};

static const unsigned char kat_RSA_X931_SHA512[] = {
  0xA6, 0x65, 0xA2, 0x77, 0x4F, 0xB3, 0x86, 0xCB, 0x64, 0x3A, 0xC1, 0x63,
  0xFC, 0xA1, 0xAA, 0xCB, 0x9B, 0x79, 0xDD, 0x4B, 0xE1, 0xD9, 0xDA, 0xAC,
  0xE7, 0x47, 0x09, 0xB2, 0x11, 0x4B, 0x8A, 0xAA, 0x05, 0x9E, 0x77, 0xD7,
  0x3A, 0xBD, 0x5E, 0x53, 0x09, 0x4A, 0xE6, 0x0F, 0x5E, 0xF9, 0x14, 0x28,
  0xA0, 0x99, 0x74, 0x64, 0x70, 0x4E, 0xF2, 0xE3, 0xFA, 0xC7, 0xF8, 0xC5,
  0x6E, 0x2B, 0x79, 0x96, 0x0D, 0x0C, 0xC8, 0x10, 0x34, 0x53, 0xD2, 0xAF,
  0x17, 0x0E, 0xE0, 0xBF, 0x79, 0xF6, 0x04, 0x72, 0x10, 0xE0, 0xF6, 0xD0,
  0xCE, 0x8A, 0x6F, 0xA1, 0x95, 0x89, 0xBF, 0x58, 0x8F, 0x46, 0x5F, 0x09,
  0x9F, 0x09, 0xCA, 0x84, 0x15, 0x85, 0xE0, 0xED, 0x04, 0x2D, 0xFB, 0x7C,
  0x36, 0x35, 0x21, 0x31, 0xC3, 0xFD, 0x92, 0x42, 0x11, 0x30, 0x71, 0x1B,
  0x60, 0x83, 0x18, 0x88, 0xA3, 0xF5, 0x59, 0xC3
};


int FIPS_selftest_rsa()
	{
	int ret = 0;
	RSA *key = NULL;
	EVP_PKEY pk;
	key=FIPS_rsa_new();
	setrsakey(key);
	pk.type = EVP_PKEY_RSA;
	pk.pkey.rsa = key;

	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_SHA1, sizeof(kat_RSA_SHA1),
				EVP_sha1(), EVP_MD_CTX_FLAG_PAD_PKCS1,
				"RSA SHA1 PKCS#1"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_SHA224, sizeof(kat_RSA_SHA224),
				EVP_sha224(), EVP_MD_CTX_FLAG_PAD_PKCS1,
				"RSA SHA224 PKCS#1"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_SHA256, sizeof(kat_RSA_SHA256),
				EVP_sha256(), EVP_MD_CTX_FLAG_PAD_PKCS1,
				"RSA SHA256 PKCS#1"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_SHA384, sizeof(kat_RSA_SHA384),
				EVP_sha384(), EVP_MD_CTX_FLAG_PAD_PKCS1,
				"RSA SHA384 PKCS#1"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_SHA512, sizeof(kat_RSA_SHA512),
				EVP_sha512(), EVP_MD_CTX_FLAG_PAD_PKCS1,
				"RSA SHA512 PKCS#1"))
		goto err;

	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_PSS_SHA1, sizeof(kat_RSA_PSS_SHA1),
				EVP_sha1(), EVP_MD_CTX_FLAG_PAD_PSS,
				"RSA SHA1 PSS"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_PSS_SHA224, sizeof(kat_RSA_PSS_SHA224),
				EVP_sha224(), EVP_MD_CTX_FLAG_PAD_PSS,
				"RSA SHA224 PSS"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_PSS_SHA256, sizeof(kat_RSA_PSS_SHA256),
				EVP_sha256(), EVP_MD_CTX_FLAG_PAD_PSS,
				"RSA SHA256 PSS"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_PSS_SHA384, sizeof(kat_RSA_PSS_SHA384),
				EVP_sha384(), EVP_MD_CTX_FLAG_PAD_PSS,
				"RSA SHA384 PSS"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_PSS_SHA512, sizeof(kat_RSA_PSS_SHA512),
				EVP_sha512(), EVP_MD_CTX_FLAG_PAD_PSS,
				"RSA SHA512 PSS"))
		goto err;


	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
			kat_RSA_X931_SHA1, sizeof(kat_RSA_X931_SHA1),
			EVP_sha1(), EVP_MD_CTX_FLAG_PAD_X931,
			"RSA SHA1 X931"))
		goto err;
	/* NB: SHA224 not supported in X9.31 */
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
			kat_RSA_X931_SHA256, sizeof(kat_RSA_X931_SHA256),
			EVP_sha256(), EVP_MD_CTX_FLAG_PAD_X931,
			"RSA SHA256 X931"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
			kat_RSA_X931_SHA384, sizeof(kat_RSA_X931_SHA384),
			EVP_sha384(), EVP_MD_CTX_FLAG_PAD_X931,
			"RSA SHA384 X931"))
		goto err;
	if (!fips_pkey_signature_test(&pk, kat_tbs, sizeof(kat_tbs) - 1,
			kat_RSA_X931_SHA512, sizeof(kat_RSA_X931_SHA512),
			EVP_sha512(), EVP_MD_CTX_FLAG_PAD_X931,
			"RSA SHA512 X931"))
		goto err;


	ret = 1;

	err:
	FIPS_rsa_free(key);
	return ret;
	}

#endif /* def OPENSSL_FIPS */
