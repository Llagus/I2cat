/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/home/rieblr/work/car2x/vanetza/vanetza/asn1/cam_en302637-2v1.3.2.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#include "LowFrequencyContainer.h"

static asn_per_constraints_t asn_PER_type_LowFrequencyContainer_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_LowFrequencyContainer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LowFrequencyContainer, choice.basicVehicleContainerLowFrequency),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BasicVehicleContainerLowFrequency,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"basicVehicleContainerLowFrequency"
		},
};
static asn_TYPE_tag2member_t asn_MAP_LowFrequencyContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* basicVehicleContainerLowFrequency */
};
static asn_CHOICE_specifics_t asn_SPC_LowFrequencyContainer_specs_1 = {
	sizeof(struct LowFrequencyContainer),
	offsetof(struct LowFrequencyContainer, _asn_ctx),
	offsetof(struct LowFrequencyContainer, present),
	sizeof(((struct LowFrequencyContainer *)0)->present),
	asn_MAP_LowFrequencyContainer_tag2el_1,
	1,	/* Count of tags in the map */
	0,
	1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_LowFrequencyContainer = {
	"LowFrequencyContainer",
	"LowFrequencyContainer",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_LowFrequencyContainer_constr_1,
	asn_MBR_LowFrequencyContainer_1,
	1,	/* Elements count */
	&asn_SPC_LowFrequencyContainer_specs_1	/* Additional specs */
};

