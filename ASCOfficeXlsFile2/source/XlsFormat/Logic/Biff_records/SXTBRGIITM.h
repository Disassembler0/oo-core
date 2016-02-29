#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of SXTBRGIITM record in BIFF8
class SXTBRGIITM: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(SXTBRGIITM)
	BASE_OBJECT_DEFINE_CLASS_NAME(SXTBRGIITM)
public:
	SXTBRGIITM();
	~SXTBRGIITM();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeSXTBRGIITM;

};

} // namespace XLS

