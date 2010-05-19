#ifndef __FSERIALIZED_TYPEFACE_H__
#define __FSERIALIZED_TYPEFACE_H__

#include "Includes.h"

class FSerializedTypeface
{
	public:
		FSerializedTypeface(const void *const serializedData, const int64 serializedDataSize);
		~FSerializedTypeface();
		const Font getFont();
		void setBold (const bool shouldBeBold);
		void setItalic (const bool shouldBeItalic);
		Typeface *getTypefaceForFlags (const int fontFlags);
		Typeface *getTypefaceForFont (const Font &font);

	private:
		uint32 plainSize, boldSize, italicSize, allSize;
		MemoryBlock plainTypefaceData, boldTypefaceData, italicTypefaceData, allTypefaceData;
		bool isPlain, isBold, isItalic, isAll;
};

#endif
