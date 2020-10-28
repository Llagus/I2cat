/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IEEE1609dot2"
 * 	found in "asn1/IEEE1609dot2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_EncryptedData_H_
#define	_EncryptedData_H_


#include "asn_application.h"

/* Including external dependencies */
#include "SequenceOfRecipientInfo.h"
#include "SymmetricCiphertext.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* EncryptedData */
typedef struct EncryptedData {
	SequenceOfRecipientInfo_t	 recipients;
	SymmetricCiphertext_t	 ciphertext;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} EncryptedData_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EncryptedData;
extern asn_SEQUENCE_specifics_t asn_SPC_EncryptedData_specs_1;
extern asn_TYPE_member_t asn_MBR_EncryptedData_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _EncryptedData_H_ */
#include "asn_internal.h"
