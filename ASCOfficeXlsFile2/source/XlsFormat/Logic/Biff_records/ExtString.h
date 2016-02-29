#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of ExtString record in BIFF8
class ExtString: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(ExtString)
	BASE_OBJECT_DEFINE_CLASS_NAME(ExtString)
public:
	ExtString();
	~ExtString();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeExtString;


};

} // namespace XLS

