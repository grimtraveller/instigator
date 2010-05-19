#include "FSerializedTypeface.h"

FSerializedTypeface::FSerializedTypeface(const void *const serializedData, const int64 serializedDataSize)
		:	plainSize(0), boldSize(0), italicSize(0), allSize(0), isPlain(true), isBold(false), isItalic(false), isAll(false)
{
	MemoryInputStream serializedFont(serializedData, (int)serializedDataSize, false);
	int64 position=0;

	/* read the size */
	serializedFont.read (&plainSize, sizeof(uint32));
	position+=sizeof(uint32);
	serializedFont.setPosition (position);

	if (plainSize > 0)
	{
		/* if the size is > 0 read this much data */
		plainTypefaceData = MemoryBlock (plainSize, true);
	
		if (serializedFont.read (plainTypefaceData.getData(), plainSize) == plainSize)
		{
			position+=plainSize;
			serializedFont.setPosition (position);
		}
	}

	serializedFont.read (&boldSize, sizeof(uint32));
	position+=sizeof(uint32);
	serializedFont.setPosition (position);

	if (boldSize > 0)
	{
		boldTypefaceData = MemoryBlock (boldSize, true);
	
		if (serializedFont.read (boldTypefaceData.getData(), boldSize) == boldSize)
		{
			position+=boldSize;
			serializedFont.setPosition (position);
		}
	}

	serializedFont.read (&italicSize, sizeof(uint32));
	position+=sizeof(uint32);
	serializedFont.setPosition (position);

	if (italicSize > 0)
	{
		italicTypefaceData = MemoryBlock(italicSize, true);
	
		if (serializedFont.read (italicTypefaceData.getData(), italicSize) == italicSize)
		{
			position+=italicSize;
			serializedFont.setPosition (position);
		}
	}

	serializedFont.read (&allSize, sizeof(uint32));
	position+=sizeof(uint32);
	serializedFont.setPosition (position);

	if (allSize > 0)
	{
		allTypefaceData = MemoryBlock(allSize, true);
	
		if (serializedFont.read (allTypefaceData.getData(), allSize) == allSize)
		{
			position+=allSize;
			serializedFont.setPosition (position);
		}
	}

	// Log (T("FSerializedTypeface::ctor ") + String(position));
}

FSerializedTypeface::~FSerializedTypeface()
{
}

Typeface *FSerializedTypeface::getTypefaceForFont (const Font &font)
{
	return (getTypefaceForFlags (font.getStyleFlags()));
}

Typeface *FSerializedTypeface::getTypefaceForFlags (const int fontFlags)
{
	if (fontFlags == 1)
	{
		/* bold */
		MemoryInputStream ins(boldTypefaceData.getData(), boldTypefaceData.getSize(), true);
		return (new CustomTypeface (ins));
	}
	else if (fontFlags == 2)
	{
		/* italic */
		MemoryInputStream ins(italicTypefaceData.getData(), italicTypefaceData.getSize(), true);
		return (new CustomTypeface (ins));
	}
	else if (fontFlags == 3)
	{
		/* both */
		MemoryInputStream ins(allTypefaceData.getData(), allTypefaceData.getSize(), true);
		return (new CustomTypeface (ins));
	}
	else
	{
		MemoryInputStream ins(plainTypefaceData.getData(), plainTypefaceData.getSize(), true);
		return (new CustomTypeface (ins));
	}
}
