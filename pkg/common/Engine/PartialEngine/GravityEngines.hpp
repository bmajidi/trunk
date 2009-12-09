// Copyright (C) 2004 by Janek Kozicki <cosurgi@berlios.de>
// 2007,2008 © Václav Šmilauer <eudoxos@arcig.cz> 
#pragma once
#include<yade/core/PartialEngine.hpp>

/* Homogeneous gravity field; applies gravity*mass force on all bodies.
 *
 * @bug is a PartialEngine, but doesn't care about subscribedBodies.
 */
class GravityEngine : public PartialEngine{
	public :
		Vector3r gravity;
		GravityEngine(): gravity(Vector3r::ZERO){};
		virtual ~GravityEngine(){};
		virtual void applyCondition(Scene*);
	protected :
	REGISTER_ATTRIBUTES(PartialEngine,(gravity));
	REGISTER_CLASS_AND_BASE(GravityEngine,PartialEngine);
};
REGISTER_SERIALIZABLE(GravityEngine);


/* Engine attracting all bodies towards a central body (doesn't depend on distance);
 *
 * @todo This code has not been yet tested at all.
 * @bug is a PartialEngine, but doesn't care about subscribedBodies.
 */
class CentralGravityEngine: public PartialEngine {
	public:
		//! The body towards which all other bodies are attracted.
		body_id_t centralBody;
		//! acceleration towards the central body
		Real accel;
		//! Whether to apply reciprocal force to the central body as well
		bool reciprocal;
		CentralGravityEngine(){ reciprocal=false; }
		virtual ~CentralGravityEngine(){};
		virtual void applyCondition(Scene*);
	protected:
		REGISTER_ATTRIBUTES(PartialEngine,(centralBody)(accel)(reciprocal));
		REGISTER_CLASS_NAME(CentralGravityEngine);
		REGISTER_BASE_CLASS_NAME(PartialEngine);
};
REGISTER_SERIALIZABLE(CentralGravityEngine);

/*! Apply acceleration (independent of distance) directed towards an axis.
 *
 * @bug is a PartialEngine, but doesn't care about subscribedBodies.
 */
class AxialGravityEngine: public PartialEngine {
	public:
		//! point through which the axis is passing
		Vector3r axisPoint;
		//! direction of the gravity axis (may not be normalized)
		Vector3r axisDirection;
		//! magnitude of acceleration that will be applied
		Real acceleration;
		AxialGravityEngine(){ }
		virtual ~AxialGravityEngine(){};
		virtual void applyCondition(Scene*);
	protected:
		REGISTER_ATTRIBUTES(PartialEngine,(axisPoint)(axisDirection)(acceleration));
		REGISTER_CLASS_NAME(AxialGravityEngine);
		REGISTER_BASE_CLASS_NAME(PartialEngine);
};
REGISTER_SERIALIZABLE(AxialGravityEngine);
