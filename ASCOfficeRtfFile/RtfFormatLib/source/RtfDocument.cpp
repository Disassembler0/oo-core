﻿/*
 * (c) Copyright Ascensio System SIA 2010-2018
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */

#include "RtfDocument.h"
#include "RtfReader.h"

#include "Writer/OOXNumberingWriter.h"
#include "Writer/OOXFontTableWriter.h"
#include "Writer/OOXStylesWriter.h"
#include "Writer/OOXSettingsWriter.h"
#include "Writer/OOXFootnoteWriter.h"

RtfDocument::RtfDocument() : m_pAppFonts(NULL)
{
    _section section;
	section.props = RtfSectionPtr(new RtfSection());

	m_aArray.push_back( section );
	
	m_oProperty.SetDefaultOOX();
	m_oDefaultCharProp.SetDefaultRtf();
	m_oDefaultParagraphProp.SetDefaultRtf();

	m_nZIndexLast = 0;
}
RtfDocument::~RtfDocument()
{
	if (m_pAppFonts)
	{
		delete m_pAppFonts;
		m_pAppFonts = NULL;
	}
}

int RtfDocument::GetType()
{
	return TYPE_RTF_DOCUMENT;
}

std::wstring RtfDocument::RenderToRtf(RenderParameter oRenderParameter)
{
	return L"";
}
std::wstring RtfDocument::RenderToOOX(RenderParameter oRenderParameter)
{
	return L"";
}
