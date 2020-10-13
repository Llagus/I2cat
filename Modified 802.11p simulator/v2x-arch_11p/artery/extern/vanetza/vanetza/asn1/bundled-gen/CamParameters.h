/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/home/rieblr/work/car2x/vanetza/vanetza/asn1/cam_en302637-2v1.3.2.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_CamParameters_H_
#define	_CamParameters_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BasicContainer.h"
#include "HighFrequencyContainer.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct LowFrequencyContainer;
struct SpecialVehicleContainer;

/* CamParameters */
typedef struct CamParameters {
	BasicContainer_t	 basicContainer;
	HighFrequencyContainer_t	 highFrequencyContainer;
	struct LowFrequencyContainer	*lowFrequencyContainer	/* OPTIONAL */;
	struct SpecialVehicleContainer	*specialVehicleContainer	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CamParameters_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CamParameters;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "LowFrequencyContainer.h"
#include "SpecialVehicleContainer.h"

#endif	/* _CamParameters_H_ */
#include <asn_internal.h>
