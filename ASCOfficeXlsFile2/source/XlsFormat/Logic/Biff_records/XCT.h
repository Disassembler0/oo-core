#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of XCT record in BIFF8
class XCT: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(XCT)
	BASE_OBJECT_DEFINE_CLASS_NAME(XCT)
public:
	XCT();
	~XCT();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeXCT;

//-----------------------------
	_UINT16 ccrn;
	_UINT16 itab;
	bool itab_exist;

		//if(itab_exist)
		//{
		//	//BO_ATTRIB_MARKUP_ATTRIB(itab)
		//}

};

} // namespace XLS

