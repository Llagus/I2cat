/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Descriptions"
 * 	found in "/home/rieblr/work/car2x/vanetza/vanetza/asn1/denm_en302637-3v1.2.2.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_AlacarteContainer_H_
#define	_AlacarteContainer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LanePosition.h"
#include "Temperature.h"
#include "PositioningSolutionType.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ImpactReductionContainer;
struct RoadWorksContainerExtended;
struct StationaryVehicleContainer;

/* AlacarteContainer */
typedef struct AlacarteContainer {
	LanePosition_t	*lanePosition	/* OPTIONAL */;
	struct ImpactReductionContainer	*impactReduction	/* OPTIONAL */;
	Temperature_t	*externalTemperature	/* OPTIONAL */;
	struct RoadWorksContainerExtended	*roadWorks	/* OPTIONAL */;
	PositioningSolutionType_t	*positioningSolution	/* OPTIONAL */;
	struct StationaryVehicleContainer	*stationaryVehicle	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AlacarteContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AlacarteContainer;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ImpactReductionContainer.h"
#include "RoadWorksContainerExtended.h"
#include "StationaryVehicleContainer.h"

#endif	/* _AlacarteContainer_H_ */
#include <asn_internal.h>
