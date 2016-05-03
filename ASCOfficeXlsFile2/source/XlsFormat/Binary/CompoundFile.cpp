
#include "CompoundFile.h"
#include "CFStream.h"

#include <sstream>

namespace XLS
{


CompoundFile::~CompoundFile()
{
	streams.clear();

	if (storage_)delete storage_;
	storage_ = NULL;
}

bool CompoundFile::isError()
{
	if (storage_ != NULL) return false;
	return true;	
}


CompoundFile::CompoundFile(const std::wstring & file_path, const ReadWriteMode mode)
:	rwMode(mode)
{
	unsigned int grfMode = 0;

	storage_ = new POLE::Storage(file_path.c_str());
	if (storage_ == NULL) return;

	switch(rwMode)
	{		
		case cf_ReadMode:
		{
			if (storage_->open(false, false) == false)
			{
				delete storage_;
				storage_ = NULL;
			}
			
		}break;
		case cf_WriteMode:
		{
			if (storage_->open(true, true) == false)
			{
				delete storage_;
				storage_ = NULL;
			}
		}break;
	}
}


// Opens "Workbook" stream and returns the only reference
CFStreamPtr CompoundFile::getWorkbookStream()
{
	CFStreamPtr stream = getNamedStream("Workbook");

	if (stream == NULL) 
		stream = getNamedStream("Book");
	if (stream == NULL) 
		stream = getNamedStream("BOOK");//file(6).xls
	if (stream == NULL) 
		stream = getNamedStream("book");
	return stream;
}


// Creates "Workbook" stream and returns the only reference
CFStreamPtr CompoundFile::createWorkbookStream()
{
	return createNamedStream("Workbook");
}


// Opens "SummaryInformation" stream and returns the only reference
CFStreamPtr CompoundFile::getSummaryInformationStream()
{
	return getNamedStream("SummaryInformation");
}


// Creates "SummaryInformation" stream and returns the only reference
CFStreamPtr CompoundFile::createSummaryInformationStream()
{
	return createNamedStream("SummaryInformation");
}


// Closes "SummaryInformation" stream
void CompoundFile::closeSummaryInformationStream()
{
	return closeNamedStream("SummaryInformation");
}


// Opens "SummaryInformation" stream and returns the only reference
CFStreamPtr CompoundFile::getDocumentSummaryInformationStream()
{
	return getNamedStream("DocumentSummaryInformation");
}


// Creates "SummaryInformation" stream and returns the only reference
CFStreamPtr CompoundFile::createDocumentSummaryInformationStream()
{
	return createNamedStream("DocumentSummaryInformation");
}


// Closes "SummaryInformation" stream
void CompoundFile::closeDocumentSummaryInformationStream()
{
	closeNamedStream("DocumentSummaryInformation");
}


CFStreamPtr CompoundFile::getNamedStream(const std::string& name)
{
	if(!streams[name])
	{
		POLE::Stream * pStream = openStream(name.c_str());
		if (pStream)	
			streams[name].reset(new CFStream(pStream));
	}
	return streams[name];
}


CFStreamPtr CompoundFile::createNamedStream(const std::string& name)
{
	if(!streams[name])
	{
		POLE::Stream * pStream = createStream(name.c_str());
		if (pStream)	
			streams[name].reset(new CFStream(pStream));
	}
	return streams[name];
}


void CompoundFile::closeNamedStream(const std::string& name)
{
	streams[name].reset();
}


// Opens a stream in the storage (shall be called not more than once per stream)
POLE::Stream* CompoundFile::openStream(const std::string & stream_name)
{
	if (storage_ == NULL) return NULL;

	POLE::Stream* pStream = new POLE::Stream(storage_, stream_name);
	if(pStream == NULL)
	{
		return NULL;
	}
	if ((pStream) && (pStream->size() > 0))
		return pStream;
	else return NULL;
}


// Creates a new stream in the storage
POLE::Stream* CompoundFile::createStream(const std::string & stream_name)
{
	if (storage_ == NULL) return NULL;

	POLE::Stream* pStream = new POLE::Stream(storage_, stream_name, true);
	if(pStream == NULL)
	{
		return NULL;
	}
	return pStream;
}


} // namespace XLS


