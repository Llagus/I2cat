/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/rieblr/work/car2x/vanetza/vanetza/asn1/cdd_ts102894-2v1.2.1.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_DeltaReferencePosition_H_
#define	_DeltaReferencePosition_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DeltaLatitude.h"
#include "DeltaLongitude.h"
#include "DeltaAltitude.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DeltaReferencePosition */
typedef struct DeltaReferencePosition {
	DeltaLatitude_t	 deltaLatitude;
	DeltaLongitude_t	 deltaLongitude;
	DeltaAltitude_t	 deltaAltitude;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DeltaReferencePosition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DeltaReferencePosition;

#ifdef __cplusplus
}
#endif

#endif	/* _DeltaReferencePosition_H_ */
#include <asn_internal.h>
