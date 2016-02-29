#pragma once

#include "BiffRecord.h"
#include <Logic/Biff_structures/LongRGB.h>

namespace XLS
{


// Logical representation of LineFormat record in BIFF8
class LineFormat: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(LineFormat)
	BASE_OBJECT_DEFINE_CLASS_NAME(LineFormat)
public:
	LineFormat();
	~LineFormat();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeLineFormat;
	int serialize(std::wostream & _stream);
//-----------------------------
	LongRGB rgb;
	_UINT16 lns;
	_UINT16 we;
	bool	fAuto;
	bool	fAxisOn;
	bool	fAutoCo;
	IcvChart icv;	
};

} // namespace XLS

