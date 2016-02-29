#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of Dimensions record in BIFF8
class Dimensions: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Dimensions)
	BASE_OBJECT_DEFINE_CLASS_NAME(Dimensions)
public:
	Dimensions();
	~Dimensions();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeDimensions;

	int serialize(std::wostream & stream);
	
	std::wstring ref_;
//-----------------------------
	_UINT32		rwMic;
	_UINT32		rwMac;
	_UINT16		colMic;
	_UINT16		colMac;
	

};

} // namespace XLS

